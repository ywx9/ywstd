// ywstd/chrono.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <chrono>
#else

#include "@/../compare.hh"
#include "@/../string_view.hh"
#include "@/../system_error.hh"
#include "@/../vector.hh"
#include "@/allocator.hh"
#include "@/basic_string.hh"
#include "@/chrono-file_clock.hh"

namespace std {

template<typename Ct, typename Tr> class basic_istream;
template<typename Ct, typename Tr> class basic_ostream;

using string = basic_string<char>;
using string_view = basic_string_view<char>;

}

namespace std::chrono {

using std::chrono::duration;
using std::chrono::duration_values;
using std::chrono::time_point;

using nanoseconds  = duration<intmax_t, ratio<1, 1000000000>>;
using microseconds = duration<intmax_t, ratio<1, 1000000>>;
using milliseconds = duration<intmax_t, ratio<1, 1000>>;
using seconds      = duration<intmax_t>;
using minutes      = duration<intmax_t, ratio<60>>;
using hours        = duration<intmax_t, ratio<3600>>;
using days         = duration<intmax_t, ratio<86400>>;
using weeks        = duration<intmax_t, ratio<604800>>;
using years        = duration<intmax_t, ratio<2629746>>;
using months       = duration<intmax_t, ratio<31556952>>;

using std::chrono::treat_as_floating_point;
using std::chrono::treat_as_floating_point_v;

template<typename Clock> struct is_clock : integral_constant<bool, false> {};
template<typename Clock> requires requires {
  typename Clock::rep; typename Clock::period; typename Clock::duration;
  typename Clock::time_point; Clock::is_steady; Clock::now(); }
struct is_clock<Clock> : integral_constant<bool, true> {};
template<typename Ty> inline constexpr bool is_clock_v = is_clock<Ty>::value;

// functions for duration

template<_::specialized_of<duration> To, typename Rep, typename Period>
constexpr To duration_cast(const duration<Rep, Period>& d) {
  return _::duration_cast<To>(d);
}
template<_::specialized_of<duration> To, typename Rep, typename Period>
constexpr To floor(const duration<Rep, Period>& d) {
  auto t = chrono::duration_cast<To>(d);
  return d < t ? t - To{1} : t;
}
template<_::specialized_of<duration> To, typename Rep, typename Period>
constexpr To ceil(const duration<Rep, Period>& d) {
  auto t = chrono::duration_cast<To>(d);
  return t < d ? t + To{1} : t;
}
template<typename To, typename Rep, typename Period>
constexpr To round(const duration<Rep, Period>& d) {
  auto t0 = chrono::floor<To>(d);
  auto t1 = t0 + To{1};
  auto d0 = d - t0;
  auto d1 = t1 - d;
  if (d0 == d1) return t0.count() & 1 ? t1 : t0;
  else if (d0 < d1) return t0;
  else return t1;
}
template<typename Rep, typename Period>
requires (duration<Rep, Period>::min() < duration<Rep, Period>::zero())
constexpr duration<Rep, Period> abs(duration<Rep, Period> d) {
  return d < d.zero() ? -d : d;
}

template<typename R1, typename P1, typename R2, typename P2>
constexpr typename common_type<duration<R1, P1>, duration<R2, P2>>::type
operator+(const duration<R1, P1>& x, const duration<R2, P2>& y) {
  using Type = typename common_type<duration<R1, P1>, duration<R2, P2>>::type;
  return Type{chrono::duration_cast<Type>(x).count() + chrono::duration_cast<Type>(y).count()};
}
template<typename R1, typename P1, typename R2, typename P2>
constexpr typename common_type<duration<R1, P1>, duration<R2, P2>>::type
operator-(const duration<R1, P1>& x, const duration<R2, P2>& y) {
  using Type = typename common_type<duration<R1, P1>, duration<R2, P2>>::type;
  return Type{chrono::duration_cast<Type>(x).count() - chrono::duration_cast<Type>(y).count()};
}
template<typename R1, typename Period, typename R2>
constexpr duration<typename common_type<R1, R2>::type, Period>
operator*(const duration<R1, Period>& d, const R2& s) {
  return {chrono::duration_cast<duration<typename common_type<R1, R2>::type, Period>>(d).count() * s};
}
template<typename R1, typename R2, typename Period>
constexpr duration<typename common_type<R1, R2>::type, Period>
operator*(const R1& s, const duration<R2, Period>& d) {
  return {chrono::duration_cast<duration<typename common_type<R1, R2>::type, Period>>(d).count() * s};
}
template<typename R1, typename Period, typename R2>
constexpr duration<typename common_type<R1, R2>::type, Period>
operator/(const duration<R1, Period>& d, const R2& s) {
  return {chrono::duration_cast<duration<typename common_type<R1, R2>::type, Period>>(d).count() / s};
}
template<typename R1, typename P1, typename R2, typename P2>
constexpr typename common_type<R1, R2>::type
operator/(const duration<R1, P1>& x, const duration<R2, P2>& y) {
  using Type = typename common_type<duration<R1, P1>, duration<R2, P2>>::type;
  return chrono::duration_cast<Type>(x).count() / chrono::duration_cast<Type>(y).count();
}
template<typename R1, typename Period, typename R2>
constexpr duration<typename common_type<R1, R2>::type, Period>
operator%(const duration<R1, Period>& d, const R2& s) {
  return {chrono::duration_cast<duration<typename common_type<R1, R2>::type, Period>>(d).count() % s};
}
template<typename R1, typename P1, typename R2, typename P2>
constexpr typename common_type<duration<R1, P1>, duration<R2, P2>>::type
operator%(const duration<R1, P1>& x, const duration<R2, P2>& y) {
  using Type = typename common_type<duration<R1, P1>, duration<R2, P2>>::type;
  return {chrono::duration_cast<Type>(x).count() % chrono::duration_cast<Type>(y).count()};
}

template<typename R1, typename P1, typename R2, typename P2>
constexpr bool operator==(const duration<R1, P1>& x, const duration<R2, P2>& y) {
  using Type = typename common_type<duration<R1, P1>, duration<R2, P2>>::type;
  return chrono::duration_cast<Type>(x).count() == chrono::duration_cast<Type>(y).count();
}
template<typename R1, typename P1, typename R2, typename P2>
constexpr bool operator<(const duration<R1, P1>& x, const duration<R2, P2>& y) {
  using Type = typename common_type<duration<R1, P1>, duration<R2, P2>>::type;
  return chrono::duration_cast<Type>(x).count() < chrono::duration_cast<Type>(y).count();
}
template<typename R1, typename P1, typename R2, typename P2>
constexpr bool operator>(const duration<R1, P1>& x, const duration<R2, P2>& y) { return y < x; }

template<typename R1, typename P1, typename R2, typename P2>
constexpr bool operator<=(const duration<R1, P1>& x, const duration<R2, P2>& y) { return !(y < x); }

template<typename R1, typename P1, typename R2, typename P2>
constexpr bool operator>=(const duration<R1, P1>& x, const duration<R2, P2>& y) { return !(x < y); }

template<typename R1, typename P1, typename R2, typename P2>
requires three_way_comparable<typename common_type<R1, R2>::type>
constexpr auto operator<=>(const duration<R1, P1>& x, const duration<R2, P2>& y) {
  using Type = typename common_type<duration<R1, P1>, duration<R2, P2>>::type;
  return chrono::duration_cast<Type>(x).count() <=> chrono::duration_cast<Type>(y).count();
}

template<typename Ct, typename Tr, typename Rep, typename Period>
basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const duration<Rep, Period>& d);

template<typename Ct, typename Tr, typename Rep, typename Period, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, duration<Rep, Period>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// time_point functions

template<typename To, typename Clock, typename Duration>
constexpr time_point<Clock, To> time_point_cast(const time_point<Clock, Duration>& t) {
  return {chrono::duration_cast<To>(t.time_since_epoch())};
}
template<typename To, typename Clock, typename Duration>
constexpr time_point<Clock, To> floor(const time_point<Clock, Duration>& t) {
  return {chrono::floor<To>(t.time_since_epoch())};
}
template<typename To, typename Clock, typename Duration>
constexpr time_point<Clock, To> ceil(const time_point<Clock, Duration>& t) {
  return {chrono::ceil<To>(t.time_since_epoch())};
}
template<typename To, typename Clock, typename Duration>
constexpr time_point<Clock, To> round(const time_point<Clock, Duration>& t) {
  return {chrono::round<To>(t.time_since_epoch())};
}

