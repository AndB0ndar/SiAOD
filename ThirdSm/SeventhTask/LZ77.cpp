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
	for (int i = 0; i < len; i += length + 1) {
		int i_buff = (i - buffer_size) > 0 ? (i - buffer_size) : 0;
		string buffer = input.substr(i_buff);
		offset = i - i_buff;
		FindLongestMatch(buffer, offset, length);
		output += to_string(offset)
			+ to_string(length)
			+ input[i + length];
	}
	compressRatio = len / (double)output.length();
	return output;
}

// decode
string LZ77::Decode(const string& input)
{
	string output;
	int offset = 0;
	int length = 0;
	int len = input.length();
	for (int i = 0; i < len; i += 3) {
		offset = input[i] - '0';
		length = input[i+1] - '0';
		string str = output.substr(output.length() - offset, length);
		str += input[i+2];
		output += str;
	}
	return output;
}
