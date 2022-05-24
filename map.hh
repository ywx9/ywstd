// ywstd/map.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <map>
#else

#include "@/../compare.hh"
#include "@/../initializer_list.hh"
#include "@/allocator.hh"
#include "@/iterator-concepts.hh"
#include "@/less.hh"
#include "@/pair.hh"
#include "@/reverse_iterator.hh"

namespace std {

template<typename Key, typename Ty, typename Comp = less<Key>, typename Al = allocator<pair<const Key, Ty>>> class map;
template<typename Key, typename Ty, typename Comp = less<Key>, typename Al = allocator<pair<const Key, Ty>>> class multimap;

namespace _ {
  template<typename Key, typename Ty, typename Comp, typename Al> struct node_handler<map<Key, Ty, Comp, Al>> {
    using key_type = Key;
    using mapped_type = Ty;
    using allocator_type = Al;
    ~node_handler();
    constexpr node_handler() noexcept {}
    node_handler(node_handler&&) noexcept;
    node_handler& operator=(node_handler&&);
    [[nodiscard]] bool empty() const noexcept;
    explicit operator bool() const noexcept;
    allocator_type get_allocator() const;
    key_type& key() const;
    mapped_type& mapped() const;
    void swap(node_handler&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_swappable_v<Comp>);
    friend void swap(node_handler& x, node_handler& y) noexcept(noexcept(x.swap(y)));
  };
}

template<typename Key, typename Ty, typename Comp, typename Al> class map {
public:
  using key_type = Key;
  using mapped_type = Ty;
  using value_type = pair<const Key, Ty>;
  using key_compare = Comp;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename map::value_type;
    using difference_type = typename map::difference_type;
    using pointer = typename map::pointer;
    using reference = typename map::reference;
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
    using value_type = typename map::value_type;
    using difference_type = typename map::difference_type;
    using pointer = typename map::const_pointer;
    using reference = typename map::const_reference;
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
  using node_type = _::node_handler<map>;
  using insert_return_type = _::insert_return_type<iterator, node_type>;

  class value_compare {
  protected:
    friend class map;
    Comp comp;
    value_compare(Comp c) : comp(c) {}

  public:
    bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
  };

  ~map();
  map() : map(Comp()) {}
  explicit map(const Comp& comp, const Al& = Al());
  template<typename InpIt> map(InpIt first, InpIt last, const Comp& comp = Comp(), const Al& = Al());
  map(const map& x);
  map(map&& x);
  explicit map(const Al&);
  map(const map&, const Al&);
  map(map&&, const Al&);
  map(initializer_list<value_type>, const Comp& = Comp(), const Al& = Al());
  template<typename InpIt> map(InpIt first, InpIt last, const Al& a) : map(first, last, Comp(), a) {}
  map(initializer_list<value_type> il, const Al& a) : map(il, Comp(), a) {}
  map& operator=(const map& x);
  map& operator=(map&& x) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_move_assignable_v<Comp>);
  map& operator=(initializer_list<value_type>);
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

  mapped_type& operator[](const key_type& x);
  mapped_type& operator[](key_type&& x);
  mapped_type& at(const key_type& x);
  const mapped_type& at(const key_type& x) const;

  template<typename... Args> pair<iterator, bool> emplace(Args&&... args);
  template<typename... Args> iterator emplace_hint(const_iterator position, Args&&... args);
  pair<iterator, bool> insert(const value_type& x);
  pair<iterator, bool> insert(value_type&& x);
  template<typename P> pair<iterator, bool> insert(P&& x);
  iterator insert(const_iterator position, const value_type& x);
  iterator insert(const_iterator position, value_type&& x);
  template<typename P> iterator insert(const_iterator position, P&&);
  template<typename InpIt> void insert(InpIt first, InpIt last);
  void insert(initializer_list<value_type>);

  node_type extract(const_iterator position);
  node_type extract(const key_type& x);
  template<typename K> node_type extract(K&& x);
  insert_return_type insert(node_type&& nh);
  iterator insert(const_iterator hint, node_type&& nh);

  template<typename... Args> pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);
  template<typename... Args> pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);
  template<typename... Args> iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args);
  template<typename... Args> iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);
  template<typename M> pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);
  template<typename M> pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);
  template<typename M> iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);
  template<typename M> iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);

  iterator erase(iterator position);
  iterator erase(const_iterator position);
  size_type erase(const key_type& x);
  template<typename K> size_type erase(K&& x);
  iterator erase(const_iterator first, const_iterator last);
  void swap(map&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_swappable_v<Comp>);
  void clear() noexcept;

  template<typename C2> void merge(map<Key, Ty, C2, Al>& source);
  template<typename C2> void merge(map<Key, Ty, C2, Al>&& source);
  template<typename C2> void merge(multimap<Key, Ty, C2, Al>& source);
  template<typename C2> void merge(multimap<Key, Ty, C2, Al>&& source);

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
  template<typename K>
  pair<iterator, iterator> equal_range(const K& x);
  template<typename K>
  pair<const_iterator, const_iterator> equal_range(const K& x) const;
};

