#include "helper_func.h"
/**
 * string_split - sets strings to tokens
 * @str: string to be worked on
 * @sep: the delimiter that seperates strings
 * @len: length of string
 * @instruct: array to populate
 *
 * Return: an array of strings
 */

void string_split(char *str, char *sep, ssize_t len, char **instruct)
{
	ssize_t j = 0;
	/* size_t numWords = 0; */
	/* char **instruct = NULL; */
	char *token = NULL;
	int ex = 0;

	if (str[len - 1] == '\n') /* get rid of newline char */
		str[len - 1] = '\0';

	token = strtok(str, sep);
	while (token != NULL)
	{
		instruct[j] = str_dup(token); /* copy string to array of strings */
		token = strtok(NULL, sep);
		j++;
	}
	/*instruct[j] = NULL;*/
	if (str_cmp(instruct[0], "exit") == 0)
	{
		ex = a_toi(instruct[1]);
		 _free(instruct);
		exit(ex);
	}
	/* return (instruct); */
}

/**
 * check_cmd - checks if a command exists or not
 * @cmds: command argument
 *
 * Return: nothing
 */
int check_cmd(char **cmds)
{
	int check;
	char *cmd_route, *token, *dpath = NULL, dupe[BUFFSIZE];

	if (str_cmp(cmds[0], "env") == 0)
	{
		print_en();
		_free(cmds);
		return (-1);
	}

	check = access(cmds[0], X_OK);
	if (check == 0)
		return (check);

	dpath = _getenv("PATH", dupe);
	token = strtok(dpath, ":");

	while (token != NULL)
	{
		cmd_route = malloc(sizeof(char) * 100);
		if (cmd_route == NULL)
			return (-1);
		str_cpy(cmd_route, token);
		_strcat(cmd_route, "/");
		_strcat(cmd_route, cmds[0]);

		check = access(cmd_route, X_OK);
		if (check == 0)
		{
			cmds[0] = cmd_route;
			return (0);
		}
		free(cmd_route);
		token = strtok(NULL, ":");
	}
	perror(cmds[0]);
	return (check);
}

/**
 * _strcat - concatenate two strings
 * @dest: first string
 * @src: second string
 *
 * Return:destination
 */
char *_strcat(char *dest, char *src)
{
	size_t i = 0;
	size_t j = 0;

	if (dest != NULL && src != NULL)
	{
		while (dest[i] != '\0')
			i++;
		while (src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
/**
 * numstr - counts the number of words in a string
 *
 * @str: string to be checked
 * @sep: delimiter in the string
 *
 * Return: num strings including null terminator
 */
size_t numstr(char *str, char sep)
{
	int i = 0;
	int count = 0;

	if (str != NULL)
	{
		for (i = 0; str[i]; i++)
		{
			if (str[i] == sep)
				count++;
		}
		if (count > 0)
			return (count + 1);
		return (1);
	}
	return (0);
}
