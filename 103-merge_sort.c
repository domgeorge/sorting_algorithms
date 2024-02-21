#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * j_subarr - Func joins two subarray
 * @array: main array
 * @temp: temp array
 * @left: starting index
 * @mid: middle index
 * @right: ending index
 */
void j_subarr(int *array, int *temp, size_t left,
		size_t mid, size_t right);
void j_subarr(int *array, int *temp, size_t left,
		size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j < right)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	for (k = left; k < right; k++)
	{
		array[k] = temp[k];
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * j_sort - recursive function that runs merge sort
 * @array: main array
 * @tem: temporary array
 * @left: starting index
 * @right: ending index
 */
void j_sort(int *array, int *tem, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
	{
		return;
	}

	mid = left + (right - left) / 2;

	j_sort(array, tem, left, mid);
	j_sort(array, tem, mid, right);
	j_subarr(array, tem, left, mid, right);
}

/**
 * merge_sort - Function that initiates merge sort algorithm
 * @array: Array
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *element;

	if (array == NULL || size < 2)
	{
		return;
	}

	element = malloc(sizeof(*element) * size);
	if (element == NULL)
	{
		return;
	}

	j_sort(array, element, 0, size);

	free(element);
}
