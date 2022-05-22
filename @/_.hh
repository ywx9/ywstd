// ywstd/@/_.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

namespace std::_ {

using nullptr_t = decltype(nullptr);
using ptrdiff_t = decltype((int*)0 - (int*)0);
using size_t = decltype(sizeof(int));

template<typename... Ts> using void_t = void;

struct call_style { size_t style; bool able, nothrow; };

template<auto Vx> struct constant {
  using value_type = decltype(Vx);
  static constexpr value_type value = Vx;
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};

template<typename T1, typename T2 = void, typename T3 = void, typename T4 = void, typename T5 = void>
struct types { using t1 = T1; using t2 = T2; using t3 = T3; using t4 = T4; using t5 = T5; };

template<typename Ty> using type_identity_t = typename types<Ty>::t1;

template<typename Ty> constexpr size_t bit_size = sizeof(Ty) * 8;
template<typename Ty> constexpr size_t bit_size<const Ty> = bit_size<Ty>;
template<typename Ty> constexpr size_t bit_size<volatile Ty> = bit_size<Ty>;
template<typename Ty> constexpr size_t bit_size<const volatile Ty> = bit_size<Ty>;
template<> constexpr size_t bit_size<bool> = 1;

template<bool... Bs> inline constexpr size_t inspects = 0;
template<bool... Bs> inline constexpr size_t inspects<true, Bs...> = 1;
template<bool... Bs> inline constexpr size_t inspects<false, Bs...> = (Bs || ...) ? 1 + inspects<Bs...> : 0;

template<bool... Bs> inline constexpr size_t counts = 0;
template<bool... Bs> inline constexpr size_t counts<true, Bs...> = 1 + counts<Bs...>;
template<bool... Bs> inline constexpr size_t counts<false, Bs...> = counts<Bs...>;

inline void non_constant_expression(const char* const = nullptr) {}

inline constexpr size_t min_buckets = 8; // for unordered_map, unordered_set

inline constexpr int char_bit = 8;
inline constexpr int mb_len_max = 5;
inline constexpr char char_min = (-128);
inline constexpr char char_max = 127;
inline constexpr signed char schar_min = (-128);
inline constexpr short shrt_min = (-32768);
inline constexpr int int_min = (-2147483647 - 1);
inline constexpr long long_min = (-2147483647L - 1L);
inline constexpr long long llong_min = (-9223372036854775807LL - 1);
inline constexpr signed char schar_max = 127;
inline constexpr short shrt_max = 32767;
inline constexpr int int_max = 2147483647;
inline constexpr long long_max = 2147483647L;
inline constexpr long long llong_max = 9223372036854775807LL;
inline constexpr unsigned char uchar_max = 0xff;
inline constexpr unsigned short ushrt_max = 0xffff;
inline constexpr unsigned int uint_max = 0xffffffff;
inline constexpr unsigned long ulong_max = 0xfffffffful;
inline constexpr unsigned long long ullong_max = 0xffffffffffffffffull;
inline constexpr ptrdiff_t ptrdiff_min = static_cast<ptrdiff_t>(sizeof(ptrdiff_t) == 4 ? int_min : llong_min);
inline constexpr ptrdiff_t ptrdiff_max = static_cast<ptrdiff_t>(sizeof(ptrdiff_t) == 4 ? int_max : llong_max);
inline constexpr size_t size_max = static_cast<size_t>(sizeof(size_t) == 4 ? uint_max : ullong_max);

inline constexpr int flt_radix = 2;
inline constexpr int decimal_dig = 17;
inline constexpr int flt_decimal_dig = 9;
inline constexpr int dbl_decimal_dig = 17;
inline constexpr int ldbl_decimal_dig = dbl_decimal_dig;
inline constexpr float flt_max = 3.402823466e+38f;
inline constexpr double dbl_max = 1.7976931348623158e+308;
inline constexpr long double ldbl_max = dbl_max;
inline constexpr float flt_min = 1.175494351e-38f;
inline constexpr double dbl_min = 2.2250738585072014e-308;
inline constexpr long double ldbl_min = dbl_min;
inline constexpr float flt_true_min = 1.401298464e-45f;
inline constexpr double dbl_true_min = 4.9406564584124654e-324;
inline constexpr long double ldbl_true_min = dbl_true_min;
inline constexpr float flt_epsilon = 1.192092896e-07f;
inline constexpr double dbl_epsilon = 2.2204460492503131e-016;
inline constexpr long double ldbl_epsilon = dbl_epsilon;
inline constexpr int flt_dig = 6;
inline constexpr int dbl_dig = 15;
inline constexpr int ldbl_dig = dbl_dig;
inline constexpr int flt_mant_dig = 24;
inline constexpr int dbl_mant_dig = 53;
inline constexpr int ldbl_mant_dig = dbl_mant_dig;
inline constexpr int flt_max_exp = 128;
inline constexpr int dbl_max_exp = 1024;
inline constexpr int ldbl_max_exp = dbl_max_exp;
inline constexpr int flt_max_10_exp = 38;
inline constexpr int dbl_max_10_exp = 308;
inline constexpr int ldbl_max_10_exp = dbl_max_10_exp;
inline constexpr int flt_min_exp = (-125);
inline constexpr int dbl_min_exp = (-1021);
inline constexpr int ldbl_min_exp = dbl_min_exp;
inline constexpr int flt_min_10_exp = (-37);
inline constexpr int dbl_min_10_exp = (-307);
inline constexpr int ldbl_min_10_exp = dbl_min_10_exp;
inline constexpr int flt_eval_method = 0;
inline constexpr int flt_has_subnorm = 1;
inline constexpr int dbl_has_subnorm = 1;
inline constexpr int ldbl_has_subnorm = dbl_has_subnorm;

template<bool Bx, typename Ty = void> struct enable_if {};
template<typename Ty> struct enable_if<true, Ty> { using type = Ty; };

template<bool Bx, typename T1, typename T2> struct conditional { using type = T2; };
template<typename T1, typename T2> struct conditional<true, T1, T2> { using type = T1; };
template<bool Bx, typename T1, typename T2> using conditional_t = typename conditional<Bx, T1, T2>::type;

template<size_t Ix, typename... Ts> struct _type_switch {};
template<size_t Ix, typename T1, typename... Ts> struct _type_switch<Ix, T1, Ts...> : _type_switch<Ix - 1, Ts...> {};
template<typename T1, typename... Ts> struct _type_switch<0, T1, Ts...> { using type = T1; };
template<size_t Ix, typename... Ts> using type_switch_t = typename _type_switch<Ix, Ts...>::type;

template<typename Ty> struct _remove_cv : types<Ty, Ty, Ty, constant<false>, constant<false>> {};
template<typename Ty> struct _remove_cv<const Ty> : types<Ty, Ty, const Ty, constant<true>, constant<false>> {};
template<typename Ty> struct _remove_cv<volatile Ty> : types<Ty, volatile Ty, Ty, constant<false>, constant<true>> {};
template<typename Ty> struct _remove_cv<const volatile Ty> : types<Ty, volatile Ty, const Ty, constant<true>, constant<true>> {};
template<typename Ty> using remove_cv_t = typename _remove_cv<Ty>::t1;
template<typename Ty> using remove_const_t = typename _remove_cv<Ty>::t2;
template<typename Ty> using remove_volatile_t = typename _remove_cv<Ty>::t3;
template<typename Ty> inline constexpr bool is_const_v = _remove_cv<Ty>::t4::value;
template<typename Ty> inline constexpr bool is_volatile_v = _remove_cv<Ty>::t5::value;

template<typename Ty> struct _remove_reference : types<Ty, constant<false>, constant<false>> {};
template<typename Ty> struct _remove_reference<Ty&> : types<Ty, constant<true>, constant<false>> {};
template<typename Ty> struct _remove_reference<Ty&&> : types<Ty, constant<false>, constant<true>> {};
template<typename Ty> using remove_reference_t = typename _remove_reference<Ty>::t1;
template<typename Ty> using remove_cvref_t = remove_cv_t<remove_reference_t<Ty>>;
template<typename Ty> inline constexpr bool is_lvalue_reference_v = _remove_reference<Ty>::t2::value;
template<typename Ty> inline constexpr bool is_rvalue_reference_v = _remove_reference<Ty>::t3::value;
template<typename Ty> inline constexpr bool is_reference_v = is_lvalue_reference_v<Ty> || is_rvalue_reference_v<Ty>;
template<typename Ty> inline constexpr bool is_function_v = !is_const_v<const Ty> && !is_reference_v<Ty>;

template<typename Ty> struct _remove_pointer : types<Ty, Ty, constant<false>> {};
template<typename Ty> using remove_pointer_t = typename _remove_pointer<Ty>::t1;
template<typename Ty> using remove_all_pointers_t = typename _remove_pointer<Ty>::t2;
template<typename Ty> inline constexpr bool is_pointer_v = _remove_pointer<Ty>::t3::value;
template<typename Ty> struct _remove_pointer<Ty*> : types<Ty, remove_all_pointers_t<Ty>, constant<true>> {};
template<typename Ty> struct _remove_pointer<Ty* const> : types<Ty, remove_all_pointers_t<Ty>, constant<true>> {};
template<typename Ty> struct _remove_pointer<Ty* volatile> : types<Ty, remove_all_pointers_t<Ty>, constant<true>> {};
template<typename Ty> struct _remove_pointer<Ty* const volatile> : types<Ty, remove_all_pointers_t<Ty>, constant<true>> {};

template<typename Ty> struct _remove_extent : types<Ty, Ty, constant<false>, constant<false>> {};
template<typename Ty> using remove_extent_t = typename _remove_extent<Ty>::t1;
template<typename Ty> using remove_all_extents_t = typename _remove_extent<Ty>::t2;
template<typename Ty> inline constexpr bool is_bounded_array_v = _remove_extent<Ty>::t3::value;
template<typename Ty> inline constexpr bool is_unbounded_array_v = _remove_extent<Ty>::t4::value;
template<typename Ty> inline constexpr bool is_array_v = is_bounded_array_v<Ty> || is_unbounded_array_v<Ty>;
template<typename Ty> struct _remove_extent<Ty[]> : types<Ty, remove_all_extents_t<Ty>, constant<false>, constant<true>> {};
template<typename Ty, size_t Nx> struct _remove_extent<Ty[Nx]> : types<Ty, remove_all_extents_t<Ty>, constant<true>, constant<false>> {};

template<typename Ty> struct _class_type { static constexpr bool b = false; };
template<typename Ty, typename Ct> struct _class_type<Ty Ct::*> { using t = Ct; static constexpr bool b = true; };
template<typename Ty> using class_type_t = typename _class_type<Ty>::t;
template<typename Ty> inline constexpr bool is_member_pointer_v = _class_type<Ty>::b;
template<typename Ty> inline constexpr bool is_member_function_pointer_v = is_member_pointer_v<Ty> && is_function_v<Ty>;
template<typename Ty> inline constexpr bool is_member_object_pointer_v = is_member_pointer_v<Ty> && !is_member_function_pointer_v<Ty>;

template<typename Ty> struct _add_cv : types<const volatile Ty, const Ty, volatile Ty> {};
template<typename Ty> using add_cv_t = typename _add_cv<Ty>::t1;
template<typename Ty> using add_const_t = typename _add_cv<Ty>::t2;
template<typename Ty> using add_volatile_t = typename _add_cv<Ty>::t3;

template<typename Ty> struct _add_reference : types<Ty, Ty> {};
template<typename Ty> requires requires { typename void_t<Ty&>; } struct _add_reference<Ty> : types<Ty&, Ty&&> {};
template<typename Ty> using add_lvalue_reference_t = typename _add_reference<Ty>::t1;
template<typename Ty> using add_rvalue_reference_t = typename _add_reference<Ty>::t2;
template<typename Ty> using force_rvalue_reference_t = add_rvalue_reference_t<remove_reference_t<Ty>>;
template<typename Ty> using force_const_lvalue_reference_t = add_lvalue_reference_t<const remove_reference_t<Ty>>;
template<typename Ty> using force_const_rvalue_reference_t = add_rvalue_reference_t<const remove_reference_t<Ty>>;

template<typename Ty> struct _add_pointer { using t = Ty; };
template<typename Ty> requires requires { typename void_t<remove_reference_t<Ty>*>; } struct _add_pointer<Ty> { using t = remove_reference_t<Ty>*; };
template<typename Ty> using add_pointer_t = typename _add_pointer<Ty>::t;

template<typename Ty, size_t Nx> struct _add_extent { using t = Ty;};
template<typename Ty, size_t Nx> requires requires { typename void_t<Ty[Nx]>; } struct _add_extent<Ty, Nx> { using t = Ty[Nx]; };
template<typename Ty> requires requires { typename void_t<Ty[]>; } struct _add_extent<Ty, 0> { using t = Ty[]; };
template<typename Ty, size_t Nx> using add_extent_t = typename _add_extent<Ty, Nx>::t;

template<typename Ty, typename Uy> struct _copy_cv : types<Ty, Ty, Ty> {};
template<typename Ty, typename Uy> struct _copy_cv<Ty, const Uy> : types<const Ty, const Ty, Ty> {};
template<typename Ty, typename Uy> struct _copy_cv<Ty, volatile Uy> : types<volatile Ty, Ty, volatile Ty> {};
template<typename Ty, typename Uy> struct _copy_cv<Ty, const volatile Uy> : types<add_cv_t<Ty>, const Ty, volatile Ty> {};
template<typename Ty, typename Uy> using copy_cv_t = typename _copy_cv<Ty, Uy>::t1;
template<typename Ty, typename Uy> using copy_const_t = typename _copy_cv<Ty, Uy>::t2;
template<typename Ty, typename Uy> using copy_volatile_t = typename _copy_cv<Ty, Uy>::t3;

template<typename Ty, typename Uy> struct _copy_ref : types<Ty> {};
template<typename Ty, typename Uy> struct _copy_ref<Ty, Uy&> { using t = add_lvalue_reference_t<Ty>; };
template<typename Ty, typename Uy> struct _copy_ref<Ty, Uy&&> { using t = add_rvalue_reference_t<Ty>; };
template<typename Ty, typename Uy> using copy_reference_t = typename _copy_ref<Ty, Uy>::t;
template<typename Ty, typename Uy> using copy_cvref_t = copy_reference_t<copy_cv_t<Ty, remove_reference_t<Uy>>, Uy>;

template<typename Ty, typename Uy> struct _copy_ptr : types<Ty, Ty> {};
template<typename Ty, typename Uy> using copy_pointer_t = typename _copy_ptr<Ty, Uy>::t1;
template<typename Ty, typename Uy> using copy_all_pointers_t = typename _copy_ptr<Ty, Uy>::t2;
template<typename Ty, typename Uy> struct _copy_ptr<Ty, Uy*> : types<add_pointer_t<Ty>, add_pointer_t<copy_all_pointers_t<Ty, Uy>>> {};
template<typename Ty, typename Uy> struct _copy_ptr<Ty, Uy* const> : types<add_pointer_t<Ty>, const add_pointer_t<copy_all_pointers_t<Ty, Uy>>> {};
template<typename Ty, typename Uy> struct _copy_ptr<Ty, Uy* volatile> : types<add_pointer_t<Ty>, volatile add_pointer_t<copy_all_pointers_t<Ty, Uy>>> {};
template<typename Ty, typename Uy> struct _copy_ptr<Ty, Uy* const volatile> : types<add_pointer_t<Ty>, add_cv_t<add_pointer_t<copy_all_pointers_t<Ty, Uy>>>> {};

template<typename Ty, typename Uy> struct _copy_extent : types<Ty, Ty> {};
template<typename Ty, typename Uy> using copy_extent_t = typename _copy_extent<Ty, Uy>::t1;
template<typename Ty, typename Uy> using copy_all_extents_t = typename _copy_extent<Ty, Uy>::t2;
template<typename Ty, typename Uy> struct _copy_extent<Ty, Uy[]> : types<add_extent_t<Ty, 0>, add_extent_t<copy_all_extents_t<Ty, Uy>, 0>> {};
template<typename Ty, typename Uy, size_t Nx> struct _copy_extent<Ty, Uy[Nx]> : types<add_extent_t<Ty, Nx>, add_extent_t<copy_all_extents_t<Ty, Uy>, Nx>> {};

template<typename Ty, typename Uy = remove_reference_t<Ty>> using decay_t =
  type_switch_t<inspects<is_array_v<Uy>, is_function_v<Uy>>, remove_cv_t<Uy>, remove_extent_t<Uy>*, add_pointer_t<Uy>>;

template<typename Ty> using underlying_type_t = __underlying_type(Ty);

template<typename Ty> add_rvalue_reference_t<Ty> declval() noexcept { static_assert(false); }

template<typename Ty> inline constexpr size_t rank_v = 0;
template<typename Ty> inline constexpr size_t rank_v<Ty[]> = 1 + rank_v<Ty>;
template<typename Ty, size_t Nx> inline constexpr size_t rank_v<Ty[Nx]> = 1 + rank_v<Ty>;

template<typename Ty, size_t Ix = 0> inline constexpr size_t extent_v = extent_v<remove_extent_t<Ty>, Ix - 1>;
template<typename Ty, size_t Nx> inline constexpr size_t extent_v<Ty[Nx], 0> = Nx;
template<typename Ty> inline constexpr size_t extent_v<Ty, 0> = 0;

template<typename T1, typename T2> inline constexpr bool is_same_v = false;
template<typename T1> inline constexpr bool is_same_v<T1, T1> = true;
template<typename T1, typename T2> concept half_same_as = is_same_v<T1, T2>;
template<typename T1, typename T2> concept same_as = half_same_as<T1, T2> && half_same_as<T2, T1>;
template<typename T1, typename T2> concept different_from = !same_as<T1, T2>;
template<typename Ty, typename... Ts> concept included_in = (half_same_as<Ty, Ts> || ...);
template<typename T1, typename T2> inline constexpr bool is_base_of_v = __is_base_of(T1, T2);
template<typename T1, typename T2> inline constexpr bool is_convertible_v = __is_convertible_to(T1, T2);
template<typename T1, typename T2> inline constexpr bool is_nothrow_convertible_v = noexcept(declval<int (&)(T2) noexcept>()(declval<T1>()));
template<typename T1, typename T2> concept derived_from = is_base_of_v<T2, T1> && is_convertible_v<const volatile T1*, const volatile T2*>;
template<typename T1, typename T2> concept expl_convertible_to = requires(T1 (&f)()) { static_cast<T2>(f()); };
template<typename T1, typename T2> concept convertible_to = is_convertible_v<T1, T2> && expl_convertible_to<T1, T2>;
template<typename T1, typename T2> concept convertible_from = convertible_to<T2, T1>;
template<typename T1, typename T2> concept nt_convertible_to = convertible_to<T1, T2> && is_nothrow_convertible_v<T1, T2>;
template<typename Ty> concept boolean_testable = convertible_to<Ty, bool> && requires { { !declval<Ty>() } -> convertible_to<bool>; };
template<typename Ty> concept nt_boolean_testable = boolean_testable<Ty> && nt_convertible_to<Ty, bool> && requires { { !declval<Ty>() } -> nt_convertible_to<bool>; };
template<typename T1, typename T2> concept half_weakly_equality_comparable_with = requires(const remove_reference_t<T1>& x, const remove_reference_t<T2>& y) { { x == y } -> boolean_testable; { x != y } -> boolean_testable; };
template<typename T1, typename T2> concept half_partially_ordered_with = requires(const remove_reference_t<T1>& x, const remove_reference_t<T2>& y) { { x < y } -> boolean_testable; { x <= y } -> boolean_testable; { x > y } -> boolean_testable; { x >= y } -> boolean_testable; };
template<typename T1, typename T2> concept weakly_equality_comparable_with = half_weakly_equality_comparable_with<T1, T2> && half_weakly_equality_comparable_with<T2, T1>;
template<typename T1, typename T2> concept partially_ordered_with = half_partially_ordered_with<T1, T2> && half_partially_ordered_with<T2, T1>;
template<typename Ty> concept equality_comparable = half_weakly_equality_comparable_with<Ty, Ty>;
template<typename Ty> concept totally_ordered = equality_comparable<Ty> && half_partially_ordered_with<Ty, Ty>;

template<typename Ty> inline constexpr bool is_enum_v = __is_enum(Ty);
template<typename Ty> inline constexpr bool is_scoped_enum_v = is_enum_v<Ty> && is_convertible_v<Ty, bool>;
template<typename Ty> inline constexpr bool is_class_v = __is_class(Ty);
template<typename Ty> inline constexpr bool is_union_v = __is_union(Ty);
template<typename Ty> inline constexpr bool is_null_pointer_v = is_same_v<remove_cv_t<Ty>, void>;
template<typename Ty> inline constexpr bool is_void_v = is_same_v<remove_cv_t<Ty>, void>;
template<typename Ty> inline constexpr bool is_bool_v = is_same_v<remove_cv_t<Ty>, bool>;
template<typename Ty> concept is_cat = included_in<remove_cv_t<Ty>, char, wchar_t>;
template<typename Ty> concept is_uct = included_in<remove_cv_t<Ty>, char8_t, char16_t, char32_t>;
template<typename Ty> concept is_int = included_in<remove_cv_t<Ty>, signed char, short, int, long, long long>;
template<typename Ty> concept is_nat = included_in<remove_cv_t<Ty>, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long>;
template<typename Ty> inline constexpr bool is_integral_v = is_bool_v<Ty> || is_cat<Ty> || is_uct<Ty> || is_int<Ty> || is_nat<Ty>;
template<typename Ty> inline constexpr bool is_floating_point_v = included_in<remove_cv_t<Ty>, float, double, long double>;
template<typename Ty> inline constexpr bool is_arithmetic_v = is_integral_v<Ty> || is_floating_point_v<Ty>;
template<typename Ty> inline constexpr bool is_signed_v = is_arithmetic_v<Ty> && requires { requires static_cast<Ty>(-1) < static_cast<Ty>(0); };
template<typename Ty> inline constexpr bool is_unsigned_v = is_integral_v<Ty> && !is_signed_v<Ty>;
template<typename Ty> inline constexpr bool is_fundamental_v = is_null_pointer_v<Ty> || is_void_v<Ty> || is_arithmetic_v<Ty>;
template<typename Ty> inline constexpr bool is_scalar_v = is_arithmetic_v<Ty> || is_enum_v<Ty> || is_pointer_v<Ty> || is_null_pointer_v<Ty>;
template<typename Ty> inline constexpr bool is_object_v = is_scalar_v<Ty> || is_array_v<Ty> || is_class_v<Ty> || is_union_v<Ty>;
template<typename Ty> inline constexpr bool is_compound_v = !is_fundamental_v<Ty>;
template<typename Ty> concept integral = is_integral_v<Ty>;
template<typename Ty> concept signed_integral = integral<Ty> && is_signed_v<Ty>;
template<typename Ty> concept unsigned_integral = integral<Ty> && !signed_integral<Ty>;
template<typename Ty> concept floating_point = is_floating_point_v<Ty>;
template<typename Ty> concept arithmetic = integral<Ty> || floating_point<Ty>;

template<typename Ty> inline constexpr bool is_destructible_v = __is_destructible(Ty);
template<typename Ty> inline constexpr bool is_nothrow_destructible_v = __is_nothrow_destructible(Ty);
template<typename Ty> inline constexpr bool is_trivially_destructible_v = __is_trivially_destructible(Ty);
template<typename Ty> concept destructible = is_nothrow_destructible_v<Ty>;

template<typename Ty, typename... As> inline constexpr bool is_constructible_v = __is_constructible(Ty, As...);
template<typename Ty, typename... As> inline constexpr bool is_nothrow_constructible_v = __is_nothrow_constructible(Ty, As...);
template<typename Ty, typename... As> inline constexpr bool is_trivially_constructible_v = __is_trivially_constructible(Ty, As...);
template<typename Ty, typename... As> concept constructible_from = destructible<Ty> && is_constructible_v<Ty, As...>;
template<typename Ty> concept default_initializable = constructible_from<Ty> && requires { Ty{}; };
template<typename Ty> concept move_constructible = constructible_from<Ty, Ty> && convertible_to<Ty, Ty>;
template<typename Ty> concept copy_constructible = move_constructible<Ty> && constructible_from<Ty, Ty&> && constructible_from<Ty, const Ty> &&
  constructible_from<Ty, const Ty&> && convertible_to<Ty&, Ty> && convertible_to<const Ty, Ty> && convertible_to<const Ty&, Ty>;

template<typename Ty> inline constexpr bool is_default_constructible_v = is_constructible_v<Ty>;
template<typename Ty> inline constexpr bool is_nothrow_default_constructible_v = is_nothrow_constructible_v<Ty>;
template<typename Ty> inline constexpr bool is_trivially_default_constructible_v = is_trivially_constructible_v<Ty>;
template<typename Ty> inline constexpr bool is_implicitly_default_constructible_v = requires(int (&f)(Ty)) { f({}); };
template<typename Ty> inline constexpr bool is_move_constructible_v = is_constructible_v<Ty, Ty>;
template<typename Ty> inline constexpr bool is_nothrow_move_constructible_v = is_nothrow_constructible_v<Ty, Ty>;
template<typename Ty> inline constexpr bool is_trivially_move_constructible_v = is_trivially_constructible_v<Ty, Ty>;
template<typename Ty> inline constexpr bool is_copy_constructible_v = is_constructible_v<Ty, const remove_reference_t<Ty>&>;
template<typename Ty> inline constexpr bool is_nothrow_copy_constructible_v = is_nothrow_constructible_v<Ty, const remove_reference_t<Ty>&>;
template<typename Ty> inline constexpr bool is_trivially_copy_constructible_v = is_trivially_constructible_v<Ty, const remove_reference_t<Ty>&>;

template<typename Ty, typename At> inline constexpr bool is_assignable_v = __is_assignable(Ty, At);
template<typename Ty, typename At> inline constexpr bool is_nothrow_assignable_v = __is_nothrow_assignable(Ty, At);
template<typename Ty, typename At> inline constexpr bool is_trivially_assignable_v = __is_trivially_assignable(Ty, At);
template<typename Ty> inline constexpr bool is_move_assignable_v = is_assignable_v<Ty&, Ty>;
template<typename Ty> inline constexpr bool is_nothrow_move_assignable_v = is_nothrow_assignable_v<Ty&, Ty>;
template<typename Ty> inline constexpr bool is_trivially_move_assignable_v = is_trivially_assignable_v<Ty&, Ty>;
template<typename Ty> inline constexpr bool is_copy_assignable_v = is_assignable_v<Ty&, const remove_reference_t<Ty>&>;
template<typename Ty> inline constexpr bool is_nothrow_copy_assignable_v = is_nothrow_assignable_v<Ty&, const remove_reference_t<Ty>&>;
template<typename Ty> inline constexpr bool is_trivially_copy_assignable_v = is_trivially_assignable_v<Ty&, const remove_reference_t<Ty>&>;

template<typename Ty> inline constexpr bool has_unique_object_representations_v = __has_unique_object_representations(Ty);
template<typename Ty> inline constexpr bool has_virtual_destructor_v = __has_virtual_destructor(Ty);
template<typename Ty> inline constexpr bool is_standard_layout_v = __is_standard_layout(Ty);
template<typename Ty> inline constexpr bool is_trivially_copyable_v = __is_trivially_copyable(Ty);
template<typename Ty> inline constexpr bool is_trivial_v = is_trivially_copyable_v<Ty> && is_trivially_default_constructible_v<Ty>;
template<typename Ty> inline constexpr bool is_abstract_v = __is_abstract(Ty);
template<typename Ty> inline constexpr bool is_aggregate_v = __is_aggregate(Ty);
template<typename Ty> inline constexpr bool is_empty_v = __is_empty(Ty);
template<typename Ty> inline constexpr bool is_final_v = __is_final(Ty);
template<typename Ty> inline constexpr bool is_polymorphic_v = __is_polymorphic(Ty);

template<bool Bx, typename Ty> struct _make_signed {};
template<bool Bx, typename Ty> requires is_enum_v<Ty> struct _make_signed<Bx, Ty> : _make_signed<Bx, underlying_type_t<Ty>> {};
template<bool Bx> struct _make_signed<Bx, char> : conditional<Bx, signed char, unsigned char> {};
template<bool Bx> struct _make_signed<Bx, wchar_t> : conditional<Bx, short, unsigned short> {};
template<bool Bx> struct _make_signed<Bx, char8_t> : conditional<Bx, signed char, unsigned char> {};
template<bool Bx> struct _make_signed<Bx, char16_t> : conditional<Bx, short, unsigned short> {};
template<bool Bx> struct _make_signed<Bx, char32_t> : conditional<Bx, int, unsigned int> {};
template<bool Bx> struct _make_signed<Bx, signed char> : conditional<Bx, signed char, unsigned char> {};
template<bool Bx> struct _make_signed<Bx, short> : conditional<Bx, short, unsigned short> {};
template<bool Bx> struct _make_signed<Bx, int> : conditional<Bx, int, unsigned int> {};
template<bool Bx> struct _make_signed<Bx, long> : conditional<Bx, long, unsigned long> {};
template<bool Bx> struct _make_signed<Bx, long long> : conditional<Bx, long, unsigned long> {};
template<bool Bx> struct _make_signed<Bx, unsigned char> : conditional<Bx, signed char, unsigned char> {};
template<bool Bx> struct _make_signed<Bx, unsigned short> : conditional<Bx, short, unsigned short> {};
template<bool Bx> struct _make_signed<Bx, unsigned int> : conditional<Bx, int, unsigned int> {};
template<bool Bx> struct _make_signed<Bx, unsigned long> : conditional<Bx, long, unsigned long> {};
template<bool Bx> struct _make_signed<Bx, unsigned long long> : conditional<Bx, long, unsigned long> {};

template<typename Ty> using make_signed_t = copy_cv_t<typename _make_signed<true, remove_cv_t<Ty>>::type, Ty>;
template<typename Ty> using make_unsigned_t = copy_cv_t<typename _make_signed<false, remove_cv_t<Ty>>::type, Ty>;

template<typename Ty> constexpr void swap(Ty& x, Ty& y)
  noexcept(is_nothrow_move_constructible_v<Ty> && is_nothrow_move_assignable_v<Ty>)
  requires is_move_constructible_v<Ty> && is_move_assignable_v<Ty> {
  Ty t = static_cast<Ty&&>(x); x = static_cast<Ty&&>(y); y = static_cast<Ty&&>(t);
}

template<typename Ty> inline constexpr bool is_swappable_v = requires { swap(declval<Ty&>(), declval<Ty&>()); };
template<typename Ty> inline constexpr bool is_nothrow_swappable_v = noexcept(noexcept(swap(declval<Ty&>(), declval<Ty&>())));
template<typename T1, typename T2> inline constexpr bool is_swappable_with_v = requires { swap(declval<T1&>(), declval<T2&>()); };
template<typename T1, typename T2> inline constexpr bool is_nothrow_swappable_with_v = noexcept(noexcept(swap(declval<T1&>(), declval<T2&>())));

template<typename Ty, size_t Nx> constexpr void swap(Ty (&x)[Nx], Ty (&y)[Nx])
  noexcept(is_nothrow_swappable_v<Ty>) requires is_swappable_v<Ty> {
  for (size_t i = 0; i < Nx; ++i) swap(x[i], y[i]);
}

template<typename Ty> constexpr Ty* addressof(Ty& x) noexcept { return __builtin_addressof(x); }
template<typename Ty> const Ty* addressof(const Ty&&) = delete;
template<typename Ty> constexpr Ty bit_cast(const auto& x) noexcept { return __builtin_bit_cast(Ty, x); }
template<typename Ty> constexpr Ty bit_mask(size_t b, size_t e) noexcept { return static_cast<Ty>((e < bit_size<Ty> ? (Ty{1} << e) - 1 : Ty{-1}) ^ ((Ty{1} << b) - 1)); }
template<typename Ty> constexpr Ty&& forward(remove_reference_t<Ty>& x) noexcept { return static_cast<Ty&&>(x); }
template<typename Ty> constexpr Ty&& forward(remove_reference_t<Ty>&& x) noexcept requires(!is_lvalue_reference_v<Ty>) { return static_cast<Ty&&>(x); }
template<typename Ty> constexpr remove_reference_t<Ty>&& move(Ty&& x) noexcept { return static_cast<remove_reference_t<Ty>&&>(x); }
template<typename Ty> constexpr decay_t<Ty> decay_copy(Ty&& x) noexcept(is_nothrow_convertible_v<Ty, decay_t<Ty>>) { return static_cast<Ty&&>(x); }

template<typename Ty, template<typename...> typename Tm> inline constexpr bool _specialized_of = false;
template<template<typename...> typename Tm, typename... Ts> inline constexpr bool _specialized_of<Tm<Ts...>, Tm> = true;
template<typename Ty, template<typename...> typename Tm> concept specialized_of = _specialized_of<Ty, Tm>;

template<typename Ty> concept has_arrow_operator = requires(Ty& t) { t.operator->(); };
template<typename Ty> concept has_const_pointer = requires { typename Ty::const_pointer; };
template<typename Ty> concept has_const_void_pointer = requires { typename Ty::const_void_pointer; };
template<typename Ty> concept has_difference_type = requires { typename Ty::difference_type; };
template<typename Ty> concept has_element_type = requires { typename Ty::element_type; };
template<typename Ty> concept has_is_always_equal = requires { Ty::is_always_equal; };
template<typename Ty> concept has_iterator_category = requires { typename Ty::iterator_category; };
template<typename Ty> concept has_pointer = requires { typename Ty::pointer; };
template<typename Ty> concept has_reference = requires { typename Ty::reference; };
template<typename Ty> concept has_size_type = requires { typename Ty::size_type; };
template<typename Ty> concept has_value_type = requires { typename Ty::value_type; };
template<typename Ty> concept has_void_pointer = requires { typename Ty::void_pointer; };
template<typename Ty> concept has_iter_types = has_difference_type<Ty> && has_value_type<Ty> && has_reference<Ty> && has_iterator_category<Ty>;
template<typename Ty, typename Uy> concept has_rebind = requires { typename Ty::template rebind<Uy>; };
template<typename Ty, typename Uy> concept has_rebind_other = requires { typename Ty::template rebind<Uy>::other; };

template<typename Ty> concept can_reference = requires { typename void_t<Ty&>; };
template<typename Ty> concept dereferenceable = requires(Ty t) { { *t } -> can_reference; };


struct identity { template<typename Ty> constexpr Ty&& operator()(Ty&& x) const noexcept { return static_cast<Ty&&>(x); } };
inline constexpr auto _less = [](const auto x, const auto y) -> bool { return x < y; };

template<typename Ty, Ty... Vs> struct sequence {
  using type = sequence;
  using value_type = Ty;
  static constexpr size_t size = sizeof...(Vs);
};

template<typename Ty, size_t End, size_t Begin, auto Fn, Ty... Vs> struct _make_sequence
  : _make_sequence<Ty, End, Begin + 1, Fn, Vs..., Fn(Begin)> {};
template<typename Ty, size_t End, auto Fn, Ty... Vs> struct _make_sequence<Ty, End, End, Fn, Vs...> : sequence<Ty, Vs...> {};
template<size_t End, size_t Begin = 0, auto Fn = identity{}> using make_sequence =
  typename _make_sequence<decay_t<decltype(Fn(Begin))>, End, Begin, Fn>::type;

template<typename Container> struct node_handler;
template<typename Iter, typename NodeType> struct insert_return_type {
  Iter position;
  bool inserted;
  NodeType node;
};

template<typename Ty> inline constexpr bool _execution_policy = false;
template<typename Ty> concept execution_policy = _execution_policy<Ty>;

}
