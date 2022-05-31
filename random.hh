// ywstd/random.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <random>
#else

#include "@/../concepts.hh"
#include "@/../initializer_list.hh"
#include "@/../cstdint.hh"
#include "@/../limits.hh"
#include "@/../vector.hh"
#include "@/../@/basic_string.hh"

namespace std {

namespace _ {
  template<typename Ty, Ty Vx> inline constexpr size_t engine_max = _::bit_size<Ty> ? numeric_limits<Ty>::max() : (1 << Vx) - 1;
}

template<typename Ct, typename Tr> class basic_istream;
template<typename Ct, typename Tr> class basic_ostream;

template<typename Gn> concept uniform_random_bit_generator =
    invocable<Gn&> && unsigned_integral<invoke_result_t<Gn&>> &&
    requires { { Gn::min() } -> same_as<invoke_result_t<Gn&>>;
               { Gn::max() } -> same_as<invoke_result_t<Gn&>>;
               requires bool_constant<(Gn::min() < Gn::max())>::value; };

template<typename Nat, Nat Ax, Nat Cx, Nat Mx> class linear_congruential_engine {
public:
  using result_type = Nat;
  static constexpr result_type multiplier = Ax;
  static constexpr result_type increment = Cx;
  static constexpr result_type modulus = Mx;
  static constexpr result_type default_seed = 1u;
  static constexpr result_type min() { return Cx == 0u ? 1u : 0u; }
  static constexpr result_type max() { return Mx - 1u; }

  linear_congruential_engine() : linear_congruential_engine(default_seed) {}
  explicit linear_congruential_engine(result_type s);
  template<typename SeedSq> explicit linear_congruential_engine(SeedSq& q);

  void seed(result_type s = default_seed);
  template<typename SeedSq> void seed(SeedSq& q);
  void discard(unsigned long long);

  result_type operator()();
  friend bool operator==(const linear_congruential_engine& x, const linear_congruential_engine& y);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const linear_congruential_engine& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, linear_congruential_engine& x);
};

template<typename Nat, size_t Wx, size_t Nx, size_t Mx, size_t Rx, Nat Ax, size_t Ux, Nat Dx, size_t Sx, Nat Bx, size_t Tx, Nat Cx, size_t Lx, Nat Fx>
class mersenne_twister_engine {
public:
  using result_type = Nat;
  static constexpr size_t word_size = Wx;
  static constexpr size_t state_size = Nx;
  static constexpr size_t shift_size = Mx;
  static constexpr size_t mask_bits = Rx;
  static constexpr Nat xor_mask = Ax;
  static constexpr size_t tempering_u = Ux;
  static constexpr Nat tempering_d = Dx;
  static constexpr size_t tempering_s = Sx;
  static constexpr Nat tempering_b = Bx;
  static constexpr size_t tempering_t = Tx;
  static constexpr Nat tempering_c = Cx;
  static constexpr size_t tempering_l = Lx;
  static constexpr Nat initialization_multiplier = Fx;
  static constexpr result_type default_seed = 5489u;
  static constexpr result_type min() { return 0; }
  static constexpr result_type max() { return _::engine_max<Nat, Wx>; }

  mersenne_twister_engine() : mersenne_twister_engine(default_seed) {}
  explicit mersenne_twister_engine(result_type value);
  template<typename SeedSq> explicit mersenne_twister_engine(SeedSq& q);

  void seed(result_type value = default_seed);
  template<typename SeedSq> void seed(SeedSq& q);
  void discard(unsigned long long z);

  result_type operator()();
  friend bool operator==(const mersenne_twister_engine& x, const mersenne_twister_engine& y);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const mersenne_twister_engine& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, mersenne_twister_engine& x);
};

