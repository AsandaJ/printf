#include "main.h"

<<<<<<< HEAD
/**
 * _printf - Custom printf function
 * @format: A string containing all the desired characters
 * @...: A variable number of arguments of the characters printed
 * Return: A total count of characters
 */
int _printf(const char *format, ...)
{
	fmt_t specifiers[] = {
	{"%s", printf_string}, {"%c", printf_char},
	{"%%", printf_37}, {"%i", printf_int},
	{"%d", printf_dec}, {"%r", printf_srev},
	{"%R", printf_rot13}, {"%b", printf_bin},
	{"%u", printf_unsigned}, {"%o", printf_oct},
	{"%x", printf_hex}, {"%X", printf_HEX},
	{"%sS", printf_exclusive_string}, {"%p", printf_pointer}
	};
	va_list args;

	va_staert(args, format);

	int cnt = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_ar(args, int);

				_putchar(c);
				cnt++;
			} else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				while (*s != '\0')
				{
					_putchar(*s);
					s++
					cnt++;
				}
			else if (*format == '%')
			{
				_putchar('%');
				cnt++;
			}
			}
			else
		{
			_putchar(*format);
			cnt++;
		}
		format++;
	}
	va_end(args);
	return (cnt);
}
int main(void)
{
	_printf("Hello, %s! Today is %c.\n", "Asanda", 'J');
	_printf("This is a %% sign.\n");

	return (0);
=======
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;

	char buffer[BUFF_SIZE];

	if (format == NULL)

		return (-1)
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			/* write(1, &format[i], 1);*/
			printed_chars++;

		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
>>>>>>> 8b01149649c4ba796bd9e8163abca3a614bf0490
}
