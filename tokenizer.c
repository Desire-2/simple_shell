#include "main.h"


/**
 * **str_to_words - Function to split a string into words.
 *		Repeat delimiters are ignored
 * @str: the string to be inputed
 * @d: the string of delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */


char **str_to_words(char *str, char *d)
{
	int r, k, m;
	int nwords = 0;
	int w;
	char **s;

	if (str == NULL)
		return (NULL);
	if (str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (r = 0; str[r] != '\0'; r++)
		if (!is_delimeter(str[r], d)
			nwords++;
		if (is_delimeter(str[r + 1], d) || !str[r + 1])
			nwords++;

	if (nwords == 0)
		return (NULL);
	s = malloc((1 + nwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, w = 0; w < nwords; w++)
	{
		while (is_delimeter(str[r], d))
			r++;
		k = 0;
		while (!is_delimeter(str[r + k], d) && str[r + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[w])
		{
			for (k = 0; k < w; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[w][m] = str[r++];
		s[w][m] = 0;
	}
	s[w] = NULL;
	return (s);
}


/**
 * **str_to_word - function to splits a string into words
 * @str: the string to be  inputed
 * @d: the delimeter character
 * Return: a pointer to an array of strings, 
 *		or NULL on failure
 */
char **str_to_word(char *str, char d)
{
	int r, k, m;
	int w;
	int nwords = 0;
	char **s;

	if (str == NULL)
		return (NULL);
	if (str[0] == 0)
		return (NULL);

	for (r = 0; str[r] != '\0'; r++)
		if ((str[r] != d && str[r + 1] == d)
		nwords++;
	for (str[i] != d && !str[i + 1]) || str[i + 1] == d)
		nwords++;
	if (nwords == 0)
		return (NULL);
	s = malloc((1 + nwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < nwords; w++)
	{
		while (str[r] == d && str[r] != d)
			r++;
		k = 0;
		while (str[r + k] != d && str[r + k] && str[r + k] != d)
			k++;
		s[r] = malloc((k + 1) * sizeof(char));
		if (!s[w])
		{
			for (k = 0; k < w; k++)
				free(s[k]);
			free(s);
			return (NULL);

		}
		for (m = 0; m < k; m++)
			s[w][m] = str[r++];
		s[w][m] = 0;
	}
	s[w] = NULL;
	return (s);

}
