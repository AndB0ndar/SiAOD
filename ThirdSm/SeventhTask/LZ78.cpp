#include <iostream>
#include <vector>
#include "LZ78.h"

using namespace std;

vector<LZ78::Node> LZ78::Encode(const string &input)
{
	string in("лорлоралоранранлоран");
	vector<Node> output;
	vector<string> dictionary;
	int i = 0;
	int len = in.length();
	while (i < len) {
		string str;
		int index = 0;
		bool found = false;
		size_t k = 1, maxLen = 1;
		while (k <= maxLen && i + k < len && !found) {
			str = in.substr(i, k);
			for (size_t j = 0; j < dictionary.size(); j++) {
				if (dictionary[j] == str) {
					index = j + 1;
					found = true;
					break;
				}
				size_t mx = dictionary[j].length();
				if (maxLen < mx) {
					maxLen = mx;
				}
			}
			k++;
		}
		if (found) {
			output.push_back({ index, in[i + k - 2] });
			dictionary.push_back(str);
			i += k - 1;
		}
		else {
			output.push_back({ 0, in[i] });
			dictionary.push_back(str);
			i++;
		}
	}
	compressRatio = len / (double)output.size();
	//output = "(0,�)(0,�)(0,�)(1,�)(3,�)(4,�)(0,�)(0,�)(5,�)(6,�)(8,)";
	return output;
}

string LZ78::Decode(const string& input)
{
	string output;
	vector<string> dictionary;
	int i = 0;
	int len = input.length();
	while (i < len) {
		cout << "+" << output << endl;
		int index = 0;
		string str;
		while (input[i] != '(') {
			i++;
		}
		i++;
		while (input[i] != ',') {
			index = index * 10 + input[i] - '0';
			i++;
		}
		i++;
		str = input[i];
		i += 2;
		if (index == 0) {
			dictionary.push_back(str);
		} else {
			str = dictionary[index-1] + str;
			dictionary.push_back(str);
		}
		output += str;
	}
	return output;
}
