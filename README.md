*This project has been created as part
of the 42 curriculum by vigomes-*
![gnl header](src/header.png)
# Get Next Line (reading a line from a file descriptor is way too tedious)

<!-- Description -->
## DESCRIPTION
#### Get Next Line is a file-reading function that returns one line at a time from a file descriptor. The project focuses on efficient memory management, static variables, and buffer handling, allowing the function to maintain its reading state between consecutive calls. It supports reading from files, standard input, and other valid file descriptors while minimizing unnecessary system calls through buffered reading.
![gnl validation](src/validation.png)

## INTRODUCTION | How to test

### 1 - Clone this repository
```bash
git clone https://github.com/vgomes-p/get_next_line-42.git
```

### 2 - Go to the project directory
```bash
cd get_next_line-42/project/
```

### 3 - Compile the program
```bash
make
```

#### 4 - Run it
```bash
./gnl_tester <files_path> <optional flag>
```
> flag `--cnt` show line counter

## ALGORITHM CHOICES

My implementation of `get_next_line()` is divided into three main functions:
`gnl_read()`, `gnl_get_current_line()`, and `gnl_trimmer()`.

#### `gnl_read()`
`gnl_read()` reads from the file descriptor and appends the data to `store` until a newline character (`\n`) is found or the end of the file is reached. Since each read operation is followed by a call to `gnl_strjoin()`, which reallocates and copies the existing content, the overall complexity can degrade to O(n²). I chose this approach because I wanted to keep the implementation simple and avoid using structures.

#### `gnl_get_current_line()`
`gnl_get_current_line()` traverses `store` until it finds a newline character or the null terminator. It then calls `gnl_substr()` to extract the current line and return it. This operation runs in O(n).

#### `gnl_trimmer()`
`gnl_trimmer()` traverses `store` until it finds a newline character. If no newline is found, the remaining memory is freed and `NULL` is returned. Otherwise, it allocates a new string large enough to hold the remaining content after the newline, copies that content, frees the old `store`, and returns the new one. This operation also runs in O(n).

#### `get_next_line()`
`get_next_line()` first calls `gnl_read()` to ensure that `store` contains at least one complete line or the remaining content of the file. Then `gnl_get_current_line()` extracts the next line to be returned. After that, `gnl_trimmer()` updates `store` so that it only contains the unread portion of the file. Finally, the extracted line is returned to the caller.

#### Complexity
Because the implementation repeatedly concatenates strings while reading, it performs multiple copies of previously read data. As a result, the overall time complexity may degrade to O(n²). A more efficient solution could achieve O(n) by avoiding repeated reallocations and copies, typically through a different buffer management strategy or the use of dedicated data structures.


## RESOURCES
<!-- Resources -->
[`Acelera 42`](https://rodsmade.notion.site/Acelera-Get_next_line-4902aab835ef4b86a7c55d82cc5c19ec)
