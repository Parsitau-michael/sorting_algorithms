#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 *
 * @array: the array to sort.
 * @size: the size of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_pos;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_pos])
				min_pos = j;

		if (min_pos != i)
		{
			temp = array[i];
			array[i] = array[min_pos];
			array[min_pos] = temp;
			print_array(array, size);
		}
	}
}
