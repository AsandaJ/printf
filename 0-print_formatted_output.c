#include "main.h"
/**
 * _printf - Custom printf function
 * @format: A string containing all the desired characters
 * @...: The variable number of arguments to format and print
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			/* Loop through the format specifiers and function pointers */
			fmt_t specifiers[] = {
				{"c", print_char},
				{"s", print_string},
				{"%", print_percent},
				{"d", print_integer},
				{"i", print_integer},
				{"b", print_binary},
				{"r", print_reversed},
				{"R", rot13},
				{"u", unsigned_integer},
				{"o", print_octal},
				{"x", print_hex},
				{"X", print_heX},
				{NULL, NULL}
			};

			int i = 0;
			while (specifiers[i].fmt)
			{
				if (*format == specifiers[i].fmt[0])
				{
					printed_chars += specifiers[i].fn(arg_list);
					break;
				}
				i++;
			}

			if (specifiers[i].fmt == NULL)
			{
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
			}
		}
		format++;
	}

	va_end(arg_list);
	return (printed_chars);
}
