
#include "monty.h"

/**
 * parse_line - Parses a line of instruction and executes it.
 * @line: The line to parse.
 * @line_number: The line number in the file.
 * @stack: Pointer to the stack.
 *
 * Description: This function parses a line of instruction by tokenizing it
 *              and extracting the opcode. It checks if the opcode is valid,
 *              retrieves the corresponding function, and executes it. If the
 *              opcode is unknown, it prints error mssge &  exits with failure.
 */
void parse_line(char *line, unsigned int line_number, stack_t **stack)
{
	instruction_t *instruction;
	char *opcode = strtok(line, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	instruction = get_instruction(opcode);

	if (instruction == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	instruction->func(stack, line_number);
}

instruction_t instructions[] = {
	{"push", opcode_push},
	{"pall", opcode_pall},
	{"pint", opcode_pint},
	{"pop", opcode_pop},
	{"swap", opcode_swap},
	{"nop", opcode_nop},
	{"sub", opcode_sub},
	{"div", opcode_div},
	{"mul", opcode_mul},
	{"mod", opcode_mod},
	{"pchar", opcode_pchar},
	{"pstr", opcode_pstr},
	{"rotl", opcode_rotl},
	{"rotr", opcode_rotr},
	{"stack", opcode_stack},
	{"queue", opcode_queue},
	{NULL, NULL}
};

instruction_t *get_instruction(char *opcode)
{
	int i;

	i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (&instructions[i]);
		i++;
	}
	return (NULL);
}
