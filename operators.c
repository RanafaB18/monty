#include "monty.h"
/**
 * push - push unto stack
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument = global_arg.arg;
	int n;
	stack_t *new;

	if (argument == NULL || is_numeric_string(argument) == 0)
	{
		free(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		free(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * pall - print data in stack
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	char *argument;
	stack_t *current = *stack;
	(void)line_number;


	argument = global_arg.arg;
	if (argument)
	{
		error_unknown(line_number, "pall");
	}
	if (*stack == NULL || !stack)
	{
		return;
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint - print integer
 * @stack: stack
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - remove top element of stack
 * @stack: stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
}
/**
 * swap - swap top and second-to-top elements in stack
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		error_swapping(line_number);
	}
	first = *stack;
	second = first->next;
	*stack = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = NULL;
}
