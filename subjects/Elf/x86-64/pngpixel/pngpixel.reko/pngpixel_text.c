// pngpixel_text.c
// Generated by decompiling pngpixel
// using Reko decompiler version 0.9.1.0.

#include "pngpixel_text.h"

// 0000000000400CD0: void _start(Register (ptr64 Eq_n) rdx, Stack Eq_n qwArg00)
void _start(void (* rdx)(), Eq_n qwArg00)
{
	__align((char *) fp + 8);
	__libc_start_main(&g_t4012F9, qwArg00, (char *) fp + 8, &g_t401780, &g_t4017F0, rdx, fp);
	__hlt();
}

// 0000000000400D00: void deregister_tm_clones()
// Called from:
//      __do_global_dtors_aux
void deregister_tm_clones()
{
	if (false || 0x00 == 0x00)
		return;
	null();
}

// 0000000000400D40: void register_tm_clones()
// Called from:
//      frame_dummy
void register_tm_clones()
{
	if (0 == 0x00 || 0x00 == 0x00)
		return;
	null();
}

// 0000000000400D80: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	if (g_b602108 == 0x00)
	{
		deregister_tm_clones();
		g_b602108 = 0x01;
	}
}

// 0000000000400DA0: void frame_dummy()
void frame_dummy()
{
	if (g_qw601E10 != 0x00 && 0x00 != 0x00)
	{
		fn0000000000000000();
		register_tm_clones();
	}
	else
		register_tm_clones();
}

// 0000000000400DC6: Register word32 component(Register Eq_n ecx, Register word32 edx, Register word32 esi, Register word64 rdi, Register int32 r8d)
// Called from:
//      print_pixel
word32 component(Eq_n ecx, word32 edx, word32 esi, word64 rdi, int32 r8d)
{
	Eq_n ecx = (word32) rcx;
	ui32 eax_n = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (edx + (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) esi) & 0x3F)) *s r8d))) *s ecx);
	struct Eq_n * v16_n = rdi + ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) esi) >> 0x06)) *s r8d)) *s ecx))) << 0x03) + (uint64) ((word32) ((uint64) ((word32) ((uint64) eax_n) >> 0x03)));
	if (ecx > 0x10)
		goto l0000000000400EC1;
	uint64 rax_n;
	switch (ecx)
	{
	case 0x00:
	case 0x03:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x09:
	case 0x0A:
	case 11:
	case 0x0C:
	case 0x0D:
	case 0x0E:
	case 0x0F:
l0000000000400EC1:
		fprintf(g_ptr602100, "pngpixel: invalid bit depth %u\n", (uint64) ecx);
		exit(0x01);
	case 0x01:
		rax_n = (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (byte) (word32) v16_n->b0000 >> (byte) ((uint64) ((word32) ((uint64) (0x07 - (eax_n & 0x07)))))) & 0x01);
		break;
	case 0x02:
		rax_n = (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (byte) (word32) v16_n->b0000 >> (byte) ((uint64) ((word32) ((uint64) (0x06 - (eax_n & 0x07)))))) & 0x03);
		break;
	case 0x04:
		rax_n = (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (byte) (word32) v16_n->b0000 >> (byte) ((uint64) ((word32) ((uint64) (0x04 - (eax_n & 0x07)))))) & 0x0F);
		break;
	case 0x08:
		rax_n = SEQ(SLICE(v16_n, word32, 32), (word32) (byte) (word32) v16_n->b0000);
		break;
	case 0x10:
		rax_n = (uint64) ((word32) (byte) (word32) v16_n->b0001 + (word32) ((uint64) ((word32) ((uint64) ((word32) ((byte) ((word32) v16_n->b0000)) << 0x08)))));
		break;
	}
	return (word32) rax_n;
}

