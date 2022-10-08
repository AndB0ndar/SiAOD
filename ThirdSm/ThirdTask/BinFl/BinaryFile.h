#ifndef BINARY_FILE_H
#define BINARY_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include "Phone.h"

class BinaryFile
{
	std::string name;
	int size;
public:
	BinaryFile(const std::string nm): name(nm), size(0)
	{ Clear(); }
	void TextToBinary(const std::string textfile);
    void Write(const Phone &ph);
	void Remove(const char *id);
    Phone Read(const int shift) const;
	void Output();
private:
	void Clear()
	{ std::ofstream f(name, std::ios::trunc); f.close(); }
};

#endif
