// RTOSDemo_text_memcpy.c
// Generated by decompiling RTOSDemo.axf
// using Reko decompiler version 0.9.1.0.

#include "RTOSDemo_text_memcpy.h"

// 0000A5C4: FlagGroup bool memcpy(Register Eq_n r0, Register Eq_n r1, Register Eq_n r2, Register Eq_n r4, Register Eq_n r5, Register Eq_n r6, Register Eq_n r7, Register Eq_n lr, Register out ptr32 r4Out, Register out ptr32 r5Out, Register out ptr32 r6Out, Register out ptr32 r7Out, Register out ptr32 lrOut)
// Called from:
//      prvCopyDataToQueue
//      prvCopyDataFromQueue
//      xQueueCRReceive
//      xQueueCRReceiveFromISR
bool memcpy(Eq_n r0, Eq_n r1, Eq_n r2, Eq_n r4, Eq_n r5, Eq_n r6, Eq_n r7, Eq_n lr, ptr32 & r4Out, ptr32 & r5Out, ptr32 & r6Out, ptr32 & r7Out, ptr32 & lrOut)
{
	Eq_n r5_n = r0;
	if (r2 > 0x0F)
	{
		if ((r1 | r0) << 30 != 0x00)
		{
			r5_n = r0;
l0000A630:
			Eq_n r3_n = 0x00;
			do
			{
				Mem100[r5_n + r3_n:byte] = SLICE(CONVERT(Mem97[r1 + r3_n:byte], byte, word32), byte, 0);
				r3_n = (word32) r3_n + 1;
			} while (r3_n != r2);
l0000A63C:
			ptr32 r4_n;
			ptr32 r5_n;
			ptr32 r6_n;
			ptr32 r7_n;
			ptr32 lr_n;
			byte NZCV_n;
			lr();
			r4Out = r4_n;
			r5Out = r5_n;
			r6Out = r6_n;
			r7Out = r7_n;
			lrOut = lr_n;
			return SLICE(NZCV_n, bool, 2);
		}
		Eq_n r4_n = r1;
		Eq_n r3_n = r0;
		Eq_n r5_n = (word32) r0 + ((r2 - 0x10 >> 4) + 0x01 << 4);
		do
		{
			*r3_n = *r4_n;
			*((word32) r3_n + 4) = *((word32) r4_n + 4);
			*((word32) r3_n + 8) = *((word32) r4_n + 8);
			*((word32) r3_n + 0x0C) = *((word32) r4_n + 0x0C);
			r3_n = (word32) r3_n + 16;
			r4_n = (word32) r4_n + 16;
		} while (r5_n != r3_n);
		ui32 r6_n = r2 - 0x10 & ~0x0F;
		r5_n = (word32) r0 + (r6_n + 0x10);
		r1 = (word32) r1 + (r6_n + 0x10);
		if ((r2 & 0x0F) > 0x03)
		{
			uint32 r6_n = (r2 & 0x0F) - 0x04;
			int32 r3_n = 0x00;
			uint32 r4_n = (r6_n >> 2) + 0x01;
			do
			{
				*((word32) r5_n + r3_n) = *((word32) r1 + r3_n);
				r3_n += 0x04;
			} while (r3_n != r4_n << 2);
			union Eq_n * r6_n = r6_n & ~0x03;
			r2 &= 0x03;
			r1 += r6_n + 0x04;
			r5_n += r6_n + 0x04;
		}
		else
			r2 &= 0x0F;
	}
	if (r2 == 0x00)
		goto l0000A63C;
	goto l0000A630;
}

