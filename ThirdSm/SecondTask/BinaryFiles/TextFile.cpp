#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "TextFile.h"

using namespace std;

vector<Phone> TextFile::Read(string name)
{
    vector<Phone> result = vector<Phone>();
    ifstream fin (name);
    if (!fin) {
        cout << "File doesn't exist\n";
    } else {
        string line;
        while (getline(fin, line)) {
            vector<char*> data = vector<char*>();
            char *str = const_cast<char *>(line.c_str());
            char *tmp_char;
            while ((tmp_char = strtok(str, ";")) != 0) {
                data.push_back(tmp_char);
            }
            result.emplace_back(data);
        }
        fin.close();
    }
	return result;
}

void TextFile::Write(string name, vector<Phone> phs) {
    ofstream fout(name);
    for (Phone ph: phs)
        fout << ph.String() << endl;
    fout.close();
}
