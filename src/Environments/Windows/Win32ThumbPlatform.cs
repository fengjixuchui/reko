#region License
/* 
 * Copyright (C) 1999-2020 John Källén.
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

using Reko.Arch.Arm.AArch32;
using Reko.Core;
using Reko.Core.CLanguage;
using Reko.Core.Serialization;
using Reko.Core.Services;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Reko.Environments.Windows
{
    // https://stackoverflow.com/questions/16375355/what-is-the-windows-rt-on-arm-native-code-calling-convention
    public class Win32ThumbPlatform : Platform
    {
        private Dictionary<int, SystemService> systemServices;

        public Win32ThumbPlatform(IServiceProvider services, IProcessorArchitecture arch) : 
            base(services, arch, "winArm")
        {
            this.systemServices = new Dictionary<int, SystemService>
            {
                {
                    0x00FE,
                    new SystemService {
                        SyscallInfo = new SyscallInfo {
                            Vector = 0x00FE,
                            RegisterValues = new RegValue[0]
                        },
                        Name = "__debugbreak",  // Breaks into the debugger. Used by ntdll!DbgUserBreakPoint(). 
                    }
                },
                { 
                    0x00FC,
                    new SystemService { 
                        SyscallInfo = new SyscallInfo
                        {
                            Vector = 0x00FC,
                            RegisterValues = new RegValue[0],
                        },
                        Name = "__assertfail",  // Used to indicate critical assertion failures in the kernel debugger. Used by KeAccumulateTicks() 
                    }
                },
                 {
                     0x00FB,
                    new SystemService {
                        SyscallInfo = new SyscallInfo
                        {
                            Vector = 0x00FB,
                            RegisterValues = new RegValue[0],
                        },
                        Name = "__fastfail",    // Indicates fast fail conditions resulting in KeBugCheckEx(KERNEL_SECURITY_CHECK_FAILURE). Called by functions like InsertTailList() upon detecting a corrupted list, as described in [9]. 
                        Characteristics = new ProcedureCharacteristics {
                            Terminates = true,
                        }
                    }
                },
                {
                    0x00FA,
                    new SystemService {
                        SyscallInfo = new SyscallInfo {
                            Vector = 0x00FA,
                            RegisterValues = new RegValue[0]
                        },
                        Name = "__rdpmccntr64", // Reads the 64-bit performance counter co-processor register and returns the value in R0+R1. Used by ReadTimeStampCounter(), KiCacheFlushTrial() etc. 
                    }
                },
                { 
                    0x00FD,
                    new SystemService {
                        SyscallInfo = new SyscallInfo {
                            Vector = 0x00FD,
                            RegisterValues = new RegValue[0],
                        },
                        Name = "__debugservice", // Invoke debugger breakpoint. Used by DbgBreakPointWithStatusEnd(), DebugPrompt() etc. 
                    }
                },
                {
                    0x00F9,
                    new SystemService
                    {
                        SyscallInfo = new SyscallInfo {
                            Vector = 0x00F9,
                            RegisterValues = new RegValue[0],
                        },
                        Name = "__brkdiv0", //  Divide By Zero Exception, used by functions like nt!_rt_udiv and nt!_rt_udiv. Also generated by the compiler to check the divisor before division operations. 
                        Characteristics = new ProcedureCharacteristics {
                            Terminates = true,
                        }
                    }
                }
            };
        }

        public override string DefaultCallingConvention
        {
            get { return ""; } 
        }

        public override Address AdjustProcedureAddress(Address addr)
        {
            return Address.Ptr32((uint)addr.ToLinear() & ~1u);
        }

        public override IPlatformEmulator CreateEmulator(SegmentMap segmentMap, Dictionary<Address, ImportReference> importReferences)
        {
            throw new NotImplementedException();
        }

        public override HashSet<RegisterStorage> CreateImplicitArgumentRegisters()
        {
            return new[] { "r11", "sp", "lr", "pc" }
                .Select(r => Architecture.GetRegister(r)).ToSet();
        }

        public override HashSet<RegisterStorage> CreateTrashedRegisters()
        {
            // https://msdn.microsoft.com/en-us/library/dn736986.aspx 
            return new[] { "r0", "r1", "r2", "r3", "ip" }
                .Select(r => Architecture.GetRegister(r)).ToSet();
        }

        public override CallingConvention GetCallingConvention(string ccName)
        {
            return new Arm32CallingConvention();
        }

        public override ImageSymbol FindMainProcedure(Program program, Address addrStart)
        {
            Services.RequireService<DecompilerEventListener>().Warn(new NullCodeLocation(program.Name),
                           "Win32 ARM main procedure finder not implemented yet.");
            return null;
        }

        public override SystemService FindService(int vector, ProcessorState state, SegmentMap segmentMap)
        {
            SystemService svc;
            systemServices.TryGetValue(vector, out svc);
            return svc;
        }

        public override int GetByteSizeFromCBasicType(CBasicType cb)
        {
            switch (cb)
            {
            case CBasicType.Bool: return 1;
            case CBasicType.Char: return 1;
            case CBasicType.Short: return 2;
            case CBasicType.Int: return 4;
            case CBasicType.Long: return 4;
            case CBasicType.LongLong: return 8;
            case CBasicType.Float: return 4;
            case CBasicType.Double: return 8;
            case CBasicType.LongDouble: return 8;
            case CBasicType.Int64: return 8;
            default: throw new NotImplementedException(string.Format("C basic type {0} not supported.", cb));
            }
        }

        public override ExternalProcedure LookupProcedureByName(string moduleName, string procName)
        {
            throw new NotImplementedException();
        }

        // http://codemachine.com/article_armasm.html

//0xDEFE __debugbreak Breaks into the debugger. Used by ntdll!DbgUserBreakPoint(). 
//0xDEFC __assertfail Used to indicate critical assertion failures in the kernel debugger. Used by KeAccumulateTicks() 
//0xDEFB __fastfail Indicates fast fail conditions resulting in KeBugCheckEx(KERNEL_SECURITY_CHECK_FAILURE). Called by functions like InsertTailList() upon detecting a corrupted list, as described in [9]. 
//0xDEFA __rdpmccntr64 Reads the 64-bit performance counter co-processor register and returns the value in R0+R1. Used by ReadTimeStampCounter(), KiCacheFlushTrial() etc. 
//0xDEFD __debugservice Invoke debugger breakpoint. Used by DbgBreakPointWithStatusEnd(), DebugPrompt() etc. 
//0xDEF9 __brkdiv0 Divide By Zero Exception, used by functions like nt!_rt_udiv and nt!_rt_udiv. Also generated by the compiler to check the divisor before division operations. 

    }
}
