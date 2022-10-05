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
	for (unsigned index = 0; index < phones.size(); index++) { 
		Add(phones[index], index);
	}
}


void BinaryFile::Add(const Phone &ph, const int shift)
{
	if (shift != -1) {
		this->size = shift+1;
	} else {
		this->size++;
	}

    ofstream out(this->name, ios::in | ios::out | ios::binary);

	this->table.Insert(ph.GetId(), this->size-1);
    out.seekp(this->size-1 * sizeof(Phone), ios::beg);
	out.write(reinterpret_cast<const char*>(&ph), sizeof(Phone));

    out.close();
}

void BinaryFile::Remove(const Phone &ph)
{
	int index = this->table.GetShift(ph.GetId());
	if (index == -1)
		return;

	vector<Phone> phones;
	Read(phones);
	phones.erase(phones.begin()+index);
	table.Clear();

	for (unsigned index = 0; index < phones.size(); index++) { 
		Add(phones[index], index);
	}
}

const Phone* BinaryFile::Get(const Phone &ph)
{
	vector<Phone> phones;
	Read(phones);

	int shift = this->table.GetShift(ph.GetId());
	if (shift == -1)
		return 0;

	return &phones[shift];
}

void BinaryFile::Output()
{
    vector<Phone> phones;
    Read(phones);
    for (Phone ph: phones)
		cout << ph.String() << endl;
}

void BinaryFile::Write(const vector<Phone> phs)
{
    ofstream out(this->name, ios::binary | ios::trunc);
    for (Phone ph: phs) {
        out.write(reinterpret_cast<const char*>(&ph), sizeof(Phone));
	}
    out.close();
}

void BinaryFile::Read(vector<Phone> &phs)
{
	phs.clear();
    ifstream in(this->name, ios::binary);
    Phone tmp;
	in.read(reinterpret_cast<char *>(&tmp), sizeof(Phone));
    while (!in.eof()) {
		phs.push_back(tmp);
		in.read(reinterpret_cast<char *>(&tmp), sizeof(Phone));
	}
    in.close();
}
