#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t linked list.
 *
 * @head: Double pointer to the head of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	// If the node to be deleted is the head
	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
		free(current);
		return (1);
	}

	// Traverse the list to find the node to delete
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	// If the node to delete is not found
	if (current == NULL)
		return (-1);

	// If the node to be deleted is not the head
	if (current->next != NULL)
		current->next->prev = current->prev;

	if (current->prev != NULL)
		current->prev->next = current->next;

	free(current);
	return (1);
}
