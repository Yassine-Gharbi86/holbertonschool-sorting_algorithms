#include "sort.h"
/**
* swap_values - Swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/
void swap_values(int *a, int *b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}
/**
* selection_sort - Sort an array of integers in ascending order
* using the selection sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*/
void selection_sort(int *array, size_t size)
{
int *min_value;
size_t i, j;
if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++)
{
min_value = array + i;
for (j = i + 1; j < size; j++)
min_value = (array[j] < *min_value) ? (array + j) : min_value;
if ((array + i) != min_value)
{
swap_values(array + i, min_value);
print_array(array, size);
}
}
}
