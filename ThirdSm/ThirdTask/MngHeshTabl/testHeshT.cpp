#include <iostream>
#include <string>
#include "HeshTable.h"

using namespace std;


int main()
{
	HeshTable ht;

	ht.Insert("hellow", 1);
	ht.Output();
	ht.Insert("?", 999);
	ht.Insert("?", 12);
	ht.Insert("hellow", 1);
	ht.Insert("hellow", 1);
	ht.Insert("hellow", 1);
	ht.Output();

	for (int i = 0; i < 10; i++) {
		ht.Insert("aa", i);
	}

	ht.Output();

	cout << "Remove '?'" << endl;
	ht.Remove("?");

	ht.Output();

	string line;
	cout << "Entry key: ";
	cin >> line;
	cout << "===========" << ht.GetShift(line.c_str()) << endl;

	ht.Output();

	return 0;
}