template<typename Nat, size_t Wx, size_t Sx, size_t Rx> class subtract_with_carry_engine {
public:
  using result_type = Nat;
  static constexpr size_t word_size = Wx;
  static constexpr size_t short_lag = Sx;
  static constexpr size_t long_lag = Rx;
  static constexpr result_type default_seed = 19780503u;
  static constexpr result_type min() { return 0; }
  static constexpr result_type max() {return _::engine_max<Nat, Wx>; }

  subtract_with_carry_engine() : subtract_with_carry_engine(default_seed) {}
  explicit subtract_with_carry_engine(result_type value);
  template<typename SeedSq> explicit subtract_with_carry_engine(SeedSq& q);

  void seed(result_type value = default_seed);
  template<typename SeedSq> void seed(SeedSq& q);
  void discard(unsigned long long z);

  result_type operator()();
  friend bool operator==(const subtract_with_carry_engine& x, const subtract_with_carry_engine& y);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const subtract_with_carry_engine& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, subtract_with_carry_engine& x);
};

template<typename Engine, size_t Px, size_t Rx> class discard_block_engine {
  Engine e;
  int n;
public:
  using result_type = typename Engine::result_type;
  static constexpr size_t block_size = Px;
  static constexpr size_t used_block = Rx;
  static constexpr result_type min() { return Engine::min(); }
  static constexpr result_type max() { return Engine::max(); }

  discard_block_engine();
  explicit discard_block_engine(const Engine& e);
  explicit discard_block_engine(Engine&& e);
  explicit discard_block_engine(result_type s);
  template<typename SeedSq> explicit discard_block_engine(SeedSq& q);

  void seed();
  void seed(result_type s);
  template<typename SeedSq> void seed(SeedSq& q);
  void discard(unsigned long long z);
  const Engine& base() const noexcept { return e; };

  result_type operator()();
  friend bool operator==(const discard_block_engine& x, const discard_block_engine& y);

  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const discard_block_engine& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, discard_block_engine& x);
};

template<typename Engine, size_t Wx, typename Nat> class independent_bits_engine {
  Engine e;
public:
  using result_type = Nat;
  static constexpr result_type min() { return 0; }
  static constexpr result_type max() { return _::engine_max<Nat, Wx>; }

  independent_bits_engine();
  explicit independent_bits_engine(const Engine& e);
  explicit independent_bits_engine(Engine&& e);
  explicit independent_bits_engine(result_type s);
  template<typename SeedSq> explicit independent_bits_engine(SeedSq& q);

  void seed();
  void seed(result_type s);
  template<typename SeedSq> void seed(SeedSq& q);
  void discard(unsigned long long z);
  const Engine& base() const noexcept { return e; };

  result_type operator()();
  friend bool operator==(const independent_bits_engine& x, const independent_bits_engine& y);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const independent_bits_engine& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, independent_bits_engine& x);
};

template<typename Engine, size_t Kx> class shuffle_order_engine {
  Engine e;
  typename Engine::result_type v[Kx];
  typename Engine::result_type y;
public:
  using result_type = typename Engine::result_type;
  static constexpr size_t table_size = Kx;
  static constexpr result_type min() { return Engine::min(); }
  static constexpr result_type max() { return Engine::max(); }

  shuffle_order_engine();
  explicit shuffle_order_engine(const Engine& e);
  explicit shuffle_order_engine(Engine&& e);
  explicit shuffle_order_engine(result_type s);
  template<typename SeedSq> explicit shuffle_order_engine(SeedSq& q);

  void seed();
  void seed(result_type s);
  template<typename SeedSq> void seed(SeedSq& q);
  void discard(unsigned long long z);
  const Engine& base() const noexcept { return e; };

  result_type operator()();
  friend bool operator==(const shuffle_order_engine& x, const shuffle_order_engine& y);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const shuffle_order_engine& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, shuffle_order_engine& x);
};