template<typename Clock, typename Duration, typename R2, typename P2>
constexpr time_point<Clock, typename common_type<Duration, duration<R2, P2>>::type>
operator+(const time_point<Clock, Duration>& t, const duration<R2, P2>& d) {
  return time_point<Clock, typename common_type<Duration, duration<R2, P2>>::type>{t.time_since_epoch() + d};
}
template<typename R1, typename P1, typename Clock, typename Duration>
constexpr time_point<Clock, typename common_type<duration<R1, P1>, Duration>::type>
operator+(const duration<R1, P1>& d, const time_point<Clock, Duration>& t) {
  return t + d;
}
template<typename Clock, typename Duration, typename R2, typename P2>
constexpr time_point<Clock, typename common_type<Duration, duration<R2, P2>>::type>
operator-(const time_point<Clock, Duration>& t, const duration<R2, P2>& d) {
  return time_point<Clock, typename common_type<Duration, duration<R2, P2>>::type>{t.time_since_epoch() - d};
}
template<typename Clock, typename D1, typename D2> constexpr typename common_type<D1, D2>::type
operator-(const time_point<Clock, D1>& x, const time_point<Clock, D2>& y) {
  return x.time_since_epoch() - y.time_since_epoch();
}

template<typename Clock, typename D1, typename D2>
constexpr bool operator==(const time_point<Clock, D1>& x, const time_point<Clock, D2>& y) {
  return x.time_since_epoch() == y.time_since_epoch();
}
template<typename Clock, typename D1, typename D2>
constexpr bool operator<(const time_point<Clock, D1>& x, const time_point<Clock, D2>& y) {
  return x.time_since_epoch() < y.time_since_epoch();
}
template<typename Clock, typename D1, typename D2>
constexpr bool operator>(const time_point<Clock, D1>& x, const time_point<Clock, D2>& y) {
  return y < x;
}
template<typename Clock, typename D1, typename D2>
constexpr bool operator<=(const time_point<Clock, D1>& x, const time_point<Clock, D2>& y) {
  return !(y < x);
}
template<typename Clock, typename D1, typename D2>
constexpr bool operator>=(const time_point<Clock, D1>& x, const time_point<Clock, D2>& y) {
  return !(x < y);
}
template<typename Clock, typename D1, three_way_comparable_with<D1> D2>
constexpr auto operator<=>(const time_point<Clock, D1>& x, const time_point<Clock, D2>& y) {
  return x.time_since_epoch() <=> y.time_since_epoch();
}

// system_clock

using std::chrono::system_clock;
using std::chrono::sys_time;
using sys_seconds = sys_time<seconds>;
using sys_days = sys_time<days>;

template<typename Ct, typename Tr, typename Duration> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const sys_time<Duration>& t);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const sys_days& dp);

template<typename Ct, typename Tr, typename Duration, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, sys_time<Duration>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// utc_clock

using std::chrono::utc_clock;
using std::chrono::utc_time;
using utc_seconds = utc_time<seconds>;

template<typename Ct, typename Tr, typename Duration> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const utc_time<Duration>& t);
template<typename Ct, typename Tr, typename Duration, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, utc_time<Duration>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// tai_clock

struct tai_clock;
template<typename Duration> using tai_time = time_point<tai_clock, Duration>;
using tai_seconds = tai_time<seconds>;

struct tai_clock {
  using rep        = typename system_clock::rep;
  using period     = typename system_clock::period;
  using duration   = chrono::duration<rep, period>;
  using time_point = chrono::time_point<tai_clock>;
  static constexpr bool is_steady = system_clock::is_steady;
  static time_point now();
  template<typename Duration> static sys_time<common_type_t<Duration, seconds>> to_sys(const tai_time<Duration>& t);
  template<typename Duration> static tai_time<common_type_t<Duration, seconds>> from_sys(const sys_time<Duration>& t);
};

template<typename Ct, typename Tr, typename Duration> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const tai_time<Duration>& t);
template<typename Ct, typename Tr, typename Duration, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, tai_time<Duration>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// gps_clock

struct gps_clock;
template<typename Duration> using gps_time = time_point<gps_clock, Duration>;
using gps_seconds = gps_time<seconds>;

struct gps_clock {
  using rep        = typename system_clock::rep;
  using period     = typename system_clock::period;
  using duration   = chrono::duration<rep, period>;
  using time_point = chrono::time_point<gps_clock>;
  static constexpr bool is_steady = system_clock::is_steady;
  static time_point now();
  template<typename Duration> static sys_time<common_type_t<Duration, seconds>> to_sys(const gps_time<Duration>& t);
  template<typename Duration> static gps_time<common_type_t<Duration, seconds>> from_sys(const sys_time<Duration>& t);
};

template<typename Ct, typename Tr, typename Duration> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const gps_time<Duration>& t);
template<typename Ct, typename Tr, typename Duration, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, gps_time<Duration>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// file_clock

using std::chrono::file_clock;
using std::chrono::file_time;

template<typename Ct, typename Tr, typename Duration> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const file_time<Duration>& t);
template<typename Ct, typename Tr, typename Duration, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, file_time<Duration>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// steady_clock

struct steady_clock {
  using rep        = long long;
  using period     = ratio<1, 1000000000>;
  using duration   = nanoseconds;
  using time_point = time_point<steady_clock>;
  static constexpr bool is_steady = true;
  static time_point now() noexcept;
};

using high_resolution_clock = steady_clock;

// local_t

struct local_t {};
template<typename Duration> using local_time = time_point<local_t, Duration>;
using local_seconds = local_time<seconds>;
using local_days = local_time<days>;

template<typename Ct, typename Tr, typename Duration> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const local_time<Duration>& t);
template<typename Ct, typename Tr, typename Duration, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, local_time<Duration>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// clock_time_conversion

template<typename Dest, typename Source> struct clock_time_conversion {};

template<typename Clock> struct clock_time_conversion<Clock, Clock> {
  template<typename Duration> time_point<Clock, Duration> operator()(const time_point<Clock, Duration>& t) const;
};
template<> struct clock_time_conversion<system_clock, system_clock> {
  template<typename Duration> sys_time<Duration> operator()(const sys_time<Duration>& t) const;
};
template<> struct clock_time_conversion<utc_clock, utc_clock> {
  template<typename Duration> utc_time<Duration> operator()(const utc_time<Duration>& t) const;
};
template<> struct clock_time_conversion<utc_clock, system_clock> {
  template<typename Duration> utc_time<common_type_t<Duration, seconds>> operator()(const sys_time<Duration>& t) const;
};
template<> struct clock_time_conversion<system_clock, utc_clock> {
  template<typename Duration> sys_time<common_type_t<Duration, seconds>> operator()(const utc_time<Duration>& t) const;
};
template<typename Source> struct clock_time_conversion<system_clock, Source> {
  template<typename Duration> auto operator()(const time_point<Source, Duration>& t) const -> decltype(Source::to_sys(t));
};
template<typename Dest> struct clock_time_conversion<Dest, system_clock> {
  template<typename Duration> auto operator()(const sys_time<Duration>& t) const -> decltype(Dest::from_sys(t));
};
template<typename Source> struct clock_time_conversion<utc_clock, Source> {
  template<typename Duration> auto operator()(const time_point<Source, Duration>& t) const -> decltype(Source::to_utc(t));
};
template<typename Dest> struct clock_time_conversion<Dest, utc_clock> {
  template<typename Duration> auto operator()(const utc_time<Duration>& t) const -> decltype(Dest::from_utc(t));
};
template<typename Dest, typename Source, typename Duration> auto clock_cast(const time_point<Source, Duration>& t);

// last

struct last_spec { explicit last_spec() = default; };
inline constexpr last_spec last{};

// information

struct sys_info {
  sys_seconds begin, end;
  seconds offset;
  minutes save;
  string abbrev;
};

struct local_info {
  static constexpr int unique = 0, nonexistent = 1, ambiguous = 2;
  int result;
  sys_info first, second;
};

template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const sys_info& si);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const local_info& li);

// exception

class nonexistent_local_time : runtime_error {
public:
  template<typename Duration> nonexistent_local_time(const local_time<Duration>&, const local_info&);
};
class ambiguous_local_time : runtime_error {
public:
  template<typename Duration> ambiguous_local_time(const local_time<Duration>&, const local_info&);
};

