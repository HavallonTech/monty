#include "monty.h"
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
 * op_pint - function prints the value at the top of the stack
 * @stack: double pointer to the stack(head)
 * @ln_num: line number for error checking
 *
 * Return: returns void
 */
void op_pint(stack_t **stack, unsigned int ln_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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

/**
 * op_nop - function does not do anything in the stack
 * @stack: double pointer to the stack(head)
 * @ln_num: line number for error checking
 *
 * Return: returns void
 */
void op_nop(stack_t **stack, unsigned int ln_num)
{
	(void)stack;
	(void)ln_num;
}
