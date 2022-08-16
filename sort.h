#ifndef SORT_H
#define SORT_H
/*end of include guard*/

#include <stdio.h>
#include <stdlib.h>
/*end of library calls*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
/*end of structs*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int* xp, int* yp);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
/*end of prototype functions*/

#endif /*SORT_H*/
