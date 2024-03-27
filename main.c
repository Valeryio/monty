#include "monty.h"
#define MAX_LENGTH 16

int main(int argc, char* argv[])
{
	int givennumber;
	FILE *myfile = NULL;
	char *filename = NULL, montyinstructionstring[16] = "", opcode[18];
	stack_t** montyds = NULL;

/*Verifing if the program have been well used like the prototype 
 * said : monty <file> 
 **/
	if (argc <= 1 || argc > 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
/*
 * Getting the name of the file tohave a better code readibility than just
 * write with an incomprehensible name of variable! @filename is better than
 * argv[1]!
 **/
	filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	if (!filename)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy(filename, argv[1]);
	filename[strlen(argv[1])] = '\0';

	printf("Voici le nom du fichier : %s\n", filename);

/*
 * Try to open the file
 */
	myfile = fopen(filename, "r");

	if (!myfile)
	{
		printf("Error, Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	printf("LE fichie est ouvert han !\n");

//	while (fscanf(myfile, "%s %d", &montyinstruction, &numbergiven) == 2)
//	printf("Nous avons : %s qui prend : %d\n", montyinstruction, numbergiven);

	while (fgets(montyinstructionstring, MAX_LENGTH, myfile))
	{
		sscanf(montyinstructionstring, "%s %d", &opcode, &givennumber);
		printf("Instruction: %s | Value : %d\n", opcode, givennumber);
		
		get_instruction_func(opcode)(montyds, givennumber);
	}
	


	fclose(myfile);
	return (0);
}
