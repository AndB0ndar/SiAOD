#include <iostream>
#include <string>
#include "Test.h"

using namespace std;

void Test::testRLE(const string& input)
{
	RLE rle;
	string result = rle.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
}

void Test::callTestRLE()
{
	testRLE("aaaabbbcc");
	testRLE("abbbcc");
	testRLE("aaaaaaaaaaaavvvvvvvvvvvvdddddddsesssss");
}

void Test::testLZ77(const string& input)
{
	LZ77 lz77;
	string result = lz77.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
}

void Test::callTestLZ77()
{
	testLZ77("0100101010010000101");
}

void Test::testLZ78(const string& input)
{
	LZ78 lz78;
	string result = lz78.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
}

void Test::callTestLZ78()
{
	testLZ78("лорлоралоранранлоран");
}

void Test::testShanFan(const string& input)
{
	ShanFan shanFan;
	string result = shanFan.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
}

void Test::callTestShanFan()
{
	testShanFan("aaaabbbcc");
}

int main()
{
	Test test;
	//cout << "RLE encoding test" << endl;
	//test.callTestRLE();
	//cout << "LZ77 encoding test" << endl;
	//test.callTestLZ77();
	//cout << "LZ78 encoding test" << endl;
	//test.callTestLZ78();
	cout << "ShanFan encoding test" << endl;
	test.callTestShanFan();
	return 0;
}
