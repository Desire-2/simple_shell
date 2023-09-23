#include "main.h"

/**
 * _myhistory - Functin displays the history list
 * @info: Structure of arguments.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	_print_list(info->history);
	return (0);
}

/**
 * _unset_alias - function that sets alias to string
 * @info: Struct parameter
 * @str: String alias
 *
 * Return: Always 0 on success, 1 on error
 */
int _unset_alias(info_t *info, char *str)
{
	char *w = _strchr(str, '=');
	char d;
	int retn;


	if (!w)
		return (1);
	d = *w;
	*w = 0;
	retn = _delete_node_at_index(&(info->alias),
		_get_node_index(info->alias, _node_starts_with(info->alias, str, -1)));
	*w = d;
	return (retn);
}

/**
 * _set_alias - Function that sets alias to string
 * @info: Struct parameter
 * @str: String alias
 *
 * Return: Always 0 on success, 1 on error
 */
int _set_alias(info_t *info, char *str)
{
	char *w;

	w = _strchr(str, '=');
	if (!w)
		return (1);
	if (!*++w)
		return (_unset_alias(info, str));

	_unset_alias(info, str);
	return (_add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _print_alias - Function prints an alias string
 * @node: Alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int _print_alias(list_t *node)
{
	char *w = NULL;
	char *d = NULL;

	if (node)
	{
		w = _strchr(node->str, '=');
		for (d = node->str; d <= w; d++)
		_putchar(*d);
		_putchar('\'');
		_puts(w + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	list_t *nd= NULL;
	int r = 0;
	char *w = NULL;

	if (info->argc == 1)
	{
		nd = info->alias;
		while (nd)
		{
			_print_alias(nd);
			nd = nd->next;
		}
		return (0);
	}
	for (r = 1; info->argv[r]; r++)
	{
		w = _strchr(info->argv[r], '=');
		if (w)
			_set_alias(info, info->argv[r]);
		else
			_print_alias(_node_starts_with(info->alias, info->argv[r], '='));
	}

	return (0);
}
