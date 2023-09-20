#include "main.h"

/**
 * printf_char - prints a char.
 * @c: arguments.
 * Return: 1.
 */
int printf_char(va_list c)
{
	char s;

	s = va_arg(c, int);
	_putchar(s);
	return (1);
}



/**
 * print_string - prints string
 *@args: string to be printed
 * Return: k
 */
int print_string(va_list args)
{
char *my_str;
int k = 0;
my_str = va_arg(args, char *);
if (my_str == NULL)
my_str = "(null)";
while (my_str[k])
{
_putchar(my_str[k]);
k++;
}
return (k);
}


/**
 * printf_37 - prints the char 37.
 * Return: 1.
 */
int printf_37(void)
{
	_putchar(37);
	return (1);
}

/**
 * print_dec - prints decimal
 * @d: decimal to be printed
 * Return: size
 */
int print_dec(va_list d)
{
	int len, powten, j, digit, n, count = 0, num;

	n = va_arg(d, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/**
 * printf_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
