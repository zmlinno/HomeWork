#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void ShellSort(int* a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = a[i];

			int j;
			for (j = i; j >= gap && a[i - gap] > temp;j-=gap)
			{
				a[j] = a[j - gap];
				

			}
			a[j] = temp;
		}
	}

}

int main()
{
	int arr[] = { 12,11,13,5,6 };
	int n1 = sizeof(arr) / sizeof(arr[0]);

	int arr1[] = { 12,34,54,2,3 };
	int n2 = sizeof(arr1) / sizeof(arr1[0]);

	InsertSort(arr, n1);
	ShellSort(arr1,n2);

	for (int i = 0; i < n1; i++)
	{
		printf("%d ", arr[i]);
		
	}
	printf("\n");

	for (int i = 0; i < n2; i++)
	{
		printf("%d ", arr1[i]);
	}

	return 0;
}