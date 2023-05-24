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
		ptr++;
	}
}

