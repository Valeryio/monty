#include "monty.h"

/**
 * executeLineInstruction - executes an instruction on a line
 *
 * @stack_head: the head of the stack
 * @line_number: the number of the line of the execution
 * Description: This function executes a valid line of instruction
 * in a monty's progra file.
 * Return: Nothing
 */

void executeLineInstruction(stack_t **stack_head, unsigned int line_number)
{
	int i = 0;
	instruction_t montyinstructions[] = {
						{"push", f_push},
						{"pall", f_pall},
						{"pint", f_pint},
						{"swap", f_swap},
						{"pop", f_pop},
						{"nop", f_nop},
						{"add", f_add},
						{"sub", f_sub},
						{"div", f_div},
						{"NULL", NULL}
					};

	while (montyinstructions[i].opcode)
	{
		if (strcmp(montyinstructions[i].opcode, montyline_args[0]) == 0)
		{
			montyinstructions[i].f(&(*stack_head), line_number);
			break;
		}
		i++;
	}
}
