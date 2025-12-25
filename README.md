# get_next_line

## Project Goal

The **get_next_line** project is a function that reads and returns a single line from a file descriptor. This project is designed to teach efficient file reading, static variable management, and dynamic memory allocation in C. The function can read from files, standard input, or any valid file descriptor, and it handles multiple consecutive calls to return lines one at a time.

### Key Objectives:
- Read text from a file descriptor one line at a time
- Handle different buffer sizes efficiently
- Manage memory properly with dynamic allocation
- Use static variables to maintain state between function calls
- Work with multiple file descriptors (bonus)

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters:
- `fd`: The file descriptor to read from

### Return Value:
- Returns a string containing the line that was read (including the newline character `\n` if present)
- Returns `NULL` if there is nothing more to read or if an error occurred

## How It Works

The `get_next_line` function implements a line-by-line reading mechanism that efficiently handles file I/O operations:

### Main Algorithm (`get_next_line.c`)

1. **Buffer Allocation**: Allocates a buffer of size `BUFFER_SIZE` to read chunks of data from the file descriptor
2. **Reading Loop**: Continuously reads from the file descriptor until:
   - A newline character (`\n`) is found
   - End of file is reached
   - An error occurs
3. **Stash Management**: Uses a static variable `stash` to store leftover data from previous reads
4. **Line Extraction**: Extracts the current line from the stash
5. **Stash Update**: Updates the stash to contain only the remaining unprocessed data

### Core Functions

#### `get_next_line(int fd)`
The main function that orchestrates the line reading process:
- Reads data from the file descriptor in chunks
- Accumulates data in a static stash
- Extracts and returns complete lines
- Maintains leftover data for the next call

#### Helper Functions (`get_next_line_utils.c`)

**`ft_strlen(const char *s)`**
- Calculates the length of a string
- Returns the number of characters before the null terminator

**`ft_strcpy(char *dst, const char *src)`**
- Copies a string from source to destination
- Returns the number of characters copied

**`ft_strchr(const char *s, int c)`**
- Searches for a character in a string
- Returns a pointer to the first occurrence of the character
- Used to detect newline characters

**`fttitistrjoin(char *s1, const char *s2)`**
- Joins two strings together, creating a new string
- Frees the first string after joining
- Allocates memory for the combined result
- Critical for accumulating data from multiple reads

**`stashsys(char *p)`**
- Extracts and returns the portion of the stash after the newline
- Frees the old stash and creates a new one
- Returns `NULL` if no data remains after the newline

**`ineeddaline(char *delulu)`**
- Extracts a single line from the stash (up to and including `\n`)
- Allocates new memory for the line
- Returns the complete line ready to be returned to the caller

## Code Structure

```
get_next_line/
├── get_next_line.h        # Header file with function prototypes and includes
├── get_next_line.c        # Main function implementation
└── get_next_line_utils.c  # Helper functions for string manipulation
```

## Compilation

To compile the project, you need to define the `BUFFER_SIZE` at compilation time:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test
```

### Buffer Size
The `BUFFER_SIZE` determines how many bytes are read in each `read()` system call. Common values:
- Small buffer (1-10): Slower but tests edge cases
- Medium buffer (32-128): Balanced performance
- Large buffer (1024+): Faster for large files

## Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    // Open a file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    // Read and print each line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Don't forget to free!
    }

    close(fd);
    return (0);
}
```

## Memory Management

The function carefully manages memory to prevent leaks:
- All allocated memory for lines must be freed by the caller
- The static stash is maintained between calls and freed when no more data is available
- Helper functions handle intermediate allocations and deallocations

## Implementation Details

### Static Variable
The `stash` variable is declared as `static`, which means:
- It persists between function calls
- Each file descriptor maintains its own reading state
- Data that doesn't form a complete line is preserved for the next call

### Edge Cases Handled
- Empty files
- Files without newline at the end
- Very large lines
- Multiple consecutive newlines
- Read errors
- Invalid file descriptors

## Technical Considerations

1. **Efficient Reading**: Uses a buffer to minimize system calls
2. **Dynamic Memory**: Grows the stash as needed to accommodate lines of any length
3. **State Persistence**: Static variable maintains position between calls
4. **Error Handling**: Returns NULL on errors and cleans up resources

## Author

Created by Youssef Abied (yoabied@student.1337.ma)

## License

This is an educational project created as part of the 42/1337 curriculum.
