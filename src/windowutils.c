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

WINDOW *createWindow(int height, int width, int starty, int startx)
{
    WINDOW *win = newwin(height, width, starty, startx);
    wrefresh(win);

    return win;
}

WINDOW *createWindowBorder(int height, int width, int starty, int startx)
{
    WINDOW *win = newwin(height, width, starty, startx);
    box(win, 0, 0);
    wrefresh(win);

    return win;
}

void destroyWindow(WINDOW *win)
{
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win);
    delwin(win);
}

void initCurses()
{
    initscr();
    cbreak(); // disable input buffering
    noecho(); // prevent characters typed from echoing unless we want them to
    nonl();   // disable newline from enter key
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE); // enable use of arrow keys/etc
    initCDKColor();

    refresh(); // Make sure the screen is ready to print to
}
