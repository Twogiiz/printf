# 0x11. C - printf

This project is a recreation of the standard C library printf function. It was created as a team project by Goodwill Monyai and Samuel Samuel for ALX Africa.

## Description

The `_printf()` function produces output based on a specified format string. It handles various conversion specifiers like `c`, `s`, `d`, `i`, `u`, `o`, `x`, `X`, `b`, `S`, `p`, `r`, `R`. It supports length modifiers, flag characters, field width, precision, etc.

Custom conversion specifiers implemented:
- `b`: Prints an unsigned int as binary
- `S`: Prints a string with non-printable characters printed as hexadecimal escape codes
- `r`: Prints a reversed string 
- `R`: Prints a rot13 encrypted string

## Getting Started

**Dependencies**
- `gcc compiler`
- `Ubuntu 20.04 LTS`

**Compiling**
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

**Testing** 
- Sample main.c files provided in examples folder
- Disable format string warnings when compiling for tests

## Usage

`int _printf(const char *format, ...)`;

Returns number of characters printed.

Check the tasks in the project requirements for example usage of the custom conversion specifiers.

## Authors
Goodwill Monyai
Samuel Samuel

Repo Link: [printf](https://github.com/Twogiiz/printf)

## Acknowledgements

This project was completed as part of the ALX Africa Software Engineering programme.
