#include "helper_func.h"

/**
 * _free - frees malloc'ed memory
 * @ptr: pointer to the memory
 *
 * Return: nothing
 */

void _free(char **ptr)
{
	if (ptr == NULL)
		return;

	while (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		ptr++;
	}
}

/**
 * exit_msg - prints exit message
 * @progmn: program name
 * @cmdname: command name
 *
 * Return: returns nothing
 */
void exit_msg(char *progmn, char **cmdname)
{
	int ex = 0;
	char excode[5];

	if (cmdname[1] == NULL)
	{
		_free(cmdname);
		exit(ex);
	}
	str_cpy(excode, cmdname[1]);
	ex = a_toi(excode);
	if (ex < 0)
	{
		write(STDOUT_FILENO, progmn, str_len(progmn));
		write(STDOUT_FILENO, ": ", 3);
		write(STDOUT_FILENO, cmdname[0], str_len(cmdname[0]));
		write(STDOUT_FILENO, ": ", 3);
		write(STDOUT_FILENO, "illegal Number", 14);
		write(STDOUT_FILENO, ": ", 3);
		write(STDOUT_FILENO, cmdname[1], str_len(cmdname[1]));
		ex = 0;
	}
	_free(cmdname);
	exit(ex);
}
