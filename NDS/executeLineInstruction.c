#include "monty.h"

/**
 * executeLineInstruction - executes an instruction on a line
 *
 * Description: This function executes a valid line of instruction
 * in a monty's progra file.
 * Return: Nothing
 */

void executeLineInstruction(stack_t **stack_head, unsigned int line_number)
{
	int i = 0;
	instruction_t montyinstructions[] = {{"push", f_push}, {"pall", f_pall}, {"NULL", NULL}};

	printf("Hey, ssuis la!\n");
	while (montyinstructions[i].opcode)
	{
		if (strcmp(montyinstructions[i].opcode, montyline_args[0]) == 0)
		{
			printf("J'ai trouve le code !\n");
			montyinstructions[i].f(&(*stack_head), line_number);
			printf("La fonction %s a du etre execute\n", montyinstructions[i].opcode);
			break;
		}
		i++;
	}
}
