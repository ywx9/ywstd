// ywstd/queue.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <queue>
#else

#include "@/../compare.hh"
#include "@/../deque.hh"
#include "@/../initializer_list.hh"
#include "@/../vector.hh"

#include "@/less.hh"
#include "@/uses_allocator.hh"

namespace std {

template<typename Ty, typename Cont = deque<Ty>> class queue {
public:
  using value_type = typename Cont::value_type;
  using reference = typename Cont::reference;
  using const_reference = typename Cont::const_reference;
  using size_type = typename Cont::size_type;
  using container_type = Cont;
protected:
  Cont c;
public:
  queue() : queue(Cont()) {}
  explicit queue(const Cont&);
  explicit queue(Cont &&);
  template<typename InpIt> queue(InpIt first, InpIt last);
  template<typename Al> explicit queue(const Al&);
  template<typename Al> queue(const Cont&, const Al&);
  template<typename Al> queue(Cont&&, const Al&);
  template<typename Al> queue(const queue&, const Al&);
  template<typename Al> queue(queue&&, const Al&);
  template<typename InpIt, typename Al> queue(InpIt first, InpIt last, const Al&);
  [[nodiscard]] bool empty() const { return c.empty(); }
  size_type size() const { return c.size(); }
  reference front() { return c.front(); }
  const_reference front() const { return c.front(); }
  reference back() { return c.back(); }
  const_reference back() const { return c.back(); }
  void push(const value_type& x) { c.push_back(x); }
  void push(value_type && x) { c.push_back(std::move(x)); }
  template<typename... As> decltype(auto) emplace(As&&... args) { return c.emplace_back(_::forward<As>(args)...); }
  void pop() { c.pop_front(); }
  void swap(queue & q) noexcept(_::is_nothrow_swappable_v<Cont>) { ranges::swap(c, q.c); }
};

template<typename Cont> queue(Cont) -> queue<typename Cont::value_type, Cont>;
template<typename InpIt> queue(InpIt, InpIt) -> queue<typename iterator_traits<InpIt>::value_type>;
template<typename Cont, typename Al> queue(Cont, Al) -> queue<typename Cont::value_type, Cont>;
template<typename InpIt, typename Al> queue(InpIt, InpIt, Al)
  -> queue<typename iterator_traits<InpIt>::value_type, deque<typename iterator_traits<InpIt>::value_type, Al>>;

template<typename Ty, typename Cont, typename Al> struct uses_allocator<queue<Ty, Cont>, Al> : uses_allocator<Cont, Al>::type {};

template<typename Ty, typename Cont> bool operator==(const queue<Ty, Cont>& x, const queue<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator!=(const queue<Ty, Cont>& x, const queue<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator<(const queue<Ty, Cont>& x, const queue<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator>(const queue<Ty, Cont>& x, const queue<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator<=(const queue<Ty, Cont>& x, const queue<Ty, Cont>& y);
template<typename Ty, typename Cont> bool operator>=(const queue<Ty, Cont>& x, const queue<Ty, Cont>& y);
template<typename Ty, three_way_comparable Cont> compare_three_way_result_t<Cont> operator<=>(const queue<Ty, Cont>& x, const queue<Ty, Cont>& y);

template<typename Ty, typename Cont> void swap(queue<Ty, Cont>& x, queue<Ty, Cont>& y) noexcept(noexcept(x.swap(y)));

template<typename Ty, typename Cont = vector<Ty>, typename Comp = less<typename Cont::value_type>> class priority_queue {
public:
  using value_type = typename Cont::value_type;
  using reference = typename Cont::reference;
  using const_reference = typename Cont::const_reference;
  using size_type = typename Cont::size_type;
  using container_type = Cont;
  using value_compare = Comp;
protected:
  Cont c;
  Comp comp;
public:
  priority_queue() : priority_queue(Comp()) {}
  explicit priority_queue(const Comp& x) : priority_queue(x, Cont()) {}
  priority_queue(const Comp& x, const Cont&);
  priority_queue(const Comp& x, Cont&&);
  template<typename InpIt> priority_queue(InpIt first, InpIt last, const Comp& x = Comp());
  template<typename InpIt> priority_queue(InpIt first, InpIt last, const Comp& x, const Cont&);
  template<typename InpIt> priority_queue(InpIt first, InpIt last, const Comp& x, Cont&&);
  template<typename Al> explicit priority_queue(const Al&);
  template<typename Al> priority_queue(const Comp&, const Al&);
  template<typename Al> priority_queue(const Comp&, const Cont&, const Al&);
  template<typename Al> priority_queue(const Comp&, Cont&&, const Al&);
  template<typename Al> priority_queue(const priority_queue&, const Al&);
  template<typename Al> priority_queue(priority_queue&&, const Al&);
  template<typename InpIt, typename Al> priority_queue(InpIt, InpIt, const Al&);
  template<typename InpIt, typename Al> priority_queue(InpIt, InpIt, const Comp&, const Al&);
  template<typename InpIt, typename Al> priority_queue(InpIt, InpIt, const Comp&, const Cont&, const Al&);
  template<typename InpIt, typename Al> priority_queue(InpIt, InpIt, const Comp&, Cont&&, const Al&);
  [[nodiscard]] bool empty() const { return c.empty(); }
  size_type size() const { return c.size(); }
  const_reference top() const { return c.front(); }
  void push(const value_type& x);
  void push(value_type&& x);
  template<typename... As> void emplace(As&&... args);
  void pop();
  void swap(priority_queue& q) noexcept(_::is_nothrow_swappable_v<Cont>&& _::is_nothrow_swappable_v<Comp>) {
    ranges::swap(c, q.c); ranges::swap(comp, q.comp);
  }
};

template<typename Comp, typename Cont>
priority_queue(Comp, Cont)
  -> priority_queue<typename Cont::value_type, Cont, Comp>;

template<typename InpIt,
         typename Comp = less<typename iterator_traits<InpIt>::value_type>,
         typename Cont = vector<typename iterator_traits<InpIt>::value_type>>
priority_queue(InpIt, InpIt, Comp = Comp(), Cont = Cont())
  -> priority_queue<typename iterator_traits<InpIt>::value_type, Cont, Comp>;

template<typename Comp, typename Cont, typename Al>
priority_queue(Comp, Cont, Al)
  -> priority_queue<typename Cont::value_type, Cont, Comp>;

template<typename InpIt, typename Al> priority_queue(InpIt, InpIt, Al)
  -> priority_queue<typename iterator_traits<InpIt>::value_type,
                    vector<typename iterator_traits<InpIt>::value_type, Al>,
                    less<typename iterator_traits<InpIt>::value_type>>;

template<typename InpIt, typename Comp, typename Al>
priority_queue(InpIt, InpIt, Comp, Al)
  -> priority_queue<typename iterator_traits<InpIt>::value_type,
                    vector<typename iterator_traits<InpIt>::value_type, Al>,
                    Comp>;

template<typename InpIt, typename Comp, typename Cont, typename Al>
priority_queue(InpIt, InpIt, Comp, Cont, Al)
  -> priority_queue<typename Cont::value_type, Cont, Comp>;

template<typename Ty, typename Cont, typename Comp, typename Al>
struct uses_allocator<priority_queue<Ty, Cont, Comp>, Al> : uses_allocator<Cont, Al>::type {};

template<typename Ty, typename Cont, typename Comp>
void swap(priority_queue<Ty, Cont, Comp>& x, priority_queue<Ty, Cont, Comp>& y) noexcept(noexcept(x.swap(y)));

}

#endif
