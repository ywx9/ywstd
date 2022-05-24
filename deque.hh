// ywlib/deque.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <deque>
#else

#include "@/../compare.hh"
#include "@/../initializer_list.hh"
#include "@/allocator.hh"
#include "@/reverse_iterator.hh"
#include "@/polymorphic_allocator.hh"

namespace std {
template<typename Ty, typename Al = allocator<Ty>> class deque {
public:
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
    using value_type = typename deque::value_type;
    using difference_type = typename deque::difference_type;
    using pointer = typename deque::pointer;
    using reference = typename deque::reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = random_access_iterator_tag;
    iterator() = default;
    iterator(const iterator&) = default;
    iterator(iterator&&) = default;
    iterator(typename deque::pointer p);
    iterator& operator=(const iterator&) = default;
    iterator& operator=(iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    reference operator[](difference_type n) const;
    iterator& operator++();
    iterator& operator--();
    iterator operator++(int);
    iterator operator--(int);
    iterator& operator+=(difference_type n);
    iterator& operator-=(difference_type n);
    iterator operator+(difference_type n);
    iterator operator-(difference_type n);
    difference_type operator-(const iterator& i);
    friend iterator operator+(difference_type n, const iterator& i);
    bool operator==(const iterator& i) const;
    strong_ordering operator<=>(const iterator& i);
  };

  class const_iterator {
    typename deque::pointer _ptr;
  public:
    using value_type = typename deque::value_type;
    using difference_type = typename deque::difference_type;
    using pointer = typename deque::const_pointer;
    using reference = typename deque::const_reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = random_access_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
    const_iterator(typename deque::pointer p) : _ptr{p} {}
    const_iterator& operator=(const const_iterator&) = default;
    const_iterator& operator=(const_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    reference operator[](difference_type n) const;
    const_iterator& operator++();
    const_iterator& operator--();
    const_iterator operator++(int);
    const_iterator operator--(int);
    const_iterator& operator+=(difference_type n);
    const_iterator& operator-=(difference_type n);
    const_iterator operator+(difference_type n);
    const_iterator operator-(difference_type n);
    difference_type operator-(const const_iterator& i);
    friend const_iterator operator+(difference_type n, const const_iterator& i);
    bool operator==(const const_iterator& i) const;
    strong_ordering operator<=>(const const_iterator& i);
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  ~deque();
  deque() : deque{Al{}} {}
  deque(const deque&);
  deque(deque&&);
  explicit deque(const Al&);
  deque(const deque&, const Al&);
  deque(deque&&, const Al&);
  explicit deque(size_type, const Al& = Al{});
  deque(size_type, const Ty&, const Al& = Al{});
  template<typename It> deque(It, It, const Al& = Al{});
  deque(initializer_list<Ty>, const Al& = Al{});
  deque& operator=(const deque&);
  deque& operator=(deque&&) noexcept(allocator_traits<Al>::is_always_equal::value);
  deque& operator=(initializer_list<Ty>);
  template<typename It> void assign(It, It);
  void assign(size_type, const Ty&);
  void assign(initializer_list<Ty>);
  allocator_type get_allocator() const noexcept;
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
  void resize(size_type);
  void resize(size_type, const Ty&);
  void shrink_to_fit();
  reference operator[](size_type);
  const_reference operator[](size_type) const;
  reference at(size_type);
  const_reference at(size_type) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  template<typename... Ts> reference emplace_front(Ts&&...);
  template<typename... Ts> reference emplace_back(Ts&&...);
  template<typename... Ts> iterator emplace(const_iterator, Ts&&...);
  void push_front(const Ty&);
  void push_front(Ty&&);
  void push_back(const Ty&);
  void push_back(Ty&&);
  iterator insert(const_iterator, const Ty&);
  iterator insert(const_iterator, Ty&&);
  iterator insert(const_iterator, size_type, const Ty&);
  template<typename It> iterator insert(const_iterator, It, It);
  iterator insert(const_iterator, initializer_list<Ty>);
  void pop_front();
  void pop_back();
  iterator erase(const_iterator);
  iterator erase(const_iterator, const_iterator);
  void swap(deque&) noexcept(allocator_traits<Al>::is_always_equal::value);
  void clear() noexcept;
  friend void swap(deque& x, deque& y) noexcept(noexcept(x.swap(y)));
  friend bool operator==(const deque&, const deque&);
  friend _::synth_three_way_result_t<value_type> operator<=>(const deque&, const deque&);
  template<typename Uy> friend size_type erase(deque&, const Uy&);
  template<typename Fn> friend size_type erase(deque&, Fn);
};

template<typename It, typename Al = allocator<typename iterator_traits<It>::value_type>>
deque(It, It, Al = Al{}) -> deque<typename iterator_traits<It>::value_type, Al>;

template<typename Ty, typename Al> bool operator==(const deque<Ty, Al>& x, const deque<Ty, Al>& y);
template<typename Ty, typename Al> _::synth_three_way_result_t<Ty> operator<=>(const deque<Ty, Al>& x, const deque<Ty, Al>& y);

template<typename Ty, typename Al> void swap(deque<Ty, Al>& x, deque<Ty, Al>& y) noexcept(noexcept(x.swap(y)));
template<typename Ty, typename Al, typename Uy> typename deque<Ty, Al>::size_type erase(deque<Ty, Al>& c, const Uy& value);
template<typename Ty, typename Al, typename Pred> typename deque<Ty, Al>::size_type erase_if(deque<Ty, Al>& c, Pred pred);

namespace pmr {
  template<typename Ty> using deque = std::deque<Ty, polymorphic_allocator<Ty>>;
}

}

#endif
