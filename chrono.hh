// ywstd/chrono.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once
#ifdef ywstd
#include <chrono.hh>
#else

#include "@/../compare.hh"
#include "@/../iosfwd.hh"
#include "@/../ratio.hh"
#include "@/chrono-file_clock.hh"

namespace std::chrono {

template<typename T> struct is_clock;
template<typename T> inline constexpr bool is_clock_v = is_clock<T>::value;

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr common_type_t<duration<Rep1, Period1>, duration<Rep2, Period2>> operator+(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr common_type_t<duration<Rep1, Period1>, duration<Rep2, Period2>> operator-(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period, typename Rep2>
constexpr duration<common_type_t<Rep1, Rep2>, Period> operator*(const duration<Rep1, Period>& d, const Rep2& s);

template<typename Rep1, typename Rep2, typename Period>
constexpr duration<common_type_t<Rep1, Rep2>, Period> operator*(const Rep1& s, const duration<Rep2, Period>& d);

template<typename Rep1, typename Period, typename Rep2>
constexpr duration<common_type_t<Rep1, Rep2>, Period> operator/(const duration<Rep1, Period>& d, const Rep2& s);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr common_type_t<Rep1, Rep2> operator/(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period, typename Rep2>
constexpr duration<common_type_t<Rep1, Rep2>, Period> operator%(const duration<Rep1, Period>& d, const Rep2& s);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr common_type_t<duration<Rep1, Period1>, duration<Rep2, Period2>> operator%(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator==(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<=(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>=(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
requires three_way_comparable<common_type_t<Rep1, Rep2>>
constexpr auto operator<=>(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename ToDr, typename Rep, typename Period>
constexpr ToDr duration_cast(const duration<Rep, Period>& d);

template<typename ToDr, typename Rep, typename Period>
constexpr ToDr floor(const duration<Rep, Period>& d);

template<typename ToDr, typename Rep, typename Period>
constexpr ToDr ceil(const duration<Rep, Period>& d);

template<typename ToDr, typename Rep, typename Period>
constexpr ToDr round(const duration<Rep, Period>& d);

template<typename Ct, typename Tr, typename Rep, typename Period>
basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const duration<Rep, Period>& d);

template<typename Ct, typename Tr, typename Rep, typename Period, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, duration<Rep, Period>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

using nanoseconds = duration<long long, nano>;
using microseconds = duration<long long, micro>;
using milliseconds = duration<long long, milli>;
using seconds = duration<long long>;
using minutes = duration<long long, ratio<60>>;
using hours = duration<long long, ratio<3600>>;
using days = duration<long long, ratio_multiply<ratio<24>, hours::period>>;
using weeks = duration<long long, ratio_multiply<ratio<7>, days::period>>;
using years = duration<long long, ratio_multiply<ratio<146097, 400>, days::period>>;
using months = duration<long long, ratio_divide<years::period, ratio<12>>>;

template<typename Clock, typename Dr1, typename Rep2, typename Period2> constexpr time_point<Clock, common_type_t<Dr1, duration<Rep2, Period2>>>
operator+(const time_point<Clock, Dr1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Rep1, typename Period1, typename Clock, typename Dr2> constexpr time_point<Clock, common_type_t<duration<Rep1, Period1>, Dr2>>
operator+(const duration<Rep1, Period1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename Clock, typename Dr1, typename Rep2, typename Period2> constexpr time_point<Clock, common_type_t<Dr1, duration<Rep2, Period2>>>
operator-(const time_point<Clock, Dr1>& lhs, const duration<Rep2, Period2>& rhs);

template<typename Clock, typename Dr1, typename Dr2> constexpr common_type_t<Dr1, Dr2>
operator-(const time_point<Clock, Dr1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename Clock, typename Dr1, typename Dr2>
constexpr bool operator==(const time_point<Clock, Dr1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename Clock, typename Dr1, typename Dr2>
constexpr bool operator<(const time_point<Clock, Dr1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename Clock, typename Dr1, typename Dr2>
constexpr bool operator>(const time_point<Clock, Dr1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename Clock, typename Dr1, typename Dr2>
constexpr bool operator<=(const time_point<Clock, Dr1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename Clock, typename Dr1, typename Dr2>
constexpr bool operator>=(const time_point<Clock, Dr1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename Clock, typename Dr1, three_way_comparable_with<Dr1> Dr2>
constexpr auto operator<=>(const time_point<Clock, Dr1>& lhs, const time_point<Clock, Dr2>& rhs);

template<typename ToDr, typename Clock, typename Dr>
constexpr time_point<Clock, ToDr> time_point_cast(const time_point<Clock, Dr>& t);

template<typename ToDr, typename Clock, typename Dr> constexpr time_point<Clock, ToDr> floor(const time_point<Clock, Dr>& tp);

template<typename ToDr, typename Clock, typename Dr> constexpr time_point<Clock, ToDr> ceil(const time_point<Clock, Dr>& tp);

template<typename ToDr, typename Clock, typename Dr> constexpr time_point<Clock, ToDr> round(const time_point<Clock, Dr>& tp);

template<typename Rep, typename Period> constexpr duration<Rep, Period> abs(duration<Rep, Period> d);

class system_clock;
template<typename Dr> using sys_time = time_point<system_clock, Dr>;
using sys_seconds = sys_time<seconds>;
using sys_days = sys_time<days>;

template<typename Ct, typename Tr, typename Dr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const sys_time<Dr>& tp);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const sys_days& dp);
template<typename Ct, typename Tr, typename Dr, typename Al = allocator<Ct>>
basic_istream<Ct, Tr>& from_stream(basic_istream<Ct, Tr>&, const Ct*, sys_time<Dr>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

class utc_clock;
template<typename Dr> using utc_time = time_point<utc_clock, Dr>;
using utc_seconds = utc_time<seconds>;

template<typename Ct, typename Tr, typename Dr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const utc_time<Dr>& t);
template<typename Ct, typename Tr, typename Dr, typename Al = allocator<Ct>>
basic_istream<Ct, Tr>& from_stream(basic_istream<Ct, Tr>&, const Ct*, utc_time<Dr>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

struct leap_second_info;
template<typename Dr> leap_second_info get_leap_second_info(const utc_time<Dr>& ut);

class tai_clock;
template<typename Dr> using tai_time = time_point<tai_clock, Dr>;
using tai_seconds = tai_time<seconds>;

template<typename Ct, typename Tr, typename Dr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const tai_time<Dr>& t);
template<typename Ct, typename Tr, typename Dr, typename Al = allocator<Ct>>
basic_istream<Ct, Tr>& from_stream(basic_istream<Ct, Tr>&, const Ct*, tai_time<Dr>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

class gps_clock;
template<typename Dr> using gps_time = time_point<gps_clock, Dr>;
using gps_seconds = gps_time<seconds>;

template<typename Ct, typename Tr, typename Dr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const gps_time<Dr>& t);
template<typename Ct, typename Tr, typename Dr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, gps_time<Dr>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

class file_clock;
template<typename Dr> using file_time = time_point<file_clock, Dr>;

template<typename Ct, typename Tr, typename Dr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const file_time<Dr>& tp);
template<typename Ct, typename Tr, typename Dr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, file_time<Dr>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

class steady_clock;
class high_resolution_clock;

struct local_t {};
template<typename Dr> using local_time = time_point<local_t, Dr>;
using local_seconds = local_time<seconds>;
using local_days = local_time<days>;

template<typename Ct, typename Tr, typename Dr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const local_time<Dr>& tp);
template<typename Ct, typename Tr, typename Dr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, local_time<Dr>&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

template<typename DestClock, typename SourceClock> struct clock_time_conversion;
template<typename DestClock, typename SourceClock, typename Dr> auto clock_cast(const time_point<SourceClock, Dr>& t);

struct last_spec;
inline constexpr last_spec last{};

class day;
constexpr bool operator==(const day& x, const day& y) noexcept;
constexpr strong_ordering operator<=>(const day& x, const day& y) noexcept;
constexpr day operator+(const day& x, const days& y) noexcept;
constexpr day operator+(const days& x, const day& y) noexcept;
constexpr day operator-(const day& x, const days& y) noexcept;
constexpr days operator-(const day& x, const day& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const day& d);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>&, const Ct*, day&, basic_string<Ct, Tr, Al>* = nullptr, minutes* = nullptr);

class month;
constexpr bool operator==(const month& x, const month& y) noexcept;
constexpr strong_ordering operator<=>(const month& x, const month& y) noexcept;
constexpr month operator+(const month& x, const months& y) noexcept;
constexpr month operator+(const months& x, const month& y) noexcept;
constexpr month operator-(const month& x, const months& y) noexcept;
constexpr months operator-(const month& x, const month& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const month& m);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>& is, const Ct* fmt, month& m, basic_string<Ct, Tr, Al>* abbrev = nullptr, minutes* offset = nullptr);

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

class year;
constexpr bool operator==(const year& x, const year& y) noexcept;
constexpr strong_ordering operator<=>(const year& x, const year& y) noexcept;
constexpr year operator+(const year& x, const years& y) noexcept;
constexpr year operator+(const years& x, const year& y) noexcept;
constexpr year operator-(const year& x, const years& y) noexcept;
constexpr years operator-(const year& x, const year& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const year& y);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>& is, const Ct* fmt, year& y, basic_string<Ct, Tr, Al>* abbrev = nullptr, minutes* offset = nullptr);

class weekday;
constexpr bool operator==(const weekday& x, const weekday& y) noexcept;
constexpr weekday operator+(const weekday& x, const days& y) noexcept;
constexpr weekday operator+(const days& x, const weekday& y) noexcept;
constexpr weekday operator-(const weekday& x, const days& y) noexcept;
constexpr days operator-(const weekday& x, const weekday& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const weekday& wd);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>& is, const Ct* fmt, weekday& wd, basic_string<Ct, Tr, Al>* abbrev = nullptr, minutes* offset = nullptr);

inline constexpr weekday Sunday{0};
inline constexpr weekday Monday{1};
inline constexpr weekday Tuesday{2};
inline constexpr weekday Wednesday{3};
inline constexpr weekday Thursday{4};
inline constexpr weekday Friday{5};
inline constexpr weekday Saturday{6};

class weekday_indexed;
constexpr bool operator==(const weekday_indexed& x, const weekday_indexed& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const weekday_indexed& wdi);

class weekday_last;
constexpr bool operator==(const weekday_last& x, const weekday_last& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const weekday_last& wdl);

class month_day;
constexpr bool operator==(const month_day& x, const month_day& y) noexcept;
constexpr strong_ordering operator<=>(const month_day& x, const month_day& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const month_day& md);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>& is, const Ct* fmt, month_day& md, basic_string<Ct, Tr, Al>* abbrev = nullptr, minutes* offset = nullptr);

class month_day_last;
constexpr bool operator==(const month_day_last& x, const month_day_last& y) noexcept;
constexpr strong_ordering operator<=>(const month_day_last& x, const month_day_last& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const month_day_last& mdl);

class month_weekday;
constexpr bool operator==(const month_weekday& x, const month_weekday& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const month_weekday& mwd);

class month_weekday_last;
constexpr bool operator==(const month_weekday_last& x, const month_weekday_last& y) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const month_weekday_last& mwdl);

class year_month;
constexpr bool operator==(const year_month& x, const year_month& y) noexcept;
constexpr strong_ordering operator<=>(const year_month& x, const year_month& y) noexcept;
constexpr year_month operator+(const year_month& ym, const months& dm) noexcept;
constexpr year_month operator+(const months& dm, const year_month& ym) noexcept;
constexpr year_month operator-(const year_month& ym, const months& dm) noexcept;
constexpr months operator-(const year_month& x, const year_month& y) noexcept;
constexpr year_month operator+(const year_month& ym, const years& dy) noexcept;
constexpr year_month operator+(const years& dy, const year_month& ym) noexcept;
constexpr year_month operator-(const year_month& ym, const years& dy) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const year_month& ym);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>& is, const Ct* fmt, year_month& ym, basic_string<Ct, Tr, Al>* abbrev = nullptr, minutes* offset = nullptr);

class year_month_day;
constexpr bool operator==(const year_month_day& x, const year_month_day& y) noexcept;
constexpr strong_ordering operator<=>(const year_month_day& x, const year_month_day& y) noexcept;
constexpr year_month_day operator+(const year_month_day& ymd, const months& dm) noexcept;
constexpr year_month_day operator+(const months& dm, const year_month_day& ymd) noexcept;
constexpr year_month_day operator+(const year_month_day& ymd, const years& dy) noexcept;
constexpr year_month_day operator+(const years& dy, const year_month_day& ymd) noexcept;
constexpr year_month_day operator-(const year_month_day& ymd, const months& dm) noexcept;
constexpr year_month_day operator-(const year_month_day& ymd, const years& dy) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const year_month_day& ymd);
template<typename Ct, typename Tr, typename Al = allocator<Ct>> basic_istream<Ct, Tr>&
from_stream(basic_istream<Ct, Tr>& is, const Ct* fmt, year_month_day& ymd, basic_string<Ct, Tr, Al>* abbrev = nullptr, minutes* offset = nullptr);

class year_month_day_last;
constexpr bool operator==(const year_month_day_last& x, const year_month_day_last& y) noexcept;
constexpr strong_ordering operator<=>(const year_month_day_last& x, const year_month_day_last& y) noexcept;
constexpr year_month_day_last operator+(const year_month_day_last& ymdl, const months& dm) noexcept;
constexpr year_month_day_last operator+(const months& dm, const year_month_day_last& ymdl) noexcept;
constexpr year_month_day_last operator+(const year_month_day_last& ymdl, const years& dy) noexcept;
constexpr year_month_day_last operator+(const years& dy, const year_month_day_last& ymdl) noexcept;
constexpr year_month_day_last operator-(const year_month_day_last& ymdl, const months& dm) noexcept;
constexpr year_month_day_last operator-(const year_month_day_last& ymdl, const years& dy) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const year_month_day_last& ymdl);

class year_month_weekday;
constexpr bool operator==(const year_month_weekday& x, const year_month_weekday& y) noexcept;
constexpr year_month_weekday operator+(const year_month_weekday& ymwd, const months& dm) noexcept;
constexpr year_month_weekday operator+(const months& dm, const year_month_weekday& ymwd) noexcept;
constexpr year_month_weekday operator+(const year_month_weekday& ymwd, const years& dy) noexcept;
constexpr year_month_weekday operator+(const years& dy, const year_month_weekday& ymwd) noexcept;
constexpr year_month_weekday operator-(const year_month_weekday& ymwd, const months& dm) noexcept;
constexpr year_month_weekday operator-(const year_month_weekday& ymwd, const years& dy) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const year_month_weekday& ymwdi);

class year_month_weekday_last;
constexpr bool operator==(const year_month_weekday_last& x, const year_month_weekday_last& y) noexcept;
constexpr year_month_weekday_last operator+(const year_month_weekday_last& ymwdl, const months& dm) noexcept;
constexpr year_month_weekday_last operator+(const months& dm, const year_month_weekday_last& ymwdl) noexcept;
constexpr year_month_weekday_last operator+(const year_month_weekday_last& ymwdl, const years& dy) noexcept;
constexpr year_month_weekday_last operator+(const years& dy, const year_month_weekday_last& ymwdl) noexcept;
constexpr year_month_weekday_last operator-(const year_month_weekday_last& ymwdl, const months& dm) noexcept;
constexpr year_month_weekday_last operator-(const year_month_weekday_last& ymwdl, const years& dy) noexcept;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const year_month_weekday_last& ymwdl);

