# grim
`grim` is an ncurses-based GUI for libewf, designed for use as part of a forensic boot CD. Its planned features include:

- Acquisition of a hard drive to E01 or Ex01 format
- Writing a single image to multiple destinations
- Automatic verification of written images
- File-based configuration of common settings, to allow for faster, easier, and less mistake-prone in-field use

grim is a work in progress, and the list of planned features is subject to change.

## Building

To build grim, you need the following installed:

- A C compiler
- ncursesw
- cdk
- pkg-config

You also need ewf-tools.

The easiest way to get there on Ubuntu is `apt install build-essential pkg-config libncursesw5-dev libcdk5-dev ewf-tools`. For Void Linux (which has more experimental support), `xbps-install -S [gcc or clang] pkg-config ncursesw-devel` will install most of the required packages, however you will need to build and install libewf and cdk yourself. Once you have the requirements installed, you can build the project as such:

1. `mkdir build`
2. `meson src build`
3. `cd build && ninja`
