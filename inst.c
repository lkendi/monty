#include "monty.h"

/**
 * get_instruction - maps opcode to function
 * @opcode: opcode in Monty file
 * @argument: argument for the opcode
 * @line_number: current line number
 * Return: instruction that corresponds to the opcode, or NULL if not found
 */
instruction_t *get_instruction(char *opcode,
			char *argument, unsigned int line_number)
{
	int i = 0;
	static instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0 && (argument == NULL || *argument == '\0'))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			return (&instructions[i]);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}


char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *copy = malloc(len);
	if (copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return memcpy(copy, str, len);
}
