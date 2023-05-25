#include "helper_func.h"
/**
 * main - This is the shell entry
 * @ac: argument count from command line
 * @av: array of strings created by OS
 *
 * Return: returns 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	ssize_t nread, i;
	char buff[BUFFSIZE];
	size_t num = 0;
	char *instruct[INSTSIZE];

	for (i = 0; i < INSTSIZE; i++)
		instruct[i] = NULL;

	signal(SIGINT, sig_handle);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		nread = _getline(buff, &num, STDIN_FILENO);
		if (nread == 1 && buff[0] == '\n')
			continue;
		if (nread <= 0)
			exit(0);

		if (cdry(buff) == 0)
			continue;

		string_split(buff, " ", nread, instruct);
		if (str_cmp(instruct[0], "exit") == 0)
			exit_msg(av[0], instruct);

		if (check_cmd(instruct, av[0]) == -1)
			continue;
		else
			start_child(instruct);
		_free(instruct);
	}
	exit(0);
}
