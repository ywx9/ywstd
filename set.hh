// ywstd/set.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <set>
#else

#include "compare.hh"
#include "initializer_list.hh"

#include "@/allocator.hh"
#include "@/less.hh"
#include "@/pair.hh"
#include "@/polymorphic_allocator.hh"
#include "@/reverse_iterator.hh"

namespace std {

template<typename Key, typename Comp = less<Key>, typename Al = allocator<Key>> class set;
template<typename Key, typename Comp = less<Key>, typename Al = allocator<Key>> class multiset;

namespace _ {
  template<typename Key, typename Comp, typename Al> struct node_handler<set<Key, Comp, Al>> {
    using value_type = Key;
    using allocator_type = Al;
    ~node_handler();
    constexpr node_handler() noexcept {}
    node_handler(node_handler&&) noexcept;
    node_handler& operator=(node_handler&&);
    [[nodiscard]] bool empty() const noexcept;
    explicit operator bool() const noexcept;
    allocator_type get_allocator() const;
    value_type& value() const;
    void swap(node_handler&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_swappable_v<Comp>);
    friend void swap(node_handler& x, node_handler& y) noexcept(noexcept(x.swap(y)));
  };
}

template<typename Key, typename Comp, typename Al> class set {
public:
  using key_type = Key;
  using key_compare = Comp;
  using value_type = Key;
  using value_compare = Comp;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename set::value_type;
    using difference_type = typename set::difference_type;
    using pointer = typename set::pointer;
    using reference = typename set::reference;
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
    using value_type = typename set::value_type;
    using difference_type = typename set::difference_type;
    using pointer = typename set::const_pointer;
    using reference = typename set::const_reference;
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
  using node_type = _::node_handler<set>;
  using insert_return_type = _::insert_return_type<iterator, node_type>;

  ~set();
  set() : set(Comp()) {}
  explicit set(const Comp& comp, const Al& = Al());
  template<typename InpIt> set(InpIt first, InpIt last, const Comp& comp = Comp(), const Al& = Al());
  set(const set& x);
  set(set&& x);
  explicit set(const Al&);
  set(const set&, const Al&);
  set(set&&, const Al&);
  set(initializer_list<value_type>, const Comp& = Comp(), const Al& = Al());
  template<typename InpIt> set(InpIt first, InpIt last, const Al& a) : set(first, last, Comp(), a) {}
  set(initializer_list<value_type> il, const Al& a) : set(il, Comp(), a) {}
  set& operator=(const set& x);
  set& operator=(set&& x) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_move_assignable_v<Comp>);
  set& operator=(initializer_list<value_type>);
  allocator_type get_allocator() const noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;

  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;
  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;
  const_reverse_iterator crbegin() const noexcept;
  const_reverse_iterator crend() const noexcept;

  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  template<typename... As> pair<iterator, bool> emplace(As&&... args);
  template<typename... As> iterator emplace_hint(const_iterator position, As&&... args);
  pair<iterator, bool> insert(const value_type& x);
  pair<iterator, bool> insert(value_type&& x);
  iterator insert(const_iterator position, const value_type& x);
  iterator insert(const_iterator position, value_type&& x);
  template<typename InpIt>
  void insert(InpIt first, InpIt last);
  void insert(initializer_list<value_type>);

  node_type extract(const_iterator position);
  node_type extract(const key_type& x);
  template<typename K> node_type extract(K&& x);
  insert_return_type insert(node_type&& nh);
  iterator insert(const_iterator hint, node_type&& nh);

  iterator erase(iterator position);
  iterator erase(const_iterator position);
  size_type erase(const key_type& x);
  template<typename K> size_type erase(K&& x);
  iterator erase(const_iterator first, const_iterator last);
  void swap(set&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_swappable_v<Comp>);
  void clear() noexcept;

  template<typename C2> void merge(set<Key, C2, Al>& source);
  template<typename C2> void merge(set<Key, C2, Al>&& source);
  template<typename C2> void merge(multiset<Key, C2, Al>& source);
  template<typename C2> void merge(multiset<Key, C2, Al>&& source);

  key_compare key_comp() const;
  value_compare value_comp() const;

  iterator find(const key_type& x);
  const_iterator find(const key_type& x) const;
  template<typename K> iterator find(const K& x);
  template<typename K> const_iterator find(const K& x) const;

  size_type count(const key_type& x) const;
  template<typename K> size_type count(const K& x) const;

