#ifndef LZ77_H
#define LZ77_H

#include <string>

class LZ77
{
public:
	void Encode(const std::string& input, std::string& output);
	void Decode(const std::string& input, std::string& output);
private:
	void FindLongestMatch(const std::string& input, int& offset, int& length);
};

#endif
