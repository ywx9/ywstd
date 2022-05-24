// ywstd/ratio.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef _ywstd_
#include <ratio>
#else

#include "@/_.hh"
#include "@/integral_constant.hh"

namespace std {

namespace _ {
  template<typename Ty> constexpr Ty gcd(Ty x, type_identity_t<Ty> y) noexcept { return y == 0 ? x : _::gcd(y, x % y); }
  template<typename Ty> constexpr Ty lcm(Ty x, type_identity_t<Ty> y) noexcept { return (x * y) / _::gcd(x, y); }
}

using intmax_t = long long;

template<intmax_t Nx, intmax_t Dx = 1> class ratio {
public:
  static constexpr intmax_t num = Nx / _::gcd(Nx, Dx);
  static constexpr intmax_t den = Dx / _::gcd(Nx, Dx);
  using type = ratio<num, den>;
};

namespace _ {
  template<typename Ratio> inline constexpr bool is_special_ratio = false;
  template<intmax_t Nx, intmax_t Dx> inline constexpr bool is_special_ratio<ratio<Nx, Dx>> = true;
  template<typename Ratio> concept ratio_specialization = is_special_ratio<Ratio>;
}

template<typename R1, typename R2> using ratio_add = typename ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>::type;
template<typename R1, typename R2> using ratio_subtract = typename ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>::type;
template<typename R1, typename R2> using ratio_multiply = typename ratio<R1::num * R2::num, R1::den * R2::den>::type;
template<typename R1, typename R2> using ratio_divide = typename ratio<R1::num * R2::den, R1::den * R2::num>::type;

template<typename R1, typename R2> struct ratio_equal : bool_constant<R1::num == R2::num && R1::den == R2::den> {};
template<typename R1, typename R2> struct ratio_not_equal : bool_constant<!ratio_equal<R1, R2>::value> {};
template<typename R1, typename R2> struct ratio_less : bool_constant<_::_less(R1::num* R2::den, R2::num* R1::den)> {};
template<typename R1, typename R2> struct ratio_greater : bool_constant<ratio_less<R2, R1>::value> {};
template<typename R1, typename R2> struct ratio_less_equal : bool_constant<!ratio_less<R2, R1>::value> {};
template<typename R1, typename R2> struct ratio_greater_equal : bool_constant<!ratio_less<R1, R2>::value> {};

using atto = ratio<1, 1000000000000000000>;
using femto = ratio<1, 1000000000000000>;
using pico = ratio<1, 1000000000000>;
using nano = ratio<1, 1000000000>;
using micro = ratio<1, 1000000>;
using milli = ratio<1, 1000>;
using centi = ratio<1, 100>;
using deci = ratio<1, 10>;
using deca = ratio<10, 1>;
using hecto = ratio<100, 1>;
using kilo = ratio<1000, 1>;
using mega = ratio<1000000, 1>;
using giga = ratio<1000000000, 1>;
using tera = ratio<1000000000000, 1>;
using peta = ratio<1000000000000000, 1>;
using exa = ratio<1000000000000000000, 1>;

}

#endif
