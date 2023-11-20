#include "sort.h"
/**
* swap - the positions of two elements into an array
* @array: array of integer
* @a: array element
* @b: array element
*/
void swap(int *array, ssize_t a, ssize_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 *hoare_partition - implementation hoare partition sorting scheme
 *@array: array of integer
 *@low: first array element
 *@high: last array element
 *@size: size of array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int low, int high, int size)
{
	int current = low - 1, finder = high + 1;
	int pivot = array[high];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@low: first array element
 *@high: last array element
 *@size: size of array
 */
void qs(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t position = 0;

	if (low < high)
	{
		position = hoare_partition(array, low, high, size);
		qs(array, low, position - 1, size);
		qs(array, position, high, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array of integer to sort
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
