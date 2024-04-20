#include "monty.h"

/**
 * queue - Implement the stack version of the opcode
 *
 * @head: the stack to use to do nothing
 * @line_number: verifications to do on the line
 * Description: This function do nothing cause the normal
 * format of the data structure in a monty interpreter is
 * a stack
 * Return: Nothing
 */

void queue(stack_t **head)
{
	int i = 0, stack_length = getStackLength(&(*head)), *new_array = NULL;
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
/*Create a new data structure to save the actual data*/
	new_array = malloc(sizeof(int) * stack_length);

	if (!new_array)
	{
		printf("Malloc fails !\n");
		return;
	}

/*Store the data in the stack order when trying to fill the new DS*/
	for (; i < stack_length; i++)
	{
		new_array[i] = tmpnode->n;
		tmpnode = tmpnode->next;
	}

	tmpnode = (*head);
	i--;

/*Erase the previous order in the monty's stack to create a monty's queue*/
	for (; i >= 0; i--)
	{
		tmpnode->n = new_array[i];
		tmpnode = tmpnode->next;
	}

	free(new_array);
	return;
}
