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
	/* char *buff = NULL; */
	char buff[BUFFSIZE];
	size_t num = 0;
	char *instruct[INSTSIZE];

	for (i = 0; i < INSTSIZE; i++)
		instruct[i] = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		/* nread = getline(&buff, &num, stdin); */
		nread = _getline(buff, &num, STDIN_FILENO);
		if (nread == 1 && buff[0] == '\n')
			continue;
		if (nread <= 0)
			exit(0);

		if (cdry(buff) == 0)
			continue;

		/* instruct = string_split(buff, " ", nread); */
		string_split(buff, " ", nread, instruct);
		if (check_cmd(instruct) == -1)
			continue;
		else
		{
			start_child(instruct);
			/* _free(instruct); */
		}
		_free(instruct);
	}
	exit(0);
}
