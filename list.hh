// ywstd/list.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <list>
#else

#include "@/../compare.hh"
#include "@/../initializer_list.hh"
#include "@/allocator.hh"
#include "@/iterator-concepts.hh"
#include "@/reverse_iterator.hh"

namespace std {

template<typename Ty, typename Al = allocator<Ty>> class list {
  using value_type = Ty;
  using allocator_type = Al;
  using size_type = size_t;
  using difference_type = ptrdiff_t;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;

  class iterator {
  public:
    using value_type = typename list::value_type;
    using difference_type = typename list::difference_type;
    using pointer = typename list::pointer;
    using reference = typename list::reference;
    using iterator_category = bidirectional_iterator_tag;
    using iterator_concept = bidirectional_iterator_tag;
    iterator() = default;
    iterator(const iterator&) = default;
    iterator(iterator&&) = default;
    iterator& operator=(const iterator&) = default;
    iterator& operator=(iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    iterator& operator++();
    iterator& operator--();
    iterator operator++(int);
    iterator operator--(int);
    difference_type operator-(iterator i);
    bool operator==(const iterator& i) const;
    strong_ordering operator<=>(const iterator& i) const;
  };

  class const_iterator {
  public:
    using value_type = typename list::value_type;
    using difference_type = typename list::difference_type;
    using pointer = typename list::const_pointer;
    using reference = typename list::const_reference;
    using iterator_category = bidirectional_iterator_tag;
    using iterator_concept = bidirectional_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
    const_iterator& operator=(const const_iterator&) = default;
    const_iterator& operator=(const_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_iterator& operator++();
    const_iterator& operator--();
    const_iterator operator++(int);
    const_iterator operator--(int);
    difference_type operator-(const_iterator i);
    bool operator==(const const_iterator& i);
    strong_ordering operator<=>(const const_iterator& i) const;
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  ~list();
  list();
  explicit list(const Al&);
  explicit list(size_type, const Ty&, const Al& = Al{});
  explicit list(size_type, const Al& = Al{});
  template<_::legacy_input_iterator It> list(It, It, const Al& = Al{});
  list(const list&);
  list(const list&, const Al&);
  list(list&&);
  list(list&&, const Al&);
  list(initializer_list<Ty>, const Al& = Al{});
  list& operator=(const list&);
  list& operator=(list&&) noexcept(allocator_traits<Al>::is_always_equal::value);
  list& operator=(initializer_list<Ty>);
  template<_::legacy_input_iterator It> void assign(It, It);
  void assign(size_t, const Ty&);
  void assign(initializer_list<Ty>);
  Al get_allocator() const noexcept;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cend() const noexcept;
  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;
  const_reverse_iterator crbegin() const noexcept;
  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;
  const_reverse_iterator crend() const noexcept;
  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void clear() noexcept;
  iterator insert(const_iterator, const Ty&);
  iterator insert(const_iterator, Ty&&);
  iterator insert(const_iterator, size_type, const Ty&);
  template<_::legacy_input_iterator It> iterator insert(const_iterator, It, It);
  iterator insert(const_iterator, initializer_list<Ty>);
  template<typename... Ts> iterator emplace(const_iterator, Ts&&...);
  iterator erase(const_iterator);
  iterator erase(const_iterator, const_iterator);
  void push_back(const Ty&);
  void push_back(Ty&&);
  template<typename... Ts> reference emplace_back(Ts&&...);
  void pop_back();
  void push_front(const Ty&);
  void push_front(Ty&&);
  template<typename... Ts> reference emplace_front(Ts...);
  void pop_front();
  void resize(size_type);
  void resize(size_type, const Ty&);
  void swap(list&) noexcept(std::allocator_traits<Al>::is_always_equal::value);
  void merge(list&&);
  template<typename Fn> void merge(list&&, Fn);
  void splice(const_iterator, list&&);
  void splice(const_iterator, list&&, const_iterator);
  void splice(const_iterator, list&&, const_iterator, const_iterator);
  size_type remove(const Ty&);
  template<typename Fn> size_type remove_if(Fn);
  void reverse() noexcept;
  size_type unique();
  template<typename Fn> size_type unique(Fn);
  void sort();
  template<typename Fn> void sort(Fn);
};

template<typename It, typename Al = allocator<typename iterator_traits<It>::value_type>>
list(It, It, Al = Al{}) -> list<typename iterator_traits<It>::value_type, Al>;

template<typename Ty, typename Al> void swap(list<Ty, Al>& x, list<Ty, Al>& y) noexcept(noexcept(x.swap(y)));

template<typename Ty, typename Al> bool operator==(const list<Ty, Al>&, const list<Ty, Al>&);
template<typename Ty, typename Al> auto operator<=>(const list<Ty, Al>&, const list<Ty, Al>&);

}

#endif