// leap_second

class leap_second {
  sys_seconds _tp;
public:
  leap_second(const leap_second&) = default;
  leap_second& operator=(const leap_second&) = default;
  constexpr leap_second(const sys_seconds& TimePoint) noexcept : _tp{TimePoint} {}
  constexpr sys_seconds date() const noexcept { return _tp; }
  constexpr seconds value() const noexcept { return seconds{1}; }
};

constexpr bool operator==(const leap_second& x, const leap_second& y) noexcept { return x.date() == y.date(); }
constexpr strong_ordering operator<=>(const leap_second& x, const leap_second& y) noexcept { return x.date() <=> y.date(); }
template<typename Duration> constexpr bool operator==(const leap_second& x, const sys_time<Duration>& y) noexcept { return x.date() == y; }
template<typename Duration> constexpr bool operator<(const leap_second& x, const sys_time<Duration>& y) noexcept { return x.date() < y; }
template<typename Duration> constexpr bool operator<(const sys_time<Duration>& x, const leap_second& y) noexcept { return x < y.date(); }
template<typename Duration> constexpr bool operator>(const leap_second& x, const sys_time<Duration>& y) noexcept { return y < x; }
template<typename Duration> constexpr bool operator>(const sys_time<Duration>& x, const leap_second& y) noexcept { return y < x; }
template<typename Duration> constexpr bool operator<=(const leap_second& x, const sys_time<Duration>& y) noexcept { return !(y < x); }
template<typename Duration> constexpr bool operator<=(const sys_time<Duration>& x, const leap_second& y) noexcept { return !(y < x); }
template<typename Duration> constexpr bool operator>=(const leap_second& x, const sys_time<Duration>& y) noexcept { return !(x < y); }
template<typename Duration> constexpr bool operator>=(const sys_time<Duration>& x, const leap_second& y) noexcept { return !(x < y); }
template<typename Duration> requires three_way_comparable_with<sys_seconds, sys_time<Duration>>
constexpr auto operator<=>(const leap_second& x, const sys_time<Duration>& y) noexcept { return x.date() <=> y; }

struct leap_second_info {
  bool is_leap_second;
  seconds elapsed;
};

template<typename Duration>
leap_second_info get_leap_second_info(const utc_time<Duration>& ut);

// time_zone

enum class choose { earliest, latest };

struct time_zone {
  time_zone(time_zone&&) = default;
  time_zone& operator=(time_zone&&) = default;
  string_view name() const noexcept;
  template<typename Duration> sys_info   get_info(const sys_time<Duration>& st)   const;
  template<typename Duration> local_info get_info(const local_time<Duration>& tp) const;
  template<typename Duration> sys_time<typename common_type<Duration, seconds>::type> to_sys(const local_time<Duration>& tp) const;
  template<typename Duration> sys_time<typename common_type<Duration, seconds>::type> to_sys(const local_time<Duration>& tp, choose z) const;
  template<typename Duration> local_time<typename common_type<Duration, seconds>::type> to_local(const sys_time<Duration>& tp) const;
};

bool operator==(const time_zone& x, const time_zone& y) noexcept;
strong_ordering operator<=>(const time_zone& x, const time_zone& y) noexcept;
const time_zone* locate_zone(string_view tz_name);
const time_zone* current_zone();

class time_zone_link {
public:
  time_zone_link(time_zone_link&&) = default;
  time_zone_link& operator=(time_zone_link&&) = default;
  string_view name()   const noexcept;
  string_view target() const noexcept;
};

bool operator==(const time_zone_link& x, const time_zone_link& y);
strong_ordering operator<=>(const time_zone_link& x, const time_zone_link& y);

struct tzdb {
  string version;
  vector<time_zone> zones;
  vector<time_zone_link> links;
  vector<leap_second> leap_seconds;
  const time_zone* locate_zone(string_view tz_name) const;
  const time_zone* current_zone() const;
};

const tzdb& get_tzdb();
const tzdb& reload_tzdb();
string remote_version();

struct tzdb_list {
  tzdb_list(const tzdb_list&) = delete;
  tzdb_list& operator=(const tzdb_list&) = delete;

  class const_iterator {
  public:
    using value_type = tzdb;
    using difference_type = ptrdiff_t;
    using pointer = const tzdb*;
    using reference = const tzdb&;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
    const_iterator& operator=(const const_iterator&) = default;
    const_iterator& operator=(const_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_iterator& operator++();
    const_iterator operator++(int);
    constexpr difference_type operator-(const const_iterator& i);
    bool operator==(const const_iterator& i) const;
    strong_ordering operator<=>(const const_iterator& i) const;
  };

  const tzdb& front() const noexcept;
  const_iterator erase_after(const_iterator p);
  const_iterator begin() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cend() const noexcept;
};

tzdb_list& get_tzdb_list();

// zoned_traits

template<typename T> struct zoned_traits {};
template<> struct zoned_traits<const time_zone*> {
  static const time_zone* default_zone();
  static const time_zone* locate_zone(string_view name);
};

}

namespace std::_ {
  template<typename TimeZonePtrOrName> using time_zone_representation =
    typename std::conditional<std::is_convertible<TimeZonePtrOrName, string_view>::value,
                         const chrono::time_zone*, typename std::remove_cvref<TimeZonePtrOrName>::type>::type;
}

namespace std::chrono {

// zoned_time

template<typename Duration, typename TimeZonePtr = const time_zone*> class zoned_time {
public:
  using duration = common_type_t<Duration, seconds>;
  zoned_time();
  zoned_time(const zoned_time&) = default;
  zoned_time& operator=(const zoned_time&) = default;
  zoned_time(const sys_time<Duration>& st);
  explicit zoned_time(TimeZonePtr z);
  explicit zoned_time(string_view name);
  template<typename D2> zoned_time(const zoned_time<D2, TimeZonePtr>& zt);
  zoned_time(TimeZonePtr z, const sys_time<Duration>& st);
  zoned_time(string_view name, const sys_time<Duration>& st);
  zoned_time(TimeZonePtr z, const local_time<Duration>& tp);
  zoned_time(string_view name, const local_time<Duration>& tp);
  zoned_time(TimeZonePtr z, const local_time<Duration>& tp, choose c);
  zoned_time(string_view name, const local_time<Duration>& tp, choose c);
  template<typename D2, typename P2> zoned_time(TimeZonePtr z, const zoned_time<D2, P2>& zt);
  template<typename D2, typename P2> zoned_time(TimeZonePtr z, const zoned_time<D2, P2>& zt, choose);
  template<typename D2, typename P2> zoned_time(string_view name, const zoned_time<D2, P2>& zt);
  template<typename D2, typename P2> zoned_time(string_view name, const zoned_time<D2, P2>& zt, choose);
  zoned_time& operator=(const sys_time<Duration>& st);
  zoned_time& operator=(const local_time<Duration>& ut);
  operator sys_time<duration>() const;
  explicit operator local_time<duration>() const;
  TimeZonePtr          get_time_zone()  const;
  local_time<duration> get_local_time() const;
  sys_time<duration>   get_sys_time()   const;
  sys_info             get_info()       const;
};

zoned_time() -> zoned_time<seconds>;

template<typename Duration>
zoned_time(sys_time<Duration>)
  -> zoned_time<common_type_t<Duration, seconds>>;

template<typename TimeZonePtrOrName>
zoned_time(TimeZonePtrOrName&&)
    -> zoned_time<seconds, _::time_zone_representation<TimeZonePtrOrName>>;

template<typename TimeZonePtrOrName, typename Duration>
zoned_time(TimeZonePtrOrName&&, sys_time<Duration>)
  -> zoned_time<typename common_type<Duration, seconds>::type, _::time_zone_representation<TimeZonePtrOrName>>;

template<typename TimeZonePtrOrName, typename Duration>
zoned_time(TimeZonePtrOrName&&, local_time<Duration>, choose = choose::earliest)
  -> zoned_time<typename common_type<Duration, seconds>::type, _::time_zone_representation<TimeZonePtrOrName>>;

template<typename Duration, typename TimeZonePtrOrName, typename P2>
zoned_time(TimeZonePtrOrName&&, zoned_time<Duration, P2>, choose = choose::earliest)
  -> zoned_time<typename common_type<Duration, seconds>::type, _::time_zone_representation<TimeZonePtrOrName>>;

using zoned_seconds = zoned_time<seconds>;

template<typename D1, typename D2, typename TyimeZonePtr>
bool operator==(const zoned_time<D1, TyimeZonePtr>& x, const zoned_time<D2, TyimeZonePtr>& y);

template<typename Ct, typename Tr, typename Duration, typename TyimeZonePtr>
basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const zoned_time<Duration, TyimeZonePtr>& t);

}

