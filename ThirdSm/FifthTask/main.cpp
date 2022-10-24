#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree tr;
	tr.Add('a');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;
	tr.Add('b');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;
	tr.Add('w');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;
	tr.Add('z');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;
	tr.Add('q');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;
	tr.Add('l');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;
	tr.Add('t');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;
	tr.Add('w');
	cout << tr.GetLeftItem()->data << endl;
	cout << "max: " << tr.FindMaxChar() << endl;

	cout << "======" << endl;
	cout << tr.GetDistanse('w') << endl;
	cout << "======" << endl;
	tr.Show();
	return 0;
}
