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
/**
 * op_div - divides the top two elements of the stack.
 * @stack: stack head
 * @ln_num: line_number
 * Return: no return
 */
void op_div(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;
	int len = 0, temp;

	curr = *stack;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* check if curr->next->n and curr->n are numbers */
	/*	if (is_valid_int(curr->next->n) && is_valid_int(curr->n)) */
	if (isdigit(curr->next->n) && isdigit(curr->n))
	{
		temp = (curr->next->n) / (curr->n);
		curr->next->n = temp;
		*stack = curr->next;
		free(curr);
	}
}

/**
 * op_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack head
 * @ln_num: line_number
 * Return: no return
 */
void op_mod(stack_t **stack, unsigned int ln_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (curr->next->n) % (curr->n);
	curr->next->n = tmp;
	*stack = curr->next;
	free(curr);
}
