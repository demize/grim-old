//===---       windowutils.c - Functions for working with windows       ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the implementations of functions useful for working with
//! windows. These functions may be used by multiple different parts of grim.
//!
//===----------------------------------------------------------------------===//

#include "windowutils.h"

void createWindow(int height, int width, int starty, int startx,
                  const char *title)
{
    newtOpenWindow(startx, starty, width, height, title);
}

void createWindowCenter(int height, int width, const char *title)
{
    newtCenteredWindow(width, height, title);
}

void destroyWindow()
{
    newtPopWindow();
}

void initNewt()
{
    newtInit();
    newtCls();
}

int max_from_three(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}