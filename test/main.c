#include "monty.h"
#define MAX_LENGTH 16

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
	int givennumber;
	FILE *myfile = NULL;
	stack_t *montystack = NULL;
	char *filename = NULL, instructionstring[16] = "", opcode[18];

/*Verifing if the program have been well used as : monty <file> */
	if (argc <= 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	get_name(argv[1], &filename);

/*Try to open the file*/
	myfile = fopen(filename, "r");
	if (!myfile)
	{
		fprintf(stderr, "Error, Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

/*Getting each line of the file, get the variables, and use them*/
	while (fgets(instructionstring, MAX_LENGTH, myfile))
	{
		if (sscanf(instructionstring, "%s %d", (char *)&opcode, &givennumber) != 0)
			get_instruction_func(opcode)(&montystack, givennumber);
	}

	fclose(myfile);
	return (0);
}
