#include "sort.h"

/**
 * merge - merges two subarrays of an array
 * @array: array to sort
 * @size: size of the array
 * @left: left subarray
 * @right: right subarray
 * Return: void
 */
void merge(int *array, size_t size, int *left, int *right)
{
	int i = 0, j = 0, k = 0;
	int size_left = size / 2, size_right = size - size_left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);
	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < size_left)
		array[k++] = left[i++];
	while (j < size_right)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending order using the Merge
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t i, size_left, size_right;

	if (array == NULL || size < 2)
		return;
	size_left = size / 2;
	size_right = size - size_left;
	left = malloc(sizeof(int) * size_left);
	if (left == NULL)
		return;
	right = malloc(sizeof(int) * size_right);
	if (right == NULL)
	{
		free(left);
		return;
	}
	for (i = 0; i < size_left; i++)
		left[i] = array[i];
	for (i = 0; i < size_right; i++)
		right[i] = array[size_left + i];
	merge_sort(left, size_left);
	merge_sort(right, size_right);
	merge(array, size, left, right);
	free(left);
	free(right);
}
