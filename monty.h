#ifndef _MAIN_H
#define _MAIN_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct var
{
	char *arg;
} globals;
extern globals global_arg;
globals global_arg;


void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_numeric_string(char *str);
int validFile(char *filename, FILE *file);
instruction_t *findOpCode(char *instruction, instruction_t *instr);
int executeOpCodes(char *instruction, stack_t **stack, unsigned int line_number);

void end_frees(stack_t *stack, char *line, FILE *file);
void free_struct(instruction_t *instructions);

void error_usage();
void error_swapping(unsigned int line_number);
void error_unknown(unsigned int line_number, char *instruction);


#endif

