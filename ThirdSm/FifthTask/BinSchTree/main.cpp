#include <iostream>
#include <ctime>
#include "../BinFl/BinaryFile.h"
#include "Tree.h"

using namespace std;

int main()
{
	Tree tr;
	tr.Generate("bin");
	BinaryFile binf("bin");
    unsigned int start_time =  clock();
	cout << "find shift: " << tr.Search("+++") << endl;
    unsigned int end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

    start_time =  clock();
	cout << "find shift: " << tr.Search("---") << endl;
    end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

    start_time =  clock();
	cout << "find shift: " << tr.Search("===") << endl;
    end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

	/*
	cout << "======" << endl;
	tr.Remove("**");
	tr.Show();

	//cout << "======" << endl;
	//cout << tr.GetDistanse('w') << endl;
	//cout << "======" << endl;
	tr.Show();
	*/
	return 0;
}
