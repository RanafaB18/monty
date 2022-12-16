#include "monty.h"
/**
 * main - main entry
 * @argc: number of arguments
 * @argv: arguments
 * Return: EXIT_SUCCESS if successful else EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *filename, *line, *instruction;
	FILE *file;
	unsigned int line_number;
	size_t line_size;
	stack_t *stack;

	if (argc != 2)
		error_usage();
	filename = argv[1];
	file = fopen(filename, "r");
	validFile(filename, file);
	line = NULL;
	line_size = 0;
	line_number = 0;
	stack = NULL;
	while (getline(&line, &line_size, file) != -1)
	{
		line_number++;
		if (line &&line[0] == '#')
			continue;
		instruction = strtok(line, " \n\t\r");
		global_arg.arg = strtok(NULL, " \n\t\r");
		if (instruction == NULL)
			continue;
		if (executeOpCodes(instruction, &stack, line_number) == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
			end_frees(stack, line, file);
			exit(EXIT_FAILURE);
		}
	}
	end_frees(stack, line, file);
	return (EXIT_SUCCESS);
}
