#include "main.h"

/**
 * _my_envirn - Function to print the current environment
 * @info: Structure containing potential arguments.
 *		Used to maintain constant function prototype.
 * Return: 0 Always
 */

int _my_envirn(info_t *info)
{
	prints_list_string(info->env);
	return (0);
}


/**
 * _getenvirn - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */

char *_getenvirn(info_t *info, const char *name)
{
	list_t *node = info->envirrn;
	char *i;

	while (node)
	{
		i = starts_with(node->str, name);
		if (i && *i)
			return (i);
		node = node->next;
	}
	return (NULL);
}


/**
 * _my_set_env - Function to Initialize a new environment variable,
 *		or modify an existing one
 * @info: Structure containing potential arguments.
 *	Used to maintain constant function prototype.
 *  Return: 0 Always
 */

int _my_set_env(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguement in shell\n");
		return (1);
	}
	if (_setenvirn(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);

}

/**
 * _my_unset_envirn - Function to Remove an environment variable in shell
 * @info: Structure containing potential arguments.
 *	Used to maintain constant function prototype.
 * Return: 0 Always
 */

int _my_unset_envirn(info_t *info)
{
	int m;

	if (info->argc == 1)
	{
		_eputs("Too few arguements in shell.\n");
		return (1);
	}
	for (n = 1; n <= info->argc; n++)
		_unsetenvirn(info, info->argv[n]);

	return (0);
}


/**
 * populate_envnt_list - Function to populate env linked list
 * @info: Structure containing potential arguments.
 *	Used to maintain constant function prototype.
 * Return: 0 Always
 */

int populate_envnt_list(info_t *info)
{
	list_t *node = NULL;
	size_t len;

	for (len = 0; environ[len]; len++)
		add_node_to_end(&node, environ[len], 0);
	info->envirn = node;
	return (0);
}
