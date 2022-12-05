#include <iostream>
#include <vector>
#include "LZ78.h"

using namespace std;

string LZ78::Encode(const string& input)
{
	string output;
	vector<string> dictionary;
	int i = 0;
	int len = input.length();
	while (i < len) {
		int index = 0;
		string str = input.substr(i, 1);
		string buff = str;
		size_t j = 0;
		while (j < dictionary.size()) {
			int size = dictionary[j].length();
			string s, sufx;
			if (i + 1 >= len) {
				s = buff;
				sufx = '\0';
			} else if (i + size >= len) {
				sufx = input.substr(i+1);
				s = buff + sufx;
				sufx += '\0';
			} else {
				sufx = input.substr(i+1, size);
				s = (sufx.length() == 1)
					? buff : buff + sufx.substr(0, sufx.length()-1);
			}
			if (s == dictionary[j]) {
				str = buff + sufx;
				index = j + 1;
			}
			j++;
		}
		dictionary.push_back(str);
		output += '(' + to_string(index) + ',' + str.back() + ')';
		i += str.length();
	}
	compressRatio = len / (double)output.length();
	return output;
}

string LZ78::Decode(const string& input)
{
	string output;
	vector<string> dictionary;
	int i = 0;
	int len = input.length();
	while (i < len) {
		int index = 0;
		string str;
		while (input[i] != '(') {
			i++;
		}
		i++;
		while (input[i] != ',') {
			index = index * 10 + input[i] - '0';
			i++;
		}
		i++;
		str = input[i];
		i += 2;
		if (index == 0) {
			dictionary.push_back(str);
		} else {
			str = dictionary[index-1] + str;
			dictionary.push_back(str);
		}
		output += str;
	}
	return output;
}
