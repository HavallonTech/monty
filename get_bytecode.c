#include "monty.h"
/**
 * *get_bc_opcode - function checks and  returns operation code from an array
 * @bc_opcode: passed operation code argument
 * Return: returns the address of the required operation code passed
 */
instruction_t *get_bc_opcode(char *bc_opcode)
{
	instruction_t op_array[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};
	int n = 0;
	while (op_array[n].opcode)
	{
		if (strcmp(op_array[n].opcode, bc_opcode) == 0)
			return &op_array[n];
		n++;
	}
	return (NULL);
}
