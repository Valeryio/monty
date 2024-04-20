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
	int i = 0, cmp_result = 0;
	instruction_t montyinstructions[] = {
						{"stack", f_stack},
						{"queue", f_queue},
						{"pchar", f_pchar},
						{"push", f_push},
						{"pall", f_pall},
						{"pint", f_pint},
						{"swap", f_swap},
						{"pstr", f_pstr},
						{"rotl", f_rotl},
						{"rotr", f_rotr},
						{"pop", f_pop},
						{"nop", f_nop},
						{"add", f_add},
						{"sub", f_sub},
						{"div", f_div},
						{"mul", f_mul},
						{"mod", f_mod},
						{"NULL", NULL}
					};

	cmp_result = montyline_args[0][0] == '#';
/*Do nothing if the line is commented with '#' */
	if (cmp_result == 1)
	{
		f_nop(&(*stack_head), line_number);
		return;
	}

/*Call the right function to execute the line*/
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
