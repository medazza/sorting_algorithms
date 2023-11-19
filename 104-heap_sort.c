#include "sort.h"

/**
 * swap - Function to swap to integers
 * @a: first integer a
 * @b: second integer b
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - makes heap in place.
 * @array: array to be sorted
 * @size: size of the array
 * @ind: index of the subtree
 * @len: size of the heap
 */

void heapify(int *array, size_t size, int ind, size_t len)
{
	int max = ind;
	int left = 2 * ind + 1;
	int right = 2 * ind + 2;

	if (left < (int)len && array[left] > array[max])
		max = left;

	if (right < (int)len && array[right] > array[max])
		max = right;

	if (max != ind)
	{
		swap(&array[ind], &array[max]);
		print_array(array, size);
		heapify(array, size, max, len);
	}
}

/**
 * heap_sort - heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array.
 */

void heap_sort(int *array, size_t size)
{
	int ind;

	if (!array || size < 2)
		return;
	for (ind = size / 2 - 1; ind >= 0; ind--)
		heapify(array, size, ind, size);
	for (ind = size - 1; ind > 0; ind--)
	{
		swap(&array[0], &array[ind]);
		print_array(array, size);
		heapify(array, size, 0, ind);
	}
}
