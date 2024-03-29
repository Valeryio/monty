#ifndef __MONTY_CIRCUS__
#define __MONTY_CIRCUS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
extern stack_t *montystack;


void push(stack_t**, unsigned int);
void pall(stack_t**, unsigned int);
void custom_pall(stack_t**, unsigned int);
void get_name(char*, char**);
char** get_arguments(char*);
void line_checker(char **, char *line, unsigned int line_number);
void (*get_instruction_func(char *str))(stack_t**, unsigned int);


#endif
