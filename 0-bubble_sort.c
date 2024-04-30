#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 *
 * array: is the array of integers to sort.
 * size: is the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
			return;
	}
}
