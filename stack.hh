// ywstd/stack.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <stack>
#else

#include "@/../compare.hh"
#include "@/../deque.hh"
#include "@/../initializer_list.hh"
#include "@/uses_allocator.hh"

namespace std {

template<typename Ty, typename Cont = deque<Ty>> class stack {
public:
  using value_type = typename Cont::value_type;
  using reference = typename Cont::reference;
  using const_reference = typename Cont::const_reference;
  using size_type = typename Cont::size_type;
  using container_type = Cont;

protected:
  Cont c;

public:
  stack() : stack(Cont()) {}
  explicit stack(const Cont&);
  explicit stack(Cont&&);
  template<typename InpIt> stack(InpIt first, InpIt last);
  template<typename Al> explicit stack(const Al&);
  template<typename Al> stack(const Cont&, const Al&);
  template<typename Al> stack(Cont&&, const Al&);
  template<typename Al> stack(const stack&, const Al&);
  template<typename Al> stack(stack&&, const Al&);
  template<typename InpIt, typename Al> stack(InpIt first, InpIt last, const Al&);

  [[nodiscard]] bool empty() const { return c.empty(); }
  size_type size() const { return c.size(); }
  reference top() { return c.back(); }
  const_reference top() const { return c.back(); }
  void push(const value_type& x) { c.push_back(x); }
  void push(value_type&& x) { c.push_back(_::move(x)); }
  template<typename... As> decltype(auto) emplace(As&&... Args) { return c.emplace_back(_::forward<As>(Args)...); }
  void pop() { c.pop_back(); }
  void swap(stack& s) noexcept(_::is_nothrow_swappable_v<Cont>) { ranges::swap(c, s.c); }
};

template<typename Cont>
stack(Cont)
  -> stack<typename Cont::value_type, Cont>;

template<typename InpIt>
stack(InpIt, InpIt)
  -> stack<typename iterator_traits<InpIt>::value_type>;

template<typename Cont, typename Al>
stack(Cont, Al)
  -> stack<typename Cont::value_type, Cont>;

template<typename InpIt, typename Al>
stack(InpIt, InpIt, Al)
  -> stack<typename iterator_traits<InpIt>::value_type,
           deque<typename iterator_traits<InpIt>::value_type,
                 Al>>;

template<typename Ty, typename Cont, typename Al>
struct uses_allocator<stack<Ty, Cont>, Al> : uses_allocator<Cont, Al>::type {};

template<typename Ty, typename Cont> bool operator==(const stack<Ty, Cont>& x, const stack<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator!=(const stack<Ty, Cont>& x, const stack<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator<(const stack<Ty, Cont>& x, const stack<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator>(const stack<Ty, Cont>& x, const stack<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator<=(const stack<Ty, Cont>& x, const stack<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator>=(const stack<Ty, Cont>& x, const stack<Ty, Cont>& y);

template<typename Ty, three_way_comparable Cont> compare_three_way_result_t<Cont>
operator<=>(const stack<Ty, Cont>& x, const stack<Ty, Cont>& y);

template<typename Ty, typename Cont> void swap(stack<Ty, Cont>& x, stack<Ty, Cont>& y) noexcept(noexcept(x.swap(y)));

}

#endif
