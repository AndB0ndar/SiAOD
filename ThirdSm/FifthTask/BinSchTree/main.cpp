#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree tr;
	tr.Add("a", 3);
	tr.Add("b", 2);
	tr.Add("w", 2);
	tr.Add("q", 4);
	tr.Show();
	//cout << "Left node: " << tr.GetLeftItem()->data << endl;
	//ncout << "max: " << tr.FindMaxChar() << endl;
	cout << "distance to 'w': " << tr.Search("w") << endl;
	tr.Add("w", 6);
	tr.Add("l", 0);
	tr.Add("f", 4);
	tr.Add("w", 1);
	tr.Show();
	//cout << "Left node: " << tr.GetLeftItem()->data << endl;
	//ncout << "max: " << tr.FindMaxChar() << endl;
	cout << "distance to 'l': " << tr.Search("b") << endl;
	tr.Remove("a");

	//cout << "======" << endl;
	//cout << tr.GetDistanse('w') << endl;
	//cout << "======" << endl;
	tr.Show();
	return 0;
}
