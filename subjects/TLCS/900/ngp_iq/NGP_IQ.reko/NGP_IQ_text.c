// NGP_IQ_text.c
// Generated by decompiling NGP_IQ.NGP
// using Reko decompiler version 0.9.4.0.

#include "NGP_IQ.h"

word32 g_dw200040 = 0x00200088; // 00200040
// 00200089: void fn00200089()
void fn00200089()
{
	fn0020060C();
	*(byte *) 0x6F86 |= 64;
	word32 * xix_n = &g_dw200040;
	word32 * xiy_n = (word32 *) 28600;
	byte b_n;
	for (b_n = 0x12; b_n != 0x00; --b_n)
	{
		*xiy_n = *xix_n;
		++xix_n;
		++xiy_n;
	}
	*(byte *) 0x8002 = 0x00;
	*(byte *) 0x8003 = 0x00;
	*(byte *) 0x8004 = 0xA0;
	*(byte *) 0x8005 = 0x98;
	word16 * xhl_n = (word16 *) 0xA000;
	word16 bc_n;
	for (bc_n = 0x0200; bc_n != 0x00; --bc_n)
	{
		*xhl_n = 0x00;
		++xhl_n;
	}
	word16 bc_n;
	word16 * xde_n = (word16 *) 0xA400;
	word16 * xhl_n = g_a20061D;
	for (bc_n = 0x0250; bc_n != 0x00; --bc_n)
	{
		*xde_n = *xhl_n;
		++xhl_n;
		++xde_n;
	}
	fn002005B8();
	__ei(0x00);
	word16 bc_n;
	word16 * xde_n = (word16 *) 0x8300;
	word16 * xhl_n = g_a200ABD;
	for (bc_n = 0x10; bc_n != 0x00; --bc_n)
	{
		*xde_n = *xhl_n;
		++xhl_n;
		++xde_n;
	}
	*(byte *) 0x83E0 = 0x33;
	*(byte *) 33761 = 0x07;
	*(byte *) 0x8118 = 0x80;
	fn00200557(0x01, 0x00, &g_b2000FD);
	fn00200557(0x01, 0x01, &g_b200122);
	fn00200557(0x02, 0x04, &g_b200147);
	fn00200557(0x04, 0x05, &g_b200165);
	word32 xwa_n = fn00200557(0x04, 0x06, &g_b20017F);
	byte a_n = (byte) xwa_n;
	word16 xwa_16_16_n = SLICE(xwa_n, word16, 16);
	byte * xde_n = (byte *) 0x7000;
	byte * xhl_n = g_a200363;
	word16 bc_n;
	for (bc_n = 303; bc_n != 0x00; --bc_n)
	{
		*xde_n = *xhl_n;
		++xhl_n;
		++xde_n;
	}
	fn002004F2(SEQ(xwa_16_16_n, 0x01, a_n));
	word32 xsp_n;
	word32 xhl_n;
	(*(union Eq_n *) 0x7000)();
	word16 xhl_16_16_n = SLICE(xhl_n, word16, 16);
	fn00200532(SEQ(xhl_16_16_n, 3334));
	if (!fn00200532(SEQ(xhl_16_16_n, 3333)))
		fn00200557(0x0F, 0x04, &g_b2001D2);
	else
		fn00200557(0x0F, 0x04, &g_b2001E8);
	fn00200557(0x02, 0x08, &g_b2001FD);
	fn00200557(0x04, 0x09, &g_b200217);
	word32 xwa_n = fn00200557(0x04, 0x0A, &g_b200231);
	byte a_n = (byte) xwa_n;
	word16 xwa_16_16_n = SLICE(xwa_n, word16, 16);
	byte * xde_n = (byte *) 0x7000;
	byte * xhl_n = g_a200492;
	word16 bc_n;
	for (bc_n = 0x23; bc_n != 0x00; --bc_n)
	{
		*xde_n = *xhl_n;
		++xhl_n;
		++xde_n;
	}
	fn002004F2(SEQ(xwa_16_16_n, 0x01, a_n));
	word32 xsp_n;
	word32 xhl_n;
	(*(union Eq_n *) 0x7000)();
	word16 xhl_16_16_n = SLICE(xhl_n, word16, 16);
	fn00200532(SEQ(xhl_16_16_n, 3338));
	if (!fn00200532(SEQ(xhl_16_16_n, 3337)))
		fn00200557(0x0F, 0x08, &g_b200284);
	else
		fn00200557(0x0F, 0x08, &g_b20029A);
	fn00200557(0x02, 0x0C, &g_b2002AF);
	fn00200557(0x04, 0x0D, &g_b2002CB);
	word32 xwa_n = fn00200557(0x04, 0x0E, &g_b2002E5);
	byte a_n = (byte) xwa_n;
	word16 xwa_16_16_n = SLICE(xwa_n, word16, 16);
	byte * xde_n = (byte *) 0x7000;
	byte * xhl_n = g_a2004B5;
	word16 bc_n;
	for (bc_n = 0x2B; bc_n != 0x00; --bc_n)
	{
		*xde_n = *xhl_n;
		++xhl_n;
		++xde_n;
	}
	fn002004F2(SEQ(xwa_16_16_n, 0x01, a_n));
	word32 xhl_n;
	(*(union Eq_n *) 0x7000)();
	word16 xhl_16_16_n = SLICE(xhl_n, word16, 16);
	fn00200532(SEQ(xhl_16_16_n, 0x0D0E));
	if (!fn00200532(SEQ(xhl_16_16_n, 0x0D0D)))
		fn00200557(0x0F, 0x0C, &g_b200338);
	else
		fn00200557(0x0F, 0x0C, &g_b20034E);
	while (true)
		;
}

