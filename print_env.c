#include "helper_func.h"
/**
 * print_en - printd the prsent working environment
 *
 * Return: always 0
 */

int print_en(void)
{
	int i = 0;
	char buff[] = "\n";

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], str_len(environ[i]));
		write(STDOUT_FILENO, buff, 1);
		i++;
	}

	return (0);
}
