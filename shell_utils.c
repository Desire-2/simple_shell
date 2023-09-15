#include "main.h"


/**
 * clear_inform - Function to initializes info_t struct
 * @info: struct address
 */

void clear_inform(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;

}


/**
 * set_inform - Function to initializes info_t struct
 * @info: struct address in shell
 * @av: argument vector in shell
 */

void set_inform(info_t *info, char **av)
{
	int r = 0;

	info->fname = av[0];

	if (info->arg)
	{
		info->argv = str_to_words(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _str_duplicate(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (r = 0; info->argv && info->argv[r]; r++)
			;
		info->argc = r;
		rep_alias(info);
		rep_vars(info);
	}

}


/**
 * free_inform - Function to frees info_t struct fields
 * @info: struct address
 * @all: if freeing all fields true
 */

void free_inform(info_t *info, int all)
{
	_str_frees(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			_free_list_nds(&(info->env));
		if (info->history)
			_free_list_nds(&(info->history));
		if (info->alias)
			_free_list_nds(&(info->alias));
		_str_frees(info->environ);
			info->environ = NULL;
		_free_p_n((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_put_char_std(BUF_FLUSH);
	}
}

