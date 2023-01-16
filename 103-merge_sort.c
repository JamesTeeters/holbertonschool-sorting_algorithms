#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the top-down merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
    if (size < 2 || !array)
        return;
    else
        merge_sort_recursion(array, 0, size - 1);
}

/**
 * merge_sort_recursion - Recursively calls the merge sort function
 * until all arrays are sorted
 * @array: pointer to the array
 * @l: left-most (first) index of the array
 * @r: right-most (last) index of the array
 * Return: void
 */
void merge_sort_recursion(int *array, int l, int r)
{
    if (r <= l)
        return;
    else
    {
        int m = l + (r - l) / 2;
        merge_sort_recursion(array, l, m);
        merge_sort_recursion(array, m + 1, r);
        merge_sorted_arrays(array, l, m, r);
        print_array_status("Done", &array[l], (r - l + 1));
    }
}

/**
 * merge_sorted_arrays - this is the function that applies the merge
 * sort algorithm on each iteration
 * @array: The address of the array being sorted
 * @l: left-most (first) index of the array
 * @m: the break point of the array being sorted
 * @r: right-most (last) index of the array
 * Return: void
 */
void merge_sorted_arrays(int *array, int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    int tmp_left[left_length];
    int tmp_right[right_length];
    int i, j, k;

    printf("Merging...\n");
    for (int i = 0; i < left_length; i++)
        tmp_left[i] = array[l + i];
    print_array_status("left", &array[l], left_length);

    for(int i = 0; i < right_length; i++)
        tmp_right[i] = array[m + 1 + i];
    print_array_status("right", &array[m + 1], right_length);

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if ((i < left_length && j >= right_length) || tmp_left[i] <= tmp_right[j])
        {
            array[k] = tmp_left[i];
            i++;
        }
        else
        {
            array[k] = tmp_right[j];
            j++;
        }
    }  
}

/**
 * print_array_status - prints the current status of the sorting
 * @status: left, right, or done
 * @array: the array to print
 * @size: how many array elements to print
 * Return: void
 */
void print_array_status(char *status, int *array, int size)
{
    printf("[%s]: ", status);
    print_array(array, size);
}