# get_next_line

A C function that reads a line from a file descriptor, one line at a time.

## Description

`get_next_line` is a function that returns a line read from a file descriptor. It is a useful function for reading files line by line, and is often used in 42 school projects.

## Features

- Reads from any file descriptor (files, standard input, etc.)
- Configurable buffer size via `BUFFER_SIZE` macro
- Handles multiple file descriptors simultaneously (bonus version)
- Memory efficient with static variable storage

## Files

### Mandatory Part
- `get_next_line.c` - Main function implementation
- `get_next_line.h` - Header file with function prototypes
- `get_next_line_utils.c` - Helper functions

### Bonus Part
- `get_next_line_bonus.c` - Implementation supporting multiple file descriptors
- `get_next_line_bonus.h` - Bonus header file
- `get_next_line_utils_bonus.c` - Bonus helper functions

## Function Prototype

```c
char *get_next_line(int fd);
```

## Parameters

- `fd` - The file descriptor to read from

## Return Value

- Returns the line that was read (including the newline `\n` if present)
- Returns `NULL` if there is nothing more to read or if an error occurred

## Usage

### Basic Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

### Compilation

**Mandatory:**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

**Bonus (multiple file descriptors):**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Configuration

The buffer size can be configured at compile time:

```bash
gcc -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c
```

## Notes

- The function uses a static variable to store leftover data between calls
- The bonus version uses an array of static variables to handle multiple file descriptors
- Memory is properly freed when reaching EOF or on error
- The function handles edge cases like empty files, very long lines, and small buffer sizes

## Author

yoabied <yoabied@student.1337.ma>

## License

This project is part of the 42 school curriculum.
