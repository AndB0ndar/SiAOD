#include <iostream>
#include <fstream>
#include <cstring>
#include "BinaryFile.h"
#include "TextFile.h"

using namespace std;

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
    static Phone tmp;
	in.read(reinterpret_cast<char *>(&tmp), sizeof(Phone));
    while (!in.eof()) {
        phs.push_back(tmp);
		in.read(reinterpret_cast<char *>(&tmp), sizeof(Phone));
	}
    in.close();
}

void BinaryFile::Output()
{
    vector<Phone> phones;
    Read(phones);
    for (Phone ph: phones)
        cout << ph.String() << endl;
}

const Phone& BinaryFile::Get(const unsigned index) const
{
    ifstream in(this->name, ios::binary);
    static Phone tmp;
    in.seekg(index * sizeof(Phone), ios::beg);
    in.read(reinterpret_cast<char *>(&tmp), sizeof(Phone));
    in.close();
    return tmp;
}

void BinaryFile::DellPhone(const unsigned index)
{
    vector<Phone> phones;
    Read(phones);

	static Phone last(phones.back());
    phones.erase(phones.begin()+index);
    phones.insert(phones.begin()+index, last);
    phones.erase(phones.end());

    Write(phones);
}

void BinaryFile::GenNwFile(const string num, const string name)
{
    vector<Phone> phones;
    vector<Phone> tmp_phones;
    Read(tmp_phones);

	for(unsigned i = 0; i < tmp_phones.size(); i++){
		Phone ph = tmp_phones[i];
		if (0 == strncmp(ph.GetNum(), num.c_str(), 3))
			phones.push_back(ph);
    }

	TextFile tfl(name);
    tfl.Write(phones);
}

void BinaryFile::DellCertPhone(const char ch)
{
    vector<Phone> phones;
    vector<Phone> tmp_phones;
    Read(tmp_phones);

	for (Phone ph: tmp_phones) {
		if (ph.GetNum()[0] != ch) {
			phones.push_back(ph);
		}
	}

    Write(phones);
}
