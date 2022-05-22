// ywstd/xmmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "mmintrin.hh"

#ifdef _ywstd_
#include <xmmintrin.h>
namespace yw::intrin {
using ::__m128;
}
#else
namespace yw::intrin {
union alignas(16) __m128 {
  fat4 m128_f32[4];
  int1 m128_i8[16];
  int2 m128_i16[8];
  int4 m128_i32[4];
  int8 m128_i64;
  nat1 m128_u8[16];
  nat2 m128_u16[8];
  nat4 m128_u32[4];
  nat8 m128_u64;
};
}
#endif

namespace yw::intrin {

YW_INTRIN_FUNC(__m128, _mm_add_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_add_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_sub_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_sub_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_mul_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_mul_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_div_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_div_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_sqrt_ss, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_sqrt_ps, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_rcp_ss, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_rcp_ps, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_rsqrt_ss, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_rsqrt_ps, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_min_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_min_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_max_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_max_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_and_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_andnot_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_or_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_xor_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpeq_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpeq_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmplt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmplt_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmple_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmple_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpgt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpgt_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpge_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpge_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpneq_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpneq_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpnlt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpnlt_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpnle_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpnle_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpngt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpngt_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpnge_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpnge_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpord_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpord_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpunord_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_cmpunord_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_comieq_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_comilt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_comile_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_comigt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_comige_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_comineq_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_ucomieq_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_ucomilt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_ucomile_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_ucomigt_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_ucomige_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_ucomineq_ss, __m128 a, __m128 b);
YW_INTRIN_FUNC(int4, _mm_cvt_ss2si, __m128 a);
YW_INTRIN_FUNC(int4, _mm_cvtt_ss2si, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_cvt_si2ss, __m128, int4);
YW_INTRIN_FUNC(fat4, _mm_cvtss_f32, __m128 a);

#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(__m64, _mm_cvt_ps2pi, __m128 a);
YW_INTRIN_FUNC(__m64, _mm_cvtt_ps2pi, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_cvt_pi2ps, __m128, __m64);
#endif

#ifdef YW_INTRIN_X64
YW_INTRIN_FUNC(int8, _mm_cvtss_si64, __m128 a);
YW_INTRIN_FUNC(int8, _mm_cvttss_si64, __m128 a);
YW_INTRIN_FUNC(__m128,  _mm_cvtsi64_ss, __m128 a, int8 b);
#endif

YW_INTRIN_FUNC(__m128, _mm_shuffle_ps, __m128 a, __m128 b, nat4 imm8);
YW_INTRIN_FUNC(__m128, _mm_unpackhi_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_unpacklo_ps, __m128 a, __m128 b);
YW_INTRIN_FUNC(__m128, _mm_loadh_pi, __m128, const __m64*);
YW_INTRIN_FUNC(__m128, _mm_movehl_ps, __m128, __m128);
YW_INTRIN_FUNC(__m128, _mm_movelh_ps, __m128, __m128);
YW_INTRIN_VOID(void, _mm_storeh_pi, __m64*, __m128);
YW_INTRIN_FUNC(__m128, _mm_loadl_pi, __m128, const __m64*);
YW_INTRIN_VOID(void, _mm_storel_pi, __m64*, __m128);
YW_INTRIN_FUNC(int, _mm_movemask_ps, __m128 a);

#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(int, _m_pextrw, __m64, int);
YW_INTRIN_FUNC(__m64, _m_pinsrw, __m64, int, int);
YW_INTRIN_FUNC(__m64, _m_pmaxsw, __m64, __m64);
YW_INTRIN_FUNC(__m64, _m_pmaxub, __m64, __m64);
YW_INTRIN_FUNC(__m64, _m_pminsw, __m64, __m64);
YW_INTRIN_FUNC(__m64, _m_pminub, __m64, __m64);
YW_INTRIN_FUNC(int, _m_pmovmskb, __m64);
YW_INTRIN_FUNC(__m64, _m_pmulhuw, __m64, __m64);
YW_INTRIN_FUNC(__m64, _m_pshufw, __m64, int);
YW_INTRIN_VOID(void, _m_maskmovq, __m64, __m64, char*);
YW_INTRIN_FUNC(__m64, _m_pavgb, __m64, __m64);
YW_INTRIN_FUNC(__m64, _m_pavgw, __m64, __m64);
YW_INTRIN_FUNC(__m64, _m_psadbw, __m64, __m64);
#endif

YW_INTRIN_FUNC(__m128, _mm_set_ss, fat4 a);
YW_INTRIN_FUNC(__m128, _mm_set_ps1, fat4 a);
YW_INTRIN_FUNC(__m128, _mm_set_ps, fat4 a, fat4 b, fat4 c, fat4 d);
YW_INTRIN_FUNC(__m128, _mm_setr_ps, fat4 a, fat4 b, fat4 c, fat4 d);
YW_INTRIN_FUNC(__m128, _mm_setzero_ps, void);
YW_INTRIN_FUNC(__m128, _mm_load_ss, const fat4* a);
YW_INTRIN_FUNC(__m128, _mm_load_ps1, const fat4* a);
YW_INTRIN_FUNC(__m128, _mm_load_ps, const fat4* a);
YW_INTRIN_FUNC(__m128, _mm_loadr_ps, const fat4* a);
YW_INTRIN_FUNC(__m128, _mm_loadu_ps, const fat4* a);
YW_INTRIN_VOID(void, _mm_store_ss, fat4* v, __m128 a);
YW_INTRIN_VOID(void, _mm_store_ps1, fat4* v, __m128 a);
YW_INTRIN_VOID(void, _mm_store_ps, fat4* v, __m128 a);
YW_INTRIN_VOID(void, _mm_storer_ps, fat4* v, __m128 a);
YW_INTRIN_VOID(void, _mm_storeu_ps, fat4* v, __m128 a);
YW_INTRIN_VOID(void, _mm_prefetch, const char* a, int4 _Sel);

#ifdef YW_INTRIN_X86
YW_INTRIN_VOID(void, _mm_stream_pi, __m64*, __m64);
#endif

YW_INTRIN_VOID(void, _mm_stream_ps, fat4* , __m128);
YW_INTRIN_FUNC(__m128, _mm_move_ss, __m128 a, __m128 b);
YW_INTRIN_VOID(void, _mm_sfence, void);
YW_INTRIN_FUNC(nat4, _mm_getcsr, void);
YW_INTRIN_VOID(void, _mm_setcsr, nat4);

#ifdef YW_INTRIN_X86
inline __m64 _mm_cvtps_pi32(__m128 a) { return _mm_cvt_ps2pi(a); }
inline __m64 _mm_cvttps_pi32(__m128 a) { return _mm_cvtt_ps2pi(a); }
inline __m128 _mm_cvtpi32_ps(__m128 a, __m64 b) { return _mm_cvt_pi2ps(a, b); }
inline int4 _mm_extract_pi16(__m64 a, int4 b) { return _m_pextrw(a, b); }
inline __m64 _mm_insert_pi16(__m64 a, int4 b, int4 c) { return _m_pinsrw(a, b, c); }
inline __m64 _mm_max_pi16(__m64 a, __m64 b) { return _m_pmaxsw(a, b); }
inline __m64 _mm_max_pu8(__m64 a, __m64 b) { return _m_pmaxub(a, b); }
inline __m64 _mm_min_pi16(__m64 a, __m64 b) { return _m_pminsw(a, b); }
inline __m64 _mm_min_pu8(__m64 a, __m64 b) { return _m_pminub(a, b); }
inline int4 _mm_movemask_pi8(__m64 a) { return _m_pmovmskb(a); }
inline __m64 _mm_mulhi_pu16(__m64 a, __m64 b) { return _m_pmulhuw(a, b); }
inline __m64 _mm_shuffle_pi16(__m64 a, int4 b) { return _m_pshufw(a, b); }
inline void _mm_maskmove_si64(__m64 a, __m64 b, char* c) { return _m_maskmovq(a, b, c); }
inline __m64 _mm_avg_pu8(__m64 a, __m64 b) { return _m_pavgb(a, b); }
inline __m64 _mm_avg_pu16(__m64 a, __m64 b) { return _m_pavgw(a, b); }
inline __m64 _mm_sad_pu8(__m64 a, __m64 b) { return _m_psadbw(a, b); }
#endif

inline int4 _mm_cvtss_si32(__m128 a) { return _mm_cvt_ss2si(a); }
inline int4 _mm_cvttss_si32(__m128 a) { return _mm_cvtt_ss2si(a); }
inline __m128 _mm_cvtsi32_ss(__m128 a, int4 b) { return _mm_cvt_si2ss(a, b); }
inline __m128 _mm_set1_ps(fat4 a) { return _mm_set_ps1(a); }
inline __m128 _mm_load1_ps(const fat4* a) { return _mm_load_ps1(a); }
inline void _mm_store1_ps(fat4* a, __m128 b) { return _mm_store_ps1(a, b); }

#ifdef YW_INTRIN_X86
inline __m128 _mm_cvtpi16_ps(__m64 a) {
  __m64  x = _mm_cmpgt_pi16(_mm_setzero_si64(), a);
  __m128 y = _mm_cvtpi32_ps(_mm_setzero_ps(), _mm_unpackhi_pi16(a, x));
  return(_mm_cvtpi32_ps(_mm_movelh_ps(y, y), _mm_unpacklo_pi16(a, x)));
}
inline __m128 _mm_cvtpu16_ps(__m64 a) {
  __m64  x = _mm_setzero_si64();
  __m128 y = _mm_cvtpi32_ps(_mm_setzero_ps(), _mm_unpackhi_pi16(a, x));
  return(_mm_cvtpi32_ps(_mm_movelh_ps(y, y), _mm_unpacklo_pi16(a, x)));
}
inline __m64 _mm_cvtps_pi16(__m128 a) { return _mm_packs_pi32(_mm_cvtps_pi32(a), _mm_cvtps_pi32(_mm_movehl_ps(a, a))); }
inline __m128 _mm_cvtpi8_ps(__m64 a) { return _mm_cvtpi16_ps(_mm_unpacklo_pi8(a, _mm_cmpgt_pi8(_mm_setzero_si64(), a))); }
inline __m128 _mm_cvtpu8_ps(__m64 a) { return _mm_cvtpu16_ps(_mm_unpacklo_pi8(a, _mm_setzero_si64())); }
inline __m64 _mm_cvtps_pi8(__m128 a) { return _mm_packs_pi16(_mm_cvtps_pi16(a), _mm_setzero_si64()); }
inline __m128 _mm_cvtpi32x2_ps(__m64 a, __m64 b) { return _mm_movelh_ps(_mm_cvt_pi2ps(_mm_setzero_ps(), a), _mm_cvt_pi2ps(_mm_setzero_ps(), b)); }
#endif

}
