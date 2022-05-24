// ywstd/limits.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <limits>
#else

#include "@/_.hh"

namespace std {

enum float_round_style {
  round_indeterminate = -1,
  round_toward_zero = 0,
  round_to_nearest = 1,
  round_toward_infinity = 2,
  round_toward_neg_infinity = 3,
};

enum float_denorm_style {
  denorm_indeterminate = -1,
  denorm_absent = 0,
  denorm_present = 1
};

template<typename Ty> class numeric_limits;
template<typename Ty> class numeric_limits<const Ty> : numeric_limits<Ty> {};
template<typename Ty> class numeric_limits<volatile Ty> : numeric_limits<Ty> {};
template<typename Ty> class numeric_limits<const volatile Ty> : numeric_limits<Ty> {};

template<typename Ty> class numeric_limits {
public:
  static constexpr int radix{}, digits{}, digits10{}, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded{}, is_exact{}, is_integer{}, is_iec559{}, is_modulo{}, is_signed{}, is_specialized{};
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr Ty max() noexcept { return Ty{}; }
  static constexpr Ty min() noexcept { return Ty{}; }
  static constexpr Ty lowest() noexcept { return Ty{}; }
  static constexpr Ty epcilon() noexcept { return Ty{}; }
  static constexpr Ty denorm_min() noexcept { return Ty{}; }
  static constexpr Ty round_error() noexcept { return Ty{}; }
  static constexpr Ty infinity() noexcept { return Ty{}; }
  static constexpr Ty quiet_NaN() noexcept { return Ty{}; }
  static constexpr Ty signaling_NaN() noexcept { return Ty{}; }
};

template<> class numeric_limits<bool> {
public:
  static constexpr int radix = 2, digits = 1, digits10 = 0, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo{}, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr bool max() noexcept { return true; }
  static constexpr bool min() noexcept { return false; }
  static constexpr bool lowest() noexcept { return false; }
  static constexpr bool epcilon() noexcept { return {}; }
  static constexpr bool denorm_min() noexcept { return {}; }
  static constexpr bool round_error() noexcept { return {}; }
  static constexpr bool infinity() noexcept { return {}; }
  static constexpr bool quiet_NaN() noexcept { return {}; }
  static constexpr bool signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<char> {
public:
  static constexpr int radix = 2, digits = 7, digits10 = 2, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr char max() noexcept { return _::char_max; }
  static constexpr char min() noexcept { return _::char_min; }
  static constexpr char lowest() noexcept { return min(); }
  static constexpr char epcilon() noexcept { return {}; }
  static constexpr char denorm_min() noexcept { return {}; }
  static constexpr char round_error() noexcept { return {}; }
  static constexpr char infinity() noexcept { return {}; }
  static constexpr char quiet_NaN() noexcept { return {}; }
  static constexpr char signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<wchar_t> {
public:
  static constexpr int radix = 2, digits = 16, digits10 = 4, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr wchar_t max() noexcept { return _::ushrt_max; }
  static constexpr wchar_t min() noexcept { return 0; }
  static constexpr wchar_t lowest() noexcept { return min(); }
  static constexpr wchar_t epcilon() noexcept { return {}; }
  static constexpr wchar_t denorm_min() noexcept { return {}; }
  static constexpr wchar_t round_error() noexcept { return {}; }
  static constexpr wchar_t infinity() noexcept { return {}; }
  static constexpr wchar_t quiet_NaN() noexcept { return {}; }
  static constexpr wchar_t signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<char8_t> {
public:
  static constexpr int radix = 2, digits = 8, digits10 = 2, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr char8_t max() noexcept { return _::uchar_max; }
  static constexpr char8_t min() noexcept { return 0; }
  static constexpr char8_t lowest() noexcept { return min(); }
  static constexpr char8_t epcilon() noexcept { return {}; }
  static constexpr char8_t denorm_min() noexcept { return {}; }
  static constexpr char8_t round_error() noexcept { return {}; }
  static constexpr char8_t infinity() noexcept { return {}; }
  static constexpr char8_t quiet_NaN() noexcept { return {}; }
  static constexpr char8_t signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<char16_t> {
public:
  static constexpr int radix = 2, digits = 16, digits10 = 4, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr char16_t max() noexcept { return _::ushrt_max; }
  static constexpr char16_t min() noexcept { return 0; }
  static constexpr char16_t lowest() noexcept { return min(); }
  static constexpr char16_t epcilon() noexcept { return {}; }
  static constexpr char16_t denorm_min() noexcept { return {}; }
  static constexpr char16_t round_error() noexcept { return {}; }
  static constexpr char16_t infinity() noexcept { return {}; }
  static constexpr char16_t quiet_NaN() noexcept { return {}; }
  static constexpr char16_t signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<char32_t> {
public:
  static constexpr int radix = 2, digits = 32, digits10 = 9, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr char32_t max() noexcept { return _::uint_max; }
  static constexpr char32_t min() noexcept { return 0; }
  static constexpr char32_t lowest() noexcept { return min(); }
  static constexpr char32_t epcilon() noexcept { return {}; }
  static constexpr char32_t denorm_min() noexcept { return {}; }
  static constexpr char32_t round_error() noexcept { return {}; }
  static constexpr char32_t infinity() noexcept { return {}; }
  static constexpr char32_t quiet_NaN() noexcept { return {}; }
  static constexpr char32_t signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<signed char> {
public:
  static constexpr int radix = 2, digits = 7, digits10 = 2, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr signed char max() noexcept { return _::schar_max; }
  static constexpr signed char min() noexcept { return _::schar_min; }
  static constexpr signed char lowest() noexcept { return min(); }
  static constexpr signed char epcilon() noexcept { return {}; }
  static constexpr signed char denorm_min() noexcept { return {}; }
  static constexpr signed char round_error() noexcept { return {}; }
  static constexpr signed char infinity() noexcept { return {}; }
  static constexpr signed char quiet_NaN() noexcept { return {}; }
  static constexpr signed char signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<short> {
public:
  static constexpr int radix = 2, digits = 15, digits10 = 4, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr short max() noexcept { return _::shrt_max; }
  static constexpr short min() noexcept { return _::shrt_min; }
  static constexpr short lowest() noexcept { return min(); }
  static constexpr short epcilon() noexcept { return {}; }
  static constexpr short denorm_min() noexcept { return {}; }
  static constexpr short round_error() noexcept { return {}; }
  static constexpr short infinity() noexcept { return {}; }
  static constexpr short quiet_NaN() noexcept { return {}; }
  static constexpr short signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<int> {
public:
  static constexpr int radix = 2, digits = 31, digits10 = 9, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr int max() noexcept { return _::int_max; }
  static constexpr int min() noexcept { return _::int_min; }
  static constexpr int lowest() noexcept { return min(); }
  static constexpr int epcilon() noexcept { return {}; }
  static constexpr int denorm_min() noexcept { return {}; }
  static constexpr int round_error() noexcept { return {}; }
  static constexpr int infinity() noexcept { return {}; }
  static constexpr int quiet_NaN() noexcept { return {}; }
  static constexpr int signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<long> {
public:
  static constexpr int radix = 2, digits = 31, digits10 = 9, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr long max() noexcept { return _::long_max; }
  static constexpr long min() noexcept { return _::long_min; }
  static constexpr long lowest() noexcept { return min(); }
  static constexpr long epcilon() noexcept { return {}; }
  static constexpr long denorm_min() noexcept { return {}; }
  static constexpr long round_error() noexcept { return {}; }
  static constexpr long infinity() noexcept { return {}; }
  static constexpr long quiet_NaN() noexcept { return {}; }
  static constexpr long signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<long long> {
public:
  static constexpr int radix = 2, digits = 63, digits10 = 18, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr long long max() noexcept { return _::llong_max; }
  static constexpr long long min() noexcept { return _::llong_min; }
  static constexpr long long lowest() noexcept { return min(); }
  static constexpr long long epcilon() noexcept { return {}; }
  static constexpr long long denorm_min() noexcept { return {}; }
  static constexpr long long round_error() noexcept { return {}; }
  static constexpr long long infinity() noexcept { return {}; }
  static constexpr long long quiet_NaN() noexcept { return {}; }
  static constexpr long long signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<unsigned char> {
public:
  static constexpr int radix = 2, digits = 8, digits10 = 2, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr unsigned char max() noexcept { return _::uchar_max; }
  static constexpr unsigned char min() noexcept { return 0; }
  static constexpr unsigned char lowest() noexcept { return min(); }
  static constexpr unsigned char epcilon() noexcept { return {}; }
  static constexpr unsigned char denorm_min() noexcept { return {}; }
  static constexpr unsigned char round_error() noexcept { return {}; }
  static constexpr unsigned char infinity() noexcept { return {}; }
  static constexpr unsigned char quiet_NaN() noexcept { return {}; }
  static constexpr unsigned char signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<unsigned short> {
public:
  static constexpr int radix = 2, digits = 16, digits10 = 4, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr unsigned short max() noexcept { return _::ushrt_max; }
  static constexpr unsigned short min() noexcept { return 0; }
  static constexpr unsigned short lowest() noexcept { return min(); }
  static constexpr unsigned short epcilon() noexcept { return {}; }
  static constexpr unsigned short denorm_min() noexcept { return {}; }
  static constexpr unsigned short round_error() noexcept { return {}; }
  static constexpr unsigned short infinity() noexcept { return {}; }
  static constexpr unsigned short quiet_NaN() noexcept { return {}; }
  static constexpr unsigned short signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<unsigned int> {
public:
  static constexpr int radix = 2, digits = 32, digits10 = 9, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr unsigned int max() noexcept { return _::uint_max; }
  static constexpr unsigned int min() noexcept { return 0; }
  static constexpr unsigned int lowest() noexcept { return min(); }
  static constexpr unsigned int epcilon() noexcept { return {}; }
  static constexpr unsigned int denorm_min() noexcept { return {}; }
  static constexpr unsigned int round_error() noexcept { return {}; }
  static constexpr unsigned int infinity() noexcept { return {}; }
  static constexpr unsigned int quiet_NaN() noexcept { return {}; }
  static constexpr unsigned int signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<unsigned long> {
public:
  static constexpr int radix = 2, digits = 32, digits10 = 9, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr unsigned long max() noexcept { return _::ulong_max; }
  static constexpr unsigned long min() noexcept { return 0; }
  static constexpr unsigned long lowest() noexcept { return min(); }
  static constexpr unsigned long epcilon() noexcept { return {}; }
  static constexpr unsigned long denorm_min() noexcept { return {}; }
  static constexpr unsigned long round_error() noexcept { return {}; }
  static constexpr unsigned long infinity() noexcept { return {}; }
  static constexpr unsigned long quiet_NaN() noexcept { return {}; }
  static constexpr unsigned long signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<unsigned long long> {
public:
  static constexpr int radix = 2, digits = 64, digits10 = 19, max_digits10{};
  static constexpr int max_exponent{}, max_exponent10{}, min_exponent{}, min_exponent10{};
  static constexpr bool has_denorm_loss{}, has_infinity{}, has_quiet_NaN{}, has_signaling_NaN{};
  static constexpr bool is_bounded = 1, is_exact = 1, is_integer = 1, is_iec559{}, is_modulo = 1, is_signed{}, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr float_round_style round_style = round_toward_zero;
  static constexpr unsigned long long max() noexcept { return _::ullong_max; }
  static constexpr unsigned long long min() noexcept { return 0; }
  static constexpr unsigned long long lowest() noexcept { return min(); }
  static constexpr unsigned long long epcilon() noexcept { return {}; }
  static constexpr unsigned long long denorm_min() noexcept { return {}; }
  static constexpr unsigned long long round_error() noexcept { return {}; }
  static constexpr unsigned long long infinity() noexcept { return {}; }
  static constexpr unsigned long long quiet_NaN() noexcept { return {}; }
  static constexpr unsigned long long signaling_NaN() noexcept { return {}; }
};

template<> class numeric_limits<float> {
public:
  static constexpr int radix = _::flt_radix;
  static constexpr int digits = _::flt_mant_dig, digits10 = _::flt_dig, max_digits10 = _::flt_decimal_dig;
  static constexpr int max_exponent = _::flt_max_exp, max_exponent10 = _::flt_max_10_exp;
  static constexpr int min_exponent = _::flt_min_exp, min_exponent10 = _::flt_min_10_exp;
  static constexpr bool has_denorm_loss{}, has_infinity = 1, has_quiet_NaN = 1, has_signaling_NaN = 1;
  static constexpr bool is_bounded = 1, is_exact{}, is_integer{}, is_iec559 = 1, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_present;
  static constexpr float_round_style round_style = round_to_nearest;
  static constexpr float max() noexcept { return _::flt_max; }
  static constexpr float min() noexcept { return _::flt_min; }
  static constexpr float lowest() noexcept { return -max(); }
  static constexpr float epcilon() noexcept { return _::flt_epsilon; }
  static constexpr float denorm_min() noexcept { return _::flt_true_min; }
  static constexpr float round_error() noexcept { return 0.5f; }
  static constexpr float infinity() noexcept { return __builtin_huge_valf(); }
  static constexpr float quiet_NaN() noexcept { return __builtin_nanf("0"); }
  static constexpr float signaling_NaN() noexcept { return __builtin_nansf("1"); }
};

template<> class numeric_limits<double> {
public:
  static constexpr int radix = _::flt_radix;
  static constexpr int digits = _::dbl_mant_dig, digits10 = _::dbl_dig, max_digits10 = _::dbl_decimal_dig;
  static constexpr int max_exponent = _::dbl_max_exp, max_exponent10 = _::dbl_max_10_exp;
  static constexpr int min_exponent = _::dbl_min_exp, min_exponent10 = _::dbl_min_10_exp;
  static constexpr bool has_denorm_loss{}, has_infinity = 1, has_quiet_NaN = 1, has_signaling_NaN = 1;
  static constexpr bool is_bounded = 1, is_exact{}, is_integer{}, is_iec559 = 1, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_present;
  static constexpr float_round_style round_style = round_to_nearest;
  static constexpr double max() noexcept { return _::dbl_max; }
  static constexpr double min() noexcept { return _::dbl_min; }
  static constexpr double lowest() noexcept { return -max(); }
  static constexpr double epcilon() noexcept { return _::dbl_epsilon; }
  static constexpr double denorm_min() noexcept { return _::dbl_true_min; }
  static constexpr double round_error() noexcept { return 0.5; }
  static constexpr double infinity() noexcept { return __builtin_huge_val(); }
  static constexpr double quiet_NaN() noexcept { return __builtin_nan("0"); }
  static constexpr double signaling_NaN() noexcept { return __builtin_nans("1"); }
};

template<> class numeric_limits<long double> {
public:
  static constexpr int radix = _::flt_radix;
  static constexpr int digits = _::ldbl_mant_dig, digits10 = _::ldbl_dig, max_digits10 = _::ldbl_decimal_dig;
  static constexpr int max_exponent = _::ldbl_max_exp, max_exponent10 = _::ldbl_max_10_exp;
  static constexpr int min_exponent = _::ldbl_min_exp, min_exponent10 = _::ldbl_min_10_exp;
  static constexpr bool has_denorm_loss{}, has_infinity = 1, has_quiet_NaN = 1, has_signaling_NaN = 1;
  static constexpr bool is_bounded = 1, is_exact{}, is_integer{}, is_iec559 = 1, is_modulo{}, is_signed = 1, is_specialized = 1;
  static constexpr bool tinyness_before{}, traps{};
  static constexpr float_denorm_style has_denorm = denorm_present;
  static constexpr float_round_style round_style = round_to_nearest;
  static constexpr long double max() noexcept { return _::ldbl_max; }
  static constexpr long double min() noexcept { return _::ldbl_min; }
  static constexpr long double lowest() noexcept { return -max(); }
  static constexpr long double epcilon() noexcept { return _::ldbl_epsilon; }
  static constexpr long double denorm_min() noexcept { return _::ldbl_true_min; }
  static constexpr long double round_error() noexcept { return 0.5; }
  static constexpr long double infinity() noexcept { return __builtin_huge_val(); }
  static constexpr long double quiet_NaN() noexcept { return __builtin_nan("0"); }
  static constexpr long double signaling_NaN() noexcept { return __builtin_nans("1"); }
};

}

#endif
