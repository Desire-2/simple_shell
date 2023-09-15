#include "main.h"

/**
 * _mem_set_cons - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */

char *_mem_set_cons(char *s, char b, unsigned int n)
{
	unsigned int r;

	for (r = 0; r < n; r++)
		s[r] = b;
	return (s);

}


/**
 * _str_frees - frees a string of strings
 * @pp: string of strings
 */

void _str_frees(char **pp)
{
	char **z = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	_str_frees(z);

}


/**
 * _reallocate_bl - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */

void *_reallocate_bl(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *m;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	m = malloc(new_size);
	if (!m)
	return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		m[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (m);

}
