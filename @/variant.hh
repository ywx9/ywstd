// ywstd/@/variant.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../initializer_list.hh"
#include "../compare.hh"
#include "in_place.hh"
#include "integral_constant.hh"

namespace std::_ {

template<bool Bx, typename... Ts> struct _variant_value {
  constexpr void destroy(size_t) noexcept {}
};
template<typename... Ts> using variant_value = _variant_value<(is_trivially_destructible_v<Ts> && ...), Ts...>;
template<typename T1, typename... Ts> struct _variant_value<true, T1, Ts...> {
  union {
    remove_const_t<T1> value;
    variant_value<Ts...> other;
  };
  constexpr _variant_value() noexcept {}
  template<typename... As> constexpr explicit _variant_value(constant<size_t{0}>, As&&... as)
    noexcept(is_nothrow_constructible_v<T1, As...>) : value{static_cast<As&&>(as)...} {}
  template<size_t Ix, typename... As> constexpr explicit _variant_value(constant<size_t{Ix}>, As&&... as)
    noexcept(is_nothrow_constructible_v<variant_value<Ts...>, constant<size_t{Ix - 1}>, As...>) : other{constant<size_t{Ix - 1}>{}, static_cast<As&&>(as)...} {}
  constexpr void destroy(size_t i) noexcept { i == 0 ? destroy_at(&value) : other.destroy(--i); }
};
template<typename T1, typename... Ts> struct _variant_value<false, T1, Ts...> {
  union { remove_const_t<T1> value; variant_value<Ts...> other; };
  ~_variant_value() noexcept {}
  _variant_value() noexcept {}
  _variant_value(const _variant_value&) = default;
  _variant_value(_variant_value&&) = default;
  template<typename... As> constexpr explicit _variant_value(constant<size_t{0}>, As&&... as)
    noexcept(is_nothrow_constructible_v<T1, As...>) : value{static_cast<As&&>(as)...} {}
  template<size_t Ix, typename... As> constexpr explicit _variant_value(constant<size_t{Ix}>, As&&... as)
    noexcept(is_nothrow_constructible_v<variant_value<Ts...>, constant<size_t{Ix - 1}>, As...>) : other{constant<size_t{Ix - 1}>{}, static_cast<As&&>(as)...} {}
  _variant_value& operator=(const _variant_value&) = default;
  _variant_value& operator=(_variant_value&&) = default;
  void destroy(size_t i) noexcept { i == 0 ? destroy_at(&value) : other.destroy(--i); }
};

template<size_t Ix, typename... Ts>
constexpr type_switch_t<Ix, Ts...>& get_variant_value(variant_value<Ts...>& x) noexcept {
  if constexpr (Ix == 0) return x.value;
  else return _::get_variant_value<Ix - 1>(x.other);
}
template<size_t Ix, typename... Ts>
constexpr type_switch_t<Ix, Ts...>&& get_variant_value(variant_value<Ts...>&& x) noexcept {
  if constexpr (Ix == 0) return _::move(x.value);
  else return _::get_variant_value<Ix - 1>(_::move(x.other));
}
template<size_t Ix, typename... Ts>
constexpr const type_switch_t<Ix, Ts...>& get_variant_value(const variant_value<Ts...>& x) noexcept {
  if constexpr (Ix == 0) return x.value;
  else return _::get_variant_value<Ix - 1>(x.other);
}
template<size_t Ix, typename... Ts>
constexpr type_switch_t<Ix, Ts...>&& get_variant_value(const variant_value<Ts...>&& x) noexcept {
  if constexpr (Ix == 0) return _::move(x.value);
  else return _::get_variant_value<Ix - 1>(_::move(x.other));
}

template<typename Ty, typename... Ts> concept variant_convertible =
  counts<is_same_v<Ty, Ts>...> == 1 || (counts<is_same_v<Ty, Ts>...> == 0 && counts<is_convertible_v<Ty, Ts>...> == 1);

template<typename Ty, typename... Ts> using variant_convert_t = conditional_t<
  (is_same_v<Ty, Ts> || ...), type_switch_t<inspects<is_same_v<Ty, Ts>...>, void, Ts...>, type_switch_t<inspects<is_convertible_v<Ty, Ts>...>, void, Ts...>>;

}

