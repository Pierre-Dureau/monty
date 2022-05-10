#include "monty.h"

/**
 * add_dnodeint - Add node at the start of a dl list
 *
 * @head: Head of the list
 * @n: Value
 * Return: Address of the new node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - Add node at the end of a dl list
 *
 * @head: Head of the list
 * @n: Value
 * Return: Address of the new node
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *t;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		t = *head;
		while (t->next)
			t = t->next;
		new->prev = t;
		t->next = new;
	}

	return (new);
}
