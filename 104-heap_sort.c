#include "sort.h"
/**
 * heapify - heapifies a subtree
 * @array: array to sort
 * @size: size of the array
 * @i: index of the subtree
 * @size_orig: original size of the array
 * Return: void
 */
void heapify(int *array, size_t size, size_t i, size_t size_orig)
{
	size_t largest = i, left = 2 * i + 1, right = 2 * i + 2;
	int temp;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size_orig);
		heapify(array, size, largest, size_orig);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
