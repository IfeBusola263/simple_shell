#include "helper_func.h"
/**
 * sig_handle - handle signals
 * @sig: void input
 *
 * Return: return nothing
 */
void sig_handle(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 2);
	prompt();
}

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
/**
 * _setenv - manipulates environment variable
 * @var: variable name
 * @val: value held by variable
 *
 * Return: returns an integer
 */
int _setenv(char *var, char *val)
{
	int i, j, len;
	char *newEnv[100];
	char *newVar;

	if (var != NULL && val != NULL)
	{
		for (i = 0; i < 100; i++)
			newEnv[i] = NULL;

		for (j = 0; environ[j]; j++)
		{
			newEnv[j] = str_dup(environ[j]);
			if (newEnv[j] == NULL)
				return (-1);
		}
		len = str_len(var) + str_len(val);
		newVar = malloc(sizeof(char) * (len + 1));
		if (newVar == NULL)
			return (-1);

		str_cpy(newVar, var);
		_strcat(newVar, "=");
		_strcat(newVar, val);
		newVar[len + 1] = '\0';

		newEnv[j] = newVar;
		environ = newEnv;

		return (0);
	}
	return (-1);
}
