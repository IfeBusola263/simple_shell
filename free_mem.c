#include "helper_func.h"

/**
 * _free - frees malloc'ed memory
 * @ptr: pointer to the memory
 *
 * Return: nothing
 */

void _free(char **ptr)
{
	char **tmp;

	if (ptr == NULL)
		return;

	tmp = ptr;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tmp);
}

