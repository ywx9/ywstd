// ywstd/mmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

namespace yw {
template<typename Ty> using type = Ty;
using int1 = signed char;
using int2 = signed short;
using int4 = signed int;
using int8 = signed long long;
using nat1 = unsigned char;
using nat2 = unsigned short;
using nat4 = unsigned int;
using nat8 = unsigned long long;
using fat4 = float;
using fat8 = double;
}

#ifdef _ywstd_
#include <mmintrin.h>
#define YW_INTRIN_FUNC(Ret, Func, ...) using ::Func;
#define YW_INTRIN_VOID(Ret, Func, ...) using ::Func;
namespace yw::intrin {
using ::__m64;
}
#else
#define YW_INTRIN_FUNC(Ret, Func, ...) inline Ret Func(__VA_ARGS__) { return Ret{}; }
#define YW_INTRIN_VOID(Ret, Func, ...) inline Ret Func(__VA_ARGS__) {}
namespace yw::intrin {
union alignas(8) __m64 {
  int1 m64_i8[8];
  int2 m64_i16[4];
  int4 m64_i32[2];
  int8 m64_i64;
  nat1 m64_u8[8];
  nat2 m64_u16[4];
  nat4 m64_u32[2];
  nat8 m64_u64;
  fat4 m64_f32[2];
};
}
#endif

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

