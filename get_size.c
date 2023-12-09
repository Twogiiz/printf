#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = (format[curr_i] == 'l') ? S_LONG : ((format[curr_i] == 'h') ? S_SHORT : 0);

    *i = (size == 0) ? curr_i - 1 : curr_i;

    return size;
}
