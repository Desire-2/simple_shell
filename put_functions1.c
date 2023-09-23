#include "main.h"

/**
 * _erratoi - Funcition that converts a string to an integer
 * @s: String to be converted
 * Return: 0 if no numbers is string,  otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int r = 0;
	unsigned long int rslt = 0;

	if (*s == '+')
		s++; 
	for (r = 0;  s[r] != '\0'; r++)
	{
		if (s[r] >= '0' && s[r] <= '9')
		{
			rslt *= 10;
			rslt += (s[r] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}

/**
 * _print_error - Function that prints an error message
 * @info: Parameter and return info struct
 * @estr: String containing specified error type
 * Return: 0 if no numbers is string,  otherwise
 *        -1 on error
 */
void _print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	_print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int _print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int r, cnt = 0;
	unsigned int _abs_, curr;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		cnt++;
	}
	else
		_abs_ = input;
	curr = _abs_;
	for (r = 1000000000; r > 1; r /= 10)
	{
		if (_abs_ / r)
		{
			__putchar('0' + curr / r);
			cnt++;
		}
		curr %= r;
	}
	__putchar('0' + curr);
	cnt++;

	return (cnt);
}

/**
 * _convert_number - Funcition that converter function, a clone of itoa
 * @num: Number to be converted
 * @base: Base
 * @flags: argument flags
 * Return: string
 */
char *_convert_number(long int num, int base, int flags)
{
	char *ptr;
	static char *array;
	unsigned long m = num;
	static char buf[50];
	char sign = 0;
	
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		m = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do	{
		*--ptr = array[m % base];
		m /= base;
	} while (m != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * -remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void _remove_comments(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
		if (buf[r] == '#' && (!r|| buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
}
