#include "monty.h"
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
	char file_contents[BUFFER_SIZE];
	char *opcode, *argument;
	instruction_t *instruction;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(file_contents, BUFFER_SIZE, file) != NULL)
	{
		opcode = strtok(file_contents, " \t\n");
		argument = strtok(NULL, " \t\n");

		/*Check the opcode for the corresponding function*/
		instruction = get_instruction(opcode, argument, line_number);
		/*Execute the function*/
		if (instruction && instruction->f)
			instruction->f(&stack, line_number);

		line_number++;
	}

	fclose(file);
	return (0);
}
