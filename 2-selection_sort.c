#include "sort.h"

/**
 * swap_ints - two integers to swap in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		minimum = array + x;
		for (y = x + 1; y < size; y++)
			minimum = (array[y] < *minimum) ? (array + y) : minimum;

		if ((array + x) != minimum)
		{
			swap_ints(array + x, minimum);
			print_array(array, size);
		}
	}
}