// 0000000000400EE9: void print_pixel(Register word32 ecx, Register word64 rdx, Register word64 rsi, Register word64 rdi, Register (ptr32 Eq_n) fs)
// Called from:
//      main
void print_pixel(word32 ecx, word64 rdx, word64 rsi, word64 rdi, struct Eq_n * fs)
{
	word64 rax_n = fs->qw0028;
	word64 rcx_n;
	word64 rax_n;
	png_get_bit_depth();
	word32 eax_n = (word32) (byte) rax_n;
	word64 rdx_n;
	word64 rcx_n;
	word64 rax_n;
	png_get_color_type();
	word32 ecx_n = (word32) rcx_n;
	up32 eax_n = (word32) (byte) rax_n;
	if (eax_n > 0x06)
		goto l00000000004012C9;
	switch (g_a401958[(uint64) eax_n])
	{
	case 0x00:
		printf("GRAY %u\n", (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x00, (word32) (uint64) ecx, rdx, 0x01));
		break;
	case 0x01:
	case 0x05:
l00000000004012C9:
		png_error();
		break;
	case 0x02:
		printf("RGB %u %u %u\n", (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x00, (word32) (uint64) ecx, rdx, 0x03), (uint64) (word32) (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x01, (word32) (uint64) ecx, rdx, 0x03), (uint64) (word32) (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x02, (word32) (uint64) ecx, rdx, 0x03));
		break;
	case 0x03:
		up32 eax_n = (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x00, (word32) (uint64) ecx, rdx, 0x01);
		word64 rax_n;
		png_get_PLTE();
		if ((word32) (uint64) ((word32) rax_n & 0x08) != 0x00 && (false && 0x00 != 0x00))
		{
			word64 rax_n;
			png_get_tRNS();
			if ((word32) (uint64) ((word32) rax_n & 0x10) != 0x00 && (false && 0x00 != 0x00))
			{
				word32 esi_n;
				if (eax_n < 0x00)
					esi_n = (word32) (byte) (word32) ((uint64) eax_n + 0x00);
				else
					esi_n = 0xFF;
				uint64 rdx_n = (uint64) eax_n;
				printf("INDEXED %u = %d %d %d %d\n", (uint64) (word32) (uint64) eax_n, SEQ(SLICE(rdx_n, word32, 32), (word32) (byte) (word32) null[rdx_n].b0000), (uint64) (uint32) (word32) (byte) (word32) ((Eq_n[]) 0x01)[(uint64) eax_n].b0000, (uint64) (word32) (byte) (word32) ((Eq_n[]) 0x02)[(uint64) eax_n].b0000, (uint64) esi_n);
			}
			else
			{
				uint64 rdx_n = (uint64) eax_n;
				printf("INDEXED %u = %d %d %d\n", (uint64) (word32) (uint64) eax_n, SEQ(SLICE(rdx_n, word32, 32), (word32) (byte) (word32) null[rdx_n].b0000), (uint64) (uint32) (word32) (byte) (word32) ((Eq_n[]) 0x01)[(uint64) eax_n].b0000, (uint64) (word32) (byte) (word32) ((Eq_n[]) 0x02)[(uint64) eax_n]);
			}
		}
		else
			printf("INDEXED %u = invalid index\n", (uint64) (word32) (uint64) eax_n);
		break;
	case 0x04:
		printf("GRAY+ALPHA %u %u\n", (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x00, (word32) (uint64) ecx, rdx, 0x02), (uint64) (word32) (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x01, (word32) (uint64) ecx, rdx, 0x02));
		break;
	case 0x06:
		printf("RGBA %u %u %u %u\n", (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x00, (word32) (uint64) ecx, rdx, 0x04), (uint64) (word32) (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x01, (word32) (uint64) ecx, rdx, 0x04), (uint64) (word32) (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x02, (word32) (uint64) ecx, rdx, 0x04), (uint64) (word32) (uint64) (word32) (uint64) (uint32) component((uint64) (word32) (uint64) eax_n, 0x03, (word32) (uint64) ecx, rdx, 0x04));
		break;
	}
	if ((rax_n ^ fs->qw0028) == 0x00)
		return;
	__stack_chk_fail();
}

