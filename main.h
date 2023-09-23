
#ifndef _MAIN_H_

#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - Singly linked list
 * @num: The number of  field
 * @str: string
 * @next: Pointer to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Function that contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: String generated from getline containing arguements
 * @argv: Array of strings generated from arg
 * @path: String path for the current command
 * @argc: The argument count
 * @line_count: Error count
 * @err_num: Error code for exit()s
 * @linecount_flag: If on count this line of input
 * @fname: Program filename
 * @env: Linked list local copy of environ
 * @environ: Custom modified copy of environ from LL env
 * @history:  History node
 * @alias: Aias node
 * @env_changed:  Environ was changed
 * @status: Return status of the last exec'd command
 * @cmd_buf: Address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: file descriptor from which to read line input
 * @histcount: History line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - Funcs contains a builtin string and related function
 * @type: Builtin command flag
 * @func: Function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


int _hsh(info_t *, char **);
int _find_builtin(info_t *);
int _is_cmd(info_t *, char *);
int _loophsh(char **);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
int _interactive(info_t *);
int _is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _putchar(char);
int bfree(void **);
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);
int _write_history(info_t *info);
int _read_history(info_t *info);
int _build_history_list(info_t *info, char *buf, int linecount);
int _renumber_history(info_t *info);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int _populate_env_list(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
int _replace_alias(info_t *);
int _replace_vars(info_t *);
int _replace_string(char **, char *);
int _erratoi(char *);
int _myhistory(info_t *);
int _myalias(info_t *);
int _is_chain(info_t *, char *, size_t *);
int _print_d(int, int);
int _getline(info_t *, char **, size_t *);
int _delete_node_at_index(list_t **, unsigned int);

char *_dup_chars(char *, int, int);
char *_find_path(info_t *, char *, char *);
char *_starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **_strtow(char *, char *);
char **_strtow2(char *, char);
char *_memset(char *, char, unsigned int);
char *_get_history_file(info_t *info);
char *_convert_number(long int, int, int);
char *_getenv(info_t *, const char *);
char **_get_environ(info_t *);
char **_list_to_strings(list_t *);


void _eputs(char *);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
void _puts(char *);
void _find_cmd(info_t *);
void _fork_cmd(info_t *);
void _clear_info(info_t *);
void _set_info(info_t *, char **);
void _free_info(info_t *, int);
void _print_error(info_t *, char *);
void _remove_comments(char *);
void sigintHandler(int);
void _check_chain(info_t *, char *, size_t *, size_t, size_t);
void _free_list(list_t **);


ssize_t _get_input(info_t *);
size_t _list_len(const list_t *);
size_t _print_list(const list_t *);
ssize_t _get_node_index(list_t *, list_t *);
size_t _print_list_str(const list_t *);

list_t *_add_node(list_t **, const char *, int);
list_t *_add_node_end(list_t **, const char *, int);
list_t *_node_starts_with(list_t *, char *, char);



#endif
