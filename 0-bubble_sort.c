#include "sort.h"

/**
 * bubble_sort - algorithm for bubble sort
 * @size: size of the array
 * @array: array
*/
void bubble_sort(int *array, size_t size)
{
	int i, j, temp;

	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
