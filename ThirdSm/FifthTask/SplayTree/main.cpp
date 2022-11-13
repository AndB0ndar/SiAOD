#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

int main()
{
	Tree tr;
	for (string i = "1"; i < "11111111111111111111111111111"; i+="1")
		tr.Add(i.c_str(), 0);
	tr.Add("---", 0);
	tr.Show();
	cout << tr.Search("11111111111111111") << endl;
	cout << tr.Search("111111111") << endl;
	cout << tr.Search("11111111") << endl;
	cout << tr.Search("11111111111") << endl;
	cout << tr.Search("111111111111111111111111!") << endl;
	cout << tr.Search("---") << endl;
	tr.Show();
	/*
	tr.Build("bin");
    unsigned int start_time =  clock();
	cout << "find shift: " << tr.Search("+++") << endl;
    unsigned int end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

    start_time =  clock();
	cout << "find shift: " << tr.Search("===") << endl;
    end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;

    start_time =  clock();
	cout << "find shift: " << tr.Search("---") << endl;
    end_time = clock();
    cout << "work time: " << (end_time - start_time)/1000.0 << " s" << endl;


	cout << "======" << endl;
	tr.Remove("**");
	tr.Show();
  
	cout << "shift = " << tr.Search("9") << endl;
	tr.Show();
	tr.Remove("6");
	tr.Show();
	*/

	return 0;
}
