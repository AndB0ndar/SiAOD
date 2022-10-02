#include <iostream>

using namespace std;

void set_value(unsigned &x, const char *msg="Enter value: ")
{
	cout << msg;
	cin >> x;
}

void show(unsigned x, const char *msg)
{
	int n = sizeof(int)*8;
	int msk = (1 << (n-1));

	cout << msg;
	for(int i = 1; i <= n; i++) {
		cout << ((x & msk) >> (n-i));
		msk >>= 1;
	}
	cout << endl;
}

void f1(int &x, int &msk)
{
	int a = 7<<2;
	msk = a;
	x |= msk;
}

void f2(int &x, int &msk)
{
	int a = 7<<11;
	int b = 1<<10;
	int c = 1;
	msk = a+b+c;
	x &= ~msk;
}

void f3(int &x)
{
	x <<= 5;
}

void f4(int &x)
{
	x >>= 5;
}

void f5(int &x, int &msk, int n)
{
	msk = 1 << (sizeof(int)*8 - 1);
	msk >>= (sizeof(int)*8 - n);
	msk = ~msk;

	x &= msk;
}

enum { setone=1, zeroing_fr, mult, divd, zeroing_sc };

const char *msg_value = "Value:   ";
const char *msg_mask = "Mask:    ";
const char *msg_result = "Result:  ";

int main()
{
	int nm;
	int value, mask;
	bool frun = true;

	while (frun) {
		cout << "Enter task number: ";
		cin >> nm;
		switch(nm) {
		case setone:
			value = 0x2BFFE;
			show(value, msg_value);
			f1(value, mask);
			show(mask, msg_mask);
			show(value, msg_result);
			break;
		case zeroing_fr:
			set_value(value);
			show(value, msg_value);
			f2(value, mask);
			show(mask, msg_mask);
			show(value, msg_result);
			break;
		case mult:
			set_value(value);
			show(value, msg_value);
			f3(value);
			show(value, msg_result);
			break;
		case divd:
			set_value(value);
			show(value, msg_value);
			f4(value);
			show(value, msg_result);
			break;
		case zeroing_sc:
			int opd;
			set_value(value);
			set_value(opd, "Enter n: ");
			show(value, msg_value);
			f5(value, mask, opd);
			show(mask, msg_mask);
			show(value, msg_result);
			break;
		default:
			frun = false;
			break;
		}
	}

	return 0;
}
