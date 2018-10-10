//===---            ewfutils.c - Utilities for use with libewf          ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the declarations for functions used to work with programs
//! from libewf, specifically ewfacquirestream and ewfverify.
//!
//===----------------------------------------------------------------------===//

#include "grim_ewfutils.h"

#include <stdlib.h>

void init_ewfargs(grim_ewfargs *args)
{
    args->source_device = calloc(256, sizeof(char));
    args->num_sectors = 0;
    args->compression_type = 0;
    args->case_number = calloc(256, sizeof(char));
    args->digest_type = 0;
    args->description = calloc(1024, sizeof(char));
    args->examiner_name = calloc(256, sizeof(char));
    args->evidence_number = calloc(256, sizeof(char));
    args->ewf_format = 0;
    args->notes = calloc(1024, sizeof(char));
    args->bytes_per_sector = 512;
    args->segment_file_size = calloc(256, sizeof(char));
    args->target = calloc(512, sizeof(char));
    args->secondary_target = calloc(512, sizeof(char));
}

void free_ewfargs(grim_ewfargs *args)
{
    free(args->source_device);
    free(args->case_number);
    free(args->description);
    free(args->examiner_name);
    free(args->evidence_number);
    free(args->notes);
    free(args->segment_file_size);
    free(args->target);
    free(args->secondary_target);
}
