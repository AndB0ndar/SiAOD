#include <iostream>
#include <ctime>
#include "sort.h"

using namespace std;

int bin_search(int *arr, int value, int low, int hight, unsigned int &cf)
{
	int interm = (low+hight)/2;
	if (cf++, value < arr[interm])
		return bin_search(arr, value, low, interm, cf);
	else if (cf++, value > arr[interm])
		return bin_search(arr, value, interm+1, hight, cf);
	else if (cf++, value == arr[interm])
		return interm;
	else
		return -1;
}

int main()
{
	int len, x;
	int pos, pos2;
	unsigned int t1, t2, cf = 0;

	cin >> len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;
	pos = rand()%len;
	arr[pos] = 13;

	merge(arr, 0, len-1);

#ifdef DEBUG
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
#endif

	cin >> x;

	t1 = clock();
	pos2 = bin_search(arr, x, 0, len-1, cf);
	t2 = clock();

	cout << len << endl;
	cout << "index= " << pos2 << endl;
	cout << t2 - t1 << endl;
	cout << "cf = " << cf;

	return 0;
}