  bool contains(const key_type& x) const;
  template<typename K> bool contains(const K& x) const;

  iterator lower_bound(const key_type& x);
  const_iterator lower_bound(const key_type& x) const;
  template<typename K> iterator lower_bound(const K& x);
  template<typename K> const_iterator lower_bound(const K& x) const;

  iterator upper_bound(const key_type& x);
  const_iterator upper_bound(const key_type& x) const;
  template<typename K> iterator upper_bound(const K& x);
  template<typename K> const_iterator upper_bound(const K& x) const;

  pair<iterator, iterator> equal_range(const key_type& x);
  pair<const_iterator, const_iterator> equal_range(const key_type& x) const;
  template<typename K> pair<iterator, iterator> equal_range(const K& x);
  template<typename K> pair<const_iterator, const_iterator> equal_range(const K& x) const;
};

template<typename InpIt, typename Comp = less<typename iterator_traits<InpIt>::value_type>,
         typename Al = allocator<typename iterator_traits<InpIt>::value_type>>
set(InpIt, InpIt, Comp = Comp(), Al = Al()) -> set<typename iterator_traits<InpIt>::value_type, Comp, Al>;

template<typename Key, typename Comp = less<Key>, typename Al = allocator<Key>>
set(initializer_list<Key>, Comp = Comp(), Al = Al()) -> set<Key, Comp, Al>;

template<typename InpIt, typename Al>
set(InpIt, InpIt, Al) -> set<typename iterator_traits<InpIt>::value_type, less<typename iterator_traits<InpIt>::value_type>, Al>;

template<typename Key, typename Al> set(initializer_list<Key>, Al) -> set<Key, less<Key>, Al>;

template<typename Key, typename Comp, typename Al>
bool operator==(const set<Key, Comp, Al>& x, const set<Key, Comp, Al>& y);
template<typename Key, typename Comp, typename Al>
_::synth_three_way_result_t<Key> operator<=>(const set<Key, Comp, Al>& x, const set<Key, Comp, Al>& y);

template<typename Key, typename Comp, typename Al>
void swap(set<Key, Comp, Al>& x, set<Key, Comp, Al>& y) noexcept(noexcept(x.swap(y)));

template<typename Key, typename Comp, typename Al, typename Predicate>
typename set<Key, Comp, Al>::size_type erase_if(set<Key, Comp, Al>& c, Predicate pred);