#ifdef YW_INTRIN_X86
namespace yw::intrin {

YW_INTRIN_VOID(void, _m_empty, void);
YW_INTRIN_FUNC(__m64, _m_from_int, int4 i);
YW_INTRIN_FUNC(int4, _m_to_int, __m64 m);
YW_INTRIN_FUNC(__m64, _m_packsswb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_packssdw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_packuswb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_punpckhbw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_punpckhwd, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_punpckhdq, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_punpcklbw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_punpcklwd, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_punpckldq, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_paddb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_paddw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_paddd, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_paddsb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_paddsw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_paddusb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_paddusw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psubb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psubw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psubd, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psubsb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psubsw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psubusb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psubusw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pmaddwd, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pmulhw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pmullw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_psllw, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_psllwi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_pslld, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_pslldi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_psllq, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_psllqi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_psraw, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_psrawi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_psrad, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_psradi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_psrlw, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_psrlwi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_psrld, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_psrldi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_psrlq, __m64 m, __m64 n);
YW_INTRIN_FUNC(__m64, _m_psrlqi, __m64 m, int4 n);
YW_INTRIN_FUNC(__m64, _m_pand, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pandn, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_por, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pxor, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pcmpeqb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pcmpeqw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pcmpeqd, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pcmpgtb, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pcmpgtw, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _m_pcmpgtd, __m64 mm1, __m64 mm2);
YW_INTRIN_FUNC(__m64, _mm_setzero_si64, void);
YW_INTRIN_FUNC(__m64, _mm_set_pi32, int4 i1, int4 i0);
YW_INTRIN_FUNC(__m64, _mm_set_pi16, int2 i3, int2 i2, int2 i1, int2 i0);
YW_INTRIN_FUNC(__m64, _mm_set_pi8, char i7, char i6, char i5, char i4, char i3, char i2, char i1, char i0);
YW_INTRIN_FUNC(__m64, _mm_set1_pi32, int4 i);
YW_INTRIN_FUNC(__m64, _mm_set1_pi16, int2 i);
YW_INTRIN_FUNC(__m64, _mm_set1_pi8, char i);
YW_INTRIN_FUNC(__m64, _mm_setr_pi32, int4 i1, int4 i0);
YW_INTRIN_FUNC(__m64, _mm_setr_pi16, int2 i3, int2 i2, int2 i1, int2 i0);
YW_INTRIN_FUNC(__m64, _mm_setr_pi8, char i7, char i6, char i5, char i4, char i3, char i2, char i1, char i0);

inline void _mm_empty(void) { return _m_empty(); }
inline __m64 _mm_cvtsi32_si64(int4 i) { return _m_from_int(i); }
inline int4 _mm_cvtsi64_si32(__m64 m) { return _m_to_int(m); }
inline __m64 _mm_packs_pi16(__m64 mm1, __m64 mm2) { return _m_packsswb(mm1, mm2); }
inline __m64 _mm_packs_pi32(__m64 mm1, __m64 mm2) { return _m_packssdw(mm1, mm2); }
inline __m64 _mm_packs_pu16(__m64 mm1, __m64 mm2) { return _m_packuswb(mm1, mm2); }
inline __m64 _mm_unpackhi_pi8(__m64 mm1, __m64 mm2) { return _m_punpckhbw(mm1, mm2); }
inline __m64 _mm_unpackhi_pi16(__m64 mm1, __m64 mm2) { return _m_punpckhwd(mm1, mm2); }
inline __m64 _mm_unpackhi_pi32(__m64 mm1, __m64 mm2) { return _m_punpckhdq(mm1, mm2); }
inline __m64 _mm_unpacklo_pi8(__m64 mm1, __m64 mm2) { return _m_punpcklbw(mm1, mm2); }
inline __m64 _mm_unpacklo_pi16(__m64 mm1, __m64 mm2) { return _m_punpcklwd(mm1, mm2); }
inline __m64 _mm_unpacklo_pi32(__m64 mm1, __m64 mm2) { return _m_punpckldq(mm1, mm2); }
inline __m64 _mm_add_pi8(__m64 mm1, __m64 mm2) { return _m_paddb(mm1, mm2); }
inline __m64 _mm_add_pi16(__m64 mm1, __m64 mm2) { return _m_paddw(mm1, mm2); }
inline __m64 _mm_add_pi32(__m64 mm1, __m64 mm2) { return _m_paddd(mm1, mm2); }
inline __m64 _mm_adds_pi8(__m64 mm1, __m64 mm2) { return _m_paddsb(mm1, mm2); }
inline __m64 _mm_adds_pi16(__m64 mm1, __m64 mm2) { return _m_paddsw(mm1, mm2); }
inline __m64 _mm_adds_pu8(__m64 mm1, __m64 mm2) { return _m_paddusb(mm1, mm2); }
inline __m64 _mm_adds_pu16(__m64 mm1, __m64 mm2) { return _m_paddusw(mm1, mm2); }
inline __m64 _mm_sub_pi8(__m64 mm1, __m64 mm2) { return _m_psubb(mm1, mm2); }
inline __m64 _mm_sub_pi16(__m64 mm1, __m64 mm2) { return _m_psubw(mm1, mm2); }
inline __m64 _mm_sub_pi32(__m64 mm1, __m64 mm2) { return _m_psubd(mm1, mm2); }
inline __m64 _mm_subs_pi8(__m64 mm1, __m64 mm2) { return _m_psubsb(mm1, mm2); }
inline __m64 _mm_subs_pi16(__m64 mm1, __m64 mm2) { return _m_psubsw(mm1, mm2); }
inline __m64 _mm_subs_pu8(__m64 mm1, __m64 mm2) { return _m_psubusb(mm1, mm2); }
inline __m64 _mm_subs_pu16(__m64 mm1, __m64 mm2) { return _m_psubusw(mm1, mm2); }
inline __m64 _mm_madd_pi16(__m64 mm1, __m64 mm2) { return _m_pmaddwd(mm1, mm2); }
inline __m64 _mm_mulhi_pi16(__m64 mm1, __m64 mm2) { return _m_pmulhw(mm1, mm2); }
inline __m64 _mm_mullo_pi16(__m64 mm1, __m64 mm2) { return _m_pmullw(mm1, mm2); }
inline __m64 _mm_sll_pi16(__m64 m, __m64 n) { return _m_psllw(m, n); }
inline __m64 _mm_slli_pi16(__m64 m, int4 n) { return _m_psllwi(m, n); }
inline __m64 _mm_sll_pi32(__m64 m, __m64 n) { return _m_pslld(m, n); }
inline __m64 _mm_slli_pi32(__m64 m, int4 n) { return _m_pslldi(m, n); }
inline __m64 _mm_sll_si64(__m64 m, __m64 n) { return _m_psllq(m, n); }
inline __m64 _mm_slli_si64(__m64 m, int4 n) { return _m_psllqi(m, n); }
inline __m64 _mm_sra_pi16(__m64 m, __m64 n) { return _m_psraw(m, n); }
inline __m64 _mm_srai_pi16(__m64 m, int4 n) { return _m_psrawi(m, n); }
inline __m64 _mm_sra_pi32(__m64 m, __m64 n) { return _m_psrad(m, n); }
inline __m64 _mm_srai_pi32(__m64 m, int4 n) { return _m_psradi(m, n); }
inline __m64 _mm_srl_pi16(__m64 m, __m64 n) { return _m_psrlw(m, n); }
inline __m64 _mm_srli_pi16(__m64 m, int4 n) { return _m_psrlwi(m, n); }
inline __m64 _mm_srl_pi32(__m64 m, __m64 n) { return _m_psrld(m, n); }
inline __m64 _mm_srli_pi32(__m64 m, int4 n) { return _m_psrldi(m, n); }
inline __m64 _mm_srl_si64(__m64 m, __m64 n) { return _m_psrlq(m, n); }
inline __m64 _mm_srli_si64(__m64 m, int4 n) { return _m_psrlqi(m, n); }
inline __m64 _mm_and_si64(__m64 mm1, __m64 mm2) { return _m_pand(mm1, mm2); }
inline __m64 _mm_andnot_si64(__m64 mm1, __m64 mm2) { return _m_pandn(mm1, mm2); }
inline __m64 _mm_or_si64(__m64 mm1, __m64 mm2) { return _m_por(mm1, mm2); }
inline __m64 _mm_xor_si64(__m64 mm1, __m64 mm2) { return _m_pxor(mm1, mm2); }
inline __m64 _mm_cmpeq_pi8(__m64 mm1, __m64 mm2) { return _m_pcmpeqb(mm1, mm2); }
inline __m64 _mm_cmpeq_pi16(__m64 mm1, __m64 mm2) { return _m_pcmpeqw(mm1, mm2); }
inline __m64 _mm_cmpeq_pi32(__m64 mm1, __m64 mm2) { return _m_pcmpeqd(mm1, mm2); }
inline __m64 _mm_cmpgt_pi8(__m64 mm1, __m64 mm2) { return _m_pcmpgtb(mm1, mm2); }
inline __m64 _mm_cmpgt_pi16(__m64 mm1, __m64 mm2) { return _m_pcmpgtw(mm1, mm2); }
inline __m64 _mm_cmpgt_pi32(__m64 mm1, __m64 mm2) { return _m_pcmpgtd(mm1, mm2); }

}
#endif
