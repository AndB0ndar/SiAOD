#ifndef SHANFAN_H
#define SHANFAN_H

#include <string>
#include <vector>

class ShanFan
{
public:
	struct Code {
		std::string alph;
		int weight;
		std::string code;
		Code *left;
		Code *right;
		Code() = default;
		Code(std::string c, int p):
			alph(c), weight(p), left(0), right(0) {}
		Code(std::string c, std::string s):
			alph(c), code(s), left(0), right(0) {}
		Code(std::string c, int p, Code *left, Code *right): 
			alph(c), weight(p), left(left), right(right) {}
		~Code();
	};
	ShanFan() = default;
	~ShanFan() { delete tree; }
	std::string Encode(const std::string& input);
	std::string Decode(const std::string& input);
	void ShowTree() { ShowTree(this->tree, 0); }
	double GetCompressRatio() { return compressRatio; }
private:
	Code *tree;
	double compressRatio;
	std::vector<Code*> GetAlph(const std::string& input);
	Code* GetTree(std::vector<Code*>& alph);
	std::vector<Code*> GetCodes(Code *tree);
	void Balance(std::vector<Code*> alph
			, std::vector<Code*> &lef
			, std::vector<Code*> &right
			);
	int Weight(std::vector<Code*> &vec);
	void Sort(std::vector<Code*> &vec);

	void TreeTraversal(Code *tree
			, std::vector<Code*> &res
			, std::string code="");
	void ShowTree(Code *tree, int level);
};

#endif
