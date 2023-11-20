#include "sort.h"

/**
* getMax - Function that get maximum value in array
* @arr: array of integer
* @size: size of the array
* Return: array
*/

int getMax(int *arr, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * radixsort - function that sorts an array of integers
 * using the Radix sort algorithm
 * @array: Array to sort
 * @size: size of Array
 * @exp: digit of numbers in array
 * Return: void
 */
void radixsort(int *array, int size, int exp)
{
	int *output;
	int ind;
	int count[10] = {0};

	output = malloc(sizeof(int) * size);
	for (ind = 0; ind < size; ind++)
		count[(array[ind] / exp) % 10]++;
	for (ind = 1; ind < 10; ind++)
		count[ind] += count[ind - 1];
	for (ind = size - 1; ind >= 0; ind--)
	{
		output[count[(array[ind] / exp) % 10] - 1] = array[ind];
		count[(array[ind] / exp) % 10]--;
	}
	for (ind = 0; ind < size; ind++)
		array[ind] = output[ind];
	print_array(array, size);
	free(output);
}

/**
 * radix_sort - a function that sorts an array of integers
 * using the Radix sort algorithm
 * @array: Array to sort
 * @size: size of Array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int exp, max = getMax(array, size);

	if (!array || size < 2)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
		radixsort(array, size, exp);
}
