#include <iostream>

using namespace std;

void set_value(unsigned &val, const char *msg="Enter value: ")
{
	cout << msg;
	cin >> val;
}

void show(unsigned val, const char *msg, unsigned size=sizeof(int))
{
	unsigned n = size*8;
	unsigned maska = (1 << (n-1));

	cout << msg;
	for(unsigned i = 1; i <= n; i++) {
		cout << ((val & maska) >> (n-i));
		maska >>= 1;
	}
	cout << endl;
}

void setting_1(unsigned &val, unsigned &mask)
{
	int a = 1<<16;
	int b = 1<<14;
	int c = 1;
	mask = a + b + c;
	val |= mask;
}

void zeroing_1(unsigned &val, unsigned &mask, unsigned n=3)
{
	mask = 1;
	for (unsigned i = 0; i < n-1; i++){
		mask <<= 1;
		mask += 1;
	}
	mask <<= 2;
	mask = ~mask;
	val &= mask;
}

void multiply(unsigned &val, unsigned opd=6)
{
	val <<= opd;
}

void divide(unsigned &val, unsigned opd=6)
{
	val >>= opd;
}

void zeroing_2(unsigned &val, unsigned &mask, unsigned opd)
{
	mask = 1 << (sizeof(int)*8 - 1);
	mask >>= (sizeof(int)*8 - opd);
	mask = ~mask;

	val &= mask;
}

enum { setone=1, zeroing_fr, mult, divd, zeroing_sc };

const char *msg_value = "Value:   ";
const char *msg_mask = "Mask:    ";
const char *msg_result = "Result:  ";

int main()
{
	int nm;
	unsigned value, mask;
	bool frun = true;

	while (frun) {
		cout << "Enter task number: ";
		cin >> nm;
		switch(nm) {
		case setone:
			value = 0x2BFFE;
			show(value, msg_value);
			setting_1(value, mask);
			show(mask, msg_mask);
			show(value, msg_result);
			break;
		case zeroing_fr:
			set_value(value);
			show(value, msg_value);
			zeroing_1(value, mask);
			show(mask, msg_mask);
			show(value, msg_result);
			break;
		case mult:
			set_value(value);
			show(value, msg_value);
			multiply(value);
			show(value, msg_result);
			break;
		case divd:
			set_value(value);
			show(value, msg_value);
			divide(value);
			show(value, msg_result);
			break;
		case zeroing_sc:
			unsigned opd;
			set_value(value);
			set_value(opd, "Enter n: ");
			show(value, msg_value);
			zeroing_2(value, mask, opd);
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
