// ywstd/@/reference_wrapper.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "invoke.hh"

namespace std {

template<typename Ty> class reference_wrapper {
  static constexpr Ty& fun(Ty& x) noexcept { return x; }
  static void fun(Ty&&) = delete;
  Ty* _ptr;
public:
  using type = Ty;

  template<typename T2> requires (!_::is_same_v<reference_wrapper, _::decay_t<T2>> && requires { reference_wrapper::fun(_::declval<T2>()); })
  constexpr reference_wrapper(T2&& x) noexcept(noexcept(reference_wrapper::fun(static_cast<T2&&>(x))))
    : _ptr(_::addressof(reference_wrapper::fun(static_cast<T2&&>(x)))) {}

  reference_wrapper(const reference_wrapper& x) noexcept = default;
  reference_wrapper& operator=(const reference_wrapper& x) noexcept = default;
  constexpr Ty& get() const noexcept { return *_ptr; }
  constexpr operator Ty& () const noexcept { return get(); }
  template<typename... Ts> constexpr invoke_result_t<Ty&, Ts...> operator()(Ts&&... xs) const { return std::invoke(get(), static_cast<Ts&&>(xs)...); }
};

template<typename Ty> reference_wrapper(Ty&) -> reference_wrapper<Ty>;

}
