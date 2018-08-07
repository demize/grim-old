//===---       cursesutils.h - Functions for working with ncurses       ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the implementations of functions useful for working with
//! ncurses. These functions may be used by multiple different parts of grim.
//!
//===----------------------------------------------------------------------===//

#include "cursesutils.h"

WINDOW *create_window(int height, int width, int starty, int startx)
{
    WINDOW *win = newwin(height, width, starty, startx);
    wrefresh(win);

    return win;
}

WINDOW *create_window_border(int height, int width, int starty, int startx)
{
    WINDOW *win = newwin(height, width, starty, startx);
    box(win, 0, 0);
    wrefresh(win);

    return win;
}

void destroy_window(WINDOW *win)
{
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win);
    delwin(win);
}

void init_curses()
{
    initscr();
    cbreak(); // disable input buffering
    noecho(); // prevent characters typed from echoing unless we want them to
    nonl();   // disable newline from enter key
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE); // enable use of arrow keys/etc
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);

    refresh(); // Make sure the screen is ready to print to
}
