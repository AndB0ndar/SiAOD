#include <iostream>
#include <cstring>
#include "RLE.h"

using namespace std;

const char* RLE::Encode(const char* input)
{
	int count = 1;
	int length = strlen(input);
	char* output = new char[length * 2];
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (input[i] == input[i + 1]) {
			count++;
		} else {
			output[j] = count + '0';
			j++;
			output[j] = input[i];
			j++;
			count = 1;
		}
	}
	output[j] = '\0';
	return output;
}

const char* RLE::Decode(const char* input)
{
	int length = strlen(input);
	char* output = new char[length];
	int j = 0;
	for (int i = 0; i < length; i += 2) {
		for (int k = 0; k < input[i] - '0'; k++) {
			output[j] = input[i+1];
			j++;
		}
	}
	output[j] = '\0';
	return output;
}
