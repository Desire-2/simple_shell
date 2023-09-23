
#include "main.h"

/**
 * **_strtow - Function that splits a string into words. Repeat delimiters are ignored
 * @str: Input string
 * @d: Delimeter string
 * Return: Pointer to an array of strings, or NULL on failure
 */

char **_strtow(char *str, char *d)
{
	int r, w, k, m, numwords = 0;
	char **z;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (r = 0; str[r] != '\0'; r++)
		if (!_is_delim(str[r], d) && (_is_delim(str[r + 1], d) || !str[r + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	z = malloc((1 + numwords) * sizeof(char *));
	if (!z)
		return (NULL);
	for (r = 0, w = 0; w < numwords; w++)
	{
		while (_is_delim(str[r], d))
			r++;
		k = 0;
		while (!_is_delim(str[r + k], d) && str[r + k])
			k++;
		z[w] = malloc((k + 1) * sizeof(char));
		if (!z[w])
		{
			for (k = 0; k < w; k++)
				free(z[k]);
			free(z);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			z[w][m] = str[r++];
		z[w][m] = 0;
	}
	z[w] = NULL;
	return (z);
}

/**
 * **_strtow2 - Function that splits a string into words
 * @str: Input string
 * @d:  Delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **_strtow2(char *str, char d)
{
	int r, w, k, m, numwords = 0;
	char **z;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (r = 0; str[r] != '\0'; r++)
		if ((str[r] != d && str[r + 1] == d) ||
				    (str[r] != d && !str[r + 1]) || str[r + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	z = malloc((1 + numwords) * sizeof(char *));
	if (!z)
		return (NULL);
	for (r = 0, w = 0; w < numwords; w++)
	{
		while (str[w] == d && str[w] != d)
			r++;
		k = 0;
		while (str[r + k] != d && str[r + k] && str[r + k] != d)
			k++;
		z[w] = malloc((k + 1) * sizeof(char));
		if (!z[w])
		{
			for (k = 0; k < w; k++)
				free(z[k]);
			free(z);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			z[w][m] = str[r++];
		z[w][m] = 0;
	}
	z[w] = NULL;
	return (z);
}
