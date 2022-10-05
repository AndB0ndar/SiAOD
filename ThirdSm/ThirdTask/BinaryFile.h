#ifndef BINARY_FILE_H
#define BINARY_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include "Phone.h"
#include "MngHeshTabl/HeshTable.h"

class BinaryFile
{
	std::string name;
	int size;
	HashTable table;
public:
	BinaryFile(const std::string nm): name(nm), size(0)
	{ Clear(); }
	void TextToBinary(const std::string textfile);
	void Add(const Phone &ph, const int shift=-1);
	void Remove(const char *id);
	const Phone* Search(const char *id);
    void Output();
private:
    void Write(const Phone &ph);
    void Read(std::vector<Phone> &phs);
	void Clear()
	{ std::ofstream f(name, std::ios::trunc); f.close(); }
};

#endif
