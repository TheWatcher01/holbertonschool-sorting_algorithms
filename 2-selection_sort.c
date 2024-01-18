#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: Array containing elements.
 * @i: Index of first element.
 * @j: Index of second element.
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * @array: Array to be sorted.
 * @size: Number of elements in array.
 *
 * Description: Uses the Selection sort algorithm.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(array, i, min_index);
			print_array(array, size);
		}
	}
}
