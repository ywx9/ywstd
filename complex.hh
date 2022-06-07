// ywstd/complex.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDTy-License-Identifier: Apache-2.0

// clang-format offa

#pragma once

#ifdef _ywstd_
#include <complex>
#else

namespace std {

template<typename Ct, typename Tyr> class basic_istream;
template<typename Ct, typename Tyr> class basic_ostream;

template<typename Ty>
class complex {
public:
  using value_type = Ty;
  constexpr complex(const Ty& re = Ty(), const Ty& im = Ty());
  constexpr complex(const complex&);
  template<typename Uy> constexpr complex(const complex<Ty>&);

  constexpr Ty real() const;
  constexpr void real(Ty);
  constexpr Ty imag() const;
  constexpr void imag(Ty);

  constexpr complex<Ty>& operator=(const Ty&);
  constexpr complex<Ty>& operator+=(const Ty&);
  constexpr complex<Ty>& operator-=(const Ty&);
  constexpr complex<Ty>& operator*=(const Ty&);
  constexpr complex<Ty>& operator/=(const Ty&);

  constexpr complex& operator=(const complex&);
  template<typename Uy> constexpr complex<Ty>& operator=(const complex<Uy>&);
  template<typename Uy> constexpr complex<Ty>& operator+=(const complex<Uy>&);
  template<typename Uy> constexpr complex<Ty>& operator-=(const complex<Uy>&);
  template<typename Uy> constexpr complex<Ty>& operator*=(const complex<Uy>&);
  template<typename Uy> constexpr complex<Ty>& operator/=(const complex<Uy>&);
};
template<> class complex<float> {
public:
  typedef float value_type;

  constexpr complex(float re = 0.0f, float im = 0.0f);
  explicit constexpr complex(const complex<double>&);
  explicit constexpr complex(const complex<long double>&);

  constexpr float real() const;
  constexpr void real(float);
  constexpr float imag() const;
  constexpr void imag(float);

  constexpr complex<float>& operator=(float);
  constexpr complex<float>& operator+=(float);
  constexpr complex<float>& operator-=(float);
  constexpr complex<float>& operator*=(float);
  constexpr complex<float>& operator/=(float);

  constexpr complex<float>& operator=(const complex<float>&);
  template<typename Uy> constexpr complex<float>& operator=(const complex<Uy>&);
  template<typename Uy> constexpr complex<float>& operator+=(const complex<Uy>&);
  template<typename Uy> constexpr complex<float>& operator-=(const complex<Uy>&);
  template<typename Uy> constexpr complex<float>& operator*=(const complex<Uy>&);
  template<typename Uy> constexpr complex<float>& operator/=(const complex<Uy>&);
};

template<> class complex<double> {
public:
  typedef double value_type;

  constexpr complex(double re = 0.0, double im = 0.0);
  constexpr complex(const complex<float>&);
  explicit constexpr complex(const complex<long double>&);

  constexpr double real() const;
  constexpr void real(double);
  constexpr double imag() const;
  constexpr void imag(double);

  constexpr complex<double>& operator=(double);
  constexpr complex<double>& operator+=(double);
  constexpr complex<double>& operator-=(double);
  constexpr complex<double>& operator*=(double);
  constexpr complex<double>& operator/=(double);

  constexpr complex<double>& operator=(const complex<double>&);
  template<typename Uy> constexpr complex<double>& operator=(const complex<Uy>&);
  template<typename Uy> constexpr complex<double>& operator+=(const complex<Uy>&);
  template<typename Uy> constexpr complex<double>& operator-=(const complex<Uy>&);
  template<typename Uy> constexpr complex<double>& operator*=(const complex<Uy>&);
  template<typename Uy> constexpr complex<double>& operator/=(const complex<Uy>&);
};

template<> class complex<long double> {
public:
  typedef long double value_type;

  constexpr complex(long double re = 0.0L, long double im = 0.0L);
  constexpr complex(const complex<float>&);
  constexpr complex(const complex<double>&);

  constexpr long double real() const;
  constexpr void real(long double);
  constexpr long double imag() const;
  constexpr void imag(long double);

  constexpr complex<long double>& operator=(const complex<long double>&);
  constexpr complex<long double>& operator=(long double);
  constexpr complex<long double>& operator+=(long double);
  constexpr complex<long double>& operator-=(long double);
  constexpr complex<long double>& operator*=(long double);
  constexpr complex<long double>& operator/=(long double);

  template<typename Uy> constexpr complex<long double>& operator=(const complex<Uy>&);
  template<typename Uy> constexpr complex<long double>& operator+=(const complex<Uy>&);
  template<typename Uy> constexpr complex<long double>& operator-=(const complex<Uy>&);
  template<typename Uy> constexpr complex<long double>& operator*=(const complex<Uy>&);
  template<typename Uy> constexpr complex<long double>& operator/=(const complex<Uy>&);
};

// operators:
template<typename Ty> constexpr complex<Ty> operator+(const complex<Ty>&, const complex<Ty>&);
template<typename Ty> constexpr complex<Ty> operator+(const complex<Ty>&, const Ty&);
template<typename Ty> constexpr complex<Ty> operator+(const Ty&, const complex<Ty>&);

template<typename Ty> constexpr complex<Ty> operator-(const complex<Ty>&, const complex<Ty>&);
template<typename Ty> constexpr complex<Ty> operator-(const complex<Ty>&, const Ty&);
template<typename Ty> constexpr complex<Ty> operator-(const Ty&, const complex<Ty>&);

template<typename Ty> constexpr complex<Ty> operator*(const complex<Ty>&, const complex<Ty>&);
template<typename Ty> constexpr complex<Ty> operator*(const complex<Ty>&, const Ty&);
template<typename Ty> constexpr complex<Ty> operator*(const Ty&, const complex<Ty>&);

template<typename Ty> constexpr complex<Ty> operator/(const complex<Ty>&, const complex<Ty>&);
template<typename Ty> constexpr complex<Ty> operator/(const complex<Ty>&, const Ty&);
template<typename Ty> constexpr complex<Ty> operator/(const Ty&, const complex<Ty>&);

template<typename Ty> constexpr complex<Ty> operator+(const complex<Ty>&);
template<typename Ty> constexpr complex<Ty> operator-(const complex<Ty>&);

template<typename Ty> constexpr bool operator==(const complex<Ty>&, const complex<Ty>&);
template<typename Ty> constexpr bool operator==(const complex<Ty>&, const Ty&);
template<typename Ty> constexpr bool operator==(const Ty&, const complex<Ty>&);

template<typename Ty> constexpr bool operator!=(const complex<Ty>&, const complex<Ty>&);
template<typename Ty> constexpr bool operator!=(const complex<Ty>&, const Ty&);
template<typename Ty> constexpr bool operator!=(const Ty&, const complex<Ty>&);

template<typename Ty, typename Ct, typename Tr> basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>&, complex<Ty>&);
template<typename Ty, typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const complex<Ty>&);

