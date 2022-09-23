#include <iostream>
#include <ctime>

using namespace std;

void merge_sort(int *arr, int low, int interm, int hight, unsigned int &cf, unsigned int &mf)
{
	int u = 0, i = low, j = interm + 1;
	int len = hight - low + 1;
	int *tmp = new int [len];

#if DEBUG
	cout << i << "=" << j << ": ";
	for (int e = low; e <= hight; e++) {
		cout << arr[e] << " ";
	}
	cout << endl;
#endif

	while ((cf++, i <= interm) && (cf++, j <= hight)) {
		if (cf++, arr[i] <= arr[j]) {
			mf++;
			tmp[u++] = arr[i++];
		} else if (cf++, arr[i] > arr[j]) {
			mf++;
			tmp[u++] = arr[j++];
		}
	}
	if (cf++, i <= interm) {
		for (; cf++, i <= interm; i++, u++) {
			mf++;
			tmp[u] = arr[i];
		}
	}
	else if (cf++, j <= hight) {
		for (; cf++, j <= hight; j++, u++) {
			mf++;
			tmp[u] = arr[j];
		}
	}

#if DEBUG
	cout << low << " " << u << "| ";
	for (int e = low; e <= hight; e++) {
		cout << tmp[e-low] << " ";
	}
	cout << endl;
#endif

	for (int e = low; cf++, e <= hight; e++) {
		mf++;
		arr[e] = tmp[e-low];
	}

	delete [] tmp;
}

void merge(int *arr, int low, int hight, unsigned int &cf, unsigned int &mf)
{
	if (low >= hight)
		return;
	int interm = (low + hight) / 2;
	merge(arr, low, interm, cf, mf);
	merge(arr, interm + 1, hight, cf, mf);
	merge_sort(arr, low, interm, hight, cf, mf);
}

int main()
{
	int len;
	unsigned int t1, t2, cf = 0, mf = 0;

	cin >> len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;

#if DEBUG
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
#endif

	t1 = clock();
	merge(arr, 0, len-1, cf, mf);
	t2 = clock();

#if DEBUG
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
#endif

	cout << len << endl;
	cout << t2 - t1 << endl;
	cout << "cf + mf = " << cf + mf;

	return 0;
}
