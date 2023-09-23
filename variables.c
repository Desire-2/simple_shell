#include "main.h"

/**
 * _is_chain - Function test if current char in buffer is a chain delimeter
 * @info: Parameter Struct
 * @buf: Char Buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int _is_chain(info_t *info, char *buf, size_t *p)
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
 * _check_chain - Function checks we should continue chaining based on last status
 * @info: Parameter Struct
 * @buf: The char Buffer
 * @p: address of current position in buf
 * @i: Starting Position in buf
 * @len: Length of buf
 *
 * Return: Void
 */
void _check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t w = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[w] = 0;
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
 * _replace_alias - Function  replaces an aliases in the tokenized string
 * @info: Parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int _replace_alias(info_t *info)
{
	int r;
	list_t *node;
	char *w;

	for (r = 0; r < 10; r++)
	{
		node = _node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		w = _strchr(node->str, '=');
		if (!w)
			return (0);
		w = _strdup(w + 1);
		if (!w)
			return (0);
		info->argv[0] = w;
	}
	return (1);
}

/**
 * _replace_vars - Function replaces vars in the tokenized string
 * @info: Parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int _replace_vars(info_t *info)
{
	int r = 0;
	list_t *nd;

	for (r = 0; info->argv[r]; r++)
	{
		if (info->argv[r][0] != '$' || !info->argv[r][1])
			continue;

		if (!_strcmp(info->argv[r], "$?"))
		{
			_replace_string(&(info->argv[r]),
					_strdup(_convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[r], "$$"))
		{
			_replace_string(&(info->argv[r]),
					_strdup(_convert_number(getpid(), 10, 0)));
			continue;
		}
		nd = _node_starts_with(info->env, &info->argv[r][1], '=');
		if (nd)
		{
			_replace_string(&(info->argv[r]),
					_strdup(_strchr(nd->str, '=') + 1));
			continue;
		}
		_replace_string(&info->argv[r], _strdup(""));

	}
	return (0);
}

/**
 * _replace_string - Function replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int _replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
