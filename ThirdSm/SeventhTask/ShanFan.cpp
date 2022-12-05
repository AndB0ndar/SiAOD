#include <iostream>
#include <vector>
#include <map>
#include "ShanFan.h"

using namespace std;

ShanFan::Code::~Code()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

void ShanFan::Sort(vector<Code*> &vec)
{
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = i + 1; j < vec.size(); j++) {
			if (vec[i]->weight < vec[j]->weight) {
				Code *temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
}

vector<ShanFan::Code*> ShanFan::GetAlph(const string &input)
{
	map<char, int> prob;
	for (size_t i = 0; i < input.length(); i++) {
		if (prob.find(input[i]) == prob.end()) {
			prob[input[i]] = 1;
		} else {
			prob[input[i]]++;
		}
	}
	vector<Code*> alph;
	map<char, int>::iterator it;
	for (it = prob.begin(); it != prob.end(); it++) {
		string s = "";
		s += it->first;
		alph.push_back(new Code(s, it->second));
	}
	return alph;
}

void ShanFan::Balance(vector<Code*> alph
		, vector<Code*> &lef
		, vector<Code*> &right)
{
	Sort(alph);
    for(Code* r : alph) {
        if (Weight(lef) < Weight(right)) {
            lef.push_back(r);
        } else {
            right.push_back(r);
        }
    }
}

int ShanFan::Weight(vector<Code*> &vec)
{
	int weight = 0;
	for (Code* r : vec) {
		weight += r->weight;
	}
	return weight;
}

ShanFan::Code* ShanFan::GetTree(vector<Code*>& alph)
{
	Code* root = new Code();
	if (alph.size() == 1) {
		root->alph = alph[0]->alph;
		root->weight = alph[0]->weight;
		return root;
	} 
	for (Code* r : alph) {
		root->alph += r->alph;
		root->weight += r->weight;
	}
	vector<Code*> left, right;
	Balance(alph, left, right);
	root->left = GetTree(left);
	root->right = GetTree(right);
	return root;
}

void ShanFan::TreeTraversal(Code *tree, vector<Code*> &res, string code)
{
	if (!tree)
		return;
	if (tree->alph.size() == 1) {
		res.push_back(new Code(tree->alph, code));
		tree->code = code;
	}
	TreeTraversal(tree->left, res, code+'0');
	TreeTraversal(tree->right, res, code+'1');
}

vector<ShanFan::Code*> ShanFan::GetCodes(Code *tree)
{
	vector<Code*> res;
	TreeTraversal(tree, res);
	return res;
}

string ShanFan::Encode(const string& input)
{
	vector<Code*> alph = GetAlph(input);
	this->tree = GetTree(alph);
	vector<Code*> codes = GetCodes(this->tree);

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

string ShanFan::Decode(const string& input)
{
	string res = "";
	Code* temp = this->tree;
	for (size_t i = 0; i < input.length(); i++) {
		temp = input[i] == '0' ? temp->left : temp->right;
		if (temp->alph.size() == 1) {
			res += temp->alph;
			temp = this->tree;
		}
	}
	return res;
}

void ShanFan::ShowTree(Code *tree, int level)
{
	if (!tree)
		return;
	ShowTree(tree->right, level+1);
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << tree->alph << " " << tree->code << endl;
	ShowTree(tree->left, level+1);
}
