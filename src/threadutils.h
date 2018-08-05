#ifndef GRIM_THREADUTILS_H
#define GRIM_THREADUTILS_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#else
# error config.h not found, please run configure
#endif

#if HAVE_THREADS==HAVE_THREADS_C11
# include <threads.h>
typedef thrd_start_t grim_start_t;
typedef thrd_t grim_thread_t;
typedef mtx_t grim_mtx_t;
typedef cnd_t grim_cnd_t;
#elif HAVE_THREADS==HAVE_THREADS_PTHREADS
# include <pthread.h>
typedef pthread_t grim_thread_t;
typedef void (*grim_start_t)(void *);
typedef pthread_mutex_t grim_mtx_t;
typedef pthread_cond_t grim_cnd_t;
#else
# error no thread library found
#endif

//////
// Thread functions
//////

/* 
pthread_create / thrd_create
 */
int grim_thread_spawn(grim_thread_t *thread, bool joinable, grim_start_t start_routine, void *arg);

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
void grim_thread_exit(int *result);

#endif
