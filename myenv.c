
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
 * _getenviron - Gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */

char *_getenviron(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *i;

	while (node)
	{
		i = starts_with_node(node->str, name);
		if (i != NULL && *i != '0')
			return (i);
		node = node->next;
	}
	return (NULL);
}


/**
 * _my_set_envirn - Function to Initialize a new environment variable,
 *		or modify an existing one
 * @info: Structure containing potential arguments.
 *	Used to maintain constant function prototype.
 *  Return: 0 Always
 */

int _my_set_envirn(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs_str("Incorrect number of arguement in shell\n");
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
	int n;

	if (info->argc == 1)
	{
		_eputs_str("Too few arguements in shell.\n");
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
	info->env = node;
	return (0);
}
