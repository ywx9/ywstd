// ywstd/tmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "pmmintrin.hh"

#ifdef _ywstd_
#include <tmmintrin.h>
#endif

namespace yw::intrin {
#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(__m64, _mm_abs_pi16, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_abs_pi32, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_abs_pi8, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_alignr_pi8, __m64 a, __m64 b, int imm8)
YW_INTRIN_FUNC(__m64, _mm_hadd_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_hadd_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_hadds_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_hsub_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_hsub_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_hsubs_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_maddubs_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_mulhrs_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_shuffle_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_sign_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_sign_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_sign_pi8, __m64 a, __m64 b)
#endif
YW_INTRIN_FUNC(__m128i, _mm_abs_epi16, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_abs_epi32, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_abs_epi8, __m128i a)
#ifdef _mm_alignr_epi8
#undef _mm_alignr_epi8
#define YW_INTRIN_MM_ALIGNR_EPI8_IS_TEMPLATE
template<int Imm8> __m128i _mm_alignr_epi8(__m128i a, __m128i b) noexcept {
  return (__m128i)__builtin_ia32_palignr128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm_alignr_epi8, __m128i a, __m128i b, int imm8)
#endif
YW_INTRIN_FUNC(__m128i, _mm_hadd_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_hadd_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_hadds_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_hsub_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_hsub_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_hsubs_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_maddubs_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_mulhrs_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_shuffle_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sign_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sign_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sign_epi8, __m128i a, __m128i b)
}
