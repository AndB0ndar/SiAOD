#include <iostream>

using namespace std;

int cf = 0, mf = 0;
enum { len_buf = 256 };
const char str[] = "Usually, people in Russia give presents to their \
					family and friends. As for gifts for children, \
					these are brought by Grandfather Frost – \
					the Russian version of Santa Claus.";


int str_len(const char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		;
	return i;
}

int bm_search(const char *str, const char *imag, const int *d, int len_i)
{
	int i = len_i-1, j = i;
	while (cf++, str[i]) {
		if (cf++, str[i] == imag[j]) {
			if (cf++, !j)
				return i;
			mf++;
			i--;
			j--;
		} else {
			mf++;
			i += d[(int)str[i]];
			j = len_i-1;
		}
	}
	return -1;
}

int main()
{
	char imag[] = "Russia";

	int len_i = str_len(imag);
	int d[len_buf];

	for (int i = 0; i < len_buf; i++)
		d[i] = len_i;
	for (int i = 0; imag[i]; i++)
		d[(int)imag[i]] = len_i-1-i;

	cout << bm_search(str, imag, d, len_i) << endl;
	cout << "cf = " << cf << " mf = " << mf << endl;
	cout << cf+mf << endl;

	return 0;
}
