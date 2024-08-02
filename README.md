
# Pipex

## Overview

The **Pipex** project delves into the UNIX mechanism of piping, allowing you to replicate shell command behavior in your own program. This project will help you understand the intricacies of process management, file handling, and inter-process communication.

## Summary

This project will let you explore in detail a UNIX mechanism that you might already know by implementing it in your program.

## Mandatory Part

### Program Name
`pipex`

### Turn-in Files
- `Makefile`
- `*.h`
- `*.c`

### Makefile Targets
- `NAME`
- `all`
- `clean`
- `fclean`
- `re`

### Arguments
- `file1`
- `cmd1`
- `cmd2`
- `file2`

### External Functions
- `open`, `close`, `read`, `write`
- `malloc`, `free`
- `perror`, `strerror`
- `access`, `dup`, `dup2`
- `execve`, `exit`
- `fork`, `pipe`
- `unlink`, `wait`, `waitpid`
- `ft_printf` and any equivalent YOU coded

### Libft Authorization
Libft is authorized for this project.

### Description
This project involves handling pipes. Your program will be executed as follows:

```sh
./pipex file1 cmd1 cmd2 file2
```

It must take 4 arguments:
- `file1` and `file2` are file names.
- `cmd1` and `cmd2` are shell commands with their parameters.

Your program should behave exactly like the following shell command:

```sh
< file1 cmd1 | cmd2 > file2
```

### Examples

```sh
./pipex infile "ls -l" "wc -l" outfile
```
Should behave like:
```sh
< infile ls -l | wc -l > outfile
```

```sh
./pipex infile "grep a1" "wc -w" outfile
```
Should behave like:
```sh
< infile grep a1 | wc -w > outfile
```

### Requirements
- Turn in a Makefile that compiles your source files without relinking.
- Handle errors thoroughly. The program should not quit unexpectedly (segmentation fault, bus error, double free, etc.).
- Ensure no memory leaks.

### Error Handling
Handle errors similarly to the shell command:
```sh
< file1 cmd1 | cmd2 > file2
```

## Bonus Part

You can earn extra points by implementing the following features:

### Bonus Features
- **Multiple Pipes**: 
  Handle multiple pipes as follows:
  ```sh
  ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
  ```
  Should behave like:
  ```sh
  < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
  ```

- **Here Document**:
  Support `«` and `»` when the first parameter is `here_doc`:
  ```sh
  ./pipex here_doc LIMITER cmd cmd1 file
  ```
  Should behave like:
  ```sh
  cmd << LIMITER | cmd1 >> file
  ```

## Installation

Clone the repository and navigate to the project directory:

```sh
git clone https://github.com/yourusername/pipex.git
cd pipex
```

Compile the project:

```sh
make
```

## Usage

Run the program with the appropriate arguments:

```sh
./pipex file1 cmd1 cmd2 file2
```

### Example

```sh
./pipex infile "ls -l" "wc -l" outfile
```

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

Special thanks to the 42 Network and all the peer reviewers who helped make this project a success.

---

Feel free to adjust the repository URL and any other specifics as needed.
