#include "sort.h"

/**
 * merge - compare merge.
 * @array: An array of integers to sort.
 * @temp: A temp_arr to store the sorted array.
 * @start: The low (start) index of the array.
 * @mid: The middle index of the array.
 * @stop: The high (stop) index of the array.
 */
void merge(int *array, int *temp, size_t start, size_t mid,
		size_t stop)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, stop - mid);

	for (i = start, j = mid; i < mid && j < stop; k++)
	{
		if (array[i] < array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}
	for (; i < mid; i++)
		temp[k++] = array[i];
	for (; j < stop; j++)
		temp[k++] = array[j];
	for (i = start, k = 0; i < stop; i++)
		array[i] = temp[k++];

	printf("[Done]: ");
	print_array(array + start, stop - start);
}

/**
 * merge_sort_recursive - merge top-down recursively.
 * @array: An array of integers to sort.
 * @temp: A temp_arr to store the sorted result.
 * @start: The start index of the array.
 * @stop: The stop index of the array.
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t stop)
{
	size_t mid;

	if (stop - start > 1)
	{
		mid = start + (stop - start) / 2;
		merge_sort_recursive(array, temp, start, mid);
		merge_sort_recursive(array, temp, mid, stop);
		merge(array, temp, start, mid, stop);
	}
}

/**
 * merge_sort - Sort an array by merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
