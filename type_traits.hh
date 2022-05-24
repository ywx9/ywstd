// ywstd/type_traits.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <type_traits>
#else

#include "@/_.hh"
#include "@/add-remove.hh"
#include "@/common_type.hh"
#include "@/integral_constant.hh"
#include "@/invoke.hh"
#include "@/add-remove.hh"
#include "@/type_identity.hh"

namespace std {

using size_t = decltype(sizeof(int));

template<typename... Ts> using void_t = void;

template<bool Bx, typename Ty = void> struct enable_if {};
template<typename Ty> struct enable_if<true, Ty> : type_identity<Ty> {};
template<bool Bx, typename Ty = void> using enable_if_t = typename enable_if<Bx, Ty>::type;

template<bool Bx, typename T1, typename T2> struct conditional : type_identity<_::conditional_t<Bx, T1, T2>> {};
template<bool Bx, typename T1, typename T2> using conditional_t = typename conditional<Bx, T1, T2>::type;

template<typename... Ts> struct conjunction : bool_constant<(Ts::value && ...)> {};
template<typename... Ts> inline constexpr bool conjunction_v = conjunction<Ts...>::value;

template<typename... Ts> struct disjunction : bool_constant<(Ts::value || ...)> {};
template<typename... Ts> inline constexpr bool disjunction_v = disjunction<Ts...>::value;

template<typename Tr> struct negation : bool_constant<Tr::value> {};
template<typename Tr> inline constexpr bool negation_v = negation<Tr>::value;

template<typename Ty> struct alignment_of : integral_constant<size_t, alignof(Ty)> {};
template<typename Ty> inline constexpr size_t alignment_of_v = alignment_of<Ty>::value;

template<typename Ty> struct rank : integral_constant<size_t, _::rank_v<Ty>> {};
template<typename Ty> inline constexpr size_t rank_v = rank<Ty>::value;

template<typename Ty, size_t Ix = 0> struct extent : integral_constant<size_t, _::extent_v<Ty, Ix>> {};
template<typename Ty, size_t Ix = 0> inline constexpr size_t extent_v = extent<Ty, Ix>::value;

template<typename T1, typename T2> struct is_same : bool_constant<_::is_same_v<T1, T2>> {};
template<typename T1, typename T2> inline constexpr bool is_same_v = is_same<T1, T2>::value;

template<typename T1, typename T2> struct is_base_of : bool_constant<_::is_base_of_v<T1, T2>> {};
template<typename T1, typename T2> inline constexpr bool is_base_of_v = is_base_of<T1, T2>::value;

template<typename T1, typename T2> struct is_convertible : bool_constant<_::is_convertible_v<T1, T2>> {};
template<typename T1, typename T2> inline constexpr bool is_convertible_v = is_convertible<T1, T2>::value;

template<typename T1, typename T2> struct is_nothrow_convertible : bool_constant<_::is_nothrow_convertible_v<T1, T2>> {};
template<typename T1, typename T2> inline constexpr bool is_nothrow_convertible_v = is_nothrow_convertible<T1, T2>::value;

template<typename T1, typename T2> struct is_layout_compatible {};
template<typename T1, typename T2> inline constexpr bool is_layout_compatible_v = is_layout_compatible<T1, T2>::value;

template<typename T1, typename T2> struct is_pointer_interconvertible_base_of {};
template<typename T1, typename T2> inline constexpr bool is_pointer_interconvertible_base_of_v = is_pointer_interconvertible_base_of<T1, T2>::value;

template<typename Rt, typename Fn, typename... Ts> struct is_invocable_r : bool_constant<_::is_invocable_r_v<Rt, Fn, Ts...>> {};
template<typename Rt, typename Fn, typename... Ts> inline constexpr bool is_invocable_r_v = is_invocable_r<Rt, Fn, Ts...>::value;

template<typename Rt, typename Fn, typename... Ts> struct is_nothrow_invocable_r : bool_constant<_::is_nothrow_invocable_r_v<Rt, Fn, Ts...>> {};
template<typename Rt, typename Fn, typename... Ts> inline constexpr bool is_nothrow_invocable_r_v = is_nothrow_invocable_r<Rt, Fn, Ts...>::value;

template<typename Ty> struct is_const : bool_constant<_::is_const_v<Ty>> {};
template<typename Ty> inline constexpr bool is_const_v = is_const<Ty>::value;

template<typename Ty> struct is_volatile : bool_constant<_::is_volatile_v<Ty>> {};
template<typename Ty> inline constexpr bool is_volatile_v = is_volatile<Ty>::value;

template<typename Ty> struct is_lvalue_reference : bool_constant<_::is_lvalue_reference_v<Ty>> {};
template<typename Ty> inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<Ty>::value;

template<typename Ty> struct is_rvalue_reference : bool_constant<_::is_rvalue_reference_v<Ty>> {};
template<typename Ty> inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<Ty>::value;

template<typename Ty> struct is_reference : disjunction<is_lvalue_reference<Ty>, is_rvalue_reference<Ty>> {};
template<typename Ty> inline constexpr bool is_reference_v = is_reference<Ty>::value;

template<typename Ty> struct is_function : conjunction<negation<is_const<const Ty>>, negation<is_reference<Ty>>> {};
template<typename Ty> inline constexpr bool is_function_v = is_function<Ty>::value;

template<typename Ty> struct is_pointer : bool_constant<_::is_pointer_v<Ty>> {};
template<typename Ty> inline constexpr bool is_pointer_v = is_pointer<Ty>::value;

template<typename Ty> struct is_bounded_array : bool_constant<_::is_bounded_array_v<Ty>> {};
template<typename Ty> inline constexpr bool is_bounded_array_v = is_bounded_array<Ty>::value;

template<typename Ty> struct is_unbounded_array : bool_constant<_::is_unbounded_array_v<Ty>> {};
template<typename Ty> inline constexpr bool is_unbounded_array_v = is_unbounded_array<Ty>::value;

template<typename Ty> struct is_array : disjunction<is_bounded_array<Ty>, is_unbounded_array<Ty>> {};
template<typename Ty> inline constexpr bool is_array_v = is_array<Ty>::value;

template<typename Ty> struct is_member_pointer : bool_constant<_::is_member_pointer_v<Ty>> {};
template<typename Ty> inline constexpr bool is_member_pointer_v = is_member_pointer<Ty>::value;

template<typename Ty> struct is_member_function_pointer : bool_constant<_::is_member_function_pointer_v<Ty>> {};
template<typename Ty> inline constexpr bool is_member_function_pointer_v = is_member_function_pointer<Ty>::value;

template<typename Ty> struct is_member_object_pointer : conjunction<is_member_pointer<Ty>, negation<is_member_function_pointer<Ty>>> {};
template<typename Ty> inline constexpr bool is_member_object_pointer_v = is_member_object_pointer<Ty>::value;

template<typename Ty> struct is_enum : bool_constant<_::is_enum_v<Ty>> {};
template<typename Ty> inline constexpr bool is_enum_v = is_enum<Ty>::value;

template<typename Ty> struct is_scoped_enum : conjunction<is_enum<Ty>, negation<is_convertible<Ty, bool>>> {};
template<typename Ty> inline constexpr bool is_scoped_enum_v = is_scoped_enum<Ty>::value;

template<typename Ty> struct is_class : bool_constant<_::is_class_v<Ty>> {};
template<typename Ty> inline constexpr bool is_class_v = is_class<Ty>::value;

template<typename Ty> struct is_union : bool_constant<_::is_union_v<Ty>> {};
template<typename Ty> inline constexpr bool is_union_v = is_union<Ty>::value;

template<typename Ty> struct is_void : bool_constant<_::is_void_v<Ty>> {};
template<typename Ty> inline constexpr bool is_void_v = is_void<Ty>::value;

template<typename Ty> struct is_null_pointer : is_same<remove_cv_t<Ty>, decltype(nullptr)> {};
template<typename Ty> inline constexpr bool is_null_pointer_v = is_null_pointer<Ty>::value;

template<typename Ty> struct is_integral : bool_constant<_::is_integral_v<Ty>> {};
template<typename Ty> inline constexpr bool is_integral_v = is_integral<Ty>::value;

template<typename Ty> struct is_floating_point : bool_constant<_::is_floating_point_v<Ty>> {};
template<typename Ty> inline constexpr bool is_floating_point_v = is_floating_point<Ty>::value;

template<typename Ty> struct is_arithmetic : disjunction<is_integral<Ty>, is_floating_point<Ty>> {};
template<typename Ty> inline constexpr bool is_arithmetic_v = is_arithmetic<Ty>::value;

template<typename Ty> struct is_signed : bool_constant<_::is_signed_v<Ty>> {};
template<typename Ty> inline constexpr bool is_signed_v = is_signed<Ty>::value;

template<typename Ty> struct is_unsigned : conjunction<is_integral<Ty>, negation<is_signed<Ty>>> {};
template<typename Ty> inline constexpr bool is_unsigned_v = is_unsigned<Ty>::value;

template<typename Ty> struct is_fundamental : disjunction<is_arithmetic<Ty>, is_void<Ty>, is_null_pointer<Ty>> {};
template<typename Ty> inline constexpr bool is_fundamental_v = is_fundamental<Ty>::value;

template<typename Ty> struct is_scalar : disjunction<is_arithmetic<Ty>, is_enum<Ty>, is_pointer<Ty>, is_member_pointer<Ty>, is_null_pointer<Ty>> {};
template<typename Ty> inline constexpr bool is_scalar_v = is_scalar<Ty>::value;

template<typename Ty> struct is_object : disjunction<is_scalar<Ty>, is_array<Ty>, is_class<Ty>, is_union<Ty>> {};
template<typename Ty> inline constexpr bool is_object_v = is_object<Ty>::value;

template<typename Ty> struct is_compound : negation<is_fundamental<Ty>> {};
template<typename Ty> inline constexpr bool is_compound_v = is_compound<Ty>::value;

template<typename Ty> struct is_destructible : bool_constant<_::is_destructible_v<Ty>> {};
template<typename Ty> inline constexpr bool is_destructible_v = is_destructible<Ty>::value;

template<typename Ty> struct is_nothrow_destructible : bool_constant<_::is_nothrow_destructible_v<Ty>> {};
template<typename Ty> inline constexpr bool is_nothrow_destructible_v = is_nothrow_destructible<Ty>::value;

template<typename Ty> struct is_trivially_destructible : bool_constant<_::is_trivially_destructible_v<Ty>> {};
template<typename Ty> inline constexpr bool is_trivially_destructible_v = is_trivially_destructible<Ty>::value;

template<typename Ty, typename... As> struct is_constructible : bool_constant<_::is_constructible_v<Ty, As...>> {};
template<typename Ty, typename... As> inline constexpr bool is_constructible_v = is_constructible<Ty, As...>::value;

template<typename Ty, typename... As> struct is_nothrow_constructible : bool_constant<_::is_nothrow_constructible_v<Ty, As...>> {};
template<typename Ty, typename... As> inline constexpr bool is_nothrow_constructible_v = is_nothrow_constructible<Ty, As...>::value;

template<typename Ty, typename... As> struct is_trivially_constructible : bool_constant<_::is_trivially_constructible_v<Ty, As...>> {};
template<typename Ty, typename... As> inline constexpr bool is_trivially_constructible_v = is_trivially_constructible<Ty, As...>::value;

template<typename Ty, typename At> struct is_assignable : bool_constant<_::is_assignable_v<Ty, At>> {};
template<typename Ty, typename At> inline constexpr bool is_assignable_v = is_assignable<Ty, At>::value;

template<typename Ty, typename At> struct is_nothrow_assignable : bool_constant<_::is_nothrow_assignable_v<Ty, At>> {};
template<typename Ty, typename At> inline constexpr bool is_nothrow_assignable_v = is_nothrow_assignable<Ty, At>::value;

template<typename Ty, typename At> struct is_trivially_assignable : bool_constant<_::is_trivially_assignable_v<Ty, At>> {};
template<typename Ty, typename At> inline constexpr bool is_trivially_assignable_v = is_trivially_assignable<Ty, At>::value;

template<typename Ty> struct is_default_constructible : is_constructible<Ty> {};
template<typename Ty> inline constexpr bool is_default_constructible_v = is_default_constructible<Ty>::value;

template<typename Ty> struct is_nothrow_default_constructible : is_nothrow_constructible<Ty> {};
template<typename Ty> inline constexpr bool is_nothrow_default_constructible_v = is_nothrow_default_constructible<Ty>::value;

template<typename Ty> struct is_trivially_default_constructible : is_trivially_constructible<Ty> {};
template<typename Ty> inline constexpr bool is_trivially_default_constructible_v = is_trivially_default_constructible<Ty>::value;

template<typename Ty> struct is_copy_constructible : is_constructible<Ty, const Ty&> {};
template<typename Ty> inline constexpr bool is_copy_constructible_v = is_copy_constructible<Ty>::value;

template<typename Ty> struct is_nothrow_copy_constructible : is_nothrow_constructible<Ty, const Ty&> {};
template<typename Ty> inline constexpr bool is_nothrow_copy_constructible_v = is_nothrow_copy_constructible<Ty>::value;

template<typename Ty> struct is_trivially_copy_constructible : is_trivially_constructible<Ty, const Ty&> {};
template<typename Ty> inline constexpr bool is_trivially_copy_constructible_v = is_trivially_copy_constructible<Ty>::value;

template<typename Ty> struct is_move_constructible : is_constructible<Ty, Ty> {};
template<typename Ty> inline constexpr bool is_move_constructible_v = is_move_constructible<Ty>::value;

template<typename Ty> struct is_nothrow_move_constructible : is_nothrow_constructible<Ty, Ty> {};
template<typename Ty> inline constexpr bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<Ty>::value;

template<typename Ty> struct is_trivially_move_constructible : is_trivially_constructible<Ty, Ty> {};
template<typename Ty> inline constexpr bool is_trivially_move_constructible_v = is_trivially_move_constructible<Ty>::value;

template<typename Ty> struct is_copy_assignable : is_assignable<Ty&, const Ty&> {};
template<typename Ty> inline constexpr bool is_copy_assignable_v = is_copy_assignable<Ty>::value;

template<typename Ty> struct is_nothrow_copy_assignable : is_nothrow_assignable<Ty&, const Ty&> {};
template<typename Ty> inline constexpr bool is_nothrow_copy_assignable_v = is_nothrow_copy_assignable<Ty>::value;

template<typename Ty> struct is_trivially_copy_assignable : is_trivially_assignable<Ty&, const Ty&> {};
template<typename Ty> inline constexpr bool is_trivially_copy_assignable_v = is_trivially_copy_assignable<Ty>::value;

template<typename Ty> struct is_move_assignable : is_assignable<Ty&, Ty> {};
template<typename Ty> inline constexpr bool is_move_assignable_v = is_move_assignable<Ty>::value;

template<typename Ty> struct is_nothrow_move_assignable : is_nothrow_assignable<Ty&, Ty> {};
template<typename Ty> inline constexpr bool is_nothrow_move_assignable_v = is_nothrow_move_assignable<Ty>::value;

template<typename Ty> struct is_trivially_move_assignable : is_trivially_assignable<Ty&, Ty> {};
template<typename Ty> inline constexpr bool is_trivially_move_assignable_v = is_trivially_move_assignable<Ty>::value;

template<typename Ty> struct is_swappable : bool_constant<_::is_swappable_v<Ty>> {};
template<typename Ty> inline constexpr bool is_swappable_v = is_swappable<Ty>::value;

template<typename Ty> struct is_nothrow_swappable : bool_constant<_::is_nothrow_swappable_v<Ty>> {};
template<typename Ty> inline constexpr bool is_nothrow_swappable_v = is_nothrow_swappable<Ty>::value;

template<typename T1, typename T2> struct is_swappable_with : bool_constant<_::is_swappable_with_v<T1, T2>> {};
template<typename T1, typename T2> inline constexpr bool is_swappable_with_v = is_swappable_with<T1, T2>::value;

template<typename T1, typename T2> struct is_nothrow_swappable_with : bool_constant<_::is_nothrow_swappable_with_v<T1, T2>> {};
template<typename T1, typename T2> inline constexpr bool is_nothrow_swappable_with_v = is_nothrow_swappable_with<T1, T2>::value;

template<typename Ty> struct has_unique_object_representations : bool_constant<_::has_unique_object_representations_v<Ty>> {};
template<typename Ty> inline constexpr bool has_unique_object_representations_v = has_unique_object_representations<Ty>::value;

template<typename Ty> struct has_virtual_destructor : bool_constant<_::has_virtual_destructor_v<Ty>> {};
template<typename Ty> inline constexpr bool has_virtual_destructor_v = has_virtual_destructor<Ty>::value;

template<typename Ty> struct is_abstract : bool_constant<_::is_abstract_v<Ty>> {};
template<typename Ty> inline constexpr bool is_abstract_v = is_abstract<Ty>::value;

template<typename Ty> struct is_aggregate : bool_constant<_::is_aggregate_v<Ty>> {};
template<typename Ty> inline constexpr bool is_aggregate_v = is_aggregate<Ty>::value;

template<typename Ty> struct is_empty : bool_constant<_::is_empty_v<Ty>> {};
template<typename Ty> inline constexpr bool is_empty_v = is_empty<Ty>::value;

template<typename Ty> struct is_final : bool_constant<_::is_final_v<Ty>> {};
template<typename Ty> inline constexpr bool is_final_v = is_final<Ty>::value;

template<typename Ty> struct is_polymorphic : bool_constant<_::is_polymorphic_v<Ty>> {};
template<typename Ty> inline constexpr bool is_polymorphic_v = is_polymorphic<Ty>::value;

template<typename Ty> struct is_standard_layout : bool_constant<_::is_standard_layout_v<Ty>> {};
template<typename Ty> inline constexpr bool is_standard_layout_v = is_standard_layout<Ty>::value;

template<typename Ty> struct is_trivially_copyable : bool_constant<_::is_trivially_copyable_v<Ty>> {};
template<typename Ty> inline constexpr bool is_trivially_copyable_v = is_trivially_copyable<Ty>::value;

template<typename Ty> struct is_trivial : conjunction<is_trivially_default_constructible<Ty>, is_trivially_copyable<Ty>> {};
template<typename Ty> inline constexpr bool is_trivial_v = is_trivial<Ty>::value;

template<typename Ty> struct make_signed : type_identity<_::make_signed_t<Ty>> {};
template<typename Ty> using make_signed_t = typename make_signed<Ty>::type;

template<typename Ty> struct make_unsigned : type_identity<_::make_unsigned_t<Ty>> {};
template<typename Ty> using make_unsigned_t = typename make_unsigned<Ty>::type;

template<typename Ty> struct underlying_type : enable_if<is_enum_v<Ty>, _::underlying_type_t<Ty>> {};
template<typename Ty> using underlying_type_t = typename underlying_type<Ty>::type;

template<typename Ty> struct unwrap_reference : type_identity<_::unwrap_reference_t<Ty>> {};
template<typename Ty> using unwrap_reference_t = typename unwrap_reference<Ty>::type;

template<typename Ty> struct unwrap_ref_decay : unwrap_reference<decay_t<Ty>> {};
template<typename Ty> using unwrap_ref_decay_t = typename unwrap_ref_decay<Ty>::type;

template<typename Ct, typename Mt> constexpr bool is_pointer_interconvertible_with_class(Mt Ct::*m) noexcept;
template<typename C1, typename C2, typename M1, typename M2> constexpr bool is_corresponding_member(M1 C1::*m1, M2 C2::*m2) noexcept;
constexpr bool is_constant_evaluated() noexcept { return __builtin_is_constant_evaluated(); }

}

#endif
