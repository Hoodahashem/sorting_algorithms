#include "sort.h"

/**
 * swap_ints - swap ints
 * @a: a pointer to int
 * @b: b pointer to int
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partition function
 * @lb: lower bound
 * @ub: upper bound
 * @array: array
 * @size: number of elements in the partition
 * Return: partition function
*/
int partition(int *array, size_t size, int lb, int ub)
{
	int *pivot, end, start;

	pivot = array + ub;
	for (end = start = lb; start < ub; start++)
	{
		if (array[start] < *pivot)
		{
			if (end < start)
			{
				swap_ints(array + start, array + end);
				print_array(array, size);
			}
			end++;
		}
	}

	if (array[end] > *pivot)
	{
		swap_ints(array + end, pivot);
		print_array(array, size);
	}

	return (end);
}


/**
 * recursively - recursively callling a function
 * @size: size of the array
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * @array: array to recurse
*/
void recursively(int *array, size_t size, int lb, int ub)
{
	int part;

	if (ub - lb > 0)
	{
		part = partition(array, size, lb, ub);
		recursively(array, size, lb, part - 1);
		recursively(array, size, part + 1, ub);
	}
}


/**
 * quick_sort - sorting algorithm
 * @size: size of the array
 * @array: array to sort
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursively(array, size, 0, size - 1);

}
