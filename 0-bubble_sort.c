#include "sort.h"
#include <stddef.h>

/**
 * swap_int - swap two integers
 * @a: swap the first integer
 * @b: swap the second integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{

	size_t x, index, temp = 0;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			temp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = temp;
			print_array(array, size);
			}
		}
}
