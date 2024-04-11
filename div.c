#include "monty.h"

/**
 * div - div two elements of a stack
 * @head: the stack
 *
 * Description: This function div two elements at the top of a
 * stack
 * Return: Nothing
 */

void divs(stack_t **head)
{
	int result = 0;
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	(*head) = (*head)->next;

	result = tmpnode->n / (*head)->n;
	(*head)->n  = result;

	free(tmpnode);
}
