#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define _GNU_SOURCE 1

#define DELIM " \t\n"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t stack;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*main functions*/
void bcprocess(FILE *bc, stack_t **stack);
ssize_t getline(char **bc_buff, size_t *bc_len, FILE *bc);
void bc_exe(const char *opcode, unsigned int cmd_num, stack_t **stack);
instruction_t *get_bc_opcode(const char *opcode);

/*aux functions*/
void pushNode(stack_t **stack, int val);
int is_valid_int(char *s);

/*get_bc_opcode*/
void op_push(stack_t **stack, unsigned int ln_num);
void op_pall(stack_t **stack, unsigned int ln_num);
void op_add(stack_t **stack, unsigned int ln_num);
void op_mul(stack_t **stack, unsigned int ln_num);
void op_rotr(stack_t **stack, __attribute__((unused)) unsigned int ln_num);
void op_div(stack_t **stack, unsigned int ln_num);
void op_mod(stack_t **stack, unsigned int ln_num);
void op_pstr(stack_t **stack, __attribute__((unused)) unsigned int ln_num);
void op_sub(stack_t **stack, unsigned int ln_num);
void op_swap(stack_t **stack, unsigned int ln_num);
void op_pop(stack_t **stack, unsigned int ln_num);
void op_pint(stack_t **stack, unsigned int ln_num);

void free_stack(stack_t *head);
#endif /*_MONTY_H_*/
