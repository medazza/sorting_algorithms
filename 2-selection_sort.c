#include "sort.h"
/**
 * selection_sort - function that sorts an array using
 *                  selection sort algorithm.
 * @size: The size of the array
 * @array: list with numbers to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int k, temp, flag = 0;

	if (!array || !size)
		return;
	for (i = 0; i < size; i++)
	{
		k = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[k] > array[j])
			{
				k = j;
				flag += 1;
			}
		}
		temp = array[i];
		array[i] = array[k];
		array[k] = temp;
		if (flag != 0)
			print_array(array, size);
	}
}
