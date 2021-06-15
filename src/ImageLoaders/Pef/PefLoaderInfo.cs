#region License
/* 
 * Copyright (C) 2018-2021 Stefano Moioli <smxdev4@gmail.com>.
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
using Reko.Core.Memory;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Reko.ImageLoaders.Pef
{
    public class PefLoaderInfo
    {
        public readonly PefLoaderSegment Loader;

        public IList<PefExportedSymbol> ExportedSymbols { get; private set; }

        private PefLoaderInfo(PefLoaderSegment loader)
        {
            Loader = loader;
            ExportedSymbols = new List<PefExportedSymbol>();
        }

        private IEnumerable<PefExportedSymbol> LoadHashChain(PefExportHash tab)
        {
            var end = tab.FirstExportIndex + tab.ChainCount;
            for(var i=tab.FirstExportIndex; i<end; i++)
            {
                var key = Loader.ExportKeyTable[i];
                var sym = Loader.ExportSymbolTable[i];
                yield return PefExportedSymbol.Load(sym, key, Loader.StringTable);
            }
        }

        private IEnumerable<PefExportedSymbol> PopulateExports()
        {
            foreach (var chain in Loader.ExportHashTable)
            {
                foreach(var sym in LoadHashChain(chain))
                {
                    yield return sym;
                }
            }
        }

        private void PopulateInfo()
        {
            ExportedSymbols = PopulateExports().ToArray();
        }

        public static PefLoaderInfo Load(PefLoaderSegment loader)
        {
            var obj = new PefLoaderInfo(loader);
            obj.PopulateInfo();
            return obj;
        }
    }
}
