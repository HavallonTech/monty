#include "monty.h"
/**
 * main - Entry point of code
 * @ac: argument count passed to the interpreter
 * @av: argument vector
 * Return: returns (0) always success
 */
int main(int ac, char *av[])
{
	FILE *bcFile;
	stack_t *stack = NULL;

	if (ac == 1 || ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bcFile = fopen(av[1], "r");

	if (bcFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	bcprocess(bcFile, &stack);
	fclose(bcFile);
	return (0);
}

/**
 * bcprocess - function process the monty bytecode
 * @bc: file descriptor after opening the monty bytecode
 * Description: This function reads the opened bytecode into a buffer
 * to be tokenized and executed
 * @stack: double pointer to the stack
 * Return: returns void
 */
void bcprocess(FILE *bc, stack_t **stack)
{
	char *bc_opcode;/*byte code operation code*/
	char *bc_buff = NULL;/*byte code buffer to store content the byte code file*/
	size_t bc_len = 0;/*byte code length of the instruction per line*/
/*	ssize_t read;*/
	ssize_t readline = 0;/*to handle getline size */
	unsigned int bc_numln = 0;/*bc_numln keeps track of the line instruction*/

/*	read = getline(&bc_buff, &bc_len, bc);*/
	while ((readline = getline(&bc_buff, &bc_len, bc)) != -1)
	{
		bc_numln++;
		bc_opcode = strtok(bc_buff, DELIM);
		/*this checks if the bc_buff is empty or commented and ignore*/
		if (bc_opcode == NULL || bc_opcode[0] == '#')
			continue;
		/*printf("This is a string %s\n", bc_opcode);*/
		if (readline > 0)
		{
			bc_exe(bc_opcode, bc_numln, stack);
		}
		/*bc_numln++;*/
	}
	free(bc_buff);
}
/**
 * bc_exe - function process and executes the op code per command line
 * @opcode: operation code command passed
 * @cmd_num: command line number
 * @stack: double pointer to the stack
 * Return: returns void
 */
void bc_exe(const char *opcode, unsigned int cmd_num, stack_t **stack)
{
	instruction_t *bc_code = get_bc_opcode(opcode);
	/*this checks if the byte code instruction is valid*/
	if (bc_code == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", cmd_num, opcode);
		exit(EXIT_FAILURE);
	}
	/*this runs the arguments of the byte code instruction*/
	bc_code->f(stack, cmd_num);
}
/*
void bcprocess(FILE *bc, stack_t **stack)
 40 {
 41         char *bc_opcode;//byte code operation code/
 42         char *bc_buff = NULL;//byte code buffer to store content the byte code file
 43         size_t bc_len = 0;/*byte code length of the instruction per line
 44 /*      ssize_t read;
 45         ssize_t readline = 0;/*to handle getline size 
 46         unsigned int bc_numln = 0;/*bc_numln keeps tk of the line instruction
 47
 48 /*      read = getline(&bc_buff, &bc_len, bc);
 49         while ((readline = getline(&bc_buff, &bc_len, bc)) != -1)
 50         {
 51                 bc_numln++;
 52                 bc_opcode = strtok(bc_buff, DELIM);
 53                 /*this checks if the bc_buff is empty or commented and ignore
 54                 if (bc_opcode == NULL || bc_opcode[0] == '#')
 55                         continue;
 56                 /*printf("This is a string %s\n", bc_opcode);
 57                 if (readline > 0)
 58                 {
 59                         bc_exe(bc_opcode, bc_numln, stack);
 60                 }
 61                 //bc_numln++;/
 62         }
 63         free(bc_buff);
 64 }*/
