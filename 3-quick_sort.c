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
	if (array == NULL || size < 2)
		return;
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

	if (high - low > 0)
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
	int *pivot, i, j;
	int temp;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}