// 00000000004012F9: void main(Register (ptr64 Eq_n) rsi, Register word32 edi, Register (ptr32 Eq_n) fs)
void main(struct Eq_n * rsi, word32 edi, struct Eq_n * fs)
{
	word64 rax_n = fs->qw0028;
	if (edi != 0x04)
	{
		fwrite(&g_v401A70, 0x01, 0x27, g_ptr602100);
		goto l000000000040175D;
	}
	char * rax_n = rsi->ptr0008;
	uint64 rax_n = SEQ(SLICE(rax_n, word32, 32), atol(rax_n));
	char * rax_n = rsi->ptr0010;
	uint64 rax_n = SEQ(SLICE(rax_n, word32, 32), atol(rax_n));
	FILE * rax_n = fopen(rsi->ptr0018, "rb");
	if (rax_n == null)
	{
		fprintf(g_ptr602100, "pngpixel: %s: could not open file\n", rsi->ptr0018);
		goto l000000000040175D;
	}
	word64 rsi_n;
	word64 rax_n;
	word64 r9_n;
	word64 r8_n;
	png_create_read_struct();
	if (rax_n == 0x00)
	{
		fwrite(&g_v401A18, 0x01, 0x2E, g_ptr602100);
		goto l000000000040175D;
	}
	word64 rax_n;
	word64 rcx_n;
	word64 r9_n;
	word64 r8_n;
	png_create_info_struct();
	if (rax_n != 0x00)
	{
		png_init_io();
		png_read_info();
		word64 rax_n;
		png_get_rowbytes();
		word64 rax_n;
		png_malloc();
		word64 rax_n;
		word64 rcx_n;
		word64 r9_n;
		word64 r8_n;
		word64 rsi_n;
		png_get_IHDR();
		if ((word32) rax_n != 0x00)
		{
			word32 eax_n = (word32) (uint64) dwLoc78;
			if (eax_n != 0x00)
			{
				if (eax_n != 0x01)
				{
					word64 rcx_n;
					word64 r9_n;
					word64 r8_n;
					png_error();
				}
				else
					dwLoc6C = 0x07;
			}
			else
				dwLoc6C = 0x01;
			word64 rcx_n;
			word64 r9_n;
			word64 r8_n;
			png_start_read_image();
			int32 dwLoc68_n = 0x00;
			while ((word32) (uint64) dwLoc68_n < dwLoc6C)
			{
				word32 dwLoc5C_n;
				word32 dwLoc58_n;
				word32 dwLoc60_n;
				word32 dwLoc64_n;
				if ((word32) (uint64) dwLoc78 == 0x01)
				{
					word32 eax_n;
					if (dwLoc68_n > 0x01)
						eax_n = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc68_n)) >> 0x01))))) - 0x01);
					else
						eax_n = 0x07;
					word32 eax_n;
					uint32 edx_n = (word32) (uint64) (word32) (uint64) ((word32) (uint64) (eax_n - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_n))) & 0x01)) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_n) + 0x01)) >> 0x01)))))))))))) & 0x07))) + dwLoc88);
					if (dwLoc68_n > 0x01)
						eax_n = (word32) (uint64) ((word32) (uint64) (0x07 - dwLoc68_n) >> 0x01);
					else
						eax_n = 0x03;
					if ((word32) (uint64) (word32) (uint64) (edx_n >> (byte) ((uint64) eax_n)) == 0x00)
						goto l000000000040166F;
					word32 eax_n;
					dwLoc60_n = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) dwLoc68_n & 0x01) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_n) + 0x01)) >> 0x01))))))))) & 0x07);
					dwLoc64_n = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) ((word32) (uint64) ((word32) (uint64) dwLoc68_n & 0x01) == 0x00) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) dwLoc68_n) >> 0x01))))))))) & 0x07);
					dwLoc58_n = (word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc68_n)) >> 0x01)))));
					if (dwLoc68_n > 0x02)
						eax_n = (word32) (uint64) (word32) (uint64) (0x08 >> (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_n) - 0x01)) >> 0x01)))));
					else
						eax_n = 0x08;
					dwLoc5C_n = eax_n;
				}
				else
				{
					dwLoc60_n = 0x00;
					dwLoc64_n = 0x00;
					dwLoc58_n = 0x01;
					dwLoc5C_n = 0x01;
				}
				up32 dwLoc54_n;
				for (dwLoc54_n = (word32) (uint64) dwLoc64_n; dwLoc54_n < (word32) ((uint64) dwLoc84); dwLoc54_n += (word32) (uint64) dwLoc5C_n)
				{
					puts("png_read_row");
					word64 r9_n;
					word64 r8_n;
					png_read_row();
					if ((uint64) dwLoc54_n == rax_n)
					{
						up32 dwLoc50_n;
						word32 dwLoc4C_n = 0x00;
						for (dwLoc50_n = (word32) (uint64) dwLoc60_n; dwLoc50_n < (word32) ((uint64) dwLoc88); dwLoc50_n += (word32) (uint64) dwLoc58_n)
						{
							if ((uint64) dwLoc50_n == rax_n)
							{
								print_pixel((word32) (uint64) dwLoc4C_n, rax_n, rax_n, rax_n, fs);
								goto l000000000040167F;
							}
							++dwLoc4C_n;
						}
					}
				}
l000000000040166F:
				++dwLoc68_n;
			}
l000000000040167F:
			png_free();
			word64 rcx_n;
			word64 r9_n;
			word64 r8_n;
			png_destroy_info_struct();
l00000000004016DE:
			word64 rcx_n;
			word64 r9_n;
			word64 r8_n;
			png_destroy_read_struct();
l000000000040175D:
			if ((rax_n ^ fs->qw0028) == 0x00)
				return;
			__stack_chk_fail();
		}
		word64 rcx_n;
		word64 r9_n;
		word64 r8_n;
		png_error();
	}
	fwrite(&g_v4019E8, 0x01, 44, g_ptr602100);
	goto l00000000004016DE;
}

// 0000000000401780: void __libc_csu_init(Register word64 rdx, Register word64 rsi, Register word32 edi)
void __libc_csu_init(word64 rdx, word64 rsi, word32 edi)
{
	word32 edi = (word32) rdi;
	_init();
	word32 r15d_n = (word32) (uint64) edi;
	int64 rbp_n = 0x00601E08 - 0x00601E00;
	if (rbp_n >> 0x03 != 0x00)
	{
		Eq_n rbx_n = 0x00;
		do
		{
			(*((char *) g_a601E00 + rbx_n * 0x08))();
			rbx_n = (word64) rbx_n.u1 + 1;
		} while (rbx_n != rbp_n >> 0x03);
	}
}

// 00000000004017F0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

