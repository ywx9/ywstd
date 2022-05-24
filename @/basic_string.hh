// ywstd/@/basic_string.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/../initializer_list.hh"
#include "../@/../string_view.hh"
#include "../@/allocator.hh"
#include "../@/char_traits.hh"
#include "../@/reverse_iterator.hh"

namespace std {

template<typename Ct, typename Tr> class basic_istream;
template<typename Ct, typename Tr> class basic_ostream;

template<typename Ct, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>> class basic_string {
public:
  using traits_type = Tr;
  using value_type = Ct;
  using allocator_type = Al;
  using size_type = typename allocator_traits<Al>::size_type;
  using difference_type = typename allocator_traits<Al>::difference_type;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;

  class iterator {
    typename basic_string::pointer _ptr;
  public:
    using value_type = typename basic_string::value_type;
    using difference_type = typename basic_string::difference_type;
    using pointer = typename basic_string::pointer;
    using reference = typename basic_string::reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    constexpr iterator() = default;
    constexpr iterator(const iterator&) = default;
    constexpr iterator(iterator&&) = default;
    constexpr iterator(basic_string::pointer p) : _ptr{p} {}
    constexpr iterator& operator=(const iterator&) = default;
    constexpr iterator& operator=(iterator&&) = default;
    constexpr reference operator*() const { return *_ptr; }
    constexpr pointer operator->() const { return _ptr; }
    constexpr reference operator[](difference_type n) const { return *(_ptr + n); }
    constexpr iterator& operator++() { return ++_ptr, *this; }
    constexpr iterator& operator--() { return --_ptr, *this; }
    constexpr iterator operator++(int) { return {_ptr++}; }
    constexpr iterator operator--(int) { return {_ptr--}; }
    constexpr iterator& operator+=(difference_type n) { return _ptr += n, *this; }
    constexpr iterator& operator-=(difference_type n) { return _ptr -= n, *this; }
    constexpr iterator operator+(difference_type n) { return {_ptr + n}; }
    constexpr iterator operator-(difference_type n) { return {_ptr + n}; }
    constexpr difference_type operator-(const iterator& i) { return _ptr - i._ptr; }
    friend constexpr iterator operator+(difference_type n, const iterator& i) { return i + n; }
    constexpr bool operator==(const iterator& i) const { return _ptr == i._ptr; }
    constexpr strong_ordering operator<=>(const iterator& i) const { return _ptr <=> i._ptr; };
  };

  class const_iterator {
    typename basic_string::const_pointer _ptr;
  public:
    using value_type = typename basic_string::value_type;
    using difference_type = typename basic_string::difference_type;
    using pointer = typename basic_string::const_pointer;
    using reference = typename basic_string::const_reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    constexpr const_iterator() = default;
    constexpr const_iterator(const const_iterator&) = default;
    constexpr const_iterator(const_iterator&&) = default;
    constexpr const_iterator(basic_string::pointer p) : _ptr{p} {}
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
    constexpr const_iterator operator+(difference_type n) { return {_ptr + n}; }
    constexpr const_iterator operator-(difference_type n) { return {_ptr + n}; }
    constexpr difference_type operator-(const const_iterator& i) { return _ptr - i._ptr; }
    friend constexpr const_iterator operator+(difference_type n, const const_iterator& i) { return i + n; }
    constexpr bool operator==(const const_iterator& i) const { return _ptr == i._ptr; }
    constexpr strong_ordering operator<=>(const const_iterator& i) const { return _ptr <=> i._ptr; };
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  static const size_type npos = -1;
  static_assert(same_as<value_type, typename traits_type::char_type>);

  constexpr ~basic_string();
  constexpr basic_string() noexcept(noexcept(Al{})) : basic_string(Al{}) {}
  constexpr explicit basic_string(const Al& a) noexcept;
  constexpr basic_string(const basic_string& str);
  constexpr basic_string(basic_string&& str) noexcept;
  constexpr basic_string(const basic_string& str, size_type pos, const Al& a = Al());
  constexpr basic_string(const basic_string& str, size_type pos, size_type n, const Al& a = Al());
  template<typename C2> constexpr basic_string(const C2& t, size_type pos, size_type n, const Al& a = Al());
  template<typename C2> constexpr explicit basic_string(const C2& t, const Al& a = Al());
  constexpr basic_string(const Ct* s, size_type n, const Al& a = Al());
  constexpr basic_string(const Ct* s, const Al& a = Al());
  constexpr basic_string(nullptr_t) = delete;
  constexpr basic_string(size_type n, Ct c, const Al& a = Al());
  template<typename In> constexpr basic_string(In begin, In end, const Al& a = Al());
  constexpr basic_string(initializer_list<Ct>, const Al& = Al());
  constexpr basic_string(const basic_string&, const Al&);
  constexpr basic_string(basic_string&&, const Al&);
  constexpr basic_string& operator=(const basic_string& str);
  constexpr basic_string& operator=(basic_string&& str)
    noexcept(allocator_traits<Al>::propagate_on_container_move_assignment::value || allocator_traits<Al>::is_always_equal::value);
  template<typename C2> constexpr basic_string& operator=(const C2& t);
  constexpr basic_string& operator=(const Ct* s);
  constexpr basic_string& operator=(nullptr_t) = delete;
  constexpr basic_string& operator=(Ct c);
  constexpr basic_string& operator=(initializer_list<Ct>);
  constexpr iterator begin() noexcept;
  constexpr const_iterator begin() const noexcept;
  constexpr iterator end() noexcept;
  constexpr const_iterator end() const noexcept;
  constexpr reverse_iterator rbegin() noexcept;
  constexpr const_reverse_iterator rbegin() const noexcept;
  constexpr reverse_iterator rend() noexcept;
  constexpr const_reverse_iterator rend() const noexcept;
  constexpr const_iterator cbegin() const noexcept;
  constexpr const_iterator cend() const noexcept;
  constexpr const_reverse_iterator crbegin() const noexcept;
  constexpr const_reverse_iterator crend() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type length() const noexcept;
  constexpr size_type max_size() const noexcept;
  constexpr void resize(size_type n, Ct c);
  constexpr void resize(size_type n);
  template<typename Operation> constexpr void resize_and_overwrite(size_type n, Operation op);
  constexpr size_type capacity() const noexcept;
  constexpr void reserve(size_type res_arg);
  constexpr void shrink_to_fit();
  constexpr void clear() noexcept;
  [[nodiscard]] constexpr bool empty() const noexcept;
  constexpr const_reference operator[](size_type pos) const;
  constexpr reference operator[](size_type pos);
  constexpr const_reference at(size_type n) const;
  constexpr reference at(size_type n);
  constexpr const Ct& front() const;
  constexpr Ct& front();
  constexpr const Ct& back() const;
  constexpr Ct& back();
  constexpr basic_string& operator+=(const basic_string& str);
  template<typename C2> constexpr basic_string& operator+=(const C2& t);
  constexpr basic_string& operator+=(const Ct* s);
  constexpr basic_string& operator+=(Ct c);
  constexpr basic_string& operator+=(initializer_list<Ct>);
  constexpr basic_string& append(const basic_string& str);
  constexpr basic_string& append(const basic_string& str, size_type pos, size_type n = npos);
  template<typename C2> constexpr basic_string& append(const C2& t);
  template<typename C2> constexpr basic_string& append(const C2& t, size_type pos, size_type n = npos);
  constexpr basic_string& append(const Ct* s, size_type n);
  constexpr basic_string& append(const Ct* s);
  constexpr basic_string& append(size_type n, Ct c);
  template<typename In>
  constexpr basic_string& append(In first, In last);
  constexpr basic_string& append(initializer_list<Ct>);
  constexpr void push_back(Ct c);
  constexpr basic_string& assign(const basic_string& str);
  constexpr basic_string& assign(basic_string&& str)
    noexcept(allocator_traits<Al>::propagate_on_container_move_assignment::value || allocator_traits<Al>::is_always_equal::value);
  constexpr basic_string& assign(const basic_string& str, size_type pos, size_type n = npos);
  template<typename C2> constexpr basic_string& assign(const C2& t);
  template<typename C2> constexpr basic_string& assign(const C2& t, size_type pos, size_type n = npos);
  constexpr basic_string& assign(const Ct* s, size_type n);
  constexpr basic_string& assign(const Ct* s);
  constexpr basic_string& assign(size_type n, Ct c);
  template<typename In> constexpr basic_string& assign(In first, In last);
  constexpr basic_string& assign(initializer_list<Ct>);
  constexpr basic_string& insert(size_type pos, const basic_string& str);
  constexpr basic_string& insert(size_type pos1, const basic_string& str, size_type pos2, size_type n = npos);
  template<typename C2> constexpr basic_string& insert(size_type pos, const C2& t);
  template<typename C2> constexpr basic_string& insert(size_type pos1, const C2& t, size_type pos2, size_type n = npos);
  constexpr basic_string& insert(size_type pos, const Ct* s, size_type n);
  constexpr basic_string& insert(size_type pos, const Ct* s);
  constexpr basic_string& insert(size_type pos, size_type n, Ct c);
  constexpr iterator insert(const_iterator p, Ct c);
  constexpr iterator insert(const_iterator p, size_type n, Ct c);
  template<typename In> constexpr iterator insert(const_iterator p, In first, In last);
  constexpr iterator insert(const_iterator p, initializer_list<Ct>);
  constexpr basic_string& erase(size_type pos = 0, size_type n = npos);
  constexpr iterator erase(const_iterator p);
  constexpr iterator erase(const_iterator first, const_iterator last);
  constexpr void pop_back();
  constexpr basic_string& replace(size_type pos1, size_type n1, const basic_string& str);
  constexpr basic_string& replace(size_type pos1, size_type n1, const basic_string& str, size_type pos2, size_type n2 = npos);
  template<typename C2> constexpr basic_string& replace(size_type pos1, size_type n1, const C2& t);
  template<typename C2> constexpr basic_string& replace(size_type pos1, size_type n1, const C2& t, size_type pos2, size_type n2 = npos);
  constexpr basic_string& replace(size_type pos, size_type n1, const Ct* s, size_type n2);
  constexpr basic_string& replace(size_type pos, size_type n1, const Ct* s);
  constexpr basic_string& replace(size_type pos, size_type n1, size_type n2, Ct c);
  constexpr basic_string& replace(const_iterator i1, const_iterator i2, const basic_string& str);
  template<typename C2> constexpr basic_string& replace(const_iterator i1, const_iterator i2, const C2& t);
  constexpr basic_string& replace(const_iterator i1, const_iterator i2, const Ct* s, size_type n);
  constexpr basic_string& replace(const_iterator i1, const_iterator i2, const Ct* s);
  constexpr basic_string& replace(const_iterator i1, const_iterator i2, size_type n, Ct c);
  template<typename In> constexpr basic_string& replace(const_iterator i1, const_iterator i2, In j1, In j2);
  constexpr basic_string& replace(const_iterator, const_iterator, initializer_list<Ct>);
  constexpr size_type copy(Ct* s, size_type n, size_type pos = 0) const;
  constexpr void swap(basic_string& str) noexcept(allocator_traits<Al>::propagate_on_container_swap::value || allocator_traits<Al>::is_always_equal::value);
  constexpr const Ct* c_str() const noexcept;
  constexpr const Ct* data() const noexcept;
  constexpr Ct* data() noexcept;
  constexpr operator basic_string_view<Ct, Tr>() const noexcept;
  constexpr allocator_type get_allocator() const noexcept;
  template<typename C2> constexpr size_type find(const C2& t, size_type pos = 0) const
    noexcept(_::is_nothrow_convertible_v<const C2&, basic_string_view<Ct, Tr>>)
    requires _::is_convertible_v<const C2&, basic_string_view<Ct, Tr>> && (!_::is_convertible_v<const C2&, const Ct*>);
  constexpr size_type find(const basic_string& str, size_type pos = 0) const noexcept;
  constexpr size_type find(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find(const Ct* s, size_type pos = 0) const;
  constexpr size_type find(Ct c, size_type pos = 0) const noexcept;
  template<typename C2> constexpr size_type rfind(const C2& t, size_type pos = npos) const
    noexcept(_::is_nothrow_convertible_v<const C2&, basic_string_view<Ct, Tr>>)
    requires _::is_convertible_v<const C2&, basic_string_view<Ct, Tr>> && (!_::is_convertible_v<const C2&, const Ct*>);
  constexpr size_type rfind(const basic_string& str, size_type pos = npos) const noexcept;
  constexpr size_type rfind(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type rfind(const Ct* s, size_type pos = npos) const;
  constexpr size_type rfind(Ct c, size_type pos = npos) const noexcept;
  template<typename C2> constexpr size_type find_first_of(const C2& t, size_type pos = 0) const
    noexcept(_::is_nothrow_convertible_v<const C2&, basic_string_view<Ct, Tr>>)
    requires _::is_convertible_v<const C2&, basic_string_view<Ct, Tr>> && (!_::is_convertible_v<const C2&, const Ct*>);
  constexpr size_type find_first_of(const basic_string& str, size_type pos = 0) const noexcept;
  constexpr size_type find_first_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_first_of(const Ct* s, size_type pos = 0) const;
  constexpr size_type find_first_of(Ct c, size_type pos = 0) const noexcept;
  template<typename C2> constexpr size_type find_last_of(const C2& t, size_type pos = npos) const
    noexcept(_::is_nothrow_convertible_v<const C2&, basic_string_view<Ct, Tr>>)
    requires _::is_convertible_v<const C2&, basic_string_view<Ct, Tr>> && (!_::is_convertible_v<const C2&, const Ct*>);
  constexpr size_type find_last_of(const basic_string& str, size_type pos = npos) const noexcept;
  constexpr size_type find_last_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_last_of(const Ct* s, size_type pos = npos) const;
  constexpr size_type find_last_of(Ct c, size_type pos = npos) const noexcept;
  template<typename C2> constexpr size_type find_first_not_of(const C2& t, size_type pos = 0) const
    noexcept(_::is_nothrow_convertible_v<const C2&, basic_string_view<Ct, Tr>>)
    requires _::is_convertible_v<const C2&, basic_string_view<Ct, Tr>> && (!_::is_convertible_v<const C2&, const Ct*>);
  constexpr size_type find_first_not_of(const basic_string& str, size_type pos = 0) const noexcept;
  constexpr size_type find_first_not_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_first_not_of(const Ct* s, size_type pos = 0) const;
  constexpr size_type find_first_not_of(Ct c, size_type pos = 0) const noexcept;
  template<typename C2> constexpr size_type find_last_not_of(const C2& t, size_type pos = npos) const
    noexcept(_::is_nothrow_convertible_v<const C2&, basic_string_view<Ct, Tr>>)
    requires _::is_convertible_v<const C2&, basic_string_view<Ct, Tr>> && (!_::is_convertible_v<const C2&, const Ct*>);
  constexpr size_type find_last_not_of(const basic_string& str, size_type pos = npos) const noexcept;
  constexpr size_type find_last_not_of(const Ct* s, size_type pos, size_type n) const;
  constexpr size_type find_last_not_of(const Ct* s, size_type pos = npos) const;
  constexpr size_type find_last_not_of(Ct c, size_type pos = npos) const noexcept;
  constexpr basic_string substr(size_type pos = 0, size_type n = npos) const;
  template<typename C2> constexpr int compare(const C2& t) const noexcept(_::is_nothrow_convertible_v<const C2&, basic_string_view<Ct, Tr>>);
  template<typename C2> constexpr int compare(size_type pos1, size_type n1, const C2& t) const;
  template<typename C2> constexpr int compare(size_type pos1, size_type n1, const C2& t, size_type pos2, size_type n2 = npos) const;
  constexpr int compare(const basic_string& str) const noexcept;
  constexpr int compare(size_type pos1, size_type n1, const basic_string& str) const;
  constexpr int compare(size_type pos1, size_type n1, const basic_string& str, size_type pos2, size_type n2 = npos) const;
  constexpr int compare(const Ct* s) const;
  constexpr int compare(size_type pos1, size_type n1, const Ct* s) const;
  constexpr int compare(size_type pos1, size_type n1, const Ct* s, size_type n2) const;
  constexpr bool starts_with(basic_string_view<Ct, Tr> x) const noexcept;
  constexpr bool starts_with(Ct x) const noexcept;
  constexpr bool starts_with(const Ct* x) const;
  constexpr bool ends_with(basic_string_view<Ct, Tr> x) const noexcept;
  constexpr bool ends_with(Ct x) const noexcept;
  constexpr bool ends_with(const Ct* x) const;
  constexpr bool contains(basic_string_view<Ct, Tr> x) const noexcept;
  constexpr bool contains(Ct x) const noexcept;
  constexpr bool contains(const Ct* x) const;
};

template<typename In, typename Al = allocator<typename iterator_traits<In>::value_type>>
basic_string(In, In, Al = Al{}) -> basic_string<typename iterator_traits<In>::value_type, char_traits<typename iterator_traits<In>::value_type>, Al>;

template<typename Ct, typename Tr, typename Al = allocator<Ct>>
explicit basic_string(basic_string_view<Ct, Tr>, const Al& = Al{}) -> basic_string<Ct, Tr, Al>;

template<typename Ct, typename Tr, typename Al = allocator<Ct>>
basic_string(basic_string_view<Ct, Tr>, typename basic_string<Ct, Tr, Al>::size_type, typename basic_string<Ct, Tr, Al>::size_type, const Al& = Al())
  -> basic_string<Ct, Tr, Al>;

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& x, const basic_string<Ct, Tr, Al>& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& x, const basic_string<Ct, Tr, Al>& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& x, basic_string<Ct, Tr, Al>&& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& x, basic_string<Ct, Tr, Al>&& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const Ct* x, const basic_string<Ct, Tr, Al>& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const Ct* x, basic_string<Ct, Tr, Al>&& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(Ct x, const basic_string<Ct, Tr, Al>& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(Ct x, basic_string<Ct, Tr, Al>&& y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& x, const Ct* y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& x, const Ct* y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& x, Ct y);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& x, Ct y);

template<typename Ct, typename Tr, typename Al> constexpr bool
operator==(const basic_string<Ct, Tr, Al>& x, const basic_string<Ct, Tr, Al>& y) noexcept;

template<typename Ct, typename Tr, typename Al> constexpr bool
operator==(const basic_string<Ct, Tr, Al>& x, const Ct* y);

template<typename Ct, typename Tr, typename Al> constexpr _::comp_cat_t<Tr>
operator<=>(const basic_string<Ct, Tr, Al>& x, const basic_string<Ct, Tr, Al>& y) noexcept;

template<typename Ct, typename Tr, typename Al> constexpr _::comp_cat_t<Tr>
operator<=>(const basic_string<Ct, Tr, Al>& x, const Ct* y);

template<typename Ct, typename Tr, typename Al> constexpr void swap(basic_string<Ct, Tr, Al>& x, basic_string<Ct, Tr, Al>& y)
  noexcept(noexcept(x.swap(y))) requires requires { x.swap(y); } { x.swap(y); }

template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, basic_string<Ct, Tr, Al>& str);
template<typename Ct, typename Tr, typename Al> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const basic_string<Ct, Tr, Al>& str);

template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>& getline(basic_istream<Ct, Tr>& is, basic_string<Ct, Tr, Al>& str, Ct delim);
template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>& getline(basic_istream<Ct, Tr>&& is, basic_string<Ct, Tr, Al>& str, Ct delim);
template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>& getline(basic_istream<Ct, Tr>& is, basic_string<Ct, Tr, Al>& str);
template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>& getline(basic_istream<Ct, Tr>&& is, basic_string<Ct, Tr, Al>& str);

template<typename Ct, typename Tr, typename Al, typename C2>
constexpr typename basic_string<Ct, Tr, Al>::size_type erase(basic_string<Ct, Tr, Al>& c, const C2& v);

template<typename Ct, typename Tr, typename Al, typename Fn>
constexpr typename basic_string<Ct, Tr, Al>::size_type erase_if(basic_string<Ct, Tr, Al>& c, Fn f);

using string    = basic_string<char>;
using wstring   = basic_string<wchar_t>;
using u8string  = basic_string<char8_t>;
using u16string = basic_string<char16_t>;
using u32string = basic_string<char32_t>;

}
