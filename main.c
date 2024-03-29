#include "monty.h"
#define MAX_LENGTH 2048

stack_t *montystack = NULL;
	
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
	char instructionstring[2048] = "";

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
		fprintf(stderr, "Error, Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

/*Getting each line of the file, get the variables, and use them*/
	while (fgets(instructionstring, MAX_LENGTH, myfile))
	{
		if (!line_checker(instructionstring, line_number))
			exit(EXIT_FAILURE);

		line_number++;
	}

	fclose(myfile);
	return (0);
}
