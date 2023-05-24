#include "helper_func.h"
/**
 * prompt - displays shell prompt to screen
 *
 * Return: nothing
 */
void prompt(void)
{
	char prompt[] = "SBush$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt));
	fflush(stdout);
}
/**
 * cdry - changes directory when called
 * @cmds: the string
 *
 * Return: returns nothing
 */
int cdry(char *cmds)
{
	int i;
	char *hm, fileptr[50];

	if (cmds[0] == 'c' && cmds[1] == 'd' && cmds[2] == '\n')
	{
		hm = _getenv("HOME", fileptr);
		if (chdir(hm) < 0)
		{
			perror("chdir");
			return (-1);
		}
		/* free(hm); */
		return (0);
	}
	else if (cmds[0] == 'c' && cmds[1] == 'd' && cmds[2] == ' ')
	{
		for (i = 0; cmds[i] != '\0';)
			i++;
		cmds[i - 1] = '\0';
		str_cpy(fileptr, (cmds + 3));
		if (chdir(fileptr) < 0)
		{
			perror("chdir");
			return (-1);
		}
		return (0);
	}
	return (-1);
}

/**
 * _getenv - gets specific environment variable
 * @name: variable name in the environment
 * @dupe: copy of environment variable with the value
 *
 * Return: pointer to the value of the variable
 */
char *_getenv(char *name, char *dupe)
{
	int i = 0;
	char *token;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, str_len(name)) == 0)
		{
			str_cpy(dupe, environ[i]);
			dupe[str_len(dupe)] = '\0';
			token = strtok(dupe, "=");
			token = strtok(NULL, "=");
			return (token);
		}
		i++;
	}
	return (NULL);
}

/**
 * _strncmp - compares two string
 * @str1: first string to be compared
 * @str2: second string to be compared
 * @n: number index
 *
 * Return: 0 or -1
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	size_t i = 0;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}
/**
 * a_toi - converts integar represented string to integar
 * @str: string to be converted
 *
 * Return: on success, integar equivalent else 0
 */
int a_toi(char *str)
{
	int ret = 0;
	int sgn = 1;

	if (str != NULL)
	{
		while (*str == ' ')/* Check for space */
			str++;

		if (*str == '+')	/* Check for signs */
			str++;
		else if (*str == '-')
		{
			sgn = -1;
			str++;
		}

		/* convert char to int */
		while (*str)
		{
			if (*str >= '0' && *str <= '9')
			{
				ret = (ret * 10) + (*str - '0');
				str++;
			} else
			{
				perror("atoi");
				return (0);
			}
		}
		return (sgn * ret);
	}
	return (0);
}
