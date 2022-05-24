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

YW_INTRIN_FUNC(__m128i, _mm_hadd_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_hadd_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_hadds_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_hsub_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_hsub_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_hsubs_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_maddubs_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_mulhrs_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_shuffle_epi8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sign_epi8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sign_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sign_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_alignr_epi8, __m128i, __m128i, int);
YW_INTRIN_FUNC(__m128i, _mm_abs_epi8, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_abs_epi16, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_abs_epi32, __m128i);

#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(__m64, _mm_hadd_pi16, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_hadd_pi32, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_hadds_pi16, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_hsub_pi16, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_hsub_pi32, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_hsubs_pi16, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_maddubs_pi16, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_mulhrs_pi16, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_shuffle_pi8, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_sign_pi8, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_sign_pi16, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_sign_pi32, __m64, __m64);
YW_INTRIN_FUNC(__m64, _mm_alignr_pi8, __m64, __m64, int);
YW_INTRIN_FUNC(__m64, _mm_abs_pi8, __m64);
YW_INTRIN_FUNC(__m64, _mm_abs_pi16, __m64);
YW_INTRIN_FUNC(__m64, _mm_abs_pi32, __m64);
#endif

}
