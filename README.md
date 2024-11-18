# **Get Next Line**

This project implements the `get_next_line` function, which reads a single line from a file descriptor at a time, including support for multiple file descriptors. It is fully compliant with the **42 Norm** and guarantees no memory leaks.

---

## **Features**

- Reads one line at a time, including the trailing newline (`\n`), if present.
- Handles files with or without a newline at the end.
- Works with multiple file descriptors simultaneously.
- Configurable buffer size via the `BUFFER_SIZE` macro.
- Ensures no memory leaks or double frees.

---

## **Function Prototype**

```c
char *get_next_line(int fd);
## **How It Works**
The get_next_line function is composed of:

read_file: Reads data from the file descriptor into a static buffer until a newline or EOF is encountered.

get_linee: Extracts a single line from the buffered string, preparing it for subsequent reads.

Helper Functions:

join_and_free: Concatenates strings while freeing old allocations.
extract_line: Handles line extraction and memory cleanup.
Usage
Including in Your Project
Add the following files to your project:

get_next_line.c
get_next_line_utils.c
get_next_line.h
Compile with the desired BUFFER_SIZE:

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
Example usage:

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
Command:

valgrind --leak-check=full --show-leak-kinds=all ./get_next_line_example
Example Output
Given the file example.txt with the following content:


Hello, there!
This is Get Next Line.
Running the example code produces:

Hello, world!
This is Get Next Line.
I tested the following cases using Valgrind:

Empty File: Ensures get_next_line handles EOF correctly.
Single Line Without Newline: Verifies no memory leaks with partial reads.
Multiple Lines: Validates memory is freed for every line.
Large Files: Confirms dynamic memory allocation works seamlessly.
Multiple File Descriptors: Checks static variable management.
Example Valgrind Report:


==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 10 allocs, 10 frees, 1,024 bytes allocated
==12345== All heap blocks were freed -- no leaks are possible
Project Norms
This project adheres to the 42 Norm, ensuring:

Functions have fewer than 25 lines.
No more than 5 variables per function.
Proper memory management throughout.
Testing
Run the following script to test for edge cases:


#!/bin/bash

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42 -o gnl_test
echo "Running tests..."

echo -n "" > empty.txt
echo "Hello, world!" > single_line.txt
echo -e "Line 1\nLine 2\nLine 3" > multiple_lines.txt

files=("empty.txt" "single_line.txt" "multiple_lines.txt")

for file in "${files[@]}"
do
    echo "Testing with file: $file"
    valgrind --leak-check=full --show-leak-kinds=all ./gnl_test < "$file"
done
Contributors
iammar - Author
