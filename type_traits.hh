#pragma once

#ifdef __ywstd__
#include <type_traits>
#else

namespace std {

using size_t = decltype(sizeof(int));
using nullptr_t = decltype(nullptr);

/// @brief compile-time constant of specified type with specified value
template<typename Ty, Ty Vx> struct integral_constant {
  static constexpr Ty value = Vx;
  using value_type = Ty;
  using type = integral_constant<Ty, Vx>;
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};
template<bool Bx> using bool_constant = integral_constant<bool, Bx>;
using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

/// @brief void variadic alias template
template<typename... Ts> using void_t = void;

/// @brief returns the type argument unchanged
template<typename Ty> struct type_identity {
  using type = Ty;
};
template<typename Ty> using type_identity_t = typename type_identity<Ty>::type;

/// @brief conditionally removes a function overload or template specialization from overload resolution
template<bool Bx, typename Ty = void> struct enable_if : type_identity<Ty> {};
template<typename Ty> struct enable_if<false, Ty> {};
template<bool Bx, typename Ty = void> using enable_if_t = typename enable_if<Bx, Ty>::type;

/// @brief chooses one type or another based on compile-time boolean
template<bool Bx, typename Ty, typename Uy> struct conditional : type_identity<Uy> {};
template<typename Ty, typename Uy> struct conditional<true, Ty, Uy> : type_identity<Ty> {};
template<bool Bx, typename Ty, typename Uy> using conditional_t = typename conditional<Bx, Ty, Uy>::type;

/// @brief removes const specifier from the given type
template<typename Ty> struct remove_const : type_identity<Ty> {};
template<typename Ty> struct remove_const<const Ty> : type_identity<Ty> {};
template<typename Ty> using remove_const_t = typename remove_const<Ty>::type;

/// @brief removes volatile specifier from the given type
template<typename Ty> struct remove_volatile : type_identity<Ty> {};
template<typename Ty> struct remove_volatile<volatile Ty> : type_identity<Ty> {};
template<typename Ty> using remove_volatile_t = typename remove_volatile<Ty>::type;

/// @brief removes const and/or volatile specifiers from the given type
template<typename Ty> struct remove_cv : type_identity<Ty> {};
template<typename Ty> struct remove_cv<const Ty> : type_identity<Ty> {};
template<typename Ty> struct remove_cv<volatile Ty> : type_identity<Ty> {};
template<typename Ty> struct remove_cv<const volatile Ty> : type_identity<Ty> {};
template<typename Ty> using remove_cv_t = typename remove_cv<Ty>::type;

/// @brief removes a reference from the given type
template<typename Ty> struct remove_reference : type_identity<Ty> {};
template<typename Ty> struct remove_reference<Ty&> : type_identity<Ty> {};
template<typename Ty> struct remove_reference<Ty&&> : type_identity<Ty> {};
template<typename Ty> using remove_reference_t = typename remove_reference<Ty>::type;

/// @brief combines std::remove_cv and std::remove_reference
template<typename Ty> struct remove_cvref : remove_cv<remove_reference_t<Ty>> {};
template<typename Ty> using remove_cvref_t = typename remove_cvref<Ty>::type;

/// @brief removes a pointer from the given type
template<typename Ty> struct remove_pointer : type_identity<Ty> {};
template<typename Ty> struct remove_pointer<Ty*> : type_identity<Ty> {};
template<typename Ty> struct remove_pointer<Ty* const> : type_identity<Ty> {};
template<typename Ty> struct remove_pointer<Ty* volatile> : type_identity<Ty> {};
template<typename Ty> struct remove_pointer<Ty* const volatile> : type_identity<Ty> {};
template<typename Ty> using remove_pointer_t = typename remove_pointer<Ty>::type;

/// @brief removes one extent from the given array type
template<typename Ty> struct remove_extent : type_identity<Ty> {};
template<typename Ty> struct remove_extent<Ty[]> : type_identity<Ty> {};
template<typename Ty, size_t Nx> struct remove_extent<Ty[Nx]> : type_identity<Ty> {};
template<typename Ty> using remove_extent_t = typename remove_extent<Ty>::type;

/// @brief removes all extents from the given array type
template<typename Ty> struct remove_all_extents : type_identity<Ty> {};
template<typename Ty> struct remove_all_extents<Ty[]> : remove_all_extents<Ty> {};
template<typename Ty, size_t Nx> struct remove_all_extents<Ty[Nx]> : remove_all_extents<Ty> {};
template<typename Ty> using remove_all_extents_t = typename remove_all_extents<Ty>::type;

/// @brief adds const specifier to the given type
template<typename Ty> struct add_const : type_identity<const Ty> {};
template<typename Ty> using add_const_t = typename add_const<Ty>::type;

/// @brief adds volatile specifier to the given type
template<typename Ty> struct add_volatile : type_identity<volatile Ty> {};
template<typename Ty> using add_volatile_t = typename add_volatile<Ty>::type;

/// @brief adds const and/or volatile specifiers to the given type
template<typename Ty> struct add_cv : type_identity<const volatile Ty> {};
template<typename Ty> using add_cv_t = typename add_cv<Ty>::type;

/// @brief adds an lvalue reference to the given type
template<typename Ty> struct add_lvalue_reference : type_identity<Ty> {};
template<typename Ty> requires requires { typename void_t<Ty&>; }
struct add_lvalue_reference<Ty> : type_identity<Ty&> {};
template<typename Ty> using add_lvalue_reference_t = typename add_lvalue_reference<Ty>::type;

/// @brief adds an rvalue reference to the given type
template<typename Ty> struct add_rvalue_reference : type_identity<Ty> {};
template<typename Ty> requires requires { typename void_t<Ty&&>; }
struct add_rvalue_reference<Ty> : type_identity<Ty&&> {};
template<typename Ty> using add_rvalue_reference_t = typename add_rvalue_reference<Ty>::type;

/// @brief adds a pointer to the given type
template<typename Ty> struct add_pointer : type_identity<Ty> {};
template<typename Ty> requires requires { typename void_t<remove_reference_t<Ty>*>; }
struct add_pointer<Ty> : type_identity<remove_reference_t<Ty>*> {};
template<typename Ty> using add_pointer_t = typename add_pointer<Ty>::type;

/// @brief obtains the type's alignment requirements
template<typename Ty> struct alignment_of : integral_constant<size_t, alignof(Ty)> {};
template<typename Ty> inline constexpr size_t alignment_of_v = alignment_of<Ty>::value;

/// @brief obtains the number of dimensions of an array type
template<typename Ty> struct rank : integral_constant<size_t, 0> {};
template<typename Ty> inline constexpr size_t rank_v = rank<Ty>::value;
template<typename Ty> struct rank<Ty[]> : integral_constant<size_t, 1 + rank_v<Ty>> {};
template<typename Ty, size_t Nx> struct rank<Ty[Nx]> : integral_constant<size_t, 1 + rank_v<Ty>> {};

/// @brief obtains the size of an array type along a specified dimension
template<typename Ty, unsigned Ix = 0> struct extent : integral_constant<size_t, 0> {};
template<typename Ty, unsigned Ix = 0> inline constexpr size_t extent_v = extent<Ty, Ix>::value;
template<typename Ty, unsigned Ix, size_t Nx> struct extent<Ty[Nx], Ix> : extent<Ty, Ix - 1> {};
template<typename Ty, unsigned Ix> struct extent<Ty[], Ix> : extent<Ty, Ix - 1> {};
template<typename Ty> struct extent<Ty[], 0> : integral_constant<size_t, 0> {};

/// @brief variadic logical AND metafunction
template<typename... Bx> struct conjunction : bool_constant<(Bx::value && ...)> {};
template<typename... Bx> inline constexpr bool conjunction_v = conjunction<Bx...>::value;

/// @brief variadic logical OR metafunction
template<typename... Bx> struct disjunction : bool_constant<(Bx::value || ...)> {};
template<typename... Bx> inline constexpr bool disjunction_v = disjunction<Bx...>::value;

/// @brief logical NOT metafunction
template<typename Bx> struct negation : bool_constant<!Bx::value> {};
template<typename Bx> inline constexpr bool negation_v = negation<Bx>::value;

/// @brief checks if two types are the same
template<typename Ty, typename Uy> struct is_same : false_type {};
template<typename Ty> struct is_same<Ty, Ty> : true_type {};
template<typename Ty, typename Uy> inline constexpr bool is_same_v = is_same<Ty, Uy>::value;

/// @brief checks if a type is void
template<typename Ty> struct is_void : is_same<remove_cv_t<Ty>, void> {};
template<typename Ty> inline constexpr bool is_void_v = is_void<Ty>::value;

/// @brief 	checks if a type is std::nullptr_t
template<typename Ty> struct is_null_pointer : is_same<remove_cv_t<Ty>, nullptr_t> {};
template<typename Ty> inline constexpr bool is_null_pointer_v = is_null_pointer<Ty>::value;

/// @brief checks if a type is const-qualified
template<typename Ty> struct is_const : false_type {};
template<typename Ty> struct is_const<const Ty> : true_type {};
template<typename Ty> inline constexpr bool is_const_v = is_const<Ty>::value;

/// @brief checks if a type is volatile-qualified
template<typename Ty> struct is_volatile : false_type {};
template<typename Ty> struct is_volatile<volatile Ty> : true_type {};
template<typename Ty> inline constexpr bool is_volatile_v = is_volatile<Ty>::value;

/// @brief checks if a type is an lvalue reference
template<typename Ty> struct is_lvalue_reference : false_type {};
template<typename Ty> struct is_lvalue_reference<Ty&> : true_type {};
template<typename Ty> inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<Ty>::value;

/// @brief checks if a type is an rvalue reference
template<typename Ty> struct is_rvalue_reference : false_type {};
template<typename Ty> struct is_rvalue_reference<Ty&&> : true_type {};
template<typename Ty> inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<Ty>::value;

/// @brief checks if a type is either an lvalue reference or rvalue reference
template<typename Ty> struct is_reference : disjunction<is_lvalue_reference<Ty>, is_rvalue_reference<Ty>> {};
template<typename Ty> inline constexpr bool is_reference_v = is_reference<Ty>::value;

/// @brief checks if a type is a pointer type
template<typename Ty> struct is_pointer : false_type {};
template<typename Ty> struct is_pointer<Ty*> : true_type {};
template<typename Ty> struct is_pointer<Ty* const> : true_type {};
template<typename Ty> struct is_pointer<Ty* volatile> : true_type {};
template<typename Ty> struct is_pointer<Ty* const volatile> : true_type {};
template<typename Ty> inline constexpr bool is_pointer_v = is_pointer<Ty>::value;

/// @brief checks if a type is an array type of known bound
template<typename Ty> struct is_bounded_array : false_type {};
template<typename Ty, size_t Nx> struct is_bounded_array<Ty[Nx]> : true_type {};
template<typename Ty> inline constexpr bool is_bounded_array_v = is_bounded_array<Ty>::value;

/// @brief checks if a type is an array type of unknown bound
template<typename Ty> struct is_unbounded_array : false_type {};
template<typename Ty> struct is_unbounded_array<Ty[]> : true_type {};
template<typename Ty> inline constexpr bool is_unbounded_array_v = is_unbounded_array<Ty>::value;

/// @brief checks if a type is an array type
template<typename Ty> struct is_array : disjunction<is_bounded_array<Ty>, is_unbounded_array<Ty>> {};
template<typename Ty> inline constexpr bool is_array_v = is_array<Ty>::value;

/// @brief checks if a type is a function type
template<typename Ty> struct is_function : bool_constant<!is_const_v<Ty> && !is_reference_v<Ty>> {};
template<typename Ty> inline constexpr bool is_function_v = is_function<Ty>::value;

template<typename Ty> struct is_member_pointer : false_type {};
template<typename Ty, typename Uy> struct is_member_pointer<Ty Uy::*> : true_type {};

namespace _ {
template<typename Ty, typename Uy> struct _is_member_pointer : false_type {};
template<typename Ty, typename Uy> struct _is_member_pointer<Ty Uy::*> : false_type {};
template<typename Ty, typename... Ts> struct _is_included : disjunction<is_same<Ty, Ts>...> {};
template<typename Ty, typename Uy> concept _is_nothrow_convertible =
    requires(void (&f)(Uy) noexcept, Ty&& x) { static_cast<Uy(*)()>(nullptr); { f(static_cast<Ty&&>(x)) } noexcept; };
}

/// @brief checks if a type is derived from the other type
template<typename Ty, typename Uy> struct is_base_of : bool_constant<__is_base_of(Ty, Uy)> {};
template<typename Ty, typename Uy> inline constexpr bool is_base_of_v = is_base_of<Ty, Uy>::value;

/// @brief checks if a type can be converted to the other type
template<typename Ty, typename Uy> struct is_convertible : bool_constant<__is_convertible(Ty, Uy)> {};
template<typename Ty, typename Uy> inline constexpr bool is_convertible_v = is_convertible<Ty, Uy>::value;

/// @brief checks if a type can be converted to the other type
template<typename Ty, typename Uy> struct is_nothrow_convertible : conjunction<is_void<Ty>, is_void<Uy>> {};
template<typename Uy, _::_is_nothrow_convertible<Uy> Ty> struct is_nothrow_convertible<Ty, Uy> : true_type {};
template<typename Ty, typename Uy> inline constexpr bool is_nothrow_convertible_v = is_nothrow_convertible<Ty, Uy>::value;

/// @brief checks if a type is an integral type
template<typename Ty> struct is_integral
    : _::_is_included<remove_cv_t<Ty>, bool, char, wchar_t, char8_t, char16_t, char32_t, signed char, short, int,
                      long, long long, unsigned char, unsigned short, unsigned, unsigned long, unsigned long long> {};
template<typename Ty> inline constexpr bool is_integral_v = is_integral<Ty>::value;

/// @brief checks if a type is a floating-point type
template<typename Ty> struct is_floating_point : _::_is_included<remove_cv_t<Ty>, float, double, long double> {};
template<typename Ty> inline constexpr bool is_floating_point_v = is_floating_point<Ty>::value;


template<typename Ty> struct is_member_object_pointer;
template<typename Ty> struct is_member_function_pointer;
template<typename Ty> struct is_enum;
template<typename Ty> struct is_union;
template<typename Ty> struct is_class;

// composite type categories
template<typename Ty> struct is_arithmetic;
template<typename Ty> struct is_fundamental;
template<typename Ty> struct is_object;
template<typename Ty> struct is_scalar;
template<typename Ty> struct is_compound;

// type properties
template<typename Ty> struct is_trivial;
template<typename Ty> struct is_trivially_copyable;
template<typename Ty> struct is_standard_layout;
template<typename Ty> struct is_empty;
template<typename Ty> struct is_polymorphic;
template<typename Ty> struct is_abstract;
template<typename Ty> struct is_final;
template<typename Ty> struct is_aggregate;

template<typename Ty> struct is_signed;
template<typename Ty> struct is_unsigned;
template<typename Ty> struct is_scoped_enum;

template<typename Ty, typename... Args> struct is_constructible;
template<typename Ty> struct is_default_constructible;
template<typename Ty> struct is_copy_constructible;
template<typename Ty> struct is_move_constructible;

template<typename Ty, typename Uy> struct is_assignable;
template<typename Ty> struct is_copy_assignable;
template<typename Ty> struct is_move_assignable;

template<typename Ty, typename Uy> struct is_swappable_with;
template<typename Ty> struct is_swappable;

template<typename Ty> struct is_destructible;

template<typename Ty, typename... Args> struct is_trivially_constructible;
template<typename Ty> struct is_trivially_default_constructible;
template<typename Ty> struct is_trivially_copy_constructible;
template<typename Ty> struct is_trivially_move_constructible;

template<typename Ty, typename Uy> struct is_trivially_assignable;
template<typename Ty> struct is_trivially_copy_assignable;
template<typename Ty> struct is_trivially_move_assignable;
template<typename Ty> struct is_trivially_destructible;

template<typename Ty, typename... Args> struct is_nothrow_constructible;
template<typename Ty> struct is_nothrow_default_constructible;
template<typename Ty> struct is_nothrow_copy_constructible;
template<typename Ty> struct is_nothrow_move_constructible;

template<typename Ty, typename Uy> struct is_nothrow_assignable;
template<typename Ty> struct is_nothrow_copy_assignable;
template<typename Ty> struct is_nothrow_move_assignable;

template<typename Ty, typename Uy> struct is_nothrow_swappable_with;
template<typename Ty> struct is_nothrow_swappable;

template<typename Ty> struct is_nothrow_destructible;

template<typename Ty> struct has_virtual_destructor;

template<typename Ty> struct has_unique_object_representations;

template<typename Ty, typename Uy> struct reference_constructs_from_temporary;
template<typename Ty, typename Uy> struct reference_converts_from_temporary;

// type relations
template<typename Ty, typename Uy> struct is_layout_compatible;
template<typename Ty, typename Uy> struct is_pointer_interconvertible_base_of;

template<typename Fn, typename... ArgTypes> struct is_invocable;
template<typename R, typename Fn, typename... ArgTypes> struct is_invocable_r;

template<typename Fn, typename... ArgTypes> struct is_nothrow_invocable;
template<typename R, typename Fn, typename... ArgTypes> struct is_nothrow_invocable_r;

// sign modifications
template<typename Ty> struct make_signed;
template<typename Ty> struct make_unsigned;

template<typename Ty>
using make_signed_t = typename make_signed<Ty>::type;
template<typename Ty>
using make_unsigned_t = typename make_unsigned<Ty>::type;

// array modifications

// other transformations
template<typename Ty> struct decay;
template<typename... Ty> struct common_type;
template<typename Ty, typename U, template<typename> class TQual, template<typename> class UQual>
struct basic_common_reference {};
template<typename... Ty> struct common_reference;
template<typename Ty> struct underlying_type;
template<typename Fn, typename... ArgTypes> struct invoke_result;
template<typename Ty> struct unwrap_reference;
template<typename Ty> struct unwrap_ref_decay;

template<typename Ty> using decay_t = typename decay<Ty>::type;
template<typename... Ty>
using common_type_t = typename common_type<Ty...>::type;
template<typename... Ty>
using common_reference_t = typename common_reference<Ty...>::type;
template<typename Ty>
using underlying_type_t = typename underlying_type<Ty>::type;
template<typename Fn, typename... ArgTypes>
using invoke_result_t = typename invoke_result<Fn, ArgTypes...>::type;
template<typename Ty>
using unwrap_reference_t = typename unwrap_reference<Ty>::type;
template<typename Ty>
using unwrap_ref_decay_t = typename unwrap_ref_decay<Ty>::type;

// primary type categories
template<typename Ty> inline constexpr bool is_member_object_pointer_v = is_member_object_pointer<Ty>::value;
template<typename Ty> inline constexpr bool is_member_function_pointer_v = is_member_function_pointer<Ty>::value;
template<typename Ty> inline constexpr bool is_enum_v = is_enum<Ty>::value;
template<typename Ty> inline constexpr bool is_union_v = is_union<Ty>::value;
template<typename Ty> inline constexpr bool is_class_v = is_class<Ty>::value;


// composite type categories
template<typename Ty>
inline constexpr bool is_arithmetic_v = is_arithmetic<Ty>::value;
template<typename Ty>
inline constexpr bool is_fundamental_v = is_fundamental<Ty>::value;
template<typename Ty>
inline constexpr bool is_object_v = is_object<Ty>::value;
template<typename Ty>
inline constexpr bool is_scalar_v = is_scalar<Ty>::value;
template<typename Ty>
inline constexpr bool is_compound_v = is_compound<Ty>::value;
template<typename Ty>
inline constexpr bool is_member_pointer_v = is_member_pointer<Ty>::value;

// type properties
template<typename Ty>
inline constexpr bool is_trivial_v = is_trivial<Ty>::value;
template<typename Ty>
inline constexpr bool is_trivially_copyable_v = is_trivially_copyable<Ty>::value;
template<typename Ty>
inline constexpr bool is_standard_layout_v = is_standard_layout<Ty>::value;
template<typename Ty>
inline constexpr bool is_empty_v = is_empty<Ty>::value;
template<typename Ty>
inline constexpr bool is_polymorphic_v = is_polymorphic<Ty>::value;
template<typename Ty>
inline constexpr bool is_abstract_v = is_abstract<Ty>::value;
template<typename Ty>
inline constexpr bool is_final_v = is_final<Ty>::value;
template<typename Ty>
inline constexpr bool is_aggregate_v = is_aggregate<Ty>::value;
template<typename Ty>
inline constexpr bool is_signed_v = is_signed<Ty>::value;
template<typename Ty>
inline constexpr bool is_unsigned_v = is_unsigned<Ty>::value;
template<typename Ty>
inline constexpr bool is_scoped_enum_v = is_scoped_enum<Ty>::value;
template<typename Ty, typename... Args>
inline constexpr bool is_constructible_v = is_constructible<Ty, Args...>::value;
template<typename Ty>
inline constexpr bool is_default_constructible_v = is_default_constructible<Ty>::value;
template<typename Ty>
inline constexpr bool is_copy_constructible_v = is_copy_constructible<Ty>::value;
template<typename Ty>
inline constexpr bool is_move_constructible_v = is_move_constructible<Ty>::value;
template<typename Ty, typename Uy>
inline constexpr bool is_assignable_v = is_assignable<Ty, Uy>::value;
template<typename Ty>
inline constexpr bool is_copy_assignable_v = is_copy_assignable<Ty>::value;
template<typename Ty>
inline constexpr bool is_move_assignable_v = is_move_assignable<Ty>::value;
template<typename Ty, typename Uy>
inline constexpr bool is_swappable_with_v = is_swappable_with<Ty, Uy>::value;
template<typename Ty>
inline constexpr bool is_swappable_v = is_swappable<Ty>::value;
template<typename Ty>
inline constexpr bool is_destructible_v = is_destructible<Ty>::value;
template<typename Ty, typename... Args>
inline constexpr bool is_trivially_constructible_v = is_trivially_constructible<Ty, Args...>::value;
template<typename Ty>
inline constexpr bool is_trivially_default_constructible_v = is_trivially_default_constructible<Ty>::value;
template<typename Ty>
inline constexpr bool is_trivially_copy_constructible_v = is_trivially_copy_constructible<Ty>::value;
template<typename Ty>
inline constexpr bool is_trivially_move_constructible_v = is_trivially_move_constructible<Ty>::value;
template<typename Ty, typename Uy>
inline constexpr bool is_trivially_assignable_v = is_trivially_assignable<Ty, Uy>::value;
template<typename Ty>
inline constexpr bool is_trivially_copy_assignable_v = is_trivially_copy_assignable<Ty>::value;
template<typename Ty>
inline constexpr bool is_trivially_move_assignable_v = is_trivially_move_assignable<Ty>::value;
template<typename Ty>
inline constexpr bool is_trivially_destructible_v = is_trivially_destructible<Ty>::value;
template<typename Ty, typename... Args>
inline constexpr bool is_nothrow_constructible_v = is_nothrow_constructible<Ty, Args...>::value;
template<typename Ty>
inline constexpr bool is_nothrow_default_constructible_v = is_nothrow_default_constructible<Ty>::value;
template<typename Ty>
inline constexpr bool is_nothrow_copy_constructible_v = is_nothrow_copy_constructible<Ty>::value;
template<typename Ty>
inline constexpr bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<Ty>::value;
template<typename Ty, typename Uy>
inline constexpr bool is_nothrow_assignable_v = is_nothrow_assignable<Ty, Uy>::value;
template<typename Ty>
inline constexpr bool is_nothrow_copy_assignable_v = is_nothrow_copy_assignable<Ty>::value;
template<typename Ty>
inline constexpr bool is_nothrow_move_assignable_v = is_nothrow_move_assignable<Ty>::value;
template<typename Ty, typename Uy>
inline constexpr bool is_nothrow_swappable_with_v = is_nothrow_swappable_with<Ty, Uy>::value;
template<typename Ty>
inline constexpr bool is_nothrow_swappable_v = is_nothrow_swappable<Ty>::value;
template<typename Ty>
inline constexpr bool is_nothrow_destructible_v = is_nothrow_destructible<Ty>::value;
template<typename Ty>
inline constexpr bool has_virtual_destructor_v = has_virtual_destructor<Ty>::value;
template<typename Ty>
inline constexpr bool has_unique_object_representations_v = has_unique_object_representations<Ty>::value;
template<typename Ty, typename Uy>
inline constexpr bool reference_constructs_from_temporary_v = reference_constructs_from_temporary<Ty, Uy>::value;
template<typename Ty, typename Uy>
inline constexpr bool reference_converts_from_temporary_v = reference_converts_from_temporary<Ty, Uy>::value;


// type relations

template<typename Ty, typename Uy>
inline constexpr bool is_layout_compatible_v = is_layout_compatible<Ty, Uy>::value;
template<typename Ty, typename Uy>
inline constexpr bool is_pointer_interconvertible_base_of_v = is_pointer_interconvertible_base_of<Ty, Uy>::value;
template<typename Fn, typename... ArgTypes>
inline constexpr bool is_invocable_v = is_invocable<Fn, ArgTypes...>::value;
template<typename R, typename Fn, typename... ArgTypes>
inline constexpr bool is_invocable_r_v = is_invocable_r<R, Fn, ArgTypes...>::value;
template<typename Fn, typename... ArgTypes>
inline constexpr bool is_nothrow_invocable_v = is_nothrow_invocable<Fn, ArgTypes...>::value;
template<typename R, typename Fn, typename... ArgTypes>
inline constexpr bool is_nothrow_invocable_r_v = is_nothrow_invocable_r<R, Fn, ArgTypes...>::value;

// member relationships
template<typename S, typename M>
constexpr bool is_pointer_interconvertible_with_class(M S::*m) noexcept;
template<typename S1, typename S2, typename M1, typename M2>
constexpr bool is_corresponding_member(M1 S1::*m1, M2 S2::*m2) noexcept;

// constant evaluation context
constexpr bool is_constant_evaluated() noexcept;
}


#endif
