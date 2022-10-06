#include "monty.h"
/**
 * is_digit - Checks for a digit 0 through 9
 * @c: character
 * Return: 0 or 1
 */
int is_digit(char *c)
{
	char *k = c;

	if(c == NULL)
		return(0);
	if(*k == '-')
		k++;

	for(;*k != '\0';k++)
	{
		if((*k < '0' || *k > '9'))
			return(0);
	}
	return(1);
}
