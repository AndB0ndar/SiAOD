#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree tr;
	tr.Add('a');
	tr.Add('b');
	tr.Add('w');
	tr.Add('q');
	tr.Show();
	//cout << "Left node: " << tr.GetLeftItem()->data << endl;
	//ncout << "max: " << tr.FindMaxChar() << endl;
	cout << "distance to 'w': " << tr.GetDistanse('w') << endl;
	tr.Add('w');
	tr.Add('l');
	tr.Add('f');
	tr.Add('w');
	tr.Show();
	//cout << "Left node: " << tr.GetLeftItem()->data << endl;
	//ncout << "max: " << tr.FindMaxChar() << endl;
	cout << "distance to 'w': " << tr.GetDistanse('w') << endl;

	//cout << "======" << endl;
	//cout << tr.GetDistanse('w') << endl;
	//cout << "======" << endl;
	//tr.Show();
	return 0;
}
