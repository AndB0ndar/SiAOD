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
public:
	BinaryFile(const std::string nm): name(nm)
	{ std::fstream f(name, std::ios::trunc); f.close(); }
	void TextToBinary(const std::string textfile);
	void Add(const Phone &ph);
	void Remove(const Phone &ph);
	const Phone* Get(const Phone &ph);
    void Output();
private:
    void Write(const std::vector<Phone> phs);
    void Read(std::vector<Phone> &phs);
};

#endif
