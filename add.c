#include "monty.h"

/**
 * add - add two elements of a stack
 * @head: the stack
 *
 * Description: This function add two elements at the top of a
 * stack
 * Return: Nothing
 */

void add(stack_t **head)
{
	int result = 0;
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	(*head) = (*head)->next;

	result = (*head)->n + tmpnode->n;
	(*head)->n  = result;

	free(tmpnode);
}
