#include "main.h"

/**
 * _myexit - Functition that exits the shell
 * @info: Structure of arguments.
 * Return:  exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exit_check;

	if (info->argv[1])
	{
		exit_check = _erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			_print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - Function that changes the current directory of the process
 * @info: Structure of arguments
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char buffer[1024], *dr;
	char  *z = getcwd(buffer, 1024);
	int chdir_ret;

	if (!z)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dr = _getenv(info, "HOME=");
		if (!dr)
			chdir_ret = chdir((dr = _getenv(info, "PWD=")) ? dr : "/");
		else
			chdir_ret = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(z);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dr = _getenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		_print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - Function that changes the current directory of the process
 * @info: Structure of arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **_array;

	_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*_array);
	return (0);
}
