#ifndef DATA_FILE_H
#define DATA_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include "./BinFl/BinaryFile.h"
#include "./BinFl/Phone.h"
#include "./MngHeshTabl/HeshTable.h"

class Data
{
	BinaryFile file;
	HeshTable table;
public:
	Data(std::string bin, std::string txt): file(bin), table()
	{ file.TextToBinary(txt); }
	Data(BinaryFile bf): file(bf), table() {}
	void SaveEntry(const int shift);
	void Remove(const char *id);
	Phone Search(const char *id);
	void Output() const;
	unsigned GetSizeFile() const { return file.GetSize(); }
};

#endif
