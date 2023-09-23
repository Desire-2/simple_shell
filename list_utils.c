#include "main.h"

/**
 * _list_len - Function that determines length of linked list
 * @h: first node to be pointed
 * Return: size of list
 */
size_t _list_len(const list_t *h)
{
	size_t r = 0;

	while (h)
	{
		h = h->next;
		r++;
	}
	return (r);
}

/**
 * _list_to_strings - Function returns an array of strings of the list->str
 * @head:  first nodeto be pointed
 * Return: Strings if array
 */
char **_list_to_strings(list_t *head)
{
	list_t *nd = head;
	size_t r = _list_len(head), w;
	char **strs;
	char *str;

	if (!head || !r)
		return (NULL);
	strs = malloc(sizeof(char *) * (r + 1));
	if (!strs)
		return (NULL);
	for (r = 0; nd; nd = nd->next, r++)
	{
		str = malloc(_strlen(nd->str) + 1);
		if (!str)
		{
			for (w = 0; w < r; w++)
				free(strs[r]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, nd->str);
		strs[r] = str;
	}
	strs[r] = NULL;
	return (strs);
}


/**
 * )print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t _print_list(const list_t *h)
{
	size_t r  = 0;

	while (h)
	{
		_puts(_convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		r++;
	}
	return (r);
}

/**
 * -node_starts_with - Function returns node whose string starts with prefix
 * @node: list head pointer
 * @prefix: match string
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *_node_starts_with(list_t *node, char *prefix, char c)
{
	char *w = NULL;

	while (node)
	{
		w = _starts_with(node->str, prefix);
		if (w && ((c == -1) || (*w == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t _get_node_index(list_t *head, list_t *node)
{
	size_t r = 0;

	while (head)
	{
		if (head == node)
			return (r);
		head = head->next;
		r++;
	}
	return (-1);
}
