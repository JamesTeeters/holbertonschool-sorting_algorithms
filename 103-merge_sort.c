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
 * @left: left-most (first) index of the array
 * @right: right-most (last) index of the array
 * Return: void
 */
void merge_sort_recursion(int *array, int left, int right)
{
int mid = ((right - left - 1) / 2) + left;

if (right <= left)
    return;
else
{
    merge_sort_recursion(array, left, mid);
    merge_sort_recursion(array, mid + 1, right);
    merge_sorted_arrays(array, left, mid, right);
    print_array_status("Done", &array[left], (right - left + 1));
}
}

/**
 * merge_sorted_arrays - this is the function that applies the merge
 * sort algorithm on each iteration
 * @array: The address of the array being sorted
 * @left: left-most (first) index of the array
 * @mid: the break point of the array being sorted
 * @right: right-most (last) index of the array
 * Return: void
 */
void merge_sorted_arrays(int *array, int left, int mid, int right)
{
int left_length = mid - left + 1;
int right_length = right - mid;
int temp_left[4096], temp_right[4096];
int i, j, k;

printf("Merging...\n");
for (i = 0; i < left_length; i++)
        temp_left[i] = array[left + i];
print_array_status("left", &array[left], left_length);
for (i = 0; i < right_length; i++)
    temp_right[i] = array[mid + 1 + i];
print_array_status("right", &array[mid + 1], right_length);
i = 0, j = 0, k = left;
while (i < left_length && j < right_length)
{
    if (temp_left[i] <= temp_right[j])
    {
        array[k] = temp_left[i];
        i++;
    }
    else
    {
        array[k] = temp_right[j];
        j++;
    }
    k++;
}

while (i < left_length)
{
    array[k] = temp_left[i];
    i++;
    k++;
}

while (j < right_length)
{
    array[k] = temp_right[j];
    j++;
    k++;
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
