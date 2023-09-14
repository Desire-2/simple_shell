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
g*
 * Return: 0 on success, 1 on error
 */

int  unset_alias_to_str(info_t *info, char *str)
{
	char *w;
	int c;
	int retrn;

	w = _str_char(str, '=');
	if (!w)
		return (1);
	c = *w;
	*w = 0;
	return = delete_node_at_index_of(&(info->alias),
		get_nd_index_on(info->alias, _nd_starts_with_(info->alias, str, -1)));
	*w = c;
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

	w = _str_char(str, '=');
	if (!w)
		return (1);
	if (!*++w)
		return (unset_alias_to_str(info, str));

	unset_alias_to_str(info, str);
	return (add_node_to_end(&(info->alias), str, 0) == NULL);

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
		w = _str_char(node->str, '=');
		for (c = node->str; c <= w; c++)
		_put_char_std(*c);
		_put_char_std('\'');
		_puts_str(w + 1);
		_puts_str("'\n");
		return (0);
	}
	return (1);
}


/**
 * _mya_lias - Function to mimics the alias builtin (man alias)
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
		w = _str_char(info->argv[r], '=');
		if (w)
			set_alias_str(info, info->argv[r]);
		else
			print_alias_str(_nd_starts_with_(info->alias, info->argv[r], '='));
	}
sigreturn (0);
}
