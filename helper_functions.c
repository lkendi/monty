#include "monty.h"

int push_argument = 0;

/**
 * print_push_error - prints usage error for push instruction
 * @line_number: instruction line number
 * Return: nothing
 */
void print_push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * get_instruction - gets function from its corresponding opcode
 * @opcode: opcode to check for corresponding instruction
 * @argument: opcode argument
 * @line_number: instruction line number
 * Return: instruction that corresponds to the opcode
 */
instruction_t *get_instruction(char *opcode,
					char *argument, unsigned int line_number)
{
	int i = 0, j;
	static instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{NULL, NULL}};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (argument == NULL)
					print_push_error(line_number);
				for (j = 0; argument[j] != '\0'; j++)
				{
					if (!isdigit(argument[j]) && argument[j] != '-')
						print_push_error(line_number);
				}
				push_argument = atoi(argument);
			}
			else
				push_argument = 0;
			return (&instructions[i]);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
