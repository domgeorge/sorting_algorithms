#include "sort.h"

void _swp(int *a, int *b);
void heap(int *array, size_t size, size_t end, size_t root);
void heap_sort(int *array, size_t size);

/**
 * _swp - Swaps two integers in memory
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void _swp(int *a, int *b)
{
	int element;

	element = *a;
	*a = *b;
	*b = element;
}

/**
 * heap - Converts array of integers into a binary heap.
 * @array: An array of integers.
 * @size: The size of the array.
 * @end: The index of the current node.
 * @root: The root node of the current node.
 */
void heap(int *array, size_t size, size_t end, size_t root)
{
	size_t left, right, big;

	left = 2 * root + 1;
	right = 2 * root + 2;
	big = root;

	if (left < end && array[left] > array[big])
		big = left;
	if (right < end && array[right] > array[big])
		big = right;

	if (big != root)
	{
		_swp(array + root, array + big);
		print_array(array, size);
		heap(array, size, end, big);
	}
}

/**
 * heap_sort - Sorts array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		_swp(array, array + i);
		print_array(array, size);
		heap(array, size, i, 0);
	}
}
