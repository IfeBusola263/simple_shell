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
	int i;

	if (sizeof(des) >= str_len(src))
	{
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
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
		perror("memory could not be allocated");
		return (NULL);
	}
	for (i = 0; s[i] != '\0'; i++)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
