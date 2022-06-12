// ywstd/pmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "emmintrin.hh"

#ifdef _ywstd_
#include <pmmintrin.h>
#endif

namespace yw::intrin {
YW_INTRIN_FUNC(__m128d, _mm_addsub_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128, _mm_addsub_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128d, _mm_hadd_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128, _mm_hadd_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128d, _mm_hsub_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m128, _mm_hsub_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m128i, _mm_lddqu_si128, __m128i const* mem_addr)
YW_INTRIN_FUNC(__m128d, _mm_loaddup_pd, double const* mem_addr)
YW_INTRIN_FUNC(void, _mm_monitor, void const* p, unsigned extensions, unsigned hints)
YW_INTRIN_FUNC(__m128d, _mm_movedup_pd, __m128d a)
YW_INTRIN_FUNC(__m128, _mm_movehdup_ps, __m128 a)
YW_INTRIN_FUNC(__m128, _mm_moveldup_ps, __m128 a)
YW_INTRIN_FUNC(void, _mm_mwait, unsigned extensions, unsigned hints)
}