// local_time_format

namespace std{

namespace _ {
  template<typename Duration> struct local_time_format_t {
    chrono::local_time<Duration> time;
    const string* abbrev;
    const chrono::seconds* offset_sec;
  };
}
namespace chrono {
  template<typename Duration> _::local_time_format_t<Duration>
  local_time_format(local_time<Duration>, const string* = nullptr, const seconds* = nullptr);
}
}

namespace std::chrono {

// day

class day {
  unsigned char _d;
public:
  day() = default;
  constexpr explicit day(unsigned d) noexcept : _d{static_cast<unsigned char>(d)} {}
  constexpr day& operator++() noexcept { ++_d; return *this; }
  constexpr day& operator--() noexcept { --_d; return *this; }
  constexpr day& operator+=(const days& d) noexcept { _d += d.count(); return *this; }
  constexpr day& operator-=(const days& d) noexcept { _d -= d.count(); return *this; }
  constexpr day operator++(int) noexcept { return day{_d++}; }
  constexpr day operator--(int) noexcept { return day{_d--}; }
  constexpr explicit operator unsigned() const noexcept { return _d; }
  constexpr bool ok() const noexcept { return 1 <= _d && _d <= 31; }
};

constexpr bool operator==(const day& x, const day& y) noexcept { return static_cast<unsigned>(x) == static_cast<unsigned>(y); }
constexpr strong_ordering operator<=>(const day& x, const day& y) noexcept { return static_cast<unsigned>(x) <=> static_cast<unsigned>(y); }
constexpr day operator+(const day& x, const days& y) noexcept { return day{static_cast<unsigned>(static_cast<unsigned>(x) + y.count())}; }
constexpr day operator+(const days& x, const day& y) noexcept { return day{static_cast<unsigned>(static_cast<unsigned>(y) + x.count())}; }
constexpr day operator-(const day& x, const days& y) noexcept { return day{static_cast<unsigned>(static_cast<unsigned>(x) - y.count())}; }
constexpr days operator-(const day& x, const day& y) noexcept { return days{static_cast<unsigned>(x) - static_cast<unsigned>(y)}; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const day& d);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>& is, const Ct* fmt, day& d, basic_string<Ct, Tr, Al>* abbrev = nullptr, minutes* offset = nullptr);

// month

class month {
  unsigned char _mm;
public:
  month() = default;
  constexpr explicit month(unsigned m) noexcept : _mm{static_cast<unsigned char>(m)} {}
  constexpr month& operator++() noexcept { return ++_mm, *this; }
  constexpr month operator++(int) noexcept { return month{_mm++}; }
  constexpr month& operator--() noexcept { return --_mm, *this; }
  constexpr month operator--(int) noexcept { return month{_mm--}; }
  constexpr month& operator+=(const months& m) noexcept { return _mm += m.count(), *this; }
  constexpr month& operator-=(const months& m) noexcept { return _mm -= m.count(), *this; }
  constexpr explicit operator unsigned() const noexcept { return static_cast<unsigned>(_mm); }
  constexpr bool ok() const noexcept { return 1 <= _mm && _mm <= 12; }
};

constexpr bool operator==(const month& x, const month& y) noexcept { return static_cast<unsigned>(x) == static_cast<unsigned>(y); }
constexpr strong_ordering operator<=>(const month& x, const month& y) noexcept { return static_cast<unsigned>(x) <=> static_cast<unsigned>(y); }
constexpr month operator+(const month& x, const months& y) noexcept { return month{static_cast<unsigned>(static_cast<unsigned>(x) + y.count())}; }
constexpr month operator+(const months& x, const month& y) noexcept { return y + x; }
constexpr month operator-(const month& x, const months& y) noexcept { return x + -y; }
constexpr months operator-(const month& x, const month& y) noexcept { return months{static_cast<unsigned>(x) - static_cast<unsigned>(y)}; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const month&);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, month&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

inline constexpr month January{1};
inline constexpr month February{2};
inline constexpr month March{3};
inline constexpr month April{4};
inline constexpr month May{5};
inline constexpr month June{6};
inline constexpr month July{7};
inline constexpr month August{8};
inline constexpr month September{9};
inline constexpr month October{10};
inline constexpr month November{11};
inline constexpr month December{12};

// year

class year {
  short _yy;
public:
  year() = default;
  constexpr explicit year(int y) noexcept : _yy{static_cast<short>(y)} {}
  constexpr year& operator++() noexcept { return ++_yy, *this; }
  constexpr year operator++(int) noexcept { return year{_yy++}; }
  constexpr year& operator--() noexcept { return --_yy, *this; }
  constexpr year operator--(int) noexcept { return year{_yy--}; }
  constexpr year& operator+=(const years& y) noexcept { return _yy += y.count(), *this; }
  constexpr year& operator-=(const years& y) noexcept { return _yy -= y.count(), *this; }
  constexpr year operator+() const noexcept { return *this; }
  constexpr year operator-() const noexcept { return year{-_yy}; }
  constexpr bool is_leap() const noexcept { return ((_yy % 4 == 0) && (_yy % 100 != 0)) || (_yy % 400 == 0); }
  constexpr explicit operator int() const noexcept { return static_cast<int>(_yy); }
  constexpr bool ok() const noexcept { return _yy != -32768; }
  static constexpr year max() noexcept { return year{32767}; }
  static constexpr year min() noexcept { return year{-32767}; }
};

constexpr bool operator==(const year& x, const year& y) noexcept { return static_cast<int>(x) == static_cast<int>(y); }
constexpr strong_ordering operator<=>(const year& x, const year& y) noexcept { return static_cast<int>(x) <=> static_cast<int>(y); }
constexpr year operator+(const year& x, const years& y) noexcept { return year{static_cast<int>(static_cast<int>(x) + y.count())}; }
constexpr year operator+(const years& x, const year& y) noexcept { return y + x; }
constexpr year operator-(const year& x, const years& y) noexcept { return x + -y; }
constexpr years operator-(const year& x, const year& y) noexcept { return years{static_cast<int>(x) - static_cast<int>(y)}; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const year&);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, year&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

}

namespace std::_ {
constexpr chrono::day last_day(const chrono::year& y, const chrono::month& m) noexcept {
  constexpr chrono::day table[] = {
    chrono::day{31}, chrono::day{28}, chrono::day{31}, chrono::day{30}, chrono::day{31}, chrono::day{30},
    chrono::day{31}, chrono::day{31}, chrono::day{30}, chrono::day{31}, chrono::day{30}, chrono::day{31}};
  return m == chrono::month{2} && y.is_leap() ? chrono::day{29} : table[(static_cast<unsigned>(m) - 1) % 12];
}
}

namespace std::chrono {

// weekday

class weekday_indexed;
class weekday_last;

class weekday {
  unsigned char _ww;
  static constexpr unsigned char _ff(int d) noexcept { return static_cast<unsigned char>(d >= -4 ? (d + 4) % 7 : (d + 5) % 7 + 6); }
public:
  weekday() = default;
  constexpr explicit weekday(unsigned w) noexcept : _ww{static_cast<unsigned char>(w)} {}
  constexpr weekday(const sys_days& d) noexcept : _ww{_ff(d.time_since_epoch().count())} {}
  constexpr explicit weekday(const local_days& d) noexcept : _ww{_ff(d.time_since_epoch().count())} {}
  constexpr weekday& operator++() noexcept { return ++_ww, *this; }
  constexpr weekday operator++(int) noexcept { return weekday{_ww++}; }
  constexpr weekday& operator--() noexcept { return --_ww, *this; }
  constexpr weekday operator--(int) noexcept { return weekday{_ww--}; }
  constexpr weekday& operator+=(const days& d) noexcept { return _ww += d.count(), *this; }
  constexpr weekday& operator-=(const days& d) noexcept { return _ww -= d.count(), *this; }
  constexpr unsigned c_encoding() const noexcept { return _ww; }
  constexpr unsigned iso_encoding() const noexcept { return _ww == 0 ? 7u : _ww; }
  constexpr bool ok() const noexcept { return _ww < 7; }
  constexpr weekday_indexed operator[](unsigned index) const noexcept;
  constexpr weekday_last operator[](last_spec) const noexcept;
};

constexpr bool operator==(const weekday& x, const weekday& y) noexcept { return x.c_encoding() == y.c_encoding(); }
constexpr weekday operator+(const weekday& x, const days& y) noexcept {
  const auto a = static_cast<long long>(x.c_encoding()) + y.count(), b = (a < 0 ? a - 6 : a) / 7;
  return weekday{static_cast<unsigned>(a - b * 7)};
}
constexpr weekday operator+(const days& x, const weekday& y) noexcept { return y + x; }
constexpr weekday operator-(const weekday& x, const days& y) noexcept { return x + -y; }
constexpr days operator-(const weekday& x, const weekday& y) noexcept {
  const auto a = x.c_encoding() - y.c_encoding();
  return days{a < 7 ? a : a + 7};
}
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const weekday&);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, weekday&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

