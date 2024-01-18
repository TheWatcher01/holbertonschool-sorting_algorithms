#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: Array of integers.
 * @i: Index of first element.
 * @j: Index of second element.
 */
void swap(int *array, size_t i, size_t j)
{
	/* Store value at index i */
	int temp = array[i];
	/* Assign value at index j to index i */
	array[i] = array[j];
	/* Assign stored value to index j */
	array[j] = temp;
}

/**
 * bubble_sort - Sorts an array of integers using Bubble sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of array.
 *
 * Description: If array is null or size is less than 2, function returns.
 * Iterates over array, swapping adjacent elements if they are in wrong order.
 * Iteration continues until no more swaps are made.
 */
void bubble_sort(int *array, size_t size)
{
	/* Loop counter */
	size_t i;
	/* Flag to check if swap occurred */
	int swapped;

	/* Return if array is null or size is less than 2 */
	if (!array || size < 2)
		return;

	/* Repeat until no more swaps are made */
	do
	{
		/* Reset swapped flag */
		swapped = 0;

		/* Loop through array */
		for (i = 0; i < size - 1; i++)
		{
			/* If current element is less than or equal to next one, continue to next iteration */
			if (array[i] <= array[i + 1])
				continue;

			/* Swap elements */
			swap(array, i, i + 1);
			/* Set swapped flag to 1 */
			swapped = 1;
			/* Print array after swap */
			print_array(array, size);
		}
		/* Continue if a swap was made */
	} while (swapped);
}
