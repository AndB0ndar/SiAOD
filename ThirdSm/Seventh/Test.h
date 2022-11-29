#ifndef TEST_H
#define TEST_H

#include "RLE.h"
#include "LZ77.h"
#include "LZ78.h"

class Test
{
public:
	Test() = default;
	~Test() = default;
	// test RLE
	void testRLE(const std::string& input, const std::string& output);
	// call test RLE
	void callTestRLE();

	// test LZ77
	void testLZ77(const std::string& input, const std::string& output);
	// call test LZ77
	void callTestLZ77();

	// test LZ78
	void testLZ78(const std::string& input, const std::string& output);
	// call test LZ78
	void callTestLZ78();
};

#endif
