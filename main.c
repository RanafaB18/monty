#include "monty.h"
/**
 * trim_and_count_spaces - remove leading and trailing spaces
 * @str: string
 * Return: number of spaces left in trimmed string
 */
int trim_and_count_spaces(char *str)
{
	int count;
	int i;
	int len;

	while (isspace(*str))
	{
		str++;
	}

	len = strlen(str);
	while (len > 0 && isspace(str[len - 1]))
	{
		len--;
	}

	str[len] = '\0';

	count = 0;
	for (i = 0; i < len; i++)
	{
		if (isspace(str[i]))
		{
			while (isspace(str[i]))
			{
				i++;
			}
			count++;
		}
	}

	return (count);
}
/**
 * check_for_comment - checks if a line is a comment
 * @line: pointer to the line being checked
 *
 * Return: 1 if line is a comment, 0 otherwise
 */
int check_for_comment(char *line)
{
	int i;

	if (!line)
		return (0);

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '#')
			return (1);
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
	}

	return (0);
}
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
		if (trim_and_count_spaces(line) > 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (check_for_comment(line) == 1)
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
