#include "monty.h"
stack_t *stack = NULL;

/**
 * main - Entry point to the program.
 * @argc: Numeber of arguments during runtime.
 * @argv: array of string of arguments.
 * Return: End of the program.
 */
int main(int argc, char *argv[])
{
        int i;
        char *full_command = NULL;
        size_t size;
        size_t len;
        FILE *file;


        if (argc != 2)
        {
                printf("USAGE: monty file");
                exit(EXIT_FAILURE);
        }
        file = fopen(argv[1], "r");
        while((len = getline(&full_command, &size, file)) != -1)
        {
                for (i = 0; full_command[i] != '\n'; i++)
                        ;
                full_command[i] = '\0';
                arguments(full_command);
        }
        return (0);
}
void arguments(char *full_command)
{
        int i;
        char **argv;
        char *each;
        char *separator;

        separator = " ";
        argv = malloc(sizeof(each) * 2);
        each = strtok(full_command, separator);
        i = 0;
        while (each)
        {
                argv[i] = each;
                each = strtok(NULL, separator);
                i++;
        }
        opcode_interpreter(argv);
        free(argv);
}
void opcode_interpreter(char **argv)
{
        func_linked *head;
        char *op;
        int n;

        op = argv[0];
        n = atoi(argv[1]);
        head = func_list();
        func_linked *current = head;
        while (current)
        {
                if (strcmp(current->instruction->opcode, op) == 0)
                {
			current->instruction->f(&stack, n);
                        return;
                }
                current = current->link;
        }
}
/**
 * func_list - Creates a linked list of available functions.
 *
 * Return: Pointer to the head of the linked list.
 */
func_linked *func_list()
{
	func_linked *head = NULL;
	void (*func[])(stack_t **stack, unsigned int line_number) = {pus, pal, pin, po, swa, add, no};
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};
	int num_functions = sizeof(func) / sizeof(func[0]);
	
	for (int i = 0; i < num_functions; i++)
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
			newNode->instruction->opcode = strdup(opcodes[i]); 
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

// Function definitions
void pus(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}
void pal(stack_t **stack, unsigned int line_number)
{
	printf("Stack contents: ");
	while ((*stack) != NULL)
	{
		printf("%d ", (*stack)->n);
		(*stack) = (*stack)->next;
	}
	printf("\n");
}

void pin(stack_t **stack, unsigned int line_number)
{
    printf("Function: pin, Line number: %d\n", line_number);
}

void po(stack_t **stack, unsigned int line_number)
{
	printf("Function: po, Line number: %d\n", line_number);
}

void swa(stack_t **stack, unsigned int line_number)
{
	printf("Function: swa, Line number: %d\n", line_number);
}

void add(stack_t **stack, unsigned int line_number)
{
	printf("Function: add, Line number: %d\n", line_number);
}

void no(stack_t **stack, unsigned int line_number)
{
	printf("Function: no, Line number: %d\n", line_number);
}
