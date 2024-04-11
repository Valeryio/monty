#include "monty.h"


/**
 * push - this function push an node
 * to a stack
 *
 * @head: the head of the link
 * @n: the data of the node
 * Description: This function adds node
 * to an existing stack.
 * Return: Nothing
 */
void push(stack_t **head, int n)
{
	stack_t *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = n;

/*In this case where the stack is empty!*/
	if (!(*head))
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		(*head) = newnode;
		return;
	}

/*What is the stack is not empty?*/
	newnode->prev = NULL;
	newnode->next = (*head);
	(*head) = newnode;
}
