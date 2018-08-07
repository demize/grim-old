# Contributing to grim

Thanks for your interest in contributing to grim! This document was written to
make sure the codebase is in a consistent format and assist anyone who wishes to
contribute in the future.

`grim` was written in an attempt to provide something useful to the forensic
community. Contributions are therefore absolutely welcome! We just ask that you
try to follow these guidelines when contributing to ensure both that everyone
feels welcome, and that the code is consistent and easily readable.

## Code of Conduct

Please abide by our
[Code of Conduct](https://github.com/demize/grim/blob/master/CODE_OF_CONDUCT.md)
at all times when participating in the community.

## How to Contribute
### Bug Reports

One of the easiest ways to contribute is to use grim and report any issues you
find. 

Before opening a new issue for a bug, confirm you're using the latest version of
grim. If not, try to reproduce the issue on the latest version. If you still
encounter the issue in the latest version, we then ask that you check the open
issues and refrain from opening a new issue if one already exists describing 
your bug.

If you find an existing issue describing your bug, please add any additional
information you have to that issue. Additional information is always useful when
trying to track down a bug!

If there is no existing issue, please open a new one and follow the bug report
template. To write a good bug report, use a clear and descriptive title, and
describe in detail the issue you encountered, including clear and concise steps
to reproduce. If you're able to help debug and troubleshoot, please let us know,
as sometimes an issue may be hardware-specific.

### Feature Requests

If you regularly use grim and would like to request we add a new feature, that's
great too! Submitting a feature request is a lot like submitting a bug report:
before submitting one, you should make sure it hasn't already been implemented
and that nobody else has requested it. When submitting a feature request, please
follow the feature request template.

### Your First Contribution

If you're not sure where to begin, take a look at the 
[good first issue](https://github.com/demize/grim/issues?q=is%3Aissue+is%3Aopen+label%3A%22good+first+issue%22)
tag. Issues tagged as a good first issue are a good introduction to grim's
codebase, and so they should be a good first issue for a newcomer. Note that
they aren't necessarily good issues for someone new to C programming, but if you
*are* new to C programming, feel free to try one out!

### Pull Requests

When submitting a pull request, please make sure it follows the style guides
(discussed below), does not break any existing code, and does not have any major
warnings when compiled/linted. `clang` can be used as a linter with the options
`-Wall -pedantic -Wextra -fsyntax-only -fno-caret-diagnostics`. If you use
Sublime Text, you can install the SublimeLinter and SublimeLinter-clang plugins
and this will happen automatically.

When submitting a pull request, you *must* use the provided template. Your pull
request title should be a clear and concise description of the changes you made,
and should not directly reference any issues (by name or number). The template
has three sections for description: one describing the change generally, one for
the benefits of the change, and one for the drawbacks of the change. These
sections should be as descriptive as possible.

## Coding Style

Aside from documentation comments, grim uses a slightly modified LLVM coding
style. To start with, you can reference
[LLVM's coding standards](http://llvm.org/docs/CodingStandards.html).

Aside from some other divergences, described below, our modifications to LLVM's
coding style are:

- Use Mozilla style line breaks before braces; that is, put the braces on
  their own lines after enum and function definitions but attach them to other
  structures.
- A function should never be combined onto a single line.
- In the case that an operation with binary operators spans multiple lines,
  place the line break before the operators.
- Preprocessor directives should be indented after the hash.
- Use an indent width of 4 and a tab width of 4.

The other divergences are described below.

If you use `clang-format`, we provide a `.clang-format` file in the src
directory that can be used to follow these guidelines; other parts of the coding
style cannot be enforced by clang-format, though, and must be checked manually.

### File Header

As per the LLVM coding standards, each file should have a header at the top. The
general format of the header is as follows:

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

Keep the \file documentation comment brief; any additional documentation should
be done at the function level.

### Includes

If your code depends on anything defined by meson during configuration, the very
first line of the header (after the header guards) should be:

    #ifdef HAVE_CONFIG_H
    #    include "config.h"
    #else
    #    error config.h not found, please run meson
    #endif

If you don't need to include config.h, then this isn't necessary. Similarly, try
to keep includes to a minimum; this reduces code complexity and improves compile
times. If your header file includes another header, don't include it again from
the source file.

### Variable Naming

While the rest of the naming conventions in the LLVM style guide are acceptable,
variables should start with a *lowercase* letter and use camel case.

### Commenting

While the LLVM style guide says to use C-style comments for C code, we prefer
C++ style comments. Comment generously, and especially when writing complex
code.

## Documentation Style

While `grim` is not a library and does not install any headers, for the purposes
of collaboration it is important to properly document all code. For this, we use
Doxygen-style documentation comments. Some of our rules are the same as the LLVM
rules, however most are not:

- At a minimum, document at the file level for every file, and at the function
  level for every header file.
- Use the QT-style `//!` for documentation comments to more easily distinguish
  them from regular comments.
- Begin each documentation comment (aside from file-level comments) with a
  \brief section that is no longer than two sentences long.
- Use `\p` when discussing parameters inline.
- Ensure each parameter is documented with a \param paragraph, and each input
  or input/output parameter is specified as such (`\param [in,out] x`).
- Don't duplicate documentation between the header and implementation files:
  in implementation files, document implementations that are not declared in
  the header file only.
- Don't duplicate function or class names at the beginning of documentation
  comments.

## License and Attribution

This file is distributed under the MIT license. See LICENSE for details.

This file is based on portions of the [Atom Contribution Guide](https://github.com/atom/atom/blob/ca71d581036ed093dd2df964fcc9bec0b5f7ff0d/CONTRIBUTING.md)
and the LLVM coding style guide.
