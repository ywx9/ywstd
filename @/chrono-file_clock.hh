// ywstd/@/chrono-file_clock.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/../limits.hh"
#include "../@/../ratio.hh"
#include "../@/_.hh"
#include "../@/common_type.hh"
#include "../@/integral_constant.hh"

namespace std {

using time_t = decltype((int*)0 - (int*)0);

namespace chrono {
  template<typename Rep, typename Period> class duration;
  template<typename Clock, typename Duration> class time_point;
  struct system_clock;
  struct utc_clock;
  struct file_clock;
  template<typename Duration> using sys_time = time_point<system_clock, Duration>;
  template<typename Duration> using utc_time = time_point<utc_clock, Duration>;
  template<typename Duration> using file_time = time_point<file_clock, Duration>;
}

namespace _ {
  template<typename To, typename Rep, typename Period>
  constexpr To duration_cast(const chrono::duration<Rep, Period>& d)
    noexcept(is_arithmetic_v<Rep> && is_arithmetic_v<typename To::rep>);
}

}

namespace std::chrono {

template<typename Rep> struct treat_as_floating_point : bool_constant<_::is_floating_point_v<Rep>> {};
template<typename Rep> inline constexpr bool treat_as_floating_point_v = treat_as_floating_point<Rep>::value;

template<typename Rep> struct duration_values {
  static constexpr Rep zero() noexcept { return Rep(0); }
  static constexpr Rep min() noexcept { return numeric_limits<Rep>::lowest(); }
  static constexpr Rep max() noexcept { return numeric_limits<Rep>::max(); }
};

template<typename Rep, typename Period = ratio<1>> class duration {
  static_assert(!_::specialized_of<Rep, duration>);
  static_assert(_::ratio_specialization<Period>);
  static_assert(0 < Period::num);

  Rep _value;
public:
  using rep = Rep;
  using period = typename Period::type;

  static constexpr duration max() noexcept { return duration_values<rep>::max(); }
  static constexpr duration min() noexcept { return duration_values<rep>::min(); }
  static constexpr duration zero() noexcept { return duration_values<rep>::zero(); }

  constexpr duration() = default;
  constexpr duration(const duration&) = default;

  template<typename R2>
  requires _::is_convertible_v<const R2&, Rep> &&
           (treat_as_floating_point<Rep>::value || !treat_as_floating_point<R2>::value)
  constexpr explicit duration(const R2& x) : _value{x} {}

  template<typename R2, typename P2>
  requires treat_as_floating_point<Rep>::value ||
           (ratio_divide<P2, Period>::den == 1 && !treat_as_floating_point<R2>::value)
  constexpr duration(const duration<R2, P2>& d) : _value{_::duration_cast<duration>(d)} {}

  constexpr rep count() const { return _value; }
  constexpr typename common_type<duration>::type operator+() const { return typename common_type<duration>::type{*this}; }
  constexpr typename common_type<duration>::type operator-() const { return typename common_type<duration>::type{-_value}; }
  constexpr duration& operator++() { ++_value; return *this; }
  constexpr duration& operator--() { --_value; return *this; }
  constexpr duration& operator+=(const duration& d) { _value += d.count(); return *this; }
  constexpr duration& operator-=(const duration& d) { _value -= d.count(); return *this; }
  constexpr duration& operator*=(const rep& r) { _value *= r; return *this; }
  constexpr duration& operator/=(const rep& r) { _value /= r; return *this; }
  constexpr duration& operator%=(const rep& r) { _value %= r; return *this; }
  constexpr duration& operator%=(const duration& d) { _value %= d.count(); return *this; }
  constexpr duration operator++(int) { return {_value++}; }
  constexpr duration operator--(int) { return {_value--}; }
};

template<typename Clock, typename Duration = typename Clock::duration>
class time_point {
  static_assert(_::specialized_of<Duration, chrono::duration>);
  Duration _dur;

public:
  using clock = Clock;
  using duration = Duration;
  using rep = typename duration::rep;
  using period = typename duration::period;

