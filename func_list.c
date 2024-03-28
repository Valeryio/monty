#include "monty.h"
/**
 * func_list - Creates a linked list of available functions.
 *
 * Return: Pointer to the head of the linked list.
 */
func_linked *func_list()
{
	int i;
        func_linked *head = NULL;
        void (*func[])(stack_t **stack, unsigned int line_number) = {pus, pal, pin, po, swa, add, no};
        char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};
        int num_functions = sizeof(func) / sizeof(func[0]);

        for (i = 0; i < num_functions; i++)
        {
                func_linked *current = head;
                int opcode_exists = 0;
                while (current != NULL)
                {
                        if (strcmp(current->instruction->opcode, opcodes[i]) == 0)
                                {
                                opcode_exists = 1;
                                break;
                        }
                        current = current->link;
                }
                if (!opcode_exists)
                {
                        func_linked *newNode = malloc(sizeof(func_linked));
                        if (newNode == NULL)
                        {
fprintf(stderr, "Memory allocation failed\n");
                                exit(EXIT_FAILURE);
                        }
                        newNode->instruction = malloc(sizeof(instruction_t));
                        if (newNode->instruction == NULL)
                        {
                                fprintf(stderr, "Memory allocation failed\n");
                                exit(EXIT_FAILURE);
                        }
                        newNode->instruction->opcode = _strdup(opcodes[i]);
                        newNode->instruction->f = func[i];
                        newNode->link = NULL;
                        if (head == NULL)
                                head = newNode;
                        else
                        {
                                func_linked *temp = head;
                                while (temp->link != NULL)
                                        temp = temp->link;
                                temp->link = newNode;
                        }
                }
        }
        return head;
}
