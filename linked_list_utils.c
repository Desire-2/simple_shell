#include "main.h"


/**
 * _add_node_start - Function to add a node to the start of the list
 * @head: Pointer to head node address
 * @str: Node field of str
 * @num: node index to be used by history
 *
 * Return: list size
 */

list_t *_add_node_start(list_t **head, const char *str, int num)
{
	list_t *nw_hd;

	if (!head)
		return (NULL);
	nw_hd = malloc(sizeof(list_t));

	if (!nw_hd)
		return (NULL);
	_memset((void *)nw_hd, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		nw_hd->str = _strdup(str);
		if (!nw_hd->str)
		{
			free(nw_hd);
			return (NULL);
		}
	}
	nw_hd->next = *head;
	*head = nw_hd;
	return (nw_hd);

}


/**
 * add_node_to_end - adds a node to the end of the list
 * @head: Pointer to head node address
 * @str: Node field of str
 * @num: Node index to be used by history
 *
 * Return: list size
 */

list_t *add_node_to_end(list_t **head, const char *str, int num)
{
	list_t *nw_node, *nd;

	if (!head)
		return (NULL);

	nd = *head;
	nw_node = malloc(sizeof(list_t));
	if (!nw_node)
		return (NULL);
	_memset((void *)nw_node, 0, sizeof(list_t));
	new_node->num = num;
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
		*head = nw_nde;
	return (nw_nde);
}


/**
 * prints_list_string - Prints only the str element of a list_t linked list
 * @h: First node pointer
 *
 * Return: List size
 */

size_t prints_list_string(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		n++;
	}
	return (n);
}


/**
 * delete_node_at_index_of - Function to delete node at given index
 * @head: Pointer to first node address
 * @index: index of node to be  deleted
 *
 * Return: on success 1, on failure 0
 */

int delete_node_at_index_of(list_t **head, unsigned int index)
{
	list_t *nd, *prev_nd;
	unsigned int r = 0;

	if (!head)
		return (0);
if (!*head)
	return (0);

	if (!index)
	{
		nd = *head;
		*head = (*head)->next;
		free(nd->str);
		free(nd);
		return (1);
	}
	node = *head;
	while (nd)
	{
		if (r == index)
		{
			prev_nd->next = nd->next;
			free(nd->str);
			free(nd);
			return (1);
		}
		r++;
		prev_nd = nd;
		node = nd->next;
	}
	return (0);
}


/**
 * _free_list_nds - Function that frees all nodes of a list
 * @head_ptr: Pointer to head node address
 *
 * Return: void
 */

void _free_list_nds(list_t **head_ptr)
{
	list_t *nd, *next_nd, *hd;

	if (!head_ptr)
		return;
if (!*head_ptr)
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
