#include "monty.h"

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

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to pointer to the top of the stack
 * @line_number: instruction line number
 * Return: nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n %= (*stack)->n;
	pop(stack, line_number);
}
