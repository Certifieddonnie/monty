#include "monty.h"

/**
 * read_file - Function that reads the file coming in.
 * @argv: file
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
void read_file(char *argv)
{
	int line = 0, res = 0;
	size_t bufsize = 0;
	char *args = NULL;
	stack_t *stack = NULL;

	global.fd = fopen(argv, "r");
	if (global.fd)
	{
		while (getline(&global.linebuf, &bufsize, global.fd) != -1)
		{
			line++;
			args = strtok(global.linebuf, " \n\t");
			if (args == NULL)
			{
				free(args);
				continue;
			}
			else if (*args == '#')
				continue;
			global.item = strtok(NULL, " \n\t");
			res = operation(&stack, args, line);
			if (res == 2)
				instruct_error(global.fd, global.linebuf, stack, args, line);
		}
		free(global.linebuf);
		free_dlistint(stack);
		fclose(global.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}

/**
 * operation - Function to handle the ops_code
 * @stack: stack or queue
 * @args: arguments token
 * @line_num: line number in file
 * Return: 1, 2, or 0(success)
 */
int operation(stack_t **stack, char *args, int line_num)
{
	int i;
	instruction_t op[] = {
		{"push", push_ops},
		{"pall", pall_ops},
		{"pint", pint_ops},
		{"pop", pop_ops},
		{"swap", swap_ops},
		{"add", add_ops},
		{"nop", nop_ops},
		{NULL, NULL}
	};

	i = 0;
	while (op[i].opcode && args)
	{
		if (strcmp(args, op[i].opcode) == 0)
		{
			op[i].f(stack, (unsigned int)line_num);
			break;
		}
		i++;
	}
	if (args && op[i].opcode == NULL)
		return (2);

	return (0);
}
