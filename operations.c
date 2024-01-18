#include "monty.h"
/**
 * swap - swaps the top 2 elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *prev;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	prev = (*stack)->prev;
	prev->prev->next = *stack;
	(*stack)->prev = prev->prev;
	(*stack)->next = prev;
	prev->next = NULL;
	prev->prev = *stack;
	(*stack) = prev;
}

/**
 * add - adds the top 2 elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 * Return: sum of the top 2 elements
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *prev;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	prev = (*stack)->prev;
	printf("%d\n", prev->n + (*stack)->n);
}
