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

#if defined HAVE_NCURSESW_CURSES_H
#    include <ncursesw/curses.h>
#elif defined HAVE_NCURSESW_H
#    include <ncursesw.h>
#elif defined HAVE_CURSES_H
#    include <curses.h>
#else
#    error "ncursesw required"
#endif

#if defined HAVE_NCURSESW_PANEL_H
#    include <ncursesw/panel.h>
#elif defined HAVE_NCURSES_PANEL_H
#    include <ncurses/panel.h>
#elif defined HAVE_PANEL_H
#    include <panel.h>
#else
#    error "SysV-compatible Curses Panel header file required"
#endif

#if defined HAVE_NCURSESW_MENU_H
#    include <ncursesw/menu.h>
#elif defined HAVE_NCURSES_MENU_H
#    include <ncurses/menu.h>
#elif defined HAVE_MENU_H
#    include <menu.h>
#else
#    error "SysV-compatible Curses Menu header file required"
#endif

#if defined HAVE_NCURSESW_FORM_H
#    include <ncursesw/form.h>
#elif defined HAVE_NCURSES_FORM_H
#    include <ncurses/form.h>
#elif defined HAVE_FORM_H
#    include <form.h>
#else
#    error "SysV-compatible Curses Form header file required"
#endif

#if defined HAVE_CDK_H
#    include <cdk.h>
#elif defined HAVE_CDK_CDK_H
#    include <cdk/cdk.h>
#else
#    error "libcdk required"
#endif

WINDOW *createWindow(int height, int width, int starty, int startx);
WINDOW *createWindowBorder(int height, int width, int starty, int startx);
void destroyWindow(WINDOW *win);
void initCurses();

#endif
