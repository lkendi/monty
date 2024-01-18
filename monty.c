#include "monty.h"

void monty(FILE *file, char *argument)
{
	char contents[BUFFER_SIZE];
	char *line_copy = NULL, *opcode, *arg;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	instruction_t *instruction;

	while (fgets(contents, sizeof(contents), file) != NULL)
	{
		printf("%s\n", contents);
		line_copy = _strdup(contents);
		if (line_copy == NULL)
		{
			fprintf(stderr, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}

		opcode = strtok(line_copy, " \t\n");
		arg = strtok(NULL, " \t\n");
		printf("Opcode: %s, Argument: %s\n", opcode, arg);

		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL || *arg == '\0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			strcpy(argument, arg);
		}

		instruction = get_instruction(opcode, argument, line_number);
		if (instruction && instruction->f)
			instruction->f(&stack, line_number);

		line_number++;
	}

	free(line_copy);
}
