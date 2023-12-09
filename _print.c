#include "main.h"
#include <stdio.h>

/**
 * Print_Buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buff_ind: Index at which to add next char, represents the length
 */ 
void Print_Buffer(char buffer[], int *buff_ind)
{
    int i;
    
    if (*buff_ind > 0) 
    {
        for (i = 0; i < *buff_ind; i++) 
        {
            fputc(buffer[i], stdout); 
        }
    }  

    *buff_ind = 0;
}

/**
 * _Printf - Printf function using fputc for output
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _Printf(const char *format, ...)
{
    va_list args;
    int i, chars_printed = 0;
    char buffer[BUFF_SIZE]; 
    int buff_index = 0;

    va_start(args, format);

    if (!format)
        return -1;

    for (i = 0; format[i]; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_index++] = format[i];
            if (buff_index == BUFF_SIZE)
                Print_Buffer(buffer, &buff_index);
                
            chars_printed++;
        }
        else
        {
             // Handle format specifiers
        }
    }

    Print_Buffer(buffer, &buff_index);
            
    return chars_printed; 
}