byte g_b2000FD = 0x2E; // 002000FD
byte g_b200122 = 0x2E; // 00200122
byte g_b200147 = 0x51; // 00200147
byte g_b200165 = 0x45; // 00200165
byte g_b20017F = 0x41; // 0020017F
byte g_b2001D2 = 0x4F; // 002001D2
byte g_b2001E8 = 0x4E; // 002001E8
byte g_b2001FD = 0x4E; // 002001FD
byte g_b200217 = 0x45; // 00200217
byte g_b200231 = 0x41; // 00200231
byte g_b200284 = 0x4F; // 00200284
byte g_b20029A = 0x4E; // 0020029A
byte g_b2002AF = 0x4C; // 002002AF
byte g_b2002CB = 0x45; // 002002CB
byte g_b2002E5 = 0x41; // 002002E5
byte g_b200338 = 0x4F; // 00200338
byte g_b20034E = 0x4E; // 0020034E
byte g_a200363[] = // 00200363
	{
	};
byte g_a200492[] = // 00200492
	{
	};
byte g_a2004B5[] = // 002004B5
	{
	};
// 002004F2: void fn002004F2(Register Eq_n w)
// Called from:
//      fn00200089
void fn002004F2(Eq_n w)
{
	byte w_n = SLICE(xwa, byte, 8);
	*(byte *) 0x4004 = 0x00;
	do
		;
	while (*(byte *) 0x4004 != w_n);
}

// 0020050A: FlagGroup bool fn0020050A(Register Eq_n hl)
// Called from:
//      fn00200532
bool fn0020050A(Eq_n hl)
{
	byte h_n = SLICE(xhl, byte, 8);
	byte l_n = (byte) xhl;
	return SLICE(cond((uint32) ((uint16) h_n * 0x02 + 0x9800 + (uint16) l_n * 0x40) + 0x01), bool, 4);
}

// 00200532: FlagGroup bool fn00200532(Register Eq_n xhl)
// Called from:
//      fn00200089
bool fn00200532(Eq_n xhl)
{
	byte h_n = SLICE(xhl, byte, 8);
	word16 xhl_16_16_n = SLICE(xhl, word16, 16);
	byte l_n = (byte) xhl;
	fn0020050A(xhl);
	return fn0020050A(SEQ(xhl_16_16_n, h_n + 0x01, l_n));
}

// 00200557: Register word32 fn00200557(Register bui8 c, Register byte b, Register (ptr32 byte) xhl)
// Called from:
//      fn00200089
word32 fn00200557(bui8 c, byte b, byte * xhl)
{
	word24 xwa_24_8_n = 0x00;
	struct Eq_n * xde_n = (uint32) (c * 0x02) + 0x9800 + (uint16) b * 0x40;
	byte b_n;
	for (b_n = 0x13; b_n != 0x00; --b_n)
	{
		cu8 v17_n = *xhl;
		word16 xwa_16_16_n = SLICE(xwa_24_8_n, word16, 8);
		word32 xwa_n = SEQ(xwa_24_8_n, v17_n);
		if (v17_n == 0x00)
			return xwa_n;
		++xhl;
		word32 * xde_n = xde_n + 1;
		word32 v24_n = *xde_n;
		xde_n = (struct Eq_n *) ((char *) xde_n + 1);
		xwa_24_8_n = SEQ(xwa_16_16_n, v24_n);
		xwa_n = SEQ(xwa_16_16_n, v24_n, xde_n->dw0000);
	}
	return xwa_n;
}

// 002005B8: void fn002005B8()
// Called from:
//      fn00200089
void fn002005B8()
{
	byte * xbc_n = (byte *) 0x9000;
	word16 hl_n;
	for (hl_n = 0x04C0; hl_n != 0x00; --hl_n)
	{
		*xbc_n = 0x00;
		++xbc_n;
	}
	byte * xbc_n = (byte *) 0x9800;
	word16 hl_n;
	for (hl_n = 0x04C0; hl_n != 0x00; --hl_n)
	{
		*xbc_n = 0x00;
		++xbc_n;
	}
}

// 002005F5: void fn002005F5(Register bui8 w, Register byte a, Register word16 xwa_16_n, Register word32 xix, Register word16 sr)
void fn002005F5(bui8 w, byte a, word16 xwa_16_n, word32 xix, word16 sr)
{
	__ldf(0x03);
	<anonymous> *** xwa_n = SEQ(xwa_16_n, w * 0x04, a);
	<anonymous> ** v9_n = *xwa_n;
	(*v9_n)();
}

// 0020060C: void fn0020060C()
// Called from:
//      fn00200089
void fn0020060C()
{
	if (*(byte *) 0x6F91 == 0x00)
	{
		*(byte *) 0x6F83 &= ~0x08;
		*(byte *) 0x6DA0 = 0x00;
	}
}

word16 g_a20061D[] = // 0020061D
	{
	};
word16 g_a200ABD[] = // 00200ABD
	{
	};
