#include "sort.h"
#include <stdio.h>
/**
 * swap - change two values in ascending or descending order
 * @arr: array
 * @a: item one
 * @b: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap(int arr[], int a, int b, int order)
{
	int temp;

	if (order == (arr[a] > arr[b]))
	{
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
}
/**
 * merge - Func that sort bitonic sequences recursively in both orders
 * @array: array to sort
 * @lw: first element
 * @nelemnt: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int array[], int lw, int nelemnt, int order)
{
	int mid, ind;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (ind = lw; ind < lw + mid; ind++)
			swap(array, ind, ind + mid, order);
		merge(array, lw, mid, order);
		merge(array, lw + mid, mid, order);
	}
}
/**
 * bitonicsort - implimentation of bitonic sort algorithm
 * @arr: array of integer to sort
 * @lw: first element
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array size
 */
void bitonicsort(int arr[], int lw, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[lw], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[lw], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, lw, mid, 1, size);
		bitonicsort(arr, lw + mid, mid, 0, size);
		merge(arr, lw, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[lw], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[lw], nelemnt);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
