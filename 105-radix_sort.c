#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *count, *output, max = 0, exp = 1;
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	while (max / exp > 0)
	{
		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;
		for (i = 1; i <= (size_t)max; i++)
			count[i] += count[i - 1];
		print_array(count, max + 1);
		for (i = 0; i < size; i++)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
		exp *= 10;
	}
	free(count);
	free(output);
}
