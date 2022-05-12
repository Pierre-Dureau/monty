#include "monty.h"

/**
 * main - Read Monty byte code files
 *
 * @ac: Number of arguments
 * @av: Arguements
 * Return: 0
 */

int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(av[1], "r");
		if (!file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			exit(EXIT_FAILURE);
		}
		else
			start(file);
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * start - Get the lines of the file and do the instruction
 *
 * @file: Monty file with instructions
 */

void start(FILE *file)
{
	stack_t *head = NULL;
	char line[100], *token, *word;
	int ln = 0, value, sq = 0;
	void (*fnc)(stack_t **stack, unsigned int line_number);

	while (fgets(line, 100, file) != NULL)
	{
		ln++;
		if (line[0] != '\n')
		{
			token = strtok(line, " \n");
			if (*token == '#')
				continue;
			if (token)
				word = token;
			else
				continue;
			if (CheckStackQueue(&sq, word) == 1)
				continue;
			if (strcmp(word, "push") == 0)
			{
				value = push(&head, ln, token);
				if (sq == 0)
					add_dnodeint(&head, value);
				else
					add_dnodeint_end(&head, value);
			}
			else
			{
				fnc = get_instruction(word);
				if (fnc)
					fnc(&head, ln);
				else
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", ln, word);
					handle_exit(head);
				}
			}
		}
	}
	free_dlistint(head);
}

/**
 * CheckStackQueue - Check if the instruction is stack or queue
 *
 * @sq: Int for check
 * @word: The instruction
 * Return: 1 if success
 */

int CheckStackQueue(int *sq, char *word)
{
	if (strcmp(word, "queue") == 0 || strcmp(word, "stack") == 0)
	{
		if (strcmp(word, "queue") == 0)
			*sq = 1;
		else
			*sq = 0;
		return (1);
	}
	return (0);
}

/**
 * handle_exit - When an error happened
 *
 * @stack: The list
 */

void handle_exit(stack_t *stack)
{
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
