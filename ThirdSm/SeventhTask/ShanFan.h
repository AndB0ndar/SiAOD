#ifndef SHANFAN_H
#define SHANFAN_H

#include <string>
#include <vector>

class ShanFan
{
public:
	struct Code {
		char ch;
		double prob;
		std::string code;
		Code(char c, double p, std::string s) : ch(c), prob(p), code(s) {}
	};
	std::string Encode(const std::string& input);
	std::string Decode(const std::string& input);
private:
	std::vector<Code> GetProb(const std::string& input);
	std::vector<Code> GetCodes(std::vector<Code>& prob);
	void Sort(std::vector<Code>& prob);
	std::string toBinary(double num, int precision = 16);
};

#endif
