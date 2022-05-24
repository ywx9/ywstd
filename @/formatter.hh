// ywstd/@/formatter.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/../stdexcept.hh"
#include "../@/../string_view.hh"
#include "../@/basic_string.hh"

namespace std {

class format_error : runtime_error {
public:
  explicit format_error(const string&);
  explicit format_error(const char*);
};

template<typename Ct> class basic_format_parse_context {
public:
  using char_type = Ct;
  using const_iterator = typename basic_string_view<Ct>::const_iterator;
  using iterator = const_iterator;
private:
  basic_string_view<Ct> _view;
  size_t _num_args; ptrdiff_t _next_arg_id{};
public:
  constexpr explicit basic_format_parse_context(basic_string_view<Ct> fmt, size_t num_args = 0) noexcept : _view{fmt}, _num_args{num_args} {}
  basic_format_parse_context(const basic_format_parse_context&) = delete;
  basic_format_parse_context& operator=(const basic_format_parse_context&) = delete;
  constexpr const_iterator begin() const noexcept { return _view.begin(); }
  constexpr const_iterator end() const noexcept { return _view.end(); }
  constexpr void advance_to(const_iterator i) { _view.remove_prefix(static_cast<size_t>(i - begin())); }
  constexpr size_t next_arg_id() {
    if (_next_arg_id < 0) throw format_error{"*this has already entered manual argument indexing mode."};
    return _next_arg_id++;
  }
  constexpr void check_arg_id(size_t id) {
    if (_next_arg_id > 0) throw format_error{"*this has already entered automatic argument indexing mode."};
    if (id >= _num_args) _::non_constant_expression("id is larger than or equal to the argument count provided in the constructor.");
    _next_arg_id = -1;
  }
};

namespace _ {
  template<typename Ty> concept formatter_char_type = included_in<Ty, char, wchar_t>;
  template<typename Ty> concept formatter_arithmetic = included_in<Ty, bool, signed char, short, int, long, long long,
    unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, float, double, long double>;
}

template<typename Ty, typename Ct = char> struct formatter {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
};

template<> struct formatter<char, char> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<char>::iterator parse(basic_format_parse_context<char>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const char& Value, FormatContext& Context) const;
};

template<> struct formatter<char, wchar_t> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<wchar_t>::iterator parse(basic_format_parse_context<wchar_t>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const char& Value, FormatContext& Context) const;
};

template<> struct formatter<wchar_t, wchar_t> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<wchar_t>::iterator parse(basic_format_parse_context<wchar_t>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const wchar_t& Value, FormatContext& Context) const;
};

template<_::formatter_char_type Ct> struct formatter<Ct*, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(Ct* const& Value, FormatContext& Context) const;
};

template<_::formatter_char_type Ct> struct formatter<const Ct*, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const Ct* const& Value, FormatContext& Context) const;
};

template<_::formatter_char_type Ct, size_t Nx> struct formatter<const Ct[Nx], Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const Ct(&Value)[Nx], FormatContext& Context) const;
};

template<_::formatter_char_type Ct, typename Tr, typename Al> struct formatter<basic_string<Ct, Tr, Al>, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const basic_string<Ct, Tr, Al>& Value, FormatContext& Context) const;
};

template<_::formatter_char_type Ct, typename Tr> struct formatter<basic_string_view<Ct, Tr>, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const basic_string_view<Ct, Tr>& Value, FormatContext& Context) const;
};

template<_::formatter_arithmetic Ty, _::formatter_char_type Ct> struct formatter<Ty, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const Ty& Value, FormatContext& Context) const;
};

template<_::formatter_char_type Ct> struct formatter<nullptr_t, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const nullptr_t& Value, FormatContext& Context) const;
};

template<_::formatter_char_type Ct> struct formatter<void*, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(void* const& Value, FormatContext& Context) const;
};

template<_::formatter_char_type Ct> struct formatter<const void*, Ct> {
  formatter() = delete;
  formatter(const formatter&) = delete;
  formatter operator=(const formatter&) = delete;
  constexpr typename basic_format_parse_context<Ct>::iterator parse(basic_format_parse_context<Ct>& Context);
  template<typename FormatContext> typename FormatContext::iterator format(const void* const& Value, FormatContext& Context) const;
};


}
