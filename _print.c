Here is one way to rewrite the code to use _putchar instead of write:

```c
#include "main.h"
#include <unistd.h>

void print_buffer(char buffer[], int *buff_ind);

/** 
 * _printf - Printf function using _putchar 
 * @format: Format string
 * Return: Number of chars printed
 */
int _printf(const char *format, ...) 
{
  va_list args;
  int chars_printed = 0;
  
  va_start(args, format);

  for(int i = 0; format[i] != '\0'; i++) {
    if(format[i] == '%') {
      // Handle format specifiers
    } else {
      _putchar(format[i]);
      chars_printed++;
    }
  }

  va_end(args);

  return chars_printed; 
}

/**
 * print_buffer - Print buffer using _putchar
 * @buffer: Char array 
 * @buff_ind: Buffer index
*/
void print_buffer(char buffer[], int *buff_ind) 
{
  for(int i = 0; i < *buff_ind; i++) {
    _putchar(buffer[i]);
  }
  
  *buff_ind = 0;
}
