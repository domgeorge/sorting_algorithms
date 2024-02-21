#include "sort.h"

/**
 * _swp - function that swaps two numbers
 * @a: first number
 * @b: second number
 */
void _swp(int *a, int *b)
{
	int element = *a;
	*a = *b;
	*b = element;
}

/**
 * _ptn - Lomuto partition scheme
 * @arr: Array of int
 * @size: Size
 * @start: Starting index
 * @end: Ending index
 * Return: Final partition
 */
int _ptn(int *arr, size_t size, int start, int end)
{
	int *piv = arr + end;
	int i, j;

	for (i = j = start; j < end; j++)
	{
		if (arr[j] < *piv)
		{
			if (i < j)
			{
				_swp(arr + j, arr + i);
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] > *piv)
	{
		_swp(arr + i, piv);
		print_array(arr, size);
	}

	return (i);
}

/**
 * _sort - Function that recursively sorts the array
 * @arr: Array of int
 * @size: Size
 * @start: Starting index
 * @end: Ending index
 */
void _sort(int *arr, int size, int start, int end)
{
	int h;

	if (start < end)
	{
		h = _ptn(arr, size, start, end);
		_sort(arr, size, start, h - 1);
		_sort(arr, size, h + 1, end);
	}
}

/**
 * quick_sort - Function that sorts array using quicksort
 * @array: Array of int
 * @size: Size
 */
void quick_sort(int *array, int size)
{
	_sort(array, size, 0, size - 1);
}
