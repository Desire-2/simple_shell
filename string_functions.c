#include "main.h"

/**
 * _strcpy - Function copies a string
 * @dest: Destination
 * @src: Source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int r = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[r])
	{
		dest[r] = src[r];
		r++;
	}
	dest[r] = 0;
	return (dest);
}

/**
 * _strdup - Function that Duplicates  String
 * @str: The String to Duplicate
 *
 * Return: Pointer to the Duplicated String
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *retn;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	retn = malloc(sizeof(char) * (len + 1));
	if (!retn)
		return (NULL);
	for (len++; len--;)
		retn[len] = *--str;
	return (retn);
}

/**
 * _puts - Function that prints an input string
 * @str: The string to  Print
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int r = 0;

	if (!str)
		return;
	while (str[r] != '\0')
	{
		_putchar(str[r]);
		r++;
	}
}

/**
 * _putchar - Function that writes the character c to stdout
 * @c: The character to be  printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int r;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(1, buffer, r);
		r = 0;
	}
	if (c != BUF_FLUSH)
		buffer[r++] = c;
	return (1);
}
