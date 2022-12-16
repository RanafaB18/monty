#include "monty.h"
/**
 * error_usage - print error message for usage
 * Return: EXIT_FAILURE
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * error_unknown - print error message for unknown instructions
 * @line_number: line number
 * @instruction: instruction
 * Return: EXIT_FAILURE
 */
void error_unknown(unsigned int line_number, char *instruction)
{
	printf("instruction in unknown: %s\n", instruction);
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
/**
 * error_swapping - print error message for swapping errors
 * @line_number: line number
 * Return: EXIT_FAILURE
 */
void error_swapping(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
