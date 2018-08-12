//===--- grim_forms.c - Functions for displaying and controlling forms ----===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the implementations of the functions grim uses to create,
//! display, and control forms.
//!
//===----------------------------------------------------------------------===//

#include "grim_forms.h"

//! \brief Show the first page of the required information.
//!
//! The first page is general information about the acquistion:
//!
//! - Source device
//! - Number of sectors to read at once
//! - Output file format
//! - Digest and compression type
//! - Whether to segment, and what segment size to use
//!
//! \param [out] args The `grim_ewfargs` struct containing all the collected
//! args for ewfacquirestream.
//!
//! \param screen The CDKSCREEN to draw on.
static void showRequiredPageOne(grim_ewfargs *args, CDKSCREEN *screen)
{
    return;
}

grim_ewfargs showRequiredForm(WINDOW *win)
{
    CDKSCREEN *form_window = initCDKScreen(win);
    grim_ewfargs ret;

    eraseCDKScreen(form_window);
    return ret;
}
