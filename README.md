#42-get_next_line

## Introduction
The get_next_line project involves creating a function that reads a line from a file descriptor,

providing an opportunity to learn about a new concept in C programming: static variables.

The function is designed to return a line ending with a newline character from a file descriptor,

and returns NULL when all lines have been read or an error occurs.

## Features
A convenient way to read a line at a time from a file descriptor.

Handles reading from both files and standard input.

Efficient memory management, freeing up all heap allocated memory when necessary.

Ability to manage multiple file descriptors simultaneously (Bonus part).

## Installation
```sh
git clone https://github.com/Asrasal47/42-get_next_line.git
```

This will download the necessary files.

## Usage
Include the header file (get_next_line.h) in your C project:
>#include "get_next_line.h"

When compiling your project, link with the required files:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c your_c_file.c -o your_program_name
```
Replace 32 with the buffer size of your choice and your_c_file.c with the C file you want to compile.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