inline constexpr weekday Sunday{0};
inline constexpr weekday Monday{1};
inline constexpr weekday Tuesday{2};
inline constexpr weekday Wednesday{3};
inline constexpr weekday Thursday{4};
inline constexpr weekday Friday{5};
inline constexpr weekday Saturday{6};

class weekday_indexed {
  chrono::weekday _ww;
  unsigned char _ii;
public:
  weekday_indexed() = default;
  constexpr weekday_indexed(const chrono::weekday& w, unsigned i) noexcept : _ww{w}, _ii{static_cast<unsigned char>(i)} {}
  constexpr chrono::weekday weekday() const noexcept { return _ww; }
  constexpr unsigned index() const noexcept { return _ii; }
  constexpr bool ok() const noexcept { return _ww.ok() && 1 <= _ii&& _ii <= 5; }
};

constexpr bool operator==(const weekday_indexed& x, const weekday_indexed& y) noexcept { return x.weekday() == y.weekday() && x.index() == y.index(); }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const weekday_indexed&);

class weekday_last {
  chrono::weekday _ww;
public:
  constexpr explicit weekday_last(const chrono::weekday& w) noexcept : _ww{w} {}
  constexpr chrono::weekday weekday() const noexcept { return _ww; }
  constexpr bool ok() const noexcept { return _ww.ok(); }
};
constexpr bool operator==(const weekday_last& x, const weekday_last& y) noexcept { return x.weekday() == y.weekday(); }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const weekday_last&);

constexpr weekday_indexed weekday::operator[](unsigned int i) const noexcept { return {*this, i}; }
constexpr weekday_last weekday::operator[](last_spec) const noexcept { return weekday_last{*this}; }

// month_day

class month_day {
  chrono::month _mm;
  chrono::day _dd;
public:
  month_day() = default;
  constexpr month_day(const chrono::month& m, const chrono::day& d) noexcept : _mm{m}, _dd{d} {}
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr chrono::day day() const noexcept { return _dd; }
  constexpr bool ok() const noexcept { return _mm.ok() && _dd.ok(); }
};
constexpr bool operator==(const month_day& x, const month_day& y) noexcept { return x.month() == y.month() && x.day() == y.day(); }
constexpr strong_ordering operator<=>(const month_day& x, const month_day& y) noexcept {
  if (const auto c = x.month() <=> y.month(); c != 0) return c;
  else return x.day() <=> y.day();
}

template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const month_day&);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, month_day&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

// month_day_last

class month_day_last {
  chrono::month _mm;
public:
  constexpr explicit month_day_last(const chrono::month& m) noexcept : _mm{m} {}
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr bool ok() const noexcept { return _mm.ok(); }
};

constexpr bool operator==(const month_day_last& x, const month_day_last& y) noexcept { return x.month() == y.month(); }
constexpr strong_ordering operator<=>(const month_day_last& x, const month_day_last& y) noexcept { return x.month() <=> y.month(); }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const month_day_last&);

// month_weekday

class month_weekday {
  chrono::month _mm;
  chrono::weekday_indexed _wi;
public:
  constexpr month_weekday(const chrono::month& m, const chrono::weekday_indexed& wi) noexcept : _mm{m}, _wi{wi} {}
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr chrono::weekday_indexed weekday_indexed() const noexcept { return _wi; }
  constexpr bool ok() const noexcept { return _mm.ok() && _wi.ok(); }
};
constexpr bool operator==(const month_weekday& x, const month_weekday& y) noexcept {
  return x.month() == y.month() && x.weekday_indexed() == y.weekday_indexed();
}

template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const month_weekday&);

// month_weekday_last

class month_weekday_last {
  chrono::month _mm;
  chrono::weekday_last _wl;
public:
  constexpr month_weekday_last(const chrono::month& m, const chrono::weekday_last& wl) noexcept : _mm{m}, _wl{wl} {}
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr chrono::weekday_last weekday_last() const noexcept { return _wl; }
  constexpr bool ok() const noexcept { return _mm.ok() && _wl.ok(); }
};

constexpr bool operator==(const month_weekday_last& x, const month_weekday_last& y) noexcept {
  return x.month() == y.month() && x.weekday_last() == y.weekday_last();
}
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const month_weekday_last&);

// year_month

class year_month {
  chrono::year _yy;
  chrono::month _mm;

public:
  year_month() = default;
  constexpr year_month(const chrono::year& y, const chrono::month& m) noexcept : _yy{y}, _mm{m} {}
  constexpr chrono::year year() const noexcept { return _yy; }
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr year_month& operator+=(const months& m) noexcept;
  constexpr year_month& operator-=(const months& m) noexcept;
  constexpr year_month& operator+=(const years& y) noexcept;
  constexpr year_month& operator-=(const years& y) noexcept;
  constexpr bool ok() const noexcept { return _yy.ok() && _mm.ok(); }
};

constexpr bool operator==(const year_month& x, const year_month& y) noexcept { return x.year() == y.year() && x.month() == y.month(); }
constexpr strong_ordering operator<=>(const year_month& x, const year_month& y) noexcept {
  if (const auto c = x.year() <=> y.year(); c != 0) return c;
  else return x.month() <=> y.month();
}
constexpr year_month operator+(const year_month& x, const months& y) noexcept {
  const long long a = static_cast<long long>(static_cast<unsigned>(x.month())) + (y.count() - 1), b = (a < 0 ? a - 11 : a) / 12;
  return year_month{x.year() + years{b}, month{static_cast<unsigned>(a - b * 12 + 1)}};
}
constexpr year_month operator+(const months& x, const year_month& y) noexcept { return y + x; }
constexpr year_month operator-(const year_month& x, const months& y) noexcept { return x + -y; }
constexpr months operator-(const year_month& x, const year_month& y) noexcept {
  return chrono::duration_cast<months>(x.year() - y.year() + months{(long long){unsigned{x.month()}} - (long long){unsigned{y.month()}}});
}
constexpr year_month operator+(const year_month& x, const years& y) noexcept { return x + chrono::duration_cast<months>(y); }
constexpr year_month operator+(const years& x, const year_month& y) noexcept { return y + x; }
constexpr year_month operator-(const year_month& x, const years& y) noexcept { return x + -y; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const year_month&);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, year_month&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

constexpr year_month& year_month::operator+=(const months& m) noexcept { return *this = *this + m; }
constexpr year_month& year_month::operator-=(const months& m) noexcept { return *this = *this - m; }
constexpr year_month& year_month::operator+=(const years& y) noexcept { return *this = *this + y; }
constexpr year_month& year_month::operator-=(const years& y) noexcept { return *this = *this - y; }

// year_month_day

class year_month_day_last;

