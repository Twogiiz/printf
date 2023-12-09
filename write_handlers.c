/**
 * print_unsigned - Prints an unsigned number.
 * @types: Variadic list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Flags for formatting.
 * @width: Width for formatting.
 * @precision: Precision for formatting.
 * @size: Size specifier.
 *
 * Description:
 * This function prints an unsigned integer to the standard output stream,
 * handling size specifiers.
 *
 * Return:
 * Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0) {
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints an unsigned number in octal format.
 * @types: Variadic list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Flags for formatting.
 * @width: Width for formatting.
 * @precision: Precision for formatting.
 * @size: Size specifier.
 *
 * Description:
 * This function prints an unsigned integer in octal format to the standard
 * output stream, handling size specifiers and the # flag.
 *
 * Return:
 * Number of characters printed.
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0) {
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in lowercase hexadecimal format.
 * @types: Variadic list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Flags for formatting.
 * @width: Width for formatting.
 * @precision: Precision for formatting.
 * @size: Size specifier.
 *
 * Description:
 * This function prints an unsigned integer in lowercase hexadecimal format to the
 * standard output stream, handling size specifiers.
 *
 * Return:
 * Number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
			flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints an unsigned number in uppercase hexadecimal format.
 * @types: Variadic list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Flags for formatting.
 * @width: Width for formatting.
 * @precision: Precision for formatting.
 * @size: Size specifier.
 *
 * Description:
 * This function prints an unsigned integer in uppercase hexadecimal format to the
 * standard output stream, handling size specifiers.
 *
 * Return:
 * Number of characters printed.
 */
int print_hexa_upper(va

