#include "monty.h"

/**
 * pchar - Print the char at the top of the stack
 *
 * @stack: A poipnter to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", (*stack)->n);
}

/**
 * pstr - Print the string starting at the top of the stack
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
