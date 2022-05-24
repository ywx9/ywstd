// ywstd/wmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "nmmintrin.hh"

#ifdef _ywstd_
#include <wmmintrin.h>
#endif

namespace yw::intrin {

YW_INTRIN_FUNC(__m128i, _mm_aesdec_si128, __m128i v, __m128i rkey);
YW_INTRIN_FUNC(__m128i, _mm_aesdeclast_si128, __m128i v, __m128i rkey);
YW_INTRIN_FUNC(__m128i, _mm_aesenc_si128, __m128i v, __m128i rkey);
YW_INTRIN_FUNC(__m128i, _mm_aesenclast_si128, __m128i v, __m128i rkey);
YW_INTRIN_FUNC(__m128i, _mm_aesimc_si128, __m128i v);
YW_INTRIN_FUNC(__m128i, _mm_aeskeygenassist_si128, __m128i ckey, const int rcon);
YW_INTRIN_FUNC(__m128i, _mm_clmulepi64_si128, __m128i v1, __m128i v2, const int imm8);

}
