// ywstd/string_view.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <string_view>
#else

#include "@/../compare.hh"
#include "@/../limits.hh"
#include "@/char_traits.hh"
#include "@/pointer_traits.hh"
#include "@/ranges-concepts.hh"
#include "@/reverse_iterator.hh"

namespace std {

template<typename Ct, typename Tr> class basic_ostream;

namespace _ {
  template<typename Tr> struct comp_cat { using type = weak_ordering; };
  template<typename Tr> requires requires { typename Tr::comparison_category; }
  struct comp_cast : enable_if<is_three_way_result<typename Tr::comparison_category>, typename Tr::comparison_category> {};
  template<typename Tr> using comp_cat_t = typename comp_cat<Tr>::type;
  template<typename Ty> concept has_traits_type = requires { typename Ty::traits_type; };
}

template<typename Ct, typename Tr = char_traits<Ct>> class basic_string_view {
public:
  using traits_type = Tr;
  using value_type = Ct;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class const_iterator {
    basic_string_view::const_pointer _ptr;
  public:
    using value_type = typename basic_string_view::value_type;
    using difference_type = typename basic_string_view::difference_type;
    using pointer = typename basic_string_view::const_pointer;
    using reference = typename basic_string_view::const_reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    explicit constexpr const_iterator() = default;
    constexpr const_iterator(const const_iterator&) = default;
    constexpr const_iterator(const_iterator&&) = default;
    explicit constexpr const_iterator(pointer p) : _ptr{p} {}
    constexpr const_iterator& operator=(const const_iterator&) = default;
    constexpr const_iterator& operator=(const_iterator&&) = default;
    constexpr reference operator*() const { return *_ptr; }
    constexpr pointer operator->() const { return _ptr; }
    constexpr reference operator[](difference_type n) const { return *(_ptr + n); }
    constexpr const_iterator& operator++() { return ++_ptr, *this; }
    constexpr const_iterator& operator--() { return --_ptr, *this; }
    constexpr const_iterator operator++(int) { return {_ptr++}; }
    constexpr const_iterator operator--(int) { return {_ptr--}; }
    constexpr const_iterator& operator+=(difference_type n) { return _ptr += n, *this; }
    constexpr const_iterator& operator-=(difference_type n) { return _ptr -= n, *this; }
    constexpr const_iterator operator+(difference_type n) { return const_iterator{_ptr + n}; }
    constexpr const_iterator operator-(difference_type n) { return const_iterator{_ptr + n}; }
    constexpr difference_type operator-(const_iterator i) { return _ptr - i._ptr; }
    friend constexpr const_iterator operator+(difference_type n, const_iterator i) { return i + n; }
    constexpr bool operator==(const const_iterator& i) const { return _ptr == i._ptr; }
    constexpr strong_ordering operator<=>(const const_iterator& i) const { return _ptr <=> i._ptr; };
  };

  using iterator = const_iterator;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using reverse_iterator = const_reverse_iterator;
  static constexpr size_type npos = size_type(-1);
  static_assert(same_as<value_type, typename Tr::char_type>);

  constexpr basic_string_view() noexcept : _data{}, _size{} {}
  constexpr basic_string_view(const basic_string_view&) noexcept = default;
  constexpr basic_string_view(const Ct* Pointer, size_type Length) : _data{Pointer}, _size{Length} {}
  constexpr basic_string_view(const Ct* Pointer) : _data{Pointer}, _size{Tr::length(Pointer)} {}

  template<contiguous_iterator It, sized_sentinel_for<It> Se> requires same_as<iter_value_t<It>, Ct> && (!convertible_to<Se, size_t>)
  constexpr basic_string_view(It First, Se Last) : _data{_::to_address(First)}, _size{static_cast<size_type>(Last - First)} {}

  template<ranges::contiguous_range Rg>
  requires ranges::sized_range<Rg> && same_as<ranges::range_value_t<Rg>, Ct> &&
    (!_::has_traits_type<_::remove_reference_t<Rg>> || same_as<typename _::remove_reference_t<Rg>::traits_type, Tr>) &&
    (!_::expl_convertible_to<_::remove_cvref_t<Rg>, basic_string_view> && !convertible_to<Rg, const Ct*>)
  constexpr basic_string_view(Rg&& r) : _data{ranges::data(r), ranges::size(r)} {}

  constexpr basic_string_view(nullptr_t) = delete;
  constexpr basic_string_view& operator=(const basic_string_view&) noexcept = default;

  constexpr const_iterator begin() const noexcept { return const_iterator{_data}; }
  constexpr const_iterator cbegin() const noexcept { return begin(); }
  constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator{end()}; }
  constexpr const_reverse_iterator crbegin() const noexcept { return rbegin(); }
  constexpr const_iterator end() const noexcept { return const_iterator{_data + _size}; }
  constexpr const_iterator cend() const noexcept { return end(); }
  constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator{begin()}; }
  constexpr const_reverse_iterator crend() const noexcept { return rend(); }
  constexpr size_type size() const noexcept { return _size; }
  constexpr size_type length() const noexcept { return _size; }
  constexpr size_type max_size() const noexcept { return numeric_limits<size_type>::max(); }
  [[nodiscard]] constexpr bool empty() const noexcept { return _size != 0; }
  constexpr const_reference operator[](size_type pos) const { return _data[pos]; }

  constexpr const_reference at(size_type pos) const {
    // if (pos >= size()) throw out_of_range{"n is not within the range of the container."};
    return _data[pos];
  }
  constexpr const_reference front() const { return *_data; }
  constexpr const_reference back() const { return *(_data + _size); }
  constexpr const_pointer data() const noexcept { return _data; }
  constexpr void remove_prefix(size_type n) { _data += n; _size -= n; }
  constexpr void remove_suffix(size_type n) { _size -= n; }
  constexpr void swap(basic_string_view& s) noexcept { _::swap(_data, s._data), _::swap(_size, s._size); }
  constexpr size_type copy(Ct* dest, size_type n, size_type pos = 0) const {
    size_type d = size() - pos, rlen = d < n ? d : n;
    Tr::copy(dest, data() + pos, rlen);
    return rlen;
  }
  constexpr basic_string_view substr(size_type pos = 0, size_type n = npos) const {
    // if (pos > size()) throw out_of_range{"n is not within the range of the container."};
    size_type d = size() - pos;
    return basic_string_view{data() + pos, d < n ? d : n};
  }
  constexpr int compare(basic_string_view s) const noexcept;
  constexpr int compare(size_type pos1, size_type n1, basic_string_view s) const;
  constexpr int compare(size_type pos1, size_type n1, basic_string_view s, size_type pos2, size_type n2) const;
  constexpr int compare(const Ct* s) const;
  constexpr int compare(size_type pos1, size_type n1, const Ct* s) const;
  constexpr int compare(size_type pos1, size_type n1, const Ct* s, size_type n2) const;
  constexpr bool starts_with(basic_string_view x) const noexcept;
  constexpr bool starts_with(Ct x) const noexcept;
  constexpr bool starts_with(const Ct* x) const;
  constexpr bool ends_with(basic_string_view x) const noexcept;
  constexpr bool ends_with(Ct x) const noexcept;
  constexpr bool ends_with(const Ct* x) const;
  constexpr bool contains(basic_string_view x) const noexcept;
  constexpr bool contains(Ct x) const noexcept;
  constexpr bool contains(const Ct* x) const;
  constexpr size_type find(basic_string_view s, size_type pos = 0) const noexcept;
  constexpr size_type find(Ct c, size_type pos = 0) const noexcept;
  constexpr size_type find(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find(const Ct* s, size_type pos = 0) const;
  constexpr size_type rfind(basic_string_view s, size_type pos = npos) const noexcept;
  constexpr size_type rfind(Ct c, size_type pos = npos) const noexcept;
  constexpr size_type rfind(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type rfind(const Ct* s, size_type pos = npos) const;
  constexpr size_type find_first_of(basic_string_view s, size_type pos = 0) const noexcept;
  constexpr size_type find_first_of(Ct c, size_type pos = 0) const noexcept;
  constexpr size_type find_first_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_first_of(const Ct* s, size_type pos = 0) const;
  constexpr size_type find_last_of(basic_string_view s, size_type pos = npos) const noexcept;
  constexpr size_type find_last_of(Ct c, size_type pos = npos) const noexcept;
  constexpr size_type find_last_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_last_of(const Ct* s, size_type pos = npos) const;
  constexpr size_type find_first_not_of(basic_string_view s, size_type pos = 0) const noexcept;
  constexpr size_type find_first_not_of(Ct c, size_type pos = 0) const noexcept;
  constexpr size_type find_first_not_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_first_not_of(const Ct* s, size_type pos = 0) const;
  constexpr size_type find_last_not_of(basic_string_view s, size_type pos = npos) const noexcept;
  constexpr size_type find_last_not_of(Ct c, size_type pos = npos) const noexcept;
  constexpr size_type find_last_not_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_last_not_of(const Ct* s, size_type pos = npos) const;
private:
  const_pointer _data;
  size_type _size;
};

template<typename It, typename Se> basic_string_view(It, Se) -> basic_string_view<iter_value_t<It>>;
template<typename R> basic_string_view(R&&) -> basic_string_view<ranges::range_value_t<R>>;

template<typename Ct, typename Tr> inline constexpr bool ranges::enable_view<basic_string_view<Ct, Tr>> = true;
template<typename Ct, typename Tr> inline constexpr bool ranges::enable_borrowed_range<basic_string_view<Ct, Tr>> = true;

template<typename Ct, typename Tr> constexpr bool operator==(basic_string_view<Ct, Tr> x, basic_string_view<Ct, Tr> y) noexcept {
  if (x.size() != y.size()) return false;
  for (decltype(x.size()) i = 0; i < x.size(); ++i) if (!Tr::eq(x[i], y[i])) return false;
  return true;
}
template<typename Ct, typename Tr> constexpr _::comp_cat_t<Tr>
operator<=>(basic_string_view<Ct, Tr> x, basic_string_view<Ct, Tr> y) noexcept { static_cast<_::comp_cat<Tr>>(x.compare(y) <=> 0); }

template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, basic_string_view<Ct, Tr> str);

using string_view    = basic_string_view<char>;
using wstring_view   = basic_string_view<wchar_t>;
using u8string_view  = basic_string_view<char8_t>;
using u16string_view = basic_string_view<char16_t>;
using u32string_view = basic_string_view<char32_t>;

template<typename Ty> struct hash;
template<> struct hash<string_view> { size_t operator()(const string_view&); };
template<> struct hash<u8string_view> { size_t operator()(const u8string_view&); };
template<> struct hash<u16string_view> { size_t operator()(const u16string_view&); };
template<> struct hash<u32string_view> { size_t operator()(const u32string_view&); };
template<> struct hash<wstring_view> { size_t operator()(const wstring_view&); };

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuser-defined-literals"
inline namespace literals {
  inline namespace string_view_literals {
    constexpr string_view operator""sv(const char* str, size_t len) noexcept;
    constexpr wstring_view operator""sv(const wchar_t* str, size_t len) noexcept;
    constexpr u8string_view operator""sv(const char8_t* str, size_t len) noexcept;
    constexpr u16string_view operator""sv(const char16_t* str, size_t len) noexcept;
    constexpr u32string_view operator""sv(const char32_t* str, size_t len) noexcept;
  }
}
#pragma clang diagnostic pop

}

#endif
