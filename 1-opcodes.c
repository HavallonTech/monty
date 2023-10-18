#include "monty.h"
/**
 * op_push - function pushes an element to the stack
 * @stack: double pointer to the stack
 * @ln_num: line number for error position
 * Return: return voids
 */
void op_push(stack_t **stack, unsigned int ln_num)
{
	int stack_val;

	char *args = strtok(NULL, DELIM);

	if (args == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln_num);
		exit(EXIT_FAILURE);
	}
	if (!is_valid_int(args))
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln_num);
		exit(EXIT_FAILURE);
	}
	stack_val = atoi(args);
	pushNode(stack, stack_val);
}
/**
 * op_pall - function prints all the element in the stack
 * @stack: double pointer to the stack
 * @ln_num: line number for error position
 * Return: returns void
 */
void op_pall(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;

	(void)ln_num; /*make is unusable*/
	curr = *stack;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
/**
 * op_add - function to add element in the stack
 * @stack: double pointer to the stack
 * @ln_num: line number for error position
 * Return: returns void
 */
void op_add(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;
	int len = 0, temp;

	curr = *stack;

	while (curr)
	{
		len++;
		curr = curr->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d, can't add element to the stack\n", ln_num);
		fclose(bcFile);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	temp = curr->n + curr->next->n;
	curr->next->n = temp;
	*stack = curr->next;
	free(curr);
}
/**
 * op_add - function to add element in the stack
 * @stack: double pointer to the stack
 * 
 * Return: returns void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;
	temp = head;
	while(head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
