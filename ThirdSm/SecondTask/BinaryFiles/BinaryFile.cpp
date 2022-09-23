#include <iostream>
#include <fstream>
#include "BinaryFile.h"

using namespace std;

void BinaryFile::Write(string name, vector<Phone> phs) {
    ofstream out(name, ios::binary);
    for (Auto ph : phs)
        out.write((char*)&ph, sizeof(Auto));
    out.close();
}

void BinaryFile::Read(string name, vector<Phone> &phs) {
    ifstream in(name, ios::binary);
    Auto *tmp = new Auto();
    while (in.eof()) {
		in.read((char*)tmp, sizeof(Auto))
        autos.push_back(*tmp);
	}
    in.close();
}

void BinaryFile::Out(string name) {
    vector<Phone> phones;
    Read(name, phones);
    for (Auto ph : phones)
        cout << ph.String() << endl;
}

Phone BinaryFile::Get(string name, int index) {
    ifstream in(name, ios::binary);
    Phone tmp;
    in.seekg(index * sizeof(Auto));
    in.read((char*)&tmp, sizeof(Auto));
    in.close();
    return tmp;
}

void BinaryFile::DellPhone(string name, int index) {
    vector<Phone> phones;
    Read(name, phones);
    phones.erase(autos.begin() + index);
    Write(name, phones);
}
