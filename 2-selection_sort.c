#include "sort.h"

/**
 * selection_sort - Function that runs selection sorts algorithm in ascending order
 * @array: Array
 * @size: Size of array
 */
void selection_sort(int *array, int size)
{
	int i, j, n;
	int element;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		n = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[n])
				n = j;
		}

		if (n != i)
		{
			element = array[i];
			array[i] = array[n];
			array[n] = element;
			print_array(array, size);
		}
	}
}
