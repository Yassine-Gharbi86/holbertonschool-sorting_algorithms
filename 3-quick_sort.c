#include "sort.h"
/**
* swap_ints - Swap two integers in an array.
* @first: The first integer to swap.
* @second: The second integer to swap.
* Return: void.
*/
void swap_ints(int *first, int *second)
{
int temp;
temp = *first;
*first = *second;
*second = temp;
}
/**
* partition_array - Partition the array using the pivot.
* @array: The array to be partitioned.
* @start: The starting index of the array.
* @end: The ending index of the array.
* @size: The size of the array.
* Return: The index of the pivot.
*/
int partition_array(int *array, int start, int end, size_t size)
{
int pivot = array[end];
int index = start - 1;
int current;
for (current = start; current <= end; current++)
{
if (array[current] <= pivot)
{
index++;
if (index != current)
{
swap_ints(&array[index], &array[current]);
print_array(array, size);
}
}
}
return (index);
}
/**
* lomuto_quick_sort - Recursively sorts the array using Lomuto partition.
* @array: The array to be sorted.
* @start: The starting index of the array.
* @end: The ending index of the array.
* @size: The size of the array.
* Return: void.
*/
void lomuto_quick_sort(int *array, int start, int end, size_t size)
{
int pivot_index;
if (start < end)
{
pivot_index = partition_array(array, start, end, size);
lomuto_quick_sort(array, start, pivot_index - 1, size);
lomuto_quick_sort(array, pivot_index + 1, end, size);
}
}
/**
* quick_sort - Sorts an array of integers using the Quick sort algorithm
*             with Lomuto partition scheme.
* @array: The array to sort.
* @size: The size of the array.
* Return: void.
*/
void quick_sort(int *array, size_t size)
{
lomuto_quick_sort(array, 0, size - 1, size);
}
