#ifndef TEST_H
#define TEST_H

#include "RLE.h"
#include "LZ77.h"
#include "LZ78.h"
#include "ShanFan.h"
#include "Huffman.h"

class Test
{
public:
	Test() = default;
	~Test() = default;
	// test RLE
	void testRLE(const std::string& input);
	// call test RLE
	void callTestRLE();

	// test LZ77
	void testLZ77(const std::string& input);
	// call test LZ77
	void callTestLZ77();

	// test LZ78
	void testLZ78(const std::string& input);
	// call test LZ78
	void callTestLZ78();

	// test ShanFan
	void testShanFan(const std::string& input);
	// call test ShanFan
	void callTestShanFan();

	// test Huffman
	void testHuffman(const std::string& input);
	// call test Huffman
	void callTestHuffman();
};

#endif
