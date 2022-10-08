#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "BinaryFile.h"
#include "TextFile.h"

using namespace std;

void BinaryFile::TextToBinary(const string textfile)
{
	TextFile tf(textfile);
	vector<Phone> phones;
	tf.Read(phones);
	for (unsigned index = 0; index < phones.size(); index++)
		Write(phones[index]);
}

void BinaryFile::Write(const Phone &ph)
{
    ofstream out(this->name, ios::binary | ios::app);
	out.write(reinterpret_cast<const char*>(&ph), sizeof(Phone));
    out.close();
}

void BinaryFile::Remove(const char *id)
{
    ifstream in(this->name, ios::binary);
    vector<Phone> phones;
	Phone ph;
	in.read(reinterpret_cast<char *>(&ph), sizeof(Phone));
    while (!in.eof()) {
		if (0 != strcmp(ph.GetId(), id))
			phones.push_back(ph);;
		in.read(reinterpret_cast<char *>(&ph), sizeof(Phone));
	}
	Clear();
	for (unsigned i = 0; i < phones.size(); i++)
		Write(phones[i]);
    in.close();
}

Phone BinaryFile::Read(const int shift) const
{
    Phone tmp;
    ifstream in(this->name, ios::binary);
	in.seekg(shift*sizeof(Phone), ios::beg);
	in.read(reinterpret_cast<char *>(&tmp), sizeof(Phone));
    in.close();
	return tmp;
}

void BinaryFile::Output()
{
    ifstream in(this->name, ios::binary);
    Phone ph;
	in.read(reinterpret_cast<char *>(&ph), sizeof(Phone));
    while (!in.eof()) {
		cout << ph.String() << endl;
		in.read(reinterpret_cast<char *>(&ph), sizeof(Phone));
	}
    in.close();
}
