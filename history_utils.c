#include "main.h"

/**
 * _get_history_file - Fnction that gets the history file
 * @info: struct parameter
 *
 * Return: allocated string containg history file
 */

char *_get_history_file(info_t *info)
{
	char *buffer, *dr;

	dr = _getenv(info, "HOME=");
	if (!dr)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, dr);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE);
	return (buffer);
}

/**
 * _write_history - Function that creates a file, or appends to an existing file
 * @info: The struct parameter
 *
 * Return: 1 on success, else -1
 */
int _write_history(info_t *info)
{
	ssize_t fild;
	char *filename = _get_history_file(info);
	list_t *nd = NULL;

	if (!filename)
		return (-1);

	fild = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fild == -1)
		return (-1);
	for (nd = info->history; nd; nd = nd->next)
	{
		_putsfd(nd->str, fild);
		_putfd('\n', fild);
	}
	_putfd(BUF_FLUSH, fild);
	close(fild);
	return (1);
}

/**
 * _read_history - Function  reads history from file
 * @info: Struct parameter
 *
 * Return: histcount on success, 0 otherwise
 */
int _read_history(info_t *info)
{
	ssize_t fild, rdlen, fsize = 0;
	int r, last = 0, linecount = 0;
	struct stat st;
	char *buffer= NULL, *filename = _get_history_file(info);

	if (!filename)
		return (0);

	fild = open(filename, O_RDONLY);
	free(filename);
	if (fild == -1)
		return (0);
	if (!fstat(fild, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
		return (0);
	rdlen = read(fild, buffer, fsize);
	buffer[fsize] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fild);
	for (r = 0; r < fsize; r++)
		if (buffer[r] == '\n')
		{
			buffer[r] = 0;
			_build_history_list(info, buffer + last, linecount++);
			last = r + 1;
		}
	if (last != r)
		_build_history_list(info, buffer + last, linecount++);
	free(buffer);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		_delete_node_at_index(&(info->history), 0);
	_renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int _build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *nd = NULL;

	if (info->history)
		nd = info->history;
	_add_node_end(&nd, buf, linecount);

	if (!info->history)
		info->history = nd;
	return (0);
}

/**
 * _renumber_history - Function renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int _renumber_history(info_t *info)
{
	list_t *nd = info->history;
	int r = 0;

	while (nd)
	{
		nd->num = r++;
		nd = nd->next;
	}
	return (info->histcount = r);
}
