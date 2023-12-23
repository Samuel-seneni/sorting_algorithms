#include "sort.h"

void merge_subarray(int *subarray, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarray, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t x, y, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, mid - front);

	printf("[right]: ");
	print_array(subarray + mid, back - mid);

	for (x = front, y = mid; x < mid && y < back; k++)
		buff[k] = (subarray[x] < subarray[y]) ? subarray[x++] : subarray[y++];
	for (; x < mid; x++)
		buff[k++] = subarray[y];
	for (; y < back; y++)
		buff[k++] = subarray[y];
	for (x = front, k = 0; x < back; x++)
		subarray[x] = buff[k++];

	printf("[Done]: ");
	print_array(subarray + front, back - front);
}

/**
 * merge_sort_recursive - Merge sort algorithm to implement through recursion.
 * @subarray: A subarray of an array of integers.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarray, buff, front, mid);
		merge_sort_recursive(subarray, buff, mid, back);
		merge_subarr(subarray, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort integers in ascending order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
