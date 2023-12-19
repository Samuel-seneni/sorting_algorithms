#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);

/**
 * cocktail_sort_list - Sort a list of integers using cocktail algorithms.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *t, *s;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (t = *list; t->next != NULL;)
		t = t->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (s = *list; s != t; s = s->next)
		{
			if (s->n > s->next->n)
			{
				swap_node_ahead(list, &t, &s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (s = s->prev; s != *list;
				s = s->prev)
		{
			if (s->n < s->prev->n)
			{
				swap_node_behind(list, &t, &s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
/**
 * swap_node_behind - Swap a node in doubly-linked with the node behind it.
 * @list: A pointer to the head of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the swapping node of the cocktail shaker.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * swap_node_ahead - Swap a nod in list of integers with the node ahead.
 * @list: A pointer to the head list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the swapping node of the cocktail shaker.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

