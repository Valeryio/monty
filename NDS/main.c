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
	/*int i = 0;*/
	unsigned int line_number = 1, arg_number = 0, right_arg = 0;
	FILE *myfile = NULL;
	/*stack_t *head = NULL;*/
	char instructionstring[2048] = ""/*, **line_arguments = NULL*/;
/*	instruction_t montyinstructions[] = {{"push", f_push}, {"pall", f_pall}, {"NULL", NULL}};
*/
/*Verifing if the program have been well used as : monty <file> */
	if (argc <= 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

/*Try to open the file*/
	myfile = fopen(argv[1], "r");
	if (!myfile)
	{
		fprintf(stderr, "Error Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

/*Getting each line of the file, get the variables, and use them*/
	while (fgets(instructionstring, MAX_LENGTH, myfile))
	{
		montyline_args = getArguments(instructionstring);
		arg_number = getNumberOfArgs();
/*Continue if we're dealing with empty lines*/
		if (arg_number == 0)
		{
			line_number++;
			printf("La ligne est vide\n");
			continue;
		}
/*Verification of the validity of the opcode*/
		right_arg = isValidArgument();

		if (!right_arg)
		{
			printf("L<%d>: unknown instruction <%s>\n", line_number, montyline_args[0]);
			exit(EXIT_FAILURE);
		}

		if (arg_number == 2)
			printf("Le nombre d'argument sur cette ligne est : %d et %d\n", right_arg, arg_number);
		else if (arg_number == 1)
			printf("IL n'y a qu'un seul argument sur la liste %s\n", montyline_args[0]);
/*Verify if the right argument exist*/
/*
		if (!right_arg)
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, line_arguments[0]);
			exit(EXIT_FAILURE);
		}
		montyinstructions[i].f(&head, line_number);
		line_number++;*/
	}

	fclose(myfile);
	return (0);
}
