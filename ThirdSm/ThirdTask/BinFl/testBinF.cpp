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
	binf.TextToBinary(txtfile);
	binf.Output();

	vector<const char*> data;

	data.push_back("92523");
	data.push_back("nsbslwn");
	data.push_back("JANDW");
	Phone ph(data);
	binf.Write(ph);

	data.clear();
	data.push_back("8204");
	data.push_back("kjahd");
	data.push_back("SVYASLJ");
	ph = Phone(data);
	binf.Write(ph);

	data.clear();
	data.push_back("?");
	data.push_back("nscslv");
	data.push_back("IQJSLS");
	ph = Phone(data);
	binf.Write(ph);

	data.clear();
	data.push_back("8204");
	data.push_back("kjahd");
	data.push_back("SVYASLJ");
	ph = Phone(data);
	binf.Write(ph);
	cout << "=======" << endl;
	binf.Output();
	cout << "=======" << endl;
	
	binf.Remove("8139049283");
	cout << "=======" << endl;
	binf.Output();
	cout << "=======" << endl;
	cout << binf.Read(0).String() << endl;
	return 0;
}
