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
			vector<char*> data = vector<char*>();
			char *str = const_cast<char *>(line.c_str());

			char *tmp_char = strtok(str, ";");

			while (tmp_char != NULL) {
				data.push_back(tmp_char);
				tmp_char = strtok(NULL, ";");
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
