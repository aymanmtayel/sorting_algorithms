#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 *  using the Bubble sort algorithm
 *  @array: array to be sorted
 *  @size: size of the array
 *  Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (!array || !size || size < 2)
		return;

	i = 0;
	while (i < size)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
