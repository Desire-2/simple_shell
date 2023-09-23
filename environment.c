#include "main.h"

/**
 * get_environ - Function returns the string array copy of our environ
 * @info: Structure  arguments.
 * Return: Always 0
 */
char **_get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = _list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Function Remove an environment variable
 * @info: Structure of arguments.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *nd = info->env;
	size_t r = 0;
	char *w;

	if (!nd || !var)
		return (0);

	while (nd)
	{
		w = _starts_with(nd->str, var);
		if (w && *w == '=')
		{
			info->env_changed = _delete_node_at_index(&(info->env), r);
			r = 0;
			nd = info->env;
			continue;
		}
		nd = nd->next;
		r++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Function that Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure of arguments.
 * @var: The string env var property
 * @value: The string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buffer = NULL;
	list_t *nd;
	char *w;

	if (!var || !value)
		return (0);

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	nd = info->env;
	while (nd)
	{
		w = _starts_with(nd->str, var);
		if (w && *w == '=')
		{
			free(nd->str);
			nd->str = buffer;
			info->env_changed = 1;
			return (0);
		}
		nd = nd->next;
	}
	_add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}
