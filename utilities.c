#include "main.h"

/**
 * interactive - checks  if shell is interactive mode
 * @info: address of struct
 *
 * Return: if interactive mode 1 , 0 otherwise
 */
int _interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _is_delim - Function that checks if character is a delimeter
 * @c: the char to be checked
 * @delim: delimeter string
 * Return: if true 1, if false 0;
 */
int _is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * __isalpha - Function checks for alphabetic character
 * @c: The character to be inputed
 * Return: if c is alphabetic 1 , 0 otherwise
 */

int __isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * __atoi - function that converts a string to an integer
 * @s: the string to convert
 * Return: if no numbers in string 0 , converted number otherwise
 */

int __atoi(char *s)
{
	int r, flag = 0, outpt;
	int sign = 1;
	unsigned int rslt = 0;

	for (r = 0; s[r] != '\0' && flag != 2; r++)
	{
		if (s[r] == '-')
			sign *= -1;

		if (s[r] >= '0' && s[r] <= '9')
		{
			flag = 1;
			rslt *= 10;
			rslt += (s[r] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		outpt = -rslt;
	else
		outpt = rslt;

	return (outpt);
}
