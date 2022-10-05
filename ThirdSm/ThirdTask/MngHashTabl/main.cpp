#include <iostream>
#include "HashTable.h"

using namespace std;


int main()
{
	HashTable ht;

	ht.Insert("hellow", 1);
	ht.Insert(",", 1);
	ht.Insert("how", 1);
	ht.Insert("are", 1);
	ht.Insert("you", 1);
	ht.Insert("?", 999);

	ht.OutPut();

	cout << "===========" << ht.GetShift("?") << endl;

	ht.Remove("are");

	ht.OutPut();

	return 0;
}
