#include "main.h"

/**
 * _get_environ - Function to returns the string array copy of our environ
 * @info: Structure containing potential arguments.
 *	Used to maintain constant function prototype.
 * Return: 0 Always
 */

char **_get_environ(info_t *info)
{
	if (!info->env || info->env_changed)
	{
		info->environ = _list_to_str(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}


/**
 * _unsetenvirn - Function to Remove an environment variable
 * @info: Structure containing potential arguments.
 * 	It is Used to maintain
 *	constant function prototype.

 * Return: on delete 1 , otherwise 0
 * @var: the string env variable property
 */

int _unsetenvirn(info_t *info, char *var)
{
	list_t *node = info->env;
	char *m;
	size_t r = 0;

	if (!node)
		return (0);
	if (!var)
		return (0);
	while (node)
	{
		m = starts_with_node(node->str, var);
		if (m && *m == '=')
		{
			info->env_changed = delete_node_at_index_of(&(info->env), r);
			r = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		r++;
	}
	return (info->env_changed);

}


/**
 * _setenvirn - Function to Initialize a new environment variable,
 *		or modify an existing one
 * @info: Structure containing potential arguments.
 *        Used to maintain constant function prototype.
 * @var: the string env variable property
 * @value: the string env variable value
 *  Return: 0 Always
 */

int _setenvirn(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	char *m;
	list_t *node;

	if (!var)
		return (0);
	if (!value)
		return (0);

	buff = malloc(_str_length(var) + _str_length(value) + 2);
	if (!buff)
		return (1);
	_str_cpy(buff, var);
	_str_cat(buff, "=");
	_str_cat(buff, value);
	node = info->env;
	while (node)
	{
		m = starts_with_node(node->str, var);
		if (m && *m == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_to_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);

}
