//===--- thread_test.c - Functions for displaying and controlling menus ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains a basic unit test for grim's threading.
//!
//===----------------------------------------------------------------------===//

#include "threadutils.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

static GRIM_CALLBACK thread_func(void *args)
{
    grim_thread_args *casted = (grim_thread_args *)args;
    for (int i = 0; i < 10; ++i) {
        *(casted->bytes_read) += 1;
        *(casted->bytes_total) -= 1;
    }
    int *result = calloc(1, sizeof(int));
    grim_thread_exit(result);
}

int main()
{
    atomic_uint_fast64_t bytes_read = 0, bytes_total = 10;

    grim_thread_args *args = malloc(sizeof(grim_thread_args));
    args->bytes_read = &bytes_read;
    args->bytes_total = &bytes_total;
    args->input_file = "none";
    args->input_file_l = 4;
    args->pipefd_w = 0;

    grim_thread_t thread;

    if (grim_thread_spawn(&thread, true, &thread_func, args) != 0) {
        return 2;
    }

    int result;

    for (int i = 0; i < 10; i++) {
        printf("read: %" PRIu64 ", total: %" PRIu64 "\n", bytes_read,
               bytes_total);
    }

    grim_thread_join(thread, &result);

    if (bytes_read == 10 && bytes_total == 0) {
        return 0;
    } else {
        printf("Expected 10 and 0, got %" PRIu64 " and %" PRIu64 "\n",
               bytes_read, bytes_total);
        return 1;
    }
}
