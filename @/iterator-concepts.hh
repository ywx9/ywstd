// ywstd/@/iterator-concepts.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/../concepts.hh"
#include "../@/add-remove.hh"
#include "../@/declval.hh"
#include "../@/identity.hh"
#include "../@/invoke.hh"
#include "../@/pointer_traits.hh"
#include "../@/ranges-less.hh"

namespace std {

using size_t = decltype(sizeof(int));
using ptrdiff_t = decltype((int*)0 - (int*)0);

struct input_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};
struct contiguous_iterator_tag : random_access_iterator_tag {};
struct output_iterator_tag {};

template<typename It> struct iterator_traits;
template<typename It> struct incrementable_traits;
template<typename It> struct indirectly_readable_traits;

struct default_sentinel_t {};
inline constexpr default_sentinel_t default_sentinel;

template<typename Se, typename It> inline constexpr bool disable_sized_sentinel_for = false;

namespace _::_iter_move {
  void iter_move();
  template<typename Ty> concept c1 = requires { declval<Ty>().iter_move(); };
  template<typename Ty> concept c2 = requires { iter_move(declval<Ty>()); };
  template<typename Ty> concept c3 = requires { *declval<Ty>(); };
  template<typename Ty> static constexpr auto cs = []() -> call_style {
    if constexpr (c1<Ty>) return {1, true, noexcept(declval<Ty>().iter_move())};
    else if constexpr (c2<Ty>) return {2, true, noexcept(iter_move(declval<Ty>()))};
    else if constexpr (c3<Ty>) return {3, true, noexcept(std::_::move(*declval<Ty>()))};
    else return {}; }();
  struct _ {
    template<typename Ty> requires (cs<Ty>.able) constexpr decltype(auto) operator()(Ty&& x) const noexcept(cs<Ty>.nothrow) {
      if constexpr (cs<Ty>.style == 1) return static_cast<Ty&&>(x).iter_move();
      else if constexpr (cs<Ty>.style == 2) return iter_move(static_cast<Ty&&>(x));
      else if constexpr (cs<Ty>.style == 3) return std::_::move(*static_cast<Ty&&>(x));
    }
  };
}

namespace ranges::inline _cpo {
  inline constexpr _::_iter_move::_ iter_move;
}

namespace _ {
  template<typename Ty> struct cond_value_type {};
  template<typename Ty> requires is_object_v<Ty> struct cond_value_type<Ty> { using value_type = remove_cv_t<Ty>; };
  template<typename Ty, typename Uy = iterator_traits<remove_cvref_t<Ty>>> concept has_primary_traits = is_same_v<Uy, typename Uy::_primary>;
  template<typename Ty> concept is_integer_like = integral<Ty>;
  template<typename Ty> concept is_signed_integer_like = signed_integral<Ty>;
  template<typename Ty> concept is_unsigned_integer_like = unsigned_integral<Ty>;
  template<typename Ty> using make_signed_integer_like_t = make_signed_t<Ty>;
  template<typename Ty> using make_unsigned_integer_like_t = make_unsigned_t<Ty>;
  template<typename It> struct iter_difference : type_identity<typename conditional_t<
    has_primary_traits<It>, incrementable_traits<remove_cvref_t<It>>, iterator_traits<remove_cvref_t<It>>>::difference_type> {};
  template<typename It> struct iter_value : type_identity<typename conditional_t<
    has_primary_traits<It>, indirectly_readable_traits<remove_cvref_t<It>>, iterator_traits<remove_cvref_t<It>>>::value_type> {};
  template<typename It> using iter_category_t = typename iterator_traits<It>::iterator_category;
  template<typename Ty> using iter_traits = conditional_t<has_primary_traits<Ty>, Ty, iterator_traits<Ty>>;
  template<typename Ty> concept _iter_concept_c1 = requires { typename iter_traits<Ty>::iterator_concept; };
  template<typename Ty> concept _iter_concept_c2 = requires { typename iter_traits<Ty>::iterator_category; };
  template<typename Ty> concept _iter_concept_c3 = has_primary_traits<Ty>;
  template<typename Ty, size_t = inspects<_iter_concept_c1<Ty>, _iter_concept_c2<Ty>, _iter_concept_c3<Ty>>> struct iter_concept {};
  template<typename Ty> struct iter_concept<Ty, 1> : type_identity<typename iter_traits<Ty>::iterator_concept> {};
  template<typename Ty> struct iter_concept<Ty, 2> : type_identity<typename iter_traits<Ty>::iterator_category> {};
  template<typename Ty> struct iter_concept<Ty, 3> : type_identity<random_access_iterator_tag> {};
  template<typename Ty> using iter_concept_t = typename iter_concept<Ty>::type;
}

