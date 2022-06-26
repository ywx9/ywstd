// ywstd/nmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "smmintrin.hh"

#ifdef _ywstd_
#include <nmmintrin.h>
#endif

namespace yw::intrin {
#ifdef _mm_cmpestra
#undef _mm_cmpestra
#define YW_INTRIN_MM_CMPESTRA_IS_TEMPLATE
template<int Imm8> int _mm_cmpestra(__m128i a, int la, __m128i b, int lb) noexcept {
  return (int)__builtin_ia32_pcmpestria128((__v16qi)a, la, b, lb, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpestra, __m128i a, int la, __m128i b, int lb, const int imm8)
#endif
#ifdef _mm_cmpestrc
#undef _mm_cmpestrc
#define YW_INTRIN_MM_CMPESTRC_IS_TEMPLATE
template<int Imm8> int _mm_cmpestrc(__m128i a, int la, __m128i b, int lb) noexcept {
  return (int)__builtin_ia32_pcmpestric128((__v16qi)a, la, (__v16qi)b, lb, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpestrc, __m128i a, int la, __m128i b, int lb, const int imm8)
#endif
#ifdef _mm_cmpestri
#undef _mm_cmpestri
#define YW_INTRIN_MM_CMPESTRI_IS_TEMPLATE
template<int Imm8> int _mm_cmpestri(__m128i a, int la, __m128i b, int lb) noexcept {
  return (int)__builtin_ia32_pcmpestri128((__v16qi)a, la, (__v16qi)b, lb, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpestri, __m128i a, int la, __m128i b, int lb, const int imm8)
#endif
#ifdef _mm_cmpestrm
#undef _mm_cmpestrm
#define YW_INTRIN_MM_CMPESTRM_IS_TEMPLATE
template<int Imm8> __m128i _mm_cmpestrm(__m128i a, int la, __m128i b, int lb) noexcept {
  return (__m128i)__builtin_ia32_pcmpestrm128((__v16qi)a, la, (__v16qi)b, lb, Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm_cmpestrm, __m128i a, int la, __m128i b, int lb, const int imm8)
#endif
#ifdef _mm_cmpestro
#undef _mm_cmpestro
#define YW_INTRIN_MM_CMPESTRO_IS_TEMPLATE
template<int Imm8> int _mm_cmpestro(__m128i a, int la, __m128i b, int lb) noexcept {
  return (int)__builtin_ia32_pcmpestrio128((__v16qi)a, la, (__v16qi)b, lb, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpestro, __m128i a, int la, __m128i b, int lb, const int imm8)
#endif
#ifdef _mm_cmpestrs
#undef _mm_cmpestrs
#define YW_INTRIN_MM_CMPESTRS_IS_TEMPLATE
template<int Imm8> int _mm_cmpestrs(__m128i a, int la, __m128i b, int lb) noexcept {
  return (int)__builtin_ia32_pcmpestris128((__v16qi)a, la, (__v16qi)b, lb, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpestrs, __m128i a, int la, __m128i b, int lb, const int imm8)
#endif
#ifdef _mm_cmpestrz
#undef _mm_cmpestrz
#define YW_INTRIN_MM_CMPESTRZ_IS_TEMPLATE
template<int Imm8> int _mm_cmpestrz(__m128i a, int la, __m128i b, int lb) noexcept {
  return (int)__builtin_ia32_pcmpestriz128((__v16qi)a, la, (__v16qi)b, lb, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpestrz, __m128i a, int la, __m128i b, int lb, const int imm8)
#endif
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi64, __m128i a, __m128i b)
#ifdef _mm_cmpistra
#undef _mm_cmpistra
#define YW_INTRIN_MM_CMPISTRA_IS_TEMPLATE
template<int Imm8> int _mm_cmpistra(__m128i a, __m128i b) noexcept {
  return (int)__builtin_ia32_pcmpistria128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpistra, __m128i a, __m128i b, const int imm8)
#endif
#ifdef _mm_cmpistrc
#undef _mm_cmpistrc
#define YW_INTRIN_MM_CMPISTRC_IS_TEMPLATE
template<int Imm8> int _mm_cmpistrc(__m128i a, __m128i b) noexcept {
  return (int)__builtin_ia32_pcmpistric128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpistrc, __m128i a, __m128i b, const int imm8)
#endif
#ifdef _mm_cmpistri
#undef _mm_cmpistri
#define YW_INTRIN_MM_CMPISTRI_IS_TEMPLATE
template<int Imm8> int _mm_cmpistri(__m128i a, __m128i b) noexcept {
  return (int)__builtin_ia32_pcmpistri128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpistri, __m128i a, __m128i b, const int imm8)
#endif
#ifdef _mm_cmpistrm
#undef _mm_cmpistrm
#define YW_INTRIN_MM_CMPISTRM_IS_TEMPLATE
template<int Imm8> int _mm_cmpistrm(__m128i a, __m128i b) noexcept {
  return (int)__builtin_ia32_pcmpistrm128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm_cmpistrm, __m128i a, __m128i b, const int imm8)
#endif
#ifdef _mm_cmpistro
#undef _mm_cmpistro
#define YW_INTRIN_MM_CMPISTRO_IS_TEMPLATE
template<int Imm8> int _mm_cmpistro(__m128i a, __m128i b) noexcept {
  return (int)__builtin_ia32_pcmpistrio128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpistro, __m128i a, __m128i b, const int imm8)
#endif
#ifdef _mm_cmpistrs
#undef _mm_cmpistrs
#define YW_INTRIN_MM_CMPISTRS_IS_TEMPLATE
template<int Imm8> int _mm_cmpistrs(__m128i a, __m128i b) noexcept {
  return (int)__builtin_ia32_pcmpistris128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpistrs, __m128i a, __m128i b, const int imm8)
#endif
#ifdef _mm_cmpistrz
#undef _mm_cmpistrz
#define YW_INTRIN_MM_CMPISTRZ_IS_TEMPLATE
template<int Imm8> int _mm_cmpistrz(__m128i a, __m128i b) noexcept {
  return (int)__builtin_ia32_pcmpistriz128((__v16qi)a, (__v16qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(int, _mm_cmpistrz, __m128i a, __m128i b, const int imm8)
#endif
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u16, unsigned int crc, unsigned short v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u16, unsigned int crc, unsigned short v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u32, unsigned int crc, unsigned int v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u32, unsigned int crc, unsigned int v)
YW_INTRIN_FUNC(unsigned __int64, _mm_crc32_u64, unsigned __int64 crc, unsigned __int64 v)
YW_INTRIN_FUNC(unsigned __int64, _mm_crc32_u64, unsigned __int64 crc, unsigned __int64 v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u8, unsigned int crc, unsigned char v)
YW_INTRIN_FUNC(unsigned int, _mm_crc32_u8, unsigned int crc, unsigned char v)
} // namespace yw::intrin
