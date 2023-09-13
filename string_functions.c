#include "main.h"
/**
 * _str_cpy - Function that copies a string
 * @dest: String destination
 * @src: The source string
 *
 * Return: Pointer to destination
 */

char *_str_cpy(char *dest, char *src)
{
	int n = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = 0;
	return (dest);
}


/**
 * _str_duplicate - Functin that duplicates a string
 * @str: The string to be duplicated
 *
 * Return: Pointer to the duplicated string
 */

char *_str_duplicate(const char *str)
{
	char *rtn;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (rtn);
}


/**
 * _puts_str - Function to print an input string
 * @str: The string to print
 *
 * Return: Nothing
 */

void _puts_str(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_put_char_std(str[n]);
		n++;
	}
}


/**
 * _put_char_std - Function writes the character c to stdout
 *@c: The character to be printed
 * Return: 1 On success.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _put_char_std(char c)
{
	static char buffer[WRITE_BUF_SIZE]
	static int n;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buffer, n);
		n = 0;
	}
	if (c != BUF_FLUSH)
		buffer[n++] = c;
	return (1);
}
