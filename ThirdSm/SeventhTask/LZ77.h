#ifndef LZ77_H
#define LZ77_H

#include <string>

class LZ77
{
	static const int buffer_size = 10;
	double compressRatio;
public:
	std::string Encode(const std::string& input);
	std::string Decode(const std::string& input);
	double GetCompressRatio() { return compressRatio; }
private:
	void FindLongestMatch(const std::string& buffer, int& offset, int& length);
};

#endif
