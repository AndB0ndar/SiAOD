#include <iostream>
#include "SrchPalindrome.h"

using namespace std;

int main()
{
	// string include polindrome
	string s = "abbhbniuytdcvbnmhhnhbnj";
	SearchPalindrome *sp = SearchPalindrome::getInstance(s);
	cout << "dynamicSearch: " << sp->dynamicSearch() << endl;
	cout << "enumerate: " << sp->getEnumerate() << endl;
	cout << "directSearch: " << sp->directSearch() << endl;
	cout << "enumerate: " << sp->getEnumerate() << endl;
	return 0;
}
