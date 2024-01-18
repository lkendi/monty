#include "monty.h"

/**
 * push - adds an element to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in Monty file
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *arg;
	stack_t *new;

	arg = strtok(NULL, " \t\n");
	printf("Push Arg: %s\n", arg);
	if ((arg == NULL) || ((isdigit(*arg) != 0) && (arg[0] != '-')))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Malloc success\n");
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
	printf("Top: %d\n", (*stack)->n);

}

/**
 * pall - prints all the nodes of the stack
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	printf("Line: %d", line_number);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	free(*stack);
	*stack = temp;
}


/**
 * nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
