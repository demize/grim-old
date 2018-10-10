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

#include <stdarg.h>

void createWindow(unsigned int height, unsigned int width, int top, int left,
                  const char *title)
{
    newtOpenWindow(left, top, width, height, title);
}

void createWindowCenter(unsigned int height, unsigned int width,
                        const char *title)
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

unsigned int max_from_n(unsigned int numargs, ...)
{
    unsigned int max = 0;

    va_list argp;
    va_start(argp, numargs);
    for (unsigned int i = numargs; i > 0; --i) {
        unsigned int current = va_arg(argp, unsigned int);
        if (current > max) {
            max = current;
        }
    }

    return max;
}
