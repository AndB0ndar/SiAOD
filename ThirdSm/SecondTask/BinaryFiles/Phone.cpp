#include "Phone.h"

using namespace std;

Auto::Auto(vector<char *> data) {
	string number = (string)data[0];;
	string address = (string)data[1];;
	string name = (string)data[2];;
}

bool Auto::operator==(const Auto& obj) const {
    return number == obj.number &&
           address == obj.address &&
           name == obj.name &&
}
