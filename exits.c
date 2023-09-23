#include "main.h"

/**
 **_strncpy - Function that copies a string
 *@dest: destination string to be copied to
 *@src: Source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int r, w;
	char *z = dest;

	r = 0;
	while (src[r] != '\0' && r < n - 1)
	{
		dest[r] = src[r];
		r++;
	}
	if (r < n)
	{
		w = r;
		while (w < n)
		{
			dest[w] = '\0';
			w++;
		}
	}
	return (z);
}

/**
 **_strncat - Function that concatenates two strings
 *@dest: First string
 *@src: the nex string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int r, w;
	char *s = dest;

	r = 0;
	w = 0;
	while (dest[r] != '\0')
		r++;
	while (src[w] != '\0' && w < n)
	{
		dest[r] = src[w];
		r++;
		w++;
	}
	if (w < n)
		dest[r] = '\0';
	return (s);
}

/**
 **_strchr - Function that locates a character in a string
 *@s: String to  parse
 *@c:  Character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
