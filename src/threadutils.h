#ifndef GRIM_THREADUTILS_H
#define GRIM_THREADUTILS_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#else
# error config.h not found, please run configure
#endif

#if HAVE_THREADS==HAVE_THREADS_C11
# include <threads.h>
#elif HAVE_THREADS==HAVE_THREADS_PTHREADS
# include <pthread.h>
#else
# error no thread library found
#endif

#include <stdatomic.h>

int ewf_thread_spawn

#endif