template<typename It> using iter_difference_t = typename _::iter_difference<It>::type;
template<typename It> using iter_value_t = typename _::iter_value<It>::type;
template<_::dereferenceable It> using iter_reference_t = decltype(*declval<It&>());
template<_::dereferenceable It> requires requires { { ranges::iter_move(declval<It&>()) } -> _::can_reference; }
using iter_rvalue_reference_t = decltype(ranges::iter_move(declval<It&>()));

template<typename It> concept weakly_incrementable =
  default_initializable<It> && movable<It> && _::is_signed_integer_like<iter_difference_t<It>> && requires(It i) { { ++i } -> same_as<It&>; i++; };

template<typename It> concept incrementable = regular<It> && weakly_incrementable<It> && requires(It i) { { i++ } -> same_as<It>; };
template<typename It> concept input_or_output_iterator = requires(It i) { { *i } -> _::can_reference; } && weakly_incrementable<It>;
template<typename Se, typename It> concept sentinel_for = semiregular<Se> && input_or_output_iterator<It> && _::weakly_equality_comparable_with<Se, It>;

template<typename Se, typename It> concept sized_sentinel_for =
  sentinel_for<Se, It> && !disable_sized_sentinel_for<remove_cv_t<Se>, remove_cv_t<It>> &&
  requires(const Se& s, const It& i) { { s - i } -> same_as<iter_difference_t<It>>; { i - s } -> same_as<iter_difference_t<It>>; };

namespace _ {
  template<typename In, typename Ty = remove_cvref_t<In>> concept _indirectly_readable =
    requires(const Ty i) { { *i } -> same_as<iter_reference_t<Ty>>; { ranges::iter_move(i) } -> same_as<iter_rvalue_reference_t<Ty>>; } &&
    common_reference_with<iter_reference_t<Ty>&&, iter_value_t<Ty>&> && common_reference_with<iter_rvalue_reference_t<Ty>&&, const iter_value_t<Ty>&> &&
    common_reference_with<iter_reference_t<Ty>&&, iter_rvalue_reference_t<Ty>&&>;
  template<typename It> concept legacy_iterator =
    copyable<It> && requires(It i) { { *i } -> can_reference; { ++i } -> same_as<It&>; { *i++ } -> can_reference; };
  template<typename It> concept legacy_input_iterator =
    legacy_iterator<It> && equality_comparable<It> && signed_integral<typename incrementable_traits<It>::difference_type> &&
    requires { typename common_type_t<iter_reference_t<It>&&, typename indirectly_readable_traits<It>::value_type&>;
               typename common_type_t<decltype(*declval<It&>()++)&&, typename indirectly_readable_traits<It>::value_type&>; };
  template<typename It> concept legacy_forward_iterator =
    legacy_input_iterator<It> && constructible_from<It> && is_lvalue_reference_v<iter_reference_t<It>> &&
    same_as<remove_cvref_t<iter_reference_t<It>>, typename indirectly_readable_traits<It>::value_type> &&
    requires(It i) { { i++ } -> convertible_to<const It&>; { *i++ } -> same_as<iter_reference_t<It>>; };
  template<typename It> concept legacy_bidirectional_iterator =
    legacy_forward_iterator<It> && same_as<decltype(*declval<It&>()--), iter_reference_t<It>> &&
    requires(It i) { { --i } -> same_as<It&>; { i-- } -> convertible_to<const It&>; };
  template<typename It> concept legacy_random_access_iterator =
    legacy_bidirectional_iterator<It> && totally_ordered<It> &&
    requires(It i, typename incrementable_traits<It>::difference_type n) {
      { i += n } -> same_as<It&>; { i -= n } -> same_as<It>; { i + n } -> same_as<It>; { n + i } -> same_as<It>;
      { i - n } -> same_as<It>; { i - i } -> same_as<decltype(n)>; { i[n] } -> convertible_to<iter_reference_t<It>>; };
  template<typename It> struct iterator_traits_pointer_1 { using type = void; };
  template<has_pointer It> struct iterator_traits_pointer_1<It> { using type = typename It::pointer; };
  template<typename It, size_t = inspects<has_pointer<It>, has_arrow_operator<It>>> struct iterator_traits_pointer_2 { using type = void; };
  template<typename It> struct iterator_traits_pointer_2<It, 1> { using type = typename It::pointer; };
  template<typename It> struct iterator_traits_pointer_2<It, 2> { using type = decltype(declval<It&>().operator->()); };
  template<typename It> struct iterator_traits_reference { using type = iter_reference_t<It>; };
  template<has_reference It> struct iterator_traits_reference<It> { using type = typename It::reference; };
  template<typename It> struct iterator_traits_difference { using type = void; };
  template<typename It> requires requires { typename incrementable_traits<It>::difference_type; }
  struct iterator_traits_difference<It> { using type = typename incrementable_traits<It>::difference_type; };
  template<typename It> struct iterator_traits_category : type_identity<type_switch_t<
    inspects<legacy_random_access_iterator<It>, legacy_bidirectional_iterator<It>, legacy_forward_iterator<It>>,
    random_access_iterator_tag, bidirectional_iterator_tag, forward_iterator_tag, input_iterator_tag>> {};
}

