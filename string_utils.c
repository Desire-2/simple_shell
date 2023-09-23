#include "main.h"

/**
 * _hsh - The main shell loop
 * @info: parameter &and return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int _hsh(info_t *info, char **av)
{
	ssize_t s = 0;
	int builtin_retn = 0;

	while (s != -1 && builtin_retn != -2)
	{
		_clear_info(info);
		if (_interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		s = _get_input(info);
		if (s != -1)
		{
			_set_info(info, av);
			builtin_retn = _find_builtin(info);
			if (builtin_retn == -1)
				_find_cmd(info);
		}
		else if (_interactive(info))
			_putchar('\n');
		_free_info(info, 0);
	}
	_write_history(info);
	_free_info(info, 1);
	if (!_interactive(info) && info->status)
		exit(info->status);
	if (builtin_retn == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_retn);
}

/**
 * find_builtin - Function finds a builtin command
 * @info: Parameter & return info struct
 *
 * Return: -1 if builtin not found.
 * 0 if builtin executed successfully,
 * 1 if builtin found but not successful,
 * 2 if builtin signals exit()
 */
int _find_builtin(info_t *info)
{
	int r, built_in_retn = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (r = 0; builtintbl[r].type; r++)
		if (_strcmp(info->argv[0], builtintbl[r].type) == 0)
		{
			info->line_count++;
			built_in_retn = builtintbl[r].func(info);
			break;
		}
	return (built_in_retn);
}

/**
 * _find_cmd - Function finds a command in PATH
 * @info: Parameter & return info struct
 *
 * Return: void
 */
void _find_cmd(info_t *info)
{
	char *pth = NULL;
	int r, m;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (r = 0, m = 0; info->arg[r]; r++)
		if (!_is_delim(info->arg[r], " \t\n"))
			m++;
	if (!m)
		return;

	pth = _find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (pth)
	{
		info->path = pth;
		_fork_cmd(info);
	}
	else
	{
		if ((_interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && _is_cmd(info, info->argv[0]))
			_fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			_print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - Function tha forks a an exec thread to run cmd
 * @info: Parameter & return info struct
 * Return: void
 */
void _fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, _get_environ(info)) == -1)
		{
			_free_info(info, 1);
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
				_print_error(info, "Permission denied\n");
		}
	}
}
