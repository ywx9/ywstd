// ywstd/array.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <cerrno>
#else

#include "@/../compare.hh"
#include "@/../initializer_list.hh"
#include "@/../type_traits.hh"
#include "@/reverse_iterator.hh"
#include "@/tuple_element.hh"


namespace std {

template<typename Ty, size_t Nx> struct array {
  using value_type = Ty;
  using pointer = Ty*;
  using const_pointer = const Ty*;
  using reference = Ty&;
  using const_reference = const Ty&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
    typename array::pointer _ptr;
  public:
    using value_type = typename array::value_type;
    using difference_type = typename array::difference_type;
    using pointer = typename array::pointer;
    using reference = typename array::reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    constexpr iterator() = default;
    constexpr iterator(const iterator&) = default;
    constexpr iterator(iterator&&) = default;
    constexpr iterator(typename array::pointer p) : _ptr{p} {}
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
    constexpr difference_type operator-(iterator i) { return _ptr - i._ptr; }
    friend constexpr iterator operator+(difference_type n, iterator i) { return i + n; }
    constexpr bool operator==(const iterator& i) const { return _ptr == i._ptr; }
    constexpr strong_ordering operator<=>(const iterator& i) const { return _ptr <=> i._ptr; };
  };

  class const_iterator {
    typename array::pointer _ptr;
  public:
    using value_type = typename array::value_type;
    using difference_type = typename array::difference_type;
    using pointer = typename array::const_pointer;
    using reference = typename array::const_reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    constexpr const_iterator() = default;
    constexpr const_iterator(const const_iterator&) = default;
    constexpr const_iterator(const_iterator&&) = default;
    constexpr const_iterator(typename array::pointer p) : _ptr{p} {}
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
    constexpr difference_type operator-(const_iterator i) { return _ptr - i._ptr; }
    friend constexpr const_iterator operator+(difference_type n, const_iterator i) { return i + n; }
    constexpr bool operator==(const const_iterator& i) const { return _ptr == i._ptr; }
    constexpr strong_ordering operator<=>(const const_iterator& i) const { return _ptr <=> i._ptr; };
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  value_type _elem[Nx];

  constexpr void fill(const Ty& u) { for (size_t i = 0; i < Nx; ++i) _elem[i] = u; }
  constexpr void swap(array& a) noexcept(_::is_nothrow_swappable_v<Ty>) { for (size_t i = 0; i < Nx; ++i) ranges::swap(_elem[i], a._elem[i]); }
  constexpr iterator begin() noexcept { return {_elem}; }
  constexpr const_iterator begin() const noexcept { return {_elem}; }
  constexpr const_iterator cbegin() const noexcept { return begin(); }
  constexpr iterator end() noexcept { return {_elem + Nx}; }
  constexpr const_iterator end() const noexcept { return {_elem + Nx}; }
  constexpr const_iterator cend() const noexcept { return end(); }
  constexpr reverse_iterator rbegin() noexcept { return {end()}; }
  constexpr const_reverse_iterator rbegin() const noexcept { return {end()}; }
  constexpr const_reverse_iterator crbegin() const noexcept { return {end()}; }
  constexpr reverse_iterator rend() noexcept { return {begin()}; }
  constexpr const_reverse_iterator rend() const noexcept { return {begin()}; }
  constexpr const_reverse_iterator crend() const noexcept { return {begin()}; }
  [[nodiscard]] constexpr bool empty() const noexcept { return false; }
  constexpr size_type size() const noexcept { return Nx; }
  constexpr size_type max_size() const noexcept { return Nx; }
  constexpr reference operator[](size_type n) { return _elem[n]; }
  constexpr const_reference operator[](size_type n) const { return _elem[n]; }

  constexpr reference at(size_type n) {
    // if (n >= size()) throw out_of_range{"n is not within the range of the container."};
    return _elem[n];
  }
  constexpr const_reference at(size_type n) const {
    // if (n >= size()) throw out_of_range{"n is not within the range of the container."};
    return _elem[n];
  }
  constexpr reference front() { return *_elem; }
  constexpr const_reference front() const { return _elem; }
  constexpr reference back() { return _elem[Nx - 1]; }
  constexpr const_reference back() const { return _elem[Nx - 1]; }
  constexpr Ty* data() noexcept { return _elem; }
  constexpr const Ty* data() const noexcept { return _elem; }
};

template<typename Ty, typename... Ts> array(Ty, Ts...) -> array<Ty, 1 + sizeof...(Ts)>;

template<typename Ty, size_t Nx> struct tuple_size<array<Ty, Nx>> : integral_constant<size_t, Nx> {};
template<size_t Ix, typename Ty, size_t Nx> struct tuple_element<Ix, array<Ty, Nx>> : type_identity<Ty> {};

template<typename Ty, size_t Nx> constexpr bool operator==(const array<Ty, Nx>& x, const array<Ty, Nx>& y) {
  for (size_t i = 0; i < Nx; ++i) if (x[i] != y[i]) return false;
  return true;
}
template<typename Ty, size_t Nx> constexpr _::synth_three_way_result_t<Ty> operator<=>(const array<Ty, Nx>& x, const array<Ty, Nx>& y) {
  for (size_t i = 0; i < Nx; ++i) if (auto c = _::synth_three_way(x[i], y[i]); c != 0) return c;
  return strong_ordering::equal;
}

template<typename Ty, size_t Nx> constexpr void swap(array<Ty, Nx>& x, array<Ty, Nx>& y)
  noexcept(noexcept(x.swap(y))) requires requires { x.swap(y); } { return x.swap(y); }

template<size_t Ix, typename Ty, size_t Nx> constexpr Ty& get(array<Ty, Nx>& a) noexcept { return a[Ix]; }
template<size_t Ix, typename Ty, size_t Nx> constexpr Ty&& get(array<Ty, Nx>&& a) noexcept { return _::move(a[Ix]); }
template<size_t Ix, typename Ty, size_t Nx> constexpr const Ty& get(const array<Ty, Nx>& a) noexcept { return a[Ix]; }
template<size_t Ix, typename Ty, size_t Nx> constexpr const Ty&& get(const array<Ty, Nx>&& a) noexcept { return _::move(a[Ix]); }

template<typename Ty, size_t Nx> constexpr array<typename remove_cv<Ty>::type, Nx> to_array(Ty (&a)[Nx]) {
  array<typename remove_cv<Ty>::type, Nx> t;
  for (size_t i = 0; i < Nx; ++i) t[i] = a[i];
  return t;
}
template<typename Ty, size_t Nx> constexpr array<typename remove_cv<Ty>::type, Nx> to_array(Ty (&&a)[Nx]) {
  array<typename remove_cv<Ty>::type, Nx> t;
  for (size_t i = 0; i < Nx; ++i) t[i] = _::move(a[i]);
  return t;
}

}

#endif
