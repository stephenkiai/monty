#include "monty.h"
/**
 * exec_instruction - Executes instruction corresponding to given opcode.
 * @opcode: The opcode to be executed.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: The line number of the instruction in the file.
 *
 * Description: looks up the instruction corresponding to the given opcode,
 *              if found, executes it by calling the associated function
 *              If the opcode is unknown, it prints an error
 *              message and exits with failure.
 */
void exec_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t *instruction = get_instruction(opcode);

	if (instruction != NULL)
	{
		instruction->func(stack, line_number);
	}
	else
	{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
	}
}
