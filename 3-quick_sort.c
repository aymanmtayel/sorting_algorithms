#include "sort.h"
/**
 * _swap - swap two integers in an array
 * @array: the array of int
 * @size: size of the array
 * @int1: integer 1
 * @int2: integer 2
 * Return: void
 */
void _swap(int *array, size_t size, int *int1, int *int2)
{
	if (*int1 != *int2)
	{
		*int1 = *int1 + *int2;
		*int2 = *int1 - *int2;
		*int1 = *int1 - *int2;
		print_array((const int *)array, size);
	}
}

/**
 * _lomuto - function to apply the lomuto on an array
 * @array: the array
 * @size: the array size
 * @a: low integer
 * @b: high integer
 * Return: the index
 */

size_t _lomuto(int *array, size_t size, ssize_t a, ssize_t b)
{
	int i, j, pivotal = array[b];

	for (i = j = a; j < b; j++)
	{
		if (array[j] < pivotal)
		{
			_swap(array, size, &array[j], &array[i]);
			i++;
		}
	}
	_swap(array, size, &array[i], &array[b]);
	return (i);
}

/**
 * helper - function to perform the quick sort on an array
 * @array: to be sorted
 * @a: first number
 * @b: seconde number
 * @size: the array size
 * Return: Void
 */
void helper(int *array, size_t size, ssize_t a, ssize_t b)
{
	if (a < b)
	{
		size_t _index = _lomuto(array, size, a, b);

		helper(array, size, a, _index - 1);
		helper(array, size, _index + 1, b);
	}
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	helper(array, size, 0, size - 1);
}
