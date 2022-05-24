// ywstd/@/invoke.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/_.hh"
#include "../@/integral_constant.hh"
#include "../@/type_identity.hh"

namespace std {

template<typename Ty> class reference_wrapper;

namespace _ {
  struct _invoke {
    template<typename Fn, typename... Ts> static constexpr size_t i = 0;
    template<typename Fn, typename Ty, typename... Ts> requires is_member_pointer_v<Ty> static constexpr size_t i<Fn, Ty, Ts...> =
      inspects<is_base_of_v<class_type_t<Fn>, decay_t<Ty>>, specialized_of<decay_t<Ty>, reference_wrapper>, true> + (is_member_object_pointer_v<Fn> ? 3 : 0);
    template<typename Fn, typename... Ts> static constexpr bool c0 = requires { declval<Fn>()(declval<Ts>()...); };
    template<typename Fn, typename Ty, typename... Ts> static constexpr bool c1 = requires { (declval<Ty>().*declval<Fn>())(declval<Ts>()...); };
    template<typename Fn, typename Ty, typename... Ts> static constexpr bool c2 = requires { (declval<Ty>().get().*declval<Fn>())(declval<Ts>()...); };
    template<typename Fn, typename Ty, typename... Ts> static constexpr bool c3 = requires { ((*declval<Ty>()).*declval<Fn>())(declval<Ts>()...); };
    template<typename Fn, typename Ty> static constexpr bool c4 = requires { declval<Ty>().*declval<Fn>(); };
    template<typename Fn, typename Ty> static constexpr bool c5 = requires { declval<Ty>().get().*declval<Fn>(); };
    template<typename Fn, typename Ty> static constexpr bool c6 = requires { (*declval<Ty>()).*declval<Fn>(); };
    template<typename Fn, typename... Ts> static constexpr call_style cs = {};
    template<typename Fn> static constexpr call_style cs<Fn> = {0, c0<Fn>, noexcept(declval<Fn>()())};
    template<typename Fn, typename Ty, typename... Ts> static constexpr call_style cs<Fn, Ty, Ts...> = []() -> call_style {
      if constexpr (i<Fn, Ty, Ts...> == 0) return {0, c0<Fn, Ty, Ts...>, noexcept(declval<Fn>()(declval<Ty>(), declval<Ts>()...))};
      else if constexpr (i<Fn, Ty, Ts...> == 1) return {1, c1<Fn, Ty, Ts...>, noexcept((declval<Ty>().*declval<Fn>())(declval<Ts>()...))};
      else if constexpr (i<Fn, Ty, Ts...> == 2) return {2, c2<Fn, Ty, Ts...>, noexcept((declval<Ty>().get().*declval<Fn>())(declval<Ts>()...))};
      else if constexpr (i<Fn, Ty, Ts...> == 3) return {3, c3<Fn, Ty, Ts...>, noexcept(((*declval<Ty>()).*declval<Fn>())(declval<Ts>()...))};
      else if constexpr (i<Fn, Ty, Ts...> == 4) return {4, c4<Fn, Ty>, noexcept(declval<Ty>().*declval<Fn>())};
      else if constexpr (i<Fn, Ty, Ts...> == 5) return {5, c5<Fn, Ty>, noexcept(declval<Ty>().get().*declval<Fn>())};
      else if constexpr (i<Fn, Ty, Ts...> == 6) return {6, c6<Fn, Ty>, noexcept((*declval<Ty>()).*declval<Fn>())};
      else return {}; }();
    template<typename Fn> requires(cs<Fn>.able) constexpr decltype(auto) operator()(Fn&& f) const noexcept(cs<Fn>.nothrow) { return static_cast<Fn&&>(f)(); }
    template<typename Fn, typename Ty, typename... Ts> requires(cs<Fn, Ty, Ts...>.able)
    constexpr decltype(auto) operator()(Fn&& f, Ty&& x, Ts&&... xs) const noexcept(cs<Fn, Ty, Ts...>.nothrow) {
      if constexpr (cs<Fn, Ty, Ts...>.style == 0) return static_cast<Fn&&>(f)(static_cast<Ty&&>(x), static_cast<Ts&&>(xs)...);
      else if constexpr (cs<Fn, Ty, Ts...>.style == 1) return (static_cast<Ty&&>(x).*static_cast<Fn&&>(f))(static_cast<Ts&&>(xs)...);
      else if constexpr (cs<Fn, Ty, Ts...>.style == 2) return (static_cast<Ty&&>(x).get().*static_cast<Fn&&>(f))(static_cast<Ts&&>(xs)...);
      else if constexpr (cs<Fn, Ty, Ts...>.style == 3) return ((*static_cast<Ty&&>(x)).*static_cast<Fn&&>(f))(static_cast<Ts&&>(xs)...);
      else if constexpr (cs<Fn, Ty, Ts...>.style == 4) return static_cast<Ty&&>(x).*static_cast<Fn&&>(f);
      else if constexpr (cs<Fn, Ty, Ts...>.style == 5) return static_cast<Ty&&>(x).get().*static_cast<Fn&&>(f);
      else if constexpr (cs<Fn, Ty, Ts...>.style == 6) return (*static_cast<Ty&&>(x)).*static_cast<Fn&&>(f);
    }
  };
}

template<typename Fn, typename... Ts> struct invoke_result {};
template<typename Fn, typename... Ts> requires requires { requires _::_invoke::cs<Fn, Ts...>.able; }
struct invoke_result<Fn, Ts...> : type_identity<decltype(_::_invoke{}(_::declval<Fn>(), _::declval<Ts>()...))> {};
template<typename Fn, typename... Ts> using invoke_result_t = typename invoke_result<Fn, Ts...>::type;

template<typename Fn, typename... Ts> struct is_invocable : bool_constant<_::_invoke::cs<Fn, Ts...>.able> {};
template<typename Fn, typename... Ts> inline constexpr bool is_invocable_v = is_invocable<Fn, Ts...>::value;

template<typename Fn, typename... Ts> struct is_nothrow_invocable : bool_constant<_::_invoke::cs<Fn, Ts...>.nothrow> {};
template<typename Fn, typename... Ts> inline constexpr bool is_nothrow_invocable_v = is_nothrow_invocable<Fn, Ts...>::value;

template<typename Fn, typename... Ts>
constexpr typename invoke_result<Fn, Ts...>::type invoke(Fn&& f, Ts&&... xs)
  noexcept(is_nothrow_invocable_v<Fn, Ts...>) requires is_invocable_v<Fn, Ts...> {
  return _::_invoke{}(static_cast<Fn&&>(f), static_cast<Ts&&>(xs)...);
}

namespace _ {
  template<typename Fn, typename... Ts> concept invocable =  requires { std::invoke(declval<Fn>(), declval<Ts>()...); };
  template<typename Fn, typename... Ts> concept regular_invocable = invocable<Fn, Ts...>;
  template<typename Fn, typename... Ts> concept predicate = regular_invocable<Fn, Ts...> && boolean_testable<invoke_result_t<Fn, Ts...>>;
  template<typename Fn, typename T1, typename T2> concept relation = predicate<Fn,T1,T1> && predicate<Fn,T1,T2> && predicate<Fn,T2,T1> && predicate<Fn,T2,T2>;
  template<typename Fn, typename T1, typename T2> concept equivalence_relation = relation<Fn, T1, T2>;
  template<typename Fn, typename T1, typename T2> concept strict_weak_order = relation<Fn, T1, T2>;

  template<typename Rt, typename Fn, typename... Ts> inline constexpr bool is_invocable_r_v =
    requires { { std::invoke(declval<Fn>(), declval<Ts>()...) } -> convertible_to<Rt>; };
  template<typename Rt, typename Fn, typename... Ts> inline constexpr bool is_nothrow_invocable_r_v =
    requires { { declval<int (&)(Rt) noexcept>()(std::invoke(declval<Fn>()), declval<Ts>()...) } noexcept; };

  template<typename Ty> struct _unwrap_reference : type_identity<Ty> {};
  template<typename Ty> struct _unwrap_reference<reference_wrapper<Ty>> : type_identity<Ty&> {};
  template<typename Ty> using unwrap_reference_t = typename _unwrap_reference<Ty>::type;
  template<typename Ty> using unwrap_ref_decay_t = unwrap_reference_t<decay_t<Ty>>;
}

}
