#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: If the array is null or the size is less than 2, the function
 *              returns without making any changes. The function iterates over
 *              the array repeatedly, swapping adjacent elements if they are in
 *              wrong order. Iteration continues until no more swaps are made.
 *
 * Return: This function does not return a value.
 */
void bubble_sort(int *array, size_t size)
{
	/* Declare variables for the loop index, temporary storage, and swap flag */
	size_t i;
	int temp, swapped;

	/* If the array is null or the size is less than 2, return */
	if (!array || size < 2)
		return;

	/* Repeat until no more swaps are made */
	do {
		/* Reset the swapped flag */
		swapped = 0;

		/* Loop through the array */
		for (i = 0; i < size - 1; i++)
		{
			/* If the current element is greater than the next one */
			if (array[i] > array[i + 1])
			{
				/* Swap the elements */
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				/* Set the swapped flag to 1 */
				swapped = 1;

				/* Print the array after the swap */
				print_array(array, size);
			}
		}
		/* Continue if a swap was made */
	}

	while (swapped);
}
