# ewfimager
`ewfimager` is an ncurses-based GUI for libewf, designed for use as part of a forensic boot CD. Its planned features include:

- Acquisition of a hard drive to E01 or Ex01 format
- Writing a single image to multiple destinations
- Automatic verification of written images
- File-based configuration of common settings, to allow for faster, easier, and less mistake-prone in-field use

ewfimager is a work in progress, and the list of planned features is subject to change.

## Building

To build ewfimager, you need the following installed:

- A C compiler
- ncursesw
- pkg-config
- libewf

The easiest way to get there on Ubuntu is `apt install build-essential pkg-config libncursesw5-dev libewf-dev`. Once you have the requirements installed, you can build the project as such:

1. `mkdir build`
2. `meson src build`
3. `cd build && ninja`
