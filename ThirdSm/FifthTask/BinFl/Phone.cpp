#include <iostream>
#include <cstring>
#include "Phone.h"

using namespace std;

Phone::Phone(vector<const char*> arr)
{
	strncpy(this->id, arr[0], maxstrlen);
	strncpy(this->address, arr[1], maxstrlen);
	strncpy(this->name, arr[2], maxstrlen);
}

Phone::Phone(const Phone &obj)
{
	strncpy(this->id, obj.id, maxstrlen);
	strncpy(this->address, obj.address, maxstrlen);
	strncpy(this->name, obj.name, maxstrlen);
}

void Phone::SetId(const char *id)
{
	strncpy(this->id, id, maxstrlen);
}

void Phone::SetAddr(const char *addr)
{
	strncpy(this->address, addr, maxstrlen);
}

void Phone::SetName(const char *name)
{
	strncpy(this->name, name, maxstrlen);
}

const string Phone::String() const
{
	if (!this->id[0])
		return "null";
	string str;
	str += this->id;
	str += "; ";
	str += this->address;
	str += "; ";
	str += this->name;
	return str;
}
