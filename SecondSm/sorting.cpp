#include <iostream>
#include "sort.h"

void qsort(int *arr, int low, int hight)
{
	int check = arr[(low+hight)/2];
	int i = low, j = hight;
	do {
		while (arr[i] < check)
			i++;
		while (arr[j] > check)
			j--;
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	} while (++i <= --j);
	if (i < hight)
		qsort(arr, i, hight);
	if (j > low)
		qsort(arr, low, j);
}

void merge_sort(int *arr, int low, int interm, int hight)
{
	int u = 0, i = low, j = interm + 1;
	int len = hight - low + 1;
	int *tmp = new int [len];

	while (i <= interm && j <= hight)
		if (arr[i] <= arr[j])
			tmp[u++] = arr[i++];
		else if (arr[i] > arr[j])
			tmp[u++] = arr[j++];

	if (i <= interm)
		for (;i <= interm; i++, u++)
			tmp[u] = arr[i];
	else if (j <= hight)
		for (;j <= hight; j++, u++)
			tmp[u] = arr[j];

	for (int e = low; e <= hight; e++)
		arr[e] = tmp[e-low];

	delete [] tmp;
}

void merge(int *arr, int low, int hight)
{
	if (low >= hight)
		return;
	int interm = (low + hight) / 2;
	merge(arr, low, interm);
	merge(arr, interm + 1, hight);
	merge_sort(arr, low, interm, hight);
}
