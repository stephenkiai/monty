#include "monty.h"
/**
 * free_stack - Frees the entire stack.
 * @stack: Pointer to the pointer to the stack.
 *
 * Description: This function frees all the nodes in the stack,
 *              starting from the top node and moving downwards.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}
}
