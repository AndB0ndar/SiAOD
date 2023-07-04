#ifndef LZ78_H
#define LZ78_H

#include <string>
#include <vector>

class LZ78
{
	double compressRatio;
public:
	struct Node {
		int index;
		char c;
		std::string Show() {
			return "(" + std::to_string(index) + "," + c + ")";
		}
	};
	std::vector<Node> Encode(const std::string &input);
	std::string Decode(const std::string& input);
	double GetCompressRatio() { return compressRatio; }
};

#endif
