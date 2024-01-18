#include "monty.h"

void monty(FILE *file)
{
	char *line, *opcode, *argument;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	size_t len = 0;
	instruction_t *instruction;

	while (getline(&line, &len, file) != -1)
	{
		// Make a copy of the line before using strtok
		char *line_copy = strdup(line);
		if (line_copy == NULL)
		{
			fprintf(stderr, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}

		opcode = strtok(line_copy, " \t\n");
		argument = strtok(NULL, " \t\n");

		//printf("Opcode: %s, Argument: %s\n", opcode, argument);

		instruction = get_instruction(opcode, argument, line_number);

		//Execute the instruction
		if (instruction && instruction->f)
			instruction->f(&stack, line_number);

		line_number++;
	}

	free(line);
	// free_stack(&stack);
}
