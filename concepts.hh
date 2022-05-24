// ywstd/concepts.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <concepts>
#else

#include "@/../type_traits.hh"

namespace std {

template<typename T1, typename T2> concept same_as = _::same_as<T1, T2>;
template<typename T1, typename T2> concept derived_from = _::derived_from<T1, T2>;
template<typename T1, typename T2> concept convertible_to = _::convertible_to<T1, T2>;
template<typename T1, typename T2> concept common_reference_with = _::common_reference_with<T1, T2>;
template<typename T1, typename T2> concept common_with = _::common_with<T1, T2>;

template<typename Ty> concept integral = _::integral<Ty>;
template<typename Ty> concept signed_integral = _::signed_integral<Ty>;
template<typename Ty> concept unsigned_integral = _::unsigned_integral<Ty>;
template<typename Ty> concept floating_point = _::floating_point<Ty>;

template<typename Ty> concept destructible = _::destructible<Ty>;
template<typename Ty, typename... As> concept constructible_from = _::constructible_from<Ty, As...>;
template<typename Ty> concept default_initializable = _::default_initializable<Ty>;
template<typename Ty> concept move_constructible = _::move_constructible<Ty>;
template<typename Ty> concept copy_constructible = _::copy_constructible<Ty>;
template<typename Ty, typename At> concept assignable_from = _::assignable_from<Ty, At>;

namespace _::_swap {
  template<typename Ty> void swap(Ty&, Ty&) = delete;
  template<typename Ty, size_t Nx> void swap(Ty (&)[Nx], Ty (&)[Nx]) = delete;
  template<typename T1, typename T2> concept c1 = requires { swap(declval<T1>(), declval<T2>()); };
  struct _ {
    template<typename T1, typename T2> constexpr void operator()(T1&& x, T2&& y) const
      noexcept(noexcept(swap(declval<T1>(), declval<T2>()))) requires c1<T1, T2> {
      swap(static_cast<T1&&>(x), static_cast<T2&&>(y));
    }
    template<typename Ty, size_t Nx> constexpr void operator()(Ty (&x)[Nx], Ty (&y)[Nx]) const
      noexcept(noexcept((*this)(*x, *y))) requires (!c1<Ty (&)[Nx], Ty (&)[Nx]>) && requires { (*this)(*x, *y); } {
      for (size_t i = 0; i < Nx; ++i) (*this)(x[i], y[i]);
    }
    template<typename Ty> constexpr void operator()(Ty& x, Ty& y) const
      noexcept(is_nothrow_move_constructible_v<Ty> && is_nothrow_move_assignable_v<Ty>)
      requires (!c1<Ty&, Ty&>) && move_constructible<Ty> && assignable_from<Ty&, Ty> {
      Ty t = static_cast<Ty&&>(x); x = static_cast<Ty&&>(y); y = static_cast<Ty&&>(t);
    }
  };
}

namespace ranges::inline _cpo {
  inline constexpr _::_swap::_ swap;
}

template<typename Ty> concept swappable = requires(Ty& x, Ty& y) { ranges::swap(x, y); };

template<typename T1, typename T2> concept swappable_with =
  common_reference_with<const _::remove_reference_t<T1>&, const _::remove_reference_t<T2>&> &&
  requires { ranges::swap(declval<T1>(), declval<T1>()); ranges::swap(declval<T1>(), declval<T2>());
             ranges::swap(declval<T2>(), declval<T1>()); ranges::swap(declval<T2>(), declval<T1>()); };

template<typename Ty> concept equality_comparable = _::equality_comparable<Ty>;
template<typename Ty> concept totally_ordered = _::totally_ordered<Ty>;
template<typename T1, typename T2> concept equality_comparable_with = _::equality_comparable_with<T1, T2>;
template<typename T1, typename T2> concept totally_ordered_with = _::totally_ordered_with<T1, T2>;

template<typename Ty> concept movable = _::is_object_v<Ty> && move_constructible<Ty> && assignable_from<Ty&, Ty> && swappable<Ty>;
template<typename Ty> concept copyable = copy_constructible<Ty> && movable<Ty> && _::copy_assignable<Ty>;
template<typename Ty> concept semiregular = copyable<Ty> && default_initializable<Ty>;
template<typename Ty> concept regular = semiregular<Ty> && equality_comparable<Ty>;

template<typename Fn, typename... Ts> concept invocable = _::invocable<Fn, Ts...>;
template<typename Fn, typename... Ts> concept regular_invocable = _::regular_invocable<Fn, Ts...>;
template<typename Fn, typename... Ts> concept predicate = _::predicate<Fn, Ts...>;
template<typename Fn, typename T1, typename T2> concept relation = _::relation<Fn, T1, T2>;
template<typename Fn, typename T1, typename T2> concept equivalence_relation = _::equivalence_relation<Fn, T1, T2>;
template<typename Fn, typename T1, typename T2> concept strict_weak_order = _::strict_weak_order<Fn, T1, T2>;

}

#endif
