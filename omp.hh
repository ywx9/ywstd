// ywstd/omp.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off/

#pragma once

#ifdef _ywstd_
#include <omp.h>
namespace yw::omp {

using ::omp_lock_t;
using ::omp_nest_lock_t;

using ::omp_destroy_lock;
using ::omp_destroy_nest_lock;
using ::omp_get_dynamic;
using ::omp_get_max_threads;
using ::omp_get_nested;
using ::omp_get_num_procs;
using ::omp_get_num_threads;
using ::omp_get_thread_num;
using ::omp_get_wtick;
using ::omp_get_wtime;
using ::omp_in_parallel;
using ::omp_init_lock;
using ::omp_init_nest_lock;
using ::omp_set_dynamic;
using ::omp_set_lock;
using ::omp_set_nest_lock;
using ::omp_set_nested;
using ::omp_set_num_threads;
using ::omp_test_lock;
using ::omp_test_nest_lock;
using ::omp_unset_lock;
using ::omp_unset_nest_lock;
}
#else

namespace yw::omp {

using omp_lock_t = void*;
using omp_nest_lock_t = void*;

void omp_set_num_threads(int _Num_threads);
int omp_get_num_threads(void);
int omp_get_max_threads(void);
int omp_get_thread_num(void);
int omp_get_num_procs(void);
void omp_set_dynamic(int _Dynamic_threads);
int omp_get_dynamic(void);
int omp_in_parallel(void);
void omp_set_nested(int _Nested);
int omp_get_nested(void);
void omp_init_lock(omp_lock_t* _Lock);
void omp_destroy_lock(omp_lock_t* _Lock);
void omp_set_lock(omp_lock_t* _Lock);
void omp_unset_lock(omp_lock_t* _Lock);
int omp_test_lock(omp_lock_t* _Lock);
void omp_init_nest_lock(omp_nest_lock_t* _Lock);
void omp_destroy_nest_lock(omp_nest_lock_t* _Lock);
void omp_set_nest_lock(omp_nest_lock_t* _Lock);
void omp_unset_nest_lock(omp_nest_lock_t* _Lock);
int omp_test_nest_lock(omp_nest_lock_t* _Lock);
double omp_get_wtime(void);
double omp_get_wtick(void);

}

#endif
