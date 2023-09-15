#include "main.h"


/**
 * is_char_chain - Function to test if current char
 *		in buffer is a chain delimeter
 * @buf: the char buffer
 * @info: The parameter struct
 * @p: The address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */

int is_char_chain(info_t *info, char *buf, size_t *p)
{
	size_t w = *p;

	if (buf[w] == '|' && buf[w + 1] == '|')
	{
		buf[w] = 0;
		w++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[w] == '&' && buf[w + 1] == '&')
	{
		buf[w] = 0;
		w++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[w] == ';')
	{
		buf[w] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = w;
	return (1);

}


/**
 * check_chain_st - Function to check if we should
 *		continue chaining based on last status
 * @info: The parameter  of struct
 * @buf: The char buffer
 * @p: The address of current position in buf
 * @i: The starting position in buf
 * @len: The length of buf
 * Return: Void
 */

void check_chain_st(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t w = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			w = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			w = len;
		}
	}
	*p = w;
}


/**
 * rep_alias - Function to replaces an aliases in the tokenized string
 * @info: The parameter of struct
 *
 * Return: if replaced 1, otherwise 0
 */

int rep_alias(info_t *info)
{
	int r;
	list_t *node;
	char *w;

	for (r = 0; r < 10; r++)
	{
		node = _nd_starts_with_(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		w = _str_char(node->str, '=');
		if (!w)
			return (0);
		w = _str_duplicate(w + 1);
		if (!w)
			return (0);
		info->argv[0] = w;
	}
	return (1);
}


/**
 * rep_vars - Function to replace vars in the tokenized string
 * @info: The parameter of struct
 *
 * Return: if replaced 1, otherwise 0
 */

int rep_vars(info_t *info)
{
	int r = 0;
	list_t *node;

	for (r = 0; info->argv[r]; r++)
	{
		if (info->argv[r][0] != '$')
			continue;
		if (!info->argv[r][1])
			continue;

		if (!_str_cmp_two(info->argv[r], "$?"))
		{
			rep_str(&(info->argv[r]),
				_str_duplicate(_convert_nb(info->status, 10, 0)));
			continue;
		}
		if (!_str_cmp_two(info->argv[r], "$$"))
		{
			rep_str(&(info->argv[r]),
						_str_duplicate(_convert_nb(getpid(), 10, 0)));
			continue;
		}
		node = _nd_starts_with_(info->env, &info->argv[r][1], '=');
		if (node)
		{
			rep_str(&(info->argv[r]),
						_str_duplicate(_str_char(node->str, '=') + 1));
			continue;
		}
		rep_str(&info->argv[r], _str_duplicate(""));

	}
	return (0);

}


/**
 * rep_str - Function to replace string
 * @old: The address of old string
 * @new: The new string
 *
 * Return: if replaced 1, otherwis 0
 */

int rep_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}




