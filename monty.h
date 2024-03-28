#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE 1024
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
 * Descrtiption: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct func_linked - linked list of functions.
 * @instruction: opcode and its function
 * @link: address of next function.
 *
 * Description: linked list of functions.
 */
typedef struct func_linked
{
        instruction_t *instruction;
        struct func_linked *link;
} func_linked;

extern stack_t *stack;
extern func_linked *head;
void arguments(char *full_command, int line_number);
void opcode_interpreter(char **argv, int line_interpreter);
func_linked *func_list();
char *_strdup(char *str);
void pus(stack_t **stack, unsigned int line_number);
void pal(stack_t **stack, unsigned int line_number);
void pin(stack_t **stack, unsigned int line_number);
void po(stack_t **stack, unsigned int line_number);
void swa(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void no(stack_t **stack, unsigned int line_number);
#endif
