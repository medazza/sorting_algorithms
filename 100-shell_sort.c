#include "sort.h"
/**
* swap - the positions of two elements into an array
* @array: array of integer to sort
* @a: array element
* @b: array element
*/
void swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 *              order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers to sort
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, ind = 0;

	if (!array || !size)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (ind = i; ind >= gap &&
			 (array[ind] < array[ind - gap]); ind -= gap)
				swap(array, ind, ind - gap);
		print_array(array, size);
		gap /= 3;
	}
}
