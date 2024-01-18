#include "sort.h"

/**
 * swap - swaps two integers
 * @number_a: first integer
 * @number_b: second integer
 * Return: Nothing
 */

void swap(int *number_a, int *number_b)
{
	int temp = *number_a;
	*number_a = *number_b;
	*number_b = temp;
}

/**
 * partition - lomuto partition scheme
 * @array: array to partition
 * @size: size of array
 * @left: left index
 * @right: right index
 * Return: index of partition
 */

int partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int index_a = left;
	int index_b = left;

	for (; index_b < right; index_b++)
	{
		if (array[index_b] < pivot)
		{
			if (index_a != index_b)
			{
				swap(&array[index_a], &array[index_b]);
				print_array(array, size);
			}

			index_a++;
		}
	}

	if (array[index_a] > array[right])
	{
		swap(&array[index_a], &array[right]);
		print_array(array, size);
	}

	return (index_a);
}

/**
 * sort - sort algorithm give by lomuto
 * @array: array to sort
 * @size: size of array
 * @left: left index
 * @right: right index
 * Return: Nothing
 */

void sort(int *array, size_t size, int left, int right)
{
	int lum_partition;

	if (right - left > 0)
	{
		lum_partition = partition(array, size, left, right);

		sort(array, size, left, lum_partition - 1);
		sort(array, size, lum_partition + 1, right);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
	{
		return;
	}

	sort(array, size, 0, size - 1);
}
