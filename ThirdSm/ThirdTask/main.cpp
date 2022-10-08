#include <iostream>
#include "Data.h"

using namespace std;

int main(int argc, char **argv)
{
	Data dt("bin", "text.txt");
	for (unsigned i = 0; i < dt.GetSizeFile(); i++)
		dt.SaveEntry(i);
	cout << "====" << endl;
	cout << dt.Search(argv[1]).String() << endl;

	return 0;
}
