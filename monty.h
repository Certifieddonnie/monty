#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - global funcs
 * @item: value
 * @fd: File descriptor
 * @linebuf: Lines in files
 *
 * Description - handling file and lines.
 */
typedef struct glob_s
{
	char *item;
	FILE *fd;
	char *linebuf;
} glob_t;

extern glob_t global;

void read_file(char *argv);
int operation(stack_t **stack, char *args, int line_num);
/*Helpers*/
int is_digit(char *c);
/*Error handlers*/
void push_error(FILE *fd, char *linebuf, stack_t **stack, int line_num);
void instruct_error(FILE *fd, char *lin, stack_t *stack, char *args, int line);
/*OpCodes*/
void nop_ops(stack_t **stack, unsigned int line_num);
void add_ops(stack_t **stack, unsigned int line_num);
void swap_ops(stack_t **stack, unsigned int line_num);
void pop_ops(stack_t **stack, unsigned int line_num);
void pint_ops(stack_t **stack, unsigned int line_num);
void pall_ops(stack_t **stack, unsigned int line_num);
void push_ops(stack_t **stack, unsigned int line_num);
/*Stacks & Queues*/
void free_dlistint(stack_t *stack);

#endif /*MONTY_H*/
