#include "monty.h"

/**
 * get_instruction - Check if the instruction exists
 *
 * @word: The instruction
 * Return: The correct function
 */

void (*get_instruction(char *word))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t function[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp(function[i].opcode, word) == 0)
		{
			return (function[i].f);
		}
	}
	return (NULL);
}
