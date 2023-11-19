#include "sort.h"

/**
 * make_counting - make a counting array.
 * @max: the max value in array
 * @size: size of array
 * @array: array of integers to sort
 * Return: pointer to counting array
 */

int *make_counting(int max, int size, int *array)
{
	int *counter;
	int ind;

	counter = malloc(sizeof(int) * (max + 1));
	if (!counter)
		return (NULL);
	for (ind = 0; ind <= max; ind++)
		counter[ind] = 0;
	ind = 0;
	while (ind < size)
	{
		counter[array[ind]] += 1;
		ind++;
	}
	ind = 1;
	while (ind <= max)
	{
		counter[ind] = counter[ind] + counter[ind - 1];
		ind++;
	}
	return (counter);
}

/**
 * counting_sort - sort an array of integers using counting sort algorithm
 * @array: array of integers to sort
 * @size: size of array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sorted;
	int maximum, i, j;

	if (!array || !size)
		return;
	maximum = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}
	counter = make_counting(maximum, size, array);
	if (!counter)
		return;

	print_array(counter, maximum + 1);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(counter);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}
	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];
	free(counter);
	free(sorted);
}
