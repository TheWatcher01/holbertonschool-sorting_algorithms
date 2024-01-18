#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: Array containing elements.
 * @i: Index of first element.
 * @j: Index of second element.
 */
void swap(int *array, size_t i, size_t j)
{
	/* Temporary variable stores value at index i */
	int temp = array[i];
	/* Value at index j assigned to index i */
	array[i] = array[j];
	/* Value stored in temporary variable assigned to index j */
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
	/* Variables for current index, inner loop index, and minimum value index */
	size_t i, j, min_index;

	/* Loop through each element in array except last one */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume current index is index of minimum value */
		min_index = i;
		/* Loop through rest of array */
		for (j = i + 1; j < size; j++)
		{
			/* If current element is less than assumed minimum, update minimum index */
			if (array[j] < array[min_index])
				min_index = j;
		}
		/* If minimum value is not at current index, swap and print array */
		if (min_index != i)
		{
			/* Swap the current element with the minimum element found */
			swap(array, i, min_index);
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
