#include "monty.h"

/**
 * push_error - handles push errors
 * @fd: file descriptor
 * @linebuf: buffer
 * @stack: stack or queue
 * @line_num: line number in file
 */
void push_error(FILE *fd, char *linebuf, stack_t **stack, int line_num)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
	fclose(fd);
	free(linebuf);
	free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * instruct_error - Handler for invalid instruction
 * @fd: file descriptor
 * @lin: buffer for lines
 * @stack: stack or queue
 * @args: ops code
 * @line: line number in file
 */
void instruct_error(FILE *fd, char *lin, stack_t *stack, char *args, int line)
{
	dprintf(STDERR_FILENO, "L%u:unknown instruction %s\n", line, args);
	fclose(fd);
	free(lin);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
