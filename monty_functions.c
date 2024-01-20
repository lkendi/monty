#include "monty.h"
/**
 * push - adds an element to the top of the stack
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	if (!push_argument && (!isdigit(push_argument + '0')))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->next = NULL;
	new->n = push_argument;

	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * pall - prints all the elements in the stack starting from the top
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the element at the top of the stack
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * pop - premoves the top element of the stack
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	temp->next = NULL;
	free(temp);
}


/**
 * nop - does nothing
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

