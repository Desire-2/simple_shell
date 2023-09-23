#include "main.h"

/**
 * bfree - Function frees a pointer and NULLs the address
 * @ptr: pointer to freed address
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
