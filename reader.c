#include "monty.h"

/**
 * read_file - Function that reads the file coming in.
 * @filename: file
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int read_file(const char *filename)
{
	FILE *fd;
	int line = 0, res = 0;
	size_t bufsize = 0;
	char *linebuf, *args = NULL, *item = NULL;
	stack_t *stack = NULL;

	fd = fopen(filename,O_RDONLY);
	if (!fd)
	{
		dprintf(STDERR_FILENO,"Error: Can't open file %s\n",filename);
		exit(EXIT_FAILURE);
	}
	while(getline(&linebuf, &bufsize, fd) != -1)
	{
		line++;
		args = strtok(linebuf,"\n\t\r");
		if(args == NULL)
		{
			free(args);
			continue;
		}
		else if(*args == '#')
			continue;
		item = strtok(NULL,"\n\t\r");
		res = operation(&stack,args,item,line);
		if(res == -1)
			push_error(fd,linebuf,stack,line);
		else if(res == -2)
			instruct_error(fd,linebuf,stack,args,line);
	}
	free(linebuf);
	free_dlistint(stack);
	fclose(fd);
	return(EXIT_SUCCESS);
}

/**
 * operation - Function to handle the ops_code
 * @stack: stack or queue
 * @args: arguments token
 * @item: token
 * @line_num: line number in file
 * Return: -1, -2, or 0(success)
 */
int operation(stack_t **stack, char *args, char *item, int line_num)
{
	int i;
	instruction_t op[] = {
		{"push",push_ops},
		{"pall",pall_ops},
		{NULL, NULL}
	};

	i = 0;
	while(op[i].opcode)
	{
		if(!strcmp(args,op[i].opcode))
		{
			if(!strcmp(args,"push"))
			{
				if(is_digit(item) == 1)
					value = atoi(item);
				else
					return(-1);
			}
			op[i].f(stack,(unsigned int)line_num);
			break;
		}
		i++;
	}
	if(!op[i].opcode)
		return(-2);

	return(0);
}
