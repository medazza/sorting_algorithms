#include "sort.h"

/**
 * bubble_sort - Func that sort array of elments using
 *               bubble sort algorithm.
 * @array: array of integers.
 * @size: The array size
 */

void bubble_sort(int *array, size_t size)
{

	size_t i, ind, temp = 0;

	if (!array || !size)
		return;
	for (i = 0; i < size; i++)
		for (ind = 0; ind < size; ind++)
		{
			if (array[ind] > array[ind + 1] && array[ind + 1])
			{
			temp = array[ind];
			array[ind] = array[ind + 1];
			array[ind + 1] = temp;
			print_array(array, size);
			}
		}
}
