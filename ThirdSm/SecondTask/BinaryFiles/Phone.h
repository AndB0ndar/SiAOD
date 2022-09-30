#ifndef PHONE_OWNER_H
#define PHONE_OWNER_H

#include <string>
#include <vector>

class Phone {
	static const unsigned maxstrlen = 20;
	char number[maxstrlen+1];
	char address[maxstrlen+1];
	char name[maxstrlen+1];
public:
    Phone() {};
    Phone(std::vector<char*> arr);
    Phone(const Phone &obj);
	const char* GetNum() const { return number; }
	const char* GetAddr() const { return address; }
	const char* GetName() const { return name; }
	const std::string String() const;
};

#endif
