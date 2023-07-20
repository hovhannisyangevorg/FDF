# libft

Welcome to libft! This is a project from the 42 programming school that aims to recreate some of the standard library functions in C. The goal of this project is to build a library of useful functions that can be reused in future projects.

## Getting Started

To use this library, you can simply clone the repository and compile the `libft.a` file by running the `make` command:

```bash
  git clone https://github.com/hovhannisyangevorg/Libft.git
```
```bash
  cd Libft
```
```bash
  make
```

This will compile the source files and create the `libft.a` library file.

You can then link this library to your own projects by including the `libft.h` header file and adding the library path and name (`-L/path/to/libft -lft`) to your compilation command.

## Project Structure

The project is organized as follows:

- `Makefile`: Contains the compilation rules for building the library.
- `libft.h`: The library's header file, which includes prototypes for all the functions in the library.
- `src/`: Directory containing the source code files for each function.
- `include/`: Directory containing additional header files used internally by the library.

## Documentation

Each function in the library is documented with a description of its purpose and usage. The function prototypes and descriptions can be found in the `libft.h` header file. We encourage you to consult this file to understand how to use each function.
