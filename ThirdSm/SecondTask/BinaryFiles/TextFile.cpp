#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "ReaderSource.h"

using namespace std;

vector<Phone> TextFile::Read(string name)
{
    vector<Phone> result = vector<Phone>();
    ifstream fin (name);
    if (!fin) {
        cout << "File doesn't exist\n";
        return result;
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
            result.emplace_back(data);
        }
        fin.close();
        return result;
    }
}

void ReaderSource::Write(string name, vector<Auto> phs) {
    ofstream fout(name);
    for (Auto ph: phs)
        fout << ph.String() << endl;
    fout.close();
}
