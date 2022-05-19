// ywstd/@/atomic.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "_.hh"

#include "memory_order.hh"

namespace std {

using ptrdiff_t = decltype((int*)0 - (int*)0);

template<typename Ty> struct atomic {
  using value_type = Ty;
  static constexpr bool is_always_lock_free = false;
  bool is_lock_free() const volatile noexcept;
  bool is_lock_free() const noexcept;
  constexpr atomic() noexcept(_::is_nothrow_default_constructible_v<Ty>);
  constexpr atomic(Ty) noexcept;
  atomic(const atomic&) = delete;
  atomic& operator=(const atomic&) = delete;
  atomic& operator=(const atomic&) volatile = delete;
  Ty load(memory_order = memory_order::seq_cst) const volatile noexcept;
  Ty load(memory_order = memory_order::seq_cst) const noexcept;
  operator Ty() const volatile noexcept;
  operator Ty() const noexcept;
  void store(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  void store(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty operator=(Ty) volatile noexcept;
  Ty operator=(Ty) noexcept;
  Ty exchange(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty exchange(Ty, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order, memory_order) noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order, memory_order) noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order = memory_order::seq_cst) noexcept;
  void wait(Ty, memory_order = memory_order::seq_cst) const volatile noexcept;
  void wait(Ty, memory_order = memory_order::seq_cst) const noexcept;
  void notify_one() volatile noexcept;
  void notify_one() noexcept;
  void notify_all() volatile noexcept;
  void notify_all() noexcept;
};

template<typename Ty> requires _::is_integral_v<Ty> struct atomic<Ty> {
  using value_type = Ty;
  using difference_type = value_type;
  static constexpr bool is_always_lock_free = false;
  bool is_lock_free() const volatile noexcept;
  bool is_lock_free() const noexcept;
  constexpr atomic() noexcept;
  constexpr atomic(Ty) noexcept;
  atomic(const atomic&) = delete;
  atomic& operator=(const atomic&) = delete;
  atomic& operator=(const atomic&) volatile = delete;
  void store(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  void store(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty operator=(Ty) volatile noexcept;
  Ty operator=(Ty) noexcept;
  Ty load(memory_order = memory_order::seq_cst) const volatile noexcept;
  Ty load(memory_order = memory_order::seq_cst) const noexcept;
  operator Ty() const volatile noexcept;
  operator Ty() const noexcept;
  Ty exchange(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty exchange(Ty, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order, memory_order) noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order, memory_order) noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty fetch_add(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty fetch_add(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty fetch_sub(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty fetch_sub(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty fetch_and(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty fetch_and(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty fetch_or(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty fetch_or(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty fetch_xor(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty fetch_xor(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty operator++(int) volatile noexcept;
  Ty operator++(int) noexcept;
  Ty operator--(int) volatile noexcept;
  Ty operator--(int) noexcept;
  Ty operator++() volatile noexcept;
  Ty operator++() noexcept;
  Ty operator--() volatile noexcept;
  Ty operator--() noexcept;
  Ty operator+=(Ty) volatile noexcept;
  Ty operator+=(Ty) noexcept;
  Ty operator-=(Ty) volatile noexcept;
  Ty operator-=(Ty) noexcept;
  Ty operator&=(Ty) volatile noexcept;
  Ty operator&=(Ty) noexcept;
  Ty operator|=(Ty) volatile noexcept;
  Ty operator|=(Ty) noexcept;
  Ty operator^=(Ty) volatile noexcept;
  Ty operator^=(Ty) noexcept;
  void wait(Ty, memory_order = memory_order::seq_cst) const volatile noexcept;
  void wait(Ty, memory_order = memory_order::seq_cst) const noexcept;
  void notify_one() volatile noexcept;
  void notify_one() noexcept;
  void notify_all() volatile noexcept;
  void notify_all() noexcept;
};

template<typename Ty> requires _::is_floating_point_v<Ty> struct atomic<Ty> {
  using value_type = Ty;
  using difference_type = value_type;
  static constexpr bool is_always_lock_free = false;
  bool is_lock_free() const volatile noexcept;
  bool is_lock_free() const noexcept;
  constexpr atomic() noexcept;
  constexpr atomic(Ty) noexcept;
  atomic(const atomic&) = delete;
  atomic& operator=(const atomic&) = delete;
  atomic& operator=(const atomic&) volatile = delete;
  void store(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  void store(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty operator=(Ty) volatile noexcept;
  Ty operator=(Ty) noexcept;
  Ty load(memory_order = memory_order::seq_cst) volatile noexcept;
  Ty load(memory_order = memory_order::seq_cst) noexcept;
  operator Ty() volatile noexcept;
  operator Ty() noexcept;
  Ty exchange(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty exchange(Ty, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order, memory_order) noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order, memory_order) noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_weak(Ty&, Ty, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_strong(Ty&, Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty fetch_add(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty fetch_add(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty fetch_sub(Ty, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty fetch_sub(Ty, memory_order = memory_order::seq_cst) noexcept;
  Ty operator+=(Ty) volatile noexcept;
  Ty operator+=(Ty) noexcept;
  Ty operator-=(Ty) volatile noexcept;
  Ty operator-=(Ty) noexcept;
  void wait(Ty, memory_order = memory_order::seq_cst) const volatile noexcept;
  void wait(Ty, memory_order = memory_order::seq_cst) const noexcept;
  void notify_one() volatile noexcept;
  void notify_one() noexcept;
  void notify_all() volatile noexcept;
  void notify_all() noexcept;
};

template<class Ty> struct atomic<Ty*> {
  using value_type = Ty*;
  using difference_type = ptrdiff_t;
  static constexpr bool is_always_lock_free = false;
  bool is_lock_free() const volatile noexcept;
  bool is_lock_free() const noexcept;
  constexpr atomic() noexcept;
  constexpr atomic(Ty*) noexcept;
  atomic(const atomic&) = delete;
  atomic& operator=(const atomic&) = delete;
  atomic& operator=(const atomic&) volatile = delete;
  void store(Ty*, memory_order = memory_order::seq_cst) volatile noexcept;
  void store(Ty*, memory_order = memory_order::seq_cst) noexcept;
  Ty* operator=(Ty*) volatile noexcept;
  Ty* operator=(Ty*) noexcept;
  Ty* load(memory_order = memory_order::seq_cst) const volatile noexcept;
  Ty* load(memory_order = memory_order::seq_cst) const noexcept;
  operator Ty*() const volatile noexcept;
  operator Ty*() const noexcept;
  Ty* exchange(Ty*, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty* exchange(Ty*, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_weak(Ty*&, Ty*, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_weak(Ty*&, Ty*, memory_order, memory_order) noexcept;
  bool compare_exchange_strong(Ty*&, Ty*, memory_order, memory_order) volatile noexcept;
  bool compare_exchange_strong(Ty*&, Ty*, memory_order, memory_order) noexcept;
  bool compare_exchange_weak(Ty*&, Ty*, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_weak(Ty*&, Ty*, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_strong(Ty*&, Ty*, memory_order = memory_order::seq_cst) volatile noexcept;
  bool compare_exchange_strong(Ty*&, Ty*, memory_order = memory_order::seq_cst) noexcept;
  Ty* fetch_add(ptrdiff_t, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty* fetch_add(ptrdiff_t, memory_order = memory_order::seq_cst) noexcept;
  Ty* fetch_sub(ptrdiff_t, memory_order = memory_order::seq_cst) volatile noexcept;
  Ty* fetch_sub(ptrdiff_t, memory_order = memory_order::seq_cst) noexcept;
  Ty* operator++(int) volatile noexcept;
  Ty* operator++(int) noexcept;
  Ty* operator--(int) volatile noexcept;
  Ty* operator--(int) noexcept;
  Ty* operator++() volatile noexcept;
  Ty* operator++() noexcept;
  Ty* operator--() volatile noexcept;
  Ty* operator--() noexcept;
  Ty* operator+=(ptrdiff_t) volatile noexcept;
  Ty* operator+=(ptrdiff_t) noexcept;
  Ty* operator-=(ptrdiff_t) volatile noexcept;
  Ty* operator-=(ptrdiff_t) noexcept;
  void wait(Ty*, memory_order = memory_order::seq_cst) const volatile noexcept;
  void wait(Ty*, memory_order = memory_order::seq_cst) const noexcept;
  void notify_one() volatile noexcept;
  void notify_one() noexcept;
  void notify_all() volatile noexcept;
  void notify_all() noexcept;
};

}