using minstd_rand0 = linear_congruential_engine<uint_fast32_t, 16807, 0, 2147483647>;
using minstd_rand = linear_congruential_engine<uint_fast32_t, 48271, 0, 2147483647>;
using mt19937 = mersenne_twister_engine<uint_fast32_t, 32, 624, 397, 31, 0x9908b0df, 11, 0xffffffff, 7, 0x9d2c5680, 15, 0xefc60000, 18, 1812433253>;
using mt19937_64 = mersenne_twister_engine<
  uint_fast64_t, 64, 312, 156, 31, 0xb5026f5aa96619e9, 29, 0x5555555555555555, 17, 0x71d67fffeda60000, 37, 0xfff7eee000000000, 43, 6364136223846793005>;
using ranlux24_base = subtract_with_carry_engine<uint_fast32_t, 24, 10, 24>;
using ranlux48_base = subtract_with_carry_engine<uint_fast64_t, 48, 5, 12>;
using ranlux24 = discard_block_engine<ranlux24_base, 223, 23>;
using ranlux48 = discard_block_engine<ranlux48_base, 389, 11>;
using knuth_b = shuffle_order_engine<minstd_rand0, 256>;
using default_random_engine = mt19937;

class random_device {
public:
  using result_type = unsigned int;
  static constexpr result_type min() { return numeric_limits<result_type>::min(); }
  static constexpr result_type max() { return numeric_limits<result_type>::max(); }

  random_device();
  explicit random_device(const string& token);
  random_device(const random_device&) = delete;
  void operator=(const random_device&) = delete;

  double entropy() const noexcept;
  result_type operator()();
};

class seed_seq {
  vector<uint_least32_t> v;
public:
  using result_type = uint_least32_t;

  seed_seq() noexcept;
  template<typename Ty> seed_seq(initializer_list<Ty> il);
  template<typename InpIt> seed_seq(InpIt begin, InpIt end);
  seed_seq(const seed_seq&) = delete;
  void operator=(const seed_seq&) = delete;

  size_t size() const noexcept;
  template<typename RnbIt> void generate(RnbIt begin, RnbIt end);
  template<typename OutIt> void param(OutIt dest) const;
};

template<typename Fat, size_t Bits, typename Gn> Fat generate_canonical(Gn& g);

template<typename Int = int> class uniform_int_distribution {
public:
  using result_type = Int;

  struct param_type {
    using distribution_type = uniform_int_distribution;
    param_type();
    explicit param_type(result_type Ax, result_type Bx = 9);
    friend bool operator==(const param_type& x, const param_type& y);
    result_type a() const;
    result_type b() const;
  };

  uniform_int_distribution() : uniform_int_distribution(0) {}
  explicit uniform_int_distribution(Int a, Int b = numeric_limits<Int>::max());
  explicit uniform_int_distribution(const param_type& parm);

  void reset();
  result_type a() const;
  result_type b() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const uniform_int_distribution& x, const uniform_int_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const uniform_int_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, uniform_int_distribution& x);
};

template<typename Fat = double> class uniform_real_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = uniform_real_distribution;
    param_type();
    explicit param_type(Fat Ax, Fat Bx = Fat{1});
    friend bool operator==(const param_type& x, const param_type& y);
    result_type a() const;
    result_type b() const;
  };

  uniform_real_distribution() : uniform_real_distribution(0.0) {}
  explicit uniform_real_distribution(Fat a, Fat b = 1.0);
  explicit uniform_real_distribution(const param_type& parm);

  void reset();
  result_type a() const;
  result_type b() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const uniform_real_distribution& x, const uniform_real_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const uniform_real_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, uniform_real_distribution& x);
};

class bernoulli_distribution {
public:
  using result_type = bool;

  struct param_type {
    using distribution_type = bernoulli_distribution;
    param_type();
    explicit param_type(double Px);
    friend bool operator==(const param_type& x, const param_type& y);
    double p() const;
  };

  bernoulli_distribution() : bernoulli_distribution(0.5) {}
  explicit bernoulli_distribution(double p);
  explicit bernoulli_distribution(const param_type& parm);

