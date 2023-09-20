#include "main.h"

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
}
