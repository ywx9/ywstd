// ywstd/forward_list.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <forward_list>
#else

#include "@/../compare.hh"
#include "@/../initializer_list.hh"

#include "@/allocator.hh"
#include "@/iterator-concepts.hh"

namespace std {

// std::forward_list
template<typename Ty, typename Al = allocator<Ty>> class forward_list {
  using value_type = Ty;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename forward_list::value_type;
    using difference_type = typename forward_list::difference_type;
    using pointer = typename forward_list::pointer;
    using reference = typename forward_list::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    iterator() = default;
    iterator(const iterator&) = default;
    iterator(iterator&&) = default;
    iterator(typename forward_list::pointer p);
    iterator& operator=(const iterator&) = default;
    iterator& operator=(iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    iterator& operator++();
    iterator operator++(int);
    constexpr difference_type operator-(const iterator& i);
    bool operator==(const iterator& i) const;
    strong_ordering operator<=>(const iterator& i);
  };

  class const_iterator {
  public:
    using value_type = typename forward_list::value_type;
    using difference_type = typename forward_list::difference_type;
    using pointer = typename forward_list::const_pointer;
    using reference = typename forward_list::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
    const_iterator(typename forward_list::pointer p);
    const_iterator& operator=(const const_iterator&) = default;
    const_iterator& operator=(const_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_iterator& operator++();
    const_iterator operator++(int);
    constexpr difference_type operator-(const const_iterator& i);
    bool operator==(const const_iterator& i) const;
    strong_ordering operator<=>(const const_iterator& i) const;
  };

  ~forward_list();
  forward_list();
  forward_list(const forward_list&);
  forward_list(forward_list&&);
  explicit forward_list(const Al&);
  forward_list(const forward_list&, const Al&);
  forward_list(forward_list&&, const Al&);
  explicit forward_list(size_type, const Al& = Al{});
  forward_list(size_type, const Ty&, const Al& = Al{});
  template<typename It> forward_list(It, It, const Al& = Al{});
  forward_list(initializer_list<Ty>, const Al& = Al{});
  forward_list& operator=(const forward_list&);
  forward_list& operator=(forward_list&&) noexcept(allocator_traits<Al>::is_always_equal::value);
  forward_list& operator=(initializer_list<Ty>);
  template<typename It> void assign(It, It);
  void assign(size_type, const Ty&);
  void assign(initializer_list<Ty>);
  allocator_type get_allocator() const noexcept;
  iterator before_begin() noexcept;
  const_iterator before_begin() const noexcept;
  const_iterator cbefore_begin() const noexcept;
  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cend() const noexcept;
  [[nodiscard]] bool empty() const noexcept;
  size_type max_size() const noexcept;
  reference front();
  const_reference front() const;
  template<typename... Ts> reference emplace_front(Ts&&...);
  void push_front(const Ty&);
  void push_front(Ty&&);
  void pop_front();
  template<typename... Ts> iterator emplace_after(const_iterator, Ts&&...);
  iterator insert_after(const_iterator, const Ty&);
  iterator insert_after(const_iterator, Ty&&);
  iterator insert_after(const_iterator, size_type, const Ty&);
  template<typename It> iterator insert_after(const_iterator, It, It);
  iterator insert_after(const_iterator, initializer_list<Ty>);
  iterator erase_after(const_iterator);
  iterator erase_after(const_iterator, const_iterator);
  void swap(forward_list&) noexcept(allocator_traits<Al>::is_always_equal::value);
  void resize(size_type);
  void resize(size_type, const value_type& c);
  void clear() noexcept;
  void splice_after(const_iterator, forward_list&);
  void splice_after(const_iterator, forward_list&&);
  void splice_after(const_iterator, forward_list&, const_iterator i);
  void splice_after(const_iterator, forward_list&&, const_iterator i);
  void splice_after(const_iterator, forward_list&, const_iterator, const_iterator);
  void splice_after(const_iterator, forward_list&&, const_iterator, const_iterator);
  size_type remove(const Ty&);
  template<typename Fn> size_type remove_if(Fn);
  size_type unique();
  template<typename Fn> size_type unique(Fn);
  void merge(forward_list&);
  void merge(forward_list&&);
  template<typename Compare> void merge(forward_list&, Compare);
  template<typename Compare> void merge(forward_list&&, Compare);
  void sort();
  template<typename Compare> void sort(Compare);
  void reverse() noexcept;
  friend void swap(forward_list& x, forward_list& y) noexcept(noexcept(x.swap(y)));
  friend bool operator==(const forward_list&, const forward_list&);
  friend _::synth_three_way_result_t<value_type> operator<=>(const forward_list&, const forward_list&);
  template<typename Uy> friend size_type erase(forward_list&, const Uy&);
  template<typename Fn> friend size_type erase(forward_list&, Fn);
};

template<typename It, typename Al = allocator<typename iterator_traits<It>::value_type>>
forward_list(It, It, Al = Al{}) -> forward_list<typename iterator_traits<It>::value_type, Al>;

}

#endif