  void reset();
  double p() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const bernoulli_distribution& x, const bernoulli_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const bernoulli_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, bernoulli_distribution& x);
};

template<typename Int = int> class binomial_distribution {
public:
  using result_type = Int;

  struct param_type {
    using distribution_type = binomial_distribution;
    param_type();
    explicit param_type(Int Tx, double Px = 0.5);
    friend bool operator==(const param_type& x, const param_type& y);
    Int t() const;
    double p() const;
  };

  binomial_distribution() : binomial_distribution(1) {}
  explicit binomial_distribution(Int t, double p = 0.5);
  explicit binomial_distribution(const param_type& parm);

  void reset();
  Int t() const;
  double p() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const binomial_distribution& x, const binomial_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);

  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const binomial_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, binomial_distribution& x);
};

template<typename Int = int> class geometric_distribution {
public:
  using result_type = Int;

  struct param_type {
    using distribution_type = geometric_distribution;
    param_type();
    explicit param_type(double Px);
    friend bool operator==(const param_type& x, const param_type& y);
    double p() const;
  };

  geometric_distribution() : geometric_distribution(0.5) {}
  explicit geometric_distribution(double p);
  explicit geometric_distribution(const param_type& parm);

  void reset();
  double p() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const geometric_distribution& x, const geometric_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const geometric_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, geometric_distribution& x);
};

template<typename Int = int> class negative_binomial_distribution {
public:
  using result_type = Int;

  struct param_type {
    using distribution_type = negative_binomial_distribution;
    param_type();
    explicit param_type(Int Kx, double Px = 0.5);
    friend bool operator==(const param_type& x, const param_type& y);
    Int k() const;
    double p() const;
  };

  negative_binomial_distribution() : negative_binomial_distribution(1) {}
  explicit negative_binomial_distribution(Int k, double p = 0.5);
  explicit negative_binomial_distribution(const param_type& parm);

  void reset();
  Int k() const;
  double p() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const negative_binomial_distribution& x, const negative_binomial_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const negative_binomial_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, negative_binomial_distribution& x);
};

template<typename Int = int> class poisson_distribution {
public:
  using result_type = Int;

  struct param_type {
    using distribution_type = poisson_distribution;
    param_type();
    explicit param_type(double Mean);
    friend bool operator==(const param_type& x, const param_type& y);
    double mean() const;
  };

  poisson_distribution() : poisson_distribution(1.0) {}
  explicit poisson_distribution(double mean);
  explicit poisson_distribution(const param_type& parm);

  void reset();
  double mean() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const poisson_distribution& x, const poisson_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const poisson_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, poisson_distribution& x);
};

template<typename Fat = double> class exponential_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = exponential_distribution;
    param_type();
    explicit param_type(Fat Lambda);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat lambda() const;
  };

  exponential_distribution() : exponential_distribution(1.0) {}
  explicit exponential_distribution(Fat lambda);
  explicit exponential_distribution(const param_type& parm);

  void reset();
  Fat lambda() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const exponential_distribution& x, const exponential_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const exponential_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, exponential_distribution& x);
};

template<typename Fat = double> class gamma_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = gamma_distribution;
    param_type();
    explicit param_type(Fat Alpha, Fat Beta = 1.0);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat alpha() const;
    Fat beta() const;
  };

  gamma_distribution() : gamma_distribution(1.0) {}
  explicit gamma_distribution(Fat alpha, Fat beta = 1.0);
  explicit gamma_distribution(const param_type& parm);

  void reset();
  Fat alpha() const;
  Fat beta() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const gamma_distribution& x, const gamma_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const gamma_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, gamma_distribution& x);
};

template<typename Fat = double> class weibull_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = weibull_distribution;
    param_type();
    explicit param_type(Fat Ax, Fat Bx = 1.0);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat a() const;
    Fat b() const;
  };

  weibull_distribution() : weibull_distribution(1.0) {}
  explicit weibull_distribution(Fat a, Fat b = 1.0);
  explicit weibull_distribution(const param_type& parm);

  void reset();
  Fat a() const;
  Fat b() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const weibull_distribution& x, const weibull_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const weibull_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, weibull_distribution& x);
};

