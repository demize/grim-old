//===--- grim_menus.h - Functions for displaying and controlling menus ---===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the declarations for the functions grim uses to create,
//! display, and control menus.
//!
//===----------------------------------------------------------------------===//

#ifndef GRIM_MENUS_H
#define GRIM_MENUS_H

//! \brief Displays and handles the main menu.
//!
//! Displays a menu with options for "Image", "Settings", and "Exit", and
//! returns a value representing which option was selected:
//!
//! - 0 for Image
//! - 1 for Settings
//! - 2 for Exit
//!
//! \return An `int` representing the option the user selected.
int showMainMenu(void);

#endif
