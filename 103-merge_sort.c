#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @l: Index of the left subarray
 * @m: Index of the middle point
 * @r: Index of the right subarray
 * @size: Size of the array
 */
void merge(int *array, int l, int m, int r, size_t size)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* Create temp arrays */
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    /* Merge the temp arrays back into array[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    /* Free temp arrays */
    free(L);
    free(R);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int mid = size / 2;
    merge_sort(array, mid);
    merge_sort(array + mid, size - mid);
    merge(array, 0, mid - 1, size - 1, size);

    /* Print array after each merge step */
    printf("Merging...\n");
    print_array(array, size);
}
