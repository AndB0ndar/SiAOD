#include <iostream>
#include <vector>
#include <map>
#include "Huffman.h"

using namespace std;

void Huffman::Sort(vector<Note*>& prob)
{
	for (size_t i = 0; i < prob.size(); i++) {
		for (size_t j = i + 1; j < prob.size(); j++) {
			if (prob[i]->weight < prob[j]->weight) {
				Note *temp = prob[i];
				prob[i] = prob[j];
				prob[j] = temp;
			}
		}
	}
}

vector<Huffman::Note*> Huffman::GetAlph(const string& input)
{
	map<char, int> prob;
	for (size_t i = 0; i < input.length(); i++) {
		if (prob.find(input[i]) == prob.end()) {
			prob[input[i]] = 1;
		} else {
			prob[input[i]]++;
		}
	}
	vector<Note*> alph;
	map<char, int>::iterator it;
	for (it = prob.begin(); it != prob.end(); it++) {
		string s = "";
		s += it->first;
		alph.push_back(new Note(s, it->second));
	}
	return alph;
}

Huffman::Note* Huffman::GetTree(vector<Note*>& alph)
{
	vector<Note*> res = alph;
	while (res.size() > 1) {
		Sort(res);
		Note *a = res.back();
		res.pop_back();
		Note *b = res.back();
		res.pop_back();
		res.push_back(new Note(a->alph + b->alph, a->weight + b->weight, a, b));
	}
	return res[0];
}

void Huffman::TreeTraversal(Note *tree, vector<Note*> &res, string code)
{
	if (!tree)
		return;
	if (tree->alph.size() == 1)
		res.push_back(new Note(tree->alph, code));
	TreeTraversal(tree->left, res, code+'0');
	TreeTraversal(tree->right, res, code+'1');
}

vector<Huffman::Note*> Huffman::GetCodes(Note *tree)
{
	vector<Note*> res;
	TreeTraversal(tree, res);
	return res;
}

string Huffman::Encode(const string& input)
{
	vector<Note*> alph = GetAlph(input);
	Note *tree = GetTree(alph);
	vector<Note*> codes = GetCodes(tree);

	string res = "";
	for (size_t i = 0; i < input.length(); i++) {
		for (size_t j = 0; j < codes.size(); j++) {
			string s = "";
			s += input[i];
			if (codes[j]->alph.compare(s) == 0) {
				res += codes[j]->code;
				break;
			}
		}
	}
	return res;
}

string Huffman::Decode(const string& input)
{
	return input;
}
