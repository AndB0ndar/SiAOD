#ifndef BINARY_FILE_H
#define BINARY_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include "Phone.h"

class BinaryFile
{
	std::string name;
	unsigned size;
public:
	BinaryFile(const std::string nm): name(nm), size(0) { Clear(); }
	BinaryFile(const BinaryFile &bf): name(bf.GetName()), size(bf.GetSize()) {}
	int Generate(const std::string textfile);
	void Search(const std::string textfile, const char *id);
    Phone Read(const int shift) const;
    void Write(const Phone &ph);

	//void Remove(const char *id);
	const std::string GetName() const { return name; }
	unsigned GetSize() const { return size; }
	void Output() const;
private:
	void Clear()
	{ std::ofstream f(name, std::ios::trunc); f.close(); }
};

#endif
