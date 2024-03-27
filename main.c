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
	char *filename = NULL, montyinstructionstring[16] = "", opcode[18];

/*Verifing if the program have been well used as : monty <file> */
	if (argc <= 1 || argc > 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	get_name(argv[1], &filename);


/*Try to open the file*/
	myfile = fopen(filename, "r");
	if (!myfile)
	{
		printf("Error, Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	printf("Hey, the file is open right NOW !\n");


/*Getting each name of the file, get the variables, and use them*/
	while (fgets(montyinstructionstring, MAX_LENGTH, myfile))
	{
		if (sscanf(montyinstructionstring, "%s %d", &opcode, &givennumber) != 0)
			get_instruction_func(opcode)(&montystack, givennumber);
	}

	fclose(myfile);
	return (0);
}
