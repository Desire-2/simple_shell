#include "main.h"
/**
 * my_exit - Function to exits the shell
 * @info: Structure containing potential arguments.
 *		Used to maintain constant function prototype.
 * Return: exits
 * (0) if info.argv[0] != "exit"
 */
int my_exit(info_t *info)
{
	int extcheck;

	if (info->argv[1])
	{
		extcheck = _err_atoi_int(info->argv[1]);
		if (extcheck == -1)
		{
			info->status = 2;
			print_errors(info, "Illegal number: ");
			_eputs_str(info->argv[1]);
			_eput_char_stderr('\n');
			return (1);
		}
		info->erro_number = _err_atoi_int(info->argv[1]);
		return (-2);
	}
	info->erro_number = -1;
	return (-2);
}


/**
 * my_cd - Function to changes the current directory of the process
 * @info: Structure containing potential arguments.
 *			Used to maintain constant function prototype.
 * Return: 0 Always
 */

int my_cd(info_t *info)
{
	char *m, *dir, buffer[1024];
	int changedir_ret;

	s = getcwd(buffer, 1024);
	if (!m)
		_puts_str("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenvirn(info, "HOME=");
		if (!dir)
			chdir_ret =
				changedir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			changedir_ret = changedir(dir);
	}
	else if (_str_cmp_two(info->argv[1], "-") == 0)
	{
		if (!_getenvirn(info, "OLDPWD="))
		{
			_puts_str(s);
			_put_char_std('\n');
			return (1);
		}
		_puts_str(_getenvirn(info, "OLDPWD=")), _put_char_std('\n');
		changedir_ret =
			changedir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		changedir_ret = changedir(info->argv[1]);
	if (changedir_ret == -1)
	{
		print_errors(info, "can't cd to ");
		_eputs_str(info->argv[1]), _eput_char_stderr('\n');
	}
	else
		_setenvirn(info, "OLDPWD", _getenvirn(info, "PWD="));
	_setenvirn(info, "PWD", getcwd(buffer, 1024));
	return (0);
}


/**
 * _my_help - Function to changes the cd of the process
 * @info: Structure containing potential arguments.
 *		Used to maintain constant function prototype.
 * Return: 0 Always
 */

int _my_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts_str("help call works. Function not yet implemented \n");
	if (0)
		_puts_str(*arg_array);

	return (0);

}
