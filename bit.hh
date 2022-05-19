// ywstd/bit.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <bit>
#else

#include "@/_.hh"

namespace std {

enum class endian { little, big, native = little };

template<typename To, typename From>
requires (sizeof(To) == sizeof(From)) && _::is_trivially_copyable_v<To> && _::is_trivially_copyable_v<From>
constexpr To bit_cast(const From& from) noexcept { return __builtin_bit_cast(To, from); }

namespace _ {
  inline constexpr unsigned char byteswap_table[256] = {
    0, 128, 64, 192, 32, 160, 96, 224, 16, 144, 80, 208, 48, 176, 112, 240,
    8, 136, 72, 200, 40, 168, 104, 232, 24, 152, 88, 216, 56, 184, 120, 248,
    4, 132, 68, 196, 36, 164, 100, 228, 20, 148, 84, 212, 52, 180, 116, 244,
    12, 140, 76, 204, 44, 172, 108, 236, 28, 156, 92, 220, 60, 188, 124, 252,
    2, 130, 66, 194, 34, 162, 98, 226, 18, 146, 82, 210, 50, 178, 114, 242,
    10, 138, 74, 202, 42, 170, 106, 234, 26, 154, 90, 218, 58, 186, 122, 250,
    6, 134, 70, 198, 38, 166, 102, 230, 22, 150, 86, 214, 54, 182, 118, 246,
    14, 142, 78, 206, 46, 174, 110, 238, 30, 158, 94, 222, 62, 190, 126, 254,
    1, 129, 65, 193, 33, 161, 97, 225, 17, 145, 81, 209, 49, 177, 113, 241,
    9, 137, 73, 201, 41, 169, 105, 233, 25, 153, 89, 217, 57, 185, 121, 249,
    5, 133, 69, 197, 37, 165, 101, 229, 21, 149, 85, 213, 53, 181, 117, 245,
    13, 141, 77, 205, 45, 173, 109, 237, 29, 157, 93, 221, 61, 189, 125, 253,
    3, 131, 67, 195, 35, 163, 99, 227, 19, 147, 83, 211, 51, 179, 115, 243,
    11, 139, 75, 203, 43, 171, 107, 235, 27, 155, 91, 219, 59, 187, 123, 251,
    7, 135, 71, 199, 39, 167, 103, 231, 23, 151, 87, 215, 55, 183, 119, 247,
    15, 143, 79, 207, 47, 175, 111, 239, 31, 159, 95, 223, 63, 191, 127, 255};
  template<typename Ty> struct byteswap_array { unsigned char value[sizeof(Ty)]; };
}

template<typename Ty> requires _::is_integral_v<Ty>
constexpr Ty byteswap(Ty Value) noexcept {
  if constexpr (_::is_bool_v<Ty>) return Value;
  if constexpr (_::is_signed_v<Ty>) return std::bit_cast<Ty>(std::byteswap(std::bit_cast<_::make_unsigned_t<Ty>>(Value)));
  _::byteswap_array<Ty> a{};
  for (size_t i = 0; i < sizeof(Ty); Value >>= 8) a.value[i++] = _::byteswap_table[Value & 0xFF];
  return std::bit_cast<Ty>(a);
}

namespace _ {
  inline constexpr int popcount_table[256] {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
}

template<typename Ty> requires _::is_nat<Ty>
constexpr int popcount(Ty x) noexcept {
  for (int i = 0;; i += _::popcount_table[x & 0xFF], x >>= 8) if (x == 0) return i;
}

template<typename Ty> requires _::is_nat<Ty>
constexpr int countl_zero(Ty x) noexcept {
  auto a = static_cast<Ty>(1ull << (_::bit_size<Ty> - 1));
  for (int i = 0;; ++i, x <<= 1) if (x & a) return i;
}

template<typename Ty> requires _::is_nat<Ty>
constexpr int countr_zero(Ty x) noexcept {
  for (int i = 0;; ++i, x >>= 1) if (x & 1) return i;
}

template<typename Ty> requires _::is_nat<Ty>
constexpr Ty bit_width(Ty x) noexcept {
  return _::bit_size<Ty> - std::countl_zero(x);
}

template<typename Ty> requires _::is_nat<Ty> constexpr int countl_one(Ty x) noexcept { return std::countl_zero(~x); }
template<typename Ty> requires _::is_nat<Ty> constexpr int countr_one(Ty x) noexcept { return std::countr_zero(~x); }

template<typename Ty> requires _::is_nat<Ty>
constexpr bool has_single_bit(Ty x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}

template<typename Ty> requires _::is_nat<Ty>
constexpr Ty bit_ceil(Ty x) noexcept {
  if (x <= 1) return Ty{1};
  return static_cast<Ty>(1ull << std::bit_width(x - 1));
}
template<typename Ty> requires _::is_nat<Ty>
constexpr Ty bit_floor(Ty x) noexcept {
  if (x == 0) return 0;
  return Ty{1} << (std::bit_width(x) - 1);
}

template<typename Ty> requires _::is_nat<Ty>
[[nodiscard]] constexpr Ty rotr(Ty x, int s) noexcept;

template<typename Ty> requires _::is_nat<Ty>
[[nodiscard]] constexpr Ty rotl(Ty x, int s) noexcept {
  int r = s % _::bit_size<Ty>;
  if (r == 0) return x;
  if (r <  0) return std::rotr(x, -r);
  return (x << r) | (x >> (_::bit_size<Ty> - r));
}
template<typename Ty> requires _::is_nat<Ty>
[[nodiscard]] constexpr Ty rotr(Ty x, int s) noexcept {
  int r = s % _::bit_size<Ty>;
  if (r == 0) return x;
  if (r <  0) return std::rotl(x, -r);
  return (x >> r) | (x << (_::bit_size<Ty> - r));
}

}

#endif
