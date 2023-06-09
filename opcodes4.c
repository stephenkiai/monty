#include "monty.h"
/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	opcode_pop(stack, line_number);
}

