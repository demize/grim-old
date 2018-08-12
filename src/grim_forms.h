//===--- grim_forms.h - Functions for displaying and controlling forms ----===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the declarations for the functions grim uses to create,
//! display, and control forms.
//!
//===----------------------------------------------------------------------===//

#ifndef GRIM_FORMS_H
#define GRIM_FORMS_H

#include "cursesutils.h"

//! Defines acceptable values for num_sectors.
typedef enum
{
    SECTORS_16,
    SECTORS_32,
    SECTORS_64,
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
    COMPRESSION_NONE,
    COMPRESSION_EMPTY_BLOCK,
    COMPRESSION_FAST,
    COMPRESSION_BEST
} grim_compression;

//! Defines acceptable values for digest_type.
typedef enum
{
    DIGEST_SHA1 = (1 << 0),
    DIEGST_SHA256 = (1 << 1)
} grim_digest_type;

//! Defines acceptable values for ewf_format.
typedef enum
{
    FORMAT_FTK,
    FORMAT_ENCASE2,
    FORMAT_ENCASE3,
    FORMAT_ENCASE4,
    FORMAT_ENCASE5,
    FORMAT_ENCASE6,
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
    const char source_device[256];
    grim_num_sectors num_sectors;
    grim_compression compression_type;
    const char case_number[256];
    grim_digest_type digest_type;
    const char description[1024];
    const char examiner_name[256];
    const char evidence_number[256];
    grim_ewf_format ewf_format;
    const char notes[1024];
    const char segment_file_size[256];
    const char target[256];
    const char secondary_target[256];
} grim_ewfargs;

//! \brief Display the form for required information and return the user's
//! input.
//!
//! Takes in an ncurses WINDOW to display the form in and returns an instance of
//! `grim_ewfargs` containing the user's input.
//!
//! \param win The window to display the form in. Should be empty.
//!
//! \return An instance of `grim_ewfargs`.
grim_ewfargs showRequiredForm(WINDOW *win);

#endif
