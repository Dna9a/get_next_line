## *This project has been created as part of the 42 curriculum by yoabied.* 
<!-- 9sem -->
<div style="display: flex; justify-content: space-between; align-items: center;">
  <span style="font-size: 45px;">:page_facing_up:</span>
  <span style="font-size: 40px;">:dromedary_camel:</span>
</div>


<!-- # Description-->
# Description
The goal and purpose of this project is to basically implement a function that reads from a file. This one is supposed to be a valid file descriptor; if not, my function is supposed to return null, otherwise it is supposed to return the line read.
 - - - - - - - - - - - - - - - - - -
## Function Prototype

```c
char *get_next_line(int fd);
char *get_next_line_bonus(int fd);
```
### Parameters

- `fd`: file descriptor for reading    
### Return Value
- `char *`: a pointer to the line read from the file descriptor, or NULL if an error occurs or EOF is reached.
## Key Features
1. Line-by-Line Reading: Reads a file or standard input line by line, handling lines of any length. __(Support in Mandatory part)__
4. Multiple File Descriptors: Supports reading from multiple file descriptors at once, keeping track of where each one is in the file. __(Support in BONUS part)__



<!-- Instructions -->
# Instructions
## Usage
#### how to use GNL 
1. Include Header: Ensure that the get_next_line.h or get_next_line_bonus.h header is included in your project.

2. Call Function: Call get_next_line(fd) in a loop to retrieve lines until NULL is returned (indicating end-of-file or an error).



```c
#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*buff;

	fd = open("file.txt", O_RDONLY);
	while ((buff = get_next_line(fd)) != NULL)
	{
		printf("%s", buff);
		free(buff);
	}
	close(fd);
	return (0);
}
```

## Makefile 
During the process of testing my GNL, I made a small makefile tester so to test my function just with a make command, that's by throwing `ps -ef` output on another file called `smg`

 - - - - - - - - - - - - - - - - - -

```Make
run:
    @ ps -f >> smg && cc -Wall -Wextra -Werror *.c -o gnl && ./gnl && rm -rf smg
clean:
    @ rm -f gnl a.out smg
```
 - - - - - - - - - - - - - - - - - -

### what you need to know :pensive: 

- Know the goal of the project
- Know what's a static variable
- The open commands
- Know what's a fd
- Leaks handling  

<!-- Resources -->
# Resources
- **[Nikito](https://youtu.be/-Mt2FdJjVno?si=UizBGaoso6nZFQve)**
- **[Ayogun](https://medium.com/@ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5)**
- **[Lannur-s](https://medium.com/@lannur-s/gnl-c3cff1ee552b)**
- **[Codequoi](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)**
- **[Notebookml (for mind maps)](https://notebooklm.google.com)**

<!-- Additional sections may be required depending on the project (e.g., usage examples, feature list, technical choices, etc.). -->

# The algorithm

## Overview
While building my GNL, I took the approach of creating multiple helper functions so to reach the projects goal .

### 1. Static Variable (Stash)
- The static variable `stash` is crucial because it retains its value between function calls
- It serves as a persistent storage unit that holds any leftover data after extracting a line
- This allows the function to remember where it left off in the file

### 2. `gnl_read` Function
- Manages the reading process by pulling data from the file descriptor
- Reads chunks of data into `buf_read` according to the specified `BUFFER_SIZE`
- Uses `fttitistrjoin` to append each new buffer to the existing stash
- Uses `ft_strchr` to check the stash for a newline character (`\n`)
- The loop breaks when EOF is reached or when a newline is found

### 3. `ineeddaline` Function
- Called once the stash contains at least one full line
- Responsible for isolating and extracting the line from the stash
- Returns the extracted line (including the newline character if present)

### 4. `stashsys` Function
- Cleans up the stash after a line has been extracted
- Keeps only the remaining data that comes after the extracted line
- Allows GNL to continue reading from where it left off on the next call

## Algorithm Flow
1. **Read**: `gnl_read` accumulates data into the stash until a newline or EOF
2. **Extract**: `ineeddaline` isolates the first complete line from the stash
3. **Update**: `stashsys` updates the stash to remove the extracted line
4. **Return**: The extracted line is returned to the caller
5. **Repeat**: On the next call, the process continues with the remaining stash content 
