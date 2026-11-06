This project has been created as part of the 42 curriculum by gearvani.

get_next_line

Description

The get_next_line project is a fundamental programming task in the 42 curriculum. The objective is to write a function in C that reads a single line ending with a newline character (\n) from a file descriptor (fd) each time it is called.

Goals & Key Concepts

Static Variables: Learning how to persist state between function calls to manage remaining buffered data across reads.

File I/O: Understanding system calls like read() and dealing with file descriptors.

Memory Management: Dynamically allocating, reallocating, and freeing memory to avoid leaks when working with arbitrary line lengths.

Buffer Management: Efficiently handling custom buffer sizes defined at compile time (BUFFER_SIZE).

Algorithm Explanation & Justification

The Challenge

When reading from a file descriptor using read(), data is fetched in chunks of size BUFFER_SIZE. These chunks rarely align perfectly with line breaks (\n). As a result, a single read() call might contain:

Part of a line.

An exact single line.

Multiple lines.

The end of a line followed by the beginning of the next line.

Algorithm Steps

Read into Buffer:
Call read() using a temporary buffer of size BUFFER_SIZE until a newline character (\n) is found within the accumulated data or until EOF (End Of File) is reached.

Accumulate via Static Storage:
Append the newly read buffer to a static string variable (stash). The static keyword ensures that any leftover characters after a newline character are retained across subsequent calls to get_next_line.

Extract the Line:
Scan the stash up to the first newline character (or EOF). Allocate memory for the line, copy the characters (including \n if present), and prepare it as the return value.

Update Stash:
Trim the stash so that it only retains the remaining characters after the newline character. If no remaining characters exist, free the stash and set it to NULL.

Justification

Static Variable Efficiency: Using a static variable acts as an in-memory residual buffer, eliminating the need for complex global state or secondary temp files.

Dynamic String Concatenation: Concatenating buffer chunks into the static stash allows get_next_line to seamlessly process lines of arbitrary or dynamic length without memory overflow or arbitrary limits.

Instructions

Prerequisites

GCC or Clang compiler

Standard C libraries (unistd.h, stdlib.h, fcntl.h)

Compilation

Include the source files along with your main program, specifying the buffer size at compile-time using the -D BUFFER_SIZE=n flag:

# Compiling mandatory part with BUFFER_SIZE = 42
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Compiling bonus part (with multiple file descriptor support)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus