#include "main.h"

/**
 * _gets_environ - Function to returns the string array copy of our environ
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: 0 Always
 */

char **_gets_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}


/**
 * _unsetenvirn - Function to Remove an environment variable
 * @info: Structure containing potential arguments.
 * It is Used to maintain
 * constant function prototype.
 * Return: on delete 1 , otherwise 0
 * @var: the string env variable property
 */

int _unsetenvirn(info_t *info, char *var)
{
	list_t *node = info->envirn;
	size_t r = 0;
	char *m;

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
			node = info->envirn;
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
	list_t *node;
	char *m;

	if (!var)
		return (0);
	if (!value)
		return (0);

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = info->envirn;
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
	add_node_ to_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);

}