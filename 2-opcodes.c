#include "main.h"
/**
 * op_pop - pop the top
 * @stack: stack head
 * @ln_num: line_number
 *
 * Return: no void
 */
void op_pop(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	*stack = curr->next;
	free(curr);
}

/**
 * op_swap - a functio to swap top two elements of the stack.
 * @stack: stack head
 * @ln_num: line_number
 *
 * Return: no return
 */
void op_swap(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;
	int len = 0, tmp;

	curr = *stack;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	tmp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = tmp;
}
