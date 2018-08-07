//===---                threadutils.c - Thread utilities                ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the implementations of wrappers for pthread or C11
//! threads, and allows other parts of the program to easily create and work
//! with threads.
//!
//===----------------------------------------------------------------------===//

#include "threadutils.h"

int grim_thread_spawn(grim_thread_t *thread, bool joinable,
                      grim_start_t start_routine, void *arg)
{
#if HAVE_THREADS == HAVE_THREADS_C11
    int ret = thrd_create(thread, start_routine, arg);
#elif HAVE_THREADS == HAVE_THREADS_PTHREADS
    int ret = pthread_create(thread, NULL, start_routine, arg);
#endif
    if (!joinable) {
        grim_thread_detach(*thread);
    }
    return ret;
}

int grim_thread_detach(grim_thread_t thread)
{
#if HAVE_THREADS == HAVE_THREADS_C11
    return thrd_detach(thread);
#elif HAVE_THREADS == HAVE_THREADS_PTHREADS
    return pthread_detach(thread);
#endif
}

int grim_thread_join(grim_thread_t thread, int *result)
{
#if HAVE_THREADS == HAVE_THREADS_C11
    return thrd_join(thread, result);
#elif HAVE_THREADS == HAVE_THREADS_PTHREADS
    return pthread_join(thread, (void **)&result);
#endif
}

grim_thread_t grim_thread_current(void)
{
#if HAVE_THREADS == HAVE_THREADS_C11
    return thrd_current();
#elif HAVE_THREADS == HAVE_THREADS_PTHREADS
    return pthread_self();
#endif
}

void grim_thread_exit(int *result)
{
#if HAVE_THREADS == HAVE_THREADS_C11
    thrd_exit(*result);
#elif HAVE_THREADS == HAVE_THREADS_PTHREADS
    pthread_exit((void *)result);
#endif
}
