shell_memory.c#include "main.h"

/**
 * _str_length - Function that returns the length of a string
 * @s: The string whose length to be checked
 *
 * Return: The integer length of string
 */

int _str_length(char *s)
{
	int n = 0;

	if (!s)
		return (0);

	while (*s++)
		n++;
	return (n);

}


/**
 * _str_cmp_twshell_memory.co - Function performs lexicogarphic comparison of two strings.
 * @s1: The first string
 * @s2: The next string
 *
 * Return: If s1 < s2 negative , if s1 > s2 positive, if s1 == s2 zero
 */

int _str_cmp_two(char *s1, char *s2)
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
 * starts_with_node - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *starts_with_node(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}


/**
 * _str_cat - Function that concatenates two strings
 * @dest: Buffer destination
 * @src: Buffer source
 *
 * Return: pointer to buffer destination
 */

char *_str_cat(char *dest, char *src)
{
	char *rtn = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rtn);

}
