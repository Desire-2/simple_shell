#include "main.h"
/**
 * _eputs_str - Function that prints an input string
 * @str: the string to  print
 *
 * Return: Nothing
 */

void _eputs_str(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_eput_char_stderr(str[n]);
		n++;
	}
}

/**
 * _eput_char_stderr - Writes the character c to stderr
 * @c: The character to be printed
 *
 * Return: 1 On success.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _eput_char_stderr(char c)
{
	static int n;
	static char buffer[WRITE_BUF_SIZE];


	if (c == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(2, buffer, n);
		n = 0;
	}
	if (c != BUF_FLUSH)
		buffer[n++] = c;
	return (1);
}

/**
 * _put_fld - Function to write the character c to given fd
 * @c: The character to be printed
 * @fd: The filedescriptor to be writen to
 *
 * Return: 1 On success.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _put_fld(char c, int fd)
{
	static char buffer[WRITE_BUF_SIZE];
    static int n;


	if (c == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, n);
		n = 0;
	}
	if (c != BUF_FLUSH)
		buffer[n++] = c;
	return (1);
}

/**
 *_puts_fld - Prints string input
 * @str: The string to print
 * @fd: The filedescriptor to be writen to
 *
 * Return: the number of chars put
 */

int _puts_fld(char *str, int fd)
{
	int n = 0;

	if (!str)
		return (0);
	while (*str)
	{
	n += _put_fld(*str++, fd);
	}
	return (n);
}