  constexpr time_point() = default;
  constexpr explicit time_point(const duration& d) : _dur{d} {}
  template<typename D2> constexpr time_point(const time_point<clock, D2>& t) : _dur{t.time_since_epoch()} {}

  constexpr duration time_since_epoch() const { return _dur; }

  constexpr time_point& operator++() { ++_dur; return *this; }
  constexpr time_point& operator--() { --_dur; return *this; }
  constexpr time_point& operator+=(const duration& d) { _dur += d; return +this; }
  constexpr time_point& operator-=(const duration& d) { _dur -= d; return +this; }
  constexpr time_point operator++(int) { return {_dur++}; }
  constexpr time_point operator--(int) { return {_dur--}; }

  static constexpr time_point max() noexcept { return {duration::max()}; }
  static constexpr time_point min() noexcept { return {duration::min()}; }
};

using seconds = duration<intmax_t>;

struct system_clock {
  using rep = intmax_t;
  using period = ratio<1, 10'000'000>; // 100 nanoseconds (from MSVC)
  using duration = chrono::duration<rep, period>;
  using time_point = chrono::time_point<system_clock>;
  static constexpr bool is_steady = false;
  static time_point now() noexcept;
  static time_t to_time_t(const time_point&);
  static time_point from_time_t(time_t);
};

class utc_clock {
public:
  using rep = typename system_clock::rep;
  using period = typename system_clock::period;
  using duration = chrono::duration<rep, period>;
  using time_point = chrono::time_point<utc_clock>;
  static constexpr bool is_steady = system_clock::is_steady;
  static time_point now();
  template<typename Duration> static sys_time<typename common_type<Duration, seconds>::type> to_sys(const utc_time<Duration>&);
  template<typename Duration> static utc_time<typename common_type<Duration, seconds>::type> from_sys(const sys_time<Duration>&);
};

struct file_clock {
  using rep = typename system_clock::rep;
  using period = typename system_clock::period;
  using duration = chrono::duration<rep, period>;
  using time_point = chrono::time_point<file_clock>;
  static constexpr bool is_steady = system_clock::is_steady;
  static time_point now();
  template<typename Duration> static utc_time<typename common_type<Duration, seconds>::type> to_utc(const file_time<Duration>&);
  template<typename Duration> static file_time<typename common_type<Duration, seconds>::type> from_utc(const utc_time<Duration>&);
};

}

namespace std {

template<typename R1, typename P1, typename R2, typename P2>
struct common_type<chrono::duration<R1, P1>, chrono::duration<R2, P2>>
  : type_identity<chrono::duration<typename common_type<R1, R2>::type, ratio<_::gcd(P1::num, P2::num), _::lcm(P1::den, P2::den)>>> {};

template<typename Clock, typename D1, typename D2>
struct common_type<chrono::time_point<Clock, D1>, chrono::time_point<Clock, D2>>
  : type_identity<chrono::time_point<Clock, typename common_type<D1, D2>::type>> {};

namespace _ {
  template<typename To, typename Rep, typename Period>
  constexpr To duration_cast(const chrono::duration<Rep, Period>& d) noexcept(is_arithmetic_v<Rep>&& is_arithmetic_v<typename To::rep>) {
    using TypeA = ratio_divide<Period, typename To::period>;
    using TypeB = typename To::rep;
    using TypeC = typename common_type<TypeB, Rep, intmax_t>::type;
    if (TypeA::den == 1) {
      if (TypeA::num == 1) return static_cast<To>(static_cast<TypeB>(d.count()));
      else return static_cast<To>(static_cast<TypeB>(static_cast<TypeC>(d.count()) * static_cast<TypeC>(TypeA::num)));
    } else {
      if (TypeA::num == 1) return static_cast<To>(static_cast<TypeB>(static_cast<TypeC>(d.count()) / static_cast<TypeC>(TypeA::den)));
      else return static_cast<To>(static_cast<TypeB>(static_cast<TypeC>(d.count()) * static_cast<TypeC>(TypeA::num) / static_cast<TypeC>(TypeA::den)));
    }
  }
}

}
