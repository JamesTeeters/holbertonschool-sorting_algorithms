#include "sort.h"
/**
 * swap - function that swaps two values
 * @xp: pointer x.
 * @yp: dpointer y.
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
 * bubble_sort - function that uses bubble sort.
 * @array: given array.
 * @size: size of array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
