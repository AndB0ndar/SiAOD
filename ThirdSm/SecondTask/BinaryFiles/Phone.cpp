#include "Phone.h"

using namespace std;

Phone::Phone(vector<string> data) {
	this->number = data[0];
	this->address = data[1];
	this->name = data[2];
}

Phone::Phone(const Phone &obj)
{
	this->number = obj.number.substr();
	this->address = obj.address.substr();
	this->name = obj.name.substr();
}

bool Phone::operator==(const Phone& obj) const {
    return number == obj.number 
		&& address == obj.address 
		&& name == obj.name;
}
