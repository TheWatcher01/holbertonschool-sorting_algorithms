#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * This function uses the Selection sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Return: This function does not return a value.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

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
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