constexpr year_month operator/(const year& y, const month& m) noexcept;
constexpr year_month operator/(const year& y, int m) noexcept;
constexpr month_day operator/(const month& m, const day& d) noexcept;
constexpr month_day operator/(const month& m, int d) noexcept;
constexpr month_day operator/(int m, const day& d) noexcept;
constexpr month_day operator/(const day& d, const month& m) noexcept;
constexpr month_day operator/(const day& d, int m) noexcept;
constexpr month_day_last operator/(const month& m, last_spec) noexcept;
constexpr month_day_last operator/(int m, last_spec) noexcept;
constexpr month_day_last operator/(last_spec, const month& m) noexcept;
constexpr month_day_last operator/(last_spec, int m) noexcept;
constexpr month_weekday operator/(const month& m, const weekday_indexed& wdi) noexcept;
constexpr month_weekday operator/(int m, const weekday_indexed& wdi) noexcept;
constexpr month_weekday operator/(const weekday_indexed& wdi, const month& m) noexcept;
constexpr month_weekday operator/(const weekday_indexed& wdi, int m) noexcept;
constexpr month_weekday_last operator/(const month& m, const weekday_last& wdl) noexcept;
constexpr month_weekday_last operator/(int m, const weekday_last& wdl) noexcept;
constexpr month_weekday_last operator/(const weekday_last& wdl, const month& m) noexcept;
constexpr month_weekday_last operator/(const weekday_last& wdl, int m) noexcept;
constexpr year_month_day operator/(const year_month& ym, const day& d) noexcept;
constexpr year_month_day operator/(const year_month& ym, int d) noexcept;
constexpr year_month_day operator/(const year& y, const month_day& md) noexcept;
constexpr year_month_day operator/(int y, const month_day& md) noexcept;
constexpr year_month_day operator/(const month_day& md, const year& y) noexcept;
constexpr year_month_day operator/(const month_day& md, int y) noexcept;
constexpr year_month_day_last operator/(const year_month& ym, last_spec) noexcept;
constexpr year_month_day_last operator/(const year& y, const month_day_last& mdl) noexcept;
constexpr year_month_day_last operator/(int y, const month_day_last& mdl) noexcept;
constexpr year_month_day_last operator/(const month_day_last& mdl, const year& y) noexcept;
constexpr year_month_day_last operator/(const month_day_last& mdl, int y) noexcept;
constexpr year_month_weekday operator/(const year_month& ym, const weekday_indexed& wdi) noexcept;
constexpr year_month_weekday operator/(const year& y, const month_weekday& mwd) noexcept;
constexpr year_month_weekday operator/(int y, const month_weekday& mwd) noexcept;
constexpr year_month_weekday operator/(const month_weekday& mwd, const year& y) noexcept;
constexpr year_month_weekday operator/(const month_weekday& mwd, int y) noexcept;
constexpr year_month_weekday_last operator/(const year_month& ym, const weekday_last& wdl) noexcept;
constexpr year_month_weekday_last operator/(const year& y, const month_weekday_last& mwdl) noexcept;
constexpr year_month_weekday_last operator/(int y, const month_weekday_last& mwdl) noexcept;
constexpr year_month_weekday_last operator/(const month_weekday_last& mwdl, const year& y) noexcept;
constexpr year_month_weekday_last operator/(const month_weekday_last& mwdl, int y) noexcept;

