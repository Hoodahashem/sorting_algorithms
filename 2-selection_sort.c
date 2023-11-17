#include "sort.h"

/**
 * selection_sort - sorting algorithm
 * @size: size of the array
 * @array: array of integers
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
	{
		return
	}
	for (i = 0; i < size - 1; i++)
	{
		size_t min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = array[min];

			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
