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
