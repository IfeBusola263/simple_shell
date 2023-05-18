#include "helper_func.h"
/**
 * string_split - sets strings to tokens
 * @str: string to be worked on
 * @sep: the delimiter that seperates strings
 *
 * Return: an arra of strings
 */

char **string_split(char *str, char *sep, ssize_t len)
{
	ssize_t i, j = 0;
	size_t numWords = 0;
	char **instruct;
	char *token;
	
	if (str[len - 1]== '\n') /* Null terminate string from getline */
		str[len - 1] = '\0';

	for (i = 0; str[i]; i++) /* Number of words in string */
	{
		if (str[i]== ' ')
			numWords++;
	}
	numWords = numWords + 2;
	
	/* memory for array of strings */
	instruct = malloc(sizeof(char *) * numWords);
	if (instruct == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(str, " ");
	while (token != NULL)
	{
		instruct[j] = token; /* copy string to array of strings */
		token = strtok(NULL, " ");
		j++;
	}
	instruct[j] = NULL;
	if (str_cmp(instruct[0],"exit") == 0)
	{
		free(instruct);
		exit(98);
	}
	return (instruct);
}

/**
 * check_cmd - checks if a command exists or not
 * @instruct: the command to be checked
 *
 * Return: nothing
 */
int check_cmd(char *instruct, char **cmds, char *prognm)
{
	int check;
	
	if (str_cmp(instruct, "env") == 0)
	{
		print_en();
		return (-1);
	}

	check = access(instruct, X_OK);
	if (check == -1)
	{
		perror(prognm);
		free(cmds);
		return (check);
	}
	return (check);
}

