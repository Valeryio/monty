#include "monty.h"
void opcode_interpreter(char **argv, int line_number)
{
        func_linked *head;
        char *op;
        int n;
	func_linked *current;

        op = argv[0];
        if (argv[1] == NULL)
                n = 0;
        else
                n = atoi(argv[1]);
	head = func_list();
	current = head;
        while (current)
        {
                if (strcmp(current->instruction->opcode, op) == 0)
                {
                        if (strcmp(current->instruction->opcode, "push")== 0)
                        {
                                current->instruction->f(&stack, n);
                                return;
                        }
                        else
                        {
                                current->instruction->f(&stack, line_number);
                                return;
                        }
                }
                current = current->link;
        }
}
