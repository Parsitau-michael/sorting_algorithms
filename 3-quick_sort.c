#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 *
 * @array: is the array of integers.
 * @size: is the number of integers in the array.
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - a function that is called recursively to implement
 * the quick sort.
 *
 * @array: is the array of integers.
 * @low: is the low index.
 * @high: is the high index.
 * @size: is the number of integers in the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * partition - a function that returns the position of the pivot element.
 *
 * @array: is the array of integers.
 * @low: is the low index.
 * @high: is the high index.
 * @size: is the number of integers in the array.
 * Return: the position of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot_val = array[high];
	int j, i = low - 1;
	int temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_val)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	return (i + 1);
}
