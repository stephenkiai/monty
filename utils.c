#include "monty.h"
/**
 * is_integer - Checks if a string represents an integer.
 * @str: The string to check.
 *
 * Return: 1 if the string represents an integer, 0 otherwise.
 *
 * Description: This function checks if a string represents a valid integer.
 *              verifies if string is not empty and consists of digits
 *              only, with an optional sign (+/-) at the beginning.
 */
int is_integer(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[0] == '-' || str[0] == '+')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
