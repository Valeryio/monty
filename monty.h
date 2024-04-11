#ifndef __MONTY_CIRCUS__
#define __MONTY_CIRCUS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

/*
 * @montystack: The extern variable used
 */
extern char **montyline_args;

int freeprog(stack_t**);
int getNumberOfArgs();
void freeStack(stack_t**);
void getArguments(char*);
int containString(char *);
int args_checker(char **, int);
void executeLineInstruction(stack_t**, unsigned int);
int isValidArgument(stack_t**, unsigned int line_number);

void f_push(stack_t**, unsigned int);
void push(stack_t**, int);

void f_pint(stack_t**, unsigned int);
void pint(stack_t**);

void f_pall(stack_t**, unsigned int);
void pall(stack_t**);

void f_pop(stack_t**, unsigned int);
void pop(stack_t**);

void f_swap(stack_t**, unsigned int);
void swap(stack_t**);

void f_nop(stack_t**, unsigned int);
void nop(void);

void f_add(stack_t**, unsigned int);
void add(stack_t**);

void custom_pall(stack_t**);
int getStackLength(stack_t**);
int line_checker(char *line, unsigned int line_number);
void (*get_instruction_func(char *str))(stack_t**, unsigned int);

/*Error functions*/

void OpenFileError(char*);
void UsageFileError();
void mallocError();

#endif
