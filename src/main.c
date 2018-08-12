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

#include "grim_forms.h"
#include "grim_menus.h"
#include "windowutils.h"

#include <signal.h>
#include <stdlib.h>
#include <string.h>

/*
 * Print the welcome message
 */
static void print_welcome()
{
    const char *line1 = "grim " PACKAGE_VERSION;
    const char *line2 = "Visit our Github at github.com/demize/grim.";
    const char *line3 = "Comments can be addressed to demize@unstable.systems.";
    const char *continueText = "Continue";
    int width = max_from_three(strlen(line1), strlen(line2), strlen(line3)) + 4;
    width += width % 2; // Make sure the width is even
    int height = 5;

    createWindowCenter(height, width, line1);

    newtComponent form, label1, label2, continueButton;

    int label1left = (width - strlen(line2)) / 2;
    int label2left = (width - strlen(line3)) / 2;
    label1 = newtLabel(label1left, 1, line2);
    label2 = newtLabel(label2left, 2, line3);
    int startx = ((width - strlen(continueText)) / 2) - 2;
    continueButton = newtCompactButton(startx, 4, continueText);

    form = newtForm(NULL, NULL, 0);
    newtFormAddComponents(form, label1, label2, continueButton, NULL);

    newtRunForm(form);

    newtFormDestroy(form);
    newtPopWindow();
}

/*
 * Tidy up before exit
 */
static void finish()
{
    newtFinished();
    exit(0);
}

int main()
{
    signal(SIGINT, finish);
    signal(SIGSEGV, finish);

    initNewt();
    print_welcome();

    switch (showMainMenu()) {
    case 0:
        showRequiredForm();
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
