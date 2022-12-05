#include <iostream>
#include <locale.h>
#include <string>
#include "Test.h"

using namespace std;

void Test::testRLE(const string& input)
{
	RLE rle;
	string result = rle.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
	cout << "Compress Ratio: " << rle.GetCompressRatio() << endl;
}

void Test::callTestRLE()
{
	cout << "Test RLE" << endl;
	cout << "========" << endl;
	testRLE("aaaaaaaaaaaavvvvvvvvvvvvdddddddsesssss");
	cout << "========" << endl;
	testRLE("asdfghqwertyuiop[zxcvbnm,.edcftyuiop");
	cout << endl;
}

void Test::testLZ77(const string& input)
{
	LZ77 lz77;
	string result = lz77.Encode(input.c_str());
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
	cout << "Compress Ratio: " << lz77.GetCompressRatio() << endl;
	result = lz77.Decode(result);
	cout << "Decode: " << result << endl;
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
	cout << "Compress Ratio: " << lz78.GetCompressRatio() << endl;
	result = lz78.Decode(result);
	cout << "Decode: " << result << endl;
}

void Test::callTestLZ78()
{
	testLZ78("лорлоралоранранлоран");
}

void Test::testShanFan(const string& input)
{
	ShanFan shanFan;
	string result = shanFan.Encode(input.c_str());
	shanFan.ShowTree();
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
	cout << "Compress Ratio: " << shanFan.GetCompressRatio() << endl;
	result = shanFan.Decode(result);
	cout << "Decode: " << result << endl;
}

void Test::callTestShanFan()
{
	testShanFan(inputShanFan);
}

void Test::testHuffman(const string& input)
{
	Huffman huffman;
	string result = huffman.Encode(input.c_str());
	huffman.ShowTree();
	cout << "Input: " << input << endl;
	cout << "Encode: " << result << endl;
	cout << "Compress Ratio: " << huffman.GetCompressRatio() << endl;
	result = huffman.Decode(result);
	cout << "Decode: " << result << endl;
}

void Test::callTestHuffman()
{
	testHuffman(inputHuffman);
}

void Test::testCompressFile()
{
	Huffman huffman;
	huffman.CompressFile("text.txt", "Compresse.bin");
}

int main()
{
	setlocale(LC_ALL,"Russian");
	Test test;
	//cout << "RLE encoding test" << endl;
	//test.callTestRLE();
	//cout << "LZ77 encoding test" << endl;
	//test.callTestLZ77();
	//cout << "LZ78 encoding test" << endl;
	//test.callTestLZ78();
	//cout << "ShanFan encoding test" << endl;
	//test.callTestShanFan();
	//cout << "Huffman encoding test" << endl;
	//test.callTestHuffman();
	
	test.testCompressFile();
	
	return 0;
}
