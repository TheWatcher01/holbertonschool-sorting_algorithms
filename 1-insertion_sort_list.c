#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list in ascending
 *                       order using the Insertion sort algorithm.
 * @list: Pointer to the doubly linked list to be sorted.
 *
 * Description: If the list is null, or the list is empty, or the list has only
 *              one node, the function returns without making any changes. The
 *              function iterates over the list, inserting each node at its
 *              correct position in the sorted part of the list.
 *
 * Return: This function does not return a value.
 */
void insertion_sort_list(listint_t **list)
{
	/* Declare pointers for the current node and a temporary node */
	listint_t *current, *temp;

	/* If list is null, or list is empty, or the list has only one node, return */
	if (!list || !*list || !(*list)->next)
		return;

	/* Loop through the list, starting from the second node */
	for (current = (*list)->next; current; current = temp)
	{
		/* Store the next node in a temporary variable */
		temp = current->next;

		/* While the current node is less than the previous node */
		while (current->prev && current->prev->n > current->n)
		{
			/* Detach the current node from the list */
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			/* Insert the current node before the previous node */
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;

			/* If the current node is now the first node, update the list pointer */
			if (!current->prev)
				*list = current;
			else
				current->prev->next = current;

			/* Print the list after the insertion */
			print_list(*list);
		}
	}
}
