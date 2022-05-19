// ywstd/utility.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "@/declval.hh"
#include "@/in_place.hh"
#include "@/pair.hh"
#include "@/../compare.hh"
#include "@/../initializer_list.hh"
#include "@/../limits.hh"
#include "@/../type_traits.hh"

namespace std {

template<typename Ty> constexpr void swap(Ty& x, Ty& y)
  noexcept(_::is_nothrow_move_constructible_v<Ty> && _::is_nothrow_move_assignable_v<Ty>)
  requires _::is_move_constructible_v<Ty> && _::is_move_assignable_v<Ty> {
  Ty t = static_cast<Ty&&>(x); x = static_cast<Ty&&>(y); y = static_cast<Ty&&>(t);
}

template<typename Ty, size_t Nx> constexpr void swap(Ty (&x)[Nx], Ty (&y)[Nx])
  noexcept(_::is_nothrow_swappable_v<Ty>) requires _::is_swappable_v<Ty> {
  for (size_t i = 0; i < Nx; ++i) swap(x[i], y[i]);
}

template<typename Ty, typename Uy = Ty> constexpr Ty exchange(Ty& x, Uy&& v)
  noexcept(_::is_nothrow_move_constructible_v<Ty> && _::is_nothrow_assignable_v<Ty&, Uy>) {
  Ty t = static_cast<Ty&&>(x); x = static_cast<Uy&&>(v); return t;
}

template<typename Ty> constexpr _::remove_reference_t<Ty>&& move(Ty&& x) noexcept { return static_cast<_::remove_reference_t<Ty>&&>(x); }

template<typename Ty> constexpr _::conditional_t<!_::is_nothrow_move_constructible_v<Ty> && _::is_copy_constructible_v<Ty>, const Ty&, Ty&&>
move_if_noexcept(Ty& x) noexcept { return static_cast<Ty&&>(x); }

template<typename Ty> constexpr Ty&& forward(_::remove_reference_t<Ty>& x) noexcept { return static_cast<Ty&&>(x); }
template<typename Ty> constexpr Ty&& forward(_::remove_reference_t<Ty>&& x) noexcept requires(!_::is_lvalue_reference_v<Ty>) { return static_cast<Ty&&>(x); }

template<typename Ty> constexpr _::add_const_t<Ty>& as_const(Ty& x) noexcept { return x; }
template<typename Ty> void as_const(const Ty&&) = delete;

using std::declval;

template<typename Ty> constexpr typename underlying_type<Ty>::type to_underlying(Ty x) noexcept { return static_cast<_::underlying_type_t<Ty>>(x); }

template<typename T1, typename T2> constexpr bool cmp_equal(const T1 x, const T2 y) noexcept {
  static_assert(_::is_integral_v<T1> && _::is_integral_v<T2>);
  if constexpr (_::is_signed_v<T1> == _::is_signed_v<T2>) return x == y;
  if constexpr (_::is_signed_v<T2>) return x == static_cast<_::make_unsigned_t<T2>>(y) && y >= 0;
  return static_cast<_::make_unsigned_t<T1>>(x) == y && x >= 0;
}

template<typename T1, typename T2> constexpr bool cmp_less(const T1 x, const T2 y) noexcept {
  static_assert(_::is_integral_v<T1> && _::is_integral_v<T2>);
  if constexpr (_::is_signed_v<T1> == _::is_signed_v<T2>) return x < y;
  if constexpr (_::is_signed_v<T2>) return y > 0 && x < static_cast<_::make_unsigned_t<T2>>(y);
  return x < 0 || static_cast<_::make_unsigned_t<T1>>(x) < y;
}

template<typename T1, typename T2> constexpr bool cmp_not_equal(const T1 x, const T2 y) noexcept {
  static_assert(_::is_integral_v<T1> && _::is_integral_v<T2>);
  return !std::cmp_equal(x, y);
}

template<typename T1, typename T2> constexpr bool cmp_greater(const T1 x, const T2 y) noexcept {
  static_assert(_::is_integral_v<T1> && _::is_integral_v<T2>);
  return std::cmp_less(y, x);
}

template<typename T1, typename T2> constexpr bool cmp_less_equal(const T1 x, const T2 y) noexcept {
  static_assert(_::is_integral_v<T1> && _::is_integral_v<T2>);
  return !std::cmp_less(y, x);
}

template<typename T1, typename T2> constexpr bool cmp_greater_equal(const T1 x, const T2 y) noexcept {
  static_assert(_::is_integral_v<T1> && _::is_integral_v<T2>);
  return !std::cmp_less(x, y);
}

template<typename Ty> constexpr bool in_range(auto x) noexcept {
  return std::cmp_greater_equal(x, numeric_limits<Ty>::min()) && std::cmp_less_equal(x, numeric_limits<Ty>::max());
}

template<typename Ty, Ty... Vs> struct integer_sequence {
  using value_type = Ty;
  static constexpr size_t size() noexcept { return sizeof...(Vs); }
};

template<size_t... Ns> using index_sequence = integer_sequence<size_t, Ns...>;
template<typename Ty, Ty Nx> using make_integer_sequence = __make_integer_seq<integer_sequence, Ty, Nx>;
template<size_t Nx> using make_index_sequence = make_integer_sequence<size_t, Nx>;
template<typename... Ts> using index_sequence_for = make_index_sequence<sizeof...(Ts)>;

}
