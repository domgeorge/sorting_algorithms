#include "sort.h"

/**
 * counting_sort - Sorts array of integers using Counting Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size);
void counting_sort(int *array, size_t size)
{
	int max, *count, j, *output;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create an array count to store the count of each element */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize array count */
	for (j = 0; j <= max; j++)
		count[j] = 0;

	/* Populate array count with the count of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Convert count[i] to count[i] + count[i-1] */
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];

	/* Print array count */
	print_array(count, max + 1);

	/* Update original array with sorted values */
	output = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy sorted elements into original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];


	/* Free allocated memory */
	free(count);
	free(output);
}
