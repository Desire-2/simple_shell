#include "main.h"


/**
 * main - The main entry point of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: on success 0 , on error 1
 */



int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fild = 2;

	asm (
			"mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fild)
			: "r" (fild)
			);

	if (ac == 2)
	{
		fild = open(av[1], O_RDONLY);
		if (fild == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs_str(av[0]);
				_eputs_str(": 0: Can't open ");
				_eputs_str(av[1]);
				_eputs_str(": No such file or directory\n");
				_eput_char_stderr(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fild;
	}
	populate_envnt_list(info);
	_read_hist(info);
	shell_hsh(info, av);
	return (EXIT_SUCCESS);
}


