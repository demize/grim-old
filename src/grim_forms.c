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

#include <newt.h>
#include <stdbool.h>
#include <stdlib.h>

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
static void showRequiredPageOne(grim_ewfargs *args)
{
    newtComponent sector_16 = newtRadiobutton(0, 0, " 16  ", 0, NULL);
    newtComponent sector_32 = newtRadiobutton(0, 1, " 32  ", 0, sector_16);
    newtComponent sector_64 = newtRadiobutton(0, 2, " 64  ", 0, sector_32);
    newtComponent sector_128 = newtRadiobutton(0, 3, " 128 ", 0, sector_64);
    newtComponent sector_256 = newtRadiobutton(1, 0, " 256 ", 0, sector_128);
    newtComponent sector_512 = newtRadiobutton(1, 1, " 512 ", 1, sector_256);
    newtComponent sector_1024 = newtRadiobutton(1, 2, " 1024 ", 0, sector_512);
    newtComponent sector_2048 = newtRadiobutton(1, 3, " 2048 ", 0, sector_1024);
    newtComponent sector_4096 = newtRadiobutton(2, 0, " 4096 ", 0, sector_2048);
    newtComponent sector_8192 = newtRadiobutton(2, 1, " 8192 ", 0, sector_4096);
    newtComponent sector_16384 = newtRadiobutton(2, 2, "16384", 0, sector_8192);
    newtComponent sector_32768
        = newtRadiobutton(2, 2, "32768", 0, sector_16384);

    newtGrid sector_grid_row1 = newtGridHStacked(
        NEWT_GRID_COMPONENT, sector_16, NEWT_GRID_COMPONENT, sector_32,
        NEWT_GRID_COMPONENT, sector_64, NEWT_GRID_COMPONENT, sector_128,
        NEWT_GRID_EMPTY, NULL);
    newtGrid sector_grid_row2 = newtGridHStacked(
        NEWT_GRID_COMPONENT, sector_256, NEWT_GRID_COMPONENT, sector_512,
        NEWT_GRID_COMPONENT, sector_1024, NEWT_GRID_COMPONENT, sector_2048,
        NEWT_GRID_EMPTY, NULL);
    newtGrid sector_grid_row3 = newtGridHStacked(
        NEWT_GRID_COMPONENT, sector_4096, NEWT_GRID_COMPONENT, sector_8192,
        NEWT_GRID_COMPONENT, sector_16384, NEWT_GRID_COMPONENT, sector_32768,
        NEWT_GRID_EMPTY, NULL);

    newtGrid sector_grid_combined = newtGridVStacked(
        NEWT_GRID_SUBGRID, sector_grid_row1, NEWT_GRID_SUBGRID,
        sector_grid_row2, NEWT_GRID_SUBGRID, sector_grid_row3, NEWT_GRID_EMPTY,
        NULL);

    newtComponent page_one = newtForm(NULL, NULL, 0);
    newtGridWrappedWindow(sector_grid_combined, "Sector Size");
    newtGridAddComponentsToForm(sector_grid_combined, page_one, true);

    int width, height;
    newtComponentGetSize(page_one, &width, &height);

    newtRunForm(page_one);
}

grim_ewfargs showRequiredForm()
{
    grim_ewfargs ret;
    showRequiredPageOne(&ret);
    return ret;
}