template<typename Ty> struct incrementable_traits {};
template<typename Ty> struct incrementable_traits<const Ty> : incrementable_traits<Ty> {};
template<_::has_difference_type Ty> struct incrementable_traits<Ty> { using difference_type = typename Ty::difference_type; };
template<typename Ty> requires (!_::has_difference_type<Ty>) && integral<decltype(declval<Ty>() - declval<Ty>())>
struct incrementable_traits<Ty> { using difference_type = _::make_signed_t<decltype(declval<Ty>() - declval<Ty>())>; };
template<typename Ty> requires _::is_object_v<Ty> struct incrementable_traits<Ty*> { using difference_type = ptrdiff_t; };

template<typename Ty> struct indirectly_readable_traits {};
template<typename Ty> struct indirectly_readable_traits<const Ty> : indirectly_readable_traits<Ty> {};
template<typename Ty> struct indirectly_readable_traits<Ty*> : _::cond_value_type<Ty> {};
template<_::has_value_type Ty> struct indirectly_readable_traits<Ty> : _::cond_value_type<typename Ty::value_type> {};
template<_::has_element_type Ty> struct indirectly_readable_traits<Ty> : _::cond_value_type<typename Ty::element_type> {};
template<_::has_element_type Ty> requires _::has_value_type<Ty> && _::same_as<typename Ty::value_type, typename Ty::element_type>
struct indirectly_readable_traits<Ty> : _::cond_value_type<typename Ty::value_type> {};

template<typename It> struct iterator_traits { using _primary = iterator_traits; };
template<_::has_iter_types It> struct iterator_traits<It> {
  using difference_type = typename It::difference_type;
  using value_type = typename It::value_type;
  using pointer = typename _::iterator_traits_pointer_1<It>::type;
  using reference = typename It::reference;
  using iterator_category = typename It::iterator_category;
  using _primary = iterator_traits;
};
template<_::legacy_input_iterator It> requires (!_::has_iter_types<It>) struct iterator_traits<It> {
  using difference_type = typename incrementable_traits<It>::difference_type;
  using value_type = typename indirectly_readable_traits<It>::value_type;
  using pointer = typename _::iterator_traits_pointer_2<It>::type;
  using reference = typename _::iterator_traits_reference<It>::type;
  using iterator_category = typename _::iterator_traits_category<It>::type;
  using _primary = iterator_traits;
};
template<_::legacy_iterator It> requires (!_::has_iter_types<It>) struct iterator_traits<It> {
  using difference_type = typename _::iterator_traits_difference<It>::type;
  using value_type = void;
  using pointer = void;
  using reference = void;
  using iterator_category = output_iterator_tag;
  using _primary = iterator_traits;
};

