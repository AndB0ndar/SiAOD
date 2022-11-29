#include <iostream>
#include <string>
#include "Test.h"

using namespace std;

void Test::testRLE(const string& input, const string& output)
{
	RLE rle;
	string result = rle.Encode(input.c_str());
	if (result == output) {
		cout << "RLE encoding test passed!" << endl;
		cout << "Input: " << input << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "RLE encoding test failed!" << endl;
	}
	result = rle.Decode(result.c_str());
	if (result == input) {
		cout << "RLE decoding test passed!" << endl;
		cout << "Input: " << output << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "RLE decoding test failed!" << endl;
	}
}

void Test::callTestRLE()
{
	testRLE("aaaabbbcc", "4a3b2c");
	testRLE("abbbcc", "a3b2c");
	testRLE("aaaaaaaaaaaavvvvvvvvvvvvdddddddsesssss", "12a13v7d1s5e");
	testRLE("abcdefg", "abcdefg");
	testRLE("xvbnmkswertyu", "xvbnmkswertyu");
}

void Test::testLZ77(const string& input, const string& output)
{
	LZ77 lz77;
	string result = lz77.Encode(input.c_str());
	if (result == output) {
		cout << "LZ77 encoding test passed!" << endl;
		cout << "Input: " << input << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "LZ77 encoding test failed!" << endl;
	}
	result = lz77.Decode(result.c_str());
	if (result == input) {
		cout << "LZ77 decoding test passed!" << endl;
		cout << "Input: " << output << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "LZ77 decoding test failed!" << endl;
	}
}

void Test::callTestLZ77()
{
	testLZ77("0100101010010000101"
			, "(0,0,0)(0,0,1)(2,1,0)(3,2,1)(7,6,0)(14,1,0)(0,0,1)(0,0,0)(0,0,1)");
}

void Test::testLZ78(const string& input, const string& output)
{
	LZ78 lz78;
	string result = lz78.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Output: " << result << endl;
	if (result == output) {
		cout << "LZ78 encoding test passed!" << endl;
		cout << "Input: " << input << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "LZ78 encoding test failed!" << endl;
	}
	result = lz78.Decode(result.c_str());
	if (result == input) {
		cout << "LZ78 decoding test passed!" << endl;
		cout << "Input: " << output << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "LZ78 decoding test failed!" << endl;
	}
}

void Test::callTestLZ78()
{
	testLZ78("лорлоралоранранлоран", "");
}

int main()
{
	Test test;
	//cout << "RLE encoding test" << endl;
	//test.callTestRLE();
	//cout << "LZ77 encoding test" << endl;
	//test.callTestLZ77();
	cout << "LZ78 encoding test" << endl;
	test.callTestLZ78();
	return 0;
}
