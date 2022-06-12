// ywstd/zmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "wmmintrin.hh"

#ifdef _ywstd_
#include <zmmintrin.h>
#include <intrin.h>
namespace yw::intrin {
using ::__m256;
using ::__m256d;
using ::__m256i;
using ::__m512;
using ::__m512d;
using ::__m512i;
using ::__mmask16;
using ::__mmask32;
using ::__mmask64;
using ::__mmask8;
}
#else
namespace yw::intrin {
using __mmask8 = unsigned char;
using __mmask16 = unsigned short;
using __mmask32 = unsigned int;
using __mmask64 = unsigned __int64;
union alignas(64) __m512 {
  float m512_f32[16];
};
union alignas(64) __m512d {
  double m512d_f64[8];
} union alignas(64) __m512i {
  char m512i_i8[64];
  short m512i_i16[32];
  int m512i_i32[16];
  long long m512i_i64[8];
  unsigned char m512i_u8[64];
  unsigned short m512i_u16[32];
  unsigned int m512i_u32[16];
  unsigned long long m512i_u64[8];
};
}
#endif

namespace yw::intrin {
#ifdef YW_INTRIN_FP16
YW_INTRIN_FUNC(__m512h, _mm512_abs_ph, __m512h v2)
YW_INTRIN_FUNC(__m512h, _mm512_add_ph, __m512h a, __m512h b)
YW_INTRIN_FUNC(__m512h, _mm512_mask_add_ph, __m512h src, __mmask32 k, __m512h a, __m512h b)
YW_INTRIN_FUNC(__m512h, _mm512_maskz_add_ph, __mmask32 k, __m512h a, __m512h b)
YW_INTRIN_FUNC(__m512h, _mm512_add_round_ph, __m512h a, __m512h b, int rounding)
YW_INTRIN_FUNC(__m512h, _mm512_mask_add_round_ph, __m512h src, __mmask32 k, __m512h a, __m512h b, int rounding)
YW_INTRIN_FUNC(__m512h, _mm512_maskz_add_round_ph, __mmask32 k, __m512h a, __m512h b, int rounding)
YW_INTRIN_FUNC(__m512h, _mm512_mask_blend_ph, __mmask32 k, __m512h a, __m512h b)
#endif
#ifdef YW_INTRIN_KNC
YW_INTRIN_FUNC(__m512i, _mm512_adc_epi32, __m512i v2, __mmask16 k2, __m512i v3, __mmask16* k2_res)
YW_INTRIN_FUNC(__m512i, _mm512_mask_adc_epi32, __m512i v2, __mmask16 k1, __mmask16 k2, __m512i v3, __mmask16* k2_res)
YW_INTRIN_FUNC(__m512d, _mm512_addn_pd, __m512d v2, __m512d v3)
YW_INTRIN_FUNC(__m512d, _mm512_mask_addn_pd, __m512d src, __mmask8 k, __m512d v2, __m512d v3)
YW_INTRIN_FUNC(__m512, _mm512_addn_ps, __m512 v2, __m512 v3)
YW_INTRIN_FUNC(__m512, _mm512_mask_addn_ps, __m512 src, __mmask16 k, __m512 v2, __m512 v3)
YW_INTRIN_FUNC(__m512d, _mm512_addn_round_pd, __m512d v2, __m512d v3, int rounding)
YW_INTRIN_FUNC(__m512d, _mm512_mask_addn_round_pd, __m512d src, __mmask8 k, __m512d v2, __m512d v3, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_addn_round_ps, __m512 v2, __m512 v3, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_mask_addn_round_ps, __m512 src, __mmask16 k, __m512 v2, __m512 v3, int rounding)
YW_INTRIN_FUNC(__m512i, _mm512_addsetc_epi32, __m512i v2, __m512i v3, __mmask16* k2_res)
YW_INTRIN_FUNC(__m512i, _mm512_mask_addsetc_epi32, __m512i v2, __mmask16 k, __mmask16 k_old, __m512i v3, __mmask16* k2_res)
YW_INTRIN_FUNC(__m512i, _mm512_addsets_epi32, __m512i v2, __m512i v3, __mmask16* sign)
YW_INTRIN_FUNC(__m512i, _mm512_mask_addsets_epi32, __m512i src, __mmask16 k, __m512i v2, __m512i v3, __mmask16* sign)
YW_INTRIN_FUNC(__m512, _mm512_addsets_ps, __m512 v2, __m512 v3, __mmask16* sign)
YW_INTRIN_FUNC(__m512, _mm512_mask_addsets_ps, __m512 src, __mmask16 k, __m512 v2, __m512 v3, __mmask16* sign)
YW_INTRIN_FUNC(__m512, _mm512_addsets_round_ps, __m512 v2, __m512 v3, __mmask16* sign, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_mask_addsets_round_ps, __m512 src, __mmask16 k, __m512 v2, __m512 v3, __mmask16* sign, int rounding)
#endif
#ifdef YW_INTRIN_AVX512_4VNNIW
YW_INTRIN_FUNC(__m512i, _mm512_4dpwssd_epi32, __m512i src, __m512i a0, __m512i a1, __m512i a2, __m512i a3, __m128i* b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_4dpwssd_epi32, __m512i src, __mmask16 k, __m512i a0, __m512i a1, __m512i a2, __m512i a3, __m128i* b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_4dpwssd_epi32, __mmask16 k, __m512i src, __m512i a0, __m512i a1, __m512i a2, __m512i a3, __m128i* b)
YW_INTRIN_FUNC(__m512i, _mm512_4dpwssds_epi32, __m512i src, __m512i a0, __m512i a1, __m512i a2, __m512i a3, __m128i* b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_4dpwssds_epi32, __m512i src, __mmask16 k, __m512i a0, __m512i a1, __m512i a2, __m512i a3, __m128i* b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_4dpwssds_epi32, __mmask16 k, __m512i src, __m512i a0, __m512i a1, __m512i a2, __m512i a3, __m128i* b)
#endif
#ifdef YW_INTRIN_AVX512_4FMAPS
YW_INTRIN_FUNC(__m512, _mm512_4fmadd_ps, __m512 src, __m512 a0, __m512 a1, __m512 a2, __m512 a3, __m128* b)
YW_INTRIN_FUNC(__m512, _mm512_mask_4fmadd_ps, __m512 src, __mmask16 k, __m512 a0, __m512 a1, __m512 a2, __m512 a3, __m128* b)
YW_INTRIN_FUNC(__m512, _mm512_maskz_4fmadd_ps, __mmask16 k, __m512 src, __m512 a0, __m512 a1, __m512 a2, __m512 a3, __m128* b)
YW_INTRIN_FUNC(__m512, _mm512_4fnmadd_ps, __m512 src, __m512 a0, __m512 a1, __m512 a2, __m512 a3, __m128* b)
YW_INTRIN_FUNC(__m512, _mm512_mask_4fnmadd_ps, __m512 src, __mmask16 k, __m512 a0, __m512 a1, __m512 a2, __m512 a3, __m128* b)
YW_INTRIN_FUNC(__m512, _mm512_maskz_4fnmadd_ps, __mmask16 k, __m512 src, __m512 a0, __m512 a1, __m512 a2, __m512 a3, __m128* b)
#endif
YW_INTRIN_FUNC(void, _mm512_2intersect_epi32, __m512i a, __m512i b, __mmask16* k1, __mmask16* k2)
YW_INTRIN_FUNC(void, _mm512_2intersect_epi64, __m512i a, __m512i b, __mmask8* k1, __mmask8* k2)
YW_INTRIN_FUNC(__m512i, _mm512_abs_epi16, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_mask_abs_epi16, __m512i src, __mmask32 k, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_abs_epi16, __mmask32 k, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_abs_epi32, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_mask_abs_epi32, __m512i src, __mmask16 k, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_abs_epi32, __mmask16 k, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_abs_epi64, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_mask_abs_epi64, __m512i src, __mmask8 k, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_abs_epi64, __mmask8 k, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_abs_epi8, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_mask_abs_epi8, __m512i src, __mmask64 k, __m512i a)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_abs_epi8, __mmask64 k, __m512i a)
YW_INTRIN_FUNC(__m512d, _mm512_abs_pd, __m512d v2)
YW_INTRIN_FUNC(__m512d, _mm512_abs_pd, __m512d v2)
YW_INTRIN_FUNC(__m512d, _mm512_mask_abs_pd, __m512d src, __mmask8 k, __m512d v2)
YW_INTRIN_FUNC(__m512d, _mm512_mask_abs_pd, __m512d src, __mmask8 k, __m512d v2)
YW_INTRIN_FUNC(__m512, _mm512_abs_ps, __m512 v2)
YW_INTRIN_FUNC(__m512, _mm512_abs_ps, __m512 v2)
YW_INTRIN_FUNC(__m512, _mm512_mask_abs_ps, __m512 src, __mmask16 k, __m512 v2)
YW_INTRIN_FUNC(__m512, _mm512_mask_abs_ps, __m512 src, __mmask16 k, __m512 v2)
YW_INTRIN_FUNC(__m512d, _mm512_acos_pd, __m512d a)
YW_INTRIN_FUNC(__m512d, _mm512_mask_acos_pd, __m512d src, __mmask8 k, __m512d a)
YW_INTRIN_FUNC(__m512, _mm512_acos_ps, __m512 a)
YW_INTRIN_FUNC(__m512, _mm512_mask_acos_ps, __m512 src, __mmask16 k, __m512 a)
YW_INTRIN_FUNC(__m512d, _mm512_acosh_pd, __m512d a)
YW_INTRIN_FUNC(__m512d, _mm512_mask_acosh_pd, __m512d src, __mmask8 k, __m512d a)
YW_INTRIN_FUNC(__m512, _mm512_acosh_ps, __m512 a)
YW_INTRIN_FUNC(__m512, _mm512_mask_acosh_ps, __m512 src, __mmask16 k, __m512 a)
YW_INTRIN_FUNC(__m512i, _mm512_add_epi16, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_add_epi16, __m512i src, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_add_epi16, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_add_epi32, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_add_epi32, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_add_epi32, __m512i src, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_add_epi32, __m512i src, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_add_epi32, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_add_epi64, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_add_epi64, __m512i src, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_add_epi64, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_add_epi8, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_add_epi8, __m512i src, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_add_epi8, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512d, _mm512_add_pd, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_add_pd, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_mask_add_pd, __m512d src, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_mask_add_pd, __m512d src, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_maskz_add_pd, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512, _mm512_add_ps, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_add_ps, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_mask_add_ps, __m512 src, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_mask_add_ps, __m512 src, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_maskz_add_ps, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512d, _mm512_add_round_pd, __m512d a, __m512d b, int rounding)
YW_INTRIN_FUNC(__m512d, _mm512_add_round_pd, __m512d a, __m512d b, int rounding)
YW_INTRIN_FUNC(__m512d, _mm512_mask_add_round_pd, __m512d src, __mmask8 k, __m512d a, __m512d b, int rounding)
YW_INTRIN_FUNC(__m512d, _mm512_mask_add_round_pd, __m512d src, __mmask8 k, __m512d a, __m512d b, int rounding)
YW_INTRIN_FUNC(__m512d, _mm512_maskz_add_round_pd, __mmask8 k, __m512d a, __m512d b, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_add_round_ps, __m512 a, __m512 b, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_add_round_ps, __m512 a, __m512 b, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_mask_add_round_ps, __m512 src, __mmask16 k, __m512 a, __m512 b, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_mask_add_round_ps, __m512 src, __mmask16 k, __m512 a, __m512 b, int rounding)
YW_INTRIN_FUNC(__m512, _mm512_maskz_add_round_ps, __mmask16 k, __m512 a, __m512 b, int rounding)
YW_INTRIN_FUNC(__m512i, _mm512_adds_epi16, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_adds_epi16, __m512i src, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_adds_epi16, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_adds_epi8, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_adds_epi8, __m512i src, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_adds_epi8, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_adds_epu16, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_adds_epu16, __m512i src, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_adds_epu16, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_adds_epu8, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_adds_epu8, __m512i src, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_adds_epu8, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_aesdec_epi128, __m512i a, __m512i RoundKey)
YW_INTRIN_FUNC(__m512i, _mm512_aesdeclast_epi128, __m512i a, __m512i RoundKey)
YW_INTRIN_FUNC(__m512i, _mm512_aesenc_epi128, __m512i a, __m512i RoundKey)
YW_INTRIN_FUNC(__m512i, _mm512_aesenclast_epi128, __m512i a, __m512i RoundKey)
YW_INTRIN_FUNC(__m512i, _mm512_alignr_epi32, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_alignr_epi32, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_mask_alignr_epi32, __m512i src, __mmask16 k, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_mask_alignr_epi32, __m512i src, __mmask16 k, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_alignr_epi32, __mmask16 k, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_alignr_epi64, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_mask_alignr_epi64, __m512i src, __mmask8 k, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_alignr_epi64, __mmask8 k, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_alignr_epi8, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_mask_alignr_epi8, __m512i src, __mmask64 k, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_alignr_epi8, __mmask64 k, __m512i a, __m512i b, const int imm8)
YW_INTRIN_FUNC(__m512i, _mm512_and_epi32, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_and_epi32, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_and_epi32, __m512i src, __mmask16 k, __m512i v2, __m512i v3)
YW_INTRIN_FUNC(__m512i, _mm512_mask_and_epi32, __m512i src, __mmask16 k, __m512i v2, __m512i v3)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_and_epi32, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_and_epi64, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_and_epi64, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_and_epi64, __m512i src, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_and_epi64, __m512i src, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_and_epi64, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512d, _mm512_and_pd, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_mask_and_pd, __m512d src, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_maskz_and_pd, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512, _mm512_and_ps, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_mask_and_ps, __m512 src, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_maskz_and_ps, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512i, _mm512_and_si512, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_and_si512, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_andnot_epi32, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_andnot_epi32, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_andnot_epi32, __m512i src, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_andnot_epi32, __m512i src, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_andnot_epi32, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_andnot_epi64, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_andnot_epi64, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_andnot_epi64, __m512i src, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_andnot_epi64, __m512i src, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_andnot_epi64, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512d, _mm512_andnot_pd, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_mask_andnot_pd, __m512d src, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_maskz_andnot_pd, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512, _mm512_andnot_ps, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_mask_andnot_ps, __m512 src, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_maskz_andnot_ps, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512i, _mm512_andnot_si512, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_andnot_si512, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512d, _mm512_asin_pd, __m512d a)
YW_INTRIN_FUNC(__m512d, _mm512_mask_asin_pd, __m512d src, __mmask8 k, __m512d a)
YW_INTRIN_FUNC(__m512, _mm512_asin_ps, __m512 a)
YW_INTRIN_FUNC(__m512, _mm512_mask_asin_ps, __m512 src, __mmask16 k, __m512 a)
YW_INTRIN_FUNC(__m512d, _mm512_asinh_pd, __m512d a)
YW_INTRIN_FUNC(__m512d, _mm512_mask_asinh_pd, __m512d src, __mmask8 k, __m512d a)
YW_INTRIN_FUNC(__m512, _mm512_asinh_ps, __m512 a)
YW_INTRIN_FUNC(__m512, _mm512_mask_asinh_ps, __m512 src, __mmask16 k, __m512 a)
YW_INTRIN_FUNC(__m512d, _mm512_atan_pd, __m512d a)
YW_INTRIN_FUNC(__m512d, _mm512_mask_atan_pd, __m512d src, __mmask8 k, __m512d a)
YW_INTRIN_FUNC(__m512, _mm512_atan_ps, __m512 a)
YW_INTRIN_FUNC(__m512, _mm512_mask_atan_ps, __m512 src, __mmask16 k, __m512 a)
YW_INTRIN_FUNC(__m512d, _mm512_atan2_pd, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_mask_atan2_pd, __m512d src, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512, _mm512_atan2_ps, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512, _mm512_mask_atan2_ps, __m512 src, __mmask16 k, __m512 a, __m512 b)
YW_INTRIN_FUNC(__m512d, _mm512_atanh_pd, __m512d a)
YW_INTRIN_FUNC(__m512d, _mm512_mask_atanh_pd, __m512d src, __mmask8 k, __m512d a)
YW_INTRIN_FUNC(__m512, _mm512_atanh_ps, __m512 a)
YW_INTRIN_FUNC(__m512, _mm512_mask_atanh_ps, __m512 src, __mmask16 k, __m512 a)
YW_INTRIN_FUNC(__m512i, _mm512_avg_epu16, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_avg_epu16, __m512i src, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_avg_epu16, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_avg_epu8, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_avg_epu8, __m512i src, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_maskz_avg_epu8, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__mmask64, _mm512_bitshuffle_epi64_mask, __m512i b, __m512i c)
YW_INTRIN_FUNC(__mmask64, _mm512_mask_bitshuffle_epi64_mask, __mmask64 k, __m512i b, __m512i c)
YW_INTRIN_FUNC(__m512i, _mm512_mask_blend_epi16, __mmask32 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_blend_epi32, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_blend_epi32, __mmask16 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_blend_epi64, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_blend_epi64, __mmask8 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512i, _mm512_mask_blend_epi8, __mmask64 k, __m512i a, __m512i b)
YW_INTRIN_FUNC(__m512d, _mm512_mask_blend_pd, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512d, _mm512_mask_blend_pd, __mmask8 k, __m512d a, __m512d b)
YW_INTRIN_FUNC(__m512, _mm512_mask_blend_ps, __mmask16 k, __m512 a, __m512 b)
}