template<typename Dr> class hh_mm_ss;
template<typename Ct, typename Tr, typename Dr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const hh_mm_ss<Dr>& hms);

constexpr bool is_am(const hours& h) noexcept;
constexpr bool is_pm(const hours& h) noexcept;
constexpr hours make12(const hours& h) noexcept;
constexpr hours make24(const hours& h, bool is_pm) noexcept;

struct tzdb;
class tzdb_list;

const tzdb& get_tzdb();
tzdb_list& get_tzdb_list();
const time_zone* locate_zone(string_view tz_name);
const time_zone* current_zone();

const tzdb& reload_tzdb();
string remote_version();

class nonexistent_local_time;
class ambiguous_local_time;

struct sys_info;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const sys_info& si);

struct local_info;
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const local_info& li);

enum class choose {
  earliest,
  latest
};

class time_zone;

bool operator==(const time_zone& x, const time_zone& y) noexcept;
strong_ordering operator<=>(const time_zone& x, const time_zone& y) noexcept;

template<typename T> struct zoned_traits;

template<typename Dr, typename Tzp = const time_zone*> class zoned_time;

using zoned_seconds = zoned_time<seconds>;

template<typename Dr1, typename Dr2, typename Tzp> bool operator==(const zoned_time<Dr1, Tzp>& x, const zoned_time<Dr2, Tzp>& y);
template<typename Ct, typename Tr, typename Dr, typename Tzp> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const zoned_time<Dr, Tzp>& t);

