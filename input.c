#include "main.h"

/**
 * _input_buf - Function buffers chained commands
 * @info:  struct parameter
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t _input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t n = 0;
	size_t _len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		n = getline(buf, &len_p, stdin);
#else
		n = _getline(info, buf, &_len_p);
#endif
		if (n > 0)
		{
			if ((*buf)[n - 1] == '\n')
			{
				(*buf)[n - 1] = '\0';
				n--;
			}
			info->linecount_flag = 1;
			_remove_comments(*buf);
			_build_history_list(info, *buf, info->histcount++);
			{
				*len = n;
				info->cmd_buf = buf;
			}
		}
	}
	return (n);
}

/**
 * _get_input - Function gets a line minus the newline
 * @info: struct parameter
 *
 * Return: bytes read
 */
ssize_t _get_input(info_t *info)
{
	static char *buffer;
	static size_t i, w, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = _input_buf(info, &buffer, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		w = i;
		p = buffer +i;
	_check_chain(info, buffer, &w, i, len);
		while (w < len)
		{
			if (_is_chain(info, buffer, &w))
				break;
			w++;
		}

		i = w + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buffer;
	return (r);
}

/**
 * _read_buf - Function  reads a buffer
 * @info: struct parameter
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t _read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t s = 0;

	if (*i)
		return (0);
	s = read(info->readfd, buf, READ_BUF_SIZE);
	if (s >= 0)
		*i = s;
	return (s);
}

/**
 * _getline - Function that gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	ssize_t r = 0, s = 0;
	char *w = NULL, *nw_p = NULL, *c;
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	

	w = *ptr;
	if (w && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = _read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	nw_p = _realloc(w, s, s ? s + k : k + 1);
	if (!nw_p)
		return (w ? free(w), -1 : -1);

	if (s)
		_strncat(nw_p, buf + i, k - i);
	else
		_strncpy(nw_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	w = nw_p;

	if (length)
		*length = s;
	*ptr = w;
	return (s);
}

/**
 * sigintHandler - Function that blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
