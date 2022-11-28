#include <iostream>
#include <string>
#include "Test.h"

using namespace std;

// test RLE
void Test::testRLE(const string& input, const string& output)
{
	RLE rle;
	string result = rle.Encode(input.c_str());
	if (result == output) {
		cout << "RLE encoding test passed!" << endl;
		// output the result
		cout << "Input: " << input << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "RLE encoding test failed!" << endl;
	}
	result = rle.Decode(result.c_str());
	if (result == input) {
		cout << "RLE decoding test passed!" << endl;
		// output the result
		cout << "Input: " << output << endl;
		cout << "Output: " << result << endl;
	} else {
		cout << "RLE decoding test failed!" << endl;
	}
}

// call test RLE
// test RLE encoding and decoding
// test case 1: "aaaabbbcc" -> "4a3b2c"
// test case 2: "abbbcc" -> "a3b2c"
// test case 3: "aaaaaaaaaaaavvvvvvvvvvvvdddddddsesssss" -> "12a13v7d1s5e"
// test case 4: "abcdefg" -> "abcdefg"
// test case 5: "xvbnmkswertyu" -> "xvbnmkswertyu"
void Test::callTestRLE()
{
	testRLE("aaaabbbcc", "4a3b2c");
	testRLE("abbbcc", "a3b2c");
	testRLE("aaaaaaaaaaaavvvvvvvvvvvvdddddddsesssss", "12a13v7d1s5e");
	testRLE("abcdefg", "abcdefg");
	testRLE("xvbnmkswertyu", "xvbnmkswertyu");
}

// test LZ77
void Test::testLZ77(const string& input, const string& output)
{
	LZ77 lz77;
	string result = lz77.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Output: " << result << endl;
	if (result == output) {
		cout << "LZ77 encoding test passed!" << endl;
	} else {
		cout << "LZ77 encoding test failed!" << endl;
	}
	result = lz77.Decode(result.c_str());
	cout << "Input: " << output << endl;
	cout << "Output: " << result << endl;
	if (result == input) {
		cout << "LZ77 decoding test passed!" << endl;
	} else {
		cout << "LZ77 decoding test failed!" << endl;
	}
}

// call test LZ77 encoding and decoding
// test case 1: "0100101010010000101" -> "(0,0,0)(0,0,1)(2,1,0)(3,2,1)(7,6,0)(14,1,0)(0,0,1)(0,0,0)(0,0,1)"
void Test::callTestLZ77()
{
	testLZ77("0100101010010000101"
			, "(0,0,0)(0,0,1)(2,1,0)(3,2,1)(7,6,0)(14,1,0)(0,0,1)(0,0,0)(0,0,1)");
}

int main()
{
	Test test;
	test.callTestLZ77();
	return 0;
}
