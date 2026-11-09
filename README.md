# Libft - 42 Barcelona

Libft is the foundational C programming project at 42 Barcelona. It is a comprehensive, modular custom standard C library providing essential utility functions for memory manipulation, string handling, character classification, integer and string conversions, file descriptor output, formatted output printing (fd_printf), and buffered line reading (get_next_line). This library serves as the core utility dependency across all subsequent 42 C systems projects.

# Prerequisites

To compile and link Libft, you will need:

- A C compiler: gcc or clang
- GNU Make
- Standard C library headers
- POSIX-compliant operating system (Linux or macOS)

# Configuration

1. Clone the repository:
```bash
git clone https://github.com/adrmarqu/libft.git
cd libft
```

No external packages or dependencies are required. The Makefile handles all compiler flags and object dependencies internally.

# Execution

### Compile the Static Library

Generate the static archive libft.a:
```bash
make
```

### Linking with Your Own Programs

Include the relevant header from inc/ and link against libft.a:

```c
// Example: main.c
#include "inc/string.h"
#include "inc/fd_printf.h"

int main(void)
{
    char *msg = ft_strdup("Hello from Libft at 42 Barcelona!");
    ft_fd_printf(1, "%s\n", msg);
    free(msg);
    return (0);
}
```

Compile and run:
```bash
gcc -Wall -Wextra -Werror main.c -L. -lft -Iinc -o example_program
./example_program
```

# Project Structure

```
libft/
├── Makefile                 # Library build automation with dependency tracking
├── inc/                     # Modular header files
│   ├── ctype.h              # Character classification prototypes
│   ├── string.h             # String manipulation prototypes
│   ├── memory.h             # Memory manipulation prototypes
│   ├── extra.h              # Number conversion and printing helper prototypes
│   ├── fd_printf.h          # Formatted print to file descriptor prototypes
│   ├── get_next_line.h      # Line reading engine prototypes
│   └── structs.h            # Data structures and list declarations
└── sources/                 # Modular source code
    ├── ctype/               # Character checks (isalpha, isdigit, isalnum, isascii, isprint)
    ├── string/              # Strings (strlen, strlcpy, strlcat, strchr, strdup, split, join)
    ├── memory/              # Memory (memset, bzero, memcpy, memmove, memchr, memcmp, calloc)
    ├── extra/               # Utilities (atoi, itoa, putchar_fd, putstr_fd, putnbr_fd)
    ├── fd_printf/           # Formatted file descriptor printing engine
    └── get_next_line/       # Buffered newline stream reader
```

# Commands and Makefile Targets

- make or make all: Compiles all C source files and packages them into the static library libft.a
- make clean: Removes compiled object files (.o) and dependency files (.d)
- make fclean: Runs clean and deletes the static library archive libft.a
- make re: Completely recompiles the library from scratch (fclean followed by all)

# Functional Modules

- Character Checks (ctype): Validation for alphanumeric, alphabetic, digit, ASCII, and printable characters.
- String Operations (string): Safe string copy, length calculation, concatenation, searching, slicing, substring creation, trimming, joining, and array splitting.
- Memory Functions (memory): Memory filling, clearing, copying, pointer comparison, and dynamic allocation with zero initialization.
- Type Conversion (extra): Robust conversion from ASCII strings to numeric types (ft_atoi) and integer values to dynamically allocated string representations (ft_itoa).
- File Descriptor Printing (fd_printf): Flexible formatted string interpolation directly to arbitrary file descriptors.
- Line Reading (get_next_line): Sequential line-by-line reading from any open file descriptor or input stream.

# Author Details

Author: Adrià Márquez Nebot
Github: https://github.com/adrmarqu
LinkedIn: https://www.linkedin.com/in/adria-marquez
Portfolio: https://adrmarqu.github.io
