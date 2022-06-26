// ywstd/wmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "nmmintrin.hh"

#ifdef _ywstd_
#include <wmmintrin.h>
#endif

namespace yw::intrin {
YW_INTRIN_FUNC(__m128i, _mm_aesdec_si128, __m128i a, __m128i RoundKey)
YW_INTRIN_FUNC(__m128i, _mm_aesdeclast_si128, __m128i a, __m128i RoundKey)
YW_INTRIN_FUNC(__m128i, _mm_aesenc_si128, __m128i a, __m128i RoundKey)
YW_INTRIN_FUNC(__m128i, _mm_aesenclast_si128, __m128i a, __m128i RoundKey)
YW_INTRIN_FUNC(__m128i, _mm_aesimc_si128, __m128i a)
#ifdef _mm_aeskeygenassist_si128
#undef _mm_aeskeygenassist_si128
#define YW_INTRIN_MM_AESKEYGENASSIST_SI128_IS_TEMPLATE
template<int Imm8> __m128i _mm_aeskeygenassist_si128(__m128i a) noexcept {
  return (__m128i)__builtin_ia32_aeskeygenassist128((__v2di)a, Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm_aeskeygenassist_si128, __m128i a, const int imm8)
#endif
#ifdef _mm_clmulepi64_si128
#undef _mm_clmulepi64_si128
#define YW_INTRIN_MM_CLMULEPI64_SI128_IS_TEMPLATE
template<int Imm8> __m128i _mm_clmulepi64_si128(__m128i a, __m128i b) noexcept {
  return (__m128i)__builtin_ia32_pclmulqdq128((__v2di)a, (__v2di)b, (char)Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm_clmulepi64_si128, __m128i a, __m128i b, const int imm8)
#endif
}
