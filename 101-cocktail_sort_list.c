#include "sort.h"
/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @node1: first node
 * @node2: second node
 * @list: doubly linked list
 * Return: void
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *temp;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	temp = node2->prev;
	node2->prev = node1->prev;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = temp;
	print_list(*list);
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to sort
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
