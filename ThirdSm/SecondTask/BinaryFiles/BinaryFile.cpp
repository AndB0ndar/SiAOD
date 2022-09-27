#include <iostream>
#include <fstream>
#include "BinaryFile.h"

using namespace std;

void BinaryFile::Write(string name, vector<Phone> phs)
{
    ofstream out(name, ios::binary | ios::trunc);
    for (Phone ph : phs)
        out.write((char*)&ph, sizeof(Phone));
    out.close();
}

void BinaryFile::Read(string name, vector<Phone> &phs)
{
    ifstream in(name, ios::binary);
    Phone *tmp = new Phone();
    while (in.eof()) {
		in.read((char*)tmp, sizeof(Phone));
        phs.push_back(*tmp);
	}
    in.close();
}

void BinaryFile::Output(string name)
{
    vector<Phone> phones;
    Read(name, phones);
    for (Phone ph : phones)
        cout << ph.String() << endl;
}

const Phone& BinaryFile::Get(string name, int index) const
{
    ifstream in(name, ios::binary);
    static Phone phone;
    in.seekg(index * sizeof(Phone));
    in.read((char*)&phone, sizeof(Phone));
    in.close();
    return phone;
}

void BinaryFile::DellPhone(string name, int index)
{
    vector<Phone> phones;
    Read(name, phones);
    phones.erase(phones.begin() + index);
    Write(name, phones);
}
