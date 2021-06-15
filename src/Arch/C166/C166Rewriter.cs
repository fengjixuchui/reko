#region License
/* 
 * Copyright (C) 1999-2021 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Expressions;
using Reko.Core.Machine;
using Reko.Core.Memory;
using Reko.Core.Rtl;
using Reko.Core.Services;
using Reko.Core.Types;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Reko.Arch.C166
{
    public class C166Rewriter : IEnumerable<RtlInstructionCluster>
    {
        private static readonly FlagGroupStorage EZ__N = FlagGroup(FlagM.EF | FlagM.ZF | FlagM.NF, "EZN");
        private static readonly FlagGroupStorage EZVCN = FlagGroup(FlagM.EF | FlagM.ZF | FlagM.VF | FlagM.CF | FlagM.NF, "EZVCN");
        private static readonly FlagGroupStorage _ZV_N = FlagGroup(FlagM.ZF | FlagM.VF | FlagM.NF, "ZVN");
        private static readonly FlagGroupStorage __V_N = FlagGroup(FlagM.VF | FlagM.NF, "VN");
        private static readonly FlagGroupStorage _Z_C_ = FlagGroup(FlagM.VF | FlagM.CF, "VC");

        private readonly C166Architecture arch;
        private readonly ProcessorState state;
        private readonly IStorageBinder binder;
        private readonly IRewriterHost host;
        private readonly EndianImageReader rdr;
        private readonly IEnumerator<C166Instruction> dasm;
        private readonly List<RtlInstruction> instrs;
        private readonly RtlEmitter m;
        private C166Instruction instr;
        private InstrClass iclass;

        public C166Rewriter(C166Architecture arch, EndianImageReader rdr, ProcessorState state, IStorageBinder binder, IRewriterHost host)
        {
            this.arch = arch;
            this.state = state;
            this.binder = binder;
            this.host = host;
            this.rdr = rdr;
            this.dasm = new C166Disassembler(arch, rdr).GetEnumerator();
            this.instrs = new List<RtlInstruction>();
            this.m = new RtlEmitter(instrs);
            this.instr = null!;
        }

        public IEnumerator<RtlInstructionCluster> GetEnumerator()
        {
            while (dasm.MoveNext())
            {
                this.instr = dasm.Current;
                this.iclass = instr.InstructionClass;
                switch (instr.Mnemonic)
                {
                default:
                    EmitUnitTest();
                    goto case Mnemonic.Invalid;
                case Mnemonic.Invalid:
                    iclass = InstrClass.Invalid;
                    m.Invalid();
                    break;
                case Mnemonic.add: RewriteAddSub(m.IAdd); break;
                case Mnemonic.and: RewriteLogical(m.And); break;
                case Mnemonic.bclr: RewriteBclr(); break;
                case Mnemonic.bset: RewriteBset(); break;
                case Mnemonic.calla: RewriteCalla(); break;
                case Mnemonic.cmp: RewriteCmp(); break;
                case Mnemonic.cmpb: RewriteCmp(); break;
                case Mnemonic.cmpd1: RewriteCmpIncDec(-1); break;
                case Mnemonic.diswdt: RewriteDiswdt(); break;
                case Mnemonic.einit: RewriteEinit(); break;
                case Mnemonic.jmpa: RewriteJmpa(); break;
                case Mnemonic.jmpr: RewriteJmpr(); break;
                case Mnemonic.jmps: RewriteJmps(); break;
                case Mnemonic.jnb: RewriteJnb(); break;
                case Mnemonic.mov: RewriteMov(); break;
                case Mnemonic.movb: RewriteMov(); break;
                case Mnemonic.nop: m.Nop(); break;
                case Mnemonic.push: RewritePush(); break;
                case Mnemonic.ret: RewriteRet(); break;
                case Mnemonic.reti: RewriteReti(); break;
                }
                yield return m.MakeCluster(instr.Address, instr.Length, iclass);
                instrs.Clear();
            }
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

        private void EmitCc(FlagGroupStorage grf, Expression e)
        {
            m.Assign(binder.EnsureFlagGroup(grf), e);
        }

        private (Expression bit, Expression exp) BitOp(int iop)
        {
            var b = (BitOfOperand) instr.Operands[iop];
            return (Constant.Int16((short)b.Bit), Src(b.Operand));
        }

        private void EmitCond(FlagGroupStorage grf, Expression e) => EmitCc(grf, m.Cond(e));

        private void EmitUnitTest()
        {
            var testgenSvc = arch.Services.GetService<ITestGenerationService>();
            testgenSvc?.ReportMissingRewriter("C166Rw", instr, instr.Mnemonic.ToString(), rdr, "");
        }

        private Expression Mem(MemoryOperand mem)
        {
            Expression ea;
            if (mem.Base != null)
            {
                var baseReg = binder.EnsureRegister(mem.Base);
                ea = baseReg;
                if (mem.Predecrement)
                {
                    m.Assign(baseReg, m.ISubS(baseReg, mem.Width.Size));
                }
                if (mem.Offset != 0)
                {
                    ea = m.IAdd(ea, mem.Offset);
                }
                if (mem.Postincrement)
                {
                    m.Assign(baseReg, m.IAddS(baseReg, mem.Width.Size));
                }
            }
            else
            {
                ea = Address.Ptr16((ushort) mem.Offset);
            }
            return m.Mem(mem.Width, ea);
        }

        private Expression Dst(int iop, Expression src)
        {
            Expression dst;
            switch (instr.Operands[iop])
            {
            case RegisterOperand reg:
                dst = binder.EnsureRegister(reg.Register);
                m.Assign(dst, src);
                return dst;
            case MemoryOperand mem:
                dst = Mem(mem); break;
            default:
                throw new InvalidOperationException($"Not implemented: {instr.Operands[iop].GetType().Name}");
            }
            if (src is Identifier || src is Constant)
            {
                m.Assign(dst, src);
                return src;
            }
            else
            {
                var tmp = binder.CreateTemporary(dst.DataType);
                m.Assign(tmp, src);
                m.Assign(dst, tmp);
                return tmp;
            }
        }
        private Expression Dst(int iop, Expression src, Func<Expression,Expression,Expression> fn)
        {
            Expression dst;
            switch (instr.Operands[iop])
            {
            case RegisterOperand reg:
                dst = binder.EnsureRegister(reg.Register); break;
            case MemoryOperand mem:
                dst = Mem(mem); break;
            default:
                throw new InvalidOperationException($"Not implemented: {instr.Operands[iop].GetType().Name}");
            }
            src = fn(dst, src);
            if (dst is Identifier)
            {
                m.Assign(dst, src);
                return dst;
            }
            else
            {
                var tmp = binder.CreateTemporary(dst.DataType);
                m.Assign(tmp, src);
                m.Assign(dst, tmp);
                return tmp;
            }
        }

        private static FlagGroupStorage FlagBit(FlagM bit, string name)
            => new FlagGroupStorage(Registers.PSW, (uint) bit, name, PrimitiveType.Bool);
        private static FlagGroupStorage FlagGroup(FlagM bits, string name)
            => new FlagGroupStorage(Registers.PSW, (uint) bits, name, Registers.PSW.DataType);

        private Expression Src(int iop) => Src(instr.Operands[iop]);

        private Expression Src(MachineOperand op)
        {
            switch (op)
            {
            case RegisterOperand reg:
                return binder.EnsureRegister(reg.Register);
            case ImmediateOperand imm:
                return imm.Value;
            case AddressOperand addr:
                return addr.Address;
            case MemoryOperand mem:
                return Mem(mem);
            default:
                throw new NotImplementedException($"Not implemented: {op.GetType().Name}");
            }
        }

        private Expression TestFromCondition(CondCode c)
        {
            ConditionCode cc;
            FlagGroupStorage flagGroup;
            switch (c)
            {
            case CondCode.cc_Z: cc = ConditionCode.EQ; flagGroup = Registers.Z; break;
            case CondCode.cc_NZ: cc = ConditionCode.EQ; flagGroup = Registers.Z; break;
            case CondCode.cc_V: cc = ConditionCode.OV; flagGroup = Registers.V; break;
            case CondCode.cc_NV: cc = ConditionCode.NO; flagGroup = Registers.V; break;
            case CondCode.cc_N: cc = ConditionCode.LT; flagGroup = Registers.N; break;
            case CondCode.cc_NN: cc = ConditionCode.GE; flagGroup = Registers.N; break;
            case CondCode.cc_C: cc = ConditionCode.ULT; flagGroup = Registers.C; break;
            case CondCode.cc_NC: cc = ConditionCode.UGE; flagGroup = Registers.C; break;
            case CondCode.cc_SGT: cc = ConditionCode.GT; flagGroup = _ZV_N; break;
            case CondCode.cc_SLE: cc = ConditionCode.LE; flagGroup = _ZV_N; break;
            case CondCode.cc_SLT: cc = ConditionCode.LT; flagGroup = __V_N; break;
            case CondCode.cc_SGE: cc = ConditionCode.GE; flagGroup = __V_N; break;
            case CondCode.cc_UGT: cc = ConditionCode.UGT; flagGroup = _Z_C_; break;
            case CondCode.cc_ULE: cc = ConditionCode.ULE; flagGroup = _Z_C_; break;
            default: throw new NotImplementedException($"Not implemented cc: {c}");
            }
            return m.Test(cc, binder.EnsureFlagGroup(flagGroup));
        }

        private void RewriteAddSub(Func<Expression,Expression, Expression> fn)
        {
            var src = Src(1);
            var dst = Dst(0, src, fn);
            EmitCond(EZVCN, dst);
        }

        private void RewriteBclr()
        {
            var (bit, reg) = BitOp(0);
            EmitCc(Registers.N, host.Intrinsic("__bit", true, PrimitiveType.Bool, reg, bit));
            EmitCc(Registers.Z, m.Comp(binder.EnsureFlagGroup(Registers.N)));
            m.Assign(reg, host.Intrinsic("__bit_clear", true, reg.DataType, reg, bit));
            EmitCc(Registers.E, Constant.False());
            EmitCc(Registers.V, Constant.False());
            EmitCc(Registers.C, Constant.False());
        }

        private void RewriteBset()
        {
            var (bit, reg) = BitOp(0);
            EmitCc(Registers.N, host.Intrinsic("__bit", true, PrimitiveType.Bool, reg, bit));
            EmitCc(Registers.Z, m.Comp(binder.EnsureFlagGroup(Registers.N)));
            m.Assign(reg, host.Intrinsic("__bit_set", true, reg.DataType, reg, bit));
            EmitCc(Registers.E, Constant.False());
            EmitCc(Registers.V, Constant.False());
            EmitCc(Registers.C, Constant.False());
        }

        private void RewriteCalla()
        {
            var cc = ((ConditionalOperand) instr.Operands[0]).CondCode;
            var addr = ((AddressOperand) instr.Operands[1]).Address;
            if (cc == CondCode.cc_UC)
            {
                m.Call(addr, 2);
                return;
            }
            throw new NotImplementedException();
        }

        private void RewriteCmp()
        {
            var left = Src(0);
            var right = Src(1);
            EmitCond(EZVCN, m.ISub(left, right));
        }

        private void RewriteCmpIncDec(int increment)
        {
            var left = Src(0);
            var right = Src(1);
            EmitCond(EZVCN, m.ISub(left, right));
            m.Assign(left, m.AddSubSignedInt(left, increment));
        }

        private void RewriteDiswdt()
        {
            m.SideEffect(host.Intrinsic("__disable_watchdog_timer", false, VoidType.Instance));
        }

        private void RewriteEinit()
        {
            m.SideEffect(host.Intrinsic("__end_of_initialization", false, VoidType.Instance));
        }

        private void RewriteJmpa()
        {
            var target = (Address) Src(1);
            var c = ((ConditionalOperand) instr.Operands[0]).CondCode;
            if (c == CondCode.cc_UC)
            {
                m.Goto(target);
            }
            else
            {
                var condition = TestFromCondition(c);
                m.Branch(condition, target);
            }
        }

        private void RewriteJmpr()
        {
            var target = (Address) Src(1);
            var c = ((ConditionalOperand) instr.Operands[0]).CondCode;
            if (c == CondCode.cc_UC)
            {
                m.Goto(target);
            }
            else
            {
                var condition = TestFromCondition(c);
                m.Branch(condition, target);
            }
        }

        private void RewriteJmps()
        {
            var seg = ((ImmediateOperand) instr.Operands[0]).Value.ToUInt16();
            var off = ((AddressOperand) instr.Operands[1]).Address.Offset;
            var addr = Address.SegPtr(seg, (uint) off);
            m.Goto(addr);
        }

        private void RewriteJnb()
        {
            var (bit, exp) = BitOp(0);
            var addr = ((AddressOperand) instr.Operands[1]).Address;
            m.Branch(m.Not(host.Intrinsic("__bit", true, PrimitiveType.Bool, exp, bit)), addr);
        }

        private void RewriteLogical(Func<Expression,Expression,Expression> fn)
        {
            var src = Src(1);
            var dst = Dst(0, src, fn);
            EmitCond(EZ__N, dst);
            m.Assign(binder.EnsureFlagGroup(Registers.V), Constant.False());
            m.Assign(binder.EnsureFlagGroup(Registers.C), Constant.False());
        }

        private void RewriteMov()
        {
            var src = Src(1);
            var dst = Dst(0, src);
            EmitCond(EZ__N, dst);
        }

        private void RewritePush()
        {
            var src = Src(0);
            var tmp = binder.CreateTemporary(src.DataType);
            m.Assign(tmp, src);
            var sp = binder.EnsureRegister(Registers.SP);
            m.Assign(sp, m.ISubS(sp, 2));
            m.Assign(m.Mem16(sp), tmp);
            EmitCond(EZ__N, tmp);
        }

        private void RewriteRet()
        {
            m.Return(2, 0);
        }

        private void RewriteReti()
        {
            var sp = binder.EnsureRegister(Registers.SP);
            var psw = binder.EnsureRegister(Registers.PSW);
            m.Assign(psw, m.Mem16(m.IAddS(sp, 2)));
            m.Return(2, 2);
        }
    }
}
