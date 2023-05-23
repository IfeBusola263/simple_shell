#include <stdlib.h>
#include <unistd.h>
#include "helper_func.h"
/**
 * str_len - a function that gets the string length
 * @s: string
 *
 * Return: size_t integer value
 */
size_t str_len(char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0';)
		i++;
	return (i);
}
/**
 * str_cpy - gets string copy
 * @des: destination buffer
 * @src: source string to be copied
 *
 * Return: pointer to destination buffer
 */
char *str_cpy(char *des, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
	return (des);
}

/**
 * str_dup - gets string duplicate
 * @s: string
 *
 * Return: on success pointer to a duplicate string
 */
char *str_dup(char *s)
{
	int i;
	char *dup;

	if (s == NULL)
		return (NULL);

	dup = malloc(sizeof(char) * str_len(s) + 1);
	if (dup == NULL)
	{
		write(STDERR_FILENO, "memory could not be allocated", 29);
		return (NULL);
	}
	for (i = 0; s[i] != '\0'; i++)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
/**
 * _getline - reads string from file to a file descriptor
 * @num: number of bytes to be read
 * @fildes: file descriptor
 * @buff: array of chars
 *
 * Return: number of read characters
 */
ssize_t _getline(char *buff, size_t *num, int fildes)
{
	ssize_t numRead;

	while (1)
	{
		numRead = read(fildes, buff, BUFFSIZE);
		if (numRead == -1)
			return (-1);
		else if (numRead == 0)
			break;
		if (*(buff + numRead - 1) == '\n')
		{
			*num = numRead;
			*(buff + numRead) = '\0';
			break;
		}
	}
	return (numRead);
}

/**
 * str_cmp - compares two strings
 * @s1: pointer to string
 * @s2: pointer to second string
 *
 * Return: returns an Int
 */
int str_cmp(char *s1, char *s2)
{
	int cmp;

	cmp = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[cmp] != '\0' && s2[cmp] != '\0')
		{
			if (s1[cmp] != s2[cmp])
			{
				return (s1[cmp] - s2[cmp]);
			}
			cmp++;
		}
		return (0);
	}
	return (-1);
}
