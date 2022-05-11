#include "monty.h"

/**
 * nop - Doesn't do anything
 *
 * @stack: A poipnter to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - Print the char at the top of the stack
 *
 * @stack: A poipnter to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		handle_exit(head);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		handle_exit(head);
	}
	else
	{
		putchar((*stack)->n);
		putchar('\n');
	}
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
