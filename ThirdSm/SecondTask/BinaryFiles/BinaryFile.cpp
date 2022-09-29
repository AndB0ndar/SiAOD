#include <iostream>
#include <fstream>
#include "BinaryFile.h"

using namespace std;

void BinaryFile::Write(const vector<Phone> phs) {
    ofstream out(this->name, ios::binary);
    for (Phone ph: phs) {
        out.write(reinterpret_cast<const char*>(&ph), sizeof(Phone));
	}
    out.close();
}

void BinaryFile::Read(vector<Phone> &phs) {
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

void BinaryFile::Output() {
    vector<Phone> phones;
    Read(phones);
    for (Phone ph: phones)
        cout << ph.String() << endl;
}

const Phone& BinaryFile::Get(const unsigned index) const {
    ifstream in(this->name, ios::binary);
    static Phone tmp;
    in.seekg(index * sizeof(Phone), ios::beg);
    in.read(reinterpret_cast<char *>(&tmp), sizeof(Phone));
    in.close();
    return tmp;
}

void BinaryFile::DellPhone(const unsigned index) {
    vector<Phone> phones;
    Read(phones);

	static Phone last(phones.back());
    phones.erase(phones.begin()+index);
    phones.insert(phones.begin()+index, last);
    phones.erase(phones.end());

    Write(phones);
}
