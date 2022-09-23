#include <iostream>
#include <fstream>
#include <cstdio>
#include "module.h"

using namespace std;

void create_file(string name_file)
{
	ofstream fout;
	fout.open(name_file, ios::out | ios::trunc);
	unsigned count_line = 2;
	unsigned count_figure = 2;
	cout << count_line << "+=+" << count_figure << endl;
	for (unsigned i = 0; i < count_line; i++) {
		for (unsigned j = 0; j < count_figure - 1; j++) {
			fout << rand()%50 << " ";
		}
		fout << rand()%50 << endl;
	}
	fout.close();
}

void out_file(string name_file) {
	ifstream fin;
	fin.open(name_file, ios::in);
	string line;
	while (!fin.eof()) {
		getline(fin, line);
		cout << line;
		if (fin.peek() != EOF)
			cout << endl;
	}
	cout << endl;
	fin.close();
}

void add_after(string name_file, string new_line)
{
	ofstream fout;
	fout.open(name_file, ios::out | ios::app);
	fout << new_line << endl;
	fout.close();
}

int geti(string name_file, int index)
{
	index++;
	int x = -1;
	ifstream fin;
	fin.open(name_file, ios::in);
	int i;
	for (i = 1; i < index && !fin.eof(); i++) {
		fin >> x;
		fin.get();
	}
	if (!fin.eof() && i == index) {
		fin >> x;
		fin.get();
	}
	fin.close();
	return x;
}

int count_figure(string name_file)
{
	unsigned count = 0;
	ifstream fin;
	fin.open(name_file, ios::in);
	char c;
	while ((c = fin.get()) != EOF) {
		if ((c >= '0') && (c <= '9')) {
			int tmp;
			fin.unget();
			fin >> tmp;
			count++;
		}
	}
	fin.close();
	return count;
}

void add_befor(string name_file, string new_line)
{
	string tmp_name = "tmp_"+name_file;

	ofstream tmp_fout;
	tmp_fout.open(tmp_name, ios::out | ios::trunc);

	ifstream fin;
	fin.open(name_file, ios::in);

	tmp_fout << new_line << endl;
	while(!fin.eof()) {
		string line;
		getline(fin, line);
		tmp_fout << line << endl;
	}
	fin.close();
	tmp_fout.close();

	ifstream tmp_fin;
	tmp_fin.open(tmp_name, ios::in);

	ofstream fout;
	fout.open(name_file, ios::out | ios::trunc);
	while(!tmp_fin.eof()) {
		string line;
		getline(tmp_fin, line);
		fout << line;
		if (tmp_fin.peek() != EOF)
			fout << endl;
	}
	fout.close();
	tmp_fin.close();
}
