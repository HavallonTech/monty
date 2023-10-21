#include "monty.h"
/**
 * op_rotl - function rotates the stack to the top
 * @stack: double pointer to the stack(head)
 * @ln_num: number line for error checking
 * Return: returns void
 */
void op_rotl(stack_t **stack, unsigned int ln_num)
{
	stack_t *node1;
	stack_t *node2;

	(void)ln_num;
	if (/*stack == NULL || */*stack == NULL || (*stack)->next == NULL)
		return;
	node1 = *stack;
	node2 = (*stack)->next;
	while (node2->next)
	{
		node1 = node1->next;
		node2 = node2->next;
	}
	node1->next = NULL;
	node2->prev = NULL;

	node2->next = *stack;
	(*stack)->prev = node2;
	*stack = node2;
}
