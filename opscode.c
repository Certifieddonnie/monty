#include "monty.h"

/**
 * push_ops - pushes data into stack
 * @stack: stack
 * @line_num: line number in file
 */
void push_ops(stack_t **stack, unsigned int line_num)
{
	stack_t *newnode;
	int i;

	if (is_digit(global.item) == 1)
		i = atoi(global.item);
	else
		push_error(global.fd, global.linebuf, stack, line_num);

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = i;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 * pall_ops - Prints all elements in stack
 * @stack: stack
 * @line_num: line number in file
 */
void pall_ops(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	temp = *stack;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * free_dlistint - Frees a list
 * @stack: Head node
 * Return: Nothing
 */
void free_dlistint(stack_t *stack)
{
	stack_t *temp = NULL;

	temp = stack;
	if (temp != NULL)
	{
		free_dlistint(temp->next);
		free(temp);
	}
}

/**
 * pint_ops - Prints the value at the top of the stack.
 * @stack: Head node
 * @line_num: line number in file
 * Return: Nothing
 */
void pint_ops(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	temp = *stack;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_num);
		fclose(global.fd);
		free(global.linebuf);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		dprintf(STDOUT_FILENO, "%d\n", temp->n);
	}
}

/**
 * pop_ops - Removes the top element of the stack.
 * @stack: Head node
 * @line_num: line number in file
 * Return: Nothing
 */
void pop_ops(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	temp = *stack;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_num);
		fclose(global.fd);
		free(global.linebuf);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		free(temp);
	}
}
