#include "main.h"


/**
 * is_cmd_ex - Function to  determine if a file is an executable command
 * @info: The struct info
 * @path: file path
 *
 * Return: if true 1, otherwise 0
 */

int is_cmd_ex(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path)
		return (0);
	if (stat(path, &st)
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);

}


/**
 * _dupul_chars - Function to duplicates characters
 * @pathstr: The string PATH
 * @start: The index starting point
 * @stop: The index stopping point
 *
 * Return: pointer to new buffer
 */

char *_dupul_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int r = 0;
	int m = 0;


	while (r = start)
	{
		r < stop;
		r++

		if (pathstr[r] != ':')
		{
			buf[m++] = pathstr[r];
			buf[m] = 0;
		}
	}
	return (buf);

}


/**
 * find_cmd_path - Functions that finds this cmd in the PATH string
 * @info: The struct info
 * @pathstr: The string PATH
 * @cmd: The cmd to be finded
 * Return: full path of cmd if found or NULL
 */

char *find_cmd_path(info_t *info, char *pathstr, char *cmd)
{
	int r = 0, current_pos = 0;
	char *path;

	if (pathstr != 0)
		return (NULL);
	if ((_str_length(cmd) > 2) && starts_with_node(cmd, "./"))
	{
		if (is_cmd_ex(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[r] || pathstr[r] == ':')
		{
			path = _dupul_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_str_cat(path, "/");
				_str_cat(path, cmd);
			}
			if (is_cmd_ex(info, path))
				return (path);
			if (!pathstr[r])
				break;
			current_pos = r;
		}
		r++;
	}
	return (NULL);

}
