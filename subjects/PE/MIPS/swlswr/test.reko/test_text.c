// test_text.c
// Generated by decompiling test.exe
// using Reko decompiler version 0.9.3.0.

#include "test.h"

// 00011000: Register word32 fn00011000()
// Called from:
//      fn000110E8
word32 fn00011000()
{
	memset(fp + -20, 0x00, 5);
	struct Eq_n * r2_n = calloc(1, 5);
	memcpy(r2_n, fp + -20, 5);
	r2_n->b0000 = 0x0C;
	r2_n->dw0001 = 0x00;
	return 0x00;
}

// 000110A0: Register Eq_n Win32CrtStartup()
Eq_n Win32CrtStartup()
{
	fn000111C4();
	return fn000110E8();
}

// 000110E8: Register Eq_n fn000110E8()
// Called from:
//      Win32CrtStartup
Eq_n fn000110E8()
{
	fn000114E4();
	Eq_n r2_n = fn00011000();
	fn00011278(r2_n);
	return r2_n;
}

// 0001116C: void fn0001116C(Register (ptr32 Eq_n) r2, Register (ptr32 (ptr32 word32)) r4, Stack word32 dwArg00)
void fn0001116C(struct Eq_n * r2, word32 ** r4, word32 dwArg00)
{
	r2->ptrFFFFFFEC = r4;
	r2->ptrFFFFFFF0 = r2->ptrFFFFFFEC;
	r2->dwFFFFFFF4 = **r2->ptrFFFFFFEC;
	word32 r8_n = r2->dwFFFFFFF4;
	r2->dwFFFFFFE8 = r8_n;
	XcptFilter();
}

// 000111C4: void fn000111C4()
// Called from:
//      Win32CrtStartup
void fn000111C4()
{
	ui32 r8_n = g_dw13030;
	if (r8_n != 0x00 && r8_n != 0xB064)
		g_dw13034 = ~r8_n;
	else
	{
		uint32 r2_n;
		COREDLL.dll!Ordinal_n();
		ui32 r8_n = r2_n >> 0x10 ^ r2_n + 0xFFFF;
		ui32 dwLoc0C_n = r8_n;
		if (r8_n == 0x00)
			dwLoc0C_n = 0xB064;
		g_dw13030 = dwLoc0C_n;
		g_dw13034 = ~dwLoc0C_n;
	}
}

// 00011278: void fn00011278(Register Eq_n r4)
// Called from:
//      fn000110E8
void fn00011278(Eq_n r4)
{
	fn000112A8(r4, 0x00, 0x00);
}

// 000112A8: void fn000112A8(Register Eq_n r4, Register int32 r5, Register int32 r6)
// Called from:
//      fn00011278
//      fn000113D8
//      fn00011408
//      fn00011434
void fn000112A8(Eq_n r4, int32 r5, int32 r6)
{
	g_b13038 = (byte) (int32) (byte) r6;
	if (r5 != 0x00)
	{
		fn0001147C(&g_dw12018, &g_dw1201C);
		if (r6 != 0x00)
			return;
		TerminateProcess(fn00011460(), r4);
	}
	else if (g_t13040 == 0x00)
	{
l00011374:
		fn0001147C(&g_dw12010, &g_dw12014);
	}
	else
	{
		do
		{
			g_t1303C = (word32) g_t1303C - 4;
			if ((word32) (g_t1303C < g_t13040) != 0x00)
			{
				free(g_t13040);
				g_t1303C.u0 = 0x00;
				g_t13040 = g_t1303C;
				goto l00011374;
			}
		} while (*g_t1303C == null);
		<anonymous> * r8_n = *g_t1303C;
		r8_n();
	}
}

// 000113D8: void fn000113D8(Register Eq_n r4)
void fn000113D8(Eq_n r4)
{
	fn000112A8(r4, 1, 0x00);
}

// 00011408: void fn00011408()
void fn00011408()
{
	fn000112A8(0x00, 0x00, 1);
}

// 00011434: void fn00011434()
void fn00011434()
{
	fn000112A8(0x00, 1, 1);
}

// 00011460: Register int32 fn00011460()
// Called from:
//      fn000112A8
int32 fn00011460()
{
	return 66;
}

// 0001147C: void fn0001147C(Register (ptr32 word32) r4, Register (ptr32 word32) r5)
// Called from:
//      fn000112A8
//      fn000114E4
void fn0001147C(word32 * r4, word32 * r5)
{
	word32 * dwArg00_n = r4;
	while ((word32) (dwArg00_n < r5) != 0x00)
	{
		if (*dwArg00_n != 0x00)
			fn00000000();
		++dwArg00_n;
	}
}

// 000114E4: void fn000114E4()
// Called from:
//      fn000110E8
void fn000114E4()
{
	fn0001147C(&g_dw12008, &g_dw1200C);
	fn0001147C(&g_dw12000, &g_dw12004);
}

// 0001152C: Register word32 fn0001152C()
// Called from:
//      fn000116FC
word32 fn0001152C()
{
	Eq_n r8_n = g_t13040;
	struct Eq_n * sp_n = fp + -56;
	if (g_t1303C - r8_n >= 0x00)
	{
		if (r8_n != 0x00)
		{
			word32 r5_n;
			msize();
			sp_n = fp + ~0x33;
		}
		if ((word32) (sp_n->t0018 < sp_n->t0024) != 0x00)
		{
			if (sp_n->t001C == 0x00)
				sp_n->t0014 = malloc(16);
			else
			{
				sp_n->t0020 = sp_n->t0018 << 0x01;
				if ((word32) (sp_n->t0018 < 513) == 0x00)
					sp_n->t0020 = (word32) sp_n->t0018 + 0x0200;
				if ((word32) (sp_n->t0018 < sp_n->t0020) != 0x00)
					sp_n->t0014 = realloc(sp_n->t001C, sp_n->t0020);
				if (sp_n->t0014 == 0x00 && (word32) (sp_n->t0018 < sp_n->t0024) != 0x00)
					sp_n->t0014 = realloc(sp_n->t001C, sp_n->t0024);
			}
			if (sp_n->t0014 == 0x00)
			{
				sp_n->ptr002C = null;
				return dwLoc0C;
			}
			sp_n->t0028 = (word32) sp_n->t0014 + ((sp_n->t0028 - sp_n->t001C >> 0x02) << 0x02);
			sp_n->t001C = sp_n->t0014;
		}
		*sp_n->t0028 = sp_n->ptr0038;
		sp_n->t0028 = (word32) sp_n->t0028 + 4;
		g_t1303C = sp_n->t0028;
		g_t13040 = sp_n->t001C;
		sp_n->ptr002C = sp_n->ptr0038;
		return dwLoc0C;
	}
	else
	{
		dwLoc0C = 0x00;
		return dwLoc0C;
	}
}

// 000116FC: void fn000116FC()
void fn000116FC()
{
	fn0001152C() == 0x00;
}

