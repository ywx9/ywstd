// ywstd/@/pair.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/../compare.hh"
#include "../@/../concepts.hh"
#include "../@/../type_traits.hh"
#include "../@/integral_constant.hh"
#include "../@/reference_wrapper.hh"
#include "../@/tuple_element.hh"

namespace std {

template<typename... Ts> class tuple;

struct piecewise_construct_t { explicit piecewise_construct_t() = default; };
inline constexpr piecewise_construct_t piecewise_construct{};

template<typename T1, class T2> struct pair {
private:
  static constexpr bool expl_1 = !_::is_implicitly_default_constructible_v<T1> || !_::is_implicitly_default_constructible_v<T2>;
  static constexpr bool expl_2 = !_::is_convertible_v<const T1&, T1> || !_::is_convertible_v<const T2&, T2>;
  template<typename U1, typename U2> static constexpr bool expl_3 = !_::is_convertible_v<U1, T1> || !_::is_convertible_v<U2, T2>;
public:
  using first_type = T1;
  using second_type = T2;
  T1 first;
  T2 second;

  explicit(expl_1) constexpr pair() requires _::is_default_constructible_v<T1> && _::is_default_constructible_v<T2> : first{}, second{} {}
  explicit(expl_2) constexpr pair(const T1& x, const T2& y) requires _::is_copy_constructible_v<T1> && _::is_copy_constructible_v<T2> : first{x}, second{y} {}

  template<typename U1 = T1, typename U2 = T2> explicit(expl_3<U1, U2>) constexpr pair(U1&& x, U2&& y)
    requires _::is_constructible_v<T1, U1> && _::is_constructible_v<T2, U2> : first{static_cast<U1&&>(x)}, second{static_cast<U2&&>(y)} {}

  template<typename U1, typename U2> explicit(expl_3<const U1&, const U2&>) constexpr pair(pair<U1, U2>& a)
    requires _::is_constructible_v<T1, U1&> && _::is_constructible_v<T2, U2&> : first{a.first}, second{a.second} {}

  template<typename U1, typename U2> explicit(expl_3<const U1&, const U2&>) constexpr pair(const pair<U1, U2>& a)
    requires _::is_constructible_v<T1, const U1&> && _::is_constructible_v<T2, const U2&> : first{a.first}, second{a.second} {}

  template<typename U1, typename U2> explicit(expl_3<U1, U2>) constexpr pair(pair<U1, U2>&& a)
    requires _::is_constructible_v<T1, U1> && _::is_constructible_v<T2, U2> : first{_::move(a.first)}, second{_::move(a.second)} {}

  template<typename U1, typename U2> explicit(expl_3<const U1, const U2>) constexpr pair(const pair<U1, U2>&& a)
    requires _::is_constructible_v<T1, const U1> && _::is_constructible_v<T2, const U2> : first{_::move(a.first)}, second{_::move(a.second)} {}

  template<typename... A1, typename... A2> pair(piecewise_construct_t, tuple<A1...> t1, tuple<A2...> t2);
  constexpr pair(const pair&) = default;
  constexpr pair(pair&&) = default;

  constexpr pair& operator=(const pair& a)
    requires _::is_copy_assignable_v<T1> && _::is_copy_assignable_v<T2> { return first = a.first, second = a.second, *this; }
  constexpr const pair& operator=(const pair& a) const
    requires _::is_copy_assignable_v<const T1> && _::is_copy_assignable_v<const T2> { return first = a.first, second = a.second, *this; }

  template<typename U1, typename U2> constexpr pair& operator=(const pair<U1, U2>& a)
    requires _::is_assignable_v<T1&, const U1&> && _::is_assignable_v<T2&, const T2&> { return first = a.first, second = a.second, *this; }

  template<typename U1, typename U2> constexpr const pair& operator=(const pair<U1, U2>& a) const
    requires _::is_assignable_v<const T1&, const U1&> && _::is_assignable_v<const T2&, const T2&> { return first = a.first, second = a.second, *this; }

  constexpr pair& operator=(pair&& a) noexcept(_::is_nothrow_move_assignable_v<T1> && _::is_nothrow_move_assignable_v<T2>)
    requires _::is_move_assignable_v<T1> && _::is_move_assignable_v<T2> { return first = _::move(a.first), second = _::move(a.second), *this; }

  constexpr const pair& operator=(pair&& a) const
    requires _::is_assignable_v<const T1&, T1> && _::is_assignable_v<const T2&, T2> { return first = _::move(a.first), second = _::move(a.second), *this; }

  template<typename U1, typename U2> constexpr pair& operator=(pair<U1, U2>&& a)
    requires _::is_assignable_v<T1&, U1> && _::is_assignable_v<T2&, U2> { return first = _::move(a.first), second = _::move(a.second), *this; }

  template<typename U1, typename U2> constexpr const pair& operator=(pair<U1, U2>&& a) const
    requires _::is_assignable_v<const T1&, U1> && _::is_assignable_v<const T2&, U2> { return first = _::move(a.first), second = _::move(a.second), *this; }

  constexpr void swap(pair& a) noexcept(_::is_nothrow_swappable_v<T1> && _::is_nothrow_swappable_v<T2>)
    requires _::is_swappable_v<T1> && _::is_swappable_v<T2> { ranges::swap(first, a.first), ranges::swap(second, a.second); }

  constexpr void swap(const pair& a) const noexcept(_::is_nothrow_swappable_v<const T1> && _::is_nothrow_swappable_v<const T2>)
    requires _::is_swappable_v<const T1> && _::is_swappable_v<const T2> { ranges::swap(first, a.first), ranges::swap(second, a.second); }
};

template<typename T1, typename T2> pair(T1, T2) -> pair<T1, T2>;

template<typename T1, typename T2> struct tuple_element<0, pair<T1, T2>> { using type = T1; };
template<typename T1, typename T2> struct tuple_element<1, pair<T1, T2>> { using type = T2; };
template<typename T1, typename T2> struct tuple_size<pair<T1, T2>> : integral_constant<size_t, 2> {};

template<typename T1, typename T2> constexpr pair<unwrap_ref_decay_t<T1>, unwrap_ref_decay_t<T2>>
make_pair(T1&& x, T2&& y) { return {static_cast<T1&&>(x), static_cast<T2&&>(y)}; }

template<typename T1, typename T2> constexpr bool
operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) { return x.first == y.first && x.second == y.second; }

