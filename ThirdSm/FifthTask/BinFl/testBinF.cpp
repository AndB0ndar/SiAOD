#include <iostream>
#include <string>
#include <vector>
#include "BinaryFile.h"

using namespace std;

int main()
{
	string txtfile = "text.txt";
	string binfile = "bin";
	BinaryFile binf(binfile);
	binf.Generate(txtfile);
	binf.Output();

	vector<const char*> data;

	data.push_back("8");
	data.push_back("nsbslwn");
	data.push_back("JANDW");
	Phone ph(data);
	binf.Write(ph);

	data.clear();
	data.push_back("9");
	data.push_back("nscslv");
	data.push_back("IQJSLS");
	ph = Phone(data);
	binf.Write(ph);

	data.clear();
	data.push_back("10");
	data.push_back("kjahd");
	data.push_back("SVYASLJ");
	ph = Phone(data);
	binf.Write(ph);
	cout << "=======" << endl;
	binf.Output();
	cout << "=======" << endl;
	
	int line;
	cout << "Entre number: ";
	cin >> line;
	cout << "=======" << endl;
	cout << binf.Read(line).String() << endl;
	return 0;
}
