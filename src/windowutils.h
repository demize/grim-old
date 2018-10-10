//===---       windowutils.c - Functions for working with windows       ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the declarations for functions useful for working with
//! windows. These functions may be used by multiple different parts of grim.
//!
//===----------------------------------------------------------------------===//

#ifndef GRIM_CURSES_H
#define GRIM_CURSES_H

#ifdef HAVE_CONFIG_H
#    include "config.h"
#else
#    error config.h not found, please run meson
#endif

#include <newt.h>

//! Creates a window with the specified dimensions.
//!
//! \param height The height of the window to draw.
//!
//! \param width The width of the window to draw.
//!
//! \param top The y-position to start drawing the window at.
//!
//! \param left The x-position to start drawing the window at.
//!
//! \param title The title of the window.
void createWindow(unsigned int height, unsigned int width, int top, int left,
                  const char *title);

//! Creates a centered window with the specified dimensions.
//!
//! \param height The height of the window to draw.
//!
//! \param width The width of the window to draw.
//!
//! \param title The title of the window.
void createWindowCenter(unsigned int height, unsigned int width,
                        const char *title);

//! Destroys the last window created.
void destroyWindow(void);

//! Initializes newt.
void initNewt(void);

//! Calculate the maximum of a list of numbers.
//!
//! \param numargs The number of arguments provided to the function.
//!
//! \param ... The numbers (as unsigned int) to find the maximum of.
unsigned int max_from_n(unsigned int numargs, ...);

/*
 * Use newt's wstrlen function for calculating string length
 */
extern int _newt_wstrlen(const char *, int);
#define wstrlen(str) _newt_wstrlen((str), -1)

#endif
