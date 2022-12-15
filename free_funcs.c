#include "monty.h"
/**
 * free_stack - free the stack
 * @stack: stack
 * Return void
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *tmp = stack;

		stack = stack->next;
		free(tmp);
	}
}
/**
  * end_frees - free stack, line and close file
  * @stack: stack
  * @line: line
  * @file: file containing opcodes
  */
void end_frees(stack_t *stack, char *line, FILE *file)
{
	free(stack);
	free(line);
	fclose(file);
}
