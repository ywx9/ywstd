// ywstd/@/common_type.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/_.hh"
#include "../@/type_identity.hh"

namespace std {

template<typename T1, typename T2, template<typename> typename Q1, template<typename> typename Q2>
struct basic_common_reference {};

template<typename... Ts> struct common_type {};
template<typename... Ts> using common_type_t = typename common_type<Ts...>::type;

template<typename... Ts> struct common_reference {};
template<typename... Ts> using common_reference_t = typename common_reference<Ts...>::type;

namespace _::common {
  template<typename Ty> using cref = add_lvalue_reference_t<const Ty>;
  template<typename T1, typename T2> using c = decay_t<decltype(false ? declval<T1>() : declval<T2>())>;
  template<typename T1, typename T2> using condres = decltype(false ? declval<T1 (&)()>()() : declval<T2 (&)()>()());
  template<typename T1, typename T2> inline constexpr bool c1 = requires { typename c<T1, T2>; };
  template<typename T1, typename T2> inline constexpr bool c2 = requires { typename condres<cref<T1>, cref<T2>>; };
  template<typename T1, typename T2, typename D1 = decay_t<T1>, typename D2 = decay_t<T2>, size_t = inspects<c1<T1, T2>, c2<T1, T2>>> struct _t : _t<D1, D2> {};
  template<typename T1, typename T2> struct _t<T1, T2, T1, T2, 0> {};
  template<typename T1, typename T2> struct _t<T1, T2, T1, T2, 1> { using type = c<T1, T2>; };
  template<typename T1, typename T2> struct _t<T1, T2, T1, T2, 2> { using type = decay_t<condres<cref<T1>, cref<T2>>>; };
  template<typename T1, typename T2> using type = typename _t<T1, T2>::type;

  template<typename Ty> struct xref { template<typename Uy> using t = copy_cvref_t<Uy, Ty>; };
  template<typename T1, typename T2> using refll = condres<copy_cv_t<T1, T2>&, copy_cv_t<T2, T1>&>;
  template<typename T1, typename T2> using refrr = add_rvalue_reference_t<refll<T1, T2>>;
  template<typename T1, typename T2> inline constexpr bool b = requires { requires is_convertible_v<T1&&, refrr<T1, T2>>; };
  template<typename T1, typename T2> struct ref {};
  template<typename T1, typename T2> struct ref<T1&, T2&> : enable_if<requires { typename refll<T1, T2>; }, refll<T1, T2>> {};
  template<typename T1, typename T2> struct ref<T1&, T2&&> : enable_if<is_convertible_v<T1&&, refll<const T1, T2>>, refll<const T1, T2>> {};
  template<typename T1, typename T2> struct ref<T1&&, T2&> : ref<T2&, T1&&> {};
  template<typename T1, typename T2> struct ref<T1&&, T2&&> : enable_if<b<T1, T2> && b<T2, T1>, refrr<T1, T2>> {};
  template<typename T1, typename T2> using bcr = basic_common_reference<T1, T2, xref<T1>::template t, xref<T2>::template t>;
  template<typename T1, typename T2> inline constexpr bool rc1 = requires { requires is_lvalue_reference_v<typename ref<T1, T2>::type>; };
  template<typename T1, typename T2> inline constexpr bool rc2 = requires { typename bcr<T1, T2>::type; };
  template<typename T1, typename T2> inline constexpr bool rc3 = requires { typename condres<T1, T2>; };
  template<typename T1, typename T2> inline constexpr bool rc4 = requires { typename common_type_t<T1, T2>; };
  template<typename T1, typename T2, size_t = inspects<rc1<T1, T2>, rc2<T1, T2>, rc3<T1, T2>, rc4<T1, T2>>> struct _r {};
  template<typename T1, typename T2> struct _r<T1, T2, 1> : ref<T1, T2> {};
  template<typename T1, typename T2> struct _r<T1, T2, 2> : bcr<T1, T2> {};
  template<typename T1, typename T2> struct _r<T1, T2, 3> { using type = condres<T1, T2>; };
  template<typename T1, typename T2> struct _r<T1, T2, 4> : std::common_type<T1, T2> {};
  template<typename T1, typename T2> using reference = typename _r<T1, T2>::type;
}

template<typename T1> struct common_type<T1> : common_type<T1, T1> {};
template<typename T1, typename T2> struct common_type<T1, T2> : type_identity<_::common::type<T1, T2>> {};
template<typename T1, typename T2, typename... Ts> struct common_type<T1, T2, Ts...> : common_type<common_type_t<T1, T2>, Ts...> {};

template<typename T1> struct common_reference<T1> : type_identity<T1> {};
template<typename T1, typename T2> struct common_reference<T1, T2> : type_identity<_::common::reference<T1, T2>> {};
template<typename T1, typename T2, typename... Ts> struct common_reference<T1, T2, Ts...> : common_reference<common_reference_t<T1, T2>, Ts...> {};

namespace _ {
  template<typename T1, typename T2> concept common_reference_with =
    same_as<common_reference_t<T1, T2>, common_reference_t<T2, T1>> &&
    convertible_to<T1, common_reference_t<T1, T2>> && convertible_to<T2, common_reference_t<T1, T2>>;

  template<typename T1, typename T2> concept common_with =
    same_as<common_type_t<T1, T2>, common_type_t<T2, T1>> &&
    requires { static_cast<common_type_t<T1, T2>>(declval<T1>()); static_cast<common_type_t<T1, T2>>(declval<T2>()); } &&
    common_reference_with<add_lvalue_reference_t<const T1>, add_lvalue_reference_t<const T2>> &&
    common_reference_with<add_lvalue_reference_t<common_type_t<T1, T2>>,
                          common_reference_t<add_lvalue_reference_t<const T1>, add_lvalue_reference_t<const T2>>>;

  template<typename Ty, typename At> concept assignable_from =
    is_lvalue_reference_v<Ty> && requires(Ty t) { {t = declval<At>() } -> same_as<Ty>; } &&
    common_reference_with<const remove_reference_t<Ty>, const remove_reference_t<At>&>;

  template<typename Ty> concept move_assignable = assignable_from<Ty&, Ty>;

  template<typename Ty> concept copy_assignable =
    move_assignable<Ty> && assignable_from<Ty&, Ty&> && assignable_from<Ty&, const Ty&> && assignable_from<Ty&, const Ty>;

  template<typename T1, typename T2> concept equality_comparable_with =
    equality_comparable<T1> && equality_comparable<T2> && weakly_equality_comparable_with<T1, T2> &&
    common_reference_with<const remove_reference_t<T1>&, const remove_reference_t<T2>&> &&
    equality_comparable<common_reference_t<const remove_reference_t<T1>&, const remove_reference_t<T2>&>>;

  template<typename T1, typename T2> concept totally_ordered_with =
    totally_ordered<T1> && totally_ordered<T2> && equality_comparable_with<T1, T2> && partially_ordered_with<T1, T2> &&
    common_reference_with<const remove_reference_t<T1>&, const remove_reference_t<T2>&> &&
    totally_ordered<common_reference_t<const remove_reference_t<T1>&, const remove_reference_t<T2>&>>;
}

}