template<typename In> concept indirectly_readable = _::_indirectly_readable<In>;

template<typename Ot, typename Ty> concept indirectly_writable =
  requires(Ot&& o) {
    *o = declval<Ty>();
    *static_cast<Ot&&>(o) = declval<Ty>();
    const_cast<const iter_reference_t<Ot>&&>(*o) = declval<Ty>();
    const_cast<const iter_reference_t<Ot>&&>(*static_cast<Ot&&>(o)) = declval<Ty>();
  };
template<typename It, typename Ty> concept output_iterator =
  input_or_output_iterator<It> && indirectly_writable<It, Ty> && requires(It i, Ty && t) { *i++ = static_cast<Ty&&>(t); };

template<typename In, typename Ot> concept indirectly_movable = indirectly_readable<In> && indirectly_writable<Ot, iter_rvalue_reference_t<In>>;
template<typename In, typename Ot> concept indirectly_copyable = indirectly_readable<In> && indirectly_writable<Ot, iter_reference_t<In>>;

template<typename In, typename Ot> concept indirectly_movable_storable =
  indirectly_movable<In, Ot> && indirectly_writable<Ot, iter_value_t<In>> && movable<iter_value_t<In>> &&
  constructible_from<iter_value_t<In>, iter_rvalue_reference_t<In>> && assignable_from<iter_value_t<In>&, iter_rvalue_reference_t<In>>;

template<typename In, typename Ot> concept indirectly_copyable_storable =
  indirectly_copyable<In, Ot> && indirectly_writable<Ot, iter_value_t<In>&> && indirectly_writable<Ot, const iter_value_t<In>&> &&
  indirectly_writable<Ot, iter_value_t<In>&&> && indirectly_writable<Ot, const iter_value_t<In>&&> && copyable<iter_value_t<In>> &&
  constructible_from<iter_value_t<In>, iter_reference_t<In>> && assignable_from<iter_value_t<In>&, iter_reference_t<In>>;

template<indirectly_readable It> using iter_common_reference_t = common_reference_t<iter_reference_t<It>, iter_value_t<It>&>;
template<typename Fn, typename... Is> requires (indirectly_readable<Is> && ...) && invocable<Fn, iter_reference_t<Is>...>
using indirect_result_t = invoke_result_t<Fn, iter_reference_t<Is>...>;

