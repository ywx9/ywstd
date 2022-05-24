// ywstd/emmintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "xmmintrin.hh"

#ifdef _ywstd_
#include <emmintrin.h>
namespace yw::intrin {
using ::__m128d;
using ::__m128i;
}
#else
namespace yw::intrin {
union alignas(16) __m128d { fat8 m128d_f64[2]; };
union alignas(16) __m128i {
    int1 m128i_i8[16];
    int2 m128i_i16[8];
    int4 m128i_i32[4];
    int8 m128i_i64[2];
    nat1 m128i_u8[16];
    nat2 m128i_u16[8];
    nat4 m128i_u32[4];
    nat8 m128i_u64[2];
};
}
#endif

namespace yw::intrin {

YW_INTRIN_FUNC(__m128d, _mm_add_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_add_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_sub_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_sub_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_mul_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_mul_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_sqrt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_sqrt_pd, __m128d a);
YW_INTRIN_FUNC(__m128d, _mm_div_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_div_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_min_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_min_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_max_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_max_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_and_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_andnot_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_or_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_xor_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpeq_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpeq_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmplt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmplt_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmple_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmple_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpgt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpgt_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpge_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpge_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpneq_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpneq_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpnlt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpnlt_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpnle_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpnle_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpngt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpngt_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpnge_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpnge_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpord_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpord_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpunord_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cmpunord_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_comieq_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_comilt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_comile_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_comigt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_comige_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_comineq_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_ucomieq_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_ucomilt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_ucomile_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_ucomigt_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_ucomige_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_ucomineq_sd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cvtepi32_pd, __m128i a);
YW_INTRIN_FUNC(__m128i, _mm_cvtpd_epi32, __m128d a);
YW_INTRIN_FUNC(__m128i, _mm_cvttpd_epi32, __m128d a);
YW_INTRIN_FUNC(__m128, _mm_cvtepi32_ps, __m128i a);
YW_INTRIN_FUNC(__m128i, _mm_cvtps_epi32, __m128 a);
YW_INTRIN_FUNC(__m128i, _mm_cvttps_epi32, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_cvtpd_ps, __m128d a);
YW_INTRIN_FUNC(__m128d, _mm_cvtps_pd, __m128 a);
YW_INTRIN_FUNC(__m128, _mm_cvtsd_ss, __m128 a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_cvtss_sd, __m128d a, __m128 b);
YW_INTRIN_FUNC(int, _mm_cvtsd_si32, __m128d a);
YW_INTRIN_FUNC(int, _mm_cvttsd_si32, __m128d a);
YW_INTRIN_FUNC(__m128d, _mm_cvtsi32_sd, __m128d a, int b);
YW_INTRIN_FUNC(__m128d, _mm_unpackhi_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(__m128d, _mm_unpacklo_pd, __m128d a, __m128d b);
YW_INTRIN_FUNC(int, _mm_movemask_pd, __m128d a);
YW_INTRIN_FUNC(__m128d, _mm_shuffle_pd, __m128d a, __m128d b, int i);
YW_INTRIN_FUNC(__m128d, _mm_load_pd, const fat8* p);
YW_INTRIN_FUNC(__m128d, _mm_load1_pd, const fat8* p);
YW_INTRIN_FUNC(__m128d, _mm_loadr_pd, const fat8* p);
YW_INTRIN_FUNC(__m128d, _mm_loadu_pd, const fat8* p);
YW_INTRIN_FUNC(__m128d, _mm_load_sd, const fat8* p);
YW_INTRIN_FUNC(__m128d, _mm_loadh_pd, __m128d a, const fat8* p);
YW_INTRIN_FUNC(__m128d, _mm_loadl_pd, __m128d a, const fat8* p);
YW_INTRIN_FUNC(__m128d, _mm_set_sd, fat8 a);
YW_INTRIN_FUNC(__m128d, _mm_set1_pd, fat8 a);
YW_INTRIN_FUNC(__m128d, _mm_set_pd, fat8 z, fat8 y);
YW_INTRIN_FUNC(__m128d, _mm_setr_pd, fat8 y, fat8 z);
YW_INTRIN_FUNC(__m128d, _mm_setzero_pd, void);
YW_INTRIN_FUNC(__m128d, _mm_move_sd, __m128d a, __m128d b);
YW_INTRIN_VOID(void, _mm_store_sd, fat8*p, __m128d a);
YW_INTRIN_VOID(void, _mm_store1_pd, fat8*p, __m128d a);
YW_INTRIN_VOID(void, _mm_store_pd, fat8*p, __m128d a);
YW_INTRIN_VOID(void, _mm_storeu_pd, fat8*p, __m128d a);
YW_INTRIN_VOID(void, _mm_storer_pd, fat8*p, __m128d a);
YW_INTRIN_VOID(void, _mm_storeh_pd, fat8*p, __m128d a);
YW_INTRIN_VOID(void, _mm_storel_pd, fat8*p, __m128d a);
YW_INTRIN_FUNC(__m128i, _mm_add_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_add_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_add_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_add_epi64, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_adds_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_adds_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_adds_epu8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_adds_epu16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_avg_epu8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_avg_epu16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_madd_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_max_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_max_epu8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_min_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_min_epu8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_mulhi_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_mulhi_epu16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_mullo_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_mul_epu32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_sad_epu8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_sub_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_sub_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_sub_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_sub_epi64, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_subs_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_subs_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_subs_epu8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_subs_epu16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_and_si128, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_andnot_si128, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_or_si128, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_xor_si128, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_slli_si128, __m128i a, int imm);
YW_INTRIN_FUNC(__m128i, _mm_slli_epi16, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_sll_epi16, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_slli_epi32, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_sll_epi32, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_slli_epi64, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_sll_epi64, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_srai_epi16, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_sra_epi16, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_srai_epi32, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_sra_epi32, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_srli_si128, __m128i a, int imm);
YW_INTRIN_FUNC(__m128i, _mm_srli_epi16, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_srl_epi16, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_srli_epi32, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_srl_epi32, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_srli_epi64, __m128i a, int count);
YW_INTRIN_FUNC(__m128i, _mm_srl_epi64, __m128i a, __m128i count);
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmpeq_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmpgt_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmplt_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmplt_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cmplt_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_cvtsi32_si128, int a);
YW_INTRIN_FUNC(int, _mm_cvtsi128_si32, __m128i a);
YW_INTRIN_FUNC(__m128i, _mm_packs_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_packs_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_packus_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(int, _mm_extract_epi16, __m128i a, int imm);
YW_INTRIN_FUNC(__m128i, _mm_insert_epi16, __m128i a, int b, int imm);
YW_INTRIN_FUNC(int, _mm_movemask_epi8, __m128i a);
YW_INTRIN_FUNC(__m128i, _mm_shuffle_epi32, __m128i a, int imm);
YW_INTRIN_FUNC(__m128i, _mm_shufflehi_epi16, __m128i a, int imm);
YW_INTRIN_FUNC(__m128i, _mm_shufflelo_epi16, __m128i a, int imm);
YW_INTRIN_FUNC(__m128i, _mm_unpackhi_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_unpackhi_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_unpackhi_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_unpackhi_epi64, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_unpacklo_epi8, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_unpacklo_epi16, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_unpacklo_epi32, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_unpacklo_epi64, __m128i a, __m128i b);
YW_INTRIN_FUNC(__m128i, _mm_load_si128, __m128i const*_P);
YW_INTRIN_FUNC(__m128i, _mm_loadu_si128, __m128i const*_P);
YW_INTRIN_FUNC(__m128i, _mm_loadl_epi64, __m128i const*_P);
YW_INTRIN_FUNC(__m128i, _mm_set_epi64x, int8 i1,int8 i0);
YW_INTRIN_FUNC(__m128i, _mm_set_epi32, int4 i3, int4 i2, int4 i1, int4 i0);
YW_INTRIN_FUNC(__m128i, _mm_set_epi16, int2 i7, int2 i6, int2 i5, int2 i4, int2 i3, int2 i2, int2 i1, int2 i0);
YW_INTRIN_FUNC(__m128i, _mm_set_epi8, char i15, char i14, char i13, char i12, char i11, char i10, char i9, char i8, char i7, char i6, char i5, char i4, char i3, char i2, char i1, char i0);
YW_INTRIN_FUNC(__m128i, _mm_set1_epi64x, int8 i);
YW_INTRIN_FUNC(__m128i, _mm_set1_epi32, int i);
YW_INTRIN_FUNC(__m128i, _mm_set1_epi16, int2 i);
YW_INTRIN_FUNC(__m128i, _mm_set1_epi8, char b);
YW_INTRIN_FUNC(__m128i, _mm_setl_epi64, __m128i q);
YW_INTRIN_FUNC(__m128i, _mm_setr_epi32, int i0, int i1, int i2, int i3);
YW_INTRIN_FUNC(__m128i, _mm_setr_epi16, int2 i0, int2 i1, int2 i2, int2 i3, int2 i4, int2 i5, int2 i6, int2 i7);
YW_INTRIN_FUNC(__m128i, _mm_setr_epi8, char i15, char i14, char i13, char i12, char i11, char i10, char i9, char i8, char i7, char i6, char i5, char i4, char i3, char i2, char i1, char i0);
YW_INTRIN_FUNC(__m128i, _mm_setzero_si128, void);
YW_INTRIN_VOID(void, _mm_store_si128, __m128i *_P, __m128i b);
YW_INTRIN_VOID(void, _mm_storeu_si128, __m128i *_P, __m128i b);
YW_INTRIN_VOID(void, _mm_storel_epi64, __m128i *_P, __m128i q);
YW_INTRIN_VOID(void, _mm_maskmoveu_si128, __m128i _D, __m128i _N, char *_P);
YW_INTRIN_FUNC(__m128i, _mm_move_epi64, __m128i q);
YW_INTRIN_VOID(void, _mm_stream_pd, fat8*p, __m128d a);
YW_INTRIN_VOID(void, _mm_stream_si128, __m128i *_P, __m128i a);
YW_INTRIN_VOID(void, _mm_clflush, void const*_P);
YW_INTRIN_VOID(void, _mm_lfence, void);
YW_INTRIN_VOID(void, _mm_mfence, void);
YW_INTRIN_VOID(void, _mm_stream_si32, int *_P, int _I);
YW_INTRIN_VOID(void, _mm_pause, void);
YW_INTRIN_FUNC(fat8, _mm_cvtsd_f64, __m128d a);
YW_INTRIN_FUNC(__m128,  _mm_castpd_ps, __m128d);
YW_INTRIN_FUNC(__m128i, _mm_castpd_si128, __m128d);
YW_INTRIN_FUNC(__m128d, _mm_castps_pd, __m128);
YW_INTRIN_FUNC(__m128i, _mm_castps_si128, __m128);
YW_INTRIN_FUNC(__m128,  _mm_castsi128_ps, __m128i);
YW_INTRIN_FUNC(__m128d, _mm_castsi128_pd, __m128i);

inline __m128d _mm_set_pd1(fat8 a) { return _mm_set1_pd(a); }
inline __m128d _mm_load_pd1(const fat8* p) { return _mm_load1_pd(p); }
inline void _mm_store_pd1(fat8*p, __m128d a) { return _mm_store1_pd(p, a); }
inline __m128i _mm_bslli_si128(__m128i a, int imm) { return _mm_slli_si128(a, imm); }
inline __m128i _mm_bsrli_si128(__m128i a, int imm) { return _mm_srli_si128(a, imm); }

#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(__m64, _mm_cvtpd_pi32, __m128d a);
YW_INTRIN_FUNC(__m64, _mm_cvttpd_pi32, __m128d a);
YW_INTRIN_FUNC(__m128d, _mm_cvtpi32_pd, __m64 a);
YW_INTRIN_FUNC(__m64, _mm_add_si64, __m64 a, __m64 b);
YW_INTRIN_FUNC(__m64, _mm_mul_su32, __m64 a, __m64 b);
YW_INTRIN_FUNC(__m64, _mm_sub_si64, __m64 a, __m64 b);
YW_INTRIN_FUNC(__m128i, _mm_set_epi64, __m64 q1, __m64 q0);
YW_INTRIN_FUNC(__m128i, _mm_set1_epi64, __m64 q);
YW_INTRIN_FUNC(__m128i, _mm_setr_epi64, __m64 q0, __m64 q1);
YW_INTRIN_FUNC(__m128i, _mm_movpi64_epi64, __m64 q);
YW_INTRIN_FUNC(__m64, _mm_movepi64_pi64, __m128i q);
#endif

#ifdef YW_INTRIN_X64
YW_INTRIN_FUNC(int8, _mm_cvtsd_si64, __m128d);
YW_INTRIN_FUNC(int8, _mm_cvttsd_si64, __m128d);
YW_INTRIN_FUNC(__m128d, _mm_cvtsi64_sd, __m128d, int8);
YW_INTRIN_FUNC(__m128i, _mm_cvtsi64_si128, int8);
YW_INTRIN_FUNC(int8, _mm_cvtsi128_si64, __m128i);
#endif

}
