#ifndef LZ78_H
#define LZ78_H

#include <string>

class LZ78
{
	double compressRatio;
public:
	std::string Encode(const std::string& input);
	std::string Decode(const std::string& input);
	double GetCompressRatio() { return compressRatio; }
};

#endif
