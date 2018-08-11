//===--- grim_menus.c - Functions for displaying and controlling menus ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the implementations of the functions grim uses to create,
//! display, and control menus.
//!
//===----------------------------------------------------------------------===//

#include "grim_menus.h"

#include <string.h>

static const char *main_choices[][2]
    = {{"Image", "Image a hard drive"},
       {"Settings", "Configure default settings"},
       {"Exit", "Exit grim"}};

//! \brief Initializes an ncurses ITEM** array with the given list of choices.
//!
//! \param [out] items A pointer to an ITEM** array where the items will be set
//! up.
//!                The array must not be initialized.
//!
//! \param choices A two-dimensional array of choices/descriptions.
//!
//! \param num_choices The number of items in the choices array.
static void init_menu_items(ITEM ***items, const char *choices[][2],
                            size_t num_choices)
{
    *items = calloc(num_choices + 2, sizeof(ITEM *));
    for (size_t i = 0; i < num_choices; ++i) {
        (*items)[i] = new_item(choices[i][0], choices[i][1]);
    }
    (*items)[num_choices] = (ITEM *)NULL;
}

//! \brief Generate coordinates to center a menu's subwindow.
//!
//! \param win The window containing the menu.
//!
//! \param menu The menu to center.
//!
//! \param [out] rows Will contain the number of rows to allocate for the
//! subwindow.
//!
//! \param [out] cols Will contain the number of cols to allocate for the
//! subwindow.
//!
//! \param [out] xpos Will contain the subwindow's x position.
//!
//! \param [out] ypos Will contain the subwindow's y position.
static void center_menu_sub(WINDOW *win, MENU *menu, int *rows, int *cols,
                            int *xpos, int *ypos)
{
    scale_menu(menu, rows, cols);
    int xdim = getmaxx(win);
    int ydim = getmaxy(win) - 1;
    *xpos = (xdim - *cols) / 2;
    *ypos = ((ydim - *rows) / 2) + 1;
}

//! \brief Prints the title for a menu.
//!
//! \param win The window containing the menu.
//!
//! \param title The title to print.
static void print_menu_title(WINDOW *win, const char *title)
{
    int length = strlen(title);
    int width = getmaxx(win);
    int x = (width - length) / 2;
    wattron(win, COLOR_PAIR(56));
    mvwprintw(win, 0, x, "%s", title);
    wattroff(win, COLOR_PAIR(56));
}

int do_main_menu(WINDOW *win)
{
    keypad(win, true);
    ITEM **menu_items;
    init_menu_items(&menu_items, main_choices, 3);
    MENU *menu = new_menu(menu_items);
    int rows, cols, xpos, ypos;
    set_menu_mark(menu, "*");
    center_menu_sub(win, menu, &rows, &cols, &xpos, &ypos);
    set_menu_win(menu, win);
    set_menu_sub(menu, derwin(win, rows, cols, ypos, xpos));

    box(win, 0, 0);
    print_menu_title(win, "grim Menu");
    refresh();

    set_menu_fore(menu, COLOR_PAIR(63));
    set_menu_back(menu, COLOR_PAIR(0));
    set_menu_grey(menu, COLOR_PAIR(48));

    post_menu(menu);
    wrefresh(win);

    int choice = -1;
    int c;
    while ((c = wgetch(win)) != KEY_ENTER && c != 10 && c != 13) {
        switch (c) {
        case KEY_DOWN:
            menu_driver(menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(menu, REQ_UP_ITEM);
            break;
        }
    }
    choice = item_index(current_item(menu));

    unpost_menu(menu);
    free_menu(menu);
    for (int i = 0; i < 3; ++i) {
        free_item(menu_items[i]);
    }
    free(menu_items);
    return choice;
}
