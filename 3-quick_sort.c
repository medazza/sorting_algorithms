#include "sort.h"
/**
 * swap - swap two integer value
 * @array: array of integer to sort
 * @a: address of 1-st value
 * @b: address of 2-nd value
 * Return: void
*/
void swap(int *array, ssize_t a, ssize_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - partitions the array.
 * @array: array of integer to sort
 * @lo: first array element
 * @hi: last array element
 * @size: size of the array.
 * Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int pivot = array[hi];
	ssize_t current = lo, finder;

	for (finder = lo; finder < hi; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[hi])
	{
		swap(array, current, hi);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - qucksort algorithm implementation via lomuto.
 *@array: array of integer to sort.
 *@lo: the low index
 *@hi: the high index
 *@size: size of the array.
 */
void qs(int *array, ssize_t lo, ssize_t hi, int size)
{
	ssize_t position = 0;


	if (lo < hi)
	{
		position = lomuto_partition(array, lo, hi, size);

		qs(array, lo, position - 1, size);
		qs(array, position + 1, hi, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	qs(array, 0, size - 1, size);
}
