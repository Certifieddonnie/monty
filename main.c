#include "monty.h"
#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>

glob_t global = {NULL, NULL, NULL};

/**
 * main - Entry Point of Program.
 * Description: The Monty Program receives monty file and
 * interpretes it.
 * @argc: arguments count
 * @argv: arguments string
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1]);

	exit(EXIT_SUCCESS);

}
