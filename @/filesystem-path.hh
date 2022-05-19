// ywstd/@/filesystem-path.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/../string_view.hh"
#include "../@/allocator.hh"
#include "../@/basic_string.hh"
#include "../@/char_traits.hh"
#include "../@/locale.hh"

namespace std {

using string = basic_string<char>;
using wstring = basic_string<wchar_t>;
using u8string = basic_string<char8_t>;
using u16string = basic_string<char16_t>;
using u32string = basic_string<char32_t>;

template<typename Ct, typename Tr> class basic_istream;
template<typename Ct, typename Tr> class basic_ostream;

}

namespace std::filesystem {

class path {
public:
  using value_type = wchar_t;
  using string_type = basic_string<value_type>;

  class iterator {
  public:
    using iterator_category = input_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = path;
    using pointer = const path*;
    using reference = const path&;
    reference operator*() const;
    pointer operator->() const;
    iterator& operator++() const;
    iterator operator++(int) const;
    iterator& operator--() const;
    iterator operator--(int) const;
    friend bool operator==(const iterator&, const iterator&);
  };

  using const_iterator = iterator;

  enum format {
    native_format,
    generic_format,
    auto_format
  };

  static constexpr value_type preferred_separator = L'\\';

  ~path();
  path() noexcept;
  path(const path& p);
  path(path&& p) noexcept;
  path(string_type&& source, format fmt = auto_format);
  template<typename Source> path(const Source& source, format fmt = auto_format);
  template<typename InputIt> path(InputIt first, InputIt last, format fmt = auto_format);
  template<typename Source> path(const Source& source, const locale& loc, format fmt = auto_format);
  template<typename InputIt> path(InputIt first, InputIt last, const locale& loc, format fmt = auto_format);

  path& operator=(const path& p);
  path& operator=(path&& p) noexcept;
  path& operator=(string_type&& source);
  path& assign(string_type&& source);
  template<typename Source> path& operator=(const Source& source);
  template<typename Source> path& assign(const Source& source);
  template<typename InputIt> path& assign(InputIt first, InputIt last);

  path& operator/=(const path& p);
  template<typename Source> path& operator/=(const Source& source);
  template<typename Source> path& append(const Source& source);
  template<typename InputIt> path& append(InputIt first, InputIt last);

  path& operator+=(const path& x);
  path& operator+=(const string_type& x);
  path& operator+=(basic_string_view<value_type> x);
  path& operator+=(const value_type* x);
  path& operator+=(value_type x);
  template<typename Source> path& operator+=(const Source& x);
  template<typename ECt> path& operator+=(ECt x);
  template<typename Source> path& concat(const Source& x);
  template<typename InputIt> path& concat(InputIt first, InputIt last);

  void clear() noexcept;
  path& make_preferred();
  path& remove_filename();
  path& replace_filename(const path& replacement);
  path& replace_extension(const path& replacement = path());
  void swap(path& rhs) noexcept;

  friend bool operator==(const path& lhs, const path& rhs) noexcept;
  friend strong_ordering operator<=>(const path& lhs, const path& rhs) noexcept;
  friend path operator/(const path& lhs, const path& rhs);

  const string_type& native() const noexcept;
  const value_type* c_str() const noexcept;
  operator string_type() const;

  template<typename ECt, typename Tr = char_traits<ECt>, typename Al = allocator<ECt>>
  basic_string<ECt, Tr, Al> string(const Al& a = Al()) const;

  std::string string() const;
  std::wstring wstring() const;
  std::u8string u8string() const;
  std::u16string u16string() const;
  std::u32string u32string() const;

  template<typename ECt, typename Tr = char_traits<ECt>, typename Al = allocator<ECt>>
  basic_string<ECt, Tr, Al> generic_string(const Al& a = Al()) const;

  std::string generic_string() const;
  std::wstring generic_wstring() const;
  std::u8string generic_u8string() const;
  std::u16string generic_u16string() const;
  std::u32string generic_u32string() const;

  int compare(const path& p) const noexcept;
  int compare(const string_type& s) const;
  int compare(basic_string_view<value_type> s) const;
  int compare(const value_type* s) const;

  path root_name() const;
  path root_directory() const;
  path root_path() const;
  path relative_path() const;
  path parent_path() const;
  path filename() const;
  path stem() const;
  path extension() const;

  [[nodiscard]] bool empty() const noexcept;
  bool has_root_name() const;
  bool has_root_directory() const;
  bool has_root_path() const;
  bool has_relative_path() const;
  bool has_parent_path() const;
  bool has_filename() const;
  bool has_stem() const;
  bool has_extension() const;
  bool is_absolute() const;
  bool is_relative() const;

  path lexically_normal() const;
  path lexically_relative(const path& base) const;
  path lexically_proximate(const path& base) const;

  iterator begin() const;
  iterator end() const;

  template<typename Ct, typename Tr> friend basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const path& p);
  template<typename Ct, typename Tr> friend basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, path& p);
};

}
