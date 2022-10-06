#include "monty.h"

/**
 * push_ops - pushes data into stack
 * @stack: stack
 * @line_num: line number in file
 */
void push_ops(stack_t **stack,unsigned int line_num)
{
	stack_t *newnode;
	(void)line_num;

	newnode = malloc(sizeof(stack_t));
	if(newnode == NULL)
	{
		dprintf(STDERR_FILENO,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = value;
	newnode->next = *stack;
	newnode->prev = NULL;
	if(*stack != NULL)
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
	while(temp != NULL)
	{
		dprintf(STDOUT_FILENO,"%d\n",temp->n);
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
	if(temp != NULL)
	{
		free_dlistint(temp->next);
		free(temp);
	}
}
