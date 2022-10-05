#include "monty.h"

/**
 * main - Entry Point of Program.
 * Description: The Monty Program receives monty file and
 * interpretes it.
 * @argc: arguments count
 * @argv: arguments string
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, const char *argv[])
{
	int output;

	if (argc != 2)
	{
		dprintf(2,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	output = read_file(argv[1]);
	if (output == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);

}
