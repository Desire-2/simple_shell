#include "main.h"

/**
 * main - The main entry point of the program
 * @ac: argument count count
 * @av: argurment vector vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fild = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fild)
			: "r" (fild));

	if (ac == 2)
	{
		fild = open(av[1], O_RDONLY);
		if (fild == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fild;
	}
	_populate_env_list(info);
	_read_history(info);
	_hsh(info, av);
	return (EXIT_SUCCESS);
}
