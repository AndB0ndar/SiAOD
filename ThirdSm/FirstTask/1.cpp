#include <iostream>
#include <bitset>

using namespace std;

//00001

void set_value(int &val)
{
	cout << "enter: ";
	cin >> val;
}

int zeroing_1(int val)
{
	int a = 1<<16;
	int b = 1<<14;
	int c = 1;
	int mask = a + b + c;
	return val | mask;
}

int zeroing_2(int val)
{
	int mask = 1;
	for (int i = 0; i < 3; i++){
		mask <<= 1;
		mask += 1;
	}
	mask <<= 2;

	return (val | mask) ^ mask;
}

int multiply(int val, int opd)
{
	return val << opd;
}

int divide(int val, int opd)
{
	return val >> opd;
}

int zeroing_3(int val, int opd)
{
	int mask = 1 << (sizeof(int) - 1);
	mask >>= (sizeof(int) - opd);

	return val & ~mask;
}
int main()
{
	cout << "1)" << endl;
	int x = 0xEB9FC1;
	cout << bitset<21>(x) << endl;
	cout << bitset<21>(zeroing_1(x)) << endl;

	cout << "2)" << endl;
	set_value(x);
	cout << bitset<11>(x) << endl;
	cout << bitset<11>(zeroing_2(x)) << endl;

	int opd;
	cout << "3)" << endl;
	set_value(x);
	set_value(opd);
	cout << bitset<11>(x) << endl;
	cout << bitset<11>(multiply(x, opd)) << endl;

	cout << "4)" << endl;
	set_value(x);
	set_value(opd);
	cout << bitset<11>(x) << endl;
	cout << bitset<11>(divide(x, opd)) << endl;

	cout << "5)" << endl;
	set_value(x);
	set_value(opd);
	cout << bitset<8*sizeof(int)>(x) << endl;
	cout << bitset<8*sizeof(int)>(zeroing_3(x, opd)) << endl;

	return 0;
}
