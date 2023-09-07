#include "main.h"

/**
 * interactive - interactive mode of the shell
 *		 It determines whether the shell is running in interactive mode or not.
 * @info: a pointer to be taken to a structure of type info_t as an argument.
 *
 * Return: 1 interactive mode, 0 otherwise
 */

int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);

}


/**
 * is_delimimeter - checks if character c is a delimeter
 * @c: the char to be checked
 * @delim: string of delimeter
 * Return: if true 1 , if false 0
 */

int is_delimimeter(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}


/**
 * _isalphabet - checks for character c is alphabetic
 * @c: The character to be  inputed
 * Return: if c is alphabetic 1 , otherwise 0
 */


int _isalphabet(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}


/**
 * _atoi_int - function to convert a string to an integer
 * @s: the string will be converted
 * Return: if no numbers in string 0, otherwise converted number
 */


int _atoi_int(char *s)
{
	int r,  flag = 0;
	int sign = 1;
	int output;
	unsigned int rslt = 0;

	for (r = 0; s[r] != '\0' && flag != 2; r++)
	{
		if (s[r] == '-')
			sign *= -1;

		if (s[r] >= '0' && s[r] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[r] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -rslt;
	else
		output = rslt;
	return (output);
}
