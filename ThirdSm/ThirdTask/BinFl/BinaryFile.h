#ifndef BINARY_FILE_H
#define BINARY_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include "Phone.h"
#include "../MngHashTabl/HashTable.h"

class BinaryFile
{
	std::string name;
	HashTable table;
	int size;
public:
	BinaryFile(const std::string nm): name(nm), size(0)
	{ std::fstream f(name, std::ios::trunc); f.close(); }
	void TextToBinary(const std::string textfile);
	void Add(const Phone &ph, const int shift=-1);
	void Remove(const Phone &ph);
	const Phone* Get(const Phone &ph);
    void Output();
private:
    void Write(const Phone &ph);
    void Read(std::vector<Phone> &phs);
};

#endif
