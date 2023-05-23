#include "main.h"

/**
 * _atoi - converts a string of digits to integers
 * @token: the string to be converted
 * Result: an integer value is returned
 */

int _atoi(char *token)
{
	int num = 0, result = 0, base = 10, sign = 1, index = 0;

	if (token[0] == '-')
	{
		sign = -1;
		index = 1;
	}
	while (token[index] != '\0')
	{
		if ((token[index] >= '0') || (token[index] <= '9'))
		{
			num = token[index] - '0';
			result = base * result;
			result += num;
		}
		index++;
	}
	result = result * sign;
	return (result);
}
