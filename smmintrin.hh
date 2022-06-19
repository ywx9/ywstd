// ywstd/smmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off/

#pragma once

#include "tmmintrin.hh"

#ifdef _ywstd_
#include <smmintrin.h>
#endif

namespace yw::intrin {
inline constexpr int MM_FROUND_TO_NEAREST_INT = 0x00;
inline constexpr int MM_FROUND_TO_NEG_INF = 0x01;
inline constexpr int MM_FROUND_TO_POS_INF = 0x02;
inline constexpr int MM_FROUND_TO_ZERO = 0x03;
inline constexpr int MM_FROUND_CUR_DIRECTION = 0x04;
inline constexpr int MM_FROUND_RAISE_EXC = 0x00;
inline constexpr int MM_FROUND_NO_EXC = 0x08;
inline constexpr int MM_FROUND_NINT = MM_FROUND_TO_NEAREST_INT | MM_FROUND_RAISE_EXC;
inline constexpr int MM_FROUND_FLOOR = MM_FROUND_TO_NEG_INF | MM_FROUND_RAISE_EXC;
inline constexpr int MM_FROUND_CEIL = MM_FROUND_TO_POS_INF | MM_FROUND_RAISE_EXC;
inline constexpr int MM_FROUND_TRUNC = MM_FROUND_TO_ZERO | MM_FROUND_RAISE_EXC;
inline constexpr int MM_FROUND_RINT = MM_FROUND_CUR_DIRECTION | MM_FROUND_RAISE_EXC;
inline constexpr int MM_FROUND_NEARBYINT = MM_FROUND_CUR_DIRECTION | MM_FROUND_NO_EXC;
YW_INTRIN_FUNC(__m128i, _mm_blend_epi16, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(__m128d, _mm_blend_pd, __m128d a, __m128d b, const int imm8)
YW_INTRIN_FUNC(__m128, _mm_blend_ps, __m128 a, __m128 b, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_blendv_epi8, __m128i a, __m128i b, __m128i mask)
YW_INTRIN_FUNC(__m128d, _mm_blendv_pd, __m128d a, __m128d b, __m128d mask)
YW_INTRIN_FUNC(__m128, _mm_blendv_ps, __m128 a, __m128 b, __m128 mask)
#ifdef _mm_ceil_pd
#undef _mm_ceil_pd
inline __m128d _mm_ceil_pd(__m128d a) noexcept { return _mm_round_pd(a, MM_FROUND_CEIL); }
#else
YW_INTRIN_FUNC(__m128d, _mm_ceil_pd, __m128d a)
#endif
#ifdef _mm_ceil_ps
#undef _mm_ceil_ps
inline __m128 _mm_ceil_ps(__m128 a) noexcept { return _mm_round_ps(a, MM_FROUND_CEIL); }
#else
YW_INTRIN_FUNC(__m128, _mm_ceil_ps, __m128 a)
#endif
#ifdef _mm_ceil_sd
#undef _mm_ceil_sd
inline __m128d _mm_ceil_sd(__m128d a, __m128d b) noexcept { return _mm_round_sd(a, b, MM_FROUND_CEIL); }
#else
YW_INTRIN_FUNC(__m128d, _mm_ceil_sd, __m128d a, __m128d b)
#endif
#ifdef _mm_ceil_ss
#undef _mm_ceil_ss
inline __m128 _mm_ceil_ss(__m128 a, __m128 b) noexcept { return _mm_round_ss(a, b, MM_FROUND_CEIL); }
#else
YW_INTRIN_FUNC(__m128, _mm_ceil_ss, __m128 a, __m128 b)
#endif
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi64, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_cvtepi16_epi32, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepi16_epi64, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepi32_epi64, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepi8_epi16, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepi8_epi32, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepi8_epi64, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepu16_epi32, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepu16_epi64, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepu32_epi64, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepu8_epi16, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepu8_epi32, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_cvtepu8_epi64, __m128i a)
YW_INTRIN_FUNC(__m128d, _mm_dp_pd, __m128d a, __m128d b, const int imm8)
YW_INTRIN_FUNC(__m128, _mm_dp_ps, __m128 a, __m128 b, const int imm8)
YW_INTRIN_FUNC(int, _mm_extract_epi32, __m128i a, const int imm8)
YW_INTRIN_FUNC(__int64, _mm_extract_epi64, __m128i a, const int imm8)
YW_INTRIN_FUNC(int, _mm_extract_epi8, __m128i a, const int imm8)
YW_INTRIN_FUNC(int, _mm_extract_ps, __m128 a, const int imm8)
#ifdef _mm_floor_pd
#undef _mm_floor_pd
inline __m128d _mm_floor_pd(__m128d a) noexcept { return _mm_round_pd(a, MM_FROUND_FLOOR); }
#else
YW_INTRIN_FUNC(__m128d, _mm_floor_pd, __m128d a)
#endif
#ifdef _mm_floor_ps
#undef _mm_floor_ps
inline __m128 _mm_floor_ps(__m128 a) noexcept { return _mm_round_ps(a, MM_FROUND_FLOOR); }
#else
YW_INTRIN_FUNC(__m128, _mm_floor_ps, __m128 a)
#endif
#ifdef _mm_floor_sd
#undef _mm_floor_sd
inline __m128d _mm_floor_sd(__m128d a, __m128d b) noexcept { return _mm_round_sd(a, b, MM_FROUND_FLOOR); }
#else
YW_INTRIN_FUNC(__m128d, _mm_floor_sd, __m128d a, __m128d b)
#endif
#ifdef _mm_floor_ss
#undef _mm_floor_ss
inline __m128 _mm_floor_ss(__m128 a, __m128 b) noexcept { return _mm_round_ss(a, b, MM_FROUND_FLOOR); }
#else
YW_INTRIN_FUNC(__m128, _mm_floor_ss, __m128 a, __m128 b)
#endif
YW_INTRIN_FUNC(__m128i, _mm_insert_epi32, __m128i a, int i, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_insert_epi64, __m128i a, __int64 i, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_insert_epi8, __m128i a, int i, const int imm8)
YW_INTRIN_FUNC(__m128, _mm_insert_ps, __m128 a, __m128 b, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_max_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_max_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_max_epu16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_max_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_min_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_min_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_min_epu16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_min_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_minpos_epu16, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_mpsadbw_epu8, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_mul_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_mullo_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_packus_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128d, _mm_round_pd, __m128d a, int rounding)
YW_INTRIN_FUNC(__m128, _mm_round_ps, __m128 a, int rounding)
YW_INTRIN_FUNC(__m128d, _mm_round_sd, __m128d a, __m128d b, int rounding)
YW_INTRIN_FUNC(__m128, _mm_round_ss, __m128 a, __m128 b, int rounding)
YW_INTRIN_FUNC(__m128i, _mm_stream_load_si128, __m128i* mem_addr)
#ifdef _mm_test_all_ones
#undef _mm_test_all_ones
inline int _mm_test_all_ones(__m128i a) noexcept { return _mm_testc_si128(a, _mm_cmpeq_epi32(a, a)); }
#else
YW_INTRIN_FUNC(int, _mm_test_all_ones, __m128i a)
#endif
#ifdef _mm_test_all_zeros
#undef _mm_test_all_zeros
inline int _mm_test_all_zeros(__m128i a, __m128i mask) noexcept { return _mm_testz_si128(a, mask); }
#else
YW_INTRIN_FUNC(int, _mm_test_all_zeros, __m128i a, __m128i mask)
#endif
#ifdef _mm_test_mix_ones_zeros
#undef _mm_test_mix_ones_zeros
inline int _mm_test_mix_ones_zeros(__m128i a, __m128i mask) noexcept { return _mm_testnzc_si128(a, mask); }
#else
YW_INTRIN_FUNC(int, _mm_test_mix_ones_zeros, __m128i a, __m128i mask)
#endif
YW_INTRIN_FUNC(int, _mm_testc_si128, __m128i a, __m128i b)
YW_INTRIN_FUNC(int, _mm_testnzc_si128, __m128i a, __m128i b)
YW_INTRIN_FUNC(int, _mm_testz_si128, __m128i a, __m128i b)
}
