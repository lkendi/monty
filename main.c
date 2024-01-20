#include "monty.h"
/**
 * print_fopen_error - display error if file not found
 * @filename: name of the file
 * Return: nothing
*/
void print_fopen_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
*/
int main(int argc, char **argv)
{
	FILE *file;
	unsigned int line_number = 1;
	char file_contents[BUFFER_SIZE], *line, *opcode, *argument;
	instruction_t *instruction;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
		print_fopen_error(argv[1]);
	while (fgets(file_contents, BUFFER_SIZE, file) != NULL)
	{
		if (file_contents[0] == '\n' || file_contents[0] == '\0')
		{
			line_number++;
			continue;
		}
		/*Trim leading and trailing spaces*/
		line = strtok(file_contents, "\n");
		line = strtok(line, " \t");
		if (line == NULL)
		{
			line_number++;
			continue;
		}
		opcode = line;
		argument = strtok(NULL, " \t\n");
		instruction = get_instruction(opcode, argument, line_number);
		/*Execute the function*/
		if (instruction && instruction->f)
			instruction->f(&stack, line_number);
		line_number++;
	}
	fclose(file);
	return (0);
}