class year_month_day {
  chrono::year _yy;
  chrono::month _mm;
  chrono::day _dd;
  static constexpr year_month_day _f1(int x) noexcept {
    const int aa = x + 719468, bb = (aa < 0 ? 4 * aa - 146093 : 4 * aa + 3) / 146097;
    const unsigned cc = static_cast<unsigned>(aa - ((146097 * bb) >> 2)), dd = (91867 * (cc + 1)) >> 25;
    const unsigned ee = cc - ((1461 * dd) >> 2), ff = (535 * ee + 333) >> 14, gg = ff + (ff < 10 ? 3 : static_cast<unsigned>(-9));
    return year_month_day{chrono::year{static_cast<int>(dd) + bb * 100 + (gg < 3)}, chrono::month{gg}, chrono::day{ee - ((979 * ff + 19) >> 5) + 1}};
  }
  constexpr days _f2() const noexcept {
    const unsigned aa = static_cast<unsigned>(_mm), bb = aa + (aa > 2 ? static_cast<unsigned>(-3) : 9);
    const int cc = static_cast<int>(_yy) - (aa < 3), dd = (cc < 0 ? cc - 99 : cc) / 100;
    return days{((1461 * cc) >> 2) - dd + (dd >> 2) + static_cast<int>(((979 * bb + 19) >> 5) + static_cast<unsigned>(_dd)) - 719469};
  }
public:
  year_month_day() = default;
  constexpr year_month_day(const chrono::year& y, const chrono::month& m, const chrono::day& d) noexcept : _yy{y}, _mm{m}, _dd{d} {}
  constexpr year_month_day(const year_month_day_last& ymdl) noexcept;
  constexpr year_month_day(const sys_days& d) noexcept : year_month_day{_f1(d.time_since_epoch().count())} {}
  constexpr explicit year_month_day(const local_days& d) noexcept : year_month_day{_f1(d.time_since_epoch().count())} {}
  constexpr chrono::year year() const noexcept { return _yy; }
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr chrono::day day() const noexcept { return _dd; }
  constexpr operator sys_days() const noexcept { return sys_days{_f2()}; }
  constexpr explicit operator local_days() const noexcept { return local_days{static_cast<sys_days>(*this).time_since_epoch()}; }
  constexpr bool ok() const noexcept { return year().ok() && month().ok() && day() >= chrono::day{1} && day() <= _::last_day(year(), month()); }
  constexpr year_month_day& operator+=(const months& m) noexcept;
  constexpr year_month_day& operator-=(const months& m) noexcept;
  constexpr year_month_day& operator+=(const years& y) noexcept;
  constexpr year_month_day& operator-=(const years& y) noexcept;
};

constexpr bool operator==(const year_month_day& x, const year_month_day& y) noexcept {
  return x.year() == y.year() && x.month() == y.month() && x.day() == y.day();
}
constexpr strong_ordering operator<=>(const year_month_day& x, const year_month_day& y) noexcept {
  if (auto c = x.year() <=> y.year(); c != 0) return c;
  if (auto c = x.month() <=> y.month(); c != 0) return c;
  return x.day() <=> y.day();
}

constexpr year_month_day operator+(const year_month_day& x, const months& y) noexcept {
  const auto aa = year_month{x.year(), x.month()} + y;
  return {aa.year(), aa.month(), x.day()};
}
constexpr year_month_day operator+(const months& x, const year_month_day& y) noexcept { return y + x; }
constexpr year_month_day operator+(const year_month_day& x, const years& y) noexcept { return {x.year() + y, x.month(), x.day()}; }
constexpr year_month_day operator+(const years& x, const year_month_day& y) noexcept { return y + x; }
constexpr year_month_day operator-(const year_month_day& x, const months& y) noexcept { return x + -y; }
constexpr year_month_day operator-(const year_month_day& x, const years& y) noexcept { return x + -y; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const year_month_day&);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, year_month_day&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

constexpr year_month_day& year_month_day::operator+=(const months& m) noexcept { return *this = *this + m; }
constexpr year_month_day& year_month_day::operator-=(const months& m) noexcept { return *this = *this - m; }
constexpr year_month_day& year_month_day::operator+=(const years& y) noexcept { return *this = *this + y; }
constexpr year_month_day& year_month_day::operator-=(const years& y) noexcept { return *this = *this - y; }

class year_month_day_last {
  chrono::year _yy;
  chrono::month_day_last _mdl;
public:
  constexpr year_month_day_last(const chrono::year& y, const chrono::month_day_last& mdl) noexcept : _yy{y}, _mdl{mdl} {}
  constexpr chrono::year year() const noexcept { return _yy; }
  constexpr chrono::month month() const noexcept { return _mdl.month(); }
  constexpr chrono::month_day_last month_day_last() const noexcept { return _mdl; }
  constexpr chrono::day day() const noexcept { return _::last_day(year(), month()); }
  constexpr operator sys_days() const noexcept { return sys_days{year_month_day{year(), month(), day()}}; }
  constexpr explicit operator local_days() const noexcept { return local_days{static_cast<sys_days>(*this).time_since_epoch()}; }
  constexpr bool ok() const noexcept { return year().ok() && month_day_last().ok(); }
  constexpr year_month_day_last& operator+=(const months& m) noexcept;
  constexpr year_month_day_last& operator-=(const months& m) noexcept;
  constexpr year_month_day_last& operator+=(const years& y) noexcept;
  constexpr year_month_day_last& operator-=(const years& y) noexcept;
};

constexpr bool operator==(const year_month_day_last& x, const year_month_day_last& y) noexcept {
  return x.year() == y.year() && x.month_day_last() == y.month_day_last();
}
constexpr strong_ordering operator<=>(const year_month_day_last& x, const year_month_day_last& y) noexcept {
  if (const auto c = x.year() <=> y.year(); c != 0) return c;
  else return x.month_day_last() <=> y.month_day_last();
}

constexpr year_month_day_last operator+(const year_month_day_last& x, const months& y) noexcept {
  const auto aa = year_month{x.year(), x.month()} + y;
  return {aa.year(), month_day_last{aa.month()}};
}
constexpr year_month_day_last operator+(const months& x, const year_month_day_last& y) noexcept { return y + x; }
constexpr year_month_day_last operator+(const year_month_day_last& x, const years& y) noexcept { return {x.year() + y, x.month_day_last()}; }
constexpr year_month_day_last operator+(const years& x, const year_month_day_last& y) noexcept { return y + x; }
constexpr year_month_day_last operator-(const year_month_day_last& x, const months& y) noexcept { return x + -y; }
constexpr year_month_day_last operator-(const year_month_day_last& x, const years& y) noexcept { return x + -y; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const year_month_day_last&);


constexpr year_month_day::year_month_day(const year_month_day_last& ymdl) noexcept : _yy{ymdl.year()}, _mm{ymdl.month()}, _dd{ymdl.day()} {}


constexpr year_month_day_last& year_month_day_last::operator+=(const months& m) noexcept { return *this = *this + m; }
constexpr year_month_day_last& year_month_day_last::operator-=(const months& m) noexcept { return *this = *this - m; }
constexpr year_month_day_last& year_month_day_last::operator+=(const years& y) noexcept { return *this = *this + y; }
constexpr year_month_day_last& year_month_day_last::operator-=(const years& y) noexcept { return *this = *this - y; }

// year_month_weekday

class year_month_weekday {
  chrono::year _yy;
  chrono::month _mm;
  chrono::weekday_indexed _wi;
  static constexpr year_month_weekday _ff(days d) noexcept {
    const chrono::year_month_day aa = sys_days{d};
    return {aa.year(), aa.month(), chrono::weekday{sys_days{d}}[((static_cast<unsigned>(aa.day()) - 1) / 7) + 1]};
  }

public:
  year_month_weekday() = default;
  constexpr year_month_weekday(const chrono::year& y, const chrono::month& m, const chrono::weekday_indexed& wi) noexcept : _yy{y}, _mm{m}, _wi{wi} {}
  constexpr year_month_weekday(const sys_days& d) noexcept : year_month_weekday{_ff(d.time_since_epoch())} {}
  constexpr explicit year_month_weekday(const local_days& d) noexcept : year_month_weekday{_ff(d.time_since_epoch())} {}
  constexpr chrono::year year() const noexcept { return _yy; }
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr chrono::weekday weekday() const noexcept { return _wi.weekday(); }
  constexpr unsigned index() const noexcept { return _wi.index(); }
  constexpr chrono::weekday_indexed weekday_indexed() const noexcept { return _wi; }
  constexpr operator sys_days() const noexcept {
    const sys_days aa = year_month_day{year(), month(), day{1}};
    return aa + days{weekday() - chrono::weekday{aa}} + days{(static_cast<int>(index()) - 1) * 7};
  }
  constexpr explicit operator local_days() const noexcept { return local_days{static_cast<sys_days>(*this).time_since_epoch()}; }
  constexpr bool ok() const noexcept {
    if (year().ok() && month().ok() && weekday_indexed().ok()) {
      if (weekday_indexed().index() < 5) return true;
      const days aa = days{weekday() - chrono::weekday{sys_days{year_month_day{year(), month(), day{1}}}}} + days{29};
      return static_cast<unsigned>(aa.count()) <= static_cast<unsigned>(_::last_day(year(), month()));
    } else return false;
  }
  constexpr year_month_weekday& operator+=(const months& m) noexcept;
  constexpr year_month_weekday& operator-=(const months& m) noexcept;
  constexpr year_month_weekday& operator+=(const years& y) noexcept;
  constexpr year_month_weekday& operator-=(const years& y) noexcept;
};

