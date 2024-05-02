#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm.
 *
 * @list: a doubly linked list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node;
	listint_t *prev_node;

	if (*list == NULL || (*list)->next == NULL)
		return;

	curr_node = (*list)->next;

	while (curr_node != NULL)
	{
		prev_node = curr_node->prev;

		while (prev_node != NULL && prev_node->n > curr_node->n)
		{
			/* swap nodes */
			if (prev_node->prev != NULL)
				prev_node->prev->next = curr_node;
			else
				*list = curr_node;

			if (curr_node->next != NULL)
				curr_node->next->prev = prev_node;

			prev_node->next = curr_node->next;
			curr_node->prev = prev_node->prev;
			curr_node->next = prev_node;
			prev_node->prev = curr_node;

			print_list(*list);

			if (curr_node->prev != NULL)
				prev_node = curr_node->prev;
			else
				return;
		}
		curr_node = curr_node->next;
	}
}
