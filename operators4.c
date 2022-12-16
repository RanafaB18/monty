#include "monty.h"
/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
/**
 * rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if ((*stack)->next != NULL)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		(*stack)->prev = temp;
		temp->next = *stack;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		temp->next->next = NULL;
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if ((*stack)->next != NULL)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		(*stack)->prev = temp;
		temp->next = *stack;
		temp->prev->next = NULL;
		temp->prev = NULL;
		(*stack) = (*stack)->prev;
	}
}
/**
 * _add - adds the top two elements in stack
 * @stack: head of stack
 * @line_number: node number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * _mul - multiply second node and top node
 * @stack: stack
 * @line_number: line of command
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
