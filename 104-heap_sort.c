#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers rep a binary tree.
 * @size: The size of the array.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, l;

	left = 2 * root + 1;
	right = 2 * root + 2;
	l = root;

	if (left < base && array[left] > array[l])
		l = left;
	if (right < base && array[right] > array[l])
		l = right;

	if (l != root)
	{
		swap_ints(array + root, array + l);
		print_array(array, size);
		max_heapify(array, size, base, l);
	}
}

/**
 * heap_sort - Sort an array of the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		max_heapify(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_ints(array, array + x);
		print_array(array, size);
		max_heapify(array, size, x, 0);
	}
}
