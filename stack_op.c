#include "monty.h"
/**
 * pushNode - function creates a node and pushes it to the stack
 * @stack: double pointer to the stack
 * @val: value to be pushed into the stack
 * Return: returns void
 */

void pushNode(stack_t **stack, int val)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error mallloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = val;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newNode;

	*stack = newNode;
}


/**
 * is_valid_int - function checks if a string is a valid integer argument
 * @s: string argument passed
 * Return: return (0) if not valid else (1)
 */
int is_valid_int(char *s)
{
	if (s == NULL || *s == '\0')
		return (0);

	if (*s == '-' || *s == '+')
		s++;
	while (*s != '\0')
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
