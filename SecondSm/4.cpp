#include <iostream>
#include <ctime>

using namespace std;

int search(int *arr, int len, int value, unsigned int &cf)
{
	int i;
	int tmp_n = arr[len-1];
	arr[len-1] = value;

	for (i = 0; cf++, arr[i] != value; i++)
		;

	if ((cf++, i != len-1) || (cf++, tmp_n == value))
		return i;
	else 
		return -1;
}

int main()
{
	int len, x;
	int pos, pos2, num = 12;
	unsigned int t1, t2, cf = 0;

	cin >> len;
	pos = rand()%len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;
	arr[pos] = num;

	cin >> x;

	t1 = clock();
	pos2 = search(arr, len, x, cf);
	t2 = clock();

	cout << len << endl;
	cout << pos << " " << pos2 << endl;
	cout << t2 - t1 << endl;
	cout << "cf = " << cf;

	return 0;
}
