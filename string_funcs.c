#include "main.h"

/**
 * _strlen - Function returns the length of a string
 * @s:  string with length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int r = 0;

	if (!s)
		return (0);

	while (*s++)
		r++;
	return (r);
}

/**
 * _strcmp - Function performs lexicogarphic comparison of two strangs.
 * @s1: First strinng
 * @s2: Second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _starts_with - Function checks if needle starts with haystack
 * @haystack: String to search
 * @needle: Substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *_starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Function concatenates two strings
 * @dest: buffer destination
 * @src: source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *retn = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (retn);
}
