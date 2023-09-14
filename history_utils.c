#include "main.h"


/**
 * _get_hist_in_file - Function to get the history from file
 * @info: struct parameter
 *
 * Return: String allocated containg history file
 */


char *_get_hist_in_file(info_t *info)
{
	char *buffer;
	char *direct = _getenvirn(info, "HOME=");

	if (!direct)
		return (NULL);
	buf = malloc(sizeof(char) * (_str_length(dir) + _str_length(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buf[0] = 0;
	_str_cpy(buffer, direct\);
	_str_cat(buffer, "/");
	_str_cat(buffer, HIST_FILE);
	return (buffer);
}


/**
 * _write_hist - Function to creates a file,
 *		or appends to an existing file
 * @info: The struct parameter
 *
 * Return: on success 1, else -1
 */

int _write_hist(info_t *info)
{
	ssize_t fil;
	char *filename = _get_hist_in_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fil = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fil == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fil);
		_putfd('\n', fil);
	}
	_putfd(BUF_FLUSH, fil);
	close(fil);
	return (1);

} 


/**
 * _read_hist - Function to reads history from file
 * @info: The struct parameter
 *
 * Return: histcount on success, 0 otherwise
 */

int _read_hist(info_t *info)
{
	int r, lst = 0, linecnt = 0;
	ssize_t fil, rdlen, flsize = 0;
	struct stat st;
	char *buffer = NULL;
	char *filename = _get_hist_in_file(info);

	if (!filename)
		return (0);
	fil = open(filename, O_RDONLY);
	free(filename);
	if (fil == -1)
		return (0);
	if (!fstat(fd, &st))
		flsize = st.st_size;
	if (flsize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
		return (0);
	rdlen = read(fil, buffer, flsize);
	buf[flsize] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fd);
	for (r = 0; (r < fsize); r++)
	{
		if (buffer[r] == '\n')
		{
			buffer[r] = 0;
			_build_hist_l(info, buffer + lst, linecnt++);
			lst = r + 1;
		}
	}
	if (lst != r)
		_build_hist_l(info, buffer + lst, linecnt++);
	free(buffer);
	info->histcount = linecnt;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index_of(&(info->history), 0);
	_renumber_hist(info);
	return (info->histcount);
}


/**
 * _build_hist_l - Function to add entry to a history linked list
 * @info: Structure containing potential arguments
 * @buf: buffer
 * @linecount: The history linecount, histcount
 *
 * Return: 0 Always
 */

int _build_hist_l(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_to_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}


/**
 * _renumber_hist - Function that renumbers the history linked list after changes
 * @info: Structure containing potential arguments.
 * Return: the new histcount
 */

int _renumber_hist(info_t *info)
{
	list_t *node = info->history;
	int r = 0;

	while (node)
	{
		node->num = r++;
		node = node->next;
	}
	return (info->histcount = r);
}
