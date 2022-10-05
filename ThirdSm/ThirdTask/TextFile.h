#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include <vector>
#include <string>

#include "Phone.h"

class TextFile {
	std::string name;
public:
	TextFile(std::string nm): name(nm) {}
	void Read(std::vector<Phone> &phs);
    void Write(const std::vector<Phone> phs);
};


#endif
