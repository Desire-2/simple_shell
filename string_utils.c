#include "main.h"


/**
 * shell_hsh - The main shell loop
 * @info: The parameter
 * @av: The argument vector from main()
 * Return: On success 0, on error 1, or error code
 */

int shell_hsh(info_t *info, char **av)
{
	ssize_t x = 0;
	int builtin_rtn = 0;

	while (x != -1 && builtin_rtn != -2)
	{
		_clear_inform(info);
		if (interactive_mode(info))
			_puts_str("$ ");
		_eput_char_stderr(BUF_FLUSH);
		x = get_input(info);
		if (x != -1)
		{
			_set_inform(info, av);
			builtin_rtn = _find_builtin_cmd(info);
			if (builtin_rtn == -1)
			_find_cmd_p(info);
		}
		else if (interactive_mode(info))
			_put_char_std('\n');
		_free_inform(info, 0);
	}
	_write_hist(info);
	_free_inform(info, 1);
	if (!interactive_mode(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_rtn);
}


/**
 * _find_builtin_cmd - Function finds a builtin command
 *			@info: the parameter
 * Return: If builtin not found -1,
 *	If builtin executed successfully 0,
 *	If builtin found but not  1,
 *	If builtin signals exit() 2
 */

int _find_builtin_cmd(info_t *info)
{
	int n;
	int builtin_rtn = -1;

	builtin_table builtintbl[] = {
		{"exit", my_exit},
		{"env", _my_envirn},
		{"help", _my_help},
		{"history", _my_hist},
		{"setenv", _my_set_envirn},
		{"unsetenv", _my_unset_envirn},
		{"cd", my_cd},
		{"alias", _my_alias},
		{NULL, NULL}
	};

	for (n = 0; builtintbl[n].type; n++)
	{
		if (_str_cmp_two(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_coutnt++;
			builtin_rtn = builtintbl[n].func(info);
			break;
		}
	}
	return (builtin_rtn);

}


/**
 * _find_cmd_p - Function finds a command in PATH
 * @info: The parameter & return info struct
 * Return: void
 */
void _find_cmd_p(info_t *info)
{
	char *pth = NULL;
	int n, m;

	info->pth = info->argv[0];
	if (info->line_cnt_flag == 1)
	{
		info->line_count++;
		info->line_cnt_flag = 0;
	}
	for (n = 0, m = 0; info->arg[n]; m++)
		if (!is_delimeter(info->arg[i], " \t\n"))
		m++;
	if (!m)
		return;

	path = find_cmd_path(info, _get_envirn(info, "PATH="), info->argv[0]);
	if (pth)
	{
		info->path = pth;
		fork_cmd_exec(info);
	}
	else
	{
		if ((interactive_mode(info) || _get_envirn(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd_ex(info, info->argv[0]))
		fork_cmd_exec(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			_print_errors(info, "not found\n");
		}
	}
}


/**
 * fork_cmd_exec - Function forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 * Return: void
 */
void fork_cmd_exec(info_t *info)
{
	pid_t chld_pd = fork();

	if (chld_pd == -1)
	{
		perror("Error:");
		return;
	}
	if (chld_pd == 0)
	{
		if (execve(info->path, info->argv, _gets_environ(info)) == -1)
		{
			_free_inform(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
			if (WIFEXITED(info->status))
			{
				info->status = WEXITSTATUS(info->status);
				if (info->status == 126)
				_print_errors(info, "Permission denied\n");
			}
	}

}
