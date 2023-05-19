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
		hm = getenv("HOME");
		if (chdir(hm) < 0)
		{
			perror("chdir");
			return (-1);
		}
		return (0);
	}
	else if (cmds[0] == 'c' && cmds[1] == 'd' && cmds[2] == ' ')
	{
		for (i = 0; cmds[i] != '\0';)
			i++;
		cmds[i - 1] = '\0';
		str_cpy(fileptr, (cmds + 3));
		printf("%s\n ", fileptr);
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
 *
 * Return: pointer to the value of the variable
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token, *dupe;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0)
	{
		dupe = strdup(environ[i]);
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
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	for (int i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}