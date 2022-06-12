// ywstd/xmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "mmintrin.hh"

#ifdef _ywstd_
#include <xmmintrin.h>
namespace yw::intrin { using ::__m128; }
#else
namespace yw::intrin {
union alignas(16) __m128 { // MSVC
  float m128_f32[4];
  signed char m128_i8[16];
  short m128_i16[8];
  int m128_i32[4];
  long long m128_i64[2];
  unsigned char m128_u8[16];
  unsigned short m128_u16[8];
  unsigned int m128_u32[4];
  unsigned long long m128_u64[2];
};
}
#endif

namespace yw::intrin {
YW_INTRIN_FUNC(__m128, _mm_add_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_add_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_and_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_andnot_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m64, _mm_avg_pu16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_avg_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_cmpeq_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpeq_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpge_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpge_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpgt_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpgt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmple_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmple_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmplt_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmplt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpneq_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpneq_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpnge_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpnge_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpngt_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpngt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpnle_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpnle_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpnlt_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpnlt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpord_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpord_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpunord_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cmpunord_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_comieq_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_comige_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_comigt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_comile_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_comilt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_comineq_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_cvt_pi2ps, __m128 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cvt_ps2pi, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_cvt_si2ss, __m128 a, int b)
YW_INTRIN_FUNC(int, _mm_cvt_ss2si, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpi16_ps, __m64 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpi32_ps, __m128 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_cvtpi32x2_ps, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_cvtpi8_ps, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_cvtps_pi16, __m128 a)
YW_INTRIN_FUNC(__m64, _mm_cvtps_pi32, __m128 a)
YW_INTRIN_FUNC(__m64, _mm_cvtps_pi8, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpu16_ps, __m64 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpu8_ps, __m64 a)
YW_INTRIN_FUNC(__m128, _mm_cvtsi32_ss, __m128 a, int b)
YW_INTRIN_FUNC(__m128, _mm_cvtsi64_ss, __m128 a, __int64 b)
YW_INTRIN_FUNC(float, _mm_cvtss_f32, __m128 a)
YW_INTRIN_FUNC(int, _mm_cvtss_si32, __m128 a)
YW_INTRIN_FUNC(__int64, _mm_cvtss_si64, __m128 a)
YW_INTRIN_FUNC(__m64, _mm_cvtt_ps2pi, __m128 a)
YW_INTRIN_FUNC(int, _mm_cvtt_ss2si, __m128 a)
YW_INTRIN_FUNC(__m64, _mm_cvttps_pi32, __m128 a)
YW_INTRIN_FUNC(int, _mm_cvttss_si32, __m128 a)
YW_INTRIN_FUNC(__int64, _mm_cvttss_si64, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_div_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_div_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_extract_pi16, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_insert_pi16, __m64 a, int i, int imm8)
YW_INTRIN_FUNC(__m64, _mm_max_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_max_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m64, _mm_max_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_max_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m64, _mm_min_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_min_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m64, _mm_min_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_min_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_move_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_movehl_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_movelh_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_movemask_pi8, __m64 a)
YW_INTRIN_FUNC(int, _mm_movemask_ps, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_mul_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_mul_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m64, _mm_mulhi_pu16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_or_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m64, _m_pavgb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pavgw, __m64 a, __m64 b)
YW_INTRIN_FUNC(int, _m_pextrw, __m64 a, int imm8)
}
