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

using Reko.Core.Machine;
using System;
using System.Collections.Generic;
using System.Text;

namespace Reko.Arch.Qualcomm
{
    public class HexagonPacket : MachineInstruction
    {
        public HexagonPacket(HexagonInstruction[] instrs)
        {
            this.Instructions = instrs;
        }

        public override int MnemonicAsInteger => 0;
        public override string MnemonicAsString => "";

        public HexagonInstruction[] Instructions { get; }
        
        protected override void DoRender(MachineInstructionRenderer renderer, MachineInstructionRendererOptions options)
        {
            renderer.WriteString("{ ");
            var sep = "";
            foreach (var instr in Instructions)
            {
                renderer.WriteString(sep);
                instr.Render(renderer, options);
                sep = "; ";
            }
            renderer.WriteString(" }");
        }
    }
}
