#include "monty.h"

/**
 * opcode_pchar - Prints the character value at the top of the stack.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	int value;
	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}

/**
 * opcode_pstr - Prints the string contained in the stack.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;
	current = *stack;

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * opcode_rotl - Rotates the stack to the top.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	
	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * opcode_rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the pointer to the stack.
 * @line_number: Line number of the instruction in the file.
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	
	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}
