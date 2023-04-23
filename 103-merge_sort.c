#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Merge two sorted subarrays into one sorted subarray.
 * @subarr: The subarray to sort.
 * @buff: A buffer array for merging the two subarrays.
 * @front: The starting index of the first subarray.
 * @mid: The ending index of the first subarray and the starting index of the second subarray.
 * @back: The ending index of the second subarray.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i, j, k;

	for (i = front, j = mid, k = 0; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];

	for (; i < mid; i++, k++)
		buff[k] = subarr[i];

	for (; j < back; j++, k++)
		buff[k] = subarr[j];

	for (i = front, k = 0; i < back; i++, k++)
		subarr[i] = buff[k];
}

/**
 * merge_sort_recursive - Recursive helper function to implement merge sort.
 * @subarr: The subarray to sort.
 * @buff: A buffer array for merging the two subarrays.
 * @front: The starting index of the subarray.
 * @back: The ending index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order using the merge sort algorithm.
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

