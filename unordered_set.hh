// ywstd/unordered_set.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <unordered_set>
#else

#include "compare.hh"
#include "initializer_list.hh"

#include "@/allocator.hh"
#include "@/equal_to.hh"
#include "@/hash.hh"
#include "@/iterator-concepts.hh"
#include "@/pair.hh"
#include "@/polymorphic_allocator.hh"

namespace std {

template<typename Key, typename Hash = hash<Key>, typename Pred = equal_to<Key>, typename Al = allocator<Key>> class unordered_set;
template<typename Key, typename Hash = hash<Key>, typename Pred = equal_to<Key>, typename Al = allocator<Key>> class unordered_multiset;

namespace _ {
  template<typename Key, typename Hash, typename Pred, typename Al> struct node_handler<unordered_set<Key, Hash, Pred, Al>> {
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
    void swap(node_handler&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_swappable_v<Hash> && is_nothrow_swappable_v<Pred>);
    friend void swap(node_handler& x, node_handler& y) noexcept(noexcept(x.swap(y)));
  };
  template<typename Key, typename Hash, typename Pred, typename Al> struct node_handler<unordered_multiset<Key, Hash, Pred, Al>> {
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
    void swap(node_handler&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_swappable_v<Hash> && is_nothrow_swappable_v<Pred>);
    friend void swap(node_handler& x, node_handler& y) noexcept(noexcept(x.swap(y)));
  };
}

template<typename Key, typename Hash, typename Pred, typename Al> class unordered_set {
public:
  using key_type = Key;
  using value_type = Key;
  using hasher = Hash;
  using key_equal = Pred;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename unordered_set::value_type;
    using difference_type = typename unordered_set::difference_type;
    using pointer = typename unordered_set::pointer;
    using reference = typename unordered_set::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    iterator() = default;
    iterator(const iterator&) = default;
    iterator(iterator&&) = default;
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
    using value_type = typename unordered_set::value_type;
    using difference_type = typename unordered_set::difference_type;
    using pointer = typename unordered_set::const_pointer;
    using reference = typename unordered_set::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
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

  class local_iterator {
  public:
    using value_type = typename unordered_set::value_type;
    using difference_type = typename unordered_set::difference_type;
    using pointer = typename unordered_set::pointer;
    using reference = typename unordered_set::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    local_iterator() = default;
    local_iterator(const local_iterator&) = default;
    local_iterator(local_iterator&&) = default;
    local_iterator& operator=(const local_iterator&) = default;
    local_iterator& operator=(local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    local_iterator& operator++();
    local_iterator operator++(int);
    constexpr difference_type operator-(const local_iterator& i);
    bool operator==(const local_iterator& i) const;
    strong_ordering operator<=>(const local_iterator& i);
  };

  class const_local_iterator {
  public:
    using value_type = typename unordered_set::value_type;
    using difference_type = typename unordered_set::difference_type;
    using pointer = typename unordered_set::const_pointer;
    using reference = typename unordered_set::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_local_iterator() = default;
    const_local_iterator(const const_local_iterator&) = default;
    const_local_iterator(const_local_iterator&&) = default;
    const_local_iterator& operator=(const const_local_iterator&) = default;
    const_local_iterator& operator=(const_local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_local_iterator& operator++();
    const_local_iterator operator++(int);
    constexpr difference_type operator-(const const_local_iterator& i);
    bool operator==(const const_local_iterator& i) const;
    strong_ordering operator<=>(const const_local_iterator& i) const;
  };

  using node_type = _::node_handler<unordered_set>;
  using insert_return_type = _::insert_return_type<iterator, node_type>;

  unordered_set();
  explicit unordered_set(size_type n, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  template<typename InpIt> unordered_set(InpIt f, InpIt l, size_type n = _::min_buckets, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_set(const unordered_set&);
  unordered_set(unordered_set&&);
  explicit unordered_set(const Al&);
  unordered_set(const unordered_set&, const Al&);
  unordered_set(unordered_set&&, const Al&);
  unordered_set(initializer_list<value_type> il, size_type n = _::min_buckets, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_set(size_type n, const allocator_type& a) : unordered_set(n, hasher(), key_equal(), a) {}
  unordered_set(size_type n, const hasher& hf, const allocator_type& a) : unordered_set(n, hf, key_equal(), a) {}
  template<typename InpIt> unordered_set(InpIt f, InpIt l, size_type n, const allocator_type& a) : unordered_set(f, l, n, hasher(), key_equal(), a) {}
  template<typename InpIt> unordered_set(InpIt f, InpIt l, size_type n, const hasher& hf, const allocator_type& a) : unordered_set(f, l, n, hf, key_equal(), a) {}
  unordered_set(initializer_list<value_type> il, size_type n, const allocator_type& a) : unordered_set(il, n, hasher(), key_equal(), a) {}
  unordered_set(initializer_list<value_type> il, size_type n, const hasher& hf, const allocator_type& a) : unordered_set(il, n, hf, key_equal(), a) {}
  ~unordered_set();
  unordered_set& operator=(const unordered_set&);
  unordered_set& operator=(unordered_set&&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_move_assignable_v<Hash> && _::is_nothrow_move_assignable_v<Pred>);
  unordered_set& operator=(initializer_list<value_type>);
  allocator_type get_allocator() const noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  template<typename... Args> pair<iterator, bool> emplace(Args&&... args);
  template<typename... Args> iterator emplace_hint(const_iterator position, Args&&... args);
  pair<iterator, bool> insert(const value_type& obj);
  pair<iterator, bool> insert(value_type&& obj);
  iterator insert(const_iterator hint, const value_type& obj);
  iterator insert(const_iterator hint, value_type&& obj);
  template<typename InpIt> void insert(InpIt first, InpIt last);
  void insert(initializer_list<value_type>);

  node_type extract(const_iterator position);
  node_type extract(const key_type& x);
  template<typename K> node_type extract(K&& x);
  insert_return_type insert(node_type&& nh);
  iterator insert(const_iterator hint, node_type&& nh);

  iterator erase(iterator position);
  iterator erase(const_iterator position);
  size_type erase(const key_type& k);
  template<typename K> size_type erase(K&& x);
  iterator erase(const_iterator first, const_iterator last);
  void swap(unordered_set&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_swappable_v<Hash> && _::is_nothrow_swappable_v<Pred>);
  void clear() noexcept;

  template<typename H2, typename P2> void merge(unordered_set<Key, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_set<Key, H2, P2, Al>&& source);
  template<typename H2, typename P2> void merge(unordered_multiset<Key, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_multiset<Key, H2, P2, Al>&& source);

  hasher hash_function() const;
  key_equal key_eq() const;

  iterator find(const key_type& k);
  const_iterator find(const key_type& k) const;
  template<typename K> iterator find(const K& k);
  template<typename K> const_iterator find(const K& k) const;
  size_type count(const key_type& k) const;
  template<typename K> size_type count(const K& k) const;
  bool contains(const key_type& k) const;
  template<typename K> bool contains(const K& k) const;
  pair<iterator, iterator> equal_range(const key_type& k);
  pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
  template<typename K> pair<iterator, iterator> equal_range(const K& k);
  template<typename K> pair<const_iterator, const_iterator> equal_range(const K& k) const;

  size_type bucket_count() const noexcept;
  size_type max_bucket_count() const noexcept;
  size_type bucket_size(size_type n) const;
  size_type bucket(const key_type& k) const;
  local_iterator begin(size_type n);
  const_local_iterator begin(size_type n) const;
  local_iterator end(size_type n);
  const_local_iterator end(size_type n) const;
  const_local_iterator cbegin(size_type n) const;
  const_local_iterator cend(size_type n) const;

  float load_factor() const noexcept;
  float max_load_factor() const noexcept;
  void max_load_factor(float z);
  void rehash(size_type n);
  void reserve(size_type n);
};

template<typename InpIt,
         typename Hash = hash<typename iterator_traits<InpIt>::value_type>,
         typename Pred = equal_to<typename iterator_traits<InpIt>::value_type>,
         typename Al = allocator<typename iterator_traits<InpIt>::value_type>>
unordered_set(InpIt, InpIt,
              typename unordered_set<typename iterator_traits<InpIt>::value_type, Hash, Pred, Al>::size_type = _::min_buckets,
              Hash = Hash(), Pred = Pred(), Al = Al())
  -> unordered_set<typename iterator_traits<InpIt>::value_type, Hash, Pred, Al>;

template<typename Ty, typename Hash = hash<Ty>, typename Pred = equal_to<Ty>, typename Al = allocator<Ty>>
unordered_set(initializer_list<Ty>, typename unordered_set<Ty, Hash, Pred, Al>::size_type = _::min_buckets, Hash = Hash(), Pred = Pred(), Al = Al())
  -> unordered_set<Ty, Hash, Pred, Al>;

template<typename InpIt, typename Al>
unordered_set(InpIt, InpIt,
              typename unordered_set<typename iterator_traits<InpIt>::value_type,
                                     hash<typename iterator_traits<InpIt>::value_type>,
                                     equal_to<typename iterator_traits<InpIt>::value_type>,
                                     Al>::size_type,
              Al)
  -> unordered_set<typename iterator_traits<InpIt>::value_type,
                   hash<typename iterator_traits<InpIt>::value_type>,
                   equal_to<typename iterator_traits<InpIt>::value_type>,
                   Al>;

template<typename InpIt, typename Hash, typename Al>
unordered_set(InpIt, InpIt,
              typename unordered_set<typename iterator_traits<InpIt>::value_type,
                                     Hash,
                                     equal_to<typename iterator_traits<InpIt>::value_type>,
                                     Al>::size_type,
              Hash, Al)
  -> unordered_set<typename iterator_traits<InpIt>::value_type,
                   Hash,
                   equal_to<typename iterator_traits<InpIt>::value_type>,
                   Al>;

template<typename Ty, typename Al>
unordered_set(initializer_list<Ty>, typename unordered_set<Ty, hash<Ty>, equal_to<Ty>, Al>::size_type, Al)
  -> unordered_set<Ty, hash<Ty>, equal_to<Ty>, Al>;

template<typename Ty, typename Hash, typename Al>
unordered_set(initializer_list<Ty>, typename unordered_set<Ty, Hash, equal_to<Ty>, Al>::size_type, Hash, Al)
  -> unordered_set<Ty, Hash, equal_to<Ty>, Al>;

template<typename Key, typename Hash, typename Pred, typename Al>
bool operator==(const unordered_set<Key, Hash, Pred, Al>& a, const unordered_set<Key, Hash, Pred, Al>& b);

template<typename Key, typename Hash, typename Pred, typename Al>
void swap(unordered_set<Key, Hash, Pred, Al>& x, unordered_set<Key, Hash, Pred, Al>& y) noexcept(noexcept(x.swap(y)));

template<typename K, typename H, typename P, typename A, typename Predicate>
class unordered_set<K, H, P, A>::size_type erase_if(unordered_set<K, H, P, A>& c, Predicate pred);

template<typename Key, typename Hash, typename Pred, typename Al> class unordered_multiset {
public:
  using key_type = Key;
  using value_type = Key;
  using hasher = Hash;
  using key_equal = Pred;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename unordered_multiset::value_type;
    using difference_type = typename unordered_multiset::difference_type;
    using pointer = typename unordered_multiset::pointer;
    using reference = typename unordered_multiset::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    iterator() = default;
    iterator(const iterator&) = default;
    iterator(iterator&&) = default;
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
    using value_type = typename unordered_multiset::value_type;
    using difference_type = typename unordered_multiset::difference_type;
    using pointer = typename unordered_multiset::const_pointer;
    using reference = typename unordered_multiset::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
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

  class local_iterator {
  public:
    using value_type = typename unordered_multiset::value_type;
    using difference_type = typename unordered_multiset::difference_type;
    using pointer = typename unordered_multiset::pointer;
    using reference = typename unordered_multiset::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    local_iterator() = default;
    local_iterator(const local_iterator&) = default;
    local_iterator(local_iterator&&) = default;
    local_iterator& operator=(const local_iterator&) = default;
    local_iterator& operator=(local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    local_iterator& operator++();
    local_iterator operator++(int);
    constexpr difference_type operator-(const local_iterator& i);
    bool operator==(const local_iterator& i) const;
    strong_ordering operator<=>(const local_iterator& i);
  };

  class const_local_iterator {
  public:
    using value_type = typename unordered_multiset::value_type;
    using difference_type = typename unordered_multiset::difference_type;
    using pointer = typename unordered_multiset::const_pointer;
    using reference = typename unordered_multiset::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_local_iterator() = default;
    const_local_iterator(const const_local_iterator&) = default;
    const_local_iterator(const_local_iterator&&) = default;
    const_local_iterator& operator=(const const_local_iterator&) = default;
    const_local_iterator& operator=(const_local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_local_iterator& operator++();
    const_local_iterator operator++(int);
    constexpr difference_type operator-(const const_local_iterator& i);
    bool operator==(const const_local_iterator& i) const;
    strong_ordering operator<=>(const const_local_iterator& i) const;
  };

  using node_type = _::node_handler<unordered_multiset>;

  unordered_multiset();
  explicit unordered_multiset(size_type n, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  template<typename InpIt> unordered_multiset(InpIt f, InpIt l, size_type n = _::min_buckets, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_multiset(const unordered_multiset&);
  unordered_multiset(unordered_multiset&&);
  explicit unordered_multiset(const Al&);
  unordered_multiset(const unordered_multiset&, const Al&);
  unordered_multiset(unordered_multiset&&, const Al&);
  unordered_multiset(initializer_list<value_type> il, size_type n = _::min_buckets, const hasher& hf = hasher(),
                     const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_multiset(size_type n, const allocator_type& a) : unordered_multiset(n, hasher(), key_equal(), a) {}
  unordered_multiset(size_type n, const hasher& hf, const allocator_type& a) : unordered_multiset(n, hf, key_equal(), a) {}
  template<typename InpIt> unordered_multiset(InpIt f, InpIt l, size_type n, const allocator_type& a) : unordered_multiset(f, l, n, hasher(), key_equal(), a) {}
  template<typename InpIt> unordered_multiset(InpIt f, InpIt l, size_type n, const hasher& hf, const allocator_type& a) : unordered_multiset(f, l, n, hf, key_equal(), a) {}
  unordered_multiset(initializer_list<value_type> il, size_type n, const allocator_type& a) : unordered_multiset(il, n, hasher(), key_equal(), a) {}
  unordered_multiset(initializer_list<value_type> il, size_type n, const hasher& hf, const allocator_type& a) : unordered_multiset(il, n, hf, key_equal(), a) {}
  ~unordered_multiset();
  unordered_multiset& operator=(const unordered_multiset&);
  unordered_multiset& operator=(unordered_multiset&&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_move_assignable_v<Hash> && _::is_nothrow_move_assignable_v<Pred>);
  unordered_multiset& operator=(initializer_list<value_type>);
  allocator_type get_allocator() const noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  template<typename... Args> iterator emplace(Args&&... args);
  template<typename... Args> iterator emplace_hint(const_iterator position, Args&&... args);
  iterator insert(const value_type& obj);
  iterator insert(value_type&& obj);
  iterator insert(const_iterator hint, const value_type& obj);
  iterator insert(const_iterator hint, value_type&& obj);
  template<typename InpIt> void insert(InpIt first, InpIt last);
  void insert(initializer_list<value_type>);

  node_type extract(const_iterator position);
  node_type extract(const key_type& x);
  template<typename K> node_type extract(K&& x);
  iterator insert(node_type&& nh);
  iterator insert(const_iterator hint, node_type&& nh);

  iterator erase(iterator position);
  iterator erase(const_iterator position);
  size_type erase(const key_type& k);
  template<typename K> size_type erase(K&& x);
  iterator erase(const_iterator first, const_iterator last);
  void swap(unordered_multiset&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_swappable_v<Hash> && _::is_nothrow_swappable_v<Pred>);
  void clear() noexcept;

  template<typename H2, typename P2> void merge(unordered_multiset<Key, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_multiset<Key, H2, P2, Al>&& source);
  template<typename H2, typename P2> void merge(unordered_set<Key, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_set<Key, H2, P2, Al>&& source);

  hasher hash_function() const;
  key_equal key_eq() const;

  iterator find(const key_type& k);
  const_iterator find(const key_type& k) const;
  template<typename K> iterator find(const K& k);
  template<typename K> const_iterator find(const K& k) const;
  size_type count(const key_type& k) const;
  template<typename K> size_type count(const K& k) const;
  bool contains(const key_type& k) const;
  template<typename K> bool contains(const K& k) const;
  pair<iterator, iterator> equal_range(const key_type& k);
  pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
  template<typename K> pair<iterator, iterator> equal_range(const K& k);
  template<typename K> pair<const_iterator, const_iterator> equal_range(const K& k) const;

  size_type bucket_count() const noexcept;
  size_type max_bucket_count() const noexcept;
  size_type bucket_size(size_type n) const;
  size_type bucket(const key_type& k) const;
  local_iterator begin(size_type n);
  const_local_iterator begin(size_type n) const;
  local_iterator end(size_type n);
  const_local_iterator end(size_type n) const;
  const_local_iterator cbegin(size_type n) const;
  const_local_iterator cend(size_type n) const;

  float load_factor() const noexcept;
  float max_load_factor() const noexcept;
  void max_load_factor(float z);
  void rehash(size_type n);
  void reserve(size_type n);
};

template<typename InpIt,
         typename Hash = hash<typename iterator_traits<InpIt>::value_type>,
         typename Pred = equal_to<typename iterator_traits<InpIt>::value_type>,
         typename Al = allocator<typename iterator_traits<InpIt>::value_type>>
unordered_multiset(InpIt, InpIt,
                   typename unordered_multiset<typename iterator_traits<InpIt>::value_type, Hash, Pred, Al>::size_type = _::min_buckets,
                   Hash = Hash(), Pred = Pred(), Al = Al())
  -> unordered_multiset<typename iterator_traits<InpIt>::value_type, Hash, Pred, Al>;

template<typename Ty, typename Hash = hash<Ty>, typename Pred = equal_to<Ty>, typename Al = allocator<Ty>>
unordered_multiset(initializer_list<Ty>, typename unordered_multiset<Ty, Hash, Pred, Al>::size_type = _::min_buckets, Hash = Hash(), Pred = Pred(), Al = Al())
  -> unordered_multiset<Ty, Hash, Pred, Al>;

template<typename InpIt, typename Al>
unordered_multiset(InpIt, InpIt,
                   typename unordered_multiset<typename iterator_traits<InpIt>::value_type,
                                               hash<typename iterator_traits<InpIt>::value_type>,
                                               equal_to<typename iterator_traits<InpIt>::value_type>,
                                               Al>::size_type,
                   Al)
  -> unordered_multiset<typename iterator_traits<InpIt>::value_type,
                        hash<typename iterator_traits<InpIt>::value_type>,
                        equal_to<typename iterator_traits<InpIt>::value_type>,
                        Al>;

template<typename InpIt, typename Hash, typename Al>
unordered_multiset(InpIt, InpIt,
                   typename unordered_multiset<typename iterator_traits<InpIt>::value_type,
                                               Hash,
                                               equal_to<typename iterator_traits<InpIt>::value_type>,
                                               Al>::size_type,
                   Hash, Al)
  -> unordered_multiset<typename iterator_traits<InpIt>::value_type,
                        Hash,
                        equal_to<typename iterator_traits<InpIt>::value_type>,
                        Al>;

template<typename Ty, typename Al>
unordered_multiset(initializer_list<Ty>, typename unordered_multiset<Ty, hash<Ty>, equal_to<Ty>, Al>::size_type, Al)
  -> unordered_multiset<Ty, hash<Ty>, equal_to<Ty>, Al>;

template<typename Ty, typename Hash, typename Al>
unordered_multiset(initializer_list<Ty>, typename unordered_multiset<Ty, Hash, equal_to<Ty>, Al>::size_type, Hash, Al)
  -> unordered_multiset<Ty, Hash, equal_to<Ty>, Al>;

template<typename Key, typename Hash, typename Pred, typename Al>
bool operator==(const unordered_multiset<Key, Hash, Pred, Al>& a, const unordered_multiset<Key, Hash, Pred, Al>& b);

template<typename Key, typename Hash, typename Pred, typename Al>
void swap(unordered_multiset<Key, Hash, Pred, Al>& x, unordered_multiset<Key, Hash, Pred, Al>& y) noexcept(noexcept(x.swap(y)));

template<typename K, typename H, typename P, typename A, typename Predicate>
class unordered_multiset<K, H, P, A>::size_type erase_if(unordered_multiset<K, H, P, A>& c, Predicate pred);

namespace pmr {
template<typename Key, typename Hash = hash<Key>, typename Pred = equal_to<Key>>
using unordered_set = std::unordered_set<Key, Hash, Pred, polymorphic_allocator<Key>>;

template<typename Key, typename Hash = hash<Key>, typename Pred = equal_to<Key>>
using unordered_multiset = std::unordered_multiset<Key, Hash, Pred, polymorphic_allocator<Key>>;
}

}

#endif