template<typename Fat = double> class extreme_value_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = extreme_value_distribution;
    param_type();
    explicit param_type(Fat Ax, Fat Bx = 1.0);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat a() const;
    Fat b() const;
  };

  extreme_value_distribution() : extreme_value_distribution(0.0) {}
  explicit extreme_value_distribution(Fat a, Fat b = 1.0);
  explicit extreme_value_distribution(const param_type& parm);

  void reset();
  Fat a() const;
  Fat b() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const extreme_value_distribution& x, const extreme_value_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const extreme_value_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, extreme_value_distribution& x);
};

template<typename Fat = double> class normal_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = normal_distribution;
    param_type();
    explicit param_type(Fat Mean, Fat Stddev = 1.0);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat mean() const;
    Fat stddev() const;
  };

  normal_distribution() : normal_distribution(0.0) {}
  explicit normal_distribution(Fat mean, Fat stddev = 1.0);
  explicit normal_distribution(const param_type& parm);

  void reset();
  Fat mean() const;
  Fat stddev() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const normal_distribution& x, const normal_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const normal_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, normal_distribution& x);
};

template<typename Fat = double> class lognormal_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = lognormal_distribution;
    param_type();
    explicit param_type(Fat Mx, Fat Sx = 1.0);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat m() const;
    Fat s() const;
  };

  lognormal_distribution() : lognormal_distribution(0.0) {}
  explicit lognormal_distribution(Fat m, Fat s = 1.0);
  explicit lognormal_distribution(const param_type& parm);

  void reset();
  Fat m() const;
  Fat s() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const lognormal_distribution& x, const lognormal_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const lognormal_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, lognormal_distribution& x);
};

template<typename Fat = double> class chi_squared_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = chi_squared_distribution;
    param_type();
    explicit param_type(Fat Nx);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat n() const;
  };

  chi_squared_distribution() : chi_squared_distribution(1.0) {}
  explicit chi_squared_distribution(Fat n);
  explicit chi_squared_distribution(const param_type& parm);

  void reset();
  Fat n() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const chi_squared_distribution& x, const chi_squared_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const chi_squared_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, chi_squared_distribution& x);
};

template<typename Fat = double> class cauchy_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = cauchy_distribution;
    param_type();
    explicit param_type(Fat Ax, Fat Bx = 1.0);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat a() const;
    Fat b() const;
  };

  cauchy_distribution() : cauchy_distribution(0.0) {}
  explicit cauchy_distribution(Fat a, Fat b = 1.0);
  explicit cauchy_distribution(const param_type& parm);

  void reset();
  Fat a() const;
  Fat b() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const cauchy_distribution& x, const cauchy_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const cauchy_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, cauchy_distribution& x);
};

template<typename Fat = double> class fisher_f_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = fisher_f_distribution;
    param_type();
    explicit param_type(Fat Mx, Fat Nx = 1.0);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat m() const;
    Fat n() const;
  };

  fisher_f_distribution() : fisher_f_distribution(1.0) {}
  explicit fisher_f_distribution(Fat m, Fat n = 1.0);
  explicit fisher_f_distribution(const param_type& parm);

  void reset();
  Fat m() const;
  Fat n() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const fisher_f_distribution& x, const fisher_f_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const fisher_f_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, fisher_f_distribution& x);
};

template<typename Fat = double> class student_t_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = student_t_distribution;
    param_type();
    explicit param_type(Fat Nx);
    friend bool operator==(const param_type& x, const param_type& y);
    Fat n() const;
  };

  student_t_distribution() : student_t_distribution(1.0) {}
  explicit student_t_distribution(Fat n);
  explicit student_t_distribution(const param_type& parm);

  void reset();
  Fat n() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const student_t_distribution& x, const student_t_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const student_t_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, student_t_distribution& x);
};

