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

#define CMD_NORM        0
#define CMD_OR                1
#define CMD_AND                2
#define CMD_CHAIN        3


#define CONVERT_LOWERCASE        1
#define CONVERT_UNSIGNED        2




#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE        ".simple_shell_history"
#define HIST_MAX        4096
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
extern char **environ;

/**
 * struct liststr - Singly linked list
 * @num: The number field
 * @str: String
 * @next: Points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;

} list_t;

/**
 * struct passinfo - Function Contains pseudo-arguements,
 * to be passed into another function,
 * allowing uniform prototype for function pointer struct
 * @arg: A string generated from getline containing arguements
 * @argv:An array of strings generated from arg
 * @path: A string path for the current command
 * @argc: The argument count
 * @line_count: The error count
 * @err_num: The error code for exit()s
 * @linecount_flag: If on count this line of input
 * @fname: The program filename
 * @env: Linked list local copy of environ
 * @environ: Custom modified copy of environ from LL env
 * @history: The history node
 * @alias: The alias node
 * @env_changed: On if environ was changed
 * @status: The return status of the last exec'd command
 * @cmd_buf: Address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: The fd from which to read line input
 * @histcount: The history line number count
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

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);

} builtin_table;



int _my_hist(info_t *info);
int  unset_alias_to_str(info_t *info, char *str);
int set_alias_str(info_t *info, char *str);
int print_alias_str(list_t *node);
int _my_alias(info_t *info);
int _unsetenvirn(info_t *info, char *var);
int _setenvirn(info_t *info, char *var, char *value);
int is_cmd_ex(info_t *info, char *path);
int _write_hist(info_t *info);
int _read_hist(info_t *info);
int _build_hist_l(info_t *info, char *buf, int linecount);
int _renumber_hist(info_t *info);
int delete_node_at_index_of(list_t **head, unsigned int index);
int _getline(info_t *info, char **ptr, size_t *length);
int _my_envirn(info_t *info);
int _my_set_envirn(info_t *info);
int populate_envnt_list(info_t *info);
int my_exit(info_t *info);
int my_cd(info_t *info);
int _my_help(info_t *info);
int main(int ac, char **av);
int _free_p_n(void **ptr);
int _eput_char_stderr(char c);
int _put_fld(char c, int fd);
int _puts_fld(char *str, int fd);
int _err_atoi_int(char *s);
int _print_dc(int input, int fd);
int _str_length(char *s);
int _str_cmp_two(char *s1, char *s2);
int _put_char_std(char c);
int shell_hsh(info_t *info, char **av);
int _find_builtin_cmd(info_t *info);
int interactive_mode(info_t *info);
int is_delimimeter(char c, char *delim);
int _isalphabet(int c);
int _atoi_int(char *s);
int is_char_chain(info_t *info, char *buf, size_t *p);
int rep_alias(info_t *info);
int rep_vars(info_t *info);
int rep_str(char **old, char *new);
int _my_unset_envirn(info_t *info);

char **_get_environ(info_t *info);
char *_str_m_cpy(char *dest, char *src, int n);
char *_str_m_cat(char *des, char *src, int n);
char *_str_char(char *s, char c);
char *_dupul_chars(char *pathstr, int start, int stop);
char *find_cmd_path(info_t *info, char *pathstr, char *cmd);
char *_get_hist_in_file(info_t *info);
char **_list_to_str(list_t *head);
char *_mem_set_cons(char *s, char b, unsigned int n);
char *_getenviron(info_t *info, const char *name);
char *_convert_nb(long int num, int base, int flags);
char *starts_with_node(const char *haystack, const char *needle);
char *_str_cat(char *dest, char *src);
char *_str_cpy(char *dest, char *src);
char *_str_duplicate(const char *str);
char **str_to_words(char *str, char *d);
char **str_to_word(char *str, char d);

ssize_t _input_buffer(info_t *info, char **buf, size_t *len);
ssize_t _get_inpt(info_t *info);
ssize_t _rd_buffer(info_t *info, char *buf, size_t *i);
ssize_t get_nd_index_on(list_t *head, list_t *node);
size_t prints_list_string(const list_t *h);
size_t _list_length_link(const list_t *h);size_t print_list_el_link(const list_t *h);


void sigintHandler(__attribute__((unused))int sig_num);
void _free_list_nds(list_t **head_ptr);
void _str_frees(char **pp);
void *_reallocate_bl(void *ptr, unsigned int old_size, unsigned int new_size);
void _eputs_str(char *str);
void _print_errors(info_t *info, char *estr);
void _clear_inform(info_t *info);
void _set_inform(info_t *info, char **av);
void _free_inform(info_t *info, int all);
void _rm_comment(char *buf);
void _puts_str(char *str);
void _find_cmd_p(info_t *info);
void fork_cmd_exec(info_t *info);
void check_chain_st(info_t *info, char *buf, size_t *p, size_t i, size_t len);


list_t *_add_node_start(list_t **head, const char *str, int num);
list_t *add_node_to_end(list_t **head, const char *str, int num);
list_t *_nd_starts_with_(list_t *node, char *prefix, char c);

#endif


