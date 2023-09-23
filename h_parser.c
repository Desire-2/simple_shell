#include "main.h"

/**
 * _is_cmd - Function determines if a file is an executable command
 * @info: info struct
 * @path: file path
 * Return: 1 if true, 0 otherwise
 */
int _is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Function thatduplicates characters
 * @pathstr: String PATH
 * @start: beginning of  index
 * @stop: ending of  index
 *
 * Return: pointer to new buffer
 */
char *_dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int r = 0, m = 0;

	for (m = 0, r = start; r < stop; r++)
		if (pathstr[r] != ':')
			buf[m++] = pathstr[r];
	buf[m] = 0;
	return (buf);
}

/**
 * _find_path - Function finds this cmd in the PATH string
 * @info: Info struct
 * @pathstr:  string PATH
 * @cmd: command to  be finded
 *
 * Return: full path of cmd if found or NULL
 */
char *_find_path(info_t *info, char *pathstr, char *cmd)
{
	int r = 0, curr_position = 0;
	char *pth;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && _starts_with(cmd, "./"))
	{
		if (_is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[r] || pathstr[r] == ':')
		{
			pth = _dup_chars(pathstr, curr_position, r);
			if (!*pth)
				_strcat(pth, cmd);
			else
			{
				_strcat(pth, "/");
				_strcat(pth, cmd);
			}
			if (_is_cmd(info, pth))
				return (pth);
			if (!pathstr[r])
				break;
			curr_position = r;
		}
		r++;
	}
	return (NULL);
}
