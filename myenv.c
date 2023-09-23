#include "main.h"

/**
 * _myenv - Function that prints the current environment
 * @info: Structure of  arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	_print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Function gets the value of an environ variable
 * @info: Structure  arguments
 * @name: environ var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *nd = info->env;
	char *w;

	while (nd)
	{
		w = _starts_with(nd->str, name);
		if (w && *w)
			return (w);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Function Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure  arguments.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int r;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (r = 1; r <= info->argc; r++)
		_unsetenv(info, info->argv[r]);

	return (0);
}

/**
 * _populate_env_list - Function that populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _populate_env_list(info_t *info)
{
	list_t *nd = NULL;
	size_t r;

	for (r = 0; environ[r]; r++)
		_add_node_end(&nd, environ[r], 0);
	info->env = nd;
	return (0);
}
