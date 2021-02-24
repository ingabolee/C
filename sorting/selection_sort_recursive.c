/**
 * @file
 * @author [Dhruv Pasricha](https://github.com/DhruvPasricha)
 * @brief [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)
 * implementation using recursion.
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Swapped two numbers using pointer
 * @param first pointer of first number
 * @param second pointer of second number
 */
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * @brief returned the index having minimum value using recursion
 * @param arr array to be sorted
 * @param size size of array
 * @return min_index index of element having minimum value.
*/
int findIndex(const int *arr, const int size)
{
    if (size == 1)
    {
        return 0;
    }

    // marking recursive call to reach starting element
    int min_index = findIndex(arr, size - 1);

    if (arr[size - 1] < arr[min_index])
    {
        min_index = size - 1;
    }

    return min_index;
}

/**
 * @brief Selection Sort algorithm implemented using recursion
 * @param arr array to be sorted
 * @param size size of array
 */
void selectionSort(int *arr, const int size)
{
    if (size == 1)
    {
        return;
    }

    /* findIndex(arr, size) returned the index having min value*/
    int min_index = findIndex(arr, size);
    /* arr[min_index] is the minimum value in the array*/

    if (min_index != 0)
    {
        swap(&arr[0], &arr[min_index]);
    }

    /*sorted the remaining array recursively*/
    selectionSort(arr + 1, size - 1);
}

/**
 * Test function
 */
void test()
{
    const int size = 10;
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    selectionSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

/** Driver Code */
int main()
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();
    return 0;
}
