/**
 * print_pointer - Prints the value of a pointer variable.
 * @types: Variadic list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Flags for formatting.
 * @width: Width for formatting.
 * @precision: Precision for formatting.
 * @size: Size specifier.
 *
 * Description:
 * This function prints the address of a pointer variable in lowercase hexadecimal
 * format to the standard output stream, handling flags and width.
 *
 * Return:
 * Number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* initial length 2 for '0x' */
	unsigned long int num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0) {
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
			width, flags, padd, extra_c, padd_start));
}
/**
 * print_non_printable - Prints non-printable characters in hexa format.
 * @types: Variadic list of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Flags for formatting.
 * @width: Width for formatting.
 * @precision: Precision for formatting.
 * @size: Size specifier.
 *
 * Description:
 * This function iterates through a string and checks if each character is printable.
 * If not, it appends the character's ASCII code in hexa format to the buffer.
 *
 * Return:
 * Number of characters printed.
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0') {
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
/**
 * print_reverse - Prints a string in reverse order.
 * @types: Variadic list of arguments.
 * @buffer: Unused buffer.
 * @flags: Unused flags.
 * @width: Unused width.
 * @precision: Unused precision.
 * @size: Unused size.
 *
 * Description:
 * This function iterates through a string in reverse order and prints each character.
 *
 * Return:
 * Number of characters printed.
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
