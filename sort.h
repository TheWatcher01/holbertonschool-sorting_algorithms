#ifndef _SORT_H_
#define _SORT_H_

/*_______________________Standards Libraries_______________________*/

#include <stdio.h>
#include <stdlib.h>

/*_______________________Structures Prototypes_______________________*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*_______________________Typedef Struct Prototypes_______________________*/



/*_______________________Functions  Prototypes_______________________*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/*____________________Functions Prototypes Advanced Task____________________*/



#endif /* _SORT_H_ */
