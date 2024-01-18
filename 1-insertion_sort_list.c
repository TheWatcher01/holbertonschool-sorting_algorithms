#include "sort.h"

/**
 * move_node - Moves a node to its correct position in list.
 * @list: Pointer to doubly linked list.
 * @node: Node to be moved.
 *
 * Description:
 * Detaches node from current position and inserts it before
 * previous node. If node is now first node, list pointer is updated.
 */
static void move_node(listint_t **list, listint_t *node)
{
	/* Detach node from list by setting next of previous to next of current */
	node->prev->next = node->next;
	/* If current node has a next, set its previous to previous of current */
	if (node->next)
		node->next->prev = node->prev;

	/* Insert node before previous by setting next of current to previous */
	node->next = node->prev;
	/* Set previous of current to previous of new next */
	node->prev = node->next->prev;
	/* Set previous of new next to current */
	node->next->prev = node;

	/* If node is now first, update list pointer */
	if (!node->prev)
		*list = node;
	/* Otherwise, set next of new previous to current */
	else
		node->prev->next = node;
}

/**
 * detach_node - Detaches a node from list.
 * @node: Node to be detached.
 *
 * Description: Detaches node from list by setting next of previous to next of
 *              current. If current node has a next, its previous is set to
 *              previous of current.
 */
static void detach_node(listint_t *node)
{
	/* Detach node from list by setting next of previous to next of current */
	node->prev->next = node->next;
	/* If current node has a next, set its previous to previous of current */
	if (node->next)
		node->next->prev = node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                       Insertion sort algorithm.
 * @list: Pointer to doubly linked list to be sorted.
 *
 * Description: If list is null, empty, or has only one node, function returns
 *              without making changes. Function iterates over list, inserting
 *              each node at its correct position in sorted part of list.
 *
 * Return: This function does not return a value.
 */
void insertion_sort_list(listint_t **list)
{
	/* Declare pointers for current node and a temp node */
	listint_t *current, *temp;

	/* If list is null, empty, or has only one node, return */
	if (!list || !*list || !(*list)->next)
		return;

	/* Loop through list, starting from second node */
	for (current = (*list)->next; current; current = temp)
	{
		/* Store next node in a temp variable */
		temp = current->next;

		/* While current node is less than previous node */
		while (current->prev && current->prev->n > current->n)
		{
			/* Detach current node from list */
			detach_node(current);

			/* Move current node to its correct position */
			move_node(list, current);

			/* Print list after insertion */
			print_list(*list);
		}
	}
}

