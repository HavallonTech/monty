#include "monty.h"
/**
 * *get_bc_opcode - function checks and  returns operation code from an array
 * @bc_opcode: passed operation code argument
 * Return: returns the address of the required operation code passed
 */
instruction_t *get_bc_opcode(const char *bc_opcode)
{
	instruction_t *op_array = NULL;
	instruction_t op_set[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"add", op_add},
		/*		{"div", op_div},*/
		{"mul", op_mul},
		/*	{"pint", op_pint},*/
		/*	{"pop", op_pop},*/
		{"swap", op_swap},
		/*{"nop", op_nop},*/
		{"sub", op_sub},
		{"mod", op_mod},
		/*	{"pchar", op_pchar},*/
		{"pstr", op_pstr},
		/*{"rotl", op_rotl},*/
		{"rotr", op_rotr},
		{"div", op_div},
		/*{"queue", op_queue},*/
		/*{"stack", op_stack},*/
		{NULL, NULL}
	};
	int n = 0;

	if (bc_opcode == NULL)
		return (NULL);
	while (op_set[n].opcode)
	{
		if (strcmp(op_set[n].opcode, bc_opcode) == 0)
		{
			op_array = &op_set[n];
			break;
		}
		n++;
	}
	return (op_array);
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