template<typename Int = int> class discrete_distribution {
public:
  using result_type = Int;

  struct param_type {
    using distribution_type = discrete_distribution;
    param_type();
    template<typename InpIt> param_type(InpIt i, InpIt s);
    param_type(initializer_list<double>);
    template<typename Fn> param_type(size_t Count, double Min, double Max, Fn Func);
    friend bool operator==(const param_type& x, const param_type& y);
    vector<double> probabilities() const;
  };

  // constructors and reset functions
  discrete_distribution();
  template<typename InpIt>
  discrete_distribution(InpIt firstW, InpIt lastW);
  discrete_distribution(initializer_list<double> wl);
  template<typename Fn> discrete_distribution(size_t Count, double Min, double Max, Fn Func);
  explicit discrete_distribution(const param_type& parm);

  void reset();
  vector<double> probabilities() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const discrete_distribution& x, const discrete_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const discrete_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, discrete_distribution& x);
};

template<typename Fat = double> class piecewise_constant_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = piecewise_constant_distribution;
    param_type();
    template<typename InpItB, typename InpItW> param_type(InpItB FirstB, InpItB LastB, InpItW FirstW, InpItW LastW);
    template<typename Fn> param_type(initializer_list<result_type>, Fn Func);
    template<typename Fn> param_type(size_t Count, double Min, double Max, Fn Func);
    friend bool operator==(const param_type& x, const param_type& y);
    vector<result_type> intervals() const;
    vector<result_type> densities() const;
  };

  piecewise_constant_distribution();
  template<typename InpItB, typename InpItW> piecewise_constant_distribution(InpItB firstB, InpItB lastB, InpItW firstW);
  template<typename Fn> piecewise_constant_distribution(initializer_list<result_type> bl, Fn fw);
  template<typename Fn> piecewise_constant_distribution(size_t Count, result_type Min, result_type Max, Fn Func);
  explicit piecewise_constant_distribution(const param_type& parm);

  void reset();
  vector<result_type> intervals() const;
  vector<result_type> densities() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const piecewise_constant_distribution& x, const piecewise_constant_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const piecewise_constant_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, piecewise_constant_distribution& x);
};

template<typename Fat = double> class piecewise_linear_distribution {
public:
  using result_type = Fat;

  struct param_type {
    using distribution_type = piecewise_linear_distribution;
    param_type();
    template<typename InpItB, typename InpItW> param_type(InpItB FirstB, InpItB LastB, InpItW FirstW, InpItW LastW);
    template<typename Fn> param_type(initializer_list<result_type>, Fn Func);
    template<typename Fn> param_type(size_t Count, double Min, double Max, Fn Func);
    friend bool operator==(const param_type& x, const param_type& y);
    vector<result_type> intervals() const;
    vector<result_type> densities() const;
  };

  piecewise_linear_distribution();
  template<typename InpItB, typename InpItW> piecewise_linear_distribution(InpItB firstB, InpItB lastB, InpItW firstW);
  template<typename Fn> piecewise_linear_distribution(initializer_list<Fat> List, Fn Func);
  template<typename Fn> piecewise_linear_distribution(size_t Count, Fat Min, Fat Max, Fn Func);
  explicit piecewise_linear_distribution(const param_type& parm);

  void reset();
  vector<result_type> intervals() const;
  vector<result_type> densities() const;
  param_type param() const;
  void param(const param_type& parm);
  result_type min() const;
  result_type max() const;

  friend bool operator==(const piecewise_linear_distribution& x, const piecewise_linear_distribution& y);
  template<typename Gn> result_type operator()(Gn& g);
  template<typename Gn> result_type operator()(Gn& g, const param_type& parm);
  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const piecewise_linear_distribution& x);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, piecewise_linear_distribution& x);
};

}

#endif
