#include "monty.h"

/**
 * op_rotr - function to rotate the stack to the bottom
 * @stack: double pointer to the stack
 * @ln_num: line number for error position
 * Return: return voids
 */
void op_rotr(stack_t **stack, __attribute__((unused)) unsigned int ln_num)
{
	stack_t *curr;
	int len = 0;

	curr = *stack;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	while (curr)
	{
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't rotate, stack too short\n", 30);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = *stack;
	curr->prev->next = NULL;
	curr->prev = NULL;
	(*stack)->prev = curr;
	(*stack) = curr;
/*	free(curr);*/
/*	free(stack);*/
}