template<typename Key, typename Comp, typename Al> class multiset {
public:
  using key_type = Key;
  using key_compare = Comp;
  using value_type = Key;
  using value_compare = Comp;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename multiset::value_type;
    using difference_type = typename multiset::difference_type;
    using pointer = typename multiset::pointer;
    using reference = typename multiset::reference;
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
    difference_type operator-(const iterator& i);
    bool operator==(const iterator& i) const;
    strong_ordering operator<=>(const iterator& i) const;
  };

  class const_iterator {
  public:
    using value_type = typename multiset::value_type;
    using difference_type = typename multiset::difference_type;
    using pointer = typename multiset::const_pointer;
    using reference = typename multiset::const_reference;
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
    difference_type operator-(const const_iterator& i);
    bool operator==(const const_iterator& i);
    strong_ordering operator<=>(const const_iterator& i) const;
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using node_type = _::node_handler<multiset>;

  ~multiset();
  multiset() : multiset(Comp()) {}
  explicit multiset(const Comp& comp, const Al& = Al{});
  template<typename InpIt> multiset(InpIt first, InpIt last, const Comp& comp = Comp(), const Al& = Al());
  multiset(const multiset& x);
  multiset(multiset&& x);
  explicit multiset(const Al&);
  multiset(const multiset&, const Al&);
  multiset(multiset&&, const Al&);
  multiset(initializer_list<value_type>, const Comp& = Comp(), const Al& = Al());
  template<typename InpIt> multiset(InpIt first, InpIt last, const Al& a) : multiset(first, last, Comp(), a) {}
  multiset(initializer_list<value_type> il, const Al& a) : multiset(il, Comp(), a) {}
  multiset& operator=(const multiset& x);
  multiset& operator=(multiset&& x) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_move_assignable_v<Comp>);
  multiset& operator=(initializer_list<value_type>);
  allocator_type get_allocator() const noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;

  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;
  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;
  const_reverse_iterator crbegin() const noexcept;
  const_reverse_iterator crend() const noexcept;

  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  template<typename... As> iterator emplace(As&&... args);
  template<typename... As> iterator emplace_hint(const_iterator position, As&&... args);
  iterator insert(const value_type& x);
  iterator insert(value_type&& x);
  iterator insert(const_iterator position, const value_type& x);
  iterator insert(const_iterator position, value_type&& x);
  template<typename InpIt> void insert(InpIt first, InpIt last);
  void insert(initializer_list<value_type>);

  node_type extract(const_iterator position);
  node_type extract(const key_type& x);
  template<typename K> node_type extract(K&& x);
  iterator insert(node_type&& nh);
  iterator insert(const_iterator hint, node_type&& nh);

  iterator erase(iterator position);
  iterator erase(const_iterator position);
  size_type erase(const key_type& x);
  template<typename K> size_type erase(K&& x);
  iterator erase(const_iterator first, const_iterator last);
  void swap(multiset&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_swappable_v<Comp>);
  void clear() noexcept;

  template<typename C2> void merge(multiset<Key, C2, Al>& source);
  template<typename C2> void merge(multiset<Key, C2, Al>&& source);
  template<typename C2> void merge(set<Key, C2, Al>& source);
  template<typename C2> void merge(set<Key, C2, Al>&& source);

  key_compare key_comp() const;
  value_compare value_comp() const;

  iterator find(const key_type& x);
  const_iterator find(const key_type& x) const;
  template<typename K> iterator find(const K& x);
  template<typename K> const_iterator find(const K& x) const;

  size_type count(const key_type& x) const;
  template<typename K> size_type count(const K& x) const;

  bool contains(const key_type& x) const;
  template<typename K> bool contains(const K& x) const;

  iterator lower_bound(const key_type& x);
  const_iterator lower_bound(const key_type& x) const;
  template<typename K> iterator lower_bound(const K& x);
  template<typename K> const_iterator lower_bound(const K& x) const;

  iterator upper_bound(const key_type& x);
  const_iterator upper_bound(const key_type& x) const;
  template<typename K> iterator upper_bound(const K& x);
  template<typename K> const_iterator upper_bound(const K& x) const;

  pair<iterator, iterator> equal_range(const key_type& x);
  pair<const_iterator, const_iterator> equal_range(const key_type& x) const;
  template<typename K> pair<iterator, iterator> equal_range(const K& x);
  template<typename K> pair<const_iterator, const_iterator> equal_range(const K& x) const;
};

template<typename InpIt,
         typename Comp = less<typename iterator_traits<InpIt>::value_type>,
         typename Al = allocator<typename iterator_traits<InpIt>::value_type>>
multiset(InpIt, InpIt, Comp = Comp(), Al = Al())
  -> multiset<typename iterator_traits<InpIt>::value_type, Comp, Al>;

template<typename Key, typename Comp = less<Key>, typename Al = allocator<Key>>
multiset(initializer_list<Key>, Comp = Comp(), Al = Al()) -> multiset<Key, Comp, Al>;

template<typename InpIt, typename Al> multiset(InpIt, InpIt, Al)
  -> multiset<typename iterator_traits<InpIt>::value_type, less<typename iterator_traits<InpIt>::value_type>, Al>;

template<typename Key, typename Al> multiset(initializer_list<Key>, Al) -> multiset<Key, less<Key>, Al>;

template<typename Key, typename Comp, typename Al>
bool operator==(const multiset<Key, Comp, Al>& x, const multiset<Key, Comp, Al>& y);

template<typename Key, typename Comp, typename Al>
_::synth_three_way_result_t<Key> operator<=>(const multiset<Key, Comp, Al>& x, const multiset<Key, Comp, Al>& y);

template<typename Key, typename Comp, typename Al>
void swap(multiset<Key, Comp, Al>& x, multiset<Key, Comp, Al>& y) noexcept(noexcept(x.swap(y)));

template<typename Key, typename Comp, typename Al, typename Predicate>
typename multiset<Key, Comp, Al>::size_type erase_if(multiset<Key, Comp, Al>& c, Predicate pred);

namespace pmr {
  template<typename Key, typename Comp = less<Key>> using set = std::set<Key, Comp, polymorphic_allocator<Key>>;
  template<typename Key, typename Comp = less<Key>> using multiset = std::multiset<Key, Comp, polymorphic_allocator<Key>>;
}

}

#endif
