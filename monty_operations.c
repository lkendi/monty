#include "monty.h"
/**
 * swap - swaps the top 2 elements of the stack
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}

/**
 * add - adds the top 2 elements of the stack
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n += (*stack)->n;
	pop(stack, line_number);
}
