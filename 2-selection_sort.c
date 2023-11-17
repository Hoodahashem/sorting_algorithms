#include "sort.h"

/**
 * selection_sort - sorting algorithm
 * @size: size of the array
 * @array: array of integers
*/
void selection_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t min = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				int temp = array[j];

				array[j] = array[min];
				array[min] = temp;
			}
		}
	}
}
