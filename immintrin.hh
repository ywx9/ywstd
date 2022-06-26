// ywstd/immintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

/*******************************************************************************
https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
SSE, SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX, AVX2, FMA, AVX_VNNI, SVML, Other.
Synopsis: #include <immintrin.h>
*******************************************************************************/

#pragma once

#include "../ywstd/wmmintrin.hh"

#ifdef _ywstd_
#include <cmath>
#include <immintrin.h>
#include <intrin.h>
namespace yw::intrin {
using ::__m256;
using ::__m256d;
using ::__m256i;
}
#else
namespace yw::intrin {
union alignas(32) __m256d {
  double m256d_f64[4];
};
union alignas(32) __m256i {
  char m256i_i8[32];
  short m256i_i16[16];
  int m256i_i32[8];
  long long m256i_i64[4];
  unsigned char m256i_u8[32];
  unsigned short m256i_u16[16];
  unsigned int m256i_u32[8];
  unsigned long long m256i_u64[4];
};
} // namespace yw::intrin
#endif

namespace yw::intrin {
using __mmask8 = unsigned char;
using __mmask16 = unsigned short;
using __mmask32 = unsigned int;
using __mmask64 = unsigned long long;
#ifdef YW_INTRIN_DISABLE
YW_INTRIN_FUNC(void, _allow_cpu_features, unsigned long long a)
YW_INTRIN_FUNC(int, _bit_scan_forward, int a)
YW_INTRIN_FUNC(int, _bit_scan_reverse, int a)
YW_INTRIN_FUNC(__m256i, _mm_broadcastsi128_si256, __m128i a)
YW_INTRIN_FUNC(int, _bswap, int a)
YW_INTRIN_FUNC(long long, _bswap64, long long a)
YW_INTRIN_FUNC(unsigned long, _castf32_u32, float a)
YW_INTRIN_FUNC(unsigned long long, _castf64_u64, double a)
YW_INTRIN_FUNC(float, _castu32_f32, unsigned long a)
YW_INTRIN_FUNC(double, _castu64_f64, unsigned long long a)
YW_INTRIN_FUNC(long, _get_ssp, void)
YW_INTRIN_FUNC(long long, _get_ssp, void)
YW_INTRIN_FUNC(void, _inc_ssp, unsigned int a)
YW_INTRIN_FUNC(int, _may_i_use_cpu_feature, unsigned long long a)
YW_INTRIN_FUNC(int, _popcnt32, int a)
YW_INTRIN_FUNC(int, _popcnt64, long long a)
YW_INTRIN_FUNC(long long, _rdpmc, int a)
YW_INTRIN_FUNC(long, _rdsspd_i32, void)
YW_INTRIN_FUNC(long long, _rdsspq_i64, void)
YW_INTRIN_FUNC(long long, _rdtsc, void)
YW_INTRIN_FUNC(unsigned short, _rotwl, unsigned short a, int shift)
YW_INTRIN_FUNC(unsigned short, _rotwr, unsigned short a, int shift)
YW_INTRIN_FUNC(int, _mm_tzcnt_32, unsigned int a)
YW_INTRIN_FUNC(long long, _mm_tzcnt_64, unsigned long long a)
YW_INTRIN_FUNC(unsigned short, _tzcnt_u16, unsigned short a)
YW_INTRIN_FUNC(void, _wbinvd, void)
#endif
YW_INTRIN_FUNC(__m256i, _mm256_abs_epi16, __m256i a)
YW_INTRIN_FUNC(__m256i, _mm256_abs_epi32, __m256i a)
YW_INTRIN_FUNC(__m256i, _mm256_abs_epi8, __m256i a)
YW_INTRIN_FUNC(__m256i, _mm256_add_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_add_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_add_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_add_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_add_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_add_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(unsigned char, _addcarry_u32, unsigned char c_in, unsigned int a, unsigned int b, unsigned int* out)
YW_INTRIN_FUNC(unsigned char, _addcarry_u64, unsigned char c_in, unsigned long long a, unsigned long long b, unsigned long long* out)
YW_INTRIN_FUNC(unsigned char, _addcarryx_u32, unsigned char c_in, unsigned int a, unsigned int b, unsigned int* out)
YW_INTRIN_FUNC(unsigned char, _addcarryx_u64, unsigned char c_in, unsigned long long a, unsigned long long b, unsigned long long* out)
YW_INTRIN_FUNC(__m256i, _mm256_adds_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_adds_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_adds_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_adds_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_addsub_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_addsub_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_aesdec_epi128, __m256i a, __m256i RoundKey)
YW_INTRIN_FUNC(unsigned char, _mm_aesdec128kl_u8, __m128i* __odata, __m128i __idata, const void* __h)
YW_INTRIN_FUNC(unsigned char, _mm_aesdec256kl_u8, __m128i* __odata, __m128i __idata, const void* __h)
YW_INTRIN_FUNC(__m256i, _mm256_aesdeclast_epi128, __m256i a, __m256i RoundKey)
YW_INTRIN_FUNC(unsigned char, _mm_aesdecwide128kl_u8, __m128i* __odata, const __m128i* __idata, const void* __h)
YW_INTRIN_FUNC(unsigned char, _mm_aesdecwide256kl_u8, __m128i* __odata, const __m128i* __idata, const void* __h)
YW_INTRIN_FUNC(__m256i, _mm256_aesenc_epi128, __m256i a, __m256i RoundKey)
YW_INTRIN_FUNC(unsigned char, _mm_aesenc128kl_u8, __m128i* __odata, __m128i __idata, const void* __h)
YW_INTRIN_FUNC(unsigned char, _mm_aesenc256kl_u8, __m128i* __odata, __m128i __idata, const void* __h)
YW_INTRIN_FUNC(__m256i, _mm256_aesenclast_epi128, __m256i a, __m256i RoundKey)
YW_INTRIN_FUNC(unsigned char, _mm_aesencwide128kl_u8, __m128i* __odata, const __m128i* __idata, const void* __h)
YW_INTRIN_FUNC(unsigned char, _mm_aesencwide256kl_u8, __m128i* __odata, const __m128i* __idata, const void* __h)
#ifdef _mm256_alignr_epi8
#undef _mm256_alignr_epi8
#define YW_INTRIN_MM_ALIGNR_EPI8
template<int Imm8> __m256i _mm256_alignr_epi8(__m256i a, __m256i b) noexcept {
  return (__m256i)__builtin_ia32_palignr256((__v32qi)a, (__v32qi)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256i, _mm256_alignr_epi8, __m256i a, __m256i b, const int imm8)
#endif
YW_INTRIN_FUNC(__m256d, _mm256_and_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_and_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_and_si256, __m256i a, __m256i b)
// YW_INTRIN_FUNC(unsigned int, _andn_u32, unsigned int a, unsigned int b)
// YW_INTRIN_FUNC(unsigned long long, _andn_u64, unsigned long long a, unsigned long long b)
YW_INTRIN_FUNC(__m256d, _mm256_andnot_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_andnot_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_andnot_si256, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_avg_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_avg_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(unsigned int, _bextr_u32, unsigned int a, unsigned int start, unsigned int len)
YW_INTRIN_FUNC(unsigned long long, _bextr_u64, unsigned long long a, unsigned int start, unsigned int len)
YW_INTRIN_FUNC(unsigned int, _bextr2_u32, unsigned int a, unsigned int control)
YW_INTRIN_FUNC(unsigned long long, _bextr2_u64, unsigned long long a, unsigned long long control)
YW_INTRIN_FUNC(unsigned char, _BitScanForward, unsigned long* index, unsigned long a)
YW_INTRIN_FUNC(unsigned char, _BitScanForward64, unsigned long* index, unsigned long long a)
YW_INTRIN_FUNC(unsigned char, _BitScanReverse, unsigned long* index, unsigned long a)
YW_INTRIN_FUNC(unsigned char, _BitScanReverse64, unsigned long* index, unsigned long long a)
YW_INTRIN_FUNC(unsigned char, _bittest, long* a, long b)
YW_INTRIN_FUNC(unsigned char, _bittest64, long long* a, long long b)
YW_INTRIN_FUNC(unsigned char, _bittestandcomplement, long* a, long b)
YW_INTRIN_FUNC(unsigned char, _bittestandcomplement64, long long* a, long long b)
YW_INTRIN_FUNC(unsigned char, _bittestandreset, long* a, long b)
YW_INTRIN_FUNC(unsigned char, _bittestandreset64, long long* a, long long b)
YW_INTRIN_FUNC(unsigned char, _bittestandset, long* a, long b)
YW_INTRIN_FUNC(unsigned char, _bittestandset64, long long* a, long long b)
#ifdef _mm256_blend_epi16
#undef _mm256_blend_epi16
#define YW_INTRIN_MM256_BLEND_EPI16_IS_TEMPLATE
template<int Imm8> __m256i _mm256_blend_epi16(__m256i a, __m256i b) noexcept {
  return (__m256i)__builtin_ia32_pblendw256((__v16hi)a, (__v16hi)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256i, _mm256_blend_epi16, __m256i a, __m256i b, const int imm8)
#endif
#ifdef _mm_blend_epi32
#undef _mm_blend_epi32
#define YW_INTRIN_MM_BLEND_EPI32_IS_TEMPLATE
template<int Imm8> __m128i _mm_blend_epi32(__m128i a, __m128i b) noexcept {
  return (__m128i)__builtin_ia32_pblendd128((__v4si)a, (__v4si)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm_blend_epi32, __m128i a, __m128i b, const int imm8)
#endif
#ifdef _mm256_blend_epi32
#undef _mm256_blend_epi32
#define YW_INTRIN_MM256_BLEND_EPI332_IS_TEMPLATE
template<int Imm8> __m256i _mm256_blend_epi32(__m256i a, __m256i b) noexcept {
  return (__m256i)__builtin_ia32_pblendd256((__v8si)a, (__v8si)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256i, _mm256_blend_epi32, __m256i a, __m256i b, const int imm8)
#endif
#ifdef _mm256_blend_pd
#undef _mm256_blend_pd
#define YW_INTRIN_MM256_BLEND_PD_IS_TEMPLATE
template<int Imm8> __m256d _mm256_blend_pd(__m256d a, __m256d b) noexcept {
  return (__m256d)__builtin_ia32_blendpd256((__v4df)a, (__v4df)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256d, _mm256_blend_pd, __m256d a, __m256d b, const int imm8)
#endif
#ifdef _mm256_blend_ps
#undef _mm256_blend_ps
#define YW_INTRIN_MM256_BLEND_PS_IS_TEMPLATE
template<int Imm8> __m256 _mm256_blend_ps(__m256 a, __m256 b) noexcept {
  return (__m256)__builtin_ia32_blendps256((__v8sf)a, (__v8sf)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256, _mm256_blend_ps, __m256 a, __m256 b, const int imm8)
#endif
YW_INTRIN_FUNC(__m256i, _mm256_blendv_epi8, __m256i a, __m256i b, __m256i mask)
YW_INTRIN_FUNC(__m256d, _mm256_blendv_pd, __m256d a, __m256d b, __m256d mask)
YW_INTRIN_FUNC(__m256, _mm256_blendv_ps, __m256 a, __m256 b, __m256 mask)
// YW_INTRIN_FUNC(unsigned int, _blsi_u32, unsigned int a)
// YW_INTRIN_FUNC(unsigned long long, _blsi_u64, unsigned long long a)
// YW_INTRIN_FUNC(unsigned int, _blsmsk_u32, unsigned int a)
// YW_INTRIN_FUNC(unsigned long long, _blsmsk_u64, unsigned long long a)
// YW_INTRIN_FUNC(unsigned int, _blsr_u32, unsigned int a)
// YW_INTRIN_FUNC(unsigned long long, _blsr_u64, unsigned long long a)
// YW_INTRIN_FUNC(void, _bnd_chk_ptr_bounds, const void* q, size_t size)
// YW_INTRIN_FUNC(void, _bnd_chk_ptr_lbounds, const void* q)
// YW_INTRIN_FUNC(void, _bnd_chk_ptr_ubounds, const void* q)
// YW_INTRIN_FUNC(void*, _bnd_copy_ptr_bounds, const void* q, const void* r)
// YW_INTRIN_FUNC(const void*, _bnd_get_ptr_lbound, const void* q)
// YW_INTRIN_FUNC(const void*, _bnd_get_ptr_ubound, const void* q)
// YW_INTRIN_FUNC(void*, _bnd_init_ptr_bounds, const void* q)
// YW_INTRIN_FUNC(void*, _bnd_narrow_ptr_bounds, const void* q, const void* r, size_t size)
// YW_INTRIN_FUNC(void*, _bnd_set_ptr_bounds, const void* srcmem, size_t size)
// YW_INTRIN_FUNC(void, _bnd_store_ptr_bounds, const void** ptr_addr, const void* ptr_val)
YW_INTRIN_FUNC(__m256d, _mm256_broadcast_pd, __m128d const* mem_addr)
YW_INTRIN_FUNC(__m256, _mm256_broadcast_ps, __m128 const* mem_addr)
YW_INTRIN_FUNC(__m256d, _mm256_broadcast_sd, double const* mem_addr)
YW_INTRIN_FUNC(__m128, _mm_broadcast_ss, float const* mem_addr)
YW_INTRIN_FUNC(__m256, _mm256_broadcast_ss, float const* mem_addr)
YW_INTRIN_FUNC(__m128i, _mm_broadcastb_epi8, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_broadcastb_epi8, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_broadcastd_epi32, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_broadcastd_epi32, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm_broadcastq_epi64, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_broadcastq_epi64, __m128i a)
YW_INTRIN_FUNC(__m128d, _mm_broadcastsd_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_broadcastsd_pd, __m128d a)
YW_INTRIN_FUNC(__m256i, _mm256_broadcastsi128_si256, __m128i a)
YW_INTRIN_FUNC(__m128, _mm_broadcastss_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_broadcastss_ps, __m128 a)
YW_INTRIN_FUNC(__m128i, _mm_broadcastw_epi16, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_broadcastw_epi16, __m128i a)
#ifdef _mm256_bslli_epi128
#undef _mm256_bslli_epi128
#define YW_INTRIN_MM256_BSLLI_EPI128_IS_TEMPLATE
template<int Imm8> __m256i _mm256_bslli_epi128(__m256i a) noexcept {
  return (__m256i)__builtin_ia32_pslldqi256_byteshift((__v4di)a, Imm8);
}
#else
YW_INTRIN_FUNC(__m256i, _mm256_bslli_epi128, __m256i a, const int imm8)
#endif
#ifdef _mm256_bsrli_epi128
#undef _mm256_bsrli_epi128
#define YW_INTRIN_MM256_BSRLI_EPI128_IS_TEMPLATE
template<int Imm8> __m256i _mm256_bsrli_epi128(__m256i a) noexcept {
  return (__m256i)__builtin_ia32_psrldqi256_byteshift((__v4di)a, Imm8);
}
#else
YW_INTRIN_FUNC(__m256i, _mm256_bsrli_epi128, __m256i a, const int imm8)
#endif
// YW_INTRIN_FUNC(unsigned int, _bzhi_u32, unsigned int a, unsigned int index)
// YW_INTRIN_FUNC(unsigned long long, _bzhi_u64, unsigned long long a, unsigned int index)
YW_INTRIN_FUNC(__m256, _mm256_castpd_ps, __m256d a)
YW_INTRIN_FUNC(__m256i, _mm256_castpd_si256, __m256d a)
YW_INTRIN_FUNC(__m256d, _mm256_castpd128_pd256, __m128d a)
YW_INTRIN_FUNC(__m128d, _mm256_castpd256_pd128, __m256d a)
YW_INTRIN_FUNC(__m256d, _mm256_castps_pd, __m256 a)
YW_INTRIN_FUNC(__m256i, _mm256_castps_si256, __m256 a)
YW_INTRIN_FUNC(__m256, _mm256_castps128_ps256, __m128 a)
YW_INTRIN_FUNC(__m128, _mm256_castps256_ps128, __m256 a)
YW_INTRIN_FUNC(__m256i, _mm256_castsi128_si256, __m128i a)
YW_INTRIN_FUNC(__m256d, _mm256_castsi256_pd, __m256i a)
YW_INTRIN_FUNC(__m256, _mm256_castsi256_ps, __m256i a)
YW_INTRIN_FUNC(__m128i, _mm256_castsi256_si128, __m256i a)
#ifdef _mm256_ceil_pd
#undef _mm256_ceil_pd
inline __m256d _mm256_ceil_pd(__m256d a) noexcept {
  return _mm256_round_pd(a, 2);
}
#else
YW_INTRIN_FUNC(__m256d, _mm256_ceil_pd, __m256d a)
#endif
#ifdef _mm256_ceil_ps
#undef _mm256_ceil_ps
inline __m256 _mm256_ceil_ps(__m256 a) noexcept { return _mm256_round_ps(a, 2); }
#else
YW_INTRIN_FUNC(__m256, _mm256_ceil_ps, __m256 a)
#endif
#ifdef _mm_cldemote
#undef _mm_cldemote
inline void _mm_cldemote(const void* p) noexcept { return ::_cldemote(p); }
#else
YW_INTRIN_FUNC(void, _mm_cldemote, const void* p)
#endif
YW_INTRIN_FUNC(void, _mm_clflushopt, const void* p)
YW_INTRIN_FUNC(void, _clrssbsy, void* p)
YW_INTRIN_FUNC(void, _clui, void)
YW_INTRIN_FUNC(void, _mm_clwb, const void* p)
#ifdef _mm_cmp_pd
#undef _mm_cmp_pd
#define YW_INTRIN_MM_CMP_PD_IS_TEMPLATE
template<int Imm8> __m128d _mm_cmp_pd(__m128d a, __m128d b) noexcept {
  return (__m128d)__builtin_ia32_cmppd((__v2df)a, (__v2df)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m128d, _mm_cmp_pd, __m128d a, __m128d b, const int imm8)
#endif
#ifdef _mm256_cmp_pd
#undef _mm256_cmp_pd
#define YW_INTRIN_MM256_CMP_PD_IS_TEMPLATE
template<int Imm8> __m256d _mm256_cmp_pd(__m256d a, __m256d b) noexcept {
  return (__m256d)__builtin_ia32_cmppd256((__v4df)a, (__v4df)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256d, _mm256_cmp_pd, __m256d a, __m256d b, const int imm8)
#endif
#ifdef _mm_cmp_ps
#undef _mm_cmp_ps
#define YW_INTRIN_MM_CMP_PS_IS_TEMPLATE
template<int Imm8> __m128 _mm_cmp_ps(__m128 a, __m128 b) noexcept {
  return (__m128)__builtin_ia32_cmpps((__v4sf)a, (__v4sf)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m128, _mm_cmp_ps, __m128 a, __m128 b, const int imm8)
#endif
#ifdef _mm256_cmp_ps
#undef _mm256_cmp_ps
#define YW_INTRIN_MM256_CMP_PS_IS_TEMPLATE
template<int Imm8> __m256 _mm256_cmp_ps(__m256 a, __m256 b) noexcept {
  return (__m256)__builtin_ia32_cmpps256((__v8sf)a, (__v8sf)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256, _mm256_cmp_ps, __m256 a, __m256 b, const int imm8)
#endif
#ifdef _mm_cmp_sd
#undef _mm_cmp_sd
#define YW_INTRIN_MM_CMP_SD_IS_TEMPLATE
template<int Imm8> __m128d _mm_cmp_sd(__m128d a, __m128d b) noexcept {
  return (__m128d)__builtin_ia32_cmpsd((__v2df)a, (__v2df)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m128d, _mm_cmp_sd, __m128d a, __m128d b, const int imm8)
#endif
#ifdef _mm_cmp_ss
#undef _mm_cmp_ss
#define YW_INTRIN_MM_CMP_SS_IS_TEMPLATE
template<int Imm8> __m128 _mm_cmp_ss(__m128 a, __m128 b) noexcept {
  return (__m128)__builtin_ia32_cmpss((__v4sf)a, (__v4sf)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m128, _mm_cmp_ss, __m128 a, __m128 b, const int imm8)
#endif
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cmpeq_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cmpgt_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi16_epi32, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi16_epi64, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi32_epi64, __m128i a)
YW_INTRIN_FUNC(__m256d, _mm256_cvtepi32_pd, __m128i a)
YW_INTRIN_FUNC(__m256, _mm256_cvtepi32_ps, __m256i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi8_epi16, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi8_epi32, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepi8_epi64, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu16_epi32, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu16_epi64, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu32_epi64, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu8_epi16, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu8_epi32, __m128i a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtepu8_epi64, __m128i a)
YW_INTRIN_FUNC(__m128i, _mm256_cvtpd_epi32, __m256d a)
YW_INTRIN_FUNC(__m128, _mm256_cvtpd_ps, __m256d a)
YW_INTRIN_FUNC(__m256i, _mm256_cvtps_epi32, __m256 a)
YW_INTRIN_FUNC(__m256d, _mm256_cvtps_pd, __m128 a)
#ifdef _mm256_cvtsd_f64
#undef _mm256_cvtsd_f64
inline double _mm256_cvtsd_f64(__m256d a) noexcept { return _mm_cvtsd_f64(_mm256_castpd256_pd128(a)); }
#else
YW_INTRIN_FUNC(double, _mm256_cvtsd_f64, __m256d a)
#endif
#ifdef _mm256_cvtsi256_si32
#undef _mm256_cvtsi256_si32
inline int _mm256_cvtsi256_si32(__m256i a) noexcept { return _mm_cvtsi128_si32(_mm256_castsi256_si128(a)); }
#else
YW_INTRIN_FUNC(int, _mm256_cvtsi256_si32, __m256i a)
#endif
#ifdef _mm256_cvtss_f32
#undef _mm256_cvtss_f32
inline float _mm256_cvtss_f32(__m256 a) noexcept { return _mm_cvtss_f32(_mm256_castps256_ps128(a)); }
#else
YW_INTRIN_FUNC(float, _mm256_cvtss_f32, __m256 a)
#endif
YW_INTRIN_FUNC(__m128i, _mm256_cvttpd_epi32, __m256d a)
YW_INTRIN_FUNC(__m256i, _mm256_cvttps_epi32, __m256 a)
YW_INTRIN_FUNC(void, _directstoreu_u32, void* dst, unsigned int val)
YW_INTRIN_FUNC(void, _directstoreu_u64, void* dst, unsigned long long val)
YW_INTRIN_FUNC(__m256d, _mm256_div_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_div_ps, __m256 a, __m256 b)
#ifdef _mm256_dp_ps
#undef _mm256_dp_ps
#define YW_INTRIN_MM256_DP_PS_IS_TEMPLATE
template<int Imm8> __m256 _mm256_dp_ps(__m256 a, __m256 b) noexcept {
  return (__m256)__builtin_ia32_dpps256((__v8sf)a, (__v8sf)b, Imm8);
}
#else
YW_INTRIN_FUNC(__m256, _mm256_dp_ps, __m256 a, __m256 b, const int imm8)
#endif
YW_INTRIN_FUNC(unsigned int, _encls_u32, const int a, size_t* __data)
YW_INTRIN_FUNC(unsigned int, _enclu_u32, const int a, size_t* __data)
YW_INTRIN_FUNC(unsigned int, _enclv_u32, const int a, size_t* __data)
YW_INTRIN_FUNC(unsigned int, _mm_encodekey128_u32, unsigned int __htype, __m128i __key, void* __h)
YW_INTRIN_FUNC(unsigned int, _mm_encodekey256_u32, unsigned int __htype, __m128i __key_lo, __m128i __key_hi, void* __h)
YW_INTRIN_FUNC(int, _enqcmd, void* __dst, const void* __src)
YW_INTRIN_FUNC(int, _enqcmds, void* __dst, const void* __src)
#ifdef _mm256_extract_epi16
#undef _mm256_extract_epi16
#define YW_INTRIN_MM256_EXTRACT_EPI16_IS_TEMPLATE
template<int Index> int _mm256_extract_epi16(__m256i a) noexcept {
  return (int)(unsigned short)__builtin_ia32_vec_ext_v16hi((__v16hi)a, Index);
}
#else
YW_INTRIN_FUNC(int, _mm256_extract_epi16, __m256i a, const int index)
#endif
#ifdef _mm256_extract_epi32
#undef _mm256_extract_epi32
#define YW_INTRIN_MM256_EXTRACT_EPI32_IS_TEMPLATE
template<int Index> long _mm256_extract_epi32(__m256i a) noexcept {
  return (int)__builtin_ia32_vec_ext_v8si((__v8si)a, Index);
}
#else
YW_INTRIN_FUNC(long, _mm256_extract_epi32, __m256i a, const int index)
#endif
#ifdef _mm256_extract_epi64
#undef _mm256_extract_epi64
#define YW_INTRIN_MM256_EXTRACT_EPI64_IS_TEMPLATE
template<int Index> long long _mm256_extract_epi64(__m256i a) noexcept {
  return (long long)__builtin_ia32_vec_ext_v4di((__v4di)a, Index);
}
#else
YW_INTRIN_FUNC(long long, _mm256_extract_epi64, __m256i a, const int index)
#endif
#ifdef _mm256_extract_epi8
#undef _mm256_extract_epi8
#define YW_INTRIN_MM256_EXTRACT_EPI8_IS_TEMPLATE
template<int Index> int _mm256_extract_epi8(__m256i a) noexcept {
  return (int)(unsigned char)__builtin_ia32_vec_ext_v32qi((__v32qi)a, Index);
}
#else
YW_INTRIN_FUNC(int, _mm256_extract_epi8, __m256i a, const int index)
#endif
#ifdef _mm256_extractf128_pd
#undef _mm256_extractf128_pd
#define YW_INTRIN_MM256_EXTRACTF128_PD_IS_TEMPLATE
template<int Imm8> __m128d _mm256_extractf128_pd(__m256d a) noexcept {
  return (__m128d)__builtin_ia32_vextractf128_pd256((__v4df)a, Imm8);
}
#else
YW_INTRIN_FUNC(__m128d, _mm256_extractf128_pd, __m256d a, const int imm8)
#endif
#ifdef _mm256_extractf128_ps
#undef _mm256_extractf128_ps
#define YW_INTRIN_MM256_EXTRACTF128_PS_IS_TEMPLATE
template<int Imm8> __m128 _mm256_extractf128_ps(__m256 a) noexcept {
  return (__m128)__builtin_ia32_vextractf128_ps256((__v8sf)a, Imm8);
}
#else
YW_INTRIN_FUNC(__m128, _mm256_extractf128_ps, __m256 a, const int imm8)
#endif
#ifdef _mm256_extractf128_si256
#undef _mm256_extractf128_si256
#define YW_INTRIN_MM256_EXTRACTF128_SI256_IS_TEMPLATE
template<int Imm8> __m128i _mm256_extractf128_si256(__m256i a) noexcept {
  return (__m128i)__builtin_ia32_vextractf128_si256((__v8si)a, Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm256_extractf128_si256, __m256i a, const int imm8)
#endif
#ifdef _mm256_extracti128_si256
#undef _mm256_extracti128_si256
#define YW_INTRIN_MM256_EXTRACTF128_SI256_IS_TEMPLATE
template<int Imm8> __m128i _mm256_extracti128_si256(__m256i a) noexcept {
  return (__m128i)__builtin_ia32_extract128i256((__v4di)a, Imm8);
}
#else
YW_INTRIN_FUNC(__m128i, _mm256_extracti128_si256, __m256i a, const int imm8)
#endif
#ifdef _mm256_floor_pd
#undef _mm256_floor_pd
inline __m256d _mm256_floor_pd(__m256d a) noexcept { return _mm256_round_pd(a, 1); }
#else
YW_INTRIN_FUNC(__m256d, _mm256_floor_pd, __m256d a)
#endif
#ifdef _mm256_floor_ps
#undef _mm256_floor_ps
inline __m256 _mm256_floor_ps(__m256 a) noexcept { return _mm256_round_ps(a, 1); }
#else
YW_INTRIN_FUNC(__m256, _mm256_floor_ps, __m256 a)
#endif
YW_INTRIN_FUNC(__m128d, _mm_fmadd_pd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m256d, _mm256_fmadd_pd, __m256d a, __m256d b, __m256d c)
YW_INTRIN_FUNC(__m128, _mm_fmadd_ps, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m256, _mm256_fmadd_ps, __m256 a, __m256 b, __m256 c)
YW_INTRIN_FUNC(__m128d, _mm_fmadd_sd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m128, _mm_fmadd_ss, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m128d, _mm_fmaddsub_pd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m256d, _mm256_fmaddsub_pd, __m256d a, __m256d b, __m256d c)
YW_INTRIN_FUNC(__m128, _mm_fmaddsub_ps, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m256, _mm256_fmaddsub_ps, __m256 a, __m256 b, __m256 c)
YW_INTRIN_FUNC(__m128d, _mm_fmsub_pd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m256d, _mm256_fmsub_pd, __m256d a, __m256d b, __m256d c)
YW_INTRIN_FUNC(__m128, _mm_fmsub_ps, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m256, _mm256_fmsub_ps, __m256 a, __m256 b, __m256 c)
YW_INTRIN_FUNC(__m128d, _mm_fmsub_sd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m128, _mm_fmsub_ss, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m128d, _mm_fmsubadd_pd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m256d, _mm256_fmsubadd_pd, __m256d a, __m256d b, __m256d c)
YW_INTRIN_FUNC(__m128, _mm_fmsubadd_ps, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m256, _mm256_fmsubadd_ps, __m256 a, __m256 b, __m256 c)
YW_INTRIN_FUNC(__m128d, _mm_fnmadd_pd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m256d, _mm256_fnmadd_pd, __m256d a, __m256d b, __m256d c)
YW_INTRIN_FUNC(__m128, _mm_fnmadd_ps, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m256, _mm256_fnmadd_ps, __m256 a, __m256 b, __m256 c)
YW_INTRIN_FUNC(__m128d, _mm_fnmadd_sd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m128, _mm_fnmadd_ss, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m128d, _mm_fnmsub_pd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m256d, _mm256_fnmsub_pd, __m256d a, __m256d b, __m256d c)
YW_INTRIN_FUNC(__m128, _mm_fnmsub_ps, __m128 a, __m128 b, __m128 c)
YW_INTRIN_FUNC(__m256, _mm256_fnmsub_ps, __m256 a, __m256 b, __m256 c)
YW_INTRIN_FUNC(__m128d, _mm_fnmsub_sd, __m128d a, __m128d b, __m128d c)
YW_INTRIN_FUNC(__m128, _mm_fnmsub_ss, __m128 a, __m128 b, __m128 c)
#ifdef _mm_free
#undef _mm_free
inline void _mm_free(void* mem_addr) noexcept { _aligned_free(mem_addr); }
#else
YW_INTRIN_FUNC(void, _mm_free, void* mem_addr)
#endif
YW_INTRIN_FUNC(void, _fxrstor, void* mem_addr)
YW_INTRIN_FUNC(void, _fxrstor64, void* mem_addr)
YW_INTRIN_FUNC(void, _fxsave, void* mem_addr)
YW_INTRIN_FUNC(void, _fxsave64, void* mem_addr)
#ifdef _MM_GET_EXCEPTION_MASK
#undef _MM_GET_EXCEPTION_MASK
inline unsigned int _MM_GET_EXCEPTION_MASK() noexcept { return _mm_getcsr() & 0x1f80; }
#else
YW_INTRIN_FUNC(unsigned int, _MM_GET_EXCEPTION_MASK)
#endif
#ifdef _MM_GET_EXCEPTION_STATE
#undef _MM_GET_EXCEPTION_STATE
inline unsigned int _MM_GET_EXCEPTION_STATE() noexcept { return _mm_getcsr() & 0x003f; }
#else
YW_INTRIN_FUNC(unsigned int, _MM_GET_EXCEPTION_STATE)
#endif
#ifdef _MM_GET_FLUSH_ZERO_MODE
#undef _MM_GET_FLUSH_ZERO_MODE
inline unsigned int _MM_GET_FLUSH_ZERO_MODE() noexcept { return _mm_getcsr() & 0x8000; }
#else
YW_INTRIN_FUNC(unsigned int, _MM_GET_FLUSH_ZERO_MODE)
#endif
#ifdef _MM_GET_ROUNDING_MODE
#undef _MM_GET_ROUNDING_MODE
inline unsigned int _MM_GET_ROUNDING_MODE() noexcept { return _mm_getcsr() & 0x6000; }
#else
YW_INTRIN_FUNC(unsigned int, _MM_GET_ROUNDING_MODE)
#endif
YW_INTRIN_FUNC(unsigned int, _mm_getcsr, void)
YW_INTRIN_FUNC(__m128i, _mm_gf2p8affine_epi64_epi8, __m128i x, __m128i A, int b)
YW_INTRIN_FUNC(__m128i, _mm_mask_gf2p8affine_epi64_epi8, __m128i src, __mmask16 k, __m128i x, __m128i A, int b)
YW_INTRIN_FUNC(__m128i, _mm_maskz_gf2p8affine_epi64_epi8, __mmask16 k, __m128i x, __m128i A, int b)
YW_INTRIN_FUNC(__m256i, _mm256_gf2p8affine_epi64_epi8, __m256i x, __m256i A, int b)
YW_INTRIN_FUNC(__m256i, _mm256_mask_gf2p8affine_epi64_epi8, __m256i src, __mmask32 k, __m256i x, __m256i A, int b)
YW_INTRIN_FUNC(__m256i, _mm256_maskz_gf2p8affine_epi64_epi8, __mmask32 k, __m256i x, __m256i A, int b)
YW_INTRIN_FUNC(__m128i, _mm_gf2p8affineinv_epi64_epi8, __m128i x, __m128i A, int b)
YW_INTRIN_FUNC(__m128i, _mm_mask_gf2p8affineinv_epi64_epi8, __m128i src, __mmask16 k, __m128i x, __m128i A, int b)
YW_INTRIN_FUNC(__m128i, _mm_maskz_gf2p8affineinv_epi64_epi8, __mmask16 k, __m128i x, __m128i A, int b)
YW_INTRIN_FUNC(__m256i, _mm256_gf2p8affineinv_epi64_epi8, __m256i x, __m256i A, int b)
YW_INTRIN_FUNC(__m256i, _mm256_mask_gf2p8affineinv_epi64_epi8, __m256i src, __mmask32 k, __m256i x, __m256i A, int b)
YW_INTRIN_FUNC(__m256i, _mm256_maskz_gf2p8affineinv_epi64_epi8, __mmask32 k, __m256i x, __m256i A, int b)
YW_INTRIN_FUNC(__m128i, _mm_gf2p8mul_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_mask_gf2p8mul_epi8, __m128i src, __mmask16 k, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_maskz_gf2p8mul_epi8, __mmask16 k, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_gf2p8mul_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_mask_gf2p8mul_epi8, __m256i src, __mmask32 k, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_maskz_gf2p8mul_epi8, __mmask32 k, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_hadd_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_hadd_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_hadd_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_hadd_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_hadds_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(void, _hreset, int __eax)
YW_INTRIN_FUNC(__m256i, _mm256_hsub_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_hsub_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_hsub_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_hsub_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_hsubs_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128d, _mm_hypot_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m256d, _mm256_hypot_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m128, _mm_hypot_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m256, _mm256_hypot_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m128i, _mm_i32gather_epi32, int const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_mask_i32gather_epi32, __m128i src, int const* base_addr, __m128i vindex, __m128i mask, const int scale)
YW_INTRIN_FUNC(__m256i, _mm256_i32gather_epi32, int const* base_addr, __m256i vindex, const int scale)
YW_INTRIN_FUNC(__m256i, _mm256_mask_i32gather_epi32, __m256i src, int const* base_addr, __m256i vindex, __m256i mask, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_i32gather_epi64, long long const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_mask_i32gather_epi64, __m128i src, long long const* base_addr, __m128i vindex, __m128i mask, const int scale)
YW_INTRIN_FUNC(__m256i, _mm256_i32gather_epi64, long long const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m256i, _mm256_mask_i32gather_epi64, __m256i src, long long const* base_addr, __m128i vindex, __m256i mask, const int scale)
YW_INTRIN_FUNC(__m128d, _mm_i32gather_pd, double const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128d, _mm_mask_i32gather_pd, __m128d src, double const* base_addr, __m128i vindex, __m128d mask, const int scale)
YW_INTRIN_FUNC(__m256d, _mm256_i32gather_pd, double const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m256d, _mm256_mask_i32gather_pd, __m256d src, double const* base_addr, __m128i vindex, __m256d mask, const int scale)
YW_INTRIN_FUNC(__m128, _mm_i32gather_ps, float const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128, _mm_mask_i32gather_ps, __m128 src, float const* base_addr, __m128i vindex, __m128 mask, const int scale)
YW_INTRIN_FUNC(__m256, _mm256_i32gather_ps, float const* base_addr, __m256i vindex, const int scale)
YW_INTRIN_FUNC(__m256, _mm256_mask_i32gather_ps, __m256 src, float const* base_addr, __m256i vindex, __m256 mask, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_i64gather_epi32, int const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_mask_i64gather_epi32, __m128i src, int const* base_addr, __m128i vindex, __m128i mask, const int scale)
YW_INTRIN_FUNC(__m128i, _mm256_i64gather_epi32, int const* base_addr, __m256i vindex, const int scale)
YW_INTRIN_FUNC(__m128i, _mm256_mask_i64gather_epi32, __m128i src, int const* base_addr, __m256i vindex, __m128i mask, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_i64gather_epi64, long long const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_mask_i64gather_epi64, __m128i src, long long const* base_addr, __m128i vindex, __m128i mask, const int scale)
YW_INTRIN_FUNC(__m256i, _mm256_i64gather_epi64, long long const* base_addr, __m256i vindex, const int scale)
YW_INTRIN_FUNC(__m256i, _mm256_mask_i64gather_epi64, __m256i src, long long const* base_addr, __m256i vindex, __m256i mask, const int scale)
YW_INTRIN_FUNC(__m128d, _mm_i64gather_pd, double const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128d, _mm_mask_i64gather_pd, __m128d src, double const* base_addr, __m128i vindex, __m128d mask, const int scale)
YW_INTRIN_FUNC(__m256d, _mm256_i64gather_pd, double const* base_addr, __m256i vindex, const int scale)
YW_INTRIN_FUNC(__m256d, _mm256_mask_i64gather_pd, __m256d src, double const* base_addr, __m256i vindex, __m256d mask, const int scale)
YW_INTRIN_FUNC(__m128, _mm_i64gather_ps, float const* base_addr, __m128i vindex, const int scale)
YW_INTRIN_FUNC(__m128, _mm_mask_i64gather_ps, __m128 src, float const* base_addr, __m128i vindex, __m128 mask, const int scale)
YW_INTRIN_FUNC(__m128, _mm256_i64gather_ps, float const* base_addr, __m256i vindex, const int scale)
YW_INTRIN_FUNC(__m128, _mm256_mask_i64gather_ps, __m128 src, float const* base_addr, __m256i vindex, __m128 mask, const int scale)
YW_INTRIN_FUNC(__m128i, _mm_idiv_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_idiv_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_idivrem_epi32, __m128i* mem_addr, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_idivrem_epi32, __m256i* mem_addr, __m256i a, __m256i b)
YW_INTRIN_FUNC(void, _incsspd, int a)
YW_INTRIN_FUNC(void, _incsspq, int a)
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi16, __m256i a, short i, const int index)
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi32, __m256i a, long i, const int index)
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi64, __m256i a, long long i, const int index)
YW_INTRIN_FUNC(__m256i, _mm256_insert_epi8, __m256i a, char i, const int index)
YW_INTRIN_FUNC(__m256d, _mm256_insertf128_pd, __m256d a, __m128d b, int imm8)
YW_INTRIN_FUNC(__m256, _mm256_insertf128_ps, __m256 a, __m128 b, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_insertf128_si256, __m256i a, __m128i b, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_inserti128_si256, __m256i a, __m128i b, const int imm8)
YW_INTRIN_FUNC(__m128d, _mm_invcbrt_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_invcbrt_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_invcbrt_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_invcbrt_ps, __m256 a)
YW_INTRIN_FUNC(void, _invpcid, unsigned int type, void* descriptor)
YW_INTRIN_FUNC(__m128d, _mm_invsqrt_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_invsqrt_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_invsqrt_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_invsqrt_ps, __m256 a)
YW_INTRIN_FUNC(__m128i, _mm_irem_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_irem_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_lddqu_si256, __m256i const* mem_addr)
YW_INTRIN_FUNC(__m256d, _mm256_load_pd, double const* mem_addr)
YW_INTRIN_FUNC(__m128, _mm_load_ps, float const* mem_addr)
YW_INTRIN_FUNC(__m256, _mm256_load_ps, float const* mem_addr)
YW_INTRIN_FUNC(__m128, _mm_load_ps1, float const* mem_addr)
YW_INTRIN_FUNC(__m256i, _mm256_load_si256, __m256i const* mem_addr)
YW_INTRIN_FUNC(__m128, _mm_load_ss, float const* mem_addr)
YW_INTRIN_FUNC(__m128, _mm_load1_ps, float const* mem_addr)
#ifdef _loadbe_i16
#undef _loadbe_i16
inline short _loadbe_i16(const void* ptr) noexcept { return (short)(_load_be_u16(ptr)); }
#else
YW_INTRIN_FUNC(short, _loadbe_i16, const void* ptr)
#endif
#ifdef _loadbe_i32
#undef _loadbe_i32
inline int _loadbe_i32(const void* ptr) noexcept { return (int)(_load_be_u32(ptr)); }
#else
YW_INTRIN_FUNC(int, _loadbe_i32, const void* ptr)
#endif
#ifdef _loadbe_i64
#undef _loadbe_i64
inline long long _loadbe_i64(const void* ptr) noexcept { return (long long)(_load_be_u64(ptr)); }
#else
YW_INTRIN_FUNC(long long, _loadbe_i64, const void* ptr)
#endif
YW_INTRIN_FUNC(__m128, _mm_loadh_pi, __m128 a, __m64 const* mem_addr)
YW_INTRIN_FUNC(void, _mm_loadiwkey, unsigned int __ctl, __m128i __intkey, __m128i __enkey_lo, __m128i __enkey_hi)
YW_INTRIN_FUNC(__m128, _mm_loadl_pi, __m128 a, __m64 const* mem_addr)
YW_INTRIN_FUNC(__m128, _mm_loadr_ps, float const* mem_addr)
YW_INTRIN_FUNC(__m256d, _mm256_loadu_pd, double const* mem_addr)
YW_INTRIN_FUNC(__m128, _mm_loadu_ps, float const* mem_addr)
YW_INTRIN_FUNC(__m256, _mm256_loadu_ps, float const* mem_addr)
#ifdef _mm_loadu_si16
#undef _mm_loadu_si16
inline __m128i _mm_loadu_si16(const void* mem_addr) noexcept { return _mm_cvtsi32_si128(*(const unsigned short*)mem_addr); }
#else
YW_INTRIN_FUNC(__m128i, _mm_loadu_si16, const void* mem_addr)
#endif
YW_INTRIN_FUNC(__m256i, _mm256_loadu_si256, __m256i const* mem_addr)
#ifdef _mm_loadu_si64
#undef _mm_loadu_si64
inline __m128i _mm_loadu_si64(const void* mem_addr) noexcept { return _mm_loadl_epi64((const __m128i*)mem_addr); }
#else
YW_INTRIN_FUNC(__m128i, _mm_loadu_si64, const void* mem_addr)
#endif
#ifdef _mm256_loadu2_m128
#undef _mm256_loadu2_m128
inline __m256 _mm256_loadu2_m128(const float* hiaddr, const float* loaddr) noexcept { return _mm256_set_m128(_mm_loadu_ps(hiaddr), _mm_loadu_ps(loaddr)); }
#else
YW_INTRIN_FUNC(__m256, _mm256_loadu2_m128, float const* hiaddr, float const* loaddr)
#endif
#ifdef _mm256_loadu2_m128d
#undef _mm256_loadu2_m128d
inline __m256d _mm256_loadu2_m128d(const double* hiaddr, const double* loaddr) noexcept { return _mm256_set_m128d(_mm_loadu_pd(hiaddr), _mm_loadu_pd(loaddr)); }
#else
YW_INTRIN_FUNC(__m256d, _mm256_loadu2_m128d, double const* hiaddr, double const* loaddr)
#endif
#ifdef _mm256_loadu2_m128i
#undef _mm256_loadu2_m128i
inline __m256i _mm256_loadu2_m128i(const __m128i* hiaddr, const __m128i* loaddr) noexcept { return _mm256_set_m128i(_mm_loadu_si128(hiaddr), _mm_loadu_si128(loaddr)); }
#else
YW_INTRIN_FUNC(__m256i, _mm256_loadu2_m128i, __m128i const* hiaddr, __m128i const* loaddr)
#endif
YW_INTRIN_FUNC(__m128d, _mm_log_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_log_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_log_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_log_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_log10_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_log10_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_log10_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_log10_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_log1p_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_log1p_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_log1p_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_log1p_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_log2_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_log2_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_log2_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_log2_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_logb_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_logb_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_logb_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_logb_ps, __m256 a)
YW_INTRIN_FUNC(unsigned long, _lrotl, unsigned long a, int shift)
YW_INTRIN_FUNC(unsigned long, _lrotr, unsigned long a, int shift)
YW_INTRIN_FUNC(unsigned int, _lzcnt_u32, unsigned int a)
YW_INTRIN_FUNC(unsigned long long, _lzcnt_u64, unsigned long long a)
YW_INTRIN_FUNC(__m256i, _mm256_madd_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_maddubs_epi16, __m256i a, __m256i b)
#ifdef _mm_malloc
#undef _mm_malloc
inline void* _mm_malloc(size_t size, size_t align) noexcept { return _aligned_malloc(size, align); }
#else
YW_INTRIN_FUNC(void*, _mm_malloc, size_t size, size_t align)
#endif
YW_INTRIN_FUNC(__m128i, _mm_maskload_epi32, int const* mem_addr, __m128i mask)
YW_INTRIN_FUNC(__m256i, _mm256_maskload_epi32, int const* mem_addr, __m256i mask)
YW_INTRIN_FUNC(__m128i, _mm_maskload_epi64, long long const* mem_addr, __m128i mask)
YW_INTRIN_FUNC(__m256i, _mm256_maskload_epi64, long long const* mem_addr, __m256i mask)
YW_INTRIN_FUNC(__m128d, _mm_maskload_pd, double const* mem_addr, __m128i mask)
YW_INTRIN_FUNC(__m256d, _mm256_maskload_pd, double const* mem_addr, __m256i mask)
YW_INTRIN_FUNC(__m128, _mm_maskload_ps, float const* mem_addr, __m128i mask)
YW_INTRIN_FUNC(__m256, _mm256_maskload_ps, float const* mem_addr, __m256i mask)
#ifdef YW_INTRIN_X86
YW_INTRIN_FUNC(void, _m_maskmovq, __m64 a, __m64 mask, char* mem_addr)
#ifdef _mm_maskmove_si64
#undef _mm_maskmove_si64
inline void _mm_maskmove_si64(__m64 a, __m64 mask, char* mem_addr) noexcept { _m_maskmovq(a, mask, mem_addr); }
#else
YW_INTRIN_FUNC(void, _mm_maskmove_si64, __m64 a, __m64 mask, char* mem_addr)
#endif
#endif
YW_INTRIN_FUNC(void, _mm_maskstore_epi32, int* mem_addr, __m128i mask, __m128i a)
YW_INTRIN_FUNC(void, _mm256_maskstore_epi32, int* mem_addr, __m256i mask, __m256i a)
YW_INTRIN_FUNC(void, _mm_maskstore_epi64, long long* mem_addr, __m128i mask, __m128i a)
YW_INTRIN_FUNC(void, _mm256_maskstore_epi64, long long* mem_addr, __m256i mask, __m256i a)
YW_INTRIN_FUNC(void, _mm_maskstore_pd, double* mem_addr, __m128i mask, __m128d a)
YW_INTRIN_FUNC(void, _mm256_maskstore_pd, double* mem_addr, __m256i mask, __m256d a)
YW_INTRIN_FUNC(void, _mm_maskstore_ps, float* mem_addr, __m128i mask, __m128 a)
YW_INTRIN_FUNC(void, _mm256_maskstore_ps, float* mem_addr, __m256i mask, __m256 a)
YW_INTRIN_FUNC(__m256i, _mm256_max_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_max_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_max_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_max_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_max_epu32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_max_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_max_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_max_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_min_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_min_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_min_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_min_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_min_epu32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_min_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_min_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_min_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(void, _movdir64b, void* dst, const void* src)
YW_INTRIN_FUNC(__m256d, _mm256_movedup_pd, __m256d a)
YW_INTRIN_FUNC(__m256, _mm256_movehdup_ps, __m256 a)
YW_INTRIN_FUNC(__m256, _mm256_moveldup_ps, __m256 a)
YW_INTRIN_FUNC(int, _mm256_movemask_epi8, __m256i a)
YW_INTRIN_FUNC(int, _mm256_movemask_pd, __m256d a)
YW_INTRIN_FUNC(int, _mm256_movemask_ps, __m256 a)
YW_INTRIN_FUNC(__m256i, _mm256_mpsadbw_epu8, __m256i a, __m256i b, const int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_mul_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_mul_epu32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_mul_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_mul_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_mulhi_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_mulhi_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_mulhrs_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_mullo_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_mullo_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(unsigned int, _mulx_u32, unsigned int a, unsigned int b, unsigned int* hi)
YW_INTRIN_FUNC(unsigned long long, _mulx_u64, unsigned long long a, unsigned long long b, unsigned long long* hi)
YW_INTRIN_FUNC(__m256d, _mm256_or_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_or_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_or_si256, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_packs_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_packs_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_packus_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_packus_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(unsigned int, _pconfig_u32, const int a, size_t* __data)
YW_INTRIN_FUNC(unsigned int, _pdep_u32, unsigned int a, unsigned int mask)
YW_INTRIN_FUNC(unsigned long long, _pdep_u64, unsigned long long a, unsigned long long mask)
YW_INTRIN_FUNC(__m128d, _mm_permute_pd, __m128d a, int imm8)
YW_INTRIN_FUNC(__m256d, _mm256_permute_pd, __m256d a, int imm8)
YW_INTRIN_FUNC(__m128, _mm_permute_ps, __m128 a, int imm8)
YW_INTRIN_FUNC(__m256, _mm256_permute_ps, __m256 a, int imm8)
YW_INTRIN_FUNC(__m256d, _mm256_permute2f128_pd, __m256d a, __m256d b, int imm8)
YW_INTRIN_FUNC(__m256, _mm256_permute2f128_ps, __m256 a, __m256 b, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_permute2f128_si256, __m256i a, __m256i b, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_permute2x128_si256, __m256i a, __m256i b, const int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_permute4x64_epi64, __m256i a, const int imm8)
YW_INTRIN_FUNC(__m256d, _mm256_permute4x64_pd, __m256d a, const int imm8)
YW_INTRIN_FUNC(__m128d, _mm_permutevar_pd, __m128d a, __m128i b)
YW_INTRIN_FUNC(__m256d, _mm256_permutevar_pd, __m256d a, __m256i b)
YW_INTRIN_FUNC(__m128, _mm_permutevar_ps, __m128 a, __m128i b)
YW_INTRIN_FUNC(__m256, _mm256_permutevar_ps, __m256 a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_permutevar8x32_epi32, __m256i a, __m256i idx)
YW_INTRIN_FUNC(__m256, _mm256_permutevar8x32_ps, __m256 a, __m256i idx)
YW_INTRIN_FUNC(unsigned int, _pext_u32, unsigned int a, unsigned int mask)
YW_INTRIN_FUNC(unsigned long long, _pext_u64, unsigned long long a, unsigned long long mask)
YW_INTRIN_FUNC(int, _mm_popcnt_u32, unsigned int a)
YW_INTRIN_FUNC(long long, _mm_popcnt_u64, unsigned long long a)
YW_INTRIN_FUNC(__m128d, _mm_pow_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m256d, _mm256_pow_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m128, _mm_pow_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m256, _mm256_pow_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(void, _mm_prefetch, char const* p, int i)
YW_INTRIN_FUNC(void, _ptwrite32, unsigned int a)
YW_INTRIN_FUNC(void, _ptwrite64, unsigned long long a)
YW_INTRIN_FUNC(__m256, _mm256_rcp_ps, __m256 a)
YW_INTRIN_FUNC(unsigned int, _rdpid_u32, void)
YW_INTRIN_FUNC(int, _rdrand16_step, unsigned short* val)
YW_INTRIN_FUNC(int, _rdrand32_step, unsigned int* val)
YW_INTRIN_FUNC(int, _rdrand64_step, unsigned long long* val)
YW_INTRIN_FUNC(int, _rdseed16_step, unsigned short* val)
YW_INTRIN_FUNC(int, _rdseed32_step, unsigned int* val)
YW_INTRIN_FUNC(int, _rdseed64_step, unsigned long long* val)
YW_INTRIN_FUNC(unsigned long long, __rdtscp, unsigned int* mem_addr)
YW_INTRIN_FUNC(unsigned int, _readfsbase_u32)
YW_INTRIN_FUNC(unsigned long long, _readfsbase_u64)
YW_INTRIN_FUNC(unsigned int, _readgsbase_u32)
YW_INTRIN_FUNC(unsigned long long, _readgsbase_u64)
YW_INTRIN_FUNC(__m128i, _mm_rem_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_rem_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_rem_epi64, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_rem_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_rem_epu16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_rem_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_rem_epu64, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_rem_epu8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_rem_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(unsigned int, _rotl, unsigned int a, int shift)
YW_INTRIN_FUNC(unsigned long long, _rotl64, unsigned long long a, int shift)
YW_INTRIN_FUNC(unsigned int, _rotr, unsigned int a, int shift)
YW_INTRIN_FUNC(unsigned long long, _rotr64, unsigned long long a, int shift)
YW_INTRIN_FUNC(__m256d, _mm256_round_pd, __m256d a, int rounding)
YW_INTRIN_FUNC(__m256, _mm256_round_ps, __m256 a, int rounding)
YW_INTRIN_FUNC(__m256, _mm256_rsqrt_ps, __m256 a)
YW_INTRIN_FUNC(void, _rstorssp, void* p)
YW_INTRIN_FUNC(__m256i, _mm256_sad_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(void, _saveprevssp, void)
YW_INTRIN_FUNC(void, _senduipi, unsigned long long __a)
YW_INTRIN_FUNC(void, _serialize)
YW_INTRIN_FUNC(__m256i, _mm256_set_epi16, short e15, short e14, short e13, short e12, short e11, short e10, short e9, short e8,
               short e7, short e6, short e5, short e4, short e3, short e2, short e1, short e0)
YW_INTRIN_FUNC(__m256i, _mm256_set_epi32, int e7, int e6, int e5, int e4, int e3, int e2, int e1, int e0)
YW_INTRIN_FUNC(__m256i, _mm256_set_epi64x, long long e3, long long e2, long long e1, long long e0)
YW_INTRIN_FUNC(__m256i, _mm256_set_epi8, char e31, char e30, char e29, char e28, char e27, char e26, char e25, char e24,
               char e23, char e22, char e21, char e20, char e19, char e18, char e17, char e16,
               char e15, char e14, char e13, char e12, char e11, char e10, char e9, char e8,
               char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0)
#ifdef _MM_SET_EXCEPTION_MASK
#undef _MM_SET_EXCEPTION_MASK
inline void _MM_SET_EXCEPTION_MASK(unsigned int a) noexcept { _mm_setcsr((_mm_getcsr() & ~0x1f80) | a); }
#else
YW_INTRIN_FUNC(void, _MM_SET_EXCEPTION_MASK, unsigned int a)
#endif
#ifdef _MM_SET_EXCEPTION_STATE
#undef _MM_SET_EXCEPTION_STATE
inline void _MM_SET_EXCEPTION_STATE(unsigned int a) noexcept { _mm_setcsr((_mm_getcsr() & ~0x003f) | a); }
#else
YW_INTRIN_FUNC(void, _MM_SET_EXCEPTION_STATE, unsigned int a)
#endif
#ifdef _MM_SET_FLUSH_ZERO_MODE
#undef _MM_SET_FLUSH_ZERO_MODE
inline void _MM_SET_FLUSH_ZERO_MODE(unsigned int a) noexcept { _mm_setcsr((_mm_getcsr() & ~0x8000) | a); }
#else
YW_INTRIN_FUNC(void, _MM_SET_FLUSH_ZERO_MODE, unsigned int a)
#endif
#ifdef _mm256_set_m128
#undef _mm256_set_m128
inline __m256 _mm256_set_m128(__m128 hi, __m128 lo) noexcept { return _mm256_insertf128_ps(_mm256_castps128_ps256(lo), hi, 0x1); }
#else
YW_INTRIN_FUNC(__m256, _mm256_set_m128, __m128 hi, __m128 lo)
#endif
#ifdef _mm256_set_m128d
#undef _mm256_set_m128d
inline __m256d _mm256_set_m128d(__m128d hi, __m128d lo) noexcept { return _mm256_insertf128_pd(_mm256_castpd128_pd256(lo), hi, 0x1); }
#else
YW_INTRIN_FUNC(__m256d, _mm256_set_m128d, __m128d hi, __m128d lo)
#endif
#ifdef _mm256_set_m128i
#undef _mm256_set_m128i
inline __m256i _mm256_set_m128i(__m128i hi, __m128i lo) noexcept { return _mm256_insertf128_si256(_mm256_castsi128_si256(lo), hi, 0x1); }
#else
YW_INTRIN_FUNC(__m256i, _mm256_set_m128i, __m128i hi, __m128i lo)
#endif
YW_INTRIN_FUNC(__m256d, _mm256_set_pd, double e3, double e2, double e1, double e0)
#ifdef _MM_SET_ROUNDING_MODE
#undef _MM_SET_ROUNDING_MODE
inline void _MM_SET_ROUNDING_MODE(unsigned int a) noexcept { _mm_setcsr((_mm_getcsr() & ~0x6000) | a); }
#else
YW_INTRIN_FUNC(void, _MM_SET_ROUNDING_MODE, unsigned int a)
#endif
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi16, short a)
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi32, int a)
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi64x, long long a)
YW_INTRIN_FUNC(__m256i, _mm256_set1_epi8, char a)
YW_INTRIN_FUNC(__m256d, _mm256_set1_pd, double a)
YW_INTRIN_FUNC(__m256, _mm256_set1_ps, float a)
YW_INTRIN_FUNC(void, _mm_setcsr, unsigned int a)
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi16, short e15, short e14, short e13, short e12, short e11, short e10, short e9, short e8, short e7, short e6, short e5, short e4, short e3, short e2, short e1, short e0)
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi32, int e7, int e6, int e5, int e4, int e3, int e2, int e1, int e0)
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi64x, long long e3, long long e2, long long e1, long long e0)
YW_INTRIN_FUNC(__m256i, _mm256_setr_epi8, char e31, char e30, char e29, char e28, char e27, char e26, char e25, char e24, char e23, char e22, char e21, char e20, char e19, char e18, char e17, char e16, char e15, char e14, char e13, char e12, char e11, char e10, char e9, char e8, char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0)
#ifdef _mm256_setr_m128
#undef _mm256_setr_m128
inline __m256 _mm256_setr_m128(__m128 lo, __m128 hi) noexcept { return _mm256_set_m128(hi, lo); }
#else
YW_INTRIN_FUNC(__m256, _mm256_setr_m128, __m128 lo, __m128 hi)
#endif
#ifdef _mm256_setr_m128d
#undef _mm256_setr_m128d
inline __m256d _mm256_setr_m128d(__m128d lo, __m128d hi) noexcept { return _mm256_set_m128d(hi, lo); }
#else
YW_INTRIN_FUNC(__m256d, _mm256_setr_m128d, __m128d lo, __m128d hi)
#endif
#ifdef _mm256_setr_m128i
#undef _mm256_setr_m128i
inline __m256i _mm256_setr_m128i(__m128i lo, __m128i hi) noexcept { return _mm256_set_m128i(hi, lo); }
#else
YW_INTRIN_FUNC(__m256, _mm256_setr_m128, __m128 lo, __m128 hi)
#endif
YW_INTRIN_FUNC(__m256d, _mm256_setr_pd, double e3, double e2, double e1, double e0)
YW_INTRIN_FUNC(__m256, _mm256_setr_ps, float e7, float e6, float e5, float e4, float e3, float e2, float e1, float e0)
YW_INTRIN_FUNC(void, _setssbsy, void)
YW_INTRIN_FUNC(__m256d, _mm256_setzero_pd, void)
YW_INTRIN_FUNC(__m256, _mm256_setzero_ps, void)
YW_INTRIN_FUNC(__m256i, _mm256_setzero_si256, void)
YW_INTRIN_FUNC(void, _mm_sfence, void)
YW_INTRIN_FUNC(__m128i, _mm_sha1msg1_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sha1msg2_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sha1nexte_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sha1rnds4_epu32, __m128i a, __m128i b, const int func)
YW_INTRIN_FUNC(__m128i, _mm_sha256msg1_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sha256msg2_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m128i, _mm_sha256rnds2_epu32, __m128i a, __m128i b, __m128i k)
YW_INTRIN_FUNC(__m256i, _mm256_shuffle_epi32, __m256i a, const int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_shuffle_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_shuffle_pd, __m256d a, __m256d b, const int imm8)
YW_INTRIN_FUNC(__m256, _mm256_shuffle_ps, __m256 a, __m256 b, const int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_shufflehi_epi16, __m256i a, const int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_shufflelo_epi16, __m256i a, const int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_sign_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_sign_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_sign_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128d, _mm_sin_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_sin_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_sin_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_sin_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_sincos_pd, __m128d* mem_addr, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_sincos_pd, __m256d* mem_addr, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_sincos_ps, __m128* mem_addr, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_sincos_ps, __m256* mem_addr, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_sind_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_sind_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_sind_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_sind_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_sinh_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_sinh_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_sinh_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_sinh_ps, __m256 a)
YW_INTRIN_FUNC(__m256i, _mm256_sll_epi16, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_sll_epi32, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_sll_epi64, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_slli_epi16, __m256i a, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_slli_epi32, __m256i a, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_slli_epi64, __m256i a, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_slli_si256, __m256i a, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_sllv_epi32, __m128i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_sllv_epi32, __m256i a, __m256i count)
YW_INTRIN_FUNC(__m128i, _mm_sllv_epi64, __m128i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_sllv_epi64, __m256i a, __m256i count)
YW_INTRIN_FUNC(__m256d, _mm256_sqrt_pd, __m256d a)
YW_INTRIN_FUNC(__m256, _mm256_sqrt_ps, __m256 a)
YW_INTRIN_FUNC(__m256i, _mm256_sra_epi16, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_sra_epi32, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_srai_epi16, __m256i a, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_srai_epi32, __m256i a, int imm8)
YW_INTRIN_FUNC(__m128i, _mm_srav_epi32, __m128i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_srav_epi32, __m256i a, __m256i count)
YW_INTRIN_FUNC(__m256i, _mm256_srl_epi16, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_srl_epi32, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_srl_epi64, __m256i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_srli_epi16, __m256i a, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_srli_epi32, __m256i a, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_srli_epi64, __m256i a, int imm8)
YW_INTRIN_FUNC(__m256i, _mm256_srli_si256, __m256i a, const int imm8)
YW_INTRIN_FUNC(__m128i, _mm_srlv_epi32, __m128i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_srlv_epi32, __m256i a, __m256i count)
YW_INTRIN_FUNC(__m128i, _mm_srlv_epi64, __m128i a, __m128i count)
YW_INTRIN_FUNC(__m256i, _mm256_srlv_epi64, __m256i a, __m256i count)
YW_INTRIN_FUNC(void, _mm256_store_pd, double* mem_addr, __m256d a)
YW_INTRIN_FUNC(void, _mm_store_ps, float* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm256_store_ps, float* mem_addr, __m256 a)
YW_INTRIN_FUNC(void, _mm_store_ps1, float* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm256_store_si256, __m256i* mem_addr, __m256i a)
YW_INTRIN_FUNC(void, _mm_store_ss, float* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm_store1_ps, float* mem_addr, __m128 a)
#ifdef _storebe_i16
#undef _storebe_i16
inline void _storebe_i16(void* ptr, short data) noexcept { _store_be_u16(ptr, (unsigned short)data); }
#else
YW_INTRIN_FUNC(void, _storebe_i16, void* ptr, short data)
#endif
#ifdef _storebe_i32
#undef _storebe_i32
inline void _storebe_i32(void* ptr, int data) noexcept { _store_be_u32(ptr, (unsigned int)data); }
#else
YW_INTRIN_FUNC(void, _storebe_i32, void* ptr, int data)
#endif
#ifdef _storebe_i64
#undef _storebe_i64
inline void _storebe_i64(void* ptr, long long data) noexcept { _store_be_u64(ptr, (unsigned long long)data); }
#else
YW_INTRIN_FUNC(void, _storebe_i64, void* ptr, long long data)
#endif
YW_INTRIN_FUNC(void, _mm_storeh_pi, __m64* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm_storel_pi, __m64* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm_storer_ps, float* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm256_storeu_pd, double* mem_addr, __m256d a)
YW_INTRIN_FUNC(void, _mm_storeu_ps, float* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm256_storeu_ps, float* mem_addr, __m256 a)
#ifdef _mm_storeu_si16
#undef _mm_storeu_si16
inline void _mm_storeu_si16(void* mem_addr, __m128i a) noexcept { (void)(*(short*)mem_addr = (short)_mm_cvtsi128_si32(a)); }
#else
YW_INTRIN_FUNC(void, _mm_storeu_si16, void* mem_addr, __m128i a)
#endif
YW_INTRIN_FUNC(void, _mm256_storeu_si256, __m256i* mem_addr, __m256i a)
#ifdef _mm_storeu_si64
#undef _mm_storeu_si64
inline void _mm_storeu_si64(void* mem_addr, __m128i a) noexcept { return _mm_storel_epi64((__m128i*)mem_addr, a); }
#else
YW_INTRIN_FUNC(void, _mm_storeu_si64, void* mem_addr, __m128i a)
#endif
#ifdef _mm256_storeu2_m128
#undef _mm256_storeu2_m128
inline void _mm256_storeu2_m128(float* hiaddr, float* loaddr, __m256 a) noexcept {
  _mm_storeu_ps(loaddr, _mm256_castps256_ps128(a));
  _mm_storeu_ps(hiaddr, _mm256_extractf128_ps(a, 0x1));
}
#else
YW_INTRIN_FUNC(void, _mm256_storeu2_m128, float* hiaddr, float* loaddr, __m256 a)
#endif
#ifdef _mm256_storeu2_m128d
#undef _mm256_storeu2_m128d
inline void _mm256_storeu2_m128d(double* hiaddr, double* loaddr, __m256d a) noexcept {
  _mm_storeu_pd(loaddr, _mm256_castpd256_pd128(a));
  _mm_storeu_pd(hiaddr, _mm256_extractf128_pd(a, 0x1));
}
#else
YW_INTRIN_FUNC(void, _mm256_storeu2_m128d, double* hiaddr, double* loaddr, __m256d a)
#endif
#ifdef _mm256_storeu2_m128i
#undef _mm256_storeu2_m128i
inline void _mm256_storeu2_m128i(__m128i* hiaddr, __m128i* loaddr, __m256i a) noexcept {
  _mm_storeu_si128(loaddr, _mm256_castsi256_si128(a));
  _mm_storeu_si128(hiaddr, _mm256_extractf128_si256(a, 0x1));
}
#else
YW_INTRIN_FUNC(void, _mm256_storeu2_m128i, __m128i* hiaddr, __m128i* loaddr, __m256i a)
#endif
YW_INTRIN_FUNC(__m256i, _mm256_stream_load_si256, __m256i const* mem_addr)
YW_INTRIN_FUNC(void, _mm256_stream_pd, double* mem_addr, __m256d a)
#ifdef YW_INRIN_X86
YW_INTRIN_FUNC(void, _mm_stream_pi, __m64* mem_addr, __m64 a)
#endif
YW_INTRIN_FUNC(void, _mm_stream_ps, float* mem_addr, __m128 a)
YW_INTRIN_FUNC(void, _mm256_stream_ps, float* mem_addr, __m256 a)
YW_INTRIN_FUNC(void, _mm256_stream_si256, __m256i* mem_addr, __m256i a)
YW_INTRIN_FUNC(void, _stui, void)
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_sub_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_sub_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_sub_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(unsigned char, _subborrow_u32, unsigned char c_in, unsigned int a, unsigned int b, unsigned int* out)
YW_INTRIN_FUNC(unsigned char, _subborrow_u64, unsigned char c_in, unsigned long long a, unsigned long long b, unsigned long long* out)
YW_INTRIN_FUNC(__m256i, _mm256_subs_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_subs_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_subs_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_subs_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128d, _mm_svml_ceil_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_svml_ceil_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_svml_ceil_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_svml_ceil_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_svml_floor_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_svml_floor_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_svml_floor_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_svml_floor_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_svml_round_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_svml_round_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_svml_round_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_svml_round_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_svml_sqrt_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_svml_sqrt_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_svml_sqrt_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_svml_sqrt_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_tan_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_tan_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_tan_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_tan_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_tand_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_tand_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_tand_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_tand_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_tanh_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_tanh_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_tanh_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_tanh_ps, __m256 a)
YW_INTRIN_FUNC(int, _mm_testc_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm256_testc_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(int, _mm_testc_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm256_testc_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(int, _mm256_testc_si256, __m256i a, __m256i b)
YW_INTRIN_FUNC(int, _mm_testnzc_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm256_testnzc_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(int, _mm_testnzc_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm256_testnzc_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(int, _mm256_testnzc_si256, __m256i a, __m256i b)
YW_INTRIN_FUNC(unsigned char, _testui, void)
YW_INTRIN_FUNC(int, _mm_testz_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(int, _mm256_testz_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(int, _mm_testz_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(int, _mm256_testz_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(int, _mm256_testz_si256, __m256i a, __m256i b)
YW_INTRIN_FUNC(unsigned char, _tpause, unsigned int ctrl, unsigned long long counter)
YW_INTRIN_FUNC(__m128d, _mm_trunc_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_trunc_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_trunc_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_trunc_ps, __m256 a)
YW_INTRIN_FUNC(unsigned int, _tzcnt_u32, unsigned int a)
YW_INTRIN_FUNC(unsigned long long, _tzcnt_u64, unsigned long long a)
YW_INTRIN_FUNC(__m128i, _mm_udiv_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_udiv_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_udivrem_epi32, __m128i* mem_addr, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_udivrem_epi32, __m256i* mem_addr, __m256i a, __m256i b)
YW_INTRIN_FUNC(void, _umonitor, void* a)
YW_INTRIN_FUNC(unsigned char, _umwait, unsigned int ctrl, unsigned long long counter)
YW_INTRIN_FUNC(__m256d, _mm256_undefined_pd, void)
YW_INTRIN_FUNC(__m128, _mm_undefined_ps, void)
YW_INTRIN_FUNC(__m256, _mm256_undefined_ps, void)
YW_INTRIN_FUNC(__m256i, _mm256_undefined_si256, void)
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_unpackhi_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_unpackhi_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_unpackhi_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256i, _mm256_unpacklo_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m256d, _mm256_unpacklo_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_unpacklo_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m128i, _mm_urem_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_urem_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(void, _wbnoinvd, void)
YW_INTRIN_FUNC(void, _writefsbase_u32, unsigned int a)
YW_INTRIN_FUNC(void, _writefsbase_u64, unsigned long long a)
YW_INTRIN_FUNC(void, _writegsbase_u32, unsigned int a)
YW_INTRIN_FUNC(void, _writegsbase_u64, unsigned long long a)
YW_INTRIN_FUNC(void, _wrssd, long val, void* p)
YW_INTRIN_FUNC(void, _wrssq, long long val, void* p)
YW_INTRIN_FUNC(void, _wrussd, long val, void* p)
YW_INTRIN_FUNC(void, _wrussq, long long val, void* p)
YW_INTRIN_FUNC(void, _xabort, const unsigned int imm8)
YW_INTRIN_FUNC(unsigned int, _xbegin, void)
YW_INTRIN_FUNC(void, _xend, void)
YW_INTRIN_FUNC(unsigned long long, _xgetbv, unsigned int a)
YW_INTRIN_FUNC(__m256d, _mm256_xor_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m256, _mm256_xor_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m256i, _mm256_xor_si256, __m256i a, __m256i b)
YW_INTRIN_FUNC(void, _xresldtrk)
YW_INTRIN_FUNC(void, _xrstor, void* mem_addr, unsigned long long rs_mask)
YW_INTRIN_FUNC(void, _xrstor64, void* mem_addr, unsigned long long rs_mask)
YW_INTRIN_FUNC(void, _xrstors, const void* mem_addr, unsigned long long rs_mask)
YW_INTRIN_FUNC(void, _xrstors64, const void* mem_addr, unsigned long long rs_mask)
YW_INTRIN_FUNC(void, _xsave, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsave64, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsavec, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsavec64, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsaveopt, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsaveopt64, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsaves, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsaves64, void* mem_addr, unsigned long long save_mask)
YW_INTRIN_FUNC(void, _xsetbv, unsigned int a, unsigned long long val)
YW_INTRIN_FUNC(void, _xsusldtrk)
YW_INTRIN_FUNC(unsigned char, _xtest, void)
YW_INTRIN_FUNC(void, _mm256_zeroall, void)
YW_INTRIN_FUNC(void, _mm256_zeroupper, void)
YW_INTRIN_FUNC(__m256d, _mm256_zextpd128_pd256, __m128d a)
YW_INTRIN_FUNC(__m256, _mm256_zextps128_ps256, __m128 a)
YW_INTRIN_FUNC(__m256i, _mm256_zextsi128_si256, __m128i a)
#ifdef YW_INTRIN_ENABLE_SVML
YW_INTRIN_FUNC(__m128d, _mm_acos_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_acos_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_acos_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_acosh_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_acosh_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_acosh_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_acosh_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_acosh_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_asin_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_asin_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_asin_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_asin_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_asinh_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_asinh_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_asinh_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_asinh_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_atan_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_atan_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_atan_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_atan_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_atan2_pd, __m128d a, __m128d b)
YW_INTRIN_FUNC(__m256d, _mm256_atan2_pd, __m256d a, __m256d b)
YW_INTRIN_FUNC(__m128, _mm_atan2_ps, __m128 a, __m128 b)
YW_INTRIN_FUNC(__m256, _mm256_atan2_ps, __m256 a, __m256 b)
YW_INTRIN_FUNC(__m128d, _mm_atanh_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_atanh_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_atanh_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_atanh_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_cbrt_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_cbrt_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_cbrt_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_cbrt_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_cdfnorm_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_cdfnorm_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_cdfnorm_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_cdfnorm_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_cdfnorminv_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_cdfnorminv_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_cdfnorminv_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_cdfnorminv_ps, __m256 a)
YW_INTRIN_FUNC(__m128, _mm_cexp_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_cexp_ps, __m256 a)
YW_INTRIN_FUNC(__m128, _mm_clog_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_clog_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_cos_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_cos_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_cos_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_cos_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_cosd_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_cosd_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_cosd_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_cosd_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_cosh_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_cosh_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_cosh_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_cosh_ps, __m256 a)
YW_INTRIN_FUNC(__m128, _mm_csqrt_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_csqrt_ps, __m256 a)
YW_INTRIN_FUNC(__m128i, _mm_div_epi16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epi16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_div_epi32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epi32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_div_epi64, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epi64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_div_epi8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epi8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_div_epu16, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epu16, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_div_epu32, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epu32, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_div_epu64, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epu64, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_div_epu8, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_div_epu8, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128d, _mm_erf_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_erf_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_erf_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_erf_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_erfc_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_erfc_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_erfc_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_erfc_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_erfcinv_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_erfcinv_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_erfcinv_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_erfcinv_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_erfinv_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_erfinv_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_erfinv_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_erfinv_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_exp_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_exp_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_exp_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_exp_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_exp10_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_exp10_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_exp10_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_exp10_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_exp2_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_exp2_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_exp2_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_exp2_ps, __m256 a)
YW_INTRIN_FUNC(__m128d, _mm_expm1_pd, __m128d a)
YW_INTRIN_FUNC(__m256d, _mm256_expm1_pd, __m256d a)
YW_INTRIN_FUNC(__m128, _mm_expm1_ps, __m128 a)
YW_INTRIN_FUNC(__m256, _mm256_expm1_ps, __m256 a)
#else
inline __m128d _mm_acos_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::acos(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_acos_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::acos(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_acos_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::acos(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_acos_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::acos(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_acosh_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::acosh(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_acosh_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::acosh(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_acosh_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::acosh(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_acosh_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::acosh(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_asin_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::asin(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_asin_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::asin(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_asin_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::asin(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_asin_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::asin(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_asinh_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::asinh(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_asinh_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::asinh(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_asinh_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::asinh(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_asinh_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::asinh(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_atan_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::atan(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_atan_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::atan(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_atan_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::atan(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_atan_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::atan(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_atanh_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::atanh(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_atanh_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::atanh(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_atanh_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::atanh(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_atanh_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::atanh(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_cbrt_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::cbrt(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_cbrt_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::cbrt(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_cbrt_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::cbrt(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_cbrt_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::cbrt(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_cos_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::cos(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_cos_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::cos(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_cos_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::cos(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_cos_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::cos(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_cosh_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::cosh(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_cosh_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::cosh(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_cosh_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::cosh(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_cosh_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::cosh(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_erf_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::erf(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_erf_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::erf(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_erf_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::erf(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_erf_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::erf(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_erfc_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::erfc(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_erfc_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::erfc(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_erfc_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::erfc(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_erfc_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::erfc(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_erfcinv_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = 1.0 / std::erfc(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_erfcinv_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = 1.0 / std::erfc(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_erfcinv_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = 1.0f / std::erfc(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_erfcinv_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = 1.0f / std::erfc(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_erfinv_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = 1.0 / std::erf(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_erfinv_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = 1.0 / std::erf(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_erfinv_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = 1.0f / std::erf(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_erfinv_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = 1.0f / std::erf(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_exp_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::exp(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_exp_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::exp(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_exp_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::exp(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_exp_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::exp(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_exp2_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::exp2(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_exp2_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::exp2(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_exp2_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::exp2(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_exp2_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::exp2(b[i]);
  return intrin::_mm256_load_ps(b);
}
inline __m128d _mm_expm1_pd(__m128d a) noexcept {
  double b[2];
  intrin::_mm_store_pd(b, a);
  for (int i = 0; i < 2; ++i) b[i] = std::expm1(b[i]);
  return intrin::_mm_load_pd(b);
}
inline __m256d _mm256_expm1_pd(__m256d a) noexcept {
  double b[4];
  intrin::_mm256_store_pd(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::expm1(b[i]);
  return intrin::_mm256_load_pd(b);
}
inline __m128 _mm_expm1_ps(__m128 a) noexcept {
  float b[4];
  intrin::_mm_store_ps(b, a);
  for (int i = 0; i < 4; ++i) b[i] = std::expm1(b[i]);
  return intrin::_mm_load_ps(b);
}
inline __m256 _mm256_expm1_ps(__m256 a) noexcept {
  float b[8];
  intrin::_mm256_store_ps(b, a);
  for (int i = 0; i < 8; ++i) b[i] = std::expm1(b[i]);
  return intrin::_mm256_load_ps(b);
}
#endif
#ifdef YW_INTRIN_ENABLE_AVXVNNI
YW_INTRIN_FUNC(__m128i, _mm_dpbusd_avx_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpbusd_avx_epi32, __m256i src, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_dpbusd_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpbusd_epi32, __m256i src, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_dpbusds_avx_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpbusds_avx_epi32, __m256i src, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_dpbusds_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpbusds_epi32, __m256i src, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_dpwssd_avx_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpwssd_avx_epi32, __m256i src, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_dpwssd_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpwssd_epi32, __m256i src, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_dpwssds_avx_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpwssds_avx_epi32, __m256i src, __m256i a, __m256i b)
YW_INTRIN_FUNC(__m128i, _mm_dpwssds_epi32, __m128i src, __m128i a, __m128i b)
YW_INTRIN_FUNC(__m256i, _mm256_dpwssds_epi32, __m256i src, __m256i a, __m256i b)
#endif
#ifdef YW_INTRIN_ENABLE_AVX512VL
YW_INTRIN_FUNC(__m256i, _mm256_clmulepi64_epi128, __m256i b, __m256i c, const int Imm8)
#endif
} // namespace yw::intrin
