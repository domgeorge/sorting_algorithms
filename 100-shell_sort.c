#include "sort.h"
/**
 * shell_sort - Function that sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: The array to be printed
 * @size: Number of elements in the Array
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1;
	size_t i, j;
	int tem;

	if (!array || size < 2)
	{
		return;
	}

	while (space < size / 3)
	{
		space = space * 3 + 1;
	}
	while (space > 0)
	{
		for (i = space; i < size; i++)
		{
			tem = array[i];
			for (j = i; j >= space && array[j - space] > tem; j -= space)
			{
				array[j] = array[j - space];
			}
			array[j] = tem;
		}
		print_array(array, (int)size);
		space = (space - 1) / 3;
	}
}
