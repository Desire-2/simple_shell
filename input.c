#include "main.h"


/**
 * _input_buffer - Function of buffers chained commands
 * @info: Struct parameter
 * @buf: Buffer address
 * @len: len var address
 *
 * Return: ead bytes
 */
ssize_t _input_buffer(info_t *info, char **buf, size_t *len)
{
	ssize_t n;
	size_t length_p;

	n = 0;
	length_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigint_Handler_ctr);

#if USE_GETLINE
		n = _get_line(buf, &length_p, stdin);

#else
		r = _get_ln(info, buf, &length_p);

#endif
		if (n > 0)
		{
			if ((*buf)[n - 1] == '\n')
			{
				(*buf)[n - 1] = '\0';
				n--;
			}
			info->line_cnt_flag = 1;
			_rm_comments(*buf);
			_build_hist_l(info, *buf, info->histcount++);
				*len = n;
				info->cmd_buf = buf;
			}
		}
	return (n);
}

/**
 * _get_inpt - Function to get a line minus the newline
 * @info: Structparameter
 *
 * Return: bytes to be readed
 */
ssize_t _get_inpt(info_t *info)
{
	ssize_t r = 0;
	static char *buffer;
	char **buffer_p = &(info->arg), *p;
	static size_t n, w, length;

	_put_char_std(BUF_FLUSH);
	r = _input_buffer(info, &buffer, &length);
	if (r == -1)
		return (-1);
	if (length)
	{
		w = n;
		p = buffer + n;

		check_chain_st(info, buffer, &w, r, length);
		while (w < length)
		{
			if (is_char_chain(info, buffer, &w))
			break;
			w++;
		}
		n = w + 1;
		if (n >= length)
		{
			n = length = 0;
			info->cmd_buffer_type = CMD_NORM;
		}
		*buffer_p = p;
		return (_strlen(p));
	*buffer_p = buffer;
	return (r);
}

/**
 * _rd_buffer - Function to reads a buffer
 * @info: Struct parameter
 * @buf: Buffer
 * @i: Size
 *
 * Return: r
 */

ssize_t _rd_buffer(info_t *info, char *buf, size_t *i)
{
	ssize_t n = 0;

	if (*i)
		return (0);
	n = read(info->readfd, buf, READ_BUF_SIZE);
	if (n >= 0)
		*i = n;
	return (n);
}


/**
 * _get_ln - Function to get the next line of input from STDIN
 * @info: Struct parameter
 * @ptr: pointer to buffer address, preallocated or NULL
 * @length: .........
 *
 * Return: z
 */

int _get_ln(info_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t n, length;
	size_t k;
	ssize_t r = 0, z = 0;
	char *p = NULL;
	char *nw_p = NULL, *c;

	p = *ptr;
	if (p && length)
	sz = *length;

	if (n == lenngth)
	r = len = 0;
	r = read_buf(info, buffer, &length);

	if (r == -1)
		return (-1);
	if  (r == 0 && length == 0)
		return (-1);

	c = str_char(buffer + n, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : length;
	new_p = _realloc(p, z, z ? z + k : k + 1);
	if (!nw_p)
		return (p ? free(p), -1 : -1);

	if (z)
	_str_m_cat(nw_p, buffer + r, k - r);
	else
	_str_m_cpy(nw_p, buffer + r, k - r + 1);
	z += k - n;
	n = k;
	p = nw_p;

	if (length)
	*length = s;
	*ptr = p;
	return (z);

}


/**
 * sigint_Handler_ctrl - Function to blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */

void sigint_Handler_ctrl(__attribute__((unused))int sig_num)
{
	_puts_str("\n");
	_puts_str("$ ");
	_put_char_std(BUF_FLUSH);
}
