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
	char argument[BUFFER_SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty(file, argument);
	fclose(file);

	return (0);
}
