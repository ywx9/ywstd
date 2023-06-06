#pragma once

#include "type_traits.hh"

#ifdef __ywstd__
#include <concepts>
#else

namespace std {

namespace _ {
template<typename Ty, typename Uy> concept _same_as = is_same_v<Ty, Uy>;
}

/// @brief specifies that a type is the same as another type
template<typename Ty, typename Uy> concept same_as = _::_same_as<Ty, Uy> && _::_same_as<Ty, Uy>;

/// @brief specifies that a type is derived from another type
template<typename Ty, typename Uy> concept derived_from =
    is_base_of_v<Uy, Ty> && is_convertible_v<const volatile Uy*, const volatile Ty*>;

/// @brief specifies that a type is implicitly convertible to another type
template<typename Ty, typename Uy> concept convertible_to =
    is_convertible_v<Ty, Uy> && requires(Ty (&f)()) { static_cast<Uy>(f()); };

/// @brief specifies that two types share a common reference type
template<typename Ty, typename Uy> concept common_reference_with =
    same_as<common_reference_t<Ty, Uy>, common_reference_t<Uy, Ty>> &&
    convertible_to<Ty, common_reference_t<Ty, Uy>> && convertible_to<Uy, common_reference_t<Ty, Uy>>;

/// @brief specifies that two types share a common type
template<typename Ty, typename Uy> concept common_with =
    same_as<common_type_t<Ty, Uy>, common_type_t<Uy, Ty>> &&
    requires { static_cast<common_type_t<Ty, Uy>>(declval<Ty>());
               static_cast<common_type_t<Ty, Uy>>(declval<Uy>()); } &&
    common_reference_with<add_lvalue_reference_t<const Ty>, add_lvalue_reference_t<const Uy>> &&
    common_reference_with<add_lvalue_reference_t<common_type_t<Ty, Uy>>,
                          common_reference_t<add_lvalue_reference_t<const Ty>, add_lvalue_reference_t<const Uy>>>;

/// @brief specifies that a type is an integral type
template<typename Ty> concept integral = is_integral_v<Ty>;

/// @brief specifies that a type is an integral type that is signed
template<typename Ty> concept signed_integral = integral<Ty> && is_signed_v<Ty>;

/// @brief specifies that a type is an integral type that is unsigned
template<typename Ty> concept unsigned_integral = integral<Ty> && !signed_integral<Ty>;

/// @brief specifies that a type is a floating-point type
template<typename Ty> concept floating_point = is_floating_point_v<Ty>;

/// @brief specifies that an object of the type can be destroyed
template<typename Ty> concept destructible = is_nothrow_destructible_v<Ty>;

/// @brief specifies that a variable of the type can be constructed from or bound to a set of argument types
template<typename Ty, typename... As> concept constructible_from = destructible<Ty> && is_constructible_v<Ty, As...>;

/// @brief specifies that an object of a type can be default constructed
template<typename Ty> concept default_initializable = constructible_from<Ty> && requires { Ty{}; };

/// @brief specifies that an object of a type can be move constructed
template<typename Ty> concept move_constructible = constructible_from<Ty, Ty> && convertible_to<Ty, Ty>;

/// @brief specifies that an object of a type can be copy constructed and move constructed
template<typename Ty> concept copy_constructible =
    move_constructible<Ty> && constructible_from<Ty, Ty&> && convertible_to<Ty&, Ty> &&
    constructible_from<Ty, const Ty&> && convertible_to<const Ty&, Ty> &&
    constructible_from<Ty, const Ty> && convertible_to<const Ty, Ty>;

/// @brief specifies that a type is assignable from another type
template<typename Ty, typename At> concept assignable_from =
    is_lvalue_reference_v<Ty> &&
    common_reference_with<const remove_reference_t<Ty>&, const remove_reference_t<At>&> &&
    requires(Ty t, At&& a) { {t = static_cast<At&&>(a) } -> same_as<Ty>; };

namespace ranges {
namespace _::_swap {
template<typename Ty> void swap(Ty&, Ty&) = delete;
template<typename Ty> concept _c0 =
    is_class_v<remove_reference_t<Ty>> || is_union_v<remove_reference_t<Ty>> || is_enum_v<remove_reference_t<Ty>>;
template<typename T1, typename T2> concept _c1 =
    (_c0<T1> || _c0<T2>)&&requires(T1&& x, T2&& y) { swap(static_cast<T1&&>(x), static_cast<T2&&>(y)); };
struct _swap {
  template<typename T1, typename T2> requires _c1<T1, T2> constexpr void operator()(T1&& x, T2&& y) const
      noexcept(noexcept(swap(static_cast<T1&&>(x), static_cast<T2&&>(y)))) {
    swap(static_cast<T1&&>(x), static_cast<T2&&>(y));
  }
  template<typename Ty> requires(!_c1<Ty&, Ty&> && move_constructible<Ty> && assignable_from<Ty&, Ty>)
  constexpr void operator()(Ty& x, Ty& y) const
      noexcept(is_nothrow_move_constructible<Ty>&& is_nothrow_move_assignable_v<Ty>) {
    Ty t(static_cast<Ty&&>(x));
    x = static_cast<Ty&&>(y), y = static_cast<Ty&&>(t);
  }
  template<typename T1, typename T2, size_t Nx> constexpr void operator()(T1 (&x)[Nx], T2 (&y)[Nx]) const
      noexcept(noexcept((*this)(x[0], y[0]))) requires requires { (*this)(x[0], y[0]); } {
    for (size_t i{}; i < Nx; ++i) (*this)(x[i], y[i]);
  }
};
}
inline namespace _cpos {

/// @brief swaps the values of two objects
inline constexpr _::_swap::_swap swap;
}
}

/// @brief specifies that a type can be swapped or that two types can be swapped with each other
template<typename Ty> concept swappable = requires(Ty& x, Ty& y) { ranges::swap(x, y); };

/// @brief specifies that a type can be swapped or that two types can be swapped with each other
template<typename Ty, typename Uy> concept swappable_with =
    common_reference_with<const remove_reference_t<Ty>&, const remove_reference_t<Uy>&> &&
    requires(Ty&& x, Uy&& y) { ranges::swap(static_cast<Ty&&>(x), static_cast<Ty&&>(x));
                               ranges::swap(static_cast<Ty&&>(x), static_cast<Uy&&>(y));
                               ranges::swap(static_cast<Uy&&>(y), static_cast<Ty&&>(x));
                               ranges::swap(static_cast<Uy&&>(y), static_cast<Uy&&>(y)); };

namespace _ {
template<typename Ty> concept _boolean_testable =
    convertible_to<Ty, bool> && requires(Ty&& x) { { !static_cast<Ty&&>(x)} -> convertible_to<bool>; };
template<typename Ty, typename Uy> concept _weakly_equality_comparable_with =
    requires(const remove_reference_t<Ty>& x, const remove_reference_t<Uy>& y) {
      { x == y } -> _boolean_testable;
      { x != y } -> _boolean_testable;
      { y == x } -> _boolean_testable;
      { y != x } -> _boolean_testable;
    };
}

/// @brief specifies that operator == is an equivalence relation
template<typename Ty> concept equality_comparable = _::_weakly_equality_comparable_with<Ty, Ty>;

/// @brief specifies that operator == is an equivalence relation
template<typename Ty, typename Uy> concept equality_comparable_with =
    equality_comparable<Ty> && equality_comparable<Uy> &&
    common_reference_with<const remove_reference_t<Ty>&, const remove_reference_t<Uy>&> &&
    equality_comparable<common_reference_t<const remove_reference_t<Ty>&, const remove_reference_t<Uy>&>> &&
    _::_weakly_equality_comparable_with<Ty, Uy>;

/// @brief specifies that the comparison operators on the type yield a total order
template<typename Ty> concept totally_ordered =
    equality_comparable<Ty> &&
    requires(const remove_reference_t<Ty>& x, const remove_reference_t<Ty>& y) {
      { x < y } -> _::_boolean_testable;
      { x > y } -> _::_boolean_testable;
      { x <= y } -> _::_boolean_testable;
      { x >= y } -> _::_boolean_testable;
    };

/// @brief specifies that the comparison operators on the type yield a total order
template<typename Ty, typename Uy> concept totally_ordered_with =
    totally_ordered<Ty> && totally_ordered<Uy> &&
    common_reference_with<const remove_reference_t<Ty>&, const remove_reference_t<Uy>&> &&
    totally_ordered<common_reference_t<const remove_reference_t<Ty>&, const remove_reference_t<Uy>&>> &&
    equality_comparable_with<Ty, Uy> &&
    requires(const remove_reference_t<Ty>& x, const remove_reference_t<Uy>& y) {
      { x < y } -> _::_boolean_testable;
      { x > y } -> _::_boolean_testable;
      { x <= y } -> _::_boolean_testable;
      { x >= y } -> _::_boolean_testable;
      { y < x } -> _::_boolean_testable;
      { y > x } -> _::_boolean_testable;
      { y <= x } -> _::_boolean_testable;
      { y >= x } -> _::_boolean_testable;
    };

/// @brief specifies that an object of a type can be moved and swapped
template<typename Ty> concept movable =
    is_object_v<Ty> && move_constructible<Ty> && assignable_from<Ty&, Ty> && swappable<Ty>;

/// @brief specifies that an object of a type can be copied, moved, and swapped
template<typename Ty> concept copyable =
    copy_constructible<Ty> && movable<Ty> && assignable_from<Ty&, Ty&> &&
    assignable_from<Ty&, const Ty&> && assignable_from<Ty&, const Ty>;

/// @brief specifies that an object of a type can be copied, moved, swapped, and default constructed
template<typename Ty> concept semiregular = copyable<Ty> && default_initializable<Ty>;

/// @brief specifies that a type is regular, that is, it is both semiregular and equality_comparable
template<typename Ty> concept regular = semiregular<Ty> && equality_comparable<Ty>;

/// @brief specifies that a callable type can be invoked with a given set of argument types
template<typename Fn, typename... As> concept invocable =
    requires(Fn&& f, As&&... as) { std::invoke(static_cast<Fn&&>(f), static_cast<As&&>(as)...); };

/// @brief specifies that a callable type can be invoked with a given set of argument types
template<typename Fn, typename... As> concept regular_invocable = invocable<Fn, As...>;

/// @brief specifies that a callable type is a Boolean predicate
template<typename Fn, typename... As> concept predicate =
    regular_invocable<Fn, As...> && _::_boolean_testable<invoke_result_t<Fn, As...>>;

/// @brief specifies that a callable type is a binary relation
template<typename Fn, typename Ty, typename Uy> concept relation =
    predicate<Fn, Ty, Ty> && predicate<Fn, Uy, Uy> && predicate<Fn, Ty, Uy> && predicate<Fn, Uy, Ty>;

/// @brief specifies that a relation imposes an equivalence relation
template<typename Fn, typename Ty, typename Uy> concept equivalence_relation = relation<Fn, Ty, Uy>;

/// @brief pecifies that a relation imposes a strict weak ordering
template<typename Fn, typename Ty, typename Uy> concept strict_weak_order = relation<Fn, Ty, Uy>;

}

#endif
