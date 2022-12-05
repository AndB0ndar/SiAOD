#ifndef HAFFMAN_H
#define HAFFMAN_H

#include <string>
#include <vector>

class Huffman
{
public:
	struct Note {
		std::string alph;
		int weight;
		std::string code;
		double prob;
		Note *left;
		Note *right;
		Note(std::string c, int p, double pr):
			alph(c), weight(p), prob(pr), left(0), right(0) {}
		Note(std::string c, std::string s):
			alph(c), code(s), left(0), right(0) {}
		Note(std::string c, int p, Note *left, Note *right): 
			alph(c), weight(p), left(left), right(right) {}
		~Note();
	};
	Huffman() = default;
	~Huffman() { delete tree; }
	std::string Encode(const std::string& input);
	std::string Decode(const std::string& input);
	void ShowTree() { ShowTree(this->tree, 0); }
	double GetCompressRatio() { return compressRatio; }

	void CompressFile(const std::string& filename, const std::string& compressedFile);
private:
	Note *tree;
	double compressRatio;
	double disperse;

	std::vector<Note*> GetAlph(const std::string& input);
	Note* GetTree(std::vector<Note*>& alph);
	std::vector<Note*> GetCodes(Note *tree);

	void TreeTraversal(Note *tree
			, std::vector<Note*> &res
			, std::string code="");
	void Sort(std::vector<Note*>& prob);
	void ShowTree(Note *tree, int level);
};

#endif
