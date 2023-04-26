#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @l: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *l)
{
	int curr_l = *l + 1;
	int size = 0;

	if (format[curr_l] == 'l')
		size = S_LONG;
	else if (format[curr_l] == 'h')
		size = S_SHORT;

	if (size == 0)
		*l = curr_l - 1;
	else
		*l = curr_l;

	return (size);
}
