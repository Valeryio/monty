#include "monty.h"

/**
 * sub - add two elements of a stack
 * @head: the stack
 *
 * Description: This function substract two elements at the top of a
 * stack
 * Return: Nothing
 */

void sub(stack_t **head)
{
	int result = 0;
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	(*head) = (*head)->next;

/*	result = tmpnode->n - (*head)->n;*/
	result = (*head)->n - tmpnode->n;
	(*head)->n  = result;

	free(tmpnode);
}
