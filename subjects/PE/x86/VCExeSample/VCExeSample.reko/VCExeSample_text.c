// VCExeSample_text.c
// Generated by decompiling VCExeSample.exe
// using Reko decompiler version 0.9.1.0.

#include "VCExeSample_text.h"

// 00401000: Register int32 main(Stack int32 argc, Stack (ptr32 (ptr32 char)) argv)
int32 main(int32 argc, char ** argv)
{
	test1(*argv, argc, "test123", 1.0F);
	return 0x00;
}

// 00401030: void test1(Stack (ptr32 char) arg1, Stack int32 arg2, Stack (ptr32 char) arg3, Stack real32 arg4)
// Called from:
//      main
//      test2
void test1(char * arg1, int32 arg2, char * arg3, real32 arg4)
{
	printf("%s %d %s %f", arg1, arg2, arg3, (real64) arg4);
}

// 00401060: void test2(Stack word32 dwArg04)
void test2(word32 dwArg04)
{
	test1("1", 0x02, "3", g_r4020F0);
	if (dwArg04 == 0x00)
		test1("5", 0x06, "7", g_r4020EC);
}

// 004010B0: void indirect_call_test3(Stack (ptr32 Eq_n) c)
void indirect_call_test3(cdecl_class * c)
{
	c->vtbl->method04(c, 1000);
}

// 004010D0: void test4()
void test4()
{
	gbl_c->vtbl->method00(gbl_c);
}

// 004010F0: void test5()
void test5()
{
	gbl_c->vtbl->method04(gbl_c, 999, g_r4020F4);
}

// 00401120: void test6(Stack Eq_n c, Stack int32 a, Stack int32 b)
// Called from:
//      nested_if_blocks_test8
void test6(Eq_n c, int32 a, int32 b)
{
	c->vtbl->method04(c, c->vtbl->sum(c, a, b));
}

// 00401160: void test7(Stack real64 rArg04)
void test7(real64 rArg04)
{
	if (rArg04 > 1.0)
		gbl_thiscall->vtbl->set_double(gbl_thiscall, rArg04);
	gbl_thiscall->vtbl->modify_double(gbl_thiscall, 0x0D, rArg04);
}

// 004011B0: void nested_if_blocks_test8(Stack real64 rArg04)
// Called from:
//      loop_test11
void nested_if_blocks_test8(real64 rArg04)
{
	gbl_thiscall->vtbl->modify_double(gbl_thiscall, ~0x00, rArg04);
	if (g_r402100 != rArg04 && g_r4020F8 > rArg04)
		gbl_thiscall->vtbl->set_double(gbl_thiscall, rArg04);
	test6(gbl_c, 0x06, 0x07);
}

// 00401230: void loop_test9(Stack real32 rArg04)
// Called from:
//      loop_test11
void loop_test9(real32 rArg04)
{
	int32 dwLoc08_n;
	for (dwLoc08_n = 0x00; gbl_thiscall->vtbl->modify_double(gbl_thiscall, dwLoc08_n, (real64) rArg04) > (real64) dwLoc08_n; ++dwLoc08_n)
		gbl_thiscall->vtbl->set_double(gbl_thiscall, (real64) rArg04);
}

// 004012A0: void const_div_test10(Stack word32 dwArg04)
void const_div_test10(word32 dwArg04)
{
	uint32 eax_n = 0x0A;
	uint32 ecx_n = 0x03;
	if (dwArg04 != 0x00)
	{
		eax_n = 0x03;
		ecx_n = 0x01;
	}
	g_dw40302C = ecx_n;
	g_dw403030 = eax_n;
}

// 004012D0: void loop_test11(Stack real64 rArg04)
void loop_test11(real64 rArg04)
{
	int32 dwLoc08_n;
	for (dwLoc08_n = 0x05; dwLoc08_n > 0x00; --dwLoc08_n)
	{
		ui32 eax_n = dwLoc08_n & 0x80000001;
		if ((dwLoc08_n & 0x80000001) < 0x00)
			eax_n = ((dwLoc08_n & 0x80000001) - 0x01 | ~0x01) + 0x01;
		if (eax_n == 0x00)
			loop_test9((real32) rArg04);
		else
			nested_if_blocks_test8(rArg04);
	}
}

// 00401330: void nested_structs_test12(Stack (ptr32 Eq_n) dwArg04)
// Called from:
//      nested_structs_test13
void nested_structs_test12(nested_structs_type * dwArg04)
{
	dwArg04->a = 0x01;
	dwArg04->str.b = 0x02;
	dwArg04->str.c = 0x03;
	dwArg04->d = 0x04;
}

// 00401360: void nested_structs_test13(Stack (ptr32 Eq_n) str)
void nested_structs_test13(nested_structs_type * str)
{
	nested_structs_test12(str);
}

// 00401380: void gbl_nested_structs_test14()
void gbl_nested_structs_test14()
{
	// gbl_nested_structs.a = 5
	gbl_nested_structs.a = 0x05;
	// gbl_nested_structs.str.b = 6
	gbl_nested_structs.str.b = 0x06;
	// gbl_nested_structs.str.c = 7
	gbl_nested_structs.str.c = 0x07;
	// gbl_nested_structs.d = 8
	gbl_nested_structs.d = 0x08;
}

// 004013B0: FpuStack real64 double_return_test15(Stack real64 d)
real64 double_return_test15(real64 d)
{
	return d;
}

