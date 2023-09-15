#include "main.h"


/**
 * _err_atoi_int - Function that converts a string to an integer
 * @s: the converted string
 * Return: if no numbers in string 0, otherwise converted number
 *	-1 on error
 */

int _err_atoi_int(char *s)
{
	unsigned long int rslt = 0;
    int n = 0;
	
	if (*s == '+')
		s++;
	for (n = 0;  s[n] != '\0'; n++)
	{
		if (s[n] >= '0' && s[n] <= '9')
		{
			rslt *= 10;
			rslt += (s[n] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}


/**
 * _print_errors - prints an error message
 * @info: return info struct & parameter
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *	-1 on error
 */

void _print_errors(info_t *info, char *estr)
{
	_eputs_str(info->fname);
	_eputs_str(": ");
	_print_dc(info->line_count, STDERR_FILENO);
	_eputs_str(": ");
	_eputs_str(info->argv[0]);
	_eputs_str(": ");
	_eputs_str(estr);
}


/**
 * _print_dc -  Prints a decimal (integer) number (base 10)
 * @input: The input
 * @fd: The filedescriptor to be writen to
 *
 * Return: number of characters printed
 */

int _print_dc(int input, int fd)
{
	int n, cnt = 0;
	int (*__putchar)(char) = _put_char_std;
	unsigned int _abs_;
	unsigned int current;


	if (fd == STDERR_FILENO)
		__putchar = _eput_char_stderr;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		cnt++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (n = 1000000000; n > 1; n /= 10)
	{
		if (_abs_ / n)
		{
			__putchar('0' + current / n);
			cnt++;
		}
		current %= n;
	}
	__putchar('0' + current);
	cnt++;
	return (cnt);
}

/**
 * _convert_nb - converter function
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */

char *_convert_nb(long int num, int base, int flags)
{
	char *ptr;
	unsigned long i = num;
	char sign = 0;
	static char buffer[50];
	static char *array;


	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		i = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do	{
		*--ptr = array[i % base];
		i /= base;
	} while (i != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * _rm_comment - Replaces first instance of '#' with '\0'
 * @buf: Address of the string to modify
 * Return: 0 Always;
 */

void _rm_comment(char *buf)
{
	int n;

	for (n = 0; buf[n] != '\0'; n++)
		if (buf[n] == '#' && (!n || buf[n - 1] == ' '))
		{
			buf[n] = '\0';
			break;
		}
}
