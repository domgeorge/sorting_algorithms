#include "sort.h"

/**
 * _swp - function that swaps two numbers
 * @a: first no
 * @b:  second no
 */
void _swp(int *a, int *b)
{
	int element = *a;
	*a = *b;
	*b = element;
}

/**
 * bubble_sort - Function that sorts an ARR of num using
 * bubble sort algorithm
 * @array: Array being sorted
 * @size: Array size
 *
 * Return: void
 */
void bubble_sort(int *array, int size)
{
	int j, k, pr;

	k = size;

	if (array == NULL || size < 2)
		return;

	while (k > 0)
	{
		pr = 0;
		for (j = 0; j < k - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				_swp(&array[j], &array[j + 1]);
				pr = j + 1;
				print_array(array, size);
			}
		}
		k = pr;
	}
}
