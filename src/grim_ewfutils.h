//===---            ewfutils.h - Utilities for use with libewf          ---===//
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

#ifndef GRIM_EWFUTILS_H
#define GRIM_EWFUTILS_H

//! Defines acceptable values for num_sectors.
typedef enum
{
    SECTORS_16 = -2,
    SECTORS_32,
    SECTORS_64, // default
    SECTORS_128,
    SECTORS_256,
    SECTORS_512,
    SECTORS_1024,
    SECTORS_2048,
    SECTORS_4096,
    SECTORS_8192,
    SECTORS_16384,
    SECTORS_32768
} grim_num_sectors;

//! Defines acceptable values for compression_type.
typedef enum
{
    COMPRESSION_NONE, // default
    COMPRESSION_EMPTY_BLOCK,
    COMPRESSION_FAST,
    COMPRESSION_BEST
} grim_compression;

//! Defines acceptable values for digest_type.
typedef enum
{
    DIGEST_MD5 = 0, // libewf requires MD5, so this is okay
    DIGEST_SHA1 = (1 << 0),
    DIEGST_SHA256 = (1 << 1)
} grim_digest_type;

//! Defines acceptable values for ewf_format.
typedef enum
{
    FORMAT_FTK = -5,
    FORMAT_ENCASE2,
    FORMAT_ENCASE3,
    FORMAT_ENCASE4,
    FORMAT_ENCASE5,
    FORMAT_ENCASE6, // default
    FORMAT_ENCASE7,
    FORMAT_LINEN5,
    FORMAT_LINEN6,
    FORMAT_LINEN7,
    FORMAT_EWFX
} grim_ewf_format;

//! Holds all the user-provided information we collect so that it can be passed
//! to another function to begin imaging.
typedef struct
{
    char *source_device;
    grim_num_sectors num_sectors;
    grim_compression compression_type;
    char *case_number;
    grim_digest_type digest_type;
    char *description;
    char *examiner_name;
    char *evidence_number;
    grim_ewf_format ewf_format;
    char *notes;
    int bytes_per_sector;
    char *segment_file_size;
    char *target;
    char *secondary_target;
} grim_ewfargs;

//! \brief Initializes an ewfargs structure.
//!
//! Any enum members are initialized to zero, and all strings are allocated with
//! `calloc`. Remember to free this memory with `free_ewfargs()` once it's no
//! longer needed.
//!
//! \param [in,out] args The ewfargs structure to initialize.
void init_ewfargs(grim_ewfargs *args);

//! Frees the memory allocated by `init_ewfargs`.
//!
//! \param args The structure to free.
void free_ewfargs(grim_ewfargs *args);

int spawn_ewfacquirestream(int stdin_fd, int stdout_fd, grim_ewfargs ewfargs);

#endif
