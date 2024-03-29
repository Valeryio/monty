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
/*	int givennumber ;*/
	unsigned int line_number = 1;
	FILE *myfile = NULL;
	char instructionstring[2048] = "";
/*	stack_t *montystack = NULL;
	char instructionstring[2048] = "", opcode[18];
*/

/*Verifing if the program have been well used as : monty <file> */
	if (argc <= 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	if (montystack != NULL)
		printf("YES NOT NULL!");

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
/*		if (sscanf(instructionstring, "%s %d", (char *)&opcode, &givennumber) != 0)
			get_instruction_func(opcode)(&montystack, givennumber);
*/
		line_checker(instructionstring, line_number);
		line_number++;
	}

	fclose(myfile);
	return (0);
}
