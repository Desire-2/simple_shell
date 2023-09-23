#include "main.h"

/**
 * _add_node - Function that adds a node to the start of the list
 * @head: Address of pointer to head node
 * @str: field of node str
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *_add_node(list_t **head, const char *str, int num)
{
	list_t *nw_head;

	if (!head)
		return (NULL);
	nw_head = malloc(sizeof(list_t));
	if (!nw_head)
		return (NULL);
	_memset((void *)nw_head, 0, sizeof(list_t));
	nw_head->num = num;
	if (str)
	{
		nw_head->str = _strdup(str);
		if (!nw_head->str)
		{
			free(nw_head);
			return (NULL);
		}
	}
	nw_head->next = *head;
	*head = nw_head;
	return (nw_head);
}

/**
 * _add_node_end - Function that adds a node to the end of the list
 * @head: Pointer to head node address
 * @str: field of node str
 * @num: node index used by history
 * Return: size of list
 */
list_t *_add_node_end(list_t **head, const char *str, int num)
{
	list_t *nw_node, *nd;

	if (!head)
		return (NULL);

	nd = *head;
	nw_node = malloc(sizeof(list_t));
	if (!nw_node)
		return (NULL);
	_memset((void *)nw_node, 0, sizeof(list_t));
	nw_node->num = num;
	if (str)
	{
		nw_node->str = _strdup(str);
		if (!nw_node->str)
		{
			free(nw_node);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = nw_node;
	}
	else
		*head = nw_node;
	return (nw_node);
}

/**
 * _print_list_str - Function that prints only the str element of a list_t linked list
 * @h: Pointer to first node
 * Return: List size
 */
size_t _print_list_str(const list_t *h)
{
	size_t r = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		r++;
	}
	return (r);
}

/**
 * _delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int _delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *nd, *prev_node;
	unsigned int r = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		nd = *head;
		*head = (*head)->next;
		free(nd->str);
		free(nd);
		return (1);
	}
	nd = *head;
	while (nd)
	{
		if (r == index)
		{
			prev_node->next = nd->next;
			free(nd->str);
			free(nd);
			return (1);
		}
		r++;
		prev_node = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * _free_list - Function frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void _free_list(list_t **head_ptr)
{
	list_t *nd, *next_nd, *hd;

	if (!head_ptr || !*head_ptr)
		return;
	hd = *head_ptr;
	nd = hd;
	while (nd)
	{
		next_nd = nd->next;
		free(nd->str);
		free(nd);
		nd = next_nd;
	}
	*head_ptr = NULL;
}
