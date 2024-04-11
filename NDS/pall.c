#include "monty.h"

/**
 * pall - show all the elements of a stack
 *
 * @head: the head of the stack
 * Description: This function shows all the
 * node inside a stack
 * Return: nothing
 */
void pall(stack_t **head)
{
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	while (tmpnode != NULL)
	{
		printf("%d\n", tmpnode->n);
		tmpnode = tmpnode->next;
	}
}


/**
 * custom_pall - show all the elements of a stack
 *
 * @head: the head of the stack
 * Description: This function shows all the
 * node inside a stack
 * Return: nothing
 */
void custom_pall(stack_t **head)
{
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	while (tmpnode != NULL)
	{
		printf("[%d]-", tmpnode->n);
		tmpnode = tmpnode->next;
	}

	printf("||*\n\n");
}
