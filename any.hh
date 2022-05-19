// ywstd/any.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <any>
#else

#include "@/../typeinfo.hh"
#include "@/../initializer_list.hh"
#include "@/../type_traits.hh"
#include "@/in_place.hh"

namespace std {

class bad_any_cast : public bad_cast {
public:
  const char* what() const noexcept override;
};

class any;

namespace _::_any {
  template<typename Ty> concept can_construct1 = !is_same_v<decay_t<Ty>, any> && !is_special_in_place_type<decay_t<Ty>> && is_copy_constructible_v<decay_t<Ty>>;
  template<typename Ty, typename... As> concept can_construct2 = is_constructible_v<decay_t<Ty>, As...> && is_copy_constructible_v<decay_t<Ty>>;
  template<typename Ty> concept can_assign = !is_same_v<decay_t<Ty>, any> && is_copy_constructible_v<decay_t<Ty>>;
  template<typename Ty, typename... As> concept can_emplace = is_constructible_v<decay_t<Ty>, As...> && is_copy_constructible_v<decay_t<Ty>>;
}

class any {
public:
  ~any();
  constexpr any() noexcept {}
  any(const any&);
  any(any&&) noexcept;
  template<_::_any::can_construct1 Ty> any(Ty&&);

  template<typename Ty, typename... As>
  requires _::_any::can_construct2<Ty, As...>
  explicit any(in_place_type_t<Ty>, As&&...);

  template<typename Ty, typename Uy, typename... As>
  requires _::_any::can_construct2<Ty, initializer_list<Uy>&, As...>
  explicit any(in_place_type_t<Ty>, initializer_list<Uy>, As&&...);

  any& operator=(const any&);
  any& operator=(any&&) noexcept;
  template<_::_any::can_assign Ty> any& operator=(Ty&&);

  template<typename Ty, typename... As> requires _::_any::can_emplace<Ty, As...>
  decay_t<Ty>& emplace(As&&...);

  template<typename Ty, typename Uy, typename... As>
  requires _::_any::can_emplace<Ty, initializer_list<Uy>&, As...>
  decay_t<Ty>& emplace(initializer_list<Uy>, As&&...);

  void reset() noexcept;
  void swap(any& rhs) noexcept;
  bool has_value() const noexcept;
  const type_info& type() const noexcept;
};

void swap(any& x, any& y) noexcept;

template<typename Ty, typename... As> any make_any(As&&...);
template<typename Ty, typename Uy, typename... As> any make_any(initializer_list<Uy>, As&&...);

template<typename Ty> Ty any_cast(const any&);
template<typename Ty> Ty any_cast(any&);
template<typename Ty> Ty any_cast(any&&);
template<typename Ty> Ty* any_cast(any*) noexcept;
template<typename Ty> const Ty* any_cast(const any*) noexcept;

}

#endif
