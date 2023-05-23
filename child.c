#include "helper_func.h"
/**
 * child - executes child process
 * @route: command name
 * @args: command arguments
 * @ens: the enviroment
 *
 * Return: return nothing
 */
void child(char *route, char *args[], char **ens)
{
	execve(route, args, ens);
	perror("Could not execute");
}
/**
 * start_child - initiates child process
 * @instruct: array with command and path
 *
 * Return: nothing
 */
void start_child(char **instruct)
{
	pid_t c_pid;
	int check;

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
}
