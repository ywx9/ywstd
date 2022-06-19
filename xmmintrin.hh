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
#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(__m64, _mm_avg_pu16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_avg_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_cvt_pi2ps, __m128 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cvt_ps2pi, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpi16_ps, __m64 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpi32_ps, __m128 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_cvtpi32x2_ps, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m128, _mm_cvtpi8_ps, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_cvtps_pi16, __m128 a)
YW_INTRIN_FUNC(__m64, _mm_cvtps_pi32, __m128 a)
YW_INTRIN_FUNC(__m64, _mm_cvtps_pi8, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpu16_ps, __m64 a)
YW_INTRIN_FUNC(__m128, _mm_cvtpu8_ps, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_cvtt_ps2pi, __m128 a)
YW_INTRIN_FUNC(__m64, _mm_cvttps_pi32, __m128 a)
YW_INTRIN_FUNC(int, _mm_extract_pi16, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_insert_pi16, __m64 a, int i, int imm8)
YW_INTRIN_FUNC(__m64, _mm_max_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_max_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_min_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_min_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(int, _mm_movemask_pi8, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_mulhi_pu16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pavgb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pavgw, __m64 a, __m64 b)
YW_INTRIN_FUNC(int, _m_pextrw, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_pinsrw, __m64 a, int i, int imm8)
YW_INTRIN_FUNC(__m64, _m_pmaxsw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pmaxub, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pminsw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pminub, __m64 a, __m64 b)
YW_INTRIN_FUNC(int, _m_pmovmskb, __m64 a)
YW_INTRIN_FUNC(__m64, _m_pmulhuw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_psadbw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pshufw, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_sad_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_shuffle_pi16, __m64 a, int imm8)

#endif
YW_INTRIN_FUNC(__m128, _mm_add_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_add_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_and_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_andnot_ps, __m128 a, __m128 b)
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
YW_INTRIN_FUNC(__m128, _mm_cvt_si2ss, __m128 a, int b)
YW_INTRIN_FUNC(int, _mm_cvt_ss2si, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_cvtsi32_ss, __m128 a, int b)
YW_INTRIN_FUNC(__m128, _mm_cvtsi64_ss, __m128 a, __int64 b)
YW_INTRIN_FUNC(float, _mm_cvtss_f32, __m128 a)
YW_INTRIN_FUNC(int, _mm_cvtss_si32, __m128 a)
YW_INTRIN_FUNC(__int64, _mm_cvtss_si64, __m128 a)
YW_INTRIN_FUNC(int, _mm_cvtt_ss2si, __m128 a)
YW_INTRIN_FUNC(int, _mm_cvttss_si32, __m128 a)
YW_INTRIN_FUNC(__int64, _mm_cvttss_si64, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_div_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_div_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_max_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_max_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_min_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_min_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_move_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_movehl_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_movelh_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_movemask_ps, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_mul_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_mul_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_or_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(void, _mm_prefetch, char const* p, int i)
YW_INTRIN_FUNC(__m128, _mm_rcp_ps, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_rcp_ss, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_rsqrt_ps, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_rsqrt_ss, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_set_ps, float e3, float e2, float e1, float e0)
YW_INTRIN_FUNC(__m128, _mm_set_ps1, float a)
YW_INTRIN_FUNC(__m128, _mm_set_ss, float a)
YW_INTRIN_FUNC(__m128, _mm_set1_ps, float a)
YW_INTRIN_FUNC(__m128, _mm_setr_ps, float e3, float e2, float e1, float e0)
YW_INTRIN_FUNC(__m128, _mm_setzero_ps, void)
YW_INTRIN_FUNC(__m128, _mm_shuffle_ps, __m128 a, __m128 b, unsigned int imm8)
YW_INTRIN_FUNC(__m128, _mm_sqrt_ps, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_sqrt_ss, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_sub_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_sub_ss, __m128 a, __m128 b)
#ifdef _MM_TRANSPOSE4_PS
#undef _MM_TRANSPOSE4_PS
inline void _MM_TRANSPOSE4_PS(__m128 row0, __m128 row1, __m128 row2, __m128 row3) noexcept {
  __m128 t3, t2, t1, t0;
  t0 = _mm_shuffle_ps((row0), (row1), 0x44);
  t2 = _mm_shuffle_ps((row0), (row1), 0xEE);
  t1 = _mm_shuffle_ps((row2), (row3), 0x44);
  t3 = _mm_shuffle_ps((row2), (row3), 0xEE);
  (row0) = _mm_shuffle_ps(t0, t1, 0x88);
  (row1) = _mm_shuffle_ps(t0, t1, 0xDD);
  (row2) = _mm_shuffle_ps(t2, t3, 0x88);
  (row3) = _mm_shuffle_ps(t2, t3, 0xDD);
}
#else
YW_INTRIN_FUNC(void, _MM_TRANSPOSE4_PS, __m128 row0, __m128 row1, __m128 row2, __m128 row3)
#endif
YW_INTRIN_FUNC(int, _mm_ucomieq_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_ucomige_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_ucomigt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_ucomile_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_ucomilt_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm_ucomineq_ss, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_unpackhi_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_unpacklo_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128, _mm_xor_ps, __m128 a, __m128 b)
}
