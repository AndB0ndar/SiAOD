#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "TextFile.h"

using namespace std;

void TextFile::Read(vector<Phone> &phs)
{
	phs.clear();
    ifstream fin(this->name);
    if (!fin) {
        cout << "File doesn't exist\n";
    } else {
        string line;
        while (getline(fin, line)) {
            vector<string> data = vector<string>();
			size_t start = 0;
			size_t edge = line.find(";", start);
			while (edge != string::npos) {
				string str = line.substr(start, edge-start);
				data.push_back(str);

				start = edge + 2;
				edge = line.find(";", start);
			}
            phs.emplace_back(data);
        }
        fin.close();
    }
}

void TextFile::Write(const vector<Phone> phs) {
    ofstream fout(this->name, ios::trunc);
    for (Phone ph: phs) {
        fout << ph.String() << endl;
	}
    fout.close();
}
