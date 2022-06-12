// ywstd/nmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "smmintrin.hh"

#ifdef _ywstd_
#include <nmmintrin.h>
#endif

namespace yw::intrin {
YW_INTRIN_FUNC(int, _mm_cmpestra, __m128i a, int la, __m128i b, int lb, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpestrc, __m128i a, int la, __m128i b, int lb, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpestri, __m128i a, int la, __m128i b, int lb, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_cmpestrm, __m128i a, int la, __m128i b, int lb, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpestro, __m128i a, int la, __m128i b, int lb, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpestrs, __m128i a, int la, __m128i b, int lb, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpestrz, __m128i a, int la, __m128i b, int lb, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi64, __m128i a, __m128i b)
YW_INTRIN_FUNC(int, _mm_cmpistra, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpistrc, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpistri, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_cmpistrm, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpistro, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpistrs, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(int, _mm_cmpistrz, __m128i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u16, unsigned int crc, unsigned short v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u16, unsigned int crc, unsigned short v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u32, unsigned int crc, unsigned int v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u32, unsigned int crc, unsigned int v)
YW_INTRIN_FUNC(unsigned __int64, _mm_crc32_u64, unsigned __int64 crc, unsigned __int64 v)
YW_INTRIN_FUNC(unsigned __int64, _mm_crc32_u64, unsigned __int64 crc, unsigned __int64 v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u8, unsigned int crc, unsigned char v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u8, unsigned int crc, unsigned char v)
}
