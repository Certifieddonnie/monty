#include "monty.h"

/**
 * read_file - Function that reads the file coming in.
 * @filename: file
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int read_file(const char *filename)
{
	int fd, line = 1, maxlinelen = 128;
	char ch;
	char *linebuf;

	if (filename == NULL)
	{
		fprintf(stderr,"Error: file is empty\n");
		return(EXIT_FAILURE);
	}
	fd = open(filename,O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr,"Error: Can't open file %s\n",filename);
		return(EXIT_FAILURE);
	}
	linebuf = malloc(sizeof(char) * maxlinelen);
	if (!linebuf)
	{
		dprintf(2,"Error: Can't allocate memory for line buffer");
		return(EXIT_FAILURE);
	}
	while(fd != EOF)
	{
		while(fgets(line, sizeof(line), fd))
		{
			;
		}
		line++;
	}


	return(EXIT_SUCCESS);
}
