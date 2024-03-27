#include "monty.h"

int main(void)
{
	int i = 0;
	stack_t *head = NULL;

	for(i = 0; i < 5; i++)
	{
		head = push(&head, i);
	}

	custom_pall(&head);

	pall(&head);

	return (0);
}
