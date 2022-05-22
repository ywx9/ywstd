// ywstd/immintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "wmmintrin.hh"

#ifdef _ywstd_
#include <immintrin.h>
namespace yw::intrin {
using ::__m256;
using ::__m256d;
using ::__m256i;
}
#else
namespace yw::intrin {
union alignas(32) __m256 {
  fat4 m256_f32[8];
};
union alignas(32) __m256d {
  fat8 m256_f64[4];
};
union alignas(32) __m256i {
  int1 m256i_i8[32];
  int2 m256i_i16[16];
  int4 m256i_i32[8];
  int8 m256i_i64[4];
  nat1 m256i_u8[32];
  nat2 m256i_u16[16];
  nat4 m256i_u32[8];
  nat8 m256i_u64[4];
};
}
#endif

namespace yw::intrin {

YW_INTRIN_FUNC(__m256d, _mm256_add_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_add_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_addsub_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_addsub_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_and_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_and_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_andnot_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_andnot_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_blend_pd, __m256d, __m256d, const int);
YW_INTRIN_FUNC(__m256, _mm256_blend_ps, __m256, __m256, const int);
YW_INTRIN_FUNC(__m256d, _mm256_blendv_pd, __m256d, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_blendv_ps, __m256, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_div_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_div_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256, _mm256_dp_ps, __m256, __m256, const int);
YW_INTRIN_FUNC(__m256d, _mm256_hadd_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_hadd_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_hsub_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_hsub_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_max_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_max_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_min_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_min_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_mul_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_mul_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_or_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_or_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_shuffle_pd, __m256d, __m256d, const int);
YW_INTRIN_FUNC(__m256, _mm256_shuffle_ps, __m256, __m256, const int);
YW_INTRIN_FUNC(__m256d, _mm256_sub_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_sub_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_xor_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_xor_ps, __m256, __m256);
YW_INTRIN_FUNC(__m128d, _mm_cmp_pd, __m128d, __m128d, const int);
YW_INTRIN_FUNC(__m256d, _mm256_cmp_pd, __m256d, __m256d, const int);
YW_INTRIN_FUNC(__m128, _mm_cmp_ps, __m128, __m128, const int);
YW_INTRIN_FUNC(__m256, _mm256_cmp_ps, __m256, __m256, const int);
YW_INTRIN_FUNC(__m128d, _mm_cmp_sd, __m128d, __m128d, const int);
YW_INTRIN_FUNC(int, _mm_comi_sd, __m128d, __m128d, const int);
YW_INTRIN_FUNC(__m128, _mm_cmp_ss, __m128, __m128, const int);
YW_INTRIN_FUNC(int, _mm_comi_ss, __m128, __m128, const int);
YW_INTRIN_FUNC(__m256d, _mm256_cvtepi32_pd, __m128i);
YW_INTRIN_FUNC(__m256, _mm256_cvtepi32_ps, __m256i);
YW_INTRIN_FUNC(__m128, _mm256_cvtpd_ps, __m256d);
YW_INTRIN_FUNC(__m256i, _mm256_cvtps_epi32, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_cvtps_pd, __m128);
YW_INTRIN_FUNC(__m128i, _mm256_cvttpd_epi32, __m256d);
YW_INTRIN_FUNC(__m128i, _mm256_cvtpd_epi32, __m256d);
YW_INTRIN_FUNC(__m256i, _mm256_cvttps_epi32, __m256);
YW_INTRIN_FUNC(__m128, _mm256_extractf128_ps, __m256, const int);
YW_INTRIN_FUNC(__m128d, _mm256_extractf128_pd, __m256d, const int);
YW_INTRIN_FUNC(__m128i, _mm256_extractf128_si256, __m256i, const int);
YW_INTRIN_VOID(void, _mm256_zeroall, void);
YW_INTRIN_VOID(void, _mm256_zeroupper, void);
YW_INTRIN_FUNC(__m256, _mm256_permutevar_ps, __m256, __m256i);
YW_INTRIN_FUNC(__m128, _mm_permutevar_ps, __m128, __m128i);
YW_INTRIN_FUNC(__m256, _mm256_permute_ps, __m256, int);
YW_INTRIN_FUNC(__m128, _mm_permute_ps, __m128, int);
YW_INTRIN_FUNC(__m256d, _mm256_permutevar_pd, __m256d, __m256i);
YW_INTRIN_FUNC(__m128d, _mm_permutevar_pd, __m128d, __m128i);
YW_INTRIN_FUNC(__m256d, _mm256_permute_pd, __m256d, int);
YW_INTRIN_FUNC(__m128d, _mm_permute_pd, __m128d, int);
YW_INTRIN_FUNC(__m256, _mm256_permute2f128_ps, __m256, __m256, int);
YW_INTRIN_FUNC(__m256d, _mm256_permute2f128_pd, __m256d, __m256d, int);
YW_INTRIN_FUNC(__m256i, _mm256_permute2f128_si256, __m256i, __m256i, int);
YW_INTRIN_FUNC(__m256, _mm256_broadcast_ss, const fat4*);
YW_INTRIN_FUNC(__m128, _mm_broadcast_ss, const fat4*);
YW_INTRIN_FUNC(__m256d, _mm256_broadcast_sd, const fat8*);
YW_INTRIN_FUNC(__m256, _mm256_broadcast_ps, __m128 const*);
YW_INTRIN_FUNC(__m256d, _mm256_broadcast_pd, __m128d const*);
YW_INTRIN_FUNC(__m256, _mm256_insertf128_ps, __m256, __m128, int);
YW_INTRIN_FUNC(__m256d, _mm256_insertf128_pd, __m256d, __m128d, int);
YW_INTRIN_FUNC(__m256i, _mm256_insertf128_si256, __m256i, __m128i, int);
YW_INTRIN_FUNC(__m256d, _mm256_load_pd, const fat8*);
YW_INTRIN_VOID(void, _mm256_store_pd, fat8*, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_load_ps, const fat4*);
YW_INTRIN_VOID(void, _mm256_store_ps, fat4*, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_loadu_pd, const fat8*);
YW_INTRIN_VOID(void, _mm256_storeu_pd, fat8*, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_loadu_ps, const fat4*);
YW_INTRIN_VOID(void, _mm256_storeu_ps, fat4*, __m256);
YW_INTRIN_FUNC(__m256i, _mm256_load_si256, __m256i const*);
YW_INTRIN_VOID(void, _mm256_store_si256, __m256i*, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_loadu_si256, __m256i const*);
YW_INTRIN_VOID(void, _mm256_storeu_si256, __m256i*, __m256i);
YW_INTRIN_FUNC(__m256d, _mm256_maskload_pd, const fat8*, __m256i);
YW_INTRIN_VOID(void, _mm256_maskstore_pd, fat8*, __m256i, __m256d);
YW_INTRIN_FUNC(__m128d, _mm_maskload_pd, const fat8*, __m128i);
YW_INTRIN_VOID(void, _mm_maskstore_pd, fat8*, __m128i, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_maskload_ps, const fat4*, __m256i);
YW_INTRIN_VOID(void, _mm256_maskstore_ps, fat4*, __m256i, __m256);
YW_INTRIN_FUNC(__m128, _mm_maskload_ps, const fat4*, __m128i);
YW_INTRIN_VOID(void, _mm_maskstore_ps, fat4*, __m128i, __m128);
YW_INTRIN_FUNC(__m256, _mm256_movehdup_ps, __m256);
YW_INTRIN_FUNC(__m256, _mm256_moveldup_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_movedup_pd, __m256d);
YW_INTRIN_FUNC(__m256i, _mm256_lddqu_si256, __m256i const*);
YW_INTRIN_VOID(void, _mm256_stream_si256, __m256i*, __m256i);
YW_INTRIN_VOID(void, _mm256_stream_pd, fat8*, __m256d);
YW_INTRIN_VOID(void, _mm256_stream_ps, fat4*, __m256);
YW_INTRIN_FUNC(__m256, _mm256_rcp_ps, __m256);
YW_INTRIN_FUNC(__m256, _mm256_rsqrt_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_sqrt_pd, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_sqrt_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_round_pd, __m256d, int);
YW_INTRIN_FUNC(__m256, _mm256_round_ps, __m256, int);
YW_INTRIN_FUNC(__m256d, _mm256_unpackhi_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_unpackhi_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_unpacklo_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_unpacklo_ps, __m256, __m256);
YW_INTRIN_FUNC(int, _mm256_testz_si256, __m256i, __m256i);
YW_INTRIN_FUNC(int, _mm256_testc_si256, __m256i, __m256i);
YW_INTRIN_FUNC(int, _mm256_testnzc_si256, __m256i, __m256i);
YW_INTRIN_FUNC(int, _mm256_testz_pd, __m256d, __m256d);
YW_INTRIN_FUNC(int, _mm256_testc_pd, __m256d, __m256d);
YW_INTRIN_FUNC(int, _mm256_testnzc_pd, __m256d, __m256d);
YW_INTRIN_FUNC(int, _mm_testz_pd, __m128d, __m128d);
YW_INTRIN_FUNC(int, _mm_testc_pd, __m128d, __m128d);
YW_INTRIN_FUNC(int, _mm_testnzc_pd, __m128d, __m128d);
YW_INTRIN_FUNC(int, _mm256_testz_ps, __m256, __m256);
YW_INTRIN_FUNC(int, _mm256_testc_ps, __m256, __m256);
YW_INTRIN_FUNC(int, _mm256_testnzc_ps, __m256, __m256);
YW_INTRIN_FUNC(int, _mm_testz_ps, __m128, __m128);
YW_INTRIN_FUNC(int, _mm_testc_ps, __m128, __m128);
YW_INTRIN_FUNC(int, _mm_testnzc_ps, __m128, __m128);
YW_INTRIN_FUNC(int, _mm256_movemask_pd, __m256d);
YW_INTRIN_FUNC(int, _mm256_movemask_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_setzero_pd, void);
YW_INTRIN_FUNC(__m256, _mm256_setzero_ps, void);
YW_INTRIN_FUNC(__m256i, _mm256_setzero_si256, void);
YW_INTRIN_FUNC(__m256d, _mm256_set_pd, fat8, fat8, fat8, fat8);
YW_INTRIN_FUNC(__m256, _mm256_set_ps, fat4, fat4, fat4, fat4, fat4, fat4, fat4, fat4);
YW_INTRIN_FUNC(__m256i, _mm256_set_epi8, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char);
YW_INTRIN_FUNC(__m256i, _mm256_set_epi16, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2);
YW_INTRIN_FUNC(__m256i, _mm256_set_epi32, int, int, int, int, int, int, int, int);
YW_INTRIN_FUNC(__m256i, _mm256_set_epi64x, int8, int8, int8, int8);
YW_INTRIN_FUNC(__m256d, _mm256_setr_pd, fat8, fat8, fat8, fat8);
YW_INTRIN_FUNC(__m256, _mm256_setr_ps, fat4, fat4, fat4, fat4, fat4, fat4, fat4, fat4);
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi8, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char, char);
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi16, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2, int2);
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi32, int, int, int, int, int, int, int, int);
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi64x, int8, int8, int8, int8);
YW_INTRIN_FUNC(__m256d, _mm256_set1_pd, fat8);
YW_INTRIN_FUNC(__m256, _mm256_set1_ps, fat4);
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi8, char);
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi16, int2);
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi32, int);
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi64x, long long);
YW_INTRIN_FUNC(__m256, _mm256_castpd_ps, __m256d);
YW_INTRIN_FUNC(__m256d, _mm256_castps_pd, __m256);
YW_INTRIN_FUNC(__m256i, _mm256_castps_si256, __m256);
YW_INTRIN_FUNC(__m256i, _mm256_castpd_si256, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_castsi256_ps, __m256i);
YW_INTRIN_FUNC(__m256d, _mm256_castsi256_pd, __m256i);
YW_INTRIN_FUNC(__m128, _mm256_castps256_ps128, __m256);
YW_INTRIN_FUNC(__m128d, _mm256_castpd256_pd128, __m256d);
YW_INTRIN_FUNC(__m128i, _mm256_castsi256_si128, __m256i);
YW_INTRIN_FUNC(__m256, _mm256_castps128_ps256, __m128);
YW_INTRIN_FUNC(__m256d, _mm256_castpd128_pd256, __m128d);
YW_INTRIN_FUNC(__m256i, _mm256_castsi128_si256, __m128i);
YW_INTRIN_FUNC(__m128, _mm_cvtph_ps, __m128i);
YW_INTRIN_FUNC(__m256, _mm256_cvtph_ps, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_cvtps_ph, __m128 m, const int imm);
YW_INTRIN_FUNC(__m128i, _mm256_cvtps_ph, __m256, int);
YW_INTRIN_FUNC(nat8, _xgetbv, nat4);
YW_INTRIN_VOID(void, _xsetbv, nat4, nat8);
YW_INTRIN_VOID(void, _xsave, void*, nat8);
YW_INTRIN_VOID(void, _xsaveopt, void*, nat8);
YW_INTRIN_VOID(void, _xsavec, void*, nat8);
YW_INTRIN_VOID(void, _xrstor, const void*, nat8);
YW_INTRIN_VOID(void, _xsaves, void*, nat8);
YW_INTRIN_VOID(void, _xrstors, const void*, nat8);
YW_INTRIN_VOID(void, _fxsave, void*);
YW_INTRIN_VOID(void, _fxrstor, const void*);
YW_INTRIN_FUNC(int, _rdrand16_step, nat2*);
YW_INTRIN_FUNC(int, _rdrand32_step, nat4*);
YW_INTRIN_FUNC(__m128, _mm_fmadd_ps, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fmadd_pd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fmadd_ss, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fmadd_sd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fmsub_ps, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fmsub_pd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fmsub_ss, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fmsub_sd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fnmadd_ps, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fnmadd_pd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fnmadd_ss, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fnmadd_sd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fnmsub_ps, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fnmsub_pd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fnmsub_ss, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fnmsub_sd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_fmadd_ps, __m256, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_fmadd_pd, __m256d, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_fmsub_ps, __m256, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_fmsub_pd, __m256d, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_fnmadd_ps, __m256, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_fnmadd_pd, __m256d, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_fnmsub_ps, __m256, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_fnmsub_pd, __m256d, __m256d, __m256d);
YW_INTRIN_FUNC(__m128, _mm_fmaddsub_ps, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fmaddsub_pd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m128, _mm_fmsubadd_ps, __m128, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fmsubadd_pd, __m128d, __m128d, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_fmaddsub_ps, __m256, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_fmaddsub_pd, __m256d, __m256d, __m256d);
YW_INTRIN_FUNC(__m256, _mm256_fmsubadd_ps, __m256, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_fmsubadd_pd, __m256d, __m256d, __m256d);
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_max_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_max_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_max_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_max_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_max_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_max_epu32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_min_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_min_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_min_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_min_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_min_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_min_epu32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_and_si256, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_andnot_si256, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_or_si256, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_xor_si256, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_abs_epi8, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_abs_epi16, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_abs_epi32, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_add_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_add_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_add_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_add_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_adds_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_adds_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_adds_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_adds_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_subs_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_subs_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_subs_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_subs_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_avg_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_avg_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_hadd_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_hadd_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_hadds_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_hsub_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_hsub_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_hsubs_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_madd_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_maddubs_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mulhi_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mulhi_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mullo_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mullo_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mul_epu32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mul_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sign_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sign_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sign_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mulhrs_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sad_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_mpsadbw_epu8, __m256i, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_slli_si256, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_srli_si256, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_sll_epi16, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_sll_epi32, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_sll_epi64, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_slli_epi16, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_slli_epi32, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_slli_epi64, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_sllv_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_sllv_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_sllv_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sllv_epi64, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_sra_epi16, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_sra_epi32, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_srai_epi16, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_srai_epi32, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_srav_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_srav_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_srl_epi16, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_srl_epi32, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_srl_epi64, __m256i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_srli_epi16, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_srli_epi32, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_srli_epi64, __m256i, int);
YW_INTRIN_FUNC(__m256i, _mm256_srlv_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_srlv_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_srlv_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_srlv_epi64, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_blend_epi32, __m128i, __m128i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_blend_epi32, __m256i, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_alignr_epi8, __m256i, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_blendv_epi8, __m256i, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_blend_epi16, __m256i, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_packs_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_packs_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_packus_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_packus_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_shuffle_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_shuffle_epi32, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_shufflehi_epi16, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_shufflelo_epi16, __m256i, const int);
YW_INTRIN_FUNC(__m128i, _mm256_extracti128_si256, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_inserti128_si256, __m256i, __m128i, const int);
YW_INTRIN_FUNC(__m128, _mm_broadcastss_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_broadcastsd_pd, __m128d);
YW_INTRIN_FUNC(__m128i, _mm_broadcastb_epi8, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_broadcastw_epi16, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_broadcastd_epi32, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_broadcastq_epi64, __m128i);
YW_INTRIN_FUNC(__m256, _mm256_broadcastss_ps, __m128);
YW_INTRIN_FUNC(__m256d, _mm256_broadcastsd_pd, __m128d);
YW_INTRIN_FUNC(__m256i, _mm256_broadcastb_epi8, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_broadcastw_epi16, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_broadcastd_epi32, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_broadcastq_epi64, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_broadcastsi128_si256, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi8_epi16, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi8_epi32, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi8_epi64, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi16_epi32, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi16_epi64, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi32_epi64, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu8_epi16, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu8_epi32, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu8_epi64, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu16_epi32, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu16_epi64, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu32_epi64, __m128i);
YW_INTRIN_FUNC(int, _mm256_movemask_epi8, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_maskload_epi32, const int4* ptr, __m128i vmask);
YW_INTRIN_FUNC(__m128i, _mm_maskload_epi64, const int8* ptr, __m128i vmask);
YW_INTRIN_VOID(void, _mm_maskstore_epi32, int* ptr, __m128i vmask, __m128i val);
YW_INTRIN_VOID(void, _mm_maskstore_epi64, int8* ptr, __m128i vmask, __m128i val);
YW_INTRIN_FUNC(__m256i, _mm256_maskload_epi32, const int4* ptr, __m256i vmask);
YW_INTRIN_FUNC(__m256i, _mm256_maskload_epi64, const int8* ptr, __m256i vmask);
YW_INTRIN_VOID(void, _mm256_maskstore_epi32, int* ptr, __m256i vmask, __m256i val);
YW_INTRIN_VOID(void, _mm256_maskstore_epi64, int8* ptr, __m256i vmask, __m256i val);
YW_INTRIN_FUNC(__m256i, _mm256_permutevar8x32_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256, _mm256_permutevar8x32_ps, __m256, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_permute4x64_epi64, __m256i, const int);
YW_INTRIN_FUNC(__m256d, _mm256_permute4x64_pd, __m256d, const int);
YW_INTRIN_FUNC(__m256i, _mm256_permute2x128_si256, __m256i, __m256i, const int);
YW_INTRIN_FUNC(__m256i, _mm256_stream_load_si256, __m256i const*);
YW_INTRIN_FUNC(__m256d, _mm256_mask_i32gather_pd, __m256d old_dst, const fat8* ptr, __m128i vindex, __m256d vmask, const int scale);
YW_INTRIN_FUNC(__m256, _mm256_mask_i32gather_ps, __m256 old_dst, const fat4* ptr, __m256i vindex, __m256 vmask, const int scale);
YW_INTRIN_FUNC(__m256d, _mm256_mask_i64gather_pd, __m256d old_dst, const fat8* ptr, __m256i vindex, __m256d vmask, const int scale);
YW_INTRIN_FUNC(__m128, _mm256_mask_i64gather_ps, __m128 old_dst, const fat4* ptr, __m256i vindex, __m128 vmask, const int scale);
YW_INTRIN_FUNC(__m128d, _mm_mask_i32gather_pd, __m128d old_dst, const fat8* ptr, __m128i vindex, __m128d vmask, const int scale);
YW_INTRIN_FUNC(__m128, _mm_mask_i32gather_ps, __m128 old_dst, const fat4* ptr, __m128i vindex, __m128 vmask, const int scale);
YW_INTRIN_FUNC(__m128d, _mm_mask_i64gather_pd, __m128d old_dst, const fat8* ptr, __m128i vindex, __m128d vmask, const int scale);
YW_INTRIN_FUNC(__m128, _mm_mask_i64gather_ps, __m128 old_dst, const fat4* ptr, __m128i vindex, __m128 vmask, const int scale);
YW_INTRIN_FUNC(__m256i, _mm256_mask_i32gather_epi32, __m256i old_dst, const int4* ptr, __m256i vindex, __m256i vmask, const int scale);
YW_INTRIN_FUNC(__m256i, _mm256_mask_i32gather_epi64, __m256i old_dst, const int8* ptr, __m128i vindex, __m256i vmask, const int scale);
YW_INTRIN_FUNC(__m128i, _mm256_mask_i64gather_epi32, __m128i old_dst, const int4* ptr, __m256i vindex, __m128i vmask, const int scale);
YW_INTRIN_FUNC(__m256i, _mm256_mask_i64gather_epi64, __m256i old_dst, const int8* ptr, __m256i vindex, __m256i vmask, const int scale);
YW_INTRIN_FUNC(__m128i, _mm_mask_i32gather_epi32, __m128i old_dst, const int4* ptr, __m128i vindex, __m128i vmask, const int scale);
YW_INTRIN_FUNC(__m128i, _mm_mask_i32gather_epi64, __m128i old_dst, const int8* ptr, __m128i vindex, __m128i vmask, const int scale);
YW_INTRIN_FUNC(__m128i, _mm_mask_i64gather_epi32, __m128i old_dst, const int4* ptr, __m128i vindex, __m128i vmask, const int scale);
YW_INTRIN_FUNC(__m128i, _mm_mask_i64gather_epi64, __m128i old_dst, const int8* ptr, __m128i vindex, __m128i vmask, const int scale);
YW_INTRIN_FUNC(__m256d, _mm256_i32gather_pd, const fat8* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m256, _mm256_i32gather_ps, const fat4* ptr, __m256i vindex, const int index_scale);
YW_INTRIN_FUNC(__m256d, _mm256_i64gather_pd, const fat8* ptr, __m256i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128, _mm256_i64gather_ps, const fat4* ptr, __m256i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128d, _mm_i32gather_pd, const fat8* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128, _mm_i32gather_ps, const fat4* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128d, _mm_i64gather_pd, const fat8* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128, _mm_i64gather_ps, const fat4* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m256i, _mm256_i32gather_epi32, const int4* ptr, __m256i vindex, const int scale);
YW_INTRIN_FUNC(__m256i, _mm256_i32gather_epi64, const int8* ptr, __m128i vindex, const int scale);
YW_INTRIN_FUNC(__m128i, _mm256_i64gather_epi32, const int4* ptr, __m256i vindex, const int scale);
YW_INTRIN_FUNC(__m256i, _mm256_i64gather_epi64, const int8* ptr, __m256i vindex, const int scale);
YW_INTRIN_FUNC(__m128i, _mm_i32gather_epi32, const int4* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128i, _mm_i32gather_epi64, const int8* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128i, _mm_i64gather_epi32, int const* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(__m128i, _mm_i64gather_epi64, const int8* ptr, __m128i vindex, const int index_scale);
YW_INTRIN_FUNC(nat4, _bextr_u32, nat4 src, nat4 start_bit, nat4 len_in_bits);
YW_INTRIN_FUNC(nat4, _bextr2_u32, nat4 src, nat4 start_and_len_in_bits);
YW_INTRIN_FUNC(nat4, _blsi_u32, nat4);
YW_INTRIN_FUNC(nat4, _blsmsk_u32, nat4);
YW_INTRIN_FUNC(nat4, _blsr_u32, nat4);
YW_INTRIN_FUNC(nat4, _bzhi_u32, nat4 src, nat4 index);
YW_INTRIN_FUNC(nat4, _mulx_u32, nat4 src1, nat4 src2, nat4* high_bits);
YW_INTRIN_FUNC(nat4, _pdep_u32, nat4 src, nat4 mask);
YW_INTRIN_FUNC(nat4, _pext_u32, nat4 src, nat4 mask);
YW_INTRIN_FUNC(nat4, _rorx_u32, nat4 src, const nat4 shift_count);
YW_INTRIN_FUNC(int, _sarx_i32, int src, nat4 shift_count);
YW_INTRIN_FUNC(nat4, _shlx_u32, nat4 src, nat4 shift_count);
YW_INTRIN_FUNC(nat4, _shrx_u32, nat4 src, nat4 shift_count);
YW_INTRIN_FUNC(nat4, _lzcnt_u32, nat4);
YW_INTRIN_FUNC(nat4, _tzcnt_u32, nat4);
YW_INTRIN_VOID(void, _invpcid, nat4 type, void* descriptor);
YW_INTRIN_FUNC(nat4, _xbegin, void);
YW_INTRIN_VOID(void, _xend, void);
YW_INTRIN_VOID(void, _xabort, const nat4);
YW_INTRIN_FUNC(nat1, _xtest, void);
YW_INTRIN_FUNC(int, _rdseed16_step, nat2*);
YW_INTRIN_FUNC(int, _rdseed32_step, nat4*);
YW_INTRIN_FUNC(nat1, _addcarryx_u32, nat1 c_in, nat4 src1, nat4 src2, nat4* out);
YW_INTRIN_FUNC(nat2, _load_be_u16, const void*);
YW_INTRIN_FUNC(nat4, _load_be_u32, const void*);
YW_INTRIN_FUNC(nat8, _load_be_u64, const void*);
YW_INTRIN_VOID(void, _store_be_u16, void*, nat2);
YW_INTRIN_VOID(void, _store_be_u32, void*, nat4);
YW_INTRIN_VOID(void, _store_be_u64, void*, nat8);
YW_INTRIN_FUNC(__m128i, _mm_sha1msg1_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sha1msg2_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sha1nexte_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sha1rnds4_epu32, __m128i, __m128i, const int);
YW_INTRIN_FUNC(__m128i, _mm_sha256msg1_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sha256msg2_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_sha256rnds2_epu32, __m128i, __m128i, __m128i);
YW_INTRIN_FUNC(type<void*>, _bnd_set_ptr_bounds, const void*, size_t);
YW_INTRIN_FUNC(type<void*>, _bnd_narrow_ptr_bounds, const void*, const void*, size_t);
YW_INTRIN_FUNC(type<void*>, _bnd_copy_ptr_bounds, const void*, const void*);
YW_INTRIN_FUNC(type<void*>, _bnd_init_ptr_bounds, const void*);
YW_INTRIN_VOID(void, _bnd_store_ptr_bounds, const void**, const void*);
YW_INTRIN_VOID(void, _bnd_chk_ptr_lbounds, const void*);
YW_INTRIN_VOID(void, _bnd_chk_ptr_ubounds, const void*);
YW_INTRIN_VOID(void, _bnd_chk_ptr_bounds, const void*, size_t);
YW_INTRIN_FUNC(type<void*>, _bnd_load_ptr_bounds, const void**, const void*);
YW_INTRIN_FUNC(type<const void*>, _bnd_get_ptr_lbound, const void*);
YW_INTRIN_FUNC(type<const void*>, _bnd_get_ptr_ubound, const void*);
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi8, __m256i dst, int src, const int index);
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi16, __m256i dst, int src, const int index);
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi32, __m256i dst, int src, const int index);
YW_INTRIN_FUNC(int, _mm256_extract_epi8, __m256i src, const int index);
YW_INTRIN_FUNC(int, _mm256_extract_epi16, __m256i src, const int index);
YW_INTRIN_FUNC(int, _mm256_extract_epi32, __m256i src, const int index);
YW_INTRIN_FUNC(__m256d, _mm256_zextpd128_pd256, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_zextps128_ps256, __m128);
YW_INTRIN_FUNC(__m256i, _mm256_zextsi128_si256, __m128i);
YW_INTRIN_FUNC(nat4, _rdpid_u32, void);
YW_INTRIN_VOID(void, _ptwrite32, nat4);
YW_INTRIN_FUNC(__m128i, _mm_dpbusd_avx_epi32, __m128i, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_dpbusd_avx_epi32, __m256i, __m256i, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_dpbusds_avx_epi32, __m128i, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_dpbusds_avx_epi32, __m256i, __m256i, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_dpwssd_avx_epi32, __m128i, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_dpwssd_avx_epi32, __m256i, __m256i, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_dpwssds_avx_epi32, __m128i, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_dpwssds_avx_epi32, __m256i, __m256i, __m256i);
YW_INTRIN_FUNC(nat4, _pconfig_u32, const int, size_t __data[]);
YW_INTRIN_VOID(void, _wbnoinvd, void);
YW_INTRIN_FUNC(nat4, _encls_u32, const int, size_t __data[]);
YW_INTRIN_FUNC(nat4, _enclu_u32, const int, size_t __data[]);
YW_INTRIN_FUNC(nat4, _enclv_u32, const int, size_t __data[]);
YW_INTRIN_FUNC(nat4, _udiv64, nat8 dividend, nat4 divisor, nat4* remainder);
YW_INTRIN_FUNC(int, _div64, int8 dividend, int divisor, int* remainder);
YW_INTRIN_FUNC(nat1, _mm_aesdec128kl_u8, __m128i* odata, __m128i idata, const void* h);
YW_INTRIN_FUNC(nat1, _mm_aesdec256kl_u8, __m128i* odata, __m128i idata, const void* h);
YW_INTRIN_FUNC(nat1, _mm_aesdecwide128kl_u8, __m128i* odata, const __m128i* idata, const void* h);
YW_INTRIN_FUNC(nat1, _mm_aesdecwide256kl_u8, __m128i* odata, const __m128i* idata, const void* h);
YW_INTRIN_FUNC(nat1, _mm_aesenc128kl_u8, __m128i* odata, __m128i idata, const void* h);
YW_INTRIN_FUNC(nat1, _mm_aesenc256kl_u8, __m128i* odata, __m128i idata, const void* h);
YW_INTRIN_FUNC(nat1, _mm_aesencwide128kl_u8, __m128i* odata, const __m128i* idata, const void* h);
YW_INTRIN_FUNC(nat1, _mm_aesencwide256kl_u8, __m128i* odata, const __m128i* idata, const void* h);
YW_INTRIN_FUNC(nat4, _mm_encodekey128_u32, nat4 htype, __m128i key, void* h);
YW_INTRIN_FUNC(nat4, _mm_encodekey256_u32, nat4 htype, __m128i key_lo, __m128i key_hi, void* h);
YW_INTRIN_VOID(void, _mm_loadiwkey, nat4 ctl, __m128i intkey, __m128i enkey_lo, __m128i enkey_hi);
YW_INTRIN_FUNC(nat4, _rdpkru_u32, void);
YW_INTRIN_VOID(void, _wrpkru, nat4);
YW_INTRIN_FUNC(int, _enqcmd, void* dst, const void* src);
YW_INTRIN_FUNC(int, _enqcmds, void* dst, const void* src);
YW_INTRIN_VOID(void, _incsspd, nat4);
YW_INTRIN_FUNC(nat4, _rdsspd, void);
YW_INTRIN_VOID(void, _saveprevssp, void);
YW_INTRIN_VOID(void, _rstorssp, void*);
YW_INTRIN_VOID(void, _wrssd, nat4, void*);
YW_INTRIN_VOID(void, _wrussd, nat4, void*);
YW_INTRIN_VOID(void, _setssbsy, void);
YW_INTRIN_VOID(void, _clrssbsy, void*);
YW_INTRIN_FUNC(type<void*>, _switchssp, void*);
YW_INTRIN_FUNC(__m128i, _mm_div_epi8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_div_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_div_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_div_epi64, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_div_epu8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_div_epu16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_div_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_div_epu64, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epi8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epi16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epi32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epi64, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epu8, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epu16, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epu32, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_rem_epu64, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epu32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_div_epu64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi64, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu8, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu16, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu32, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu64, __m256i, __m256i);
YW_INTRIN_FUNC(__m128i, _mm_divrem_epi32, __m128i* rem_res, __m128i, __m128i);
YW_INTRIN_FUNC(__m128i, _mm_divrem_epu32, __m128i* rem_res, __m128i, __m128i);
YW_INTRIN_FUNC(__m256i, _mm256_divrem_epi32, __m256i* rem_res, __m256i, __m256i);
YW_INTRIN_FUNC(__m256i, _mm256_divrem_epu32, __m256i* rem_res, __m256i, __m256i);
YW_INTRIN_FUNC(__m128, _mm_sin_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_sin_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_sin_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_sin_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_cos_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_cos_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_cos_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_cos_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_sincos_ps, __m128* cos_res, __m128);
YW_INTRIN_FUNC(__m128d, _mm_sincos_pd, __m128d* cos_res, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_sincos_ps, __m256* cos_res, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_sincos_pd, __m256d* cos_res, __m256d);
YW_INTRIN_FUNC(__m128, _mm_tan_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_tan_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_tan_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_tan_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_asin_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_asin_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_asin_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_asin_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_acos_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_acos_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_acos_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_acos_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_atan_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_atan_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_atan_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_atan_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_atan2_ps, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_atan2_pd, __m128d, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_atan2_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_atan2_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m128, _mm_sind_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_sind_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_sind_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_sind_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_cosd_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_cosd_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_cosd_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_cosd_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_tand_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_tand_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_tand_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_tand_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_sinh_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_sinh_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_sinh_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_sinh_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_cosh_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_cosh_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_cosh_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_cosh_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_tanh_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_tanh_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_tanh_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_tanh_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_asinh_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_asinh_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_asinh_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_asinh_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_acosh_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_acosh_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_acosh_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_acosh_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_atanh_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_atanh_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_atanh_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_atanh_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_log_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_log_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_log_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_log_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_log1p_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_log1p_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_log1p_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_log1p_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_log10_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_log10_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_log10_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_log10_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_log2_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_log2_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_log2_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_log2_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_logb_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_logb_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_logb_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_logb_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_exp_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_exp_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_exp_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_exp_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_exp10_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_exp10_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_exp10_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_exp10_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_exp2_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_exp2_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_exp2_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_exp2_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_expm1_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_expm1_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_expm1_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_expm1_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_pow_ps, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_pow_pd, __m128d, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_pow_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_pow_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m128, _mm_trunc_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_trunc_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_trunc_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_trunc_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_svml_floor_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_svml_floor_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_svml_floor_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_svml_floor_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_svml_ceil_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_svml_ceil_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_svml_ceil_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_svml_ceil_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_svml_round_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_svml_round_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_svml_round_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_svml_round_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_fmod_ps, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_fmod_pd, __m128d, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_fmod_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_fmod_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m128, _mm_svml_sqrt_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_svml_sqrt_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_svml_sqrt_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_svml_sqrt_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_invsqrt_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_invsqrt_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_invsqrt_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_invsqrt_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_cbrt_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_cbrt_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_cbrt_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_cbrt_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_invcbrt_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_invcbrt_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_invcbrt_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_invcbrt_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_hypot_ps, __m128, __m128);
YW_INTRIN_FUNC(__m128d, _mm_hypot_pd, __m128d, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_hypot_ps, __m256, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_hypot_pd, __m256d, __m256d);
YW_INTRIN_FUNC(__m128, _mm_cdfnorm_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_cdfnorm_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_cdfnorm_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_cdfnorm_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_cdfnorminv_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_cdfnorminv_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_cdfnorminv_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_cdfnorminv_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_cexp_ps, __m128);
YW_INTRIN_FUNC(__m256, _mm256_cexp_ps, __m256);
YW_INTRIN_FUNC(__m128, _mm_clog_ps, __m128);
YW_INTRIN_FUNC(__m256, _mm256_clog_ps, __m256);
YW_INTRIN_FUNC(__m128, _mm_csqrt_ps, __m128);
YW_INTRIN_FUNC(__m256, _mm256_csqrt_ps, __m256);
YW_INTRIN_FUNC(__m128, _mm_erf_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_erf_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_erf_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_erf_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_erfc_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_erfc_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_erfc_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_erfc_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_erfcinv_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_erfcinv_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_erfcinv_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_erfcinv_pd, __m256d);
YW_INTRIN_FUNC(__m128, _mm_erfinv_ps, __m128);
YW_INTRIN_FUNC(__m128d, _mm_erfinv_pd, __m128d);
YW_INTRIN_FUNC(__m256, _mm256_erfinv_ps, __m256);
YW_INTRIN_FUNC(__m256d, _mm256_erfinv_pd, __m256d);
YW_INTRIN_VOID(void, _mm_cldemote, const void*);
YW_INTRIN_VOID(void, _directstoreu_u32, void*, nat4);
YW_INTRIN_VOID(void, _movdir64b, void*, const void*);
YW_INTRIN_VOID(void, _serialize, void);
YW_INTRIN_VOID(void, _xsusldtrk, void);
YW_INTRIN_VOID(void, _xresldtrk, void);
YW_INTRIN_VOID(void, _umonitor, void*);
YW_INTRIN_FUNC(nat1, _umwait, nat4, nat8);
YW_INTRIN_FUNC(nat1, _tpause, nat4, nat8);
YW_INTRIN_VOID(void, _hreset, nat4);
YW_INTRIN_FUNC(__m128, _mm_svml_cvtepu32_ps, __m128i);
YW_INTRIN_FUNC(__m256, _mm256_svml_cvtepu32_ps, __m256i);
YW_INTRIN_FUNC(__m128d, _mm_svml_cvtepu32_pd, __m128i);
YW_INTRIN_FUNC(__m256d, _mm256_svml_cvtepu32_pd, __m128i);
YW_INTRIN_FUNC(__m128d, _mm_svml_cvtepi64_pd, __m128i);
YW_INTRIN_FUNC(__m256d, _mm256_svml_cvtepi64_pd, __m256i);
YW_INTRIN_FUNC(__m128d, _mm_svml_cvtepu64_pd, __m128i);
YW_INTRIN_FUNC(__m256d, _mm256_svml_cvtepu64_pd, __m256i);

