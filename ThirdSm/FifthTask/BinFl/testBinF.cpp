#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "BinaryFile.h"

using namespace std;

int main()
{
	string txtfile = "text.txt";
	string binfile = "bin";
	BinaryFile binf(binfile);
	binf.Generate(txtfile);

    unsigned int start_time =  clock();
	cout << "find: " << binf.Search("+++").String() << endl;
    unsigned int end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

    start_time =  clock();
	cout << "find: " << binf.Search("---").String() << endl;
    end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

    start_time =  clock();
	cout << "find: " << binf.Search("===").String() << endl;
    end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

	return 0;
}
