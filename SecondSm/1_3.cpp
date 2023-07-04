#include <iostream>
#include <ctime>

using namespace std;

void ins_sort(int *arr, int len, unsigned int &cf, unsigned int &mf)
{
	for(int i = 0; cf++, i < len - 1; i++) {
		int min = i;
		for(int j = i; cf++, j < len; j++) {
			if(cf++, arr[j] < arr[min])
				min = j;
		}
		if(cf++, arr[min] != arr[i]) {
			mf++;
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

int main()
{
	int len, t1, t2;
	unsigned int cf = 0, mf = 0;
	int *arr;

	cin >> len;
	arr = new int [len];

	for(int i = 0; i < len; i++)
		arr[i] = rand()%100;

	t1 = clock();
	ins_sort(arr, len, cf, mf);
	t2 = clock();
	cout << t2 - t1 << endl; 
	cout << "cf + mf = " << cf + mf;

	return 0;
}
