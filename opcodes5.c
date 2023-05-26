#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * mod - Computes the remainder of the division of the second top element
 *       of the stack by the top element.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	opcode_pop(stack, line_number);
}

int mode = 0; /* 0 represents stack mode, 1 represents queue mode */

/**
 * opcode_stack - Sets the mode to stack (LIFO).
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 0;
}

/**
 * opcode_queue - Sets the mode to queue (FIFO).
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 1;
}
