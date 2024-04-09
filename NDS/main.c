#include "monty.h"
#define MAX_LENGTH 2048

stack_t *montystack = NULL;
char **montyline_args = NULL;

/**
 * main - compile monty code
 * @argc: the number of args
 * @argv: different args
 *
 * Description: This function interpret monty code and
 * Return: An integer
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 1;
	FILE *myfile = NULL;
	stack_t *head = NULL;
	char instructionstring[2048] = "";

	/*Verifing if the program have been well used as : monty <file> */
	if (argc <= 1 || argc > 2)
	{
		UsageFileError();
	}

/*Try to open the file*/
	myfile = fopen(argv[1], "r");
	if (!myfile)
	{
		OpenFileError(argv[1]);
	}

/*Getting each line of the file, get the variables, and use them*/
	while (fgets(instructionstring, MAX_LENGTH, myfile))
	{
		getArguments(instructionstring);
		printf("Et bien on a : %s et %s sur cette ligne !\n", montyline_args[0], montyline_args[1]);
/*		montyline_args = getArguments(instructionstring);*/
/*Continue if we're dealing with empty lines*/
		if (getNumberOfArgs() == 0)
		{
		printf("Et bien on a : %s et %s sur cette ligne !\n", montyline_args[0], montyline_args[1]);
			line_number++;
			printf("La ligne est vide\n");
			continue;
		}
		printf("Eya: %s et %s sur cette ligne !\n", montyline_args[0], montyline_args[1]);
/*Verification of the validity of the opcode*/
		isValidArgument(&head, line_number);

		printf("AFTER VALIDATION : %s et %s sur cette ligne !\n", montyline_args[0], montyline_args[1]);
		printf("La ligne n'est pas vide, alors, continuons !\n");
		executeLineInstruction(&head, line_number);
		line_number++;
		printf("Eya: %s et %s, ligne suivante\n", montyline_args[0], montyline_args[1]);
	}

	fclose(myfile);
	freeStack(&head);

	for (line_number = 0; (int)line_number < getNumberOfArgs(); line_number++)
		free(montyline_args[line_number]);

	if (!head)
		printf("Et bien, ma staack est vide !");

	return (0);
}
