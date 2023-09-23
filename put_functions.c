#include "main.h"

/**
 * _eputs - Function that prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int r = 0;

	if (!str)
		return;
	while (str[r] != '\0')
	{
		_eputchar(str[r]);
		r++;
	}
}

/**
 * _eputchar - Function that writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static char buffer[WRITE_BUF_SIZE];
	static int r;

	if (c == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(2, buffer, r);
		r = 0;
	}
	if (c != BUF_FLUSH)
		buffer[r++] = c;
	return (1);
}

/**
 * _putfd -Function that writes the character c to given fd
 * @c: character to be printed
 * @fd: The filedescriptor to write to
 * Return: 1 On success.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static char buffer[WRITE_BUF_SIZE];
	static int r;

	if (c == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, r);
		r = 0;
	}
	if (c != BUF_FLUSH)
		buffer[r++] = c;
	return (1);
}

/**
 * _putsfd - Function that prints an input string
 * @str: string to  print
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int r = 0;

	if (!str)
		return (0);
	while (*str)
	{
		r += _putfd(*str++, fd);
	}
	return (r);
}