inline fat4 _mm256_cvtss_f32 (__m256 a) { return _mm_cvtss_f32(_mm256_castps256_ps128(a)); }
inline fat8 _mm256_cvtsd_f64 (__m256d a) { return _mm_cvtsd_f64(_mm256_castpd256_pd128(a)); }
inline int _mm256_cvtsi256_si32 (__m256i a) { return _mm_cvtsi128_si32(_mm256_castsi256_si128(a)); }
inline __m256 _mm256_set_m128(__m128 hi, __m128 lo) { return _mm256_insertf128_ps(_mm256_castps128_ps256(lo), hi, 0x1); }
inline __m256d _mm256_set_m128d(__m128d hi, __m128d lo) { return _mm256_insertf128_pd(_mm256_castpd128_pd256(lo), hi, 0x1); }
inline __m256i _mm256_set_m128i(__m128i hi, __m128i lo) { return _mm256_insertf128_si256(_mm256_castsi128_si256(lo), hi, 0x1); }
inline __m256 _mm256_loadu2_m128(const fat4* hiaddr, const fat4* loaddr) { return _mm256_set_m128(_mm_loadu_ps(hiaddr), _mm_loadu_ps(loaddr)); }
inline __m256d _mm256_loadu2_m128d(const fat8* hiaddr, const fat8* loaddr) { return _mm256_set_m128d(_mm_loadu_pd(hiaddr), _mm_loadu_pd(loaddr)); }
inline __m256i _mm256_loadu2_m128i(const __m128i* hiaddr, const __m128i* loaddr) { return _mm256_set_m128i(_mm_loadu_si128(hiaddr), _mm_loadu_si128(loaddr)); }
inline __m256d _mm256_ceil_pd(__m256d val) { return _mm256_round_pd(val, 0); }
inline __m256d _mm256_floor_pd(__m256d val) { return _mm256_round_pd(val, 0); }
inline __m256 _mm256_ceil_ps(__m256 val) { return _mm256_round_ps(val, 0); }
inline __m256 _mm256_floor_ps(__m256 val) { return _mm256_round_ps(val, 0); }
inline int _mm256_test_all_zeros(__m256i mask, __m256i val) { return _mm256_testz_si256(mask, val); }
inline int _mm256_test_all_ones(__m256i val) { return _mm256_testc_si256(val, _mm256_cmpeq_epi32(val, val)); }
inline int _mm256_test_mix_ones_zeros(__m256i mask, __m256i val) { return _mm256_testnzc_si256(mask, val); }
inline __m256 _mm256_setr_m128(__m128 lo, __m128 hi) { return _mm256_set_m128(hi, lo); }
inline __m256d _mm256_setr_m128d(__m128d lo, __m128d hi) { return _mm256_set_m128d(hi, lo); }
inline __m256i _mm256_setr_m128i(__m128i lo, __m128i hi) { return _mm256_set_m128i(hi, lo); }
inline __m128 _mm_undefined_ps() { return _mm_setzero_ps(); }
inline __m128d _mm_undefined_pd() { return _mm_setzero_pd(); }
inline __m128i _mm_undefined_si128() { return _mm_setzero_si128(); }
inline __m256 _mm256_undefined_ps() { return _mm256_setzero_ps(); }
inline __m256d _mm256_undefined_pd() { return _mm256_setzero_pd(); }
inline __m256i _mm256_undefined_si256() { return _mm256_setzero_si256(); }
inline __m256i _mm256_bslli_epi128(__m256i a, const int b) { return _mm256_slli_si256(a, b); }
inline __m256i _mm256_bsrli_epi128(__m256i a, const int b) { return _mm256_srli_si256(a, b); }
inline __m128i _mm_loadu_si16(const void* p) { return _mm_cvtsi32_si128(*(const nat2*)(p)); }
inline void _mm_storeu_si16(void* p, __m128i a) { (void)(*(int2*)(p) = (int2)_mm_cvtsi128_si32((a))); }
inline __m128i _mm_loadu_si32(const void* p) { return _mm_cvtsi32_si128(*(const nat4*)(p)); }
inline void _mm_storeu_si32(void* p, __m128i a) { (void)(*(int*)(p) = _mm_cvtsi128_si32((a))); }
inline __m128i _mm_loadu_si64(const void* p) { return _mm_loadl_epi64((const __m128i*)(p)); }
inline void _mm_storeu_si64(void* p, __m128i a) { (void)(_mm_storel_epi64((__m128i*)(p), (a))); }
inline int2 _loadbe_i16(const void* p) { return (int2)_load_be_u16(p); }
inline int4 _loadbe_i32(const void* p) { return (int4)_load_be_u32(p); }
inline int8 _loadbe_i64(const void* p) { return (int8)_load_be_u64(p); }
inline void _storebe_i16(void* p, int2 v) { return _store_be_u16(p, (nat2)v); }
inline void _storebe_i32(void* p, int4 v) { return _store_be_u32(p, (nat4)v); }
inline void _storebe_i64(void* p, int8 v) { return _store_be_u64(p, (nat8)v); }
inline __m128i _mm_idiv_epi32(__m128i a, __m128i b) { return _mm_div_epi32(a, b); }
inline __m128i _mm_irem_epi32(__m128i a, __m128i b) { return _mm_rem_epi32(a, b); }
inline __m128i _mm_udiv_epi32(__m128i a, __m128i b) { return _mm_div_epu32(a, b); }
inline __m128i _mm_urem_epi32(__m128i a, __m128i b) { return _mm_rem_epu32(a, b); }
inline __m256i _mm256_idiv_epi32(__m256i a, __m256i b) { return _mm256_div_epi32(a, b); }
inline __m256i _mm256_irem_epi32(__m256i a, __m256i b) { return _mm256_rem_epi32(a, b); }
inline __m256i _mm256_udiv_epi32(__m256i a, __m256i b) { return _mm256_div_epu32(a, b); }
inline __m256i _mm256_urem_epi32(__m256i a, __m256i b) { return _mm256_rem_epu32(a, b); }
inline __m128i _mm_idivrem_epi32(__m128i* rem_res, __m128i a, __m128i b) { return _mm_divrem_epi32(rem_res, a, b); }
inline __m128i _mm_udivrem_epi32(__m128i* rem_res, __m128i a, __m128i b) { return _mm_divrem_epu32(rem_res, a, b); }
inline __m256i _mm256_idivrem_epi32(__m256i* rem_res, __m256i a, __m256i b) { return _mm256_divrem_epi32(rem_res, a, b); }
inline __m256i _mm256_udivrem_epi32(__m256i* rem_res, __m256i a, __m256i b) { return _mm256_divrem_epu32(rem_res, a, b); }
inline void _cldemote(const void* p) { _mm_cldemote(p); }

