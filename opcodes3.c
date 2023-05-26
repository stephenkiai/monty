#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    opcode_pop(stack, line_number);
}
