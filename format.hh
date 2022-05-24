// ywstd/format.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <format>
#else

#include "@/../string_view.hh"
#include "@/back_insert_iterator.hh"
#include "@/basic_string.hh"
#include "@/formatter.hh"
#include "@/locale.hh"

namespace std {

using string = basic_string<char>;
using wstring = basic_string<wchar_t>;

using string_view = basic_string_view<char>;
using wstring_view = basic_string_view<wchar_t>;

namespace _ {
  template<typename Ty> class format_buffer { void push_back(Ty Value); };
  template<typename Context, typename... As> struct format_arg_store {};
  template<typename Ct, typename... As> struct basic_format_string { template<typename Ty> consteval basic_format_string(const Ty&) {} };
  template<typename... As> using format_string = basic_format_string<char, typename type_identity<As>::type...>;
  template<typename... As> using wformat_string = basic_format_string<wchar_t, typename type_identity<As>::type...>;
}

using format_parse_context = basic_format_parse_context<char>;
using wformat_parse_context = basic_format_parse_context<wchar_t>;

template<typename Context> class basic_format_arg {
public:
  class handle {
    template<typename Ty> explicit handle(Ty&&) noexcept;
    void format(basic_format_parse_context<typename Context::char_type>&, Context&) const;
  };
  basic_format_arg() noexcept;
  explicit operator bool() const noexcept;
};

template<typename Ot, typename Ct> class basic_format_context {
public:
  using iterator = Ot;
  using char_type = Ct;
  template<typename Ty> using formatter_type = formatter<Ty, Ct>;
  basic_format_arg<basic_format_context> arg(size_t id) const;
  locale locale();
  iterator out();
  void advance_to(iterator it);
};
using format_context = basic_format_context<back_insert_iterator<_::format_buffer<char>>, char>;
using wformat_context = basic_format_context<back_insert_iterator<_::format_buffer<wchar_t>>, wchar_t>;

template<typename Context> class basic_format_args {
public:
  basic_format_args() noexcept;
  template<typename... As> basic_format_args(const _::format_arg_store<Context, As...>&) noexcept;
  basic_format_arg<Context> get(size_t i) const noexcept;
};
using format_args = basic_format_args<format_context>;
using wformat_args = basic_format_args<wformat_context>;

template<typename... As> string format(_::format_string<As...> fmt, As&&... args);
template<typename... As> wstring format(_::wformat_string<As...> fmt, As&&... args);
template<typename... As> string format(const locale& loc, _::format_string<As...> fmt, As&&... args);
template<typename... As> wstring format(const locale& loc, _::wformat_string<As...> fmt, As&&... args);

string vformat(string_view fmt, format_args args);
wstring vformat(wstring_view fmt, wformat_args args);
string vformat(const locale& loc, string_view fmt, format_args args);
wstring vformat(const locale& loc, wstring_view fmt, wformat_args args);

template<typename Ot, typename... As> Ot format_to(Ot out, _::format_string<As...> fmt, As&&... args);
template<typename Ot, typename... As> Ot format_to(Ot out, _::wformat_string<As...> fmt, As&&... args);
template<typename Ot, typename... As> Ot format_to(Ot out, const locale& loc, _::format_string<As...> fmt, As&&... args);
template<typename Ot, typename... As> Ot format_to(Ot out, const locale& loc, _::wformat_string<As...> fmt, As&&... args);

template<typename Ot> Ot vformat_to(Ot out, string_view fmt, format_args args);
template<typename Ot> Ot vformat_to(Ot out, wstring_view fmt, wformat_args args);
template<typename Ot> Ot vformat_to(Ot out, const locale& loc, string_view fmt, format_args args);
template<typename Ot> Ot vformat_to(Ot out, const locale& loc, wstring_view fmt, wformat_args args);

template<typename Ot> struct format_to_n_result {
  Ot out;
  iter_difference_t<Ot> size;
};

template<typename Ot, typename... As> format_to_n_result<Ot> format_to_n(Ot out, iter_difference_t<Ot> n, _::format_string<As...> fmt, As&&... args);
template<typename Ot, typename... As> format_to_n_result<Ot> format_to_n(Ot out, iter_difference_t<Ot> n, _::wformat_string<As...> fmt, As&&... args);
template<typename Ot, typename... As> format_to_n_result<Ot> format_to_n(Ot out, iter_difference_t<Ot> n, const locale& loc, _::format_string<As...> fmt, As&&... args);
template<typename Ot, typename... As> format_to_n_result<Ot> format_to_n(Ot out, iter_difference_t<Ot> n, const locale& loc, _::wformat_string<As...> fmt, As&&... args);

template<typename... As> size_t formatted_size(_::format_string<As...> fmt, As&&... args);
template<typename... As> size_t formatted_size(_::wformat_string<As...> fmt, As&&... args);
template<typename... As> size_t formatted_size(const locale& loc, _::format_string<As...> fmt, As&&... args);
template<typename... As> size_t formatted_size(const locale& loc, _::wformat_string<As...> fmt, As&&... args);

template<typename Visitor, typename Context> auto visit_format_arg(Visitor&& vis, basic_format_arg<Context> arg);
template<typename Context = format_context, typename... As> _::format_arg_store<Context, As...> make_format_args(As&&... args);
template<typename... As> _::format_arg_store<wformat_context, As...> make_wformat_args(As&&... args);

}

#endif
