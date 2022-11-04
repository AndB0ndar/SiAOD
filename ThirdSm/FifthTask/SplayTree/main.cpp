#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree tr;

	tr.Build("bin");
	tr.Show();
  
    cout << "shift = " << tr.Search("?") << endl;
	
	tr.Show();

    cout << "shift = " << tr.Search("?") << endl;
	return 0;
}
