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
		Note *left;
		Note *right;
		Note(std::string c, int p):
			alph(c), weight(p), left(0), right(0) {}
		Note(std::string c, std::string s):
			alph(c), code(s), left(0), right(0) {}
		Note(std::string c, int p, Note *left, Note *right): 
			alph(c), weight(p), left(left), right(right) {}
	};
	Huffman() = default;
	~Huffman() = default;
	std::string Encode(const std::string& input);
	std::string Decode(const std::string& input);
	void ShowTree();
private:
	Note *tree;
	std::vector<Note*> GetAlph(const std::string& input);
	Note* GetTree(std::vector<Note*>& alph);
	std::vector<Note*> GetCodes(Note *tree);
	void TreeTraversal(Note *tree, std::vector<Note*> &res, std::string code="0");
	void Sort(std::vector<Note*>& prob);
	void ShowTree(Note *tree, int level);
};

#endif