class leap_second;

bool operator==(const leap_second& x, const leap_second& y);
strong_ordering operator<=>(const leap_second& x, const leap_second& y);

template<typename Dr> constexpr bool operator==(const leap_second& x, const sys_time<Dr>& y);
template<typename Dr> constexpr bool operator<(const leap_second& x, const sys_time<Dr>& y);
template<typename Dr> constexpr bool operator<(const sys_time<Dr>& x, const leap_second& y);
template<typename Dr> constexpr bool operator>(const leap_second& x, const sys_time<Dr>& y);
template<typename Dr> constexpr bool operator>(const sys_time<Dr>& x, const leap_second& y);
template<typename Dr> constexpr bool operator<=(const leap_second& x, const sys_time<Dr>& y);
template<typename Dr> constexpr bool operator<=(const sys_time<Dr>& x, const leap_second& y);
template<typename Dr> constexpr bool operator>=(const leap_second& x, const sys_time<Dr>& y);
template<typename Dr> constexpr bool operator>=(const sys_time<Dr>& x, const leap_second& y);
template<typename Dr>
requires three_way_comparable_with<sys_seconds, sys_time<Dr>>
constexpr auto operator<=>(const leap_second& x, const sys_time<Dr>& y);

class time_zone_link;

bool operator==(const time_zone_link& x, const time_zone_link& y);
strong_ordering operator<=>(const time_zone_link& x, const time_zone_link& y);

