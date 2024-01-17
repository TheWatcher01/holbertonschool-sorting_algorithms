#include "sort.h"

/**
 * lomuto_partition - Partitions a portion of an array using the Lomuto
 *                    partition scheme.
 * @array: Pointer to the array of integers to be partitioned.
 * @low: The low index of the portion to be partitioned.
 * @high: The high index of the portion to be partitioned.
 * @size: The size of the array.
 *
 * Description: The function selects the element at the high index as pivot,
 *              then rearranges array so that all elements less than or equal
 *              to the pivot come before pivot, and all elements greater than
 *              the pivot come after it. Function returns the index of the
 *              pivot in the partitioned array.
 *
 * Return: The index of the pivot in the partitioned array.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	/* Declare variables for pivot, i: index of smaller element, y: loop index,*/
	/* and temporary storage for swap 2 array item */
	int pivot = array[high], i = (low - 1), j, temp;

	/* Loop through the array from the low index to the high index */
	for (j = low; j <= high - 1; j++)
	{
		/* If the current element is less than or equal to the pivot */
		if (array[j] <= pivot)
		{
			/* Increment the index of the smaller element */
			i++;
			/* Swap the current element with the element at index of smaller element */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			/* If current element is not at index of smaller element, print the array */
			if (i != j)
				print_array(array, size);
		}
	}
	/* Swap the element at the index of the smaller element plus one with pivot */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	/* If the pivot is not at index of smaller element plus one, print array */
	if (high != (i + 1))
		print_array(array, size);

	/* Return the index of the pivot */
	return (i + 1);
}


/**
 * quick_sort_helper - Helper function that sorts a portion of an array.
 * @array: Pointer to the array of integers to be sorted.
 * @low: The low index of the portion to be sorted.
 * @high: The high index of the portion to be sorted.
 * @size: The size of the array.
 *
 * Description: If the low index is less than the high index, the function
 *              selects a pivot using the Lomuto partition scheme, then
 *              recursively sorts the elements before and after the pivot.
 *
 * Return: This function does not return a value.
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	/* If the low index is less than the high index */
	if (low < high)
	{
		/* Select a pivot using the Lomuto partition scheme */
		int pivot = lomuto_partition(array, low, high, size);

		/* Recursively sort the elements before the pivot */
		quick_sort_helper(array, low, pivot - 1, size);
		/* Recursively sort the elements after the pivot */
		quick_sort_helper(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: If the array is null or the size of the array is less than 2,
 *              the function returns without making any changes. The function
 *              calls a helper function to sort the array.
 *
 * Return: This function does not return a value.
 */

void quick_sort(int *array, size_t size)
{
	/* If the array is null or the size of the array is less than 2, return */
	if (!array || size < 2)
		return;

	/* Declare variables for the low and high indices */
	int low = 0, high = size - 1;

	/* Call the helper function to sort the array */
	quick_sort_helper(array, low, high, size);
}
