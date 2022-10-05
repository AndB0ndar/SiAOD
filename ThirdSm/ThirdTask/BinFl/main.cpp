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
	binf.Add(ph);

	data.clear();
	data.push_back("8204");
	data.push_back("kjahd");
	data.push_back("SVYASLJ");
	ph = Phone(data);
	binf.Add(ph);

	data.clear();
	data.push_back("?");
	data.push_back("nscslv");
	data.push_back("IQJSLS");
	ph = Phone(data);
	binf.Add(ph);

	data.clear();
	data.push_back("8204");
	data.push_back("kjahd");
	data.push_back("SVYASLJ");
	ph = Phone(data);
	binf.Add(ph);
	binf.Output();
}
