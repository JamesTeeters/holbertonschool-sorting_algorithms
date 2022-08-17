#include "sort.h"
/**
 * swap - swaps two pointers.
 * @xp: first pointer.
 * @yp:  second pointer.
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
 * selection_sort - function that uses selection sort.
 * @array: given array.
 * @size: size of array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idex;

	for (i = 0; i < size - 1; i++)
	{
		min_idex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idex])
				min_idex = j;
		}
			if (min_idex != i)
			{
				swap(&array[min_idex], &array[i]);
				print_array(array, size);
			}
	}
}
