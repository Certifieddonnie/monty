#include "monty.h"

/**
 * swap_ops - Swaps the top two elements of the stack
 * @stack: Head node
 * @line_num: Line number of the file
 * Return: nothing
 */
void swap_ops(stack_t **stack, unsigned int line_num)
{
	stack_t *current;
	int nodes = 0, temp;

	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
		nodes++;
	}
	if (nodes < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_num);
		fclose(global.fd);
		free(global.linebuf);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		current = *stack;
		temp = current->n;
		current->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}

}

/**
 * add_ops - adds the top two elements of the stack
 * @stack: Head node
 * @line_num: line number in file
 * Return: nothing
 */
void add_ops(stack_t **stack, unsigned int line_num)
{
	stack_t *current;
	int nodes = 0, temp, sum;

	current = *stack;
	while (current)
	{
		current = current->next;
		nodes++;
	}
	if (nodes < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_num);
		fclose(global.fd);
		free(global.linebuf);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		current = *stack;
		temp = current->n;
		sum = temp + (*stack)->next->n;
		(*stack) = (*stack)->next;
		(*stack)->n = sum;
		free(current);
	}
}

/**
 * nop_ops - doesn't do anything
 * @stack: head node
 * @line_num: line number in a file
 * Return: nothing
 */
void nop_ops(stack_t **stack, unsigned int line_num)
{
	(void)*stack;
	(void)line_num;
}
