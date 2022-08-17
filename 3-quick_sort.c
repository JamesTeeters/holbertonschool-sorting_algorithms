#include "sort.h"
/**
 * swap - swaps 2 pointers.
 * @xp: pointer 1.
 * @yp: pointer 2.
 *
 * Return: Nothing.
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/**
 * partition - function that sorts elements around pivot.
 * @array: given array.
 * @low: start of index.
 * @high: end of index.i
 *
 * Return
 */
int partition(int *array, size_t low, size_t high)
{
	size_t pivot = array[high];
	size_t i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}
/**
 * quick_sort - function that uses quicksort.
 * @array: given array.
 * @size: size of array.
 *
 * Return: Nothing.
 */
void quick_sort(int array, size_t size)
{
	size_t low = 0, high = (sizeof(array) / sizeof(array[0]) - 1);

	if (low < high)
		size_t pi = partition(array, low, high);

	quickSort(array, low, pi - 1);
	quickSort(array, pi + 1, high);
	}
