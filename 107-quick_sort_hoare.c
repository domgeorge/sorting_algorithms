#include "sort.h"

void _swp(int *a, int *b);
int _split(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * _swp - Swaps two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void _swp(int *a, int *b)
{
	int tm;

	tm = *a;
	*a = *b;
	*b = tm;
}

/**
 * _split - Order for subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int _split(int *array, size_t size, int left, int right)
{
	int rot, top, bottom;

	rot = array[right];
	for (top = left - 1, bottom = right + 1; top < bottom;)
	{
		do {
			top++;
		} while (array[top] < rot);
		do {
			bottom--;
		} while (array[bottom] > rot);

		if (top < bottom)
		{
			_swp(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * h_sort - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void h_sort(int *array, size_t size, int left, int right)
{
	int qsort;

	if (right - left > 0)
	{
		qsort = _split(array, size, left, right);
		h_sort(array, size, left, qsort - 1);
		h_sort(array, size, qsort, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	h_sort(array, size, 0, size - 1);
}
