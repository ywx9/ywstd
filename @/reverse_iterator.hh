// ywstd/@/reverse_iterator.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/../compare.hh"
#include "../@/../type_traits.hh"
#include "../@/iterator-concepts.hh"

namespace std {

namespace _::_reverse_iterator {
  template<typename It> struct iterator_concept : conditional<random_access_iterator<It>, random_access_iterator_tag, bidirectional_iterator_tag> {};
  template<typename It> struct iterator_category : conditional<
    derived_from<iter_category_t<It>, random_access_iterator_tag>, random_access_iterator_tag, iter_category_t<It>> {};
}

template<typename It> class reverse_iterator {
  template<class> friend class reverse_iterator;
protected:
  It current{};
public:
  using iterator_type = It;
  using iterator_category = typename _::_reverse_iterator::iterator_category<It>::type;
  using iterator_concept = typename _::_reverse_iterator::iterator_concept<It>::type;
  using value_type = iter_value_t<It>;
  using difference_type = iter_difference_t<It>;
  using pointer = typename iterator_traits<It>::pointer;
  using reference = iter_reference_t<It>;

  static_assert(bidirectional_iterator<It>);

  constexpr ~reverse_iterator() = default;
  constexpr reverse_iterator() = default;
  constexpr explicit reverse_iterator(It x) : current(static_cast<It&&>(x)) {}

  template<_::different_from<It> I2> requires convertible_to<const I2&, It>
  constexpr reverse_iterator(const reverse_iterator<I2>& x) : current(x.current) {}

  constexpr reverse_iterator& operator=(const reverse_iterator&) = default;

  template<_::different_from<It> I2> requires convertible_to<const I2&, It>&& assignable_from<It&, const I2&>
  constexpr reverse_iterator& operator=(const reverse_iterator<I2>& x) { return current = x.current, *this; }

  constexpr It base() const { return current; }
  constexpr reference operator*() const { It a = current; return *--a; }

  constexpr pointer operator->() const requires(_::is_pointer_v<It> || requires(const It i) { i.operator->(); }) {
    It a = current;
    if constexpr (_::is_pointer_v<It>) return --a;
    else return (--a).operator->();
  }
  constexpr reference operator[](const difference_type n) const { return current[static_cast<difference_type>(-n - 1)]; }
  constexpr reverse_iterator& operator++() { return --current, *this; }
  constexpr reverse_iterator& operator--() { return ++current, *this; }
  constexpr reverse_iterator& operator+=(const difference_type n) { return current -= n, *this; }
  constexpr reverse_iterator& operator-=(const difference_type n) { return current += n, *this; }
  constexpr reverse_iterator operator+(const difference_type n) const { return {current - n}; }
  constexpr reverse_iterator operator-(const difference_type n) const { return {current + n}; }
  constexpr reverse_iterator operator++(int) { return {--current}; }
  constexpr reverse_iterator operator--(int) { return {++current}; }

  friend constexpr iter_rvalue_reference_t<It> iter_move(const reverse_iterator& i)
    noexcept(_::is_nothrow_copy_constructible_v<It> && noexcept(ranges::iter_move(--declval<It&>()))) {
    auto a = i.base(); return ranges::iter_move(--i);
  }
  template<indirectly_swappable<It> I2> friend constexpr void iter_swap(const reverse_iterator& x, const reverse_iterator<I2>& y)
    noexcept(_::is_nothrow_copy_constructible_v<It> && _::is_nothrow_copy_constructible_v<I2> &&
             noexcept(ranges::iter_swap(--declval<It&>(), --declval<I2&>()))) {
    auto a = x.base(); auto b = y.base(); ranges::iter_swap(--a, --b);
  }
};

template<typename I1, typename I2> requires(!sized_sentinel_for<I1, I2>)
inline constexpr bool disable_sized_sentinel_for<reverse_iterator<I1>, reverse_iterator<I2>> = true;

template<typename I1, typename I2> requires requires { { declval<I1>() == declval<I2>() } -> _::boolean_testable; } constexpr bool
operator==(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y) { return x.base() == y.base(); }

template<typename I1, typename I2> requires requires { { declval<I1>() > declval<I2>() } -> _::boolean_testable; } constexpr bool
operator<(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y) { return x.base() > y.base(); }

template<typename I1, typename I2> requires requires { { declval<I1>() < declval<I2>() } -> _::boolean_testable; } constexpr bool
operator>(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y) { return x.base() < y.base(); }

template<typename I1, typename I2> requires requires { { declval<I1>() >= declval<I2>() } -> _::boolean_testable; } constexpr bool
operator<=(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y) { return x.base() >= y.base(); }

template<typename I1, typename I2> requires requires { { declval<I1>() <= declval<I2>() } -> _::boolean_testable; } constexpr bool
operator>=(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y) { return x.base() <= y.base(); }

template<typename I1, three_way_comparable_with<I1> I2> constexpr compare_three_way_result_t<I1, I2>
operator<=>(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y) { return y.base() <=> x.base(); }

template<typename I1, typename I2> constexpr auto operator-(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y)
  -> decltype(y.base() - x.base()) { return y.base() - x.base(); }

template<typename It> constexpr reverse_iterator<It>
operator+(typename reverse_iterator<It>::difference_type n, const reverse_iterator<It>& y) { return y + n; }

template<typename It> constexpr reverse_iterator<It> make_reverse_iterator(It i) { return reverse_iterator<It>{static_cast<It&&>(i)}; }

}
