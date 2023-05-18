#include "helper_func.h"
/**
 * main - This is the shell entry
 * @ac: argument count from command line
 * @av: array of strings created by OS
 *
 * Return: returns 0
 */
int main(int ac, char **av)
{
	(void)ac;
	char prompt[] = "SBush$ ";
	ssize_t nread;
	char *buff = NULL, *token;
	size_t num = 0, i = 0;
	char **instruct;
	pid_t c_pid;
	int check;

	while (1)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt));
		nread = getline(&buff, &num, stdin);
		if (nread < 0)
		{
			exit(0);
		}
		instruct = string_split(buff, " ", nread);
		if (check_cmd(instruct[0], instruct, av[0]) == -1)
			continue;

		else
		{
			c_pid = fork();
			if (c_pid == -1)
			{
				perror("Error");
			} else if (c_pid == 0)
			{
				(child(instruct[0], instruct, environ));
				perror(instruct[0]);
			} else
				wait(&check);
			
			free(instruct);
		}	
		free(buff);


	}
	exit(0);
}
