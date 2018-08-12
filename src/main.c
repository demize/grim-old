//===---               main.c - The entry point for grim                ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the entry point for grim, as well as the initialization
//! of ncurses, and coordinates action with other parts of the program.
//!
//===----------------------------------------------------------------------===//

#include "cursesutils.h"
#include "grim_menus.h"

#include <signal.h>
#include <stdlib.h>
#include <string.h>

/*
 * Calculate the maximum of five numbers, used in the welcome message
 */
static inline int max_from_five(int a, int b, int c, int d, int e)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;
    if (e > max)
        max = e;
    return max;
}

/*
 * Print a string padded to fit in the center of width
 */
static void print_padded(WINDOW *win, const char *str, int width)
{
    int padding = (width - strlen(str)) / 2;
    for (int i = 0; i < padding; i++)
        wprintw(win, " ");
    wprintw(win, str);
    wprintw(win, "\n");
    wrefresh(win);
}

/*
 * Print the welcome message
 */
static void print_welcome()
{
    curs_set(0); // Remove the cursor for the welcome screen
    const char *line1 = "grim " PACKAGE_VERSION;
    const char *line2 = "Visit our Github at github.com/demize/grim.";
    const char *line3 = "Comments can be addressed to demize@unstable.systems.";
    const char *line4 = "";
    const char *line5 = "Press any key to continue.";
    int width = max_from_five(strlen(line1), strlen(line2), strlen(line3),
                              strlen(line4), strlen(line5))
                + 4;
    width += width % 2; // Make sure the width is even
    int height = 5;

    int starty = (LINES - height) / 2;
    int startx = (COLS - width) / 2;

    WINDOW *text_win = createWindow(height, width, starty, startx);
    WINDOW *border_win
        = createWindowBorder(height + 2, width + 2, starty - 1, startx - 1);

    wattron(text_win, A_BOLD); // Make the version text bold
    print_padded(text_win, line1, width);
    wattroff(text_win, A_BOLD); // Make the rest of the text not
    print_padded(text_win, line2, width);
    print_padded(text_win, line3, width);
    print_padded(text_win, line4, width);
    print_padded(text_win, line5, width);

    getch(); // Wait for a key to be pressed
    destroyWindow(text_win);
    destroyWindow(border_win);
    curs_set(1); // Return the cursor for the rest of the program
}

/*
 * Tidy up before exit
 */
static void finish()
{
    endwin();
    exit(0);
}

int main()
{
    signal(SIGINT, finish);

    initCurses();
    print_welcome();

    WINDOW *main_win = createWindow(LINES - 2, COLS - 2, 1, 1);
    switch (showMainMenu(main_win)) {
    case 0:
        // Start imaging
        break;
    case 1:
        // Start settings menu
        break;
    case 2:
        // Exit
        finish();
    }

    finish();
}
