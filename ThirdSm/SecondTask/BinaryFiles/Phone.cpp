#include <iostream>
#include <cstring>
#include "Phone.h"

using namespace std;

Phone::Phone(vector<char*> arr) {
	strncpy(this->number, arr[0], maxstrlen);
	strncpy(this->address, arr[1], maxstrlen);
	strncpy(this->name, arr[2], maxstrlen);
}

Phone::Phone(const Phone &obj)
{
	strncpy(this->number, obj.number, maxstrlen);
	strncpy(this->address, obj.address, maxstrlen);
	strncpy(this->name, obj.name, maxstrlen);
}

const string Phone::String() const
{
	string str;
	str += this->number;
	str += "; ";
	str += this->address;
	str += "; ";
	str += this->name;
	return str;
}
