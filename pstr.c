#include "monty.h"

/**
 * pstr - print a string from a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function prints a string from a stack
 * Return: Nothing
 */

void pstr(stack_t **head)
{
	int c[1];
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	while (tmpnode)
	{
		c[0] = tmpnode->n;

/*1 - Stop when the value of the elementt is 0*/
		if (c[0] == 0)
			return;

/*2 - stop when the value of the element is not in ASCII table*/
		if (c[0] > 127 || c[0] < 0)
			return;

/*3 - Print the right character*/
		printf("%c", c[0]);
		tmpnode = tmpnode->next;
	}
	printf("\n");
}