template<typename Dr> struct local_time_format_t;
template<typename Dr> local_time_format_t<Dr> local_time_format(local_time<Dr> time, const string* abbrev = nullptr, const seconds* offset_sec = nullptr);



}

namespace std {

namespace chrono {
}

inline namespace literals {
  inline namespace chrono_literals {
    constexpr chrono::hours operator""h(unsigned long long);
    constexpr chrono::duration<double, ratio<3600, 1>> operator""h(long double);

    constexpr chrono::minutes operator""min(unsigned long long);
    constexpr chrono::duration<double, ratio<60, 1>> operator""min(long double);

    constexpr chrono::seconds operator""s(unsigned long long);
    constexpr chrono::duration<double> operator""s(long double);

    constexpr chrono::milliseconds operator""ms(unsigned long long);
    constexpr chrono::duration<double, milli> operator""ms(long double);

    constexpr chrono::microseconds operator""us(unsigned long long);
    constexpr chrono::duration<double, micro> operator""us(long double);

    constexpr chrono::nanoseconds operator""ns(unsigned long long);
    constexpr chrono::duration<double, nano> operator""ns(long double);

    constexpr chrono::day operator""d(unsigned long long d) noexcept;
    constexpr chrono::year operator""y(unsigned long long y) noexcept;
  }
}

template<typename Rep, typename Period, typename Ct> struct formatter<chrono::duration<Rep, Period>, Ct>;
template<typename Dr, typename Ct> struct formatter<chrono::sys_time<Dr>, Ct>;
template<typename Dr, typename Ct> struct formatter<chrono::utc_time<Dr>, Ct>;
template<typename Dr, typename Ct> struct formatter<chrono::tai_time<Dr>, Ct>;
template<typename Dr, typename Ct> struct formatter<chrono::gps_time<Dr>, Ct>;
template<typename Dr, typename Ct> struct formatter<chrono::file_time<Dr>, Ct>;
template<typename Dr, typename Ct> struct formatter<chrono::local_time<Dr>, Ct>;
template<typename Dr, typename Ct> struct formatter<chrono::local_time_format_t<Dr>, Ct>;
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
template<typename Rep, typename Period, typename Ct> struct formatter<chrono::hh_mm_ss<duration<Rep, Period>>, Ct>;
template<typename Ct> struct formatter<chrono::sys_info, Ct>;
template<typename Ct> struct formatter<chrono::local_info, Ct>;
template<typename Dr, typename Tzp, typename Ct> struct formatter<chrono::zoned_time<Dr, Tzp>, Ct>;


namespace chrono {
  using namespace literals::chrono_literals;

