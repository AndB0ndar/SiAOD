#include <iostream>
#include <ctime>

using namespace std;

void qsort(int *arr, int low, int hight, unsigned int &cf, unsigned int &mf)
{
	int check = arr[(low+hight)/2];
	int i = low, j = hight;
	do {
		while (cf++, arr[i] < check)
			i++;
		while (cf++, arr[j] > check)
			j--;
		if (cf++, i <= j) {
			mf++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	} while (cf++, ++i <= --j);
	if (cf++, i < hight)
		qsort(arr, i, hight, cf, mf);
	if (cf++, j > low)
		qsort(arr, low, j, cf, mf);
}

int main()
{
	int len;
	unsigned int t1, t2, cf = 0, mf = 0;

	cin >> len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;

	t1 = clock();
	qsort(arr, 0, len-1, cf, mf);
	t2 = clock();

	cout << len << endl;
	cout << t2 - t1 << endl;
	cout << "cf + mf = " << cf + mf;

	return 0;
}