inline void _mm256_storeu2_m128(fat4* hiaddr, fat4* loaddr, __m256 a) {
  do {
    __m256 _a = (a);
    _mm_storeu_ps((loaddr), _mm256_castps256_ps128(_a));
    _mm_storeu_ps((hiaddr), _mm256_extractf128_ps(_a, 0x1));
  } while (0);
}
inline void _mm256_storeu2_m128d(fat8* hiaddr, fat8* loaddr, __m256d a) {
  do {
    __m256d _a = (a);
    _mm_storeu_pd((loaddr), _mm256_castpd256_pd128(_a));
    _mm_storeu_pd((hiaddr), _mm256_extractf128_pd(_a, 0x1));
  } while (0);
}
inline void _mm256_storeu2_m128i(__m128i* hiaddr, __m128i* loaddr, __m256i a) {
  do {
    __m256i _a = (a);
    _mm_storeu_si128((loaddr), _mm256_castsi256_si128(_a));
    _mm_storeu_si128((hiaddr), _mm256_extractf128_si256(_a, 0x1));
  } while (0);
}


#ifdef YW_INTRIN_X64
YW_INTRIN_VOID(void, _xsave64, void*, nat8);
YW_INTRIN_VOID(void, _xsaveopt64, void*, nat8);
YW_INTRIN_VOID(void, _xsavec64, void*, nat8);
YW_INTRIN_VOID(void, _xrstor64, const void*, nat8);
YW_INTRIN_VOID(void, _xsaves64, void*, nat8);
YW_INTRIN_VOID(void, _xrstors64, const void*, nat8);
YW_INTRIN_VOID(void, _fxsave64, void*);
YW_INTRIN_VOID(void, _fxrstor64, const void*);
YW_INTRIN_FUNC(int4, _rdrand64_step, nat8 *);
YW_INTRIN_FUNC(nat4, _readfsbase_u32, void);
YW_INTRIN_FUNC(nat4, _readgsbase_u32, void);
YW_INTRIN_FUNC(nat8, _readfsbase_u64, void);
YW_INTRIN_FUNC(nat8, _readgsbase_u64, void);
YW_INTRIN_VOID(void, _writefsbase_u32, nat4);
YW_INTRIN_VOID(void, _writegsbase_u32, nat4);
YW_INTRIN_VOID(void, _writefsbase_u64, nat8);
YW_INTRIN_VOID(void, _writegsbase_u64, nat8);
YW_INTRIN_FUNC(nat8, _bextr_u64, nat8 src, nat4 start_bit, nat4 len_in_bits);
YW_INTRIN_FUNC(nat8, _bextr2_u64, nat8 src, nat8 start_and_len_in_bits);
YW_INTRIN_FUNC(nat8, _blsi_u64, nat8);
YW_INTRIN_FUNC(nat8, _blsmsk_u64, nat8);
YW_INTRIN_FUNC(nat8, _blsr_u64, nat8);
YW_INTRIN_FUNC(nat8, _bzhi_u64, nat8 src, nat4 index);
YW_INTRIN_FUNC(nat8, _mulx_u64, nat8 src1, nat8 src2, nat8* high_bits);
YW_INTRIN_FUNC(nat8, _pdep_u64, nat8 src, nat8 mask);
YW_INTRIN_FUNC(nat8, _pext_u64, nat8 src, nat8 mask);
YW_INTRIN_FUNC(nat8, _rorx_u64, nat8 src, const nat4 shift_count);
YW_INTRIN_FUNC(int8, _sarx_i64, int8 src, nat4 shift_count);
YW_INTRIN_FUNC(nat8, _shlx_u64, nat8 src, nat4 shift_count);
YW_INTRIN_FUNC(nat8, _shrx_u64, nat8 src, nat4 shift_count);
YW_INTRIN_FUNC(nat8, _lzcnt_u64, nat8);
YW_INTRIN_FUNC(nat8, _tzcnt_u64, nat8);
YW_INTRIN_VOID(void, _Store64_HLERelease, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedExchange64_HLEAcquire, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedExchange64_HLERelease, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedExchangeAdd64_HLEAcquire, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedExchangeAdd64_HLERelease, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedAnd64_HLEAcquire, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedAnd64_HLERelease, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedOr64_HLEAcquire, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedOr64_HLERelease, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedXor64_HLEAcquire, volatile int8*, int8);
YW_INTRIN_FUNC(int8, _InterlockedXor64_HLERelease, volatile int8*, int8);
YW_INTRIN_FUNC(nat1, _interlockedbittestandset64_HLEAcquire, int8*, int8);
YW_INTRIN_FUNC(nat1, _interlockedbittestandset64_HLERelease, int8*, int8);
YW_INTRIN_FUNC(nat1, _interlockedbittestandreset64_HLEAcquire, int8*, int8);
YW_INTRIN_FUNC(nat1, _interlockedbittestandreset64_HLERelease, int8*, int8);
YW_INTRIN_FUNC(int, _rdseed64_step, nat8*);
YW_INTRIN_FUNC(nat1, _addcarryx_u64, nat1 c_in, nat8 src1, nat8 src2, nat8* out);
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi64, __m256i dst, int8 src, const int index);
YW_INTRIN_FUNC(int8, _mm256_extract_epi64, __m256i src, const int index);
YW_INTRIN_VOID(void, _ptwrite64, nat8);
YW_INTRIN_FUNC(nat8, _udiv128, nat8 highdividend, nat8 lowdividend, nat8 divisor, nat8* remainder);
YW_INTRIN_FUNC(int8, _div128, int8 highdividend, int8 lowdividend, int8 divisor, int8* remainder);
YW_INTRIN_VOID(void, _incsspq, nat8);
YW_INTRIN_FUNC(nat8, _rdsspq, void);
YW_INTRIN_VOID(void, _wrssq, nat8, void*);
YW_INTRIN_VOID(void, _wrussq, nat8, void*);
YW_INTRIN_VOID(void, _directstoreu_u64, void*, nat8);
YW_INTRIN_VOID(void, _clui, void);
YW_INTRIN_VOID(void, _stui, void);
YW_INTRIN_FUNC(nat1, _testui, void);
YW_INTRIN_VOID(void, _senduipi, nat8);

inline int8 _mm256_cvtsi256_si64(__m256i a) { return _mm_cvtsi128_si64(_mm256_castsi256_si128(a)); }
#endif

}
