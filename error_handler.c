#include "monty.h"

/**
 * push_error - handles push errors
 * @fd: file descriptor
 * @linebuf: buffer
 * @stack: stack or queue
 * @line_num: line number in file
 */
void push_error(FILE *fd, char *linebuf, stack_t *stack, int line_num)
{
	dprintf(STDERR_FILENO,"L%u: usage: push integer\n", line_num);
	fclose(fd);
	free(linebuf);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * instruct_error - Handler for invalid instruction
 * @fd: file descriptor
 * @linebuf: buffer for lines
 * @stack: stack or queue
 * @item: ops code
 * @line_num: line number in file
 */
void instruct_error(FILE *fd,char *linebuf,stack_t *stack,char *item,int line_num)
{
	dprintf(STDERR_FILENO,"L%u:unknown instruction %s\n",line_num,item);
	fclose(fd);
	free(linebuf);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