constexpr bool operator==(const year_month_weekday& x, const year_month_weekday& y) noexcept {
  return x.year() == y.year() && x.month() == y.month() && x.weekday_indexed() == y.weekday_indexed();
}
constexpr year_month_weekday operator+(const year_month_weekday& x, const months& y) noexcept {
  const auto aa = year_month{x.year(), x.month()} + y;
  return {aa.year(), aa.month(), x.weekday_indexed()};
}
constexpr year_month_weekday operator+(const months& x, const year_month_weekday& y) noexcept { return y + x; }
constexpr year_month_weekday operator+(const year_month_weekday& x, const years& y) noexcept {
  return year_month_weekday{x.year() + y, x.month(), x.weekday_indexed()};
}
constexpr year_month_weekday operator+(const years& x, const year_month_weekday& y) noexcept { return y + x; }
constexpr year_month_weekday operator-(const year_month_weekday& x, const months& y) noexcept { return x + -y; }
constexpr year_month_weekday operator-(const year_month_weekday& x, const years& y) noexcept { return x + -y; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const year_month_weekday&);

constexpr year_month_weekday& year_month_weekday::operator+=(const months& m) noexcept { return *this = *this + m; }
constexpr year_month_weekday& year_month_weekday::operator-=(const months& m) noexcept { return *this = *this - m; }
constexpr year_month_weekday& year_month_weekday::operator+=(const years& y) noexcept { return *this = *this + y; }
constexpr year_month_weekday& year_month_weekday::operator-=(const years& y) noexcept { return *this = *this - y; }

// year_month_weekday_last

class year_month_weekday_last {
  chrono::year _yy;
  chrono::month _mm;
  chrono::weekday_last _wl;

public:
  constexpr year_month_weekday_last(const chrono::year& y, const chrono::month& m, const chrono::weekday_last& wl) noexcept : _yy{y}, _mm{m}, _wl{wl} {}
  constexpr chrono::year year() const noexcept { return _yy; }
  constexpr chrono::month month() const noexcept { return _mm; }
  constexpr chrono::weekday weekday() const noexcept { return _wl.weekday(); }
  constexpr chrono::weekday_last weekday_last() const noexcept { return _wl; }
  constexpr operator sys_days() const noexcept {
    const sys_days aa = year_month_day_last{year(), month_day_last{month()}};
    return aa - (chrono::weekday{aa} - weekday());
  }
  constexpr explicit operator local_days() const noexcept { return local_days{static_cast<sys_days>(*this).time_since_epoch()}; }
  constexpr bool ok() const noexcept { return year().ok() && month().ok() && weekday_last().ok(); }
  constexpr year_month_weekday_last& operator+=(const months& m) noexcept;
  constexpr year_month_weekday_last& operator-=(const months& m) noexcept;
  constexpr year_month_weekday_last& operator+=(const years& y) noexcept;
  constexpr year_month_weekday_last& operator-=(const years& y) noexcept;
};

constexpr bool operator==(const year_month_weekday_last& x, const year_month_weekday_last& y) noexcept {
  return x.year() == y.year() && x.month() == y.month() && x.weekday_last() == y.weekday_last();
}
constexpr year_month_weekday_last operator+(const year_month_weekday_last& x, const months& y) noexcept {
  const auto aa = year_month{x.year(), x.month()} + y;
  return {aa.year(), aa.month(), x.weekday_last()};
}
constexpr year_month_weekday_last operator+(const months& x, const year_month_weekday_last& y) noexcept { return y + x; }
constexpr year_month_weekday_last operator+(const year_month_weekday_last& x, const years& y) noexcept { return {x.year() + y, x.month(), x.weekday_last()}; }
constexpr year_month_weekday_last operator+(const years& x, const year_month_weekday_last& y) noexcept { return y + x; }
constexpr year_month_weekday_last operator-(const year_month_weekday_last& x, const months& y) noexcept { return x + -y; }
constexpr year_month_weekday_last operator-(const year_month_weekday_last& x, const years& y) noexcept { return x + -y; }
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const year_month_weekday_last&);

constexpr year_month_weekday_last& year_month_weekday_last::operator+=(const months& m) noexcept { return *this = *this + m; }
constexpr year_month_weekday_last& year_month_weekday_last::operator-=(const months& m) noexcept { return *this = *this - m; }
constexpr year_month_weekday_last& year_month_weekday_last::operator+=(const years& y) noexcept { return *this = *this + y; }
constexpr year_month_weekday_last& year_month_weekday_last::operator-=(const years& y) noexcept { return *this = *this - y; }

constexpr year_month operator/(const year& y, const month& m) noexcept { return {y, m}; }
constexpr year_month operator/(const year& y, int m) noexcept { return y / month{static_cast<unsigned>(m)}; }
constexpr month_day operator/(const month& m, const day& d) noexcept { return month_day{m, d}; }
constexpr month_day operator/(const month& m, int d) noexcept { return m / day{static_cast<unsigned int>(d)}; }
constexpr month_day operator/(int m, const day& d) noexcept { return month{static_cast<unsigned>(m)} / d; }
constexpr month_day operator/(const day& d, const month& m) noexcept { return m / d; }
constexpr month_day operator/(const day& d, int m) noexcept { return month{static_cast<unsigned>(m)} / d; }
constexpr month_day_last operator/(const month& m, last_spec) noexcept { return month_day_last{m}; }
constexpr month_day_last operator/(int m, last_spec) noexcept { return month{static_cast<unsigned>(m)} / last; }
constexpr month_day_last operator/(last_spec, const month& m) noexcept { return m / last; }
constexpr month_day_last operator/(last_spec, int m) noexcept { return month{static_cast<unsigned>(m)} / last; }
constexpr month_weekday operator/(const month& m, const weekday_indexed& wi) noexcept { return {m, wi}; }
constexpr month_weekday operator/(int m, const weekday_indexed& wi) noexcept { return month{static_cast<unsigned>(m)} / wi; }
constexpr month_weekday operator/(const weekday_indexed& wi, const month& m) noexcept { return m / wi; }
constexpr month_weekday operator/(const weekday_indexed& wi, int m) noexcept { return month{static_cast<unsigned>(m)} / wi; }
constexpr month_weekday_last operator/(const month& m, const weekday_last& wl) noexcept { return {m, wl}; }
constexpr month_weekday_last operator/(int m, const weekday_last& wl) noexcept { return month{static_cast<unsigned>(m)} / wl; }
constexpr month_weekday_last operator/(const weekday_last& wl, const month& m) noexcept { return m / wl; }
constexpr month_weekday_last operator/(const weekday_last& wl, int m) noexcept { return month{static_cast<unsigned>(m)} / wl; }
constexpr year_month_day operator/(const year_month& ym, const day& d) noexcept { return {ym.year(), ym.month(), d}; }
constexpr year_month_day operator/(const year_month& ym, int d) noexcept { return ym / day{static_cast<unsigned>(d)}; }
constexpr year_month_day operator/(const year& y, const month_day& md) noexcept { return y / md.month() / md.day(); }
constexpr year_month_day operator/(int y, const month_day& md) noexcept { return year{y} / md.month() / md.day(); }
constexpr year_month_day operator/(const month_day& md, const year& y) noexcept { return y / md.month() / md.day(); }
constexpr year_month_day operator/(const month_day& md, int y) noexcept { return year{y} / md.month() / md.day(); }
constexpr year_month_day_last operator/(const year_month& ym, last_spec) noexcept { return {ym.year(), month_day_last{ym.month()}}; }
constexpr year_month_day_last operator/(const year& y, const month_day_last& mdl) noexcept { return {y, mdl}; }
constexpr year_month_day_last operator/(int y, const month_day_last& mdl) noexcept { return {year{y}, mdl}; }
constexpr year_month_day_last operator/(const month_day_last& mdl, const year& y) noexcept { return y / mdl; }
constexpr year_month_day_last operator/(const month_day_last& mdl, int y) noexcept { return year{y} / mdl; }
constexpr year_month_weekday operator/(const year_month& ym, const weekday_indexed& wi) noexcept { return year_month_weekday{ym.year(), ym.month(), wi}; }
constexpr year_month_weekday operator/(const year& y, const month_weekday& mw) noexcept { return year_month_weekday{y, mw.month(), mw.weekday_indexed()}; }
constexpr year_month_weekday operator/(int y, const month_weekday& mw) noexcept { return year{y} / mw; }
constexpr year_month_weekday operator/(const month_weekday& mw, const year& y) noexcept { return y / mw; }
constexpr year_month_weekday operator/(const month_weekday& mw, int y) noexcept { return year{y} / mw; }
constexpr year_month_weekday_last operator/(const year_month& ym, const weekday_last& wl) noexcept { return {ym.year(), ym.month(), wl}; }
constexpr year_month_weekday_last operator/(const year& y, const month_weekday_last& mwl) noexcept { return {y, mwl.month(), mwl.weekday_last()}; }
constexpr year_month_weekday_last operator/(int y, const month_weekday_last& mwl) noexcept { return year{y} / mwl; }
constexpr year_month_weekday_last operator/(const month_weekday_last& mwl, const year& y) noexcept { return y / mwl; }
constexpr year_month_weekday_last operator/(const month_weekday_last& mwl, int y) noexcept { return year{y} / mwl; }


