#include <iostream>
#include <cmath>
#include <bitset>
#include <map>
#include "ShanFan.h"

using namespace std;

void ShanFan::Sort(vector<Code>& prob)
{
	for (size_t i = 0; i < prob.size(); i++) {
		for (size_t j = i + 1; j < prob.size(); j++) {
			if (prob[i].prob < prob[j].prob) {
				Code temp = prob[i];
				prob[i] = prob[j];
				prob[j] = temp;
			}
		}
	}
}

// convert a double number to binary string
string ShanFan::toBinary(double num, int precision)
{
	string result = "0.";
	while (num > 0 && precision > 0) {
		num *= 2;
		if (num >= 1) {
			result += "1";
			num -= 1;
		} else {
			result += "0";
		}
		precision--;
	}
	return result;
}

vector<ShanFan::Code> ShanFan::DetProb(const string& input)
{
	vector<Code> res;
	map<char, double> prob;
	for (size_t i = 0; i < input.length(); i++) {
		if (prob.find(input[i]) == prob.end()) {
			prob[input[i]] = 1;
		} else {
			prob[input[i]]++;
		}
	}
	map<char, double>::iterator it;
	for (it = prob.begin(); it != prob.end(); it++) {
		res.push_back(Code(it->first, it->second / input.length(), ""));
	}
	Sort(res);
	return res;
}

vector<ShanFan::Code> ShanFan::DetCode(vector<Code>& prob)
{
	int length = ceil(-log2(prob[0].prob));
	prob[0].code = "";
	for (auto i = 0; i < length; i++)
		prob[0].code += "0";

	for (size_t i = 1; i < prob.size(); i++) {
		double sum = 0;
		for (size_t j = 0; j < i; j++) {
			sum += prob[j].prob;
		}
		length = ceil(-log2(prob[i].prob));
		prob[i].code = toBinary(sum).substr(2, length);
	}

	return prob;
}

string ShanFan::Encode(const string& input)
{
	vector<Code> prob = DetProb(input);
	vector<Code> code = DetCode(prob);

	string output = "";
	for (size_t i = 0; i < input.length(); i++) {
		for (size_t j = 0; j < code.size(); j++) {
			if (input[i] == code[j].ch) {
				output += code[j].code;
				break;
			}
		}
	}
	return output;
}

string ShanFan::Decode(const string& input)
{
	string output = "";

	return output;
}
