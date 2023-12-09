#include "main.h"
#include <stdio.h>

/**
 * Print_Unsigned - Print unsigned number
 * @types: List of arguments
 * @flags: Flags  
 * @width: Width
 * @precision: Precision
 * @size: Size modifier
 *
 * Return: Number of chars printed
 */
int Print_Unsigned(va_list types,  
        int flags, int width, int precision, int size)
{
    unsigned long num = va_arg(types, unsigned long);
    
    // Format number

    output_number(formatted_num); 

    return num_chars_printed;
}

/**
 * Print_Octal - Print octal number
 * @types: List of arguments
 * @flags: Flags
 * @width: Width 
 * @precision: Precision
 * @size: Size modifier
 *
 * Return: Chars printed  
 */
int Print_Octal(va_list types,  
        int flags, int width, int precision, int size)
{
    unsigned long n = va_arg(types, unsigned long);
    
    // Format number

    output_number(formatted_num);

    return num_chars_printed; 
}
 
/**
 * output_number - Print formatted number 
 * @num_str: Formatted number string
 *
 * Return: Chars printed
 */
int output_number(char *num_str)
{
    int i;

    for (i = 0; num_str[i]; i++)
        fputc(num_str[i], stdout);
    
    return i;
}
