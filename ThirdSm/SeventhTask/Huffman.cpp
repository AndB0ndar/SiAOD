#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Huffman.h"

using namespace std;

Huffman::Note::~Note()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

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
		alph.push_back(new Note(s, it->second, it->second/(double)input.length()));
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
	if (tree->alph.size() == 1) {
		res.push_back(new Note(tree->alph, code));
		tree->code = code;
	}
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
	this->tree = GetTree(alph);
	vector<Note*> codes = GetCodes(this->tree);

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
	compressRatio = input.length() / (double)res.length();
	return res;
}

void Huffman::ShowTree(Note *tree, int level)
{
	if (!tree)
		return;
	ShowTree(tree->right, level+1);
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << tree->alph << " " << tree->code << endl;
	ShowTree(tree->left, level+1);
}

string Huffman::Decode(const string& input)
{
	string res = "";
	Note *temp = this->tree;
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == '0') {
			temp = temp->left;
		} else {
			temp = temp->right;
		}
		if (temp->alph.size() == 1) {
			res += temp->alph;
			temp = this->tree;
		}
	}
	return res;
}

void Huffman::CompressFile(const string &filename, const string &compressedFile)
{
	string input = "", line;
	ifstream fin(filename, ios::in);
	if (!fin.is_open()) {
		cout << "Can't open file " << filename << endl;
		return;
	}
	while (getline(fin, line)) {
		input += line;
	}
	fin.close();

	string output = Encode(input);
	ofstream fout(compressedFile, ios::out | ios::binary);
	if (!fout.is_open()) {
		cout << "Can't open file " << compressedFile << endl;
		return;
	}
	int coutn = 0;
	char c = 0;
	for (size_t i = 0; i < output.length(); i++) {
		c <<= 1;
		if (output[i] == '1')
			c |= 1;
		coutn++;
		if (coutn == 8) {
			fout.write(&c, sizeof(char));
			coutn = 0;
			c = 0;
		}
	}
	fout.close();
}
