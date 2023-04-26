#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @l: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *l, va_list list)
{
	int curr_l = *l + 1;
	int precision = -1;

	if (format[curr_l] != '.')
		return (precision);

	precision = 0;

	for (curr_l += 1; format[curr_l] != '\0'; curr_l++)
	{
		if (is_digit(format[curr_l]))
		{
			precision *= 10;
			precision += format[curr_l] - '0';
		}
		else if (format[curr_l] == '*')
		{
			curr_l++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*l = curr_l - 1;

	return (precision);
}
