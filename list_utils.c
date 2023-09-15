#include "main.h"

/**
 * _list_length_link - Functions that determines length of linked list
 * @h: First node pointer
 *
 * Return: List size
 */

size_t _list_length_link(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		h = h->next;
		n++;
	}
	return (n);

}


/**
 * _list_to_str - returns an array of strings of the list->str
 * @head: First node pointer
 * Return: str array
 */

char **_list_to_str(list_t *head)
{
	list_t *nd = head;
	size_t n = _list_length_link(head), w;
	char **strs, *str;

	if (!head || !n)
		return (NULL);

	strs = malloc(sizeof(char *) * (n + 1));
	if (!strs)
		return (NULL);
	for (n = 0; nd; nd = nd->next, n++)
	{
		str = malloc(_str_length(nd->str) + 1);
		if (!str)
		{
			for (w = 0; w < n; w++)
				free(strs[w]);
			free(strs);
			return (NULL);
		}

		str = _str_cpy(str, nd->str);
		strs[n] = str;
	}
	strs[n] = NULL;
	return (strs);

}
/**
 * print_list_el_link - prints all elements of a list_t linked list
 * @h: First node pointer
 *
 * Return: List size
 */

size_t print_list_el_link(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		_puts_str(_convert_nb(h->num, 10, 0));
		_put_char_std(':');
		_put_char_std(' ');
		_puts_str(h->str ? h->str : "(nil)");
		_puts_str("\n");
		h = h->next;
		n++;
	}
	return (n);
}


/**
 * _nd_starts_with_ - Funcs that returns node whose string starts with prefix
 * @node: List head pointer
 * @prefix: String to be matched
 * @c: The following character after prefix to match
 *
 * Return: Matched node or null
 */

list_t *_nd_starts_with_(list_t *node, char *prefix, char c)
{
	char *j = NULL;

	while (node)
	{
		j = starts_with_node(node->str, prefix);
		if (j && ((c == -1) || (*j == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


/**
 * get_nd_index_on - Function that gets the index of a node
 * @head: List head pointer
 * @node: The node pointed
 *
 * Return: node index or -1
 */

ssize_t get_nd_index_on(list_t *head, list_t *node)
{
	size_t n = 0;

	while (head)
	{
		if (head == node)
			return (n);
		head = head->next;
		n++;
	}
	return (-1);
}
