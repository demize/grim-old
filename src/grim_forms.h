//===--- grim_forms.h - Functions for displaying and controlling forms ----===//
//
//                                grim Project
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//!
//! \file
//! This file contains the declarations for the functions grim uses to create,
//! display, and control forms.
//!
//===----------------------------------------------------------------------===//

#ifndef GRIM_FORMS_H
#define GRIM_FORMS_H

#include "grim_ewfutils.h"
#include "windowutils.h"

#include <newt.h>

//! Defines possible return values for forms: either the user selected to go to
//! the previous page, the next page, or exit.
typedef enum
{
    form_prev,
    form_next,
    form_exit
} form_return;

//! \brief Collect information about the case and the examiner.
//!
//! Displays the form asking for information about the examiner and the case.
//! Stores the user's answers in the provided `grim_ewfargs` structure. Uses the
//! values already present in that structure as the defaults, if present. The
//! structure must be initialized with `init_ewfargs()` prior to this function
//! being called.
//!
//! \param [in,out] args The structure containing the arguments to pass
//! to ewfacquirestream.
//!
//! \return A `form_return` value saying which button the user selected.
form_return showExaminerInfoForm(grim_ewfargs *args);

//! \brief Collect the information that's required to image a drive.
//!
//! Displays the forms asking for basic information relating to the image and
//! stores the user's answers in the provided `grim_ewfargs` structure. Uses the
//! values already present in that structure as the defaults, if present. The
//! structure must be initialized with `init_ewfargs()` prior to this function
//! being called.
//!
//! \param [in,out] args The structure containing the arguments to pass
//! to ewfacquirestream.
//!
//! \return A `form_return` value saying which button the user selected.
form_return showRequiredForm(grim_ewfargs *args);

#endif
