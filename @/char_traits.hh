// ywstd/@/char_traits.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/../compare.hh"
#include "../@/fpos.hh"

namespace std {

using streamoff = decltype((int*)0 - (int*)0);
using uint_least16_t = unsigned short;
using uint_least32_t = unsigned int;
using wint_t = unsigned short;

namespace _::char_traits {
  template<typename Ct> constexpr int compare(const Ct* s1, const Ct* s2, size_t n) {
    for (size_t i = 0; i < n; ++i, ++s1, ++s2) { if (*s1 < *s2) return -1; if (*s2 < *s2) return 1; } return 0; }
  template<typename Ct> constexpr size_t length(const Ct* s) { for (size_t i = 0;; ++i) if (*s++ == Ct{}) return i; }
  template<typename Ct> constexpr const Ct* find(const Ct* s, size_t n, const Ct& a) { for (size_t i = 0; i < n; ++i) if (*s++ == a) break; return s; }
  template<typename Ct> constexpr Ct* move(Ct* s1, const Ct* s2, size_t n) {
    auto a = new Ct[n]; for (size_t i = 0; i < n; ++i) a[i] = s2[i]; for (size_t i = 0; i < n; ++i) s1[i] = a[i]; delete[] a; return s1 + n; }
  template<typename Ct> constexpr Ct* copy(Ct* s1, const Ct* s2, size_t n) { for (size_t i = 0; i < n; ++i) s1[i] = s2[i]; return s1 + n; }
  template<typename Ct> constexpr Ct* assign(Ct* s, size_t n, Ct a) { for (size_t i = 0; i < n; ++i) s[i] = a; return s + n; }
}

template<typename Ct> struct char_traits;

template<> struct char_traits<char> {
  using char_type = char;
  using int_type = int;
  using off_type = streamoff;
  using pos_type = streampos;
  using state_type = mbstate_t;
  using comparison_category = strong_ordering;
  static constexpr void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }
  static constexpr bool eq(char_type c1, char_type c2) noexcept { return c1 == c2; }
  static constexpr bool eq_int_type(int_type c1, int_type c2) noexcept { return c1 == c2; }
  static constexpr bool lt(char_type c1, char_type c2) noexcept { return c1 < c2; }
  static constexpr int compare(const char_type* s1, const char_type* s2, size_t n) { return char_traits::compare(s1, s2, n); }
  static constexpr size_t length(const char_type* s) { return char_traits::length(s); }
  static constexpr const char_type* find(const char_type* s, size_t n, const char_type& a) { return char_traits::find(s, n, a); }
  static constexpr char_type* move(char_type* s1, const char_type* s2, size_t n) { return char_traits::move(s1, s2, n); }
  static constexpr char_type* copy(char_type* s1, const char_type* s2, size_t n) { return char_traits::copy(s1, s2, n); }
  static constexpr char_type* assign(char_type* s, size_t n, char_type a) { return char_traits::assign(s, n, a); }
  static constexpr char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }
  static constexpr int_type to_int_type(char_type c) noexcept { return static_cast<int_type>(c); }
  static constexpr int_type eof() noexcept { return static_cast<int_type>(-1); }
  static constexpr int_type not_eof(int_type c) noexcept { return eq_int_type(c, eof()) ? int_type{} : c; }
};
template<> struct char_traits<wchar_t> {
  using char_type = wchar_t;
  using int_type = wint_t;
  using off_type = streamoff;
  using pos_type = wstreampos;
  using state_type = mbstate_t;
  using comparison_category = strong_ordering;
  static constexpr void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }
  static constexpr bool eq(char_type c1, char_type c2) noexcept { return c1 == c2; }
  static constexpr bool eq_int_type(int_type c1, int_type c2) noexcept { return c1 == c2; }
  static constexpr bool lt(char_type c1, char_type c2) noexcept { return c1 < c2; }
  static constexpr int compare(const char_type* s1, const char_type* s2, size_t n) { return char_traits::compare(s1, s2, n); }
  static constexpr size_t length(const char_type* s) { return char_traits::length(s); }
  static constexpr const char_type* find(const char_type* s, size_t n, const char_type& a) { return char_traits::find(s, n, a); }
  static constexpr char_type* move(char_type* s1, const char_type* s2, size_t n) { return char_traits::move(s1, s2, n); }
  static constexpr char_type* copy(char_type* s1, const char_type* s2, size_t n) { return char_traits::copy(s1, s2, n); }
  static constexpr char_type* assign(char_type* s, size_t n, char_type a) { return char_traits::assign(s, n, a); }
  static constexpr char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }
  static constexpr int_type to_int_type(char_type c) noexcept { return static_cast<int_type>(c); }
  static constexpr int_type eof() noexcept { return static_cast<int_type>(-1); }
  static constexpr int_type not_eof(int_type c) noexcept { return eq_int_type(c, eof()) ? int_type{} : c; }
};
template<> struct char_traits<char8_t> {
  using char_type = char8_t;
  using int_type = unsigned int;
  using off_type = streamoff;
  using pos_type = u8streampos;
  using state_type = mbstate_t;
  using comparison_category = strong_ordering;
  static constexpr void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }
  static constexpr bool eq(char_type c1, char_type c2) noexcept { return c1 == c2; }
  static constexpr bool eq_int_type(int_type c1, int_type c2) noexcept { return c1 == c2; }
  static constexpr bool lt(char_type c1, char_type c2) noexcept { return c1 < c2; }
  static constexpr int compare(const char_type* s1, const char_type* s2, size_t n) { return char_traits::compare(s1, s2, n); }
  static constexpr size_t length(const char_type* s) { return char_traits::length(s); }
  static constexpr const char_type* find(const char_type* s, size_t n, const char_type& a) { return char_traits::find(s, n, a); }
  static constexpr char_type* move(char_type* s1, const char_type* s2, size_t n) { return char_traits::move(s1, s2, n); }
  static constexpr char_type* copy(char_type* s1, const char_type* s2, size_t n) { return char_traits::copy(s1, s2, n); }
  static constexpr char_type* assign(char_type* s, size_t n, char_type a) { return char_traits::assign(s, n, a); }
  static constexpr char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }
  static constexpr int_type to_int_type(char_type c) noexcept { return static_cast<int_type>(c); }
  static constexpr int_type eof() noexcept { return static_cast<int_type>(-1); }
  static constexpr int_type not_eof(int_type c) noexcept { return eq_int_type(c, eof()) ? int_type{} : c; }
};
template<> struct char_traits<char16_t> {
  using char_type = char16_t;
  using int_type = uint_least16_t;
  using off_type = streamoff;
  using pos_type = u16streampos;
  using state_type = mbstate_t;
  using comparison_category = strong_ordering;
  static constexpr void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }
  static constexpr bool eq(char_type c1, char_type c2) noexcept { return c1 == c2; }
  static constexpr bool eq_int_type(int_type c1, int_type c2) noexcept { return c1 == c2; }
  static constexpr bool lt(char_type c1, char_type c2) noexcept { return c1 < c2; }
  static constexpr int compare(const char_type* s1, const char_type* s2, size_t n) { return char_traits::compare(s1, s2, n); }
  static constexpr size_t length(const char_type* s) { return char_traits::length(s); }
  static constexpr const char_type* find(const char_type* s, size_t n, const char_type& a) { return char_traits::find(s, n, a); }
  static constexpr char_type* move(char_type* s1, const char_type* s2, size_t n) { return char_traits::move(s1, s2, n); }
  static constexpr char_type* copy(char_type* s1, const char_type* s2, size_t n) { return char_traits::copy(s1, s2, n); }
  static constexpr char_type* assign(char_type* s, size_t n, char_type a) { return char_traits::assign(s, n, a); }
  static constexpr char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }
  static constexpr int_type to_int_type(char_type c) noexcept { return static_cast<int_type>(c); }
  static constexpr int_type eof() noexcept { return static_cast<int_type>(-1); }
  static constexpr int_type not_eof(int_type c) noexcept { return eq_int_type(c, eof()) ? int_type{} : c; }
};
template<> struct char_traits<char32_t> {
  using char_type = char32_t;
  using int_type = uint_least32_t;
  using off_type = streamoff;
  using pos_type = u32streampos;
  using state_type = mbstate_t;
  using comparison_category = strong_ordering;
  static constexpr void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }
  static constexpr bool eq(char_type c1, char_type c2) noexcept { return c1 == c2; }
  static constexpr bool eq_int_type(int_type c1, int_type c2) noexcept { return c1 == c2; }
  static constexpr bool lt(char_type c1, char_type c2) noexcept { return c1 < c2; }
  static constexpr int compare(const char_type* s1, const char_type* s2, size_t n) { return char_traits::compare(s1, s2, n); }
  static constexpr size_t length(const char_type* s) { return char_traits::length(s); }
  static constexpr const char_type* find(const char_type* s, size_t n, const char_type& a) { return char_traits::find(s, n, a); }
  static constexpr char_type* move(char_type* s1, const char_type* s2, size_t n) { return char_traits::move(s1, s2, n); }
  static constexpr char_type* copy(char_type* s1, const char_type* s2, size_t n) { return char_traits::copy(s1, s2, n); }
  static constexpr char_type* assign(char_type* s, size_t n, char_type a) { return char_traits::assign(s, n, a); }
  static constexpr char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }
  static constexpr int_type to_int_type(char_type c) noexcept { return static_cast<int_type>(c); }
  static constexpr int_type eof() noexcept { return static_cast<int_type>(-1); }
  static constexpr int_type not_eof(int_type c) noexcept { return eq_int_type(c, eof()) ? int_type{} : c; }
};

}
