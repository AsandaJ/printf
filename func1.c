#include "main.h"
#include <stdlib.h>

/**
 * printf_bin - prints a binary number.
 * @val: arguments.
 * Return: 1.
 */
int printf_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}

/**
 * printf_unsigned - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
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

/**
 * printf_oct - prints an octal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_oct(va_list val)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 8;
		temp /= 8;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
/**
 * print_hex - takes an unsigned int and prints it in lowercase hex notation
 * @x: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_hex(va_list x)
{
	return (print_hexHEX(va_arg(x, unsigned int), 0));
}

/**
 * print_HEX - takes am unsigned int and prints it in uppercase hex notation
 * @X: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_HEX(va_list X)
{
	return (print_hexHEX(va_arg(X, unsigned int), 1));
}

