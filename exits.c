#include "main.h"


/**
 *_str_m_cpy - Function to copie a string
 *@dest: The string destination  to be copied to
 *@src: The string source
 *@n: The characters amount to be copied
 *Return: The string concatenated
 */

char *_str_m_cpy(char *dest, char *src, int n)
{
	int r;
	int w;
	char *s = dest;

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
	return (s);
}


/**
 **_str_m_cat - Function to concatenate two strings
 *@dest: The initial string
 *@src: The the following string
 *@n: The bytes  amount to be maximally used
 *Return: The string concatenated
 */

char *_str_m_cat(char *des, char *src, int n)
{
	int r = 0;
	int j = 0;
	char *z = des;

	
	while (des[r] != '\0')
		r++;
	while (src[j] != '\0' && j < n)
	{
		des[j] = src[j];
		r++;
		j++;
	}
	if (j < n)
		des[j] = '\0';
	return (z);
}


/**
 **_str_char - Function to locates a character in a string
 *@s: The parsed string 
 *@c: the character to check in
 *Return: (s) a pointer
 */

char *_str_char(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
