// ywstd/smmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "tmmintrin.hh"

#ifdef _ywstd_
#include <smmintrin.h>
#endif

#undef _MM_FROUND_TO_NEAREST_INT
#undef _MM_FROUND_TO_NEG_INF
#undef _MM_FROUND_TO_POS_INF
#undef _MM_FROUND_TO_ZERO
#undef _MM_FROUND_CUR_DIRECTION
#undef _MM_FROUND_RAISE_EXC
#undef _MM_FROUND_NO_EXC
#undef _MM_FROUND_NINT
#undef _MM_FROUND_FLOOR
#undef _MM_FROUND_CEIL
#undef _MM_FROUND_TRUNC
#undef _MM_FROUND_RINT
#undef _MM_FROUND_NEARBYINT

namespace yw::intrin {

inline constexpr int4 _MM_FROUND_TO_NEAREST_INT = 0x00;
inline constexpr int4 _MM_FROUND_TO_NEG_INF = 0x01;
inline constexpr int4 _MM_FROUND_TO_POS_INF = 0x02;
inline constexpr int4 _MM_FROUND_TO_ZERO = 0x03;
inline constexpr int4 _MM_FROUND_CUR_DIRECTION = 0x04;
inline constexpr int4 _MM_FROUND_RAISE_EXC = 0x00;
inline constexpr int4 _MM_FROUND_NO_EXC = 0x08;

inline constexpr int4 _MM_FROUND_NINT = _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_RAISE_EXC;
inline constexpr int4 _MM_FROUND_FLOOR = _MM_FROUND_TO_NEG_INF | _MM_FROUND_RAISE_EXC;
inline constexpr int4 _MM_FROUND_CEIL = _MM_FROUND_TO_POS_INF | _MM_FROUND_RAISE_EXC;
inline constexpr int4 _MM_FROUND_TRUNC = _MM_FROUND_TO_ZERO | _MM_FROUND_RAISE_EXC;
inline constexpr int4 _MM_FROUND_RINT = _MM_FROUND_CUR_DIRECTION | _MM_FROUND_RAISE_EXC;
inline constexpr int4 _MM_FROUND_NEARBYINT = _MM_FROUND_CUR_DIRECTION | _MM_FROUND_NO_EXC;

YW_INTRIN_FUNC(__m128i, _mm_blend_epi16, __m128i, __m128i, const int mask);
YW_INTRIN_FUNC(__m128i, _mm_blendv_epi8, __m128i, __m128i, __m128i mask);
YW_INTRIN_FUNC(__m128, _mm_blend_ps, __m128, __m128, const int mask);
YW_INTRIN_FUNC(__m128, _mm_blendv_ps, __m128, __m128, __m128 mask);
YW_INTRIN_FUNC(__m128d, _mm_blend_pd, __m128d, __m128d, const int mask);
YW_INTRIN_FUNC(__m128d, _mm_blendv_pd, __m128d, __m128d, __m128d mask);
YW_INTRIN_FUNC(__m128, _mm_dp_ps, __m128, __m128, const int mask);
YW_INTRIN_FUNC(__m128d, _mm_dp_pd, __m128d, __m128d, const int mask);
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi64, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_min_epi8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_max_epi8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_min_epu16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_max_epu16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_min_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_max_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_min_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_max_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_mullo_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_mul_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(int, _mm_testz_si128, __m128i mask, __m128i val);
YW_INTRIN_FUNC(int, _mm_testc_si128, __m128i mask, __m128i val);
YW_INTRIN_FUNC(int, _mm_testnzc_si128, __m128i mask, __m128i val);
YW_INTRIN_FUNC(__m128, _mm_insert_ps, __m128 dst, __m128 src, const int index);
YW_INTRIN_FUNC(int, _mm_extract_ps, __m128 src, const int index);
YW_INTRIN_FUNC(__m128i, _mm_insert_epi8, __m128i dst, int src, const int index);
YW_INTRIN_FUNC(__m128i, _mm_insert_epi32, __m128i dst, int src, const int index);
YW_INTRIN_FUNC(int, _mm_extract_epi8, __m128i src, const int index);
YW_INTRIN_FUNC(int, _mm_extract_epi32, __m128i src, const int index);
YW_INTRIN_FUNC(__m128i, _mm_minpos_epu16, __m128i);
YW_INTRIN_FUNC(__m128d, _mm_round_pd, __m128d val, int RoundMode);
YW_INTRIN_FUNC(__m128d, _mm_round_sd, __m128d dst, __m128d val, int RoundMode);
YW_INTRIN_FUNC(__m128, _mm_round_ps, __m128 val, int RoundMode);
YW_INTRIN_FUNC(__m128, _mm_round_ss, __m128 dst, __m128 val, int RoundMode);
YW_INTRIN_FUNC(__m128i, _mm_cvtepi8_epi32, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepi16_epi32, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepi8_epi64, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepi32_epi64, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepi16_epi64, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepi8_epi16, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepu8_epi32, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepu16_epi32, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepu8_epi64, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepu32_epi64, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepu16_epi64, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtepu8_epi16, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_packus_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_mpsadbw_epu8, __m128i s1, __m128i s2, const int mask);
YW_INTRIN_FUNC(__m128i, _mm_stream_load_si128, const __m128i*);

inline __m128d _mm_ceil_pd(__m128d val) { return _mm_round_pd(val, 0); }
inline __m128d _mm_ceil_sd(__m128d dst, __m128d val) { return _mm_round_sd(dst, val, 0); }
inline __m128 _mm_ceil_ps(__m128 val) { return _mm_round_ps(val, 0); }
inline __m128 _mm_ceil_ss(__m128 dst, __m128 val) { return _mm_round_ss(dst, val, 0); }
inline __m128d _mm_floor_pd(__m128d val) { return _mm_round_pd(val, 0); }
inline __m128d _mm_floor_sd(__m128d dst, __m128d val) { return _mm_round_sd(dst, val, 0); }
inline __m128 _mm_floor_ps(__m128 val) { return _mm_round_ps(val, 0); }
inline __m128 _mm_floor_ss(__m128 dst, __m128 val) { return _mm_round_ss(dst, val, 0); }
inline int _mm_test_all_zeros(__m128i mask, __m128i val) { return _mm_testz_si128(mask, val); }
inline int _mm_test_all_ones(__m128i val) { return _mm_testc_si128(val, _mm_cmpeq_epi32(val, val)); }
inline int _mm_test_mix_ones_zeros(__m128i mask, __m128i val) { return _mm_testnzc_si128(mask, val); }

#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(__m128i, _mm_insert_epi64, __m128i dst, __int64 src, const int index);
YW_INTRIN_FUNC(__int64, _mm_extract_epi64, __m128i src, const int index);
#endif

}
