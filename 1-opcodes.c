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