namespace _::_iter_swap {
  template<typename T1, typename T2> void iter_swap(T1, T2) = delete;
  template<typename T1, typename T2> concept c1 = requires { declval<T1>().iter_swap(declval<T2>()); };
  template<typename T1, typename T2> concept c2 = requires { iter_swap(declval<T1>(), declval<T2>()); };
  template<typename T1, typename T2> concept c3 =
    indirectly_readable<remove_reference_t<T1>> && indirectly_readable<remove_reference_t<T2>> && swappable_with<iter_reference_t<T1>, iter_reference_t<T2>>;
  template<typename T1, typename T2> concept c4 =
    indirectly_movable_storable<remove_reference_t<T1>, remove_reference_t<T2>> && indirectly_movable_storable<remove_reference_t<T2>, remove_reference_t<T1>>;
  template<typename T1, typename T2> constexpr auto call(T1&& t, T2&& u)
    noexcept(noexcept(iter_value_t<T1>{ranges::iter_move(t)})) { T1 a = ranges::iter_move(t); *t = ranges::iter_move(u); return a; }
  template<typename T1, typename T2> static constexpr auto cs = []() -> call_style {
    if constexpr (c1<T1, T2>) return {1, true, noexcept(declval<T1>().iter_swap(declval<T2>()))};
    else if constexpr (c2<T1, T2>) return {2, true, noexcept(iter_swap(declval<T1>(), declval<T2>()))};
    else if constexpr (c3<T1, T2>) return {3, true, noexcept(ranges::swap(*declval<T1>(), *declval<T2>()))};
    else if constexpr (c4<T1, T2>) return {4, true, noexcept(*declval<T1>() = _iter_swap::call(declval<T2>(), declval<T1>()))};
    else return {}; }();
  struct _ {
    template<typename T1, typename T2> requires (cs<T1, T2>.able) constexpr void operator()(T1&& x, T2&& y) const noexcept(cs<T1, T2>.nothrow) {
      if constexpr (cs<T1, T2>.style == 1) static_cast<T1&&>(x).iter_swap(static_cast<T2&&>(y));
      else if constexpr (cs<T1, T2>.style == 2) iter_swap(static_cast<T1&&>(x), static_cast<T2&&>(y));
      else if constexpr (cs<T1, T2>.style == 3) ranges::swap(*static_cast<T1&&>(x), *static_cast<T2&&>(y));
      else if constexpr (cs<T1, T2>.style == 4) *static_cast<T1&&>(x) = _iter_swap::call(static_cast<T2&&>(y), static_cast<T1&&>(x));
    }
  };
}

namespace ranges::inline _cpo {
  inline constexpr std::_::_iter_swap::_ iter_swap;
}

template<typename I1, typename I2 = I1> concept indirectly_swappable =
  indirectly_readable<I1> && indirectly_readable<I2> &&
  requires(const I1 i1, const I2 i2) {
    ranges::iter_swap(i1, i1); ranges::iter_swap(i1, i2);
    ranges::iter_swap(i2, i1); ranges::iter_swap(i2, i2);
  };
template<typename Fn, typename It> concept indirectly_unary_invocable =
  indirectly_readable<It> && copy_constructible<Fn> && invocable<Fn&, iter_value_t<It>&> && invocable<Fn&, iter_reference_t<It>> &&
  invocable<Fn&, iter_common_reference_t<It>> && common_reference_with<invoke_result_t<Fn&, iter_value_t<It>&>, invoke_result_t<Fn&, iter_reference_t<It>>>;

template<typename Fn, typename It> concept indirectly_regular_unary_invocable =
  indirectly_readable<It> && copy_constructible<Fn> && regular_invocable<Fn&, iter_value_t<It>&> &&
  regular_invocable<Fn&, iter_reference_t<It>> && regular_invocable<Fn&, iter_common_reference_t<It>> &&
  common_reference_with<invoke_result_t<Fn&, iter_value_t<It>&>, invoke_result_t<Fn&, iter_reference_t<It>>>;

template<typename Fn, typename It> concept indirect_unary_predicate =
  indirectly_readable<It> && copy_constructible<Fn> && predicate<Fn&, iter_value_t<It>&> &&
  predicate<Fn&, iter_reference_t<It>> && predicate<Fn&, iter_common_reference_t<It>>;

template<typename Fn, typename It1, typename It2 = It1> concept indirect_binary_predicate =
  indirectly_readable<It1> && indirectly_readable<It2> && copy_constructible<Fn> && predicate<Fn&, iter_value_t<It1>&, iter_value_t<It2>&> &&
  predicate<Fn&, iter_value_t<It1>&, iter_reference_t<It2>> && predicate<Fn&, iter_reference_t<It1>, iter_value_t<It2>&> &&
  predicate<Fn&, iter_reference_t<It1>, iter_reference_t<It2>> && predicate<Fn&, iter_common_reference_t<It1>, iter_common_reference_t<It2>>;

