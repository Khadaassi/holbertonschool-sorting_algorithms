#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	next = current->next;

	while (next != NULL)
	{
		prev = current;
		next = current->next;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev;
			current->prev = prev->prev;
			prev->next = current->next;
			current->next = prev;
			prev->prev = current;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			prev = current->prev;
		}
		current = next;
	}
}
