/* 
 * Copyright (C) 1999-2008 John K�ll�n.
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

using Decompiler.Core.Code;
using Decompiler.Core.Lib;
using Decompiler.Core.Output;
using Decompiler.Core.Types;
using System;
using System.IO;
using System.Xml;

namespace Decompiler.Core
{
	/// <summary>
	/// Summarizes the effects of calling a procedure, as seen by the caller. Procedure signatures
	/// may be shared by several procedures.
	/// </summary>
	/// <remarks>
	/// Calling a procedure affects a few things: the registers, the stack depth, and in the case of the intel x86
	/// architecture the fpu stack depth. These effects are summarized by the signature.
	/// </remarks>
	public class ProcedureSignature
	{
		private Identifier ret;
		private Identifier [] formals;
		private int stackDelta;
		private TypeVariable typeVar;

		private int fpuStackDelta;	
		private int fpuStackMax;
		private int fpuStackWriteMax;

		public ProcedureSignature()
		{
		}

		public ProcedureSignature(Identifier returnId, Identifier [] formalArguments)
		{
			this.ret = returnId;
			this.formals = formalArguments;
		}
		
		public Identifier [] FormalArguments
		{
			get { return formals; } 
		}

		public void Emit(string fnName, EmitFlags f, TextWriter w)
		{
            Emit(fnName, f, new CodeFormatter(w), new TypeFormatter(w, true));
		}

        public void Emit(string fnName, EmitFlags f, CodeFormatter w, TypeFormatter t)
        {
            bool emitStorage = (f & EmitFlags.ArgumentKind) == EmitFlags.ArgumentKind;
            if (emitStorage)
            {
                if (ret != null)
                {
                    WriteType(ret, emitStorage, w);
                    w.Write(" ");
                }
                else
                {
                    w.Write("void ");
                }
                w.Write("{0}(", fnName);
            }
            else
            {
                if (ret == null)
                    t.Write("void {0}", fnName);
                else
                {
                    t.Write(ret.DataType, fnName);           //$TODO: won't work with fn's that return pointers to functions or arrays.
                }
                t.Write("(");
            }
            if (formals != null && formals.Length > 0)
            {
                EmitArgument(formals[0], emitStorage, w, t);
                for (int i = 1; i < formals.Length; ++i)
                {
                    w.Write(", ");
                    EmitArgument(formals[i], emitStorage, w, t);
                }
            }
            w.Write(")");
            if ((f & EmitFlags.LowLevelInfo) == EmitFlags.LowLevelInfo)
            {
                w.WriteLine();
                w.Write("// stackDelta: {0}; fpuStackDelta: {1}; fpuMaxParam: {2}", stackDelta, FpuStackDelta, FpuStackParameterMax);
                w.WriteLine();
            }
        }

		private void EmitArgument(Identifier arg, bool writeStorage, CodeFormatter writer, TypeFormatter t)
		{
            if (writeStorage)
            {
                WriteType(arg, writeStorage, writer);
                writer.Write(" ");
                writer.Write(arg.Name);
            }
            else
            {
                t.Write(arg.DataType, arg.Name);
            }
        }


        public void WriteType(Identifier arg, bool writeStorage, CodeFormatter writer)
        {
            if (writeStorage)
            {
                OutArgumentStorage os = arg.Storage as OutArgumentStorage;
                if (os != null)
                {
                    writer.Write(os.OriginalIdentifier.Storage.Kind);
                    writer.Write(" out ");
                }
                else
                {
                    writer.Write(arg.Storage.Kind);
                    writer.Write(" ");
                }
            }
            writer.Write(arg.DataType.ToString());
        }

		/// <summary>
		/// Amount by which the FPU stack grows or shrinks after the procedure is called.
		/// </summary>
		public int FpuStackDelta 
		{
			get { return fpuStackDelta; }
			set { fpuStackDelta = value; }
		}

		/// <summary>
		/// The index of the 'deepest' FPU stack argument written. -1 means no stack parameters are used.
		/// </summary>
		public int FpuStackOutParameterMax
		{
			get { return fpuStackWriteMax; }
			set { fpuStackWriteMax = value; }
		}

		/// <summary>
		/// The index of the 'deepest' FPU stack argument used. -1 means no stack parameters are used.
		/// </summary>
		public int FpuStackParameterMax
		{
			get { return fpuStackMax; }
			set { fpuStackMax = value; }
		}

		public bool ArgumentsValid
		{
			get { return formals != null || ret != null; }
		}

		/// <summary>
		/// Amount of bytes to add to the stack pointer after returning from the procedure.
		/// Note that this also includes the return address size, if the return address is 
		/// passed on the stack.
		/// </summary>
		public int StackDelta
		{
			get { return stackDelta; }
			set 
			{
				stackDelta = value; 
			}
		}

		public Identifier ReturnValue
		{
			get { return ret; }
		}

		public override string ToString()
		{
			StringWriter w = new StringWriter();
            CodeFormatter f = new CodeFormatter(w);
            TypeFormatter tf = new TypeFormatter(w, false);
			Emit("()", EmitFlags.ArgumentKind|EmitFlags.LowLevelInfo, f, tf);
			return w.ToString();
		}

		public string ToString(string name)
		{
			StringWriter sw = new StringWriter();
            CodeFormatter cf = new CodeFormatter(sw);
            TypeFormatter tf = new TypeFormatter(sw, false);
            Emit(name, EmitFlags.ArgumentKind, cf, tf);
			return sw.ToString();
		}

		public TypeVariable TypeVariable
		{
			get { return typeVar; }
			set { typeVar = value; }
		}

		[Flags]
		public enum EmitFlags
		{
			None = 0,
			ArgumentKind = 1,
			LowLevelInfo = 2,
		}
	}
}