template<typename Duration> class hh_mm_ss {
  static constexpr intmax_t _ff(auto x) noexcept {
    for (intmax_t aa = 0;; --x)
      if (x == 0) return aa;
  }

public:
  static constexpr unsigned fractional_width = [] {
    static_assert(Duration::period::num > 0 && Duration::period::den > 0);
    unsigned int cc = 0;
    for (auto aa = Duration::period::num; aa % Duration::period::den != 0 && cc < 19; ++cc) aa = aa % Duration::period::den * 10;
    return cc == 19 ? 6 : cc; }();
  using precision = duration<common_type_t<typename Duration::rep, seconds::rep>, ratio<1, _ff(fractional_width)>>;

  constexpr hh_mm_ss() noexcept : hh_mm_ss{Duration::zero()} {}
  constexpr explicit hh_mm_ss(Duration d);

  constexpr bool is_negative() const noexcept;
  constexpr chrono::hours hours() const noexcept;
  constexpr chrono::minutes minutes() const noexcept;
  constexpr chrono::seconds seconds() const noexcept;
  constexpr precision subseconds() const noexcept;

  constexpr explicit operator precision() const noexcept;
  constexpr precision to_duration() const noexcept;

private:
  bool is_neg;
  chrono::hours h;
  chrono::minutes m;
  chrono::seconds s;
  precision ss;
};

template<typename Ct, typename Tr, typename Duration> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>&, const hh_mm_ss<Duration>& hms);

constexpr bool is_am(const hours& h) noexcept;
constexpr bool is_pm(const hours& h) noexcept;
constexpr hours make12(const hours& h) noexcept;
constexpr hours make24(const hours& h, bool is_pm) noexcept;

}

namespace std {

template<typename Ty, typename Ct> struct formatter;
template<typename Rep, typename Period, typename Ct> struct formatter<chrono::duration<Rep, Period>, Ct>;
template<typename Duration, typename Ct> struct formatter<chrono::sys_time<Duration>, Ct>;
template<typename Duration, typename Ct> struct formatter<chrono::utc_time<Duration>, Ct>;
template<typename Duration, typename Ct> struct formatter<chrono::tai_time<Duration>, Ct>;
template<typename Duration, typename Ct> struct formatter<chrono::gps_time<Duration>, Ct>;
template<typename Duration, typename Ct> struct formatter<chrono::file_time<Duration>, Ct>;
template<typename Duration, typename Ct> struct formatter<chrono::local_time<Duration>, Ct>;
template<typename Duration, typename Ct> struct formatter<_::local_time_format_t<Duration>, Ct>;
template<typename Ct> struct formatter<chrono::day, Ct>;
template<typename Ct> struct formatter<chrono::month, Ct>;
template<typename Ct> struct formatter<chrono::year, Ct>;
template<typename Ct> struct formatter<chrono::weekday, Ct>;
template<typename Ct> struct formatter<chrono::weekday_indexed, Ct>;
template<typename Ct> struct formatter<chrono::weekday_last, Ct>;
template<typename Ct> struct formatter<chrono::month_day, Ct>;
template<typename Ct> struct formatter<chrono::month_day_last, Ct>;
template<typename Ct> struct formatter<chrono::month_weekday, Ct>;
template<typename Ct> struct formatter<chrono::month_weekday_last, Ct>;
template<typename Ct> struct formatter<chrono::year_month, Ct>;
template<typename Ct> struct formatter<chrono::year_month_day, Ct>;
template<typename Ct> struct formatter<chrono::year_month_day_last, Ct>;
template<typename Ct> struct formatter<chrono::year_month_weekday, Ct>;
template<typename Ct> struct formatter<chrono::year_month_weekday_last, Ct>;
template<typename Rep, typename Period, typename Ct> struct formatter<chrono::hh_mm_ss<chrono::duration<Rep, Period>>, Ct>;
template<typename Ct> struct formatter<chrono::sys_info, Ct>;
template<typename Ct> struct formatter<chrono::local_info, Ct>;
template<typename Duration, typename TyimeZonePtr, typename Ct> struct formatter<chrono::zoned_time<Duration, TyimeZonePtr>, Ct>;

namespace chrono {
  template<typename Ct, typename Parsable> auto parse(const Ct* fmt, Parsable& tp);
  template<typename Ct, typename Tr, typename Al, typename Parsable> auto parse(const basic_string<Ct, Tr, Al>& format, Parsable& tp);
  template<typename Ct, typename Tr, typename Al, typename Parsable> auto parse(const Ct* fmt, Parsable& tp, basic_string<Ct, Tr, Al>& abbrev);
  template<typename Ct, typename Tr, typename Al, typename Parsable> auto parse(const basic_string<Ct, Tr, Al>& format, Parsable& tp, basic_string<Ct, Tr, Al>& abbrev);
  template<typename Ct, typename Parsable> auto parse(const Ct* fmt, Parsable& tp, minutes& offset);
  template<typename Ct, typename Tr, typename Al, typename Parsable> auto parse(const basic_string<Ct, Tr, Al>& format, Parsable& tp, minutes& offset);
  template<typename Ct, typename Tr, typename Al, typename Parsable> auto parse(const Ct* fmt, Parsable& tp, basic_string<Ct, Tr, Al>& abbrev, minutes& offset);
  template<typename Ct, typename Tr, typename Al, typename Parsable> auto parse(const basic_string<Ct, Tr, Al>& format, Parsable& tp, basic_string<Ct, Tr, Al>& abbrev, minutes& offset);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuser-defined-literals"

inline namespace literals {
  inline namespace chrono_literals {
    constexpr chrono::hours operator""h(unsigned long long);
    constexpr chrono::duration<intmax_t, ratio<3600, 1>> operator""h(long double);
    constexpr chrono::minutes operator""min(unsigned long long);
    constexpr chrono::duration<intmax_t, ratio<60, 1>> operator""min(long double);
    constexpr chrono::seconds operator""s(unsigned long long);
    constexpr chrono::duration<intmax_t> operator""s(long double);
    constexpr chrono::milliseconds operator""ms(unsigned long long);
    constexpr chrono::duration<intmax_t, ratio<1, 1000>> operator""ms(long double);
    constexpr chrono::microseconds operator""us(unsigned long long);
    constexpr chrono::duration<intmax_t, ratio<1, 1000000>> operator""us(long double);
    constexpr chrono::nanoseconds operator""ns(unsigned long long);
    constexpr chrono::duration<intmax_t, ratio<1, 1000000000>> operator""ns(long double);
    constexpr chrono::day operator""d(unsigned long long d) noexcept;
    constexpr chrono::year operator""y(unsigned long long y) noexcept;
  }
}

#pragma clang diagnostic pop

namespace chrono {
  using namespace literals::chrono_literals;
}

}

#endif
