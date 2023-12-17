#include "sort.h"

/**
 * swap_nodes - Swap two nodes of doubly-linked list
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: The first node swap of the pointer
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers.
 * @list: A pointer to the head of a doubly-linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iteration, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iteration = (*list)->next; iteration != NULL; iteration = temp)
	{
		temp = iteration->next;
		insert = iteration->prev;
		while (insert != NULL && iteration->n < insert->n)
		{
			swap_nodes(list, &insert, iteration);
			print_list((const listint_t *)*list);
		}
	}
}
