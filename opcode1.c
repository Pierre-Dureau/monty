#include "monty.h"

/**
 * @brief
 *
 * @param stack
 * @param line_number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;

	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
	(void)line_number;
}

/**
 * @brief
 *
 * @param stack
 * @param line_number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	}

	printf("%d\n", (*stack)->n);
}
