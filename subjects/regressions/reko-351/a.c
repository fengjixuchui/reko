// a.c
// Generated by decompiling a.out
// using Reko decompiler version 0.6.2.0.

#include "a.h"

void deregister_tm_clones()
{
	if (false && 0x00 != 0x00)
	{
		word32 a7_39;
		word32 a6_40;
		word32 d0_41;
		byte CVZN_42;
		byte CVZNX_43;
		word32 d1_44;
		byte C_45;
		word32 a0_46;
		byte ZN_47;
		byte V_48;
		byte Z_49;
		null();
	}
	return;
}

void register_tm_clones()
{
	int32 d0_11 = 0x00;
	if (true)
		d0_11 = 0x01;
	int32 d0_15 = d0_11 >> 0x01;
	if (d0_15 != 0x00 && 0x00 != 0x00)
	{
		word32 a7_49;
		word32 a6_50;
		word32 d0_51;
		byte CVZN_52;
		byte CVZNX_53;
		byte N_54;
		byte Z_55;
		word32 a0_56;
		byte ZN_57;
		byte C_58;
		byte V_59;
		null();
	}
	return;
}

void __do_global_dtors_aux(word32 d2)
{
	if (globals->b80002724 == 0x00)
	{
		uint32 d0_105 = globals->dw80002726;
		Eq_324 a2_106[] = globals->a80002714;
		if (0x00 - d0_105 > 0x00)
		{
			do
			{
				ui32 d0_107 = d0_105 + 0x01;
				globals->dw80002726 = d0_107;
				<anonymous> * a0_112 = a2_106[d0_107].ptr0000;
				word32 a7_113;
				word32 a6_114;
				byte CVZN_116;
				word32 d2_117;
				byte ZN_118;
				byte C_119;
				byte V_120;
				byte Z_121;
				word32 d0_122;
				byte CVZNX_123;
				byte VZ_124;
				word32 a0_125;
				bcuiposr0 None_126;
				byte CZ_127;
				a0_112();
				d0_105 = globals->dw80002726;
			} while (0x00 - d0_105 > 0x00);
		}
		deregister_tm_clones();
		if (0x00 != 0x00)
		{
			word32 a7_89;
			word32 a6_90;
			word32 a2_91;
			byte CVZN_92;
			word32 d2_93;
			byte ZN_94;
			byte C_95;
			byte V_96;
			byte Z_97;
			word32 d0_98;
			byte CVZNX_99;
			byte VZ_100;
			word32 a0_101;
			bcuiposr0 None_102;
			byte CZ_103;
			null();
		}
		globals->b80002724 = 0x01;
	}
	return;
}

void call___do_global_dtors_aux()
{
	return;
}

void frame_dummy()
{
	if (0x00 != 0x00)
	{
		word32 a7_83;
		word32 a6_84;
		word32 a0_85;
		byte ZN_86;
		byte C_87;
		byte V_88;
		byte Z_89;
		word32 a1_90;
		byte CVZN_91;
		word32 d0_92;
		byte CVZNX_93;
		byte N_94;
		null();
	}
	if (globals->dw8000271C != 0x00 && 0x00 != 0x00)
	{
		word32 a7_64;
		word32 a6_65;
		word32 a0_66;
		byte ZN_67;
		byte C_68;
		byte V_69;
		byte Z_70;
		word32 a1_71;
		byte CVZN_72;
		word32 d0_73;
		byte CVZNX_74;
		byte N_75;
		null();
		register_tm_clones();
		return;
	}
	else
	{
		register_tm_clones();
		return;
	}
}

void call_frame_dummy()
{
	return;
}

void sine_taylor(real64 rArg04)
{
	return;
}

int32 _ZL9factoriali(int32 dwArg04)
{
	int32 dwLoc0C_15 = 0x01;
	int32 dwLoc08_12 = 0x02;
	while (dwLoc08_12 - dwArg04 <= 0x00)
	{
		dwLoc0C_15 = dwLoc0C_15 *s dwLoc08_12;
		dwLoc08_12 = dwLoc08_12 + 0x01;
	}
	return dwLoc0C_15;
}

real80 _ZL7pow_intdi(real64 rArg04, int32 dwArg0C)
{
	int32 dwLoc08_10 = 0x00;
	while (dwLoc08_10 - dwArg0C < 0x00)
		dwLoc08_10 = dwLoc08_10 + 0x01;
	return (real80) DPB(rLoc18, 0x3FF00000, 0);
}

void sine_taylor(real64 rArg04, int32 dwArg0C)
{
	word32 dwArg04_5 = (word32) rArg04;
	int32 dwLoc08_24 = 0x03;
	while (dwLoc08_24 - dwArg0C <= 0x00)
	{
		rLoc28 = DPB(rLoc28, dwArg04_5, 0);
		_ZL7pow_intdi(rLoc28, dwLoc08_24);
		_ZL9factoriali(dwLoc08_24);
		dwLoc08_24 = dwLoc08_24 + 0x04;
	}
	int32 dwLoc08_108 = 0x05;
	while (dwLoc08_108 - dwArg0C <= 0x00)
	{
		rLoc28 = DPB(rLoc28, dwArg04_5, 0);
		_ZL7pow_intdi(rLoc28, dwLoc08_108);
		_ZL9factoriali(dwLoc08_108);
		dwLoc08_108 = dwLoc08_108 + 0x04;
	}
	return;
}

void main()
{
	sine_taylor(DPB(rLoc10, 0x40091EB8, 0));
	_sin(DPB(rLoc1C, 0x40091EB8, 0), DPB(rLoc14, 1063818100, 0), fp - 0x08);
	return;
}

void _sin(real64 rArg04, real64 rArg0C, Eq_233 tArg14)
{
	Eq_244 rLoc0C_117 = DPB(rLoc0C, SLICE(rArg04, word32, 32), 32);
	Eq_248 v9_28 = (real64) ((real80) rLoc0C_117 * rLoc0C_117);
	int32 dwLoc20_132 = 0x01;
	while ((real64) ((real80) rLoc0C_117 / rLoc14) >= rArg0C)
	{
		*tArg14 = (word32) *tArg14 + 0x01;
		word32 v24_77 = dwLoc20_132 + 0x01;
		rLoc0C_117 = (real64) ((real80) (real64) ((real80) rLoc0C_117 * v9_28) * v9_28);
		dwLoc20_132 = v24_77 + 0x03;
		rLoc14 = (real64) ((real80) (real64) ((real80) (real64) ((real80) (real64) ((real80) rLoc14 * (real80) v24_77) * (real80) (v24_77 + 0x01)) * (real80) (v24_77 + 0x02)) * (real80) (v24_77 + 0x03));
	}
	return;
}

void __do_global_ctors_aux()
{
	<anonymous> * a0_12 = globals->ptr8000270C;
	if (-0x01 - a0_12 != 0x00)
	{
		do
		{
			word32 a7_26;
			word32 a6_27;
			ptr32 a2_28;
			byte CVZN_29;
			word32 a0_30;
			word32 d0_31;
			byte Z_32;
			a0_12();
		} while (-0x01 - *(a2_28 - 0x04) != 0x00);
	}
	return;
}

void call___do_global_ctors_aux()
{
	return;
}

