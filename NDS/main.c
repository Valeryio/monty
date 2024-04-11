#include "monty.h"
#define MAX_LENGTH 2048

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
	/*Continue if we're dealing with empty lines*/
		if (getNumberOfArgs() == 0)
		{
			line_number++;
			continue;
		}
		/*Verification of the validity of the opcode*/
		isValidArgument(&head);
		executeLineInstruction(&head, line_number);
		line_number++;
	}

	/*Freeing all the memory allocated*/
	fclose(myfile);
	freeStack(&head);
	for (line_number = 0; (int)line_number < getNumberOfArgs(); line_number++)
		free(montyline_args[line_number]);
	free(montyline_args);
	return (0);
}
