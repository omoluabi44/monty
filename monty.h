#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdarg.h>
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

/** globalvariable declarartion */
extern char **tokens;
extern instruction_t *all_func;
extern int N_token;
extern unsigned int line_number;
extern stack_t *head;
extern int stack_length;
extern FILE *fileOpen;
extern char *line;
/** important functions*/
int main(int argc, char **argv);
void valid_argument(int argc);
FILE *file(char *filename);
void tokenize_opcodes(void);
void function_ptr(void);
/**stack_t *create_newNode(int value);*/

/** others small functions */
void run_instr(void);
void malloc_fail(void);
void ini_all_func(void);
void invalid_instr(void);
int is_number(char *str);

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

/** free function */
void free_all(void);
void free_head(void);
void free_arguments(void);
void free_tokes(void);
void close_stream(void);

#endif
