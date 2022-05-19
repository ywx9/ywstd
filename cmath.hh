// ywstd/cmath.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <cmath>
#else

#include "@/_.hh"

namespace sld {

using float_t = float;
using double_t = double;

float acos(float x);
double acos(double x);
long double acos(long double x);
float acosf(float x);
long double acosl(long double x);

float asin(float x);
double asin(double x);
long double asin(long double x);
float asinf(float x);
long double asinl(long double x);

float atan(float x);
double atan(double x);
long double atan(long double x);
float atanf(float x);
long double atanl(long double x);

float atan2(float y, float x);
double atan2(double y, double x);
long double atan2(long double y, long double x);
float atan2f(float y, float x);
long double atan2l(long double y, long double x);

float cos(float x);
double cos(double x);
long double cos(long double x);
float cosf(float x);
long double cosl(long double x);

float sin(float x);
double sin(double x);
long double sin(long double x);
float sinf(float x);
long double sinl(long double x);

float tan(float x);
double tan(double x);
long double tan(long double x);
float tanf(float x);
long double tanl(long double x);

float acosh(float x);
double acosh(double x);
long double acosh(long double x);
float acoshf(float x);
long double acoshl(long double x);

float asinh(float x);
double asinh(double x);
long double asinh(long double x);
float asinhf(float x);
long double asinhl(long double x);

float atanh(float x);
double atanh(double x);
long double atanh(long double x);
float atanhf(float x);
long double atanhl(long double x);

float cosh(float x);
double cosh(double x);
long double cosh(long double x);
float coshf(float x);
long double coshl(long double x);

float sinh(float x);
double sinh(double x);
long double sinh(long double x);
float sinhf(float x);
long double sinhl(long double x);

float tanh(float x);
double tanh(double x);
long double tanh(long double x);
float tanhf(float x);
long double tanhl(long double x);

float exp(float x);
double exp(double x);
long double exp(long double x);
float expf(float x);
long double expl(long double x);

float exp2(float x);
double exp2(double x);
long double exp2(long double x);
float exp2f(float x);
long double exp2l(long double x);

float expm1(float x);
double expm1(double x);
long double expm1(long double x);
float expm1f(float x);
long double expm1l(long double x);

constexpr float frexp(float value, int* exp);
constexpr double frexp(double value, int* exp);
constexpr long double frexp(long double value, int* exp);
constexpr float frexpf(float value, int* exp);
constexpr long double frexpl(long double value, int* exp);

constexpr int ilogb(float x);
constexpr int ilogb(double x);
constexpr int ilogb(long double x);
constexpr int ilogbf(float x);
constexpr int ilogbl(long double x);

constexpr float ldexp(float x, int exp);
constexpr double ldexp(double x, int exp);
constexpr long double ldexp(long double x, int exp);
constexpr float ldexpf(float x, int exp);
constexpr long double ldexpl(long double x, int exp);

float log(float x);
double log(double x);
long double log(long double x);
float logf(float x);
long double logl(long double x);

float log10(float x);
double log10(double x);
long double log10(long double x);
float log10f(float x);
long double log10l(long double x);

float log1p(float x);
double log1p(double x);
long double log1p(long double x);
float log1pf(float x);
long double log1pl(long double x);

float log2(float x);
double log2(double x);
long double log2(long double x);
float log2f(float x);
long double log2l(long double x);

constexpr float logb(float x);
constexpr double logb(double x);
constexpr long double logb(long double x);
constexpr float logbf(float x);
constexpr long double logbl(long double x);

constexpr float modf(float value, float* iptr);
constexpr double modf(double value, double* iptr);
constexpr long double modf(long double value, long double* iptr);
constexpr float modff(float value, float* iptr);
constexpr long double modfl(long double value, long double* iptr);

constexpr float scalbn(float x, int n);
constexpr double scalbn(double x, int n);
constexpr long double scalbn(long double x, int n);
constexpr float scalbnf(float x, int n);
constexpr long double scalbnl(long double x, int n);

constexpr float scalbln(float x, long int n);
constexpr double scalbln(double x, long int n);
constexpr long double scalbln(long double x, long int n);
constexpr float scalblnf(float x, long int n);
constexpr long double scalblnl(long double x, long int n);

float cbrt(float x);
double cbrt(double x);
long double cbrt(long double x);
float cbrtf(float x);
long double cbrtl(long double x);

// absolute values
constexpr int abs(int j);
constexpr long int abs(long int j);
constexpr long long int abs(long long int j);
constexpr float abs(float j);
constexpr double abs(double j);
constexpr long double abs(long double j);

constexpr float fabs(float x);
constexpr double fabs(double x);
constexpr long double fabs(long double x);
constexpr float fabsf(float x);
constexpr long double fabsl(long double x);

float hypot(float x, float y);
double hypot(double x, double y);
long double hypot(long double x, long double y);
float hypotf(float x, float y);
long double hypotl(long double x, long double y);

// three-dimensional hypotenuse
float hypot(float x, float y, float z);
double hypot(double x, double y, double z);
long double hypot(long double x, long double y, long double z);

float pow(float x, float y);
double pow(double x, double y);
long double pow(long double x, long double y);
float powf(float x, float y);
long double powl(long double x, long double y);

float sqrt(float x);
double sqrt(double x);
long double sqrt(long double x);
float sqrtf(float x);
long double sqrtl(long double x);

float erf(float x);
double erf(double x);
long double erf(long double x);
float erff(float x);
long double erfl(long double x);

float erfc(float x);
double erfc(double x);
long double erfc(long double x);
float erfcf(float x);
long double erfcl(long double x);

float lgamma(float x);
double lgamma(double x);
long double lgamma(long double x);
float lgammaf(float x);
long double lgammal(long double x);

float tgamma(float x);
double tgamma(double x);
long double tgamma(long double x);
float tgammaf(float x);
long double tgammal(long double x);

constexpr float ceil(float x);
constexpr double ceil(double x);
constexpr long double ceil(long double x);
constexpr float ceilf(float x);
constexpr long double ceill(long double x);

constexpr float floor(float x);
constexpr double floor(double x);
constexpr long double floor(long double x);
constexpr float floorf(float x);
constexpr long double floorl(long double x);

float nearbyint(float x);
double nearbyint(double x);
long double nearbyint(long double x);
float nearbyintf(float x);
long double nearbyintl(long double x);

float rint(float x);
double rint(double x);
long double rint(long double x);
float rintf(float x);
long double rintl(long double x);

long int lrint(float x);
long int lrint(double x);
long int lrint(long double x);
long int lrintf(float x);
long int lrintl(long double x);

long long int llrint(float x);
long long int llrint(double x);
long long int llrint(long double x);
long long int llrintf(float x);
long long int llrintl(long double x);

constexpr float round(float x);
constexpr double round(double x);
constexpr long double round(long double x);
constexpr float roundf(float x);
constexpr long double roundl(long double x);

constexpr long int lround(float x);
constexpr long int lround(double x);
constexpr long int lround(long double x);
constexpr long int lroundf(float x);
constexpr long int lroundl(long double x);

constexpr long long int llround(float x);
constexpr long long int llround(double x);
constexpr long long int llround(long double x);
constexpr long long int llroundf(float x);
constexpr long long int llroundl(long double x);

constexpr float trunc(float x);
constexpr double trunc(double x);
constexpr long double trunc(long double x);
constexpr float truncf(float x);
constexpr long double truncl(long double x);

constexpr float fmod(float x, float y);
constexpr double fmod(double x, double y);
constexpr long double fmod(long double x, long double y);
constexpr float fmodf(float x, float y);
constexpr long double fmodl(long double x, long double y);

constexpr float remainder(float x, float y);
constexpr double remainder(double x, double y);
constexpr long double remainder(long double x, long double y);
constexpr float remainderf(float x, float y);
constexpr long double remainderl(long double x, long double y);

constexpr float remquo(float x, float y, int* quo);
constexpr double remquo(double x, double y, int* quo);
constexpr long double remquo(long double x, long double y, int* quo);
constexpr float remquof(float x, float y, int* quo);
constexpr long double remquol(long double x, long double y, int* quo);

constexpr float copysign(float x, float y);
constexpr double copysign(double x, double y);
constexpr long double copysign(long double x, long double y);
constexpr float copysignf(float x, float y);
constexpr long double copysignl(long double x, long double y);

double nan(const char* tagp);
float nanf(const char* tagp);
long double nanl(const char* tagp);

constexpr float nextafter(float x, float y);
constexpr double nextafter(double x, double y);
constexpr long double nextafter(long double x, long double y);
constexpr float nextafterf(float x, float y);
constexpr long double nextafterl(long double x, long double y);

constexpr float nexttoward(float x, long double y);
constexpr double nexttoward(double x, long double y);
constexpr long double nexttoward(long double x, long double y);
constexpr float nexttowardf(float x, long double y);
constexpr long double nexttowardl(long double x, long double y);

constexpr float fdim(float x, float y);
constexpr double fdim(double x, double y);
constexpr long double fdim(long double x, long double y);
constexpr float fdimf(float x, float y);
constexpr long double fdiml(long double x, long double y);

constexpr float fmax(float x, float y);
constexpr double fmax(double x, double y);
constexpr long double fmax(long double x, long double y);
constexpr float fmaxf(float x, float y);
constexpr long double fmaxl(long double x, long double y);

constexpr float fmin(float x, float y);
constexpr double fmin(double x, double y);
constexpr long double fmin(long double x, long double y);
constexpr float fminf(float x, float y);
constexpr long double fminl(long double x, long double y);

constexpr float fma(float x, float y, float z);
constexpr double fma(double x, double y, double z);
constexpr long double fma(long double x, long double y, long double z);
constexpr float fmaf(float x, float y, float z);
constexpr long double fmal(long double x, long double y, long double z);

// linear interpolation
constexpr float lerp(float a, float b, float t) noexcept;
constexpr double lerp(double a, double b, double t) noexcept;
constexpr long double lerp(long double a, long double b, long double t) noexcept;

// classification / comparison functions
constexpr int fpclassify(float x);
constexpr int fpclassify(double x);
constexpr int fpclassify(long double x);

constexpr bool isfinite(float x);
constexpr bool isfinite(double x);
constexpr bool isfinite(long double x);

constexpr bool isinf(float x);
constexpr bool isinf(double x);
constexpr bool isinf(long double x);

constexpr bool isnan(float x);
constexpr bool isnan(double x);
constexpr bool isnan(long double x);

constexpr bool isnormal(float x);
constexpr bool isnormal(double x);
constexpr bool isnormal(long double x);

constexpr bool signbit(float x);
constexpr bool signbit(double x);
constexpr bool signbit(long double x);

constexpr bool isgreater(float x, float y);
constexpr bool isgreater(double x, double y);
constexpr bool isgreater(long double x, long double y);

constexpr bool isgreaterequal(float x, float y);
constexpr bool isgreaterequal(double x, double y);
constexpr bool isgreaterequal(long double x, long double y);

constexpr bool isless(float x, float y);
constexpr bool isless(double x, double y);
constexpr bool isless(long double x, long double y);

constexpr bool islessequal(float x, float y);
constexpr bool islessequal(double x, double y);
constexpr bool islessequal(long double x, long double y);

constexpr bool islessgreater(float x, float y);
constexpr bool islessgreater(double x, double y);
constexpr bool islessgreater(long double x, long double y);

constexpr bool isunordered(float x, float y);
constexpr bool isunordered(double x, double y);
constexpr bool isunordered(long double x, long double y);

// mathematical special functions

// associated Laguerre polynomials
double assoc_laguerre(unsigned n, unsigned m, double x);
float assoc_laguerref(unsigned n, unsigned m, float x);
long double assoc_laguerrel(unsigned n, unsigned m, long double x);

// associated Legendre functions
double assoc_legendre(unsigned l, unsigned m, double x);
float assoc_legendref(unsigned l, unsigned m, float x);
long double assoc_legendrel(unsigned l, unsigned m, long double x);

// beta function
double beta(double x, double y);
float betaf(float x, float y);
long double betal(long double x, long double y);

// complete elliptic integral of the first kind
double comp_ellint_1(double k);
float comp_ellint_1f(float k);
long double comp_ellint_1l(long double k);

// complete elliptic integral of the second kind
double comp_ellint_2(double k);
float comp_ellint_2f(float k);
long double comp_ellint_2l(long double k);

// complete elliptic integral of the third kind
double comp_ellint_3(double k, double nu);
float comp_ellint_3f(float k, float nu);
long double comp_ellint_3l(long double k, long double nu);

// regular modified cylindrical Bessel functions
double cyl_bessel_i(double nu, double x);
float cyl_bessel_if(float nu, float x);
long double cyl_bessel_il(long double nu, long double x);

// cylindrical Bessel functions of the first kind
double cyl_bessel_j(double nu, double x);
float cyl_bessel_jf(float nu, float x);
long double cyl_bessel_jl(long double nu, long double x);

// irregular modified cylindrical Bessel functions
double cyl_bessel_k(double nu, double x);
float cyl_bessel_kf(float nu, float x);
long double cyl_bessel_kl(long double nu, long double x);

// cylindrical Neumann functions;
// cylindrical Bessel functions of the second kind
double cyl_neumann(double nu, double x);
float cyl_neumannf(float nu, float x);
long double cyl_neumannl(long double nu, long double x);

// incomplete elliptic integral of the first kind
double ellint_1(double k, double phi);
float ellint_1f(float k, float phi);
long double ellint_1l(long double k, long double phi);

// incomplete elliptic integral of the second kind
double ellint_2(double k, double phi);
float ellint_2f(float k, float phi);
long double ellint_2l(long double k, long double phi);

// incomplete elliptic integral of the third kind
double ellint_3(double k, double nu, double phi);
float ellint_3f(float k, float nu, float phi);
long double ellint_3l(long double k, long double nu, long double phi);

// exponential integral
double expint(double x);
float expintf(float x);
long double expintl(long double x);

// Hermite polynomials
double hermite(unsigned n, double x);
float hermitef(unsigned n, float x);
long double hermitel(unsigned n, long double x);

// Laguerre polynomials
double laguerre(unsigned n, double x);
float laguerref(unsigned n, float x);
long double laguerrel(unsigned n, long double x);

// Legendre polynomials
double legendre(unsigned l, double x);
float legendref(unsigned l, float x);
long double legendrel(unsigned l, long double x);

// Riemann zeta function
double riemann_zeta(double x);
float riemann_zetaf(float x);
long double riemann_zetal(long double x);

// spherical Bessel functions of the first kind
double sph_bessel(unsigned n, double x);
float sph_besself(unsigned n, float x);
long double sph_bessell(unsigned n, long double x);

// spherical associated Legendre functions
double sph_legendre(unsigned l, unsigned m, double theta);
float sph_legendref(unsigned l, unsigned m, float theta);
long double sph_legendrel(unsigned l, unsigned m, long double theta);

// spherical Neumann functions;
// spherical Bessel functions of the second kind
double sph_neumann(unsigned n, double x);
float sph_neumannf(unsigned n, float x);
long double sph_neumannl(unsigned n, long double x);

}

#endif
