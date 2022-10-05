#include <iostream>
#include "HashTable.h"

using namespace std;


int main()
{
	HashTable ht;

	ht.Insert("hellow");
	ht.Insert(",");
	ht.Insert("how");
	ht.Insert("are");
	ht.Insert("you");
	ht.Insert("?");

	ht.OutPut();

	cout << "===========" << ht.Search("?") << endl;

	ht.Remove("are");

	ht.OutPut();

	return 0;
}
