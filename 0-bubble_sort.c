#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * This function uses the Bubble sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Return: This function does not return a value.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, swapped;

	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