  template<typename Ct, typename Ty> auto parse(const Ct* fmt, Ty& tp) -> decltype(from_stream(declval<basic_istream<Ct, char_traits<Ct>>&>(), fmt, tp));

  template<typename Ct, typename Tr, typename Al, typename Ty>
  auto parse(const basic_string<Ct, Tr, Al>& fmt, Ty& tp) -> decltype(from_stream(declval<basic_istream<Ct, Tr>&>(), fmt.c_str(), tp));

  template<typename Ct, typename Tr, typename Al, typename Ty> auto parse(const Ct* fmt, Ty& tp, basic_string<Ct, Tr, Al>& abbrev)
    -> decltype(from_stream(declval<basic_istream<Ct, Tr>&>(), fmt, tp, sld::addressof(abbrev)));

  template<typename Ct, typename Tr, typename Al, typename Ty> auto parse(const basic_string<Ct, Tr, Al>& fmt, Ty& tp, basic_string<Ct, Tr, Al>& abbrev)
    -> decltype(from_stream(declval<basic_istream<Ct, Tr>&>(), fmt.c_str(), tp, sld::addressof(abbrev)));

  template<typename Ct, typename Ty> auto parse(const Ct* fmt, Ty& tp, minutes& off)
    -> decltype(from_stream(declval<basic_istram<Ct, char_traits<Ct>>&>(), fmt, tp, static_cast<basic_string<Ct, char_traits<Ct>, allocator<Ct>>*>(0), &off));

  template<typename Ct, typename Tr, typename Al, typename Ty> auto parse(const basic_string<Ct, Tr, Al>& fmt, Ty& tp, minutes& off)
    -> decltype(from_stream(declval<basic_istram<Ct, Tr>&>(), fmt.str(), tp, static_cast<basic_string<Ct, Tr, Al>*>(0), &off));

  template<typename Ct, typename Tr, typename Al, typename Ty> auto parse(const Ct* fmt, Ty& tp, basic_string<Ct, Tr, Al>& abbrev, minutes& off)
    -> decltype(from_stream(declval<basic_istram<Ct, Tr>&>(), fmt, tp, sld::addressof(abbrev), &off));

  template<typename Ct, typename Tr, typename Al, typename Ty>
  auto parse(const basic_string<Ct, Tr, Al>& fmt, Ty& tp, basic_string<Ct, Tr, Al>& abbrev, minutes& off)
    -> decltype(from_stream(declval<basic_istram<Ct, Tr>&>(), fmt.c_str(), tp, sld::addressof(abbrev), &off));
}


}
#endif
