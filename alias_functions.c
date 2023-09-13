#include "main.h"

/**
 * _my_hist - displays the history list, one command by line
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */

int _my_hist(info_t *info)
{
	print_list(info->history);
	return (0);

}


/**
* unset_alias_to_str - Function to sets alias to string
 * @info: parameter struct
 * @str: the alias string
 *
 * Return: 0 on success, 1 on error
 */

int  unset_alias_to_str(info_t *info, char *str)
{
	char *w;
	int c;
	int retrn;

	p = _strchar(str, '=');
	if (!w)
		return (1);
	c = *w;
	*p = 0;
	retrn = delete_node_at_index_of(&(info->alias),
		get_node_index_on(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (retrn);

}


/**
 * set_alias_str - Function to sets alias to string
 * @info: parameter struct
 * @str: the string to represent alias
 *
 * Return: 0 on success, 1 on error
 */

int set_alias_str(info_t *info, char *str)
{
	char *w;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	if (!*++w)
		return (unset_alias_str(info, str));

	unset_alias_str(info, str);
	return (add_node_end_of(&(info->alias), str, 0) == NULL);

}


/**
 * print_alias_str - Function to prints an alias string
 * @node: the alias node
 *
 * Return: 0 on success, 1 on error
 */

int print_alias_str(list_t *node)
{
	char *w = NULL, *c = NULL;

	if (node)
	{
		w = _strchar(node->str, '=');
		for (a = node->str; c <= p; c++)
		_putchar(*c);
		_putchar('\'');
		_puts(w + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}


/**
 * _my_alias - Function to mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 *	Used to maintain constant function prototype.
 * Return: 0 Always
 */

int _my_alias(info_t *info)
{
	int r = 0;
	char *w = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias_str(node);
			node = node->next;
		}
		return (0);
	}
	for (r = 1; info->argv[r]; r++)
	{
		w = _strchar(info->argv[r], '=');
		if (w)
			set_alias_str(info, info->argv[r]);
		else
			print_alias_str(node_starts_with_(info->alias, info->argv[r], '='));
	}
	return (0);
}