template<typename T1, typename T2>
constexpr common_comparison_category_t<_::synth_three_way_result_t<T1>, _::synth_three_way_result_t<T2>>
operator<=>(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  if (const auto c = _::synth_three_way(x.first, y.first); c != 0) return c;
  else return _::synth_three_way(x.first, y.first);
}

template<typename T1, typename T2> constexpr void swap(pair<T1, T2>& x, pair<T1, T2>& y)
  noexcept(noexcept(x.swap(y))) requires _::is_swappable_v<T1> && _::is_swappable_v<T2> { x.swap(y); }

template<typename T1, typename T2> constexpr void swap(const pair<T1, T2>& x, const pair<T1, T2>& y)
  noexcept(noexcept(x.swap(y))) requires _::is_swappable_v<const T1> && _::is_swappable_v<const T2> { x.swap(y); }

template<size_t Ix, typename T1, typename T2> requires(Ix < 2) constexpr tuple_element_t<Ix, pair<T1, T2>>& get(pair<T1, T2>& x) noexcept  {
  if constexpr (Ix == 0) return x.first;
  if constexpr (Ix == 1) return x.second;
}

template<size_t Ix, typename T1, typename T2> requires(Ix < 2) constexpr const tuple_element_t<Ix, pair<T1, T2>>& get(const pair<T1, T2>& x) noexcept {
  if constexpr (Ix == 0) return x.first;
  if constexpr (Ix == 1) return x.second;
}

template<size_t Ix, typename T1, typename T2> requires(Ix < 2) constexpr tuple_element_t<Ix, pair<T1, T2>>&& get(pair<T1, T2>&& x) noexcept  {
  if constexpr (Ix == 0) return _::move(x.first);
  if constexpr (Ix == 1) return _::move(x.second);
}

template<size_t Ix, typename T1, typename T2> requires(Ix < 2) constexpr const tuple_element_t<Ix, pair<T1, T2>>&& get(const pair<T1, T2>&& x) noexcept {
  if constexpr (Ix == 0) return static_cast<const T1&&>(x.first);
  if constexpr (Ix == 1) return static_cast<const T2&&>(x.second);
}

template<typename T1, typename T2> constexpr T1& get(pair<T1, T2>& x) noexcept { return x.first; }
template<typename T1, typename T2> constexpr const T1& get(const pair<T1, T2>& x) noexcept { return x.first; }
template<typename T1, typename T2> constexpr T1&& get(pair<T1, T2>&& x) noexcept { return _::move(x.first); }
template<typename T1, typename T2> constexpr const T1&& get(const pair<T1, T2>& x) noexcept { return _::move(x.first); }
template<typename T1, typename T2> constexpr T1& get(pair<T2, T1>& x) noexcept { return x.second; }
template<typename T1, typename T2> constexpr const T1& get(const pair<T2, T1>& x) noexcept { return x.second; }
template<typename T1, typename T2> constexpr T1&& get(pair<T2, T1>&& x) noexcept { return _::move(x.second); }
template<typename T1, typename T2> constexpr const T1&& get(const pair<T2, T1>& x) noexcept { return _::move(x.second); }

}
