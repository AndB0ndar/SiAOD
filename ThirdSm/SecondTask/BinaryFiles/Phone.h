#ifndef PHONE_OWNER_H
#define PHONE_OWNER_H

#include <string>
#include <vector>

class Phone {
	std::string number;
	std::string address;
	std::string name;
public:
    Phone(): number(""), address(""), name("") {}
    Phone(std::vector<char*> data);
    bool operator==(const Phone& obj) const;
	const std::string String() const
	{ return number + "; " + address + "; " + name + '\n'; }
};

#endif
