#include "monty.h"

/**
 * op_rotr - function to rotate the stack to the bottom
 * @stack: double pointer to the stack
 * @ln_num: line number for error position
 *
 * Return: oids
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
}
/**
 * op_div - divides the top two elements of the stack.
 * @stack: stack head
 * @ln_num: line_number
 *
 * Return: void
 */
void op_div(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr = NULL;
	int len = 0, div;

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
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/**
	 * check if curr->next->n and curr->n are numbers is not needed
	 * this is because div does not take an argument and the check for numbers
	 * have been passed in the op_push function
	 */
	/*if (isdigit(curr->next->n) && isdigit(curr->n))*/
	div = (*stack)->next->n / (*stack)->n;
	pop(stack);
	(*stack)->n = div;
}

/**
 * op_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack head
 * @ln_num: line_number
 *
 * Return: void
 */
void op_mod(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;
	int len = 0, mod;

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
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	pop(stack);
	(*stack)->n = mod;
}
/**
 * op_pstr - a function to prints the string starting at the top of the stack
 * @stack: stack stack
 * @ln_num: line_number
 *
 * Return: void
 */
void op_pstr(stack_t **stack, __attribute__((unused)) unsigned int ln_num)
{
	stack_t *curr;

	curr = *stack;

	while (curr)
	{
		if (curr->n > 127 || curr->n <= 0)
		{
			break;
		}
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
/**
  *op_sub- a function to subtracts the top element of the stack from
  * the second top element of the stack
  *@stack: stack head
  *@ln_num: line_number
  *
  *Return: no return
 */
void op_sub(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;
	int tmp, elements = 0;

	curr = *stack;

	while (curr != NULL)
	{
		elements++;
		curr = curr->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;

	tmp = (curr->next->n) - (curr->n);
	curr->next->n = tmp;
	*stack = curr->next;
	free(curr);
}
