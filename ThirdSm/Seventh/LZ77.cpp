#include <iostream>
#include <string>
#include "LZ77.h"

using namespace std;

void LZ77::FindLongestMatch(const string& buffer, int& offset, int& length)
{
	int i = offset, j = 0;
	int maxLength = 0, maxOffset = 0;
	int len = buffer.size();
	while (j < i && i < len) {
		int k = 0;
		while (i+k < len && j+k < len 
				&& buffer[i+k] == buffer[j+k]) {
			k++;
		}
		if (k > maxLength) {
			maxLength = k;
			maxOffset = i - j;
		}
		j++;
	}
	offset = maxOffset;
	length = maxLength;
}

// encode
string LZ77::Encode(const string& input)
{
	string output;
	int offset = 0;
	int length = 0;
	int len = input.length();
	int i = 0;
	while (i < len) {
		int i_buff = (i - buffer_size) > 0 ? (i - buffer_size) : 0;
		offset = i;
		FindLongestMatch(input.substr(i_buff), offset, length);
		output += "(" + to_string(offset)
			+ "," + to_string(length)
			+ "," + input[i + length]
			+ ")";
		i += length + 1;
	}
	return output;
}

// decode
string LZ77::Decode(const string& input)
{
	string output;
	int len = input.length();
	int i = 0;
	while (i < len) {
		int offset = 0, length = 0;
		if (input[i] == '(') {
			i++;
			while (input[i] != ',') {
				offset = offset * 10 + (input[i] - '0');
				i++;
			}
			i++;
			while (input[i] != ',') {
				length = length * 10 + (input[i] - '0');
				i++;
			}
			i++;
			output += output.substr(output.length() - offset, length);
			output += input[i];
			i += 2;
		} else {
			cout << "Error: " << input[i] << endl;
			return "";
		}
	}
	return output;
}
