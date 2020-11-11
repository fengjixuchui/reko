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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reko.Arch.zSeries
{
    public enum Mnemonic
    {
        invalid,




        a,
        ad,
        adr,
        ae,
        aghi,
        agr,
        ah,
        ahi,
        alr,
        ap,
        ar,
        au,
        awr,
        b,
        balr,
        bas,
        basr,
        bassm,
        bctr,
        be,
        ber,
        bh,
        bhe,
        bher,
        bhr,
        bl,
        ble,
        bler,
        blh,
        blhr,
        blr,
        bne,
        bner,
        bnh,
        bnhe,
        bnher,
        bnhr,
        bnl,
        bnle,
        bnler,
        bnlh,
        bnlhr,
        bnlr,
        bno,
        bnor,
        bo,
        bor,
        bprp,
        br,
        brasl,
        brc,
        brcl,
        brctg,
        bsm,
        c,
        cd,
        cdr,
        cgf,
        cghi,
        cgr,
        ch,
        chi,
        cl,
        clc,
        clcl,
        clg,
        clgr,
        cli,
        clmh,
        clr,
        cr,
        cvb,
        cvd,
        d,
        dd,
        ddr,
        dp,
        dr,
        edmk,
        ex,
        her,
        ic,
        icm,
        iihh,
        iihl,
        iilh,
        iill,
        j,
        je,
        jg,
        jge,
        jgh,
        jghe,
        jgl,
        jgle,
        jglh,
        jgne,
        jgnh,
        jgnhe,
        jgnl,
        jgnle,
        jgnlh,
        jgno,
        jgo,
        jh,
        jhe,
        jl,
        jle,
        jlh,
        jne,
        jnh,
        jnhe,
        jnl,
        jnle,
        jnlh,
        jno,
        jo,
        l,
        la,
        lae,
        lam,
        larl,
        lat,
        lay,
        lcr,
        ld,
        ldgr,
        ldr,
        lg,
        lgat,
        lgdr,
        lgf,
        lgfr,
        lgfrl,
        lghi,
        lghrl,
        lgr,
        lgrl,
        lh,
        lhi,
        lhrl,
        llgfrl,
        llghrl,
        llhrl,
        llill,
        lm,
        lmg,
        lnr,
        locgr,
        locgre,
        locgrh,
        locgrhe,
        locgrl,
        locgrle,
        locgrlh,
        locgrne,
        locgrnh,
        locgrnhe,
        locgrnl,
        locgrnle,
        locgrnlh,
        locgrno,
        locgro,
        lpdr,
        lper,
        lpr,
        lr,
        lra,
        lrl,
        lt,
        ltg,
        ltgf,
        ltgfr,
        ltgr,
        ltr,
        m,
        md,
        mdr,
        mh,
        mp,
        mr,
        ms,
        mvc,
        mvcl,
        mvcle,
        mvcs,
        mvhi,
        mvi,
        mvo,
        mvz,
        mxd,
        n,
        nc,
        ngr,
        nop,
        nopr,
        nr,
        o,
        oc,
        oi,
        or,
        pku,
        pr,
        s,
        sck,
        sd,
        sdr,
        se,
        sgr,
        sh,
        sigp,
        sla,
        slag,
        sll,
        sllg,
        sllk,
        slr,
        sp,
        spm,
        sr,
        sra,
        srag,
        srl,
        srlg,
        srp,
        ssm,
        st,
        stam,
        stc,
        std,
        ste,
        stg,
        stgrl,
        sth,
        sthrl,
        stm,
        stmg,
        strl,
        su,
        swr,
        trtr,
        unpka,
        unpku,
        x,
        xc,
        xi,
        xr,
    }
}
