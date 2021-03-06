//===---                threadutils.c - Thread utilities                ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the declarations for wrappers for pthread or C11
//! threads, and allows other parts of the program to easily create and work
//! with threads.
//!
//===----------------------------------------------------------------------===//

#ifndef GRIM_THREADUTILS_H
#define GRIM_THREADUTILS_H

#ifdef HAVE_CONFIG_H
#    include "config.h"
#else
#    error config.h not found, please run meson
#endif

#include <stdatomic.h>
#include <stdbool.h>

#if HAVE_THREADS == HAVE_THREADS_C11
#    include <threads.h>
#    define GRIM_CALLBACK int
typedef thrd_start_t grim_start_t;
typedef thrd_t grim_thread_t;
typedef mtx_t grim_mtx_t;
typedef cnd_t grim_cnd_t;
#elif HAVE_THREADS == HAVE_THREADS_PTHREADS
#    include <pthread.h>
#    define GRIM_CALLBACK void *
typedef pthread_t grim_thread_t;
typedef void *(*grim_start_t)(void *);
typedef pthread_mutex_t grim_mtx_t;
typedef pthread_cond_t grim_cnd_t;
#else
#    error no thread library found
#endif

/*
pthread_create / thrd_create
 */
int grim_thread_spawn(grim_thread_t *thread, bool joinable,
                      grim_start_t start_routine, void *arg);

/*
pthread_detach / thrd_detach
 */
int grim_thread_detach(grim_thread_t thread);

/*
pthread_join / thrd_join
 */
int grim_thread_join(grim_thread_t thread, int *result);

/*
pthread_self / thrd_current
 */
grim_thread_t grim_thread_current(void);

/*
pthread_exit / thrd_exit
 */
void grim_thread_exit(int *result) __attribute__((noreturn));

typedef struct
{
    atomic_uint_fast64_t *bytes_read;  // the number of bytes read so far...
    atomic_uint_fast64_t *bytes_total; // ...out of this many bytes
    char *input_file;    // the file to read from (device or regular)
    size_t input_file_l; //
    int pipefd_w;
} grim_thread_args;

#endif
