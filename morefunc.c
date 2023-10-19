#include "monty.h"

/**
 *p_rotr - function to rotate the stack to the bottom
 * @stack: double pointer to the stack
 * @ln_num: line number for error position
 * Return: return voids
 */
void op_rotr(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;

	curr = *stack;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->head = *stack;
	curr->prev->next = NULL;
	curr->prev = NULL;
	(*head)->prev = curr;
	(*head) = curr;
	/*free(stack);*/
}
