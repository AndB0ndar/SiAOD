#include <iostream>

using namespace std;

void set_value(unsigned &x, const char *msg="Enter value: ")
{
	cout << msg;
	cin >> x;
}

void show(unsigned x, const char *msg)
{
	unsigned n = sizeof(int)*8;
	unsigned maska = (1 << (n-1));

	cout << msg;
	for(unsigned i = 1; i <= n; i++) {
		cout << ((x & maska) >> (n-i));
		maska >>= 1;
	}
	cout << endl;
}

void f1(unsigned &x, unsigned &msk)
{
	int a = 7<<2;
	msk = a;
	x |= msk;
}

void f2(unsigned &x, unsigned &msk)
{
	int a = 1<<11;
	int b = 1<<10;
	int c = 1;
	msk = a+b+c;
	msk = ~msk;
	x &= msk;
}

void f3(unsigned &x)
{
	x <<= 5;
}

void f4(unsigned &x)
{
	x >>= 5;
}

void f5(unsigned &x, unsigned &msk, unsigned opd)
{
	msk = 1 << (sizeof(int)*8 - 1);
	msk >>= (sizeof(int)*8 - opd);
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
	unsigned x, msk;
	bool frun = true;

	while (frun) {
		cout << "Enter task number: ";
		cin >> nm;
		switch(nm) {
		case setone:
			x = 0x2BFFE;
			show(x, msg_value);
			f1(x, msk);
			show(msk, msg_mask);
			show(x, msg_result);
			break;
		case zeroing_fr:
			set_value(x);
			show(x, msg_value);
			f2(x, msk);
			show(msk, msg_mask);
			show(x, msg_result);
			break;
		case mult:
			set_value(x);
			show(x, msg_value);
			f3(x);
			show(x, msg_result);
			break;
		case divd:
			set_value(x);
			show(x, msg_value);
			f4(x);
			show(x, msg_result);
			break;
		case zeroing_sc:
			unsigned opd;
			set_value(x);
			set_value(opd, "Enter n: ");
			show(x, msg_value);
			f5(x, msk, opd);
			show(msk, msg_mask);
			show(x, msg_result);
			break;
		default:
			frun = false;
			break;
		}
	}

	return 0;
}
