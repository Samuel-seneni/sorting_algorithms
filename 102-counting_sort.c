#include "sort.h"

/**
 * get_max - Get the maximum value of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, x;
	
	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}
	return (max);
}
/**
 * counting_sort - sorts an array of integers using the Counting sort algorithm
 * @array: array of integers
 * @size: size of the array.
 */
 void counting_sort(int *array, size_t size)
{
	int *count;
	int *s;
	int max;
	int x;

	if (array == NULL || size < 2)
		return;

	s = malloc(sizeof(int) * size);
	if (s == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(s);
		return;
	}
	for (x = 0; x < (max + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 0; x < (max + 1); x++)
		count[x] += count[x - 1];
	print_array(count, max + 1);

	for (x = 0; x < (int)size; x++)
	{
		s[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = s[x];

	free(s);
	free(count);
}
