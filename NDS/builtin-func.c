#include "monty.h"

/**
 * get_arguments - get the two arguments of monty code
 *
 * @line: a string
 *
 * Description: This function takes a string and save
 * the monty's code instruction from it. It stores each
 * arguments, the opcode and the number (or not) in an
 * array of character that is sent
 *
 * Return: An array of strings
 * -------------- -------------
 * | arguments[0] | *opcode   |
 * -------------- -------------
 * | arguments[1] | str(int)) |
 * -------------- -------------
 */
char **getArguments____isold(char *line)
{
	int i;
	char **arguments, *field, *separator;

	i = 0;
	separator = " \t\n";
	arguments = malloc(sizeof(field) * 2);
	field = strtok(line, separator);

	printf("BOn, voici le premier argument : %s\n", field);

/* When we get an empty line send a null*/
	if (!field)
		return (NULL);

	while (field)
	{
		arguments[i] = field;
		field = strtok(NULL, separator);
		i++;
	}
	return (arguments);
}

void getArguments(char *line)
{
	int i = 0, result = 0;
	char opcode[8], arg[2];

	printf("JE suis la et voici la taille %d\n", getNumberOfArgs());
	while (i < getNumberOfArgs())
	{
		printf("JE suis la by freeing \n");
		free(montyline_args[i]);
		i++;
	}

	printf("JE suis la apres le freeing\n");
	free(montyline_args);
	montyline_args = NULL;

	printf("JE suis la apres le  super freeing\n");
	result = sscanf(line, "%s %s", opcode, arg);

	printf("THe reesult %d\n", result);
	if (result == 1)
	{
		printf("JE suis la apres la lecture\n");
		montyline_args = (char **)malloc(1 * sizeof(char *));
		mallocError(&(montyline_args));
		montyline_args[0] = malloc(sizeof(char) * (strlen(opcode) + 1));
		
		strcpy(montyline_args[0], opcode);
		montyline_args[1] = NULL;
	}

	if (result == 2)
	{
		printf("JE suis la apres la lecture\n");
		montyline_args = (char **)malloc(2 * sizeof(char *));
		printf("J'essaie d'alloouoer de l'espace au double pointer\n");
		
		if (montyline_args == NULL)
		{
			printf("Error: malloc failed for double P");
			exit(EXIT_FAILURE);
		}
		/*mallocError(&(*montyline_args));
		*/printf("C'est reussi\n");

		montyline_args[0] = NULL;
		montyline_args[1] = NULL;
		printf("J'essaie d'alloouoer de l'espace a index 1\n");
		montyline_args[0] = malloc(sizeof(char) * (strlen(opcode) + 1));
		/*mallocError(montyline_args[0]);
		*/if (montyline_args[0] == NULL)
		{
			printf("Error: malloc failed for double P");
		printf("le fameux argument : %s\n", montyline_args[i]);
			exit(EXIT_FAILURE);
		}
		printf("C'est reussi\n");
		printf("J'essaie d'alloouoer de l'espace a index 2\n");
		montyline_args[1] = malloc(sizeof(char) * (strlen(arg) + 1));
	/*	mallocError(montyline_args[1]);
		*/if (montyline_args[1] == NULL)
		{
			printf("Error: malloc failed for double P");
			exit(EXIT_FAILURE);
		}
		printf("C'est reussi\n");

		strcpy(montyline_args[0], opcode);
		strcpy(montyline_args[1], arg);
/*		montyline_args[2] = NULL;
*/
		if (!montyline_args[2])	
			printf("LE dernier argument est bel et bien nul\n");
		printf("C'est bon la-----------------------\n");
/*		printf("Nous avons : %s %s\n", opcode, arg);
*/	}


}

/**
 * arg_detector - this function check if an argument exist
 * @str: the argument
 *
 * Description: 
 * Return: An integer
 */

int isValidArgument(stack_t **head, unsigned int line_number)
{
	int i = 0, known_arg = 0, result = 0;
	char *montyinstructions[] = {"push", "pall", "pint", "NULL"};

	printf("--------------JE SUIS LE VALIDATEUR------------\n");
	printf("le fameux argument : %s\n", montyline_args[i]);

	while (montyinstructions[i])
	{
		result = strcmp(montyinstructions[i], montyline_args[0]);
		printf("Le resultat : %d\n", result);
		/*if (strcmp(montyinstructions[i], montyline_args[0]) == 0)
*/		if (result == 0)
		{
			known_arg = 1;
			break;
		}
		i++;
	}

	printf("--------------PHASE DE VALIDATION 2 :------------\n");
	if (!known_arg)
	{
		printf("L%d: unkown instruction <%s>\n", line_number, montyline_args[0]);
		freeStack(&(*head));
		if ((*head))
			printf("La stack est non nulle !\n");
		custom_pall(&(*head));
		exit(EXIT_FAILURE);
	}

	printf("--------------JE SORS DU VALIDATEUR------------\n");
	return (0);
}

/**
 * numberofargs - count the number of args
 *
 * Description: This function counts the number of args in
 * a monty line datastructure (array of strings)
 * Return: An integer
 */

int getNumberOfArgs()
{
	int i = 0;

/*	printf("BOn, moi, je vais voir le nombre d'arguments!");
		printf("le fameux argument : %s\n", montyline_args[i]);
*/	if (montyline_args == NULL)
		return (0);
	printf("le fameux argument : %s\n", montyline_args[i]);
	printf("le fameux argument : %s\n", montyline_args[i + 1]);
	printf("le fameux argument : %s\n", montyline_args[i + 2]);
	while (montyline_args[i] != NULL)
	{
		i++;
	}
	printf("IL m'a envoye han, et je suis : %d\n", i);
	return (i);
}

/**
 * args_checker - check each arguments of a monty's line
 * @args: a array of args
 * @length: the length of the arrray
 *
 * Description: This function check each args of a line
 * and send its result
 * Return: 1 on success, 0 otherwise
 */

int args_checker(char *args[], int length)
{

/*	length = length - 1;
*/
	printf("JE suis la et ma taille est : %d\n", length);

/*Check for bad entry for push*/
	if (!strcmp(args[0], "push") && (length == 1))
		return (0);
	if (!strcmp(args[0], "push") && (atoi(args[1]) == 0))
		return (0);

/*Check for pall function*/
	if (!strcmp(args[0], "pall") && (args[1] != 0))
		return (0);

	return (1);
}
