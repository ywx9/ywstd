// ywstd/iterator.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <iterator>
#else

#include "@/iterator-concepts.hh"
#include "@/ranges-concepts.hh"
#include "@/reverse_iterator.hh"

namespace std {

template<typename It, typename DT> constexpr void advance(It& Iter, DT n) {
  if constexpr (random_access_iterator<It>) Iter += n;
  else {
    if constexpr (_::is_signed_v<DT> && !bidirectional_iterator<It>) if (n < 0) return;
    if constexpr (_::is_signed_v<DT> && bidirectional_iterator<It>) for (; n < 0; ++n) --Iter;
    for (; 0 < n; --n) ++Iter;
  }
}

template<typename It> constexpr iter_difference_t<It> distance(It First, It Last) {
  if constexpr (random_access_iterator<It>) return Last - First;
  else {
    iter_difference_t<It> n = 0;
    for (; First != Last; ++First) ++n;
    return n;
  }
}

template<input_iterator It> constexpr It next(It First, iter_difference_t<It> n = 1) {
  return std::advance(First, n), First;
}

template<bidirectional_iterator BI> constexpr BI prev(BI First, iter_difference_t<BI> n = 1) {
  return std::advance(First, -n), First;
}

}

#endif
