#include "main.h"

/**
 * _memset - Function fills memory with a constant byte
 * @s: memory area pointer
 * @b: Byte to fill *s with
 * @n: Amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int r;

	for (r = 0; r < n; r++)
		s[r] = b;
	return (s);
}

/**
 * ffree - Function frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **b = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(b);
}

/**
 * _realloc - Function reallocates a block of memory
 * @ptr: Pointer to previous malloc'ated block
 * @old_size: Byte size of previous block
 * @new_size: Byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *w;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	w = malloc(new_size);
	if (!w)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		w[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (w);
}
