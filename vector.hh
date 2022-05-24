// ywstd/vector.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <vector>
#else


#include "@/../compare.hh"
#include "@/../initializer_list.hh"
#include "@/allocator.hh"
#include "@/polymorphic_allocator.hh"
#include "@/reverse_iterator.hh"

namespace std {

template<typename Ty, typename Al = allocator<Ty>> class vector {
public:
  using value_type = Ty;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
    typename vector::pointer _ptr;
  public:
    using value_type = typename vector::value_type;
    using difference_type = typename vector::difference_type;
    using pointer = typename vector::pointer;
    using reference = typename vector::reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    constexpr iterator() = default;
    constexpr iterator(const iterator&) = default;
    constexpr iterator(iterator&&) = default;
    constexpr iterator(typename vector::pointer p) : _ptr{p} {}
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
    typename vector::pointer _ptr;
  public:
    using value_type = typename vector::value_type;
    using difference_type = typename vector::difference_type;
    using pointer = typename vector::const_pointer;
    using reference = typename vector::const_reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    constexpr const_iterator() = default;
    constexpr const_iterator(const const_iterator&) = default;
    constexpr const_iterator(const_iterator&&) = default;
    constexpr const_iterator(typename vector::pointer p) : _ptr{p} {}
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

  constexpr ~vector();
  constexpr vector() noexcept(noexcept(Al())) : vector(Al()) {}
  constexpr explicit vector(const Al&) noexcept;
  constexpr explicit vector(size_type n, const Al& = Al());
  constexpr vector(size_type n, const Ty& value, const Al& = Al());
  template<typename InputIt> constexpr vector(InputIt first, InputIt last, const Al& = Al());
  constexpr vector(const vector& x);
  constexpr vector(vector&&) noexcept;
  constexpr vector(const vector&, const Al&);
  constexpr vector(vector&&, const Al&);
  constexpr vector(initializer_list<Ty>, const Al& = Al());
  constexpr vector& operator=(const vector& x);

  constexpr vector& operator=(vector&& x)
    noexcept(allocator_traits<Al>::propagate_on_container_move_assignment::value || allocator_traits<Al>::is_always_equal::value);

  constexpr vector& operator=(initializer_list<Ty>);
  template<typename InputIt> constexpr void assign(InputIt first, InputIt last);
  constexpr void assign(size_type n, const Ty& u);
  constexpr void assign(initializer_list<Ty>);
  constexpr allocator_type get_allocator() const noexcept;

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

  [[nodiscard]] constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;
  constexpr size_type capacity() const noexcept;
  constexpr void resize(size_type sz);
  constexpr void resize(size_type sz, const Ty& c);
  constexpr void reserve(size_type n);
  constexpr void shrink_to_fit();

  constexpr reference operator[](size_type n);
  constexpr const_reference operator[](size_type n) const;
  constexpr const_reference at(size_type n) const;
  constexpr reference at(size_type n);
  constexpr reference front();
  constexpr const_reference front() const;
  constexpr reference back();
  constexpr const_reference back() const;

  constexpr Ty* data() noexcept;
  constexpr const Ty* data() const noexcept;

  template<typename... Args> constexpr reference emplace_back(Args&&... args);
  constexpr void push_back(const Ty& x);
  constexpr void push_back(Ty&& x);
  constexpr void pop_back();

  template<typename... Args> constexpr iterator emplace(const_iterator position, Args&&... args);
  constexpr iterator insert(const_iterator position, const Ty& x);
  constexpr iterator insert(const_iterator position, Ty&& x);
  constexpr iterator insert(const_iterator position, size_type n, const Ty& x);
  template<typename InputIt> constexpr iterator insert(const_iterator position, InputIt first, InputIt last);
  constexpr iterator insert(const_iterator position, initializer_list<Ty> il);
  constexpr iterator erase(const_iterator position);
  constexpr iterator erase(const_iterator first, const_iterator last);
  constexpr void swap(vector&) noexcept(allocator_traits<Al>::propagate_on_container_swap::value || allocator_traits<Al>::is_always_equal::value);
  constexpr void clear() noexcept;
};

namespace _ {
  template<size_t Denominator, typename Ty = ptrdiff_t> struct fraction {
    static_assert(0 < static_cast<Ty>(Denominator));
    static_assert(is_integral_v<Ty>);
    static constexpr Ty den = Denominator;
    Ty num;
    constexpr Ty integer_part() const noexcept { return num / den; }
    constexpr Ty decimal_part() const noexcept { return num % den; }
    constexpr fraction& operator++() noexcept { ++num; return *this; }
    constexpr fraction& operator--() noexcept { --num; return *this; }
    constexpr fraction& operator+=(Ty i) noexcept { num += i; return *this; }
    constexpr fraction& operator-=(Ty i) noexcept { num -= i; return *this; }
    constexpr fraction& operator*=(Ty i) noexcept { num *= i; return *this; }
    constexpr fraction& operator/=(Ty i) noexcept { num /= i; return *this; }
    constexpr fraction operator++(int) const noexcept { return {num++}; }
    constexpr fraction operator--(int) const noexcept { return {num--}; }
    constexpr fraction operator+(Ty i) const noexcept { return {num + i}; }
    constexpr fraction operator-(Ty i) const noexcept { return {num - i}; }
    constexpr fraction operator*(Ty i) const noexcept { return {num * i}; }
    constexpr fraction operator/(Ty i) const noexcept { return {num / i}; }
    friend constexpr fraction operator+(Ty i, fraction f) noexcept { return f + i; }
    friend constexpr fraction operator-(Ty i, fraction f) noexcept { return f - i; }
    friend constexpr fraction operator*(Ty i, fraction f) noexcept { return f * i; }
    friend constexpr bool operator==(const fraction& x, const fraction& y) noexcept { return x.num == y.num; }
    friend constexpr strong_ordering operator<=>(const fraction& x, const fraction& y) noexcept { return x.num <=> y.num; }
  };
}

template<typename Al> class vector<bool, Al> {
public:
  using value_type = bool;
  using allocator_type = Al;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class reference {
    friend class vector;
    typename vector::size_type* _ptr;
    _::fraction<_::bit_size<size_type>, difference_type> _frac;
    constexpr reference() noexcept : _ptr{nullptr}, _frac{1} {}
    constexpr reference(size_t n) noexcept : _frac{static_cast<ptrdiff_t>(n)} {}
  public:
    constexpr ~reference() noexcept;
    constexpr reference(const reference&) = default;
    constexpr operator bool() const noexcept { return static_cast<bool>(*(_ptr + _frac.integer_part()) & (1 << _frac.decimal_part())); }
    constexpr reference& operator=(const bool x) noexcept {
      if (x) *(_ptr + _frac.integer_part()) |= (1 << _frac.decimal_part());
      else *(_ptr + _frac.integer_part()) &= ~(1 << _frac.decimal_part());
      return *this;
    }
    constexpr reference& operator=(const reference& x) noexcept { return *this = static_cast<bool>(x); }
    constexpr void flip() noexcept { *(_ptr + _frac.integer_part()) ^= (1 << _frac.decimal_part()); }
  };

  using pointer = reference*;
  using const_pointer = const reference*;
  using const_reference = bool;

  class iterator {
    typename vector::reference _ref;
  public:
    using value_type = typename vector::value_type;
    using difference_type = typename vector::difference_type;
    using pointer = typename vector::pointer;
    using reference = typename vector::reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = random_access_iterator_tag;
    constexpr iterator() = default;
    constexpr iterator(const iterator&) = default;
    constexpr iterator(iterator&&) = default;
    constexpr iterator(typename vector::reference r) : _ref{r._frac} {}
    constexpr iterator& operator=(const iterator&) = default;
    constexpr reference operator*() const { return _ref; }
    constexpr pointer operator->() const { return &_ref; }
    constexpr reference operator[](difference_type n) const { return reference{_ref._frac + n}; }
    constexpr iterator& operator++() { ++_ref._frac; return *this; }
    constexpr iterator& operator--() { --_ref._frac; return *this; }
    constexpr iterator operator++(int) { return {reference{_ref._frac++}}; }
    constexpr iterator operator--(int) { return {reference{_ref._frac--}}; }
    constexpr iterator& operator+=(difference_type n) { return _ref._frac += n, *this; }
    constexpr iterator& operator-=(difference_type n) { return _ref._frac -= n, *this; }
    constexpr iterator operator+(difference_type n) const { return {reference{_ref._frac + n}}; }
    constexpr iterator operator-(difference_type n) const { return {reference{_ref._frac - n}}; }
    constexpr difference_type operator-(const iterator& i) const { return _ref._frac.num - i._ref._frac.num; }
    friend constexpr iterator operator+(difference_type n, const iterator& i) { return i + n; }
    constexpr bool operator==(const iterator& i) const { return _ref._frac == i._ref._frac; }
  };

  class const_iterator {
    typename vector::reference _ref;
  public:
    using value_type = typename vector::value_type;
    using difference_type = typename vector::difference_type;
    using pointer = typename vector::const_pointer;
    using reference = typename vector::const_reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = random_access_iterator_tag;
    constexpr const_iterator() = default;
    constexpr const_iterator(const const_iterator&) = default;
    constexpr const_iterator(const_iterator&&) = default;
    constexpr const_iterator(typename vector::reference r) : _ref{r._frac} {}
    constexpr const_iterator& operator=(const const_iterator&) = default;
    constexpr reference operator*() const { return _ref; }
    constexpr pointer operator->() const { return &_ref; }
    constexpr reference operator[](difference_type n) const { return reference{_ref._frac + n}; }
    constexpr const_iterator& operator++() { ++_ref._frac; return *this; }
    constexpr const_iterator& operator--() { --_ref._frac; return *this; }
    constexpr const_iterator operator++(int) { return {reference{_ref._frac++}}; }
    constexpr const_iterator operator--(int) { return {reference{_ref._frac--}}; }
    constexpr const_iterator& operator+=(difference_type n) { return _ref._frac += n, *this; }
    constexpr const_iterator& operator-=(difference_type n) { return _ref._frac -= n, *this; }
    constexpr const_iterator operator+(difference_type n) const { return {reference{_ref._frac + n}}; }
    constexpr const_iterator operator-(difference_type n) const { return {reference{_ref._frac - n}}; }
    constexpr difference_type operator-(const const_iterator& i) const { return _ref._frac.num - i._ref._frac.num; }
    friend constexpr const_iterator operator+(difference_type n, const const_iterator& i) { return i + n; }
    constexpr bool operator==(const const_iterator& i) const { return _ref._frac == i._ref._frac; }
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  constexpr ~vector();
  constexpr vector() : vector(Al()) {}
  constexpr explicit vector(const Al&);
  constexpr explicit vector(size_type n, const Al& = Al());
  constexpr vector(size_type n, const bool& value, const Al& = Al());
  template<typename InputIt> constexpr vector(InputIt first, InputIt last, const Al& = Al());
  constexpr vector(const vector& x);
  constexpr vector(vector&& x);
  constexpr vector(const vector&, const Al&);
  constexpr vector(vector&&, const Al&);
  constexpr vector(initializer_list<bool>, const Al& = Al{});
  constexpr vector& operator=(const vector& x);
  constexpr vector& operator=(vector&& x);
  constexpr vector& operator=(initializer_list<bool>);
  template<typename InputIt> constexpr void assign(InputIt first, InputIt last);
  constexpr void assign(size_type n, const bool& t);
  constexpr void assign(initializer_list<bool>);
  constexpr allocator_type get_allocator() const noexcept;

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

  [[nodiscard]] constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;
  constexpr size_type capacity() const noexcept;
  constexpr void resize(size_type sz, bool c = false);
  constexpr void reserve(size_type n);
  constexpr void shrink_to_fit();

  constexpr reference operator[](size_type n);
  constexpr const_reference operator[](size_type n) const;
  constexpr const_reference at(size_type n) const;
  constexpr reference at(size_type n);
  constexpr reference front();
  constexpr const_reference front() const;
  constexpr reference back();
  constexpr const_reference back() const;

  template<typename... Args> constexpr reference emplace_back(Args&&... args);
  constexpr void push_back(const bool& x);
  constexpr void pop_back();
  template<typename... Args> constexpr iterator emplace(const_iterator position, Args&&... args);
  constexpr iterator insert(const_iterator position, const bool& x);
  constexpr iterator insert(const_iterator position, size_type n, const bool& x);
  template<typename InputIt> constexpr iterator insert(const_iterator position, InputIt first, InputIt last);
  constexpr iterator insert(const_iterator position, initializer_list<bool> il);

  constexpr iterator erase(const_iterator position);
  constexpr iterator erase(const_iterator first, const_iterator last);
  constexpr void swap(vector&);
  constexpr static void swap(reference x, reference y) noexcept;
  constexpr void flip() noexcept; // flips all bits
  constexpr void clear() noexcept;
private:
  size_type* _buffer;
  size_type _buffer_size;
};

template<typename Ty, typename Al> constexpr bool operator==(const vector<Ty, Al>& x, const vector<Ty, Al>& y);
template<typename Ty, typename Al> constexpr _::synth_three_way_result_t<Ty> operator<=>(const vector<Ty, Al>& x, const vector<Ty, Al>& y);

template<typename Ty, typename Al> constexpr void swap(vector<Ty, Al>& x, vector<Ty, Al>& y) noexcept(noexcept(x.swap(y)));
template<typename Ty, typename Al, typename U> constexpr typename vector<Ty, Al>::size_type erase(vector<Ty, Al>& c, const U& value);
template<typename Ty, typename Al, typename Pred> constexpr typename vector<Ty, Al>::size_type erase_if(vector<Ty, Al>& c, Pred pred);

template<typename Ty> struct hash;
template<typename Al> struct hash<vector<bool, Al>> { size_t operator()(const vector<bool, Al>&); };

namespace pmr {
  template<typename Ty> using vector = std::vector<Ty, polymorphic_allocator<Ty>>;
}

}

#endif
