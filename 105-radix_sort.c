#include "sort.h"

/**
 * _max - Obtain the maximum value.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer.
 */
int _max(int *array, int size);
int _max(int *array, int size)
{
	int max, u;

	for (max = array[0], u = 1; u < size; u++)
	{
		if (array[u] > max)
			max = array[u];
	}

	return (max);
}

/**
 * radix_count - Sorts the significant digits of an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @dig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array
 */
void radix_count(int *array, size_t size, int dig, int *buff);
void radix_count(int *array, size_t size, int dig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / dig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / dig) % 10] - 1] = array[i];
		count[(array[i] / dig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size);
void radix_sort(int *array, size_t size)
{
	int max, dig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = _max(array, size);
	for (dig = 1; max / dig > 0; dig *= 10)
	{
		radix_count(array, size, dig, buff);
		print_array(array, size);
	}

	free(buff);
}