template<typename InpIt,
         typename Comp = less<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
         typename Al = allocator<pair<typename add_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                      typename iterator_traits<InpIt>::value_type::second_type>>>
map(InpIt, InpIt, Comp = Comp(), Al = Al())
  -> map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
         typename iterator_traits<InpIt>::value_type::second_type,
         Comp, Al>;

template<typename Key, typename Ty, typename Comp = less<Key>, typename Al = allocator<pair<const Key, Ty>>>
map(initializer_list<pair<Key, Ty>>, Comp = Comp(), Al = Al())
  -> map<Key, Ty, Comp, Al>;

template<typename InpIt, typename Al>
map(InpIt, InpIt, Al)
  -> map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
         typename iterator_traits<InpIt>::value_type::second_type,
         less<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
         Al>;

template<typename Key, typename Ty, typename Al>
map(initializer_list<pair<Key, Ty>>, Al) -> map<Key, Ty, less<Key>, Al>;

template<typename Key, typename Ty, typename Comp, typename Al>
void swap(map<Key, Ty, Comp, Al>& x, map<Key, Ty, Comp, Al>& y) noexcept(noexcept(x.swap(y)));

template<typename Key, typename Ty, typename Comp, typename Al> class multimap {
public:
  using key_type = Key;
  using mapped_type = Ty;
  using value_type = pair<const Key, Ty>;
  using key_compare = Comp;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename multimap::value_type;
    using difference_type = typename multimap::difference_type;
    using pointer = typename multimap::pointer;
    using reference = typename multimap::reference;
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
    using value_type = typename multimap::value_type;
    using difference_type = typename multimap::difference_type;
    using pointer = typename multimap::const_pointer;
    using reference = typename multimap::const_reference;
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
  using node_type = _::node_handler<multimap>;

  class value_compare {
  protected:
    friend class multimap;
    Comp comp;
    value_compare(Comp c) : comp(c) {}

  public:
    bool operator()(const value_type& x, const value_type& y) const;
  };

  ~multimap();
  multimap() : multimap(Comp()) {}
  explicit multimap(const Comp& comp, const Al& = Al());
  template<_::legacy_input_iterator InpIt> multimap(InpIt first, InpIt last, const Comp& comp = Comp(), const Al& = Al());
  multimap(const multimap& x);
  multimap(multimap&& x);
  explicit multimap(const Al&);
  multimap(const multimap&, const Al&);
  multimap(multimap&&, const Al&);
  multimap(initializer_list<value_type>, const Comp& = Comp(), const Al& = Al());
  template<_::legacy_input_iterator InpIt> multimap(InpIt first, InpIt last, const Al& a) : multimap(first, last, Comp(), a) {}
  multimap(initializer_list<value_type> il, const Al& a) : multimap(il, Comp(), a) {}
  multimap& operator=(const multimap& x);
  multimap& operator=(multimap&& x) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_move_assignable_v<Comp>);
  multimap& operator=(initializer_list<value_type>);
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

  template<typename... Args> iterator emplace(Args&&... args);
  template<typename... Args> iterator emplace_hint(const_iterator position, Args&&... args);
  iterator insert(const value_type& x);
  iterator insert(value_type&& x);
  template<typename P> iterator insert(P&& x);
  iterator insert(const_iterator position, const value_type& x);
  iterator insert(const_iterator position, value_type&& x);
  template<typename P> iterator insert(const_iterator position, P&& x);
  template<_::legacy_input_iterator InpIt> void insert(InpIt first, InpIt last);
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
  void swap(multimap&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_move_assignable_v<Comp>);
  void clear() noexcept;

  template<typename C2> void merge(multimap<Key, Ty, C2, Al>& source);
  template<typename C2> void merge(multimap<Key, Ty, C2, Al>&& source);
  template<typename C2> void merge(map<Key, Ty, C2, Al>& source);
  template<typename C2> void merge(map<Key, Ty, C2, Al>&& source);

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
         typename Comp = less<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
         typename Al = allocator<pair<typename add_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                      typename iterator_traits<InpIt>::value_type::second_type>>>
multimap(InpIt, InpIt, Comp = Comp(), Al = Al())
  -> multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
              typename iterator_traits<InpIt>::value_type::second_type,
              Comp, Al>;

template<typename Key, typename Ty, typename Comp = less<Key>, typename Al = allocator<pair<const Key, Ty>>>
multimap(initializer_list<pair<Key, Ty>>, Comp = Comp(), Al = Al()) -> multimap<Key, Ty, Comp, Al>;

template<typename InpIt, typename Al>
multimap(InpIt, InpIt, Al)
  -> multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
              typename iterator_traits<InpIt>::value_type::second_type,
              less<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
              Al>;

template<typename Key, typename Ty, typename Al>
multimap(initializer_list<pair<Key, Ty>>, Al) -> multimap<Key, Ty, less<Key>, Al>;

template<typename Key, typename Ty, typename Comp, typename Al>
void swap(multimap<Key, Ty, Comp, Al>& x, multimap<Key, Ty, Comp, Al>& y) noexcept(noexcept(x.swap(y)));

}

#endif
