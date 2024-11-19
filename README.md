# get_next_line

## Description

The `get_next_line` function reads data from a file descriptor, returning one line at a time. It is designed to handle text files or streams where lines are delimited by newline (`\n`) characters. The function retains state between calls, enabling successive retrieval of lines from the same file descriptor.

## Features

- **Line-by-Line Reading**: Processes files or streams one line at a time for efficient parsing.
- **Buffer Management**: Utilizes a buffer to optimize reading performance.
- **Handles Large Files**: Capable of reading large files without loading them entirely into memory.
- **Works with Multiple File Descriptors**: Can simultaneously read from multiple file descriptors.

## Function Prototype

```c
char *get_next_line(int fd);
```
## Parameters

- `fd` (int): The file descriptor to read from.

## Return Value

- Returns a dynamically allocated string containing the next line, including the newline character (`\n`), if present.
- Returns `NULL` when:
  - The end of the file is reached.
  - An error occurs (e.g., invalid file descriptor or memory allocation failure).

## Usage

1. Include the header file in your source code:
   ```c
   #include "get_next_line.h"
   ```
1. Call the function in a loop to read lines until the end of the file:
  ```c
int fd = open("example.txt", O_RDONLY);
if (fd < 0)
    return (1);

char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```
## Compilation

Ensure the following files are included in your project:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

Compile using `gcc` or your preferred compiler:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```
Replace `BUFFER_SIZE` with your desired buffer size.

## Important Notes

- **Memory Management**: Each call to `get_next_line` returns a dynamically allocated string. The caller must free the memory to prevent leaks.
- **Buffer Size**: The `BUFFER_SIZE` macro must be defined during compilation. Its value significantly affects performance and memory usage.

## Limitations

- The function relies on the presence of `\n` to delimit lines. If the file does not end with a newline, the final line will still be returned.
- The behavior for non-text files (e.g., binary data) is undefined.

## Example Output

Given the file `example.txt`:

```plaintext
Hello, World!
This is a test.
EOF.
```
## The Function Outputs

```vbnet
Hello, World!
This is a test.
EOF.
```
## Author
Developed by Iammar as part of the **1337 School (42 Network)** project for mastering file I/O and dynamic memory allocation in C.
