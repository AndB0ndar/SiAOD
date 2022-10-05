#include <iostream>
#include "HeshTable.h"

using namespace std;

int main()
{
	HashTable ht;
	ht.Insert("4727", 1);
	ht.Insert("000", 13);
	ht.Insert("998", 0);
	ht.Insert("?!", 3);
	ht.Insert("how", 5);
	ht.Insert("?!", 8);
	ht.Insert("?!", 11);
	ht.Insert("000", 748);
	ht.Output();
	cout << "=======" << "000 : " << ht.GetShift("000") << endl;

	cout << "remove with shift: " << ht.Remove("how") << endl;
	ht.Output();


	return 0;
}
