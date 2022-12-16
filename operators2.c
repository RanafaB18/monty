#include "monty.h"
/**
 * is_numeric_string - subtract
 * @str: string
 * Return: 1 if str is only digits else 0
 */
int is_numeric_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
	}
	return (1);
}
/**
 * validFile - check if the file can be opened
 * @filename: name of the file
 * @file: file
 * Return: 1 if the file is valid else EXIT_FAILURE
 */
int validFile(char *filename, FILE *file)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (1);
}
/**
 * findOpCode - get the opcode
 * @instruction: instruction
 * @instr: list of instructions
 * Return: instruction with the opcode
 */
instruction_t *findOpCode(char *instruction, instruction_t *instr)
{
	while (instr->opcode != NULL)
	{
		if (strcmp(instruction, instr->opcode) == 0)
		{
			return (instr);
		}
		instr++;
	}
	return (instr);
}
/**
 * executeOpCodes - execute instructions of opcode
 * @instruction: opcode
 * @stack: stack
 * @line_number: line number
 * Return: 1 if it executes else 0
 */
int executeOpCodes(char *instruction, stack_t **stack,
		unsigned int line_number)
{
	instruction_t *instr;
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"pall", pall},
		{"pint", pint},
		{"add", _add},
		{"sub", sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", _stack},
		{NULL, NULL}};
	instr = findOpCode(instruction, instructions);
	if (instr->opcode != NULL)
	{
		instr->f(stack, line_number);
		return (1);
	}
	return (0);
}
