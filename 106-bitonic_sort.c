#include "sort.h"

/**
 * r_op - function that prints a range of elem
 * @array: Array to print
 * @start: Start index
 * @end: End index
 */
void r_op(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * swp_element - Function that swaps two elem
 * @array: Array
 * @u: First element
 * @v: Second element
 * @way: path sorting
 */
void swp_element(int *array, int u, int v, int way)
{
	int element;

	if (way == (array[u] > array[v]))
	{
		element = array[u];
		array[u] = array[v];
		array[v] = element;
	}
}

/**
 * bit_m - Bitonic merge sequence
 * @array: Array to sort
 * @down: Starting index
 * @size: Size length
 * @path: Sorting path
 * @n: size of array
 */
void bit_m(int *array, int down, int size, int path, const int n)
{
	int i = down, j = size;

	if (size > 1)
	{
		j = size / 2;
		for (i = down; i < down + j; i++)
			swp_element(array, i, i + j, path);

		bit_m(array, down, j, path, n);
		bit_m(array, down + j, j, path, n);
	}
}

/**
 * sort_it - Function that recursively runs bitonic sort
 * @array: Array
 * @down: Starting index
 * @size: Size of length array
 * @path: Sorting direction
 * @n: Size of all array
 */
void sort_it(int *array, int down, int size, int path, const int n)
{
	int j = size;

	if (size > 1)
	{
		if (path == 1)
			printf("Merging [%d/%d] (UP):\n", size, n);
		if (path == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, n);
		r_op(array, down, down + j - 1);

		j = size / 2;
		sort_it(array, down, j, 1,  n);

		sort_it(array, down + j, j, 0, n);

		bit_m(array, down, size, path, n);
		if (path == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, n);
			r_op(array, down, down + 2 * j - 1);
		}
		if (path == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, n);
			r_op(array, down, down + 2 * j - 1);
		}
	}
}

/**
 * bitonic_sort - Function that runs bitonic sort algorithm
 * @array: Array
 * @size: Size
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int m = (int)size;

	if (size < 2 || !array)
		return;

	sort_it(array, 0, (int)size, up, m);
}
