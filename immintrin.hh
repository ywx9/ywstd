// ywstd/immintrin.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "zmmintrin.hh"

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
  float m256_f32[8];
};
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
}
#endif

namespace yw::intrin {
using MM_CMPINT_ENUM = int;

}
