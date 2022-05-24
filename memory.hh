// ywstd/memory.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <memory>
#else

#include "@/../compare.hh"
#include "@/../exception.hh"
#include "@/../execution.hh"
#include "@/../iosfwd.hh"
#include "@/../type_traits.hh"
#include "@/../tuple.hh"
#include "@/allocator.hh"
#include "@/atomic.hh"
#include "@/iterator-concepts.hh"
#include "@/pair.hh"
#include "@/pointer_traits.hh"
#include "@/ranges-concepts.hh"
#include "@/ranges-subrange.hh"
#include "@/ranges-in_out_result.hh"
#include "@/to_address.hh"
#include "@/unique_ptr.hh"
#include "@/uses_allocator.hh"

namespace std {

template<typename Al> [[nodiscard]] constexpr allocation_result<typename allocator_traits<Al>::pointer> allocate_at_least(Al& a, size_t n) {
  if constexpr (requires { a.allocate_at_least(n); }) return a.allocate_at_least(n);
  else return {a.allocate(n), n};
}

class bad_weak_ptr : public exception {
public:
  bad_weak_ptr() noexcept;
};

template<typename Ty, typename... As> unique_ptr<Ty> make_unique(As&&... as);
template<typename Ty> unique_ptr<Ty> make_unique(size_t n);
template<typename Ty, typename... As> void make_unique(As&&...) = delete;

template<typename Ty> unique_ptr<Ty> make_unique_for_overwrite();
template<typename Ty> unique_ptr<Ty> make_unique_for_overwrite(size_t n);
template<typename Ty, typename... As> void make_unique_for_overwrite(As&&...) = delete;

template<typename Ty, typename Dl> void swap(unique_ptr<Ty, Dl>& x, unique_ptr<Ty, Dl>& y) noexcept;

template<typename T1, typename D1, typename T2, typename D2> bool operator==(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
template<typename T1, typename D1, typename T2, typename D2> bool operator<(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
template<typename T1, typename D1, typename T2, typename D2> bool operator>(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
template<typename T1, typename D1, typename T2, typename D2> bool operator<=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
template<typename T1, typename D1, typename T2, typename D2> bool operator>=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);

template<typename T1, typename D1, typename T2, typename D2>
requires three_way_comparable_with<typename unique_ptr<T1, D1>::pointer, typename unique_ptr<T2, D2>::pointer>
compare_three_way_result_t<typename unique_ptr<T1, D1>::pointer, typename unique_ptr<T2, D2>::pointer>
operator<=>(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);

template<typename Ty, typename Dl> bool operator==(const unique_ptr<Ty, Dl>& x, nullptr_t) noexcept;
template<typename Ty, typename Dl> bool operator<(const unique_ptr<Ty, Dl>& x, nullptr_t);
template<typename Ty, typename Dl> bool operator<(nullptr_t, const unique_ptr<Ty, Dl>& y);
template<typename Ty, typename Dl> bool operator>(const unique_ptr<Ty, Dl>& x, nullptr_t);
template<typename Ty, typename Dl> bool operator>(nullptr_t, const unique_ptr<Ty, Dl>& y);
template<typename Ty, typename Dl> bool operator<=(const unique_ptr<Ty, Dl>& x, nullptr_t);
template<typename Ty, typename Dl> bool operator<=(nullptr_t, const unique_ptr<Ty, Dl>& y);
template<typename Ty, typename Dl> bool operator>=(const unique_ptr<Ty, Dl>& x, nullptr_t);
template<typename Ty, typename Dl> bool operator>=(nullptr_t, const unique_ptr<Ty, Dl>& y);
template<typename Ty, typename Dl> requires three_way_comparable<typename unique_ptr<Ty, Dl>::pointer>
compare_three_way_result_t<typename unique_ptr<Ty, Dl>::pointer> operator<=>(const unique_ptr<Ty, Dl>& x, nullptr_t);

template<typename E, typename Ty, typename Y, typename Dl>
basic_ostream<E, Ty>& operator<<(basic_ostream<E, Ty>& os, const unique_ptr<Y, Dl>& p);

template<typename Ty> class shared_ptr;

template<typename Ty> class weak_ptr {
public:
  using element_type = typename remove_extent<Ty>::type;
  ~weak_ptr();
  constexpr weak_ptr() noexcept {}
  template<typename Uy> weak_ptr(const shared_ptr<Uy>& r) noexcept;
  weak_ptr(const weak_ptr& r) noexcept;
  template<typename Uy> weak_ptr(const weak_ptr<Uy>& r) noexcept;
  weak_ptr(weak_ptr&& r) noexcept;
  template<typename Uy> weak_ptr(weak_ptr<Uy>&& r) noexcept;
  weak_ptr& operator=(const weak_ptr& r) noexcept;
  template<typename Uy> weak_ptr& operator=(const weak_ptr<Uy>& r) noexcept;
  template<typename Uy> weak_ptr& operator=(const shared_ptr<Uy>& r) noexcept;
  weak_ptr& operator=(weak_ptr&& r) noexcept;
  template<typename Uy> weak_ptr& operator=(weak_ptr<Uy>&& r) noexcept;
  void swap(weak_ptr& r) noexcept;
  void reset() noexcept;
  long use_count() const noexcept;
  bool expired() const noexcept;
  shared_ptr<Ty> lock() const noexcept;
  template<typename Uy> bool owner_before(const shared_ptr<Uy>& b) const noexcept;
  template<typename Uy> bool owner_before(const weak_ptr<Uy>& b) const noexcept;
};

template<typename Ty> weak_ptr(shared_ptr<Ty>) -> weak_ptr<Ty>;

template<typename Ty> class shared_ptr {
public:
  using element_type = typename remove_extent<Ty>::type;
  using weak_type = weak_ptr<Ty>;
  ~shared_ptr();
  constexpr shared_ptr() noexcept {}
  constexpr shared_ptr(nullptr_t) noexcept : shared_ptr() {}
  template<typename Uy> explicit shared_ptr(Uy* p);
  template<typename Uy, typename Dl> shared_ptr(Uy* p, Dl d);
  template<typename Uy, typename Dl, typename Al> shared_ptr(Uy* p, Dl d, Al a);
  template<typename Dl> shared_ptr(nullptr_t p, Dl d);
  template<typename Dl, typename Al> shared_ptr(nullptr_t p, Dl d, Al a);
  template<typename Uy> shared_ptr(const shared_ptr<Uy>& r, element_type* p) noexcept;
  template<typename Uy> shared_ptr(shared_ptr<Uy>&& r, element_type* p) noexcept;
  shared_ptr(const shared_ptr& r) noexcept;
  template<typename Uy> shared_ptr(const shared_ptr<Uy>& r) noexcept;
  shared_ptr(shared_ptr&& r) noexcept;
  template<typename Uy> shared_ptr(shared_ptr<Uy>&& r) noexcept;
  template<typename Uy> explicit shared_ptr(const weak_ptr<Uy>& r);
  template<typename Uy, typename Dl> shared_ptr(unique_ptr<Uy, Dl>&& r);
  shared_ptr& operator=(const shared_ptr& r) noexcept;
  template<typename Uy> shared_ptr& operator=(const shared_ptr<Uy>& r) noexcept;
  shared_ptr& operator=(shared_ptr&& r) noexcept;
  template<typename Uy> shared_ptr& operator=(shared_ptr<Uy>&& r) noexcept;
  template<typename Uy, typename Dl> shared_ptr& operator=(unique_ptr<Uy, Dl>&& r);
  void swap(shared_ptr& r) noexcept;
  void reset() noexcept;
  template<typename Uy> void reset(Uy* p);
  template<typename Uy, typename Dl> void reset(Uy* p, Dl d);
  template<typename Uy, typename Dl, typename Al> void reset(Uy* p, Dl d, Al a);
  element_type* get() const noexcept;
  Ty& operator*() const noexcept;
  Ty* operator->() const noexcept;
  element_type& operator[](ptrdiff_t i) const;
  long use_count() const noexcept;
  explicit operator bool() const noexcept;
  template<typename Uy> bool owner_before(const shared_ptr<Uy>& b) const noexcept;
  template<typename Uy> bool owner_before(const weak_ptr<Uy>& b) const noexcept;
};

template<typename Ty> shared_ptr(weak_ptr<Ty>) -> shared_ptr<Ty>;
template<typename Ty, typename Dl> shared_ptr(unique_ptr<Ty, Dl>) -> shared_ptr<Ty>;

template<typename Ty> struct atomic<shared_ptr<Ty>> {
  using value_type = shared_ptr<Ty>;
  static constexpr bool is_always_lock_free = false;
  constexpr atomic() noexcept = default;
  constexpr atomic(nullptr_t) noexcept : atomic{} {}
  atomic(shared_ptr<Ty>) noexcept;
  atomic(const atomic&) = delete;
  void operator=(const atomic&) = delete;
  void operator=(shared_ptr<Ty>) noexcept;
  bool is_lock_free() const noexcept;
  void store(shared_ptr<Ty>, memory_order = memory_order::seq_cst) noexcept;
  shared_ptr<Ty> load(memory_order = memory_order::seq_cst) const noexcept;
  operator shared_ptr<Ty>() const noexcept;
  shared_ptr<Ty> exchange(shared_ptr<Ty>, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_strong(shared_ptr<Ty>&, shared_ptr<Ty>, memory_order, memory_order) noexcept;
  bool compare_exchange_weak(shared_ptr<Ty>&, shared_ptr<Ty>, memory_order, memory_order) noexcept;
  bool compare_exchange_strong(shared_ptr<Ty>&, shared_ptr<Ty>, memory_order= memory_order::seq_cst) noexcept;
  bool compare_exchange_weak(shared_ptr<Ty>&, shared_ptr<Ty>, memory_order = memory_order::seq_cst) noexcept;
  void wait(shared_ptr<Ty>, memory_order = memory_order::seq_cst) const noexcept;
  void notify_one() noexcept;
  void notify_all() noexcept;
};

template<typename Ty> struct atomic<weak_ptr<Ty>> {
  using value_type = weak_ptr<Ty>;
  static constexpr bool is_always_lock_free = false;
  constexpr atomic() noexcept = default;
  atomic(weak_ptr<Ty>) noexcept;
  atomic(const atomic&) = delete;
  void operator=(const atomic&) = delete;
  void operator=(weak_ptr<Ty>) noexcept;
  bool is_lock_free() const noexcept;
  void store(weak_ptr<Ty>, memory_order = memory_order::seq_cst) noexcept;
  weak_ptr<Ty> load(memory_order = memory_order::seq_cst) const noexcept;
  operator weak_ptr<Ty>() const noexcept;
  weak_ptr<Ty> exchange(weak_ptr<Ty>, memory_order = memory_order::seq_cst) noexcept;
  bool compare_exchange_strong(weak_ptr<Ty>&, weak_ptr<Ty>, memory_order, memory_order) noexcept;
  bool compare_exchange_weak(weak_ptr<Ty>&, weak_ptr<Ty>, memory_order, memory_order) noexcept;
  bool compare_exchange_strong(weak_ptr<Ty>&, weak_ptr<Ty>, memory_order= memory_order::seq_cst) noexcept;
  bool compare_exchange_weak(weak_ptr<Ty>&, weak_ptr<Ty>, memory_order = memory_order::seq_cst) noexcept;
  void wait(weak_ptr<Ty>, memory_order = memory_order::seq_cst) const noexcept;
  void notify_one() noexcept;
  void notify_all() noexcept;
};

using std::uses_allocator;
template<typename Ty, typename Al> inline constexpr bool uses_allocator_v = uses_allocator<Ty, Al>::value;

template<typename Ty, typename Al, typename... As> constexpr auto uses_allocator_construction_args(const Al& al, As&&... as) noexcept
  requires (!_::specialized_of<Ty, pair>) {
  if constexpr (!uses_allocator_v<Ty, Al> && _::is_constructible_v<Ty, As...>) return _::forward_as_tuple(forward<As>(as)...);
  else if constexpr (uses_allocator_v<Ty, Al> && _::is_constructible_v<Ty, allocator_arg_t, const Al&, As...>)
    return tuple<allocator_arg_t, const Al&, As&&...>(allocator_arg, al, _::forward<As>(as)...);
  else if constexpr (uses_allocator_v<Ty, Al> && _::is_constructible_v<Ty, As..., Al>) return _::forward_as_tuple(_::forward<As>(as)..., al);
}
template<_::specialized_of<pair> Ty, typename Al, typename Tp1, typename Tp2>
constexpr auto uses_allocator_construction_args(const Al& al, piecewise_construct_t, Tp1&& t1, Tp2&& t2) noexcept {
  return _::make_tuple(piecewise_construct_t{},
    _::apply([&al]<typename... As>(As&&... as) { return std::uses_allocator_construction_args<Tp1>(al, _::forward<As>(as)...); }, _::forward<Tp1>(t1)),
    _::apply([&al]<typename... As>(As&&... as) { return std::uses_allocator_construction_args<Tp2>(al, _::forward<As>(as)...); }, _::forward<Tp2>(t2)));
}
template<_::specialized_of<pair> Ty, typename Al> constexpr auto uses_allocator_construction_args(const Al& al) noexcept {
  return std::uses_allocator_construction_args<Ty>(al, piecewise_construct_t{}, tuple<>{}, tuple<>{});
}
template<_::specialized_of<pair> Ty, typename Al, typename U1, typename U2>
constexpr auto uses_allocator_construction_args(const Al& al, U1&& u1, U2&& u2) noexcept {
  return std::uses_allocator_construction_args<Ty>(al, piecewise_construct_t{}, _::forward_as_tuple(_::forward<U1>(u1)), _::forward_as_tuple(_::forward<U2>(u2)));
}
template<_::specialized_of<pair> Ty, typename Al, typename U1, typename U2>
constexpr auto uses_allocator_construction_args(const Al& al, pair<U1, U2>& p) noexcept {
  return std::uses_allocator_construction_args<Ty>(al, piecewise_construct_t{}, _::forward_as_tuple(p.first), _::forward_as_tuple(p.second));
}
template<_::specialized_of<pair> Ty, typename Al, typename U1, typename U2>
constexpr auto uses_allocator_construction_args(const Al& al, const pair<U1, U2>& p) noexcept {
  return std::uses_allocator_construction_args<Ty>(al, piecewise_construct_t{}, _::forward_as_tuple(p.first), _::forward_as_tuple(p.second));
}
template<_::specialized_of<pair> Ty, typename Al, typename U1, typename U2>
constexpr auto uses_allocator_construction_args(const Al& al, pair<U1, U2>&& p) noexcept {
  return std::uses_allocator_construction_args<Ty>(al, piecewise_construct_t{}, _::forward_as_tuple(_::move(p.first)), _::forward_as_tuple(_::move(p.second)));
}
template<_::specialized_of<pair> Ty, typename Al, typename U1, typename U2>
constexpr auto uses_allocator_construction_args(const Al& al, const pair<U1, U2>&& p) noexcept {
  return std::uses_allocator_construction_args<Ty>(al, piecewise_construct_t{}, _::forward_as_tuple(_::move(p.first)), _::forward_as_tuple(_::move(p.second)));
}

template<typename Ty, typename Al, typename... As> constexpr Ty make_obj_using_allocator(const Al& al, As&&... as) {
  return _::make_from_tuple<Ty>(uses_allocator_construction_args<Ty>(al, _::forward<As>(as)...));
}

namespace _ {
  template<typename T1, typename T2> void deduce_as_pair(const pair<T1, T2>&);
  template<typename Ty, typename Al, typename Uy> class pair_constructor {
    const Al& _al;
    Uy& _u;
    constexpr auto reconstruct(const remove_cv_t<Ty>& t) const { return std::make_obj_using_allocator<remove_cv_t<Ty>>(_al, t); }
    constexpr auto reconstruct(remove_cv_t<Ty>&& t) const { return std::make_obj_using_allocator<remove_cv_t<Ty>>(_al, _::move(t)); }
  public:
    constexpr pair_constructor(const Al& al, Uy& u) : _al{al}, _u{u} {}
    constexpr operator typename remove_cv<Ty>::type() const { return reconstruct(_::forward<Uy>(_u)); }
  };
}

template<_::specialized_of<pair> Ty, typename Al, typename Uy>
constexpr auto uses_allocator_construction_args(const Al& al, Uy&& u) noexcept requires (!requires { _::deduce_as_pair(u); }) {
  return _::make_tuple(_::pair_constructor<Ty, Al, Uy>{al, u});
}

}

namespace std {

void* align(size_t alignment, size_t size, void*& ptr, size_t& space);
template<size_t Nx, typename Ty> [[nodiscard]] constexpr Ty* assume_aligned(Ty* ptr) { return ptr; }
template<typename Ty, typename Al, typename... As> constexpr Ty make_obj_using_allocator(const Al& alloc, As&&... as);
template<typename Ty, typename Al, typename... As> constexpr Ty* uninitialized_construct_using_allocator(Ty* p, const Al& alloc, As&&... as);

template<typename Ty> constexpr Ty* addressof(Ty& r) noexcept { return _::addressof(r); }
template<typename Ty> const Ty* addressof(const Ty&&) = delete;

namespace _ {
  template<typename Se, typename It> concept no_throw_sentinel_for = sentinel_for<Se, It>;
  template<typename It> concept no_throw_input_iterator =
    input_iterator<It> && is_lvalue_reference_v<iter_reference_t<It>> && same_as<remove_cvref_t<iter_reference_t<It>>, iter_value_t<It>>;
  template<typename Rg> concept no_throw_input_range =
    ranges::range<Rg> && no_throw_input_iterator<ranges::iterator_t<Rg>> && no_throw_sentinel_for<ranges::sentinel_t<Rg>, ranges::iterator_t<Rg>>;
  template<typename It> concept no_throw_forward_iterator = no_throw_input_iterator<It> && forward_iterator<It> && no_throw_sentinel_for<It, It>;
  template<typename Rg> concept no_throw_forward_range = no_throw_input_range<Rg> && no_throw_forward_iterator<ranges::iterator_t<Rg>>;
}

template<typename FwdIt> void uninitialized_default_construct(FwdIt first, FwdIt last);
template<_::execution_policy Ex, typename FwdIt> void uninitialized_default_construct(Ex&& exec, FwdIt first, FwdIt last);
template<typename FwdIt, typename Size> FwdIt uninitialized_default_construct_n(FwdIt first, Size n);
template<_::execution_policy Ex, typename FwdIt, typename Size> FwdIt uninitialized_default_construct_n(Ex&& exec, FwdIt first, Size n);

namespace ranges {
  template<typename Rg> using iterator_t = decltype(ranges::begin(declval<Rg&>()));
  template<range Rg> using borrowed_iterator_t = conditional_t<borrowed_range<Rg>, iterator_t<Rg>, dangling>;

  template<_::no_throw_forward_iterator It, _::no_throw_sentinel_for<It> Se> requires default_initializable<iter_value_t<It>>
  It uninitialized_default_construct(It first, Se last);

  template<_::no_throw_forward_range Rg> requires default_initializable<ranges::range_value_t<Rg>>
  borrowed_iterator_t<Rg> uninitialized_default_construct(Rg&& r);

  template<_::no_throw_forward_iterator It> requires default_initializable<iter_value_t<It>>
  It uninitialized_default_construct_n(It first, iter_difference_t<It> n);
}

template<typename FwdIt> void uninitialized_value_construct(FwdIt first, FwdIt last);
template<_::execution_policy Ex, typename FwdIt> void uninitialized_value_construct(Ex&& exec, FwdIt first, FwdIt last);
template<typename FwdIt, typename Size> FwdIt uninitialized_value_construct_n(FwdIt first, Size n);
template<_::execution_policy Ex, typename FwdIt, typename Size> FwdIt uninitialized_value_construct_n(Ex&& exec, FwdIt first, Size n);

namespace ranges {
  template<_::no_throw_forward_iterator It, _::no_throw_sentinel_for<It> Se> requires default_initializable<iter_value_t<It>>
  It uninitialized_value_construct(It first, Se last);

  template<_::no_throw_forward_range Rg> requires default_initializable<ranges::range_value_t<Rg>>
  borrowed_iterator_t<Rg> uninitialized_value_construct(Rg&& r);

  template<_::no_throw_forward_iterator It> requires default_initializable<iter_value_t<It>>
  It uninitialized_value_construct_n(It first, iter_difference_t<It> n);
}

template<typename InpIt, typename FwdIt> FwdIt uninitialized_copy(InpIt first, InpIt last, FwdIt result);
template<_::execution_policy Ex, typename FwdIt, typename FwdOt> FwdOt uninitialized_copy(Ex&& exec, FwdIt first, FwdIt last, FwdOt result);
template<typename InpIt, typename Size, typename FwdOt> FwdOt uninitialized_copy_n(InpIt first, Size n, FwdOt result);
template<_::execution_policy Ex, typename FwdIt, typename Size, typename FwdOt> FwdOt uninitialized_copy_n(Ex&& exec, FwdIt first, Size n, FwdOt result);

namespace ranges {
  template<typename It, typename Ot> using uninitialized_copy_result = in_out_result<It, Ot>;
  template<typename It, typename Ot> using uninitialized_copy_n_result = in_out_result<It, Ot>;

  template<input_iterator It, sentinel_for<It> S1, _::no_throw_forward_iterator Ot, _::no_throw_sentinel_for<Ot> S2>
  requires constructible_from<iter_value_t<Ot>, iter_reference_t<It>>
  uninitialized_copy_result<It, Ot> uninitialized_copy(It ifirst, S1 ilast, Ot ofirst, S2 olast);

  template<input_range Rg, _::no_throw_forward_range OutRg>
  requires constructible_from<ranges::range_value_t<OutRg>, ranges::range_reference_t<Rg>>
  uninitialized_copy_result<borrowed_iterator_t<Rg>, borrowed_iterator_t<OutRg>> uninitialized_copy(Rg&& in_range, OutRg&& out_range);

  template<input_iterator It, _::no_throw_forward_iterator Ot, _::no_throw_sentinel_for<Ot> Se>
  requires constructible_from<iter_value_t<Ot>, iter_reference_t<It>>
  uninitialized_copy_n_result<It, Ot> uninitialized_copy_n(It ifirst, iter_difference_t<It> n, Ot ofirst, Se olast);
}

template<typename InpIt, typename FwdOt> FwdOt uninitialized_move(InpIt first, InpIt last, FwdOt result);
template<_::execution_policy Ex, typename FwdIt, typename FwdOt> FwdOt uninitialized_move(Ex&& exec, FwdIt first, FwdIt last, FwdOt result);
template<typename InpIt, typename Size, typename FwdOt> pair<InpIt, FwdOt> uninitialized_move_n(InpIt first, Size n, FwdOt result);

template<_::execution_policy Ex, typename FwdIt, typename Size, typename FwdOt>
pair<FwdIt, FwdOt> uninitialized_move_n(Ex&& exec, FwdIt first, Size n, FwdOt result);

namespace ranges {
  template<typename It, typename Ot> using uninitialized_move_result = in_out_result<It, Ot>;
  template<typename It, typename Ot> using uninitialized_move_n_result = in_out_result<It, Ot>;

  template<input_iterator It, sentinel_for<It> S1, _::no_throw_forward_iterator Ot, _::no_throw_sentinel_for<Ot> S2>
  requires constructible_from<iter_value_t<Ot>, iter_rvalue_reference_t<It>>
  uninitialized_move_result<It, Ot> uninitialized_move(It ifirst, S1 ilast, Ot ofirst, S2 olast);

  template<input_range Rg, _::no_throw_forward_range OutRg>
  requires constructible_from<ranges::range_value_t<OutRg>, ranges::range_rvalue_reference_t<Rg>>
  uninitialized_move_result<borrowed_iterator_t<Rg>, borrowed_iterator_t<OutRg>> uninitialized_move(Rg&& in_range, OutRg&& out_range);

  template<input_iterator It, _::no_throw_forward_iterator Ot, _::no_throw_sentinel_for<Ot> Se>
  requires constructible_from<iter_value_t<Ot>, iter_rvalue_reference_t<It>>
  uninitialized_move_n_result<It, Ot> uninitialized_move_n(It ifirst, iter_difference_t<It> n, Ot ofirst, Se olast);
}

template<typename FwdOt, typename Ty> void uninitialized_fill(FwdOt first, FwdOt last, const Ty& x);
template<_::execution_policy Ex, typename FwdOt, typename Ty> void uninitialized_fill(Ex&& exec, FwdOt first, FwdOt last, const Ty& x);
template<typename FwdOt, typename Size, typename Ty> FwdOt uninitialized_fill_n(FwdOt first, Size n, const Ty& x);
template<_::execution_policy Ex, typename FwdOt, typename Size, typename Ty> FwdOt uninitialized_fill_n(Ex&& exec, FwdOt first, Size n, const Ty& x);

namespace ranges {
  template<_::no_throw_forward_iterator It, _::no_throw_sentinel_for<It> Se, typename Ty>
  requires constructible_from<iter_value_t<It>, const Ty&>
  It uninitialized_fill(It first, Se last, const Ty& x);

  template<_::no_throw_forward_range R, typename Ty>
  requires constructible_from<ranges::range_value_t<R>, const Ty&>
  borrowed_iterator_t<R> uninitialized_fill(R&& r, const Ty& x);

  template<_::no_throw_forward_iterator It, typename Ty>
  requires constructible_from<iter_value_t<It>, const Ty&>
  It uninitialized_fill_n(It first, iter_difference_t<It> n, const Ty& x);
}

template<typename Ty, typename... As> constexpr Ty* construct_at(Ty* p, As&&... as) { return _::_allocator_traits::construct_at(p, static_cast<As&&>(as)...); }

namespace ranges {
  template<typename Ty, typename... As> constexpr Ty* construct_at(Ty* location, As&&... as);
}

template<typename Ty> constexpr void destroy_at(Ty* location);
template<typename FwdOt> constexpr void destroy(FwdOt first, FwdOt last);
template<_::execution_policy Ex, typename FwdOt> void destroy(Ex&& exec, FwdOt first, FwdOt last);
template<typename FwdOt, typename Size> constexpr FwdOt destroy_n(FwdOt first, Size n);
template<_::execution_policy Ex, typename FwdOt, typename Size> FwdOt destroy_n(Ex&& exec, FwdOt first, Size n);

namespace ranges {
  template<destructible Ty> constexpr void destroy_at(Ty* location) noexcept;

  template<_::no_throw_input_iterator It, _::no_throw_sentinel_for<It> Se>
  requires destructible<iter_value_t<It>>
  constexpr It destroy(It first, Se last) noexcept;

  template<_::no_throw_input_range Rg>
  requires destructible<ranges::range_value_t<Rg>>
  constexpr borrowed_iterator_t<Rg> destroy(Rg&& r) noexcept;

  template<_::no_throw_input_iterator It>
  requires destructible<iter_value_t<It>>
  constexpr It destroy_n(It first, iter_difference_t<It> n) noexcept;
}

template<typename Ty, typename... As> shared_ptr<Ty> make_shared(As&&... as);
template<typename Ty, typename Al, typename... As> shared_ptr<Ty> allocate_shared(const Al& al, As&&... as);
template<typename Ty> shared_ptr<Ty> make_shared(size_t Nx);
template<typename Ty, typename Al> shared_ptr<Ty> allocate_shared(const Al& al, size_t Nx);
template<typename Ty> shared_ptr<Ty> make_shared();
template<typename Ty, typename Al> shared_ptr<Ty> allocate_shared(const Al& al);
template<typename Ty> shared_ptr<Ty> make_shared(size_t Nx, const typename remove_extent<Ty>::type& u);
template<typename Ty, typename Al> shared_ptr<Ty> allocate_shared(const Al& al, size_t Nx, const typename remove_extent<Ty>::type& u);
template<typename Ty> shared_ptr<Ty> make_shared(const typename remove_extent<Ty>::type& u);
template<typename Ty, typename Al> shared_ptr<Ty> allocate_shared(const Al& al, const typename remove_extent<Ty>::type& u);
template<typename Ty> shared_ptr<Ty> make_shared_for_overwrite();
template<typename Ty, typename Al> shared_ptr<Ty> allocate_shared_for_overwrite(const Al& al);
template<typename Ty> shared_ptr<Ty> make_shared_for_overwrite(size_t Nx);
template<typename Ty, typename Al> shared_ptr<Ty> allocate_shared_for_overwrite(const Al& al, size_t Nx);

template<typename Ty, typename Uy> bool operator==(const shared_ptr<Ty>& a, const shared_ptr<Uy>& b) noexcept;
template<typename Ty> bool operator==(const shared_ptr<Ty>& x, nullptr_t) noexcept;
template<typename Ty, typename Uy> strong_ordering operator<=>(const shared_ptr<Ty>& a, const shared_ptr<Uy>& b) noexcept;
template<typename Ty> strong_ordering operator<=>(const shared_ptr<Ty>& x, nullptr_t) noexcept;
template<typename Ty> void swap(shared_ptr<Ty>& a, shared_ptr<Ty>& b) noexcept;

template<typename Ty, typename Uy> shared_ptr<Ty> static_pointer_cast(const shared_ptr<Uy>& r) noexcept;
template<typename Ty, typename Uy> shared_ptr<Ty> static_pointer_cast(shared_ptr<Uy>&& r) noexcept;
template<typename Ty, typename Uy> shared_ptr<Ty> dynamic_pointer_cast(const shared_ptr<Uy>& r) noexcept;
template<typename Ty, typename Uy> shared_ptr<Ty> dynamic_pointer_cast(shared_ptr<Uy>&& r) noexcept;
template<typename Ty, typename Uy> shared_ptr<Ty> const_pointer_cast(const shared_ptr<Uy>& r) noexcept;
template<typename Ty, typename Uy> shared_ptr<Ty> const_pointer_cast(shared_ptr<Uy>&& r) noexcept;
template<typename Ty, typename Uy> shared_ptr<Ty> reinterpret_pointer_cast(const shared_ptr<Uy>& r) noexcept;
template<typename Ty, typename Uy> shared_ptr<Ty> reinterpret_pointer_cast(shared_ptr<Uy>&& r) noexcept;

template<typename Dl, typename Ty> Dl* get_deleter(const shared_ptr<Ty>& p) noexcept;
template<typename Ct, typename Tr, typename Ty> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const shared_ptr<Ty>& p);

template<typename Ty> void swap(weak_ptr<Ty>& a, weak_ptr<Ty>& b) noexcept;

template<typename Ty = void> struct owner_less;
template<typename Ty> struct owner_less<shared_ptr<Ty>> {
  bool operator()(const shared_ptr<Ty>&, const shared_ptr<Ty>&) const noexcept;
  bool operator()(const shared_ptr<Ty>&, const weak_ptr<Ty>&) const noexcept;
  bool operator()(const weak_ptr<Ty>&, const shared_ptr<Ty>&) const noexcept;
};
template<typename Ty> struct owner_less<weak_ptr<Ty>> {
  bool operator()(const weak_ptr<Ty>&, const weak_ptr<Ty>&) const noexcept;
  bool operator()(const shared_ptr<Ty>&, const weak_ptr<Ty>&) const noexcept;
  bool operator()(const weak_ptr<Ty>&, const shared_ptr<Ty>&) const noexcept;
};
template<> struct owner_less<void> {
  using is_transparent = int;
  template<typename Ty, typename Uy> bool operator()(const shared_ptr<Ty>&, const shared_ptr<Uy>&) const noexcept;
  template<typename Ty, typename Uy> bool operator()(const shared_ptr<Ty>&, const weak_ptr<Uy>&) const noexcept;
  template<typename Ty, typename Uy> bool operator()(const weak_ptr<Ty>&, const shared_ptr<Uy>&) const noexcept;
  template<typename Ty, typename Uy> bool operator()(const weak_ptr<Ty>&, const weak_ptr<Uy>&) const noexcept;
};

template<typename Ty> class enable_shared_from_this {
protected:
  ~enable_shared_from_this();
  constexpr enable_shared_from_this() noexcept;
  enable_shared_from_this(const enable_shared_from_this&) noexcept;
  enable_shared_from_this& operator=(const enable_shared_from_this&) noexcept;
public:
  shared_ptr<Ty> shared_from_this();
  shared_ptr<Ty const> shared_from_this() const;
  weak_ptr<Ty> weak_from_this() noexcept;
  weak_ptr<Ty const> weak_from_this() const noexcept;
};

template<typename Ty> struct hash;
template<typename Ty> struct hash<shared_ptr<Ty>> { size_t operator()(const shared_ptr<Ty>&); };
template<typename Ty, typename Dl> struct hash<unique_ptr<Ty, Dl>> { size_t operator()(const unique_ptr<Ty, Dl>&); };

template<typename Smart, typename Pointer, typename... As> class out_ptr_t {
public:
  ~out_ptr_t();
  explicit out_ptr_t(Smart&, As...);
  out_ptr_t(const out_ptr_t&) = delete;
  operator Pointer*() const noexcept;
  operator void**() const noexcept;
};

template<typename Pointer = void, typename Smart, typename... As> auto out_ptr(Smart& s, As&&... as);

template<typename Smart, typename Pointer, typename... As> class inout_ptr_t {
public:
  ~inout_ptr_t();
  explicit inout_ptr_t(Smart&, As...);
  inout_ptr_t(const inout_ptr_t&) = delete;
  operator Pointer*() const noexcept;
  operator void**() const noexcept;
};

template<typename Pointer = void, typename Smart, typename... As> auto inout_ptr(Smart& s, As&&... as);

}

#endif
