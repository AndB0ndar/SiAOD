#ifndef READ_TEXT_FILE_H
#define READ_TEXT_FILE_H

#include <vector>
#include <string>

#include "Phone.h"

class TextFile {
public:
	std::vector<Phone> Read(std::string name);
    void Write(std::string name, std::vector<Phone> phs);
};


#endif
