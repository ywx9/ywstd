// ywstd/emmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "xmmintrin.hh"

#ifdef _ywstd_
#include <emmintrin.h>
namespace yw::intrin {
using ::__m128d;
using ::__m128i;
using ::__m256;
}
#else
namespace yw::intrin {
union alignas(16) __m128d { // MSVC
  double m128d_f64[2];
};
union alignas(16) __m128i { // MSVC
  char m128i_i8[16];
  short m128i_i16[8];
  int m128i_i32[4];
  long long m128i_i64[2];
  unsigned char m128i_u8[16];
  unsigned short m128i_u16[8];
  unsigned int m128i_u32[4];
  unsigned long long m128i_u64[2];
};
union alignas(16) __m256 { // MSVC
  float m256_f32[8];
};
}
#endif

namespace yw::intrin {
#ifdef YW_INTRIN_FP16
YW_INTRIN_FUNC(float, _cvtsh_ss, unsigned short a)
#endif
YW_INTRIN_FUNC(__m128i, _mm_add_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_add_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_add_epi64, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_add_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128d, _mm_add_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_add_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m64, _mm_add_si64, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128i, _mm_adds_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_adds_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_adds_epu16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_adds_epu8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128d, _mm_and_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128i, _mm_and_si128, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128d, _mm_andnot_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128i, _mm_andnot_si128, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_avg_epu16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_avg_epu8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_bslli_si128, __m128i a, int imm8)
YW_INTRIN_FUNC(__m128i, _mm_bsrli_si128, __m128i a, int imm8)
YW_INTRIN_FUNC(__m128, _mm_castpd_ps, __m128d a)
YW_INTRIN_FUNC(__m128i, _mm_castpd_si128, __m128d a)
YW_INTRIN_FUNC(__m128d, _mm_castps_pd, __m128 a)
YW_INTRIN_FUNC(__m128i, _mm_castps_si128, __m128 a)
YW_INTRIN_FUNC(__m128d, _mm_castsi128_pd, __m128i a)
YW_INTRIN_FUNC(__m128, _mm_castsi128_ps, __m128i a)
YW_INTRIN_FUNC(void, _mm_clflush, void const* p)
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128d, _mm_cmpeq_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpeq_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpge_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpge_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128d, _mm_cmpgt_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpgt_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmple_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmple_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128i, _mm_cmplt_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_cmplt_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_cmplt_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128d, _mm_cmplt_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmplt_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpneq_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpneq_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpnge_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpnge_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpngt_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpngt_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpnle_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpnle_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpnlt_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpnlt_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpord_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpord_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpunord_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cmpunord_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm_comieq_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm_comige_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm_comigt_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm_comile_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm_comilt_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm_comineq_sd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128d, _mm_cvtepi32_pd, __m128i a)
YW_INTRIN_FUNC(__m128, _mm_cvtepi32_ps, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtpd_epi32, __m128d a)
YW_INTRIN_FUNC(__m64, _mm_cvtpd_pi32, __m128d a)
YW_INTRIN_FUNC(__m128, _mm_cvtpd_ps, __m128d a)
YW_INTRIN_FUNC(__m128, _mm_cvtph_ps, __m128i a)
YW_INTRIN_FUNC(__m256, _mm256_cvtph_ps, __m128i a)
YW_INTRIN_FUNC(__m128d, _mm_cvtpi32_pd, __m64 a)
YW_INTRIN_FUNC(__m128i, _mm_cvtps_epi32, __m128 a)
YW_INTRIN_FUNC(__m128d, _mm_cvtps_pd, __m128 a)
YW_INTRIN_FUNC(__m128i, _mm_cvtps_ph, __m128 a, int sae)
YW_INTRIN_FUNC(__m128i, _mm256_cvtps_ph, __m256 a, int sae)
YW_INTRIN_FUNC(double, _mm_cvtsd_f64, __m128d a)
YW_INTRIN_FUNC(int, _mm_cvtsd_si32, __m128d a)
YW_INTRIN_FUNC(__int64, _mm_cvtsd_si64, __m128d a)
YW_INTRIN_FUNC(__int64, _mm_cvtsd_si64x, __m128d a)
YW_INTRIN_FUNC(__m128, _mm_cvtsd_ss, __m128 a, __m128d b)
}
