#include "main.h"
#include <stdio.h>

/**
 * Print_Char - Prints a character 
 * @types: List of arguments
 * @flags: Calculates active flags
 * @width: Width 
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int Print_Char(va_list types, 
        int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);  
    return (Handle_Write_Char(c, flags, width, precision, size)); 
}

/**
 * Print_String - Prints a string
 * @types: List of arguments
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier  
 *
 * Return: Number of chars printed
 */
int Print_String(va_list types,  
        int flags, int width, int precision, int size)
{
    int i, length = 0;
    char *str = va_arg(types, char*);
    
    if (!str) 
        str = "(null)";

    while (str[length])
        length++;

    // Handle padding

    return (output_string(str, length));  
}

/** 
 * output_string - Print string using fputc
 * @str: String
 * @length: String length
 */
int output_string(char *str, int length) 
{
    int i;
    
    for (i = 0; i < length; i++) 
        fputc(str[i], stdout);

    return length;  
}

/**
 * Print_Percent - Print % character
 *
 * Return: Number of characters printed (1) 
 */
int Print_Percent(void)
{
     fputc('%', stdout);
     return (1);
}

/** 
 * Print_Int - Print an integer
 * @types: List of arguments  
 * @flags: Flags
 * @width: Width
 * @precision: Precision  
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */ 
int Print_Int(va_list types, int flags, int width, int precision, int size)
{
     int num = va_arg(types, int);
     // Print integer

     return output_length;
}
