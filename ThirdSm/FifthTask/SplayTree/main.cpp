#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree tr;

	tr.Build("bin");
	tr.Show();
  
	cout << "shift = " << tr.Search("9\0") << endl;
	tr.Show();
	tr.Remove("6\n");
	tr.Show();

	return 0;
}