// values:
template<typename Ty> constexpr Ty real(const complex<Ty>&);
template<typename Ty> constexpr Ty imag(const complex<Ty>&);

template<typename Ty> Ty abs(const complex<Ty>&);
template<typename Ty> Ty arg(const complex<Ty>&);
template<typename Ty> constexpr Ty norm(const complex<Ty>&);

template<typename Ty> constexpr complex<Ty> conj(const complex<Ty>&);
template<typename Ty> complex<Ty> proj(const complex<Ty>&);
template<typename Ty> complex<Ty> polar(const Ty&, const Ty& = 0);

// transcendentals:
template<typename Ty> complex<Ty> sin(const complex<Ty>&);
template<typename Ty> complex<Ty> cos(const complex<Ty>&);
template<typename Ty> complex<Ty> tan(const complex<Ty>&);

template<typename Ty> complex<Ty> acos(const complex<Ty>&);
template<typename Ty> complex<Ty> asin(const complex<Ty>&);
template<typename Ty> complex<Ty> atan(const complex<Ty>&);

template<typename Ty> complex<Ty> sinh(const complex<Ty>&);
template<typename Ty> complex<Ty> cosh(const complex<Ty>&);
template<typename Ty> complex<Ty> tanh(const complex<Ty>&);

template<typename Ty> complex<Ty> acosh(const complex<Ty>&);
template<typename Ty> complex<Ty> asinh(const complex<Ty>&);
template<typename Ty> complex<Ty> atanh(const complex<Ty>&);
template<typename Ty> complex<Ty> exp(const complex<Ty>&);
template<typename Ty> complex<Ty> log(const complex<Ty>&);
template<typename Ty> complex<Ty> log10(const complex<Ty>&);

template<typename Ty> complex<Ty> pow(const complex<Ty>&, const Ty&);
template<typename Ty> complex<Ty> pow(const complex<Ty>&, const complex<Ty>&);
template<typename Ty> complex<Ty> pow(const Ty&, const complex<Ty>&);

template<typename Ty> complex<Ty> sqrt(const complex<Ty>&);
template<typename Ty> complex<Ty> cbrt(const complex<Ty>& x) { return pow(x, static_cast<Ty>(1.0 / 3.0)); }

// complex literals:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuser-defined-literals"
inline namespace literals {
  inline namespace complex_literals {
    constexpr complex<long double> operator""il(long double);
    constexpr complex<long double> operator""il(unsigned long long);
    constexpr complex<double> operator""i(long double);
    constexpr complex<double> operator""i(unsigned long long);
    constexpr complex<float> operator""if(long double);
    constexpr complex<float> operator""if(unsigned long long);
  }
}
#pragma clang diagnostic pop

}

#endif
