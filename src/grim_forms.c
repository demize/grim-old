//===--- grim_forms.c - Functions for displaying and controlling forms ----===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the implementations of the functions grim uses to create,
//! display, and control forms.
//!
//===----------------------------------------------------------------------===//

#include "grim_forms.h"

#include <newt.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// sizes for entry boxes
// minus one because strings have a NULL terminator
static const int size_256 = 254;
static const int size_512 = 510;
static const int size_1024 = 1020;

static int length_filter(newtComponent entry __attribute__((unused)),
                          void *data, int ch, int cursor)
{
    int length = *(int *)data;
    if (NEWT_KEY_DELETE == ch || NEWT_KEY_BKSPC == ch) {
        return ch;
    }
    if (NEWT_KEY_UP == ch || NEWT_KEY_DOWN == ch || NEWT_KEY_LEFT == ch
        || NEWT_KEY_RIGHT == ch || NEWT_KEY_ENTER == ch) {
        return ch;
    }
    if (cursor >= length) {
        return 0;
    }
    return ch;
}

form_return showExaminerInfoForm(grim_ewfargs *args)
{
    // Need strings to store user's answers
    const char *examiner_name;
    const char *case_number;
    const char *evidence_number;
    const char *description;
    const char *notes;

    // Build the entry boxes
    newtComponent name_entry = newtEntry(1, 1, args->examiner_name, 74,
                                         &examiner_name, NEWT_ENTRY_SCROLL);
    newtComponent case_entry = newtEntry(1, 4, args->case_number, 74,
                                         &case_number, NEWT_ENTRY_SCROLL);
    newtComponent evidence_entry = newtEntry(
        1, 7, args->evidence_number, 74, &evidence_number, NEWT_ENTRY_SCROLL);
    newtComponent desc_entry = newtEntry(1, 10, args->description, 74,
                                         &description, NEWT_ENTRY_SCROLL);
    newtComponent notes_entry
        = newtEntry(1, 13, args->notes, 74, &notes, NEWT_ENTRY_SCROLL);

    // Set the filter for maximum length
    newtEntrySetFilter(name_entry, length_filter, (void *)&size_256);
    newtEntrySetFilter(case_entry, length_filter, (void *)&size_256);
    newtEntrySetFilter(evidence_entry, length_filter, (void *)&size_256);
    newtEntrySetFilter(desc_entry, length_filter, (void *)&size_1024);
    newtEntrySetFilter(notes_entry, length_filter, (void *)&size_1024);

    // Build the labels
    newtComponent name_label = newtLabel(1, 0, "Examiner name:");
    newtComponent case_label = newtLabel(1, 3, "Case number:");
    newtComponent evidence_label = newtLabel(1, 6, "Evidence number:");
    newtComponent desc_label = newtLabel(1, 9, "Description:");
    newtComponent notes_label = newtLabel(1, 12, "Notes:");

    // Build the buttons
    newtComponent next_button = newtCompactButton(16, 17, "Next");
    newtComponent exit_button = newtCompactButton(52, 17, "Exit");

    // Create the form, add the components to it, and run it
    newtComponent info_form = newtForm(NULL, NULL, 0);

    newtFormAddComponents(info_form, name_entry, case_entry, evidence_entry,
                          desc_entry, notes_entry, name_label, case_label,
                          evidence_label, desc_label, notes_label, next_button,
                          exit_button, NULL);

    createWindowCenter(20, 76, "Basic Information");
    newtComponent pressedButton = newtRunForm(info_form);

    // Next or exit?
    if(pressedButton == exit_button)
    {
        newtFormDestroy(info_form);
        newtPopWindow();
        return form_exit;
    }
    // only other choice is next or F12, both of which count as "continue"
    // copy the strings, making sure to leave the last character NULL
    strncpy(args->examiner_name, examiner_name, 255);
    strncpy(args->case_number, case_number, 255);
    strncpy(args->evidence_number, evidence_number, 255);
    strncpy(args->description, description, 1023);
    strncpy(args->notes, notes, 1023);

    newtFormDestroy(info_form);
    newtPopWindow();

    return form_next;
}

form_return showRequiredForm(grim_ewfargs *args)
{
    // Build bytes per sector listbox
    newtComponent num_sectors_list
        = newtListbox(30, 0, 5, NEWT_FLAG_SCROLL | NEWT_FLAG_BORDER);
    newtListboxAppendEntry(num_sectors_list, "16 Bytes", (void *)SECTORS_16);
    newtListboxAppendEntry(num_sectors_list, "32 Bytes", (void *)SECTORS_32);
    newtListboxAppendEntry(num_sectors_list, "64 Bytes", (void *)SECTORS_64);
    newtListboxAppendEntry(num_sectors_list, "128 Bytes", (void *)SECTORS_128);
    newtListboxAppendEntry(num_sectors_list, "256 Bytes", (void *)SECTORS_256);
    newtListboxAppendEntry(num_sectors_list, "512 Bytes", (void *)SECTORS_512);
    newtListboxAppendEntry(num_sectors_list, "1 Kilobyte",
                           (void *)SECTORS_1024);
    newtListboxAppendEntry(num_sectors_list, "2 Kilobytes",
                           (void *)SECTORS_2048);
    newtListboxAppendEntry(num_sectors_list, "4 Kilobytes",
                           (void *)SECTORS_4096);
    newtListboxAppendEntry(num_sectors_list, "8 Kilobytes",
                           (void *)SECTORS_8192);
    newtListboxAppendEntry(num_sectors_list, "16 Kilobytes",
                           (void *)SECTORS_16384);
    newtListboxAppendEntry(num_sectors_list, "32 Kilobytes",
                           (void *)SECTORS_32768);

    // Set the current selection to the selection in the arguments and center it
    grim_num_sectors next = args->num_sectors + 1;
    newtListboxSetCurrentByKey(num_sectors_list, (void *)next);
    newtListboxSetCurrentByKey(num_sectors_list, (void *)(args->num_sectors));
    // Set the width of the listbox
    newtListboxSetWidth(num_sectors_list, 45);

    // Create the label for the listbox
    newtComponent num_sectors_label = newtLabel(0, 2, "Bytes per sector:");

    // Build the buttons
    newtComponent next_button = newtCompactButton(16, 17, "Next");
    newtComponent back_button = newtCompactButton(34, 17, "Back");
    newtComponent exit_button = newtCompactButton(52, 17, "Exit");

    // Add everything to the form and display the form
    newtComponent page_one = newtForm(NULL, NULL, 0);
    newtFormAddComponents(page_one, num_sectors_list, num_sectors_label,
                          next_button, back_button, exit_button, NULL);

    createWindowCenter(20, 76, "Required Information");
    newtComponent pressedButton = newtRunForm(page_one);

    // actually use the input...

    if(pressedButton == exit_button)
    {
        newtFormDestroy(page_one);
        newtPopWindow();
        return form_exit;
    }
    else if(pressedButton == back_button)
    {
        newtFormDestroy(page_one);
        newtPopWindow();
        return form_prev;
    }

    newtFormDestroy(page_one);
    newtPopWindow();

    return form_exit;
}