template<typename Fn, typename It1, typename It2 = It1> concept indirect_equivalence_relation =
  indirectly_readable<It1> && indirectly_readable<It2> && copy_constructible<Fn> && equivalence_relation<Fn&, iter_reference_t<It1>, iter_reference_t<It2>> &&
  equivalence_relation<Fn&, iter_reference_t<It1>, iter_value_t<It2>&> && equivalence_relation<Fn&, iter_value_t<It1>&, iter_reference_t<It2>> &&
  equivalence_relation<Fn&, iter_value_t<It1>&, iter_value_t<It2>&> && equivalence_relation<Fn&, iter_common_reference_t<It1>, iter_common_reference_t<It2>>;

template<typename Fn, typename It1, typename It2 = It1> concept indirect_strict_weak_order =
  indirectly_readable<It1> && indirectly_readable<It2> && copy_constructible<Fn> && strict_weak_order<Fn&, iter_value_t<It1>&, iter_value_t<It2>&> &&
  strict_weak_order<Fn&, iter_value_t<It1>&, iter_reference_t<It2>> && strict_weak_order<Fn&, iter_reference_t<It1>, iter_value_t<It2>&> &&
  strict_weak_order<Fn&, iter_reference_t<It1>, iter_reference_t<It2>> && strict_weak_order<Fn&, iter_common_reference_t<It1>, iter_common_reference_t<It2>>;

template<indirectly_readable It, indirectly_regular_unary_invocable<It> Pj> struct projected {
  using value_type = remove_cvref_t<indirect_result_t<Pj&, It>>;
  indirect_result_t<Pj&, It> operator*() const;
};

template<weakly_incrementable It, typename Pj> struct incrementable_traits<projected<It, Pj>> { using difference_type = iter_difference_t<It>; };

template<typename It> concept input_iterator =
  input_or_output_iterator<It> && indirectly_readable<It> && derived_from<_::iter_concept_t<It>, input_iterator_tag>;

template<typename It> concept forward_iterator =
  input_iterator<It> && derived_from<_::iter_concept_t<It>, forward_iterator_tag> && incrementable<It> && sentinel_for<It, It>;

template<typename It> concept bidirectional_iterator =
  forward_iterator<It> && derived_from<_::iter_concept_t<It>, bidirectional_iterator_tag> &&
  requires(It i) { { --i } -> same_as<It&>; { i-- } -> same_as<It>; };

template<typename It> concept random_access_iterator =
  bidirectional_iterator<It> && derived_from<_::iter_concept_t<It>, random_access_iterator_tag> && totally_ordered<It> && sized_sentinel_for<It, It> &&
  requires(It i, const It j, const iter_difference_t<It> n) {
    { i += n } -> same_as<It&>; { j + n } -> same_as<It>; { n + j } -> same_as<It>;
    { i -= n } -> same_as<It&>; { j - n } -> same_as<It>; { j[n] } -> same_as<iter_reference_t<It>>; };

template<typename It> concept contiguous_iterator =
  random_access_iterator<It> && derived_from<_::iter_concept_t<It>, contiguous_iterator_tag> &&
  _::is_lvalue_reference_v<iter_reference_t<It>> && same_as<iter_value_t<It>, remove_cvref_t<iter_reference_t<It>>> &&
  requires(const It& i) { { _::to_address(i) } -> same_as<add_pointer_t<iter_reference_t<It>>>; };

template<typename It1, typename It2, typename Fn, typename Pj1 = identity, typename Pj2 = identity>
concept indirectly_comparable = indirect_binary_predicate<Fn, projected<It1, Pj1>, projected<It2, Pj2>>;

template<typename It1, typename It2, typename Ot, typename Fn = ranges::less, typename Pj1 = identity, typename Pj2 = identity>
concept mergeable = input_iterator<It1> && input_iterator<It2> && weakly_incrementable<Ot> && indirectly_copyable<It1, Ot> &&
  indirectly_copyable<It2, Ot> && indirect_strict_weak_order<Fn, projected<It1, Pj1>, projected<It2, Pj2>>;

template<typename It> concept permutable = forward_iterator<It> && indirectly_movable_storable<It, It> && indirectly_swappable<It>;

template<typename It, typename Fn = ranges::less, typename Pj = identity>
concept sortable = permutable<It> && indirect_strict_weak_order<Fn, projected<It, Pj>>;

}
