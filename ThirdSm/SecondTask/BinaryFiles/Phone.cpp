#include "Phone.h"

using namespace std;

Phone::Phone(vector<char *> data) {
	this->number = (string)(data[0]);
	this->address = (string)(data[1]);
	this->name = (string)(data[2]);
}

bool Phone::operator==(const Phone& obj) const {
    return number == obj.number 
		&& address == obj.address 
		&& name == obj.name;
}