namespace std {

template<typename... Ts> class variant;

inline constexpr size_t variant_npos = -1;

template<typename Ty> struct variant_size;
template<typename Ty> struct variant_size<const Ty> : variant_size<Ty> {};
template<typename Ty> struct variant_size<volatile Ty> : variant_size<Ty> {};
template<typename Ty> struct variant_size<const volatile Ty> : variant_size<Ty> {};
template<typename Ty> inline constexpr size_t variant_size_v = variant_size<Ty>::value;
template<typename... Ts> struct variant_size<variant<Ts...>> : integral_constant<size_t, sizeof...(Ts)> {};

template<size_t Ix, typename Ty> struct variant_alternative;
template<size_t Ix, typename Ty> struct variant_alternative<Ix, const Ty> : variant_alternative<Ix, Ty> {};
template<size_t Ix, typename Ty> struct variant_alternative<Ix, volatile Ty> : variant_alternative<Ix, Ty> {};
template<size_t Ix, typename Ty> struct variant_alternative<Ix, const volatile Ty> : variant_alternative<Ix, Ty> {};
template<size_t Ix, typename Ty> using variant_alternative_t = typename variant_alternative<Ix, Ty>::type;
template<size_t Ix, typename... Ts> struct variant_alternative<Ix, variant<Ts...>> : type_identity<_::type_switch_t<Ix, Ts...>> {};

template<typename... Ts> class variant {
  _::variant_value<Ts...> _v;
  size_t _i;
public:
  constexpr ~variant() {}

  constexpr variant() noexcept(_::is_nothrow_default_constructible_v<_::type_switch_t<0, Ts...>>)
    requires _::is_default_constructible_v<variant_alternative_t<0, variant>> : _v{_::constant<size_t{0}>{}}, _i{0} {}

  constexpr variant(const variant& a) requires (_::is_copy_constructible_v<Ts> && ...) : _v{a._v}, _i{a._i} {}

  constexpr variant(variant&& a) noexcept((_::is_nothrow_move_constructible_v<Ts> && ...))
    requires (_::is_move_constructible_v<Ts> && ...) : _v{_::move(a._v)}, _i{a._i} {}

  template<typename Ty> constexpr variant(Ty&& v) noexcept(_::is_nothrow_constructible_v<_::variant_convert_t<Ty, Ts...>, Ty>)
    requires _::is_constructible_v<_::variant_convert_t<Ty, Ts...>, Ty> &&
      (!_::specialized_of<_::remove_cvref_t<Ty>, in_place_type_t> && !_::is_special_in_place_index<_::remove_cvref_t<Ty>>)
    : _v{_::constant<_::inspects<_::is_same_v<_::variant_convert_t<Ty, Ts...>, Ts>...> - 1>{}, static_cast<Ty&&>(v)},
      _i{_::inspects<_::is_same_v<_::variant_convert_t<Ty, Ts...>, Ts>...> - 1} {}

  template<typename Ty, typename... As> constexpr explicit variant(in_place_type_t<Ty>, As&&... as)
    requires _::is_constructible_v<Ty, As...> && _::included_in<Ty, Ts...>
    : _v{_::constant<_::inspects<_::is_same_v<Ty, Ts>...> - 1>{}, static_cast<As&&>(as)...}, _i{_::inspects<_::is_same_v<Ty, Ts>...> - 1} {}

  template<typename Ty, typename Uy, typename... As> constexpr explicit variant(in_place_type_t<Ty>, initializer_list<Uy> il, As&&... as)
    requires _::is_constructible_v<Ty, initializer_list<Uy>&, As...> && _::included_in<Ty, Ts...>
    : _v{_::constant<_::inspects<_::is_same_v<Ty, Ts>...> - 1>{}, il, static_cast<As&&>(as)...}, _i{_::inspects<_::is_same_v<Ty, Ts>...> - 1} {}

  template<size_t Ix, typename... As> constexpr explicit variant(in_place_index_t<Ix>, As&&... as)
    requires _::is_convertible_v<variant_alternative_t<Ix, variant>, As...> : _v{_::constant<Ix>{}, static_cast<As&&>(as)...}, _i{Ix} {}

  template<size_t Ix, typename Uy, typename... As> constexpr explicit variant(in_place_index_t<Ix>, initializer_list<Uy> il, As&&... as)
    requires _::is_constructible_v<variant_alternative_t<Ix, variant>, initializer_list<Uy>&, As...>
    : _v{_::constant<Ix>{}, il, static_cast<As&&>(as)...}, _i{Ix} {}

  constexpr variant& operator=(const variant& a) {
    if (valueless_by_exception() && a.valueless_by_exception()) return *this;
    if (a.valueless_by_exception()) { _v.destroy(_i); _i = 0; return *this; }
    if constexpr (_::is_nothrow_copy_constructible_v<variant_alternative_t<a.index(), variant>> &&
                  !_::is_nothrow_move_constructible_v<variant_alternative_t<a.index(), variant>>)
      return this->emplace<a.index()>(get<a.index()>(a));
    return  this->operator=(variant{a});
  }
  constexpr variant& operator=(variant&&) noexcept(((_::is_nothrow_move_constructible_v<Ts> && ...) && (_::is_nothrow_move_assignable_v<Ts> && ...)));

  template<typename Ty> constexpr variant& operator=(Ty&&)
    noexcept(_::is_nothrow_constructible_v<_::variant_convert_t<Ty, Ts...>, Ty> && _::is_nothrow_assignable_v<_::variant_convert_t<Ty, Ts...>&, Ty>);

  template<typename Ty, typename... As> constexpr Ty& emplace(As&&...);
  template<typename Ty, typename Uy, typename... As> constexpr Ty& emplace(initializer_list<Uy>, As&&...);
  template<size_t I, typename... As> constexpr variant_alternative_t<I, variant<As...>>& emplace(As&&...);
  template<size_t I, typename Uy, typename... As> constexpr variant_alternative_t<I, variant<As...>>& emplace(initializer_list<Uy>, As&&...);
  constexpr bool valueless_by_exception() const noexcept;
  constexpr size_t index() const noexcept;
  constexpr void swap(variant&) noexcept(((_::is_nothrow_move_constructible_v<Ts> && _::is_nothrow_swappable_v<Ts>) && ...));
};

template<typename... Ts> requires (three_way_comparable<Ts> && ...)
constexpr common_comparison_category_t<compare_three_way_result_t<Ts>...> operator<=>(const variant<Ts...>&, const variant<Ts...>&);

template<size_t Ix, typename... Ts> constexpr variant_alternative_t<Ix, variant<Ts...>>& get(variant<Ts...>&);
template<size_t Ix, typename... Ts> constexpr variant_alternative_t<Ix, variant<Ts...>>&& get(variant<Ts...>&&);
template<size_t Ix, typename... Ts> constexpr const variant_alternative_t<Ix, variant<Ts...>>& get(const variant<Ts...>&);
template<size_t Ix, typename... Ts> constexpr const variant_alternative_t<Ix, variant<Ts...>>&& get(const variant<Ts...>&&);

template<typename T, typename... Ts> constexpr T& get(variant<Ts...>&);
template<typename T, typename... Ts> constexpr T&& get(variant<Ts...>&&);
template<typename T, typename... Ts> constexpr const T& get(const variant<Ts...>&);
template<typename T, typename... Ts> constexpr const T&& get(const variant<Ts...>&&);

template<typename... Ts> constexpr bool operator==(const variant<Ts...>&, const variant<Ts...>&);
template<typename... Ts> constexpr bool operator!=(const variant<Ts...>&, const variant<Ts...>&);
template<typename... Ts> constexpr bool operator<(const variant<Ts...>&, const variant<Ts...>&);
template<typename... Ts> constexpr bool operator>(const variant<Ts...>&, const variant<Ts...>&);
template<typename... Ts> constexpr bool operator<=(const variant<Ts...>&, const variant<Ts...>&);
template<typename... Ts> constexpr bool operator>=(const variant<Ts...>&, const variant<Ts...>&);

}
