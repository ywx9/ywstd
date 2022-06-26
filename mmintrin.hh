// ywstd/mmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _M_IX86
#ifndef YW_INTRIN_X86
#define YW_INTRIN_X86
#endif
#endif

#ifdef _M_X64
#ifndef YW_INTRIN_X64
#define YW_INTRIN_X64
#endif
#endif

#ifdef _ywstd_
#include <mmintrin.h>
#include <intrin.h>
namespace yw::intrin { using ::__m64; }
#define YW_INTRIN_FUNC(Ret, Func, ...) using ::Func;
#else
namespace yw::intrin {
union alignas(8) __m64 { // MSVC
  unsigned long long m64_u64;
  float m64_f32[2];
  char m64_i8[8];
  short m64_i16[4];
  int m64_i32[2];
  long long m64_i64;
  unsigned char m64_u8[8];
  unsigned short m64_u16[4];
  unsigned int m64_u32[2];
};
}
#define YW_INTRIN_FUNC(Ret, Func, ...) extern Ret Func(__VA_ARGS__);
#endif

namespace yw::intrin {
using std::size_t;
#ifdef YW_INTRIN_UNAVAILABLE
YW_INTRIN_FUNC(__int64, _mm_cvtm64_si64, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_cvtsi64_m64, __int64 a)
YW_INTRIN_FUNC(__m64, _m_from_int64, __int64 a)
YW_INTRIN_FUNC(__int64, _m_to_int64, __m64 a)
#endif
#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(__m64, _mm_add_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_add_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_add_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_adds_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_adds_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_adds_pu16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_adds_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_and_si64, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_andnot_si64, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cmpeq_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cmpeq_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cmpeq_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cmpgt_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cmpgt_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cmpgt_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_cvtsi32_si64, int a)
YW_INTRIN_FUNC(int, _mm_cvtsi64_si32, __m64 a)
YW_INTRIN_FUNC(void, _m_empty, void)
YW_INTRIN_FUNC(void, _mm_empty, void)
YW_INTRIN_FUNC(__m64, _m_from_int, int a)
YW_INTRIN_FUNC(__m64, _mm_madd_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_mulhi_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_mullo_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_or_si64, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_packs_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_packs_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_packs_pu16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_packssdw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_packsswb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_packuswb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_paddb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_paddd, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_paddsb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_paddsw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_paddusb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_paddusw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_paddw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pand, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pandn, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pcmpeqb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pcmpeqd, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pcmpeqw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pcmpgtb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pcmpgtd, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pcmpgtw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pmaddwd, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pmulhw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pmullw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_por, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pslld, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_pslldi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psllq, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_psllqi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psllw, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_psllwi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psrad, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_psradi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psraw, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_psrawi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psrld, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_psrldi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psrlq, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_psrlqi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psrlw, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _m_psrlwi, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _m_psubb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_psubd, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_psubsb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_psubsw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_psubusb, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_psubusw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_psubw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_punpckhbw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_punpckhdq, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_punpckhwd, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_punpcklbw, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_punpckldq, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_punpcklwd, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _m_pxor, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_set_pi16, short e3, short e2, short e1, short e0)
YW_INTRIN_FUNC(__m64, _mm_set_pi32, int e1, int e0)
YW_INTRIN_FUNC(__m64, _mm_set_pi8, char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0)
YW_INTRIN_FUNC(__m64, _mm_set1_pi16, short a)
YW_INTRIN_FUNC(__m64, _mm_set1_pi32, int a)
YW_INTRIN_FUNC(__m64, _mm_set1_pi8, char a)
YW_INTRIN_FUNC(__m64, _mm_setr_pi16, short e3, short e2, short e1, short e0)
YW_INTRIN_FUNC(__m64, _mm_setr_pi32, int e1, int e0)
YW_INTRIN_FUNC(__m64, _mm_setr_pi8, char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0)
YW_INTRIN_FUNC(__m64, _mm_setzero_si64, void)
YW_INTRIN_FUNC(__m64, _mm_sll_pi16, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_sll_pi32, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_sll_si64, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_slli_pi16, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_slli_pi32, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_slli_si64, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_sra_pi16, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_sra_pi32, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_srai_pi16, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_srai_pi32, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_srl_pi16, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_srl_pi32, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_srl_si64, __m64 a, __m64 count)
YW_INTRIN_FUNC(__m64, _mm_srli_pi16, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_srli_pi32, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_srli_si64, __m64 a, int imm8)
YW_INTRIN_FUNC(__m64, _mm_sub_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_sub_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_sub_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_subs_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_subs_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_subs_pu16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_subs_pu8, __m64 a, __m64 b)
YW_INTRIN_FUNC(int, _m_to_int, __m64 a)
YW_INTRIN_FUNC(__m64, _mm_unpackhi_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_unpackhi_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_unpackhi_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_unpacklo_pi16, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_unpacklo_pi32, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_unpacklo_pi8, __m64 a, __m64 b)
YW_INTRIN_FUNC(__m64, _mm_xor_si64, __m64 a, __m64 b)
#endif
}
