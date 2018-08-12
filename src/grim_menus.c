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

#include "windowutils.h"

#include <string.h>

static const char *main_choices[]
    = {"Image:    Image a hard drive", "Settings: Configure default settings",
       "Exit:     Exit grim"};

int showMainMenu()
{
    int width = max_from_three(strlen(main_choices[0]), strlen(main_choices[1]),
                               strlen(main_choices[2]))
                + 4;
    width += (width % 2);

    createWindowCenter(5, width, "grim");
    newtComponent form = newtForm(NULL, NULL, 0);
    newtComponent menubox = newtListbox(1, 1, 3, NEWT_FLAG_RETURNEXIT);

    for (size_t i = 0; i < 3; i++) {
        newtListboxAppendEntry(menubox, main_choices[i], (void *)i);
    }

    newtFormAddComponents(form, menubox, NULL);
    newtRunForm(form);

    int choice = -1;
    switch ((size_t)newtListboxGetCurrent(menubox)) {
    case 0:
        choice = 0;
        break;
    case 1:
        choice = 1;
        break;
    case 2:
        choice = 2;
        break;
    }

    newtFormDestroy(form);
    newtPopWindow();

    return choice;
}
