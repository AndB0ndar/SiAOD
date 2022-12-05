#include <iostream>
#include "SrchPalindrome.h"

using namespace std;

SearchPalindrome::SearchPalindrome(string s): s(s)
{
	enumerate = 0;
	size_t len = s.length();
	lengthMx = new int*[len];
	for (size_t i = 0; i < len; i++) {
		lengthMx[i] = new int[len];
		for (size_t j = 0; j < len; j++) {
			lengthMx[i][j] = 0;
		}
		lengthMx[i][i] = 1;
	}
	//setLengthMx(0, len-1);
}

SearchPalindrome::~SearchPalindrome()
{
	size_t len = s.length();
	for (size_t i = 0; i < len; i++) {
		delete[] lengthMx[i];
	}
	delete[] lengthMx;
}

SearchPalindrome *SearchPalindrome::getInstance(string s)
{
	static SearchPalindrome *instance = new SearchPalindrome(s);
	return instance;
}

int SearchPalindrome::dynamicSearch(int start, int end)
{
	if (start > end)
		return 0;
	enumerate++;
	if (lengthMx[start][end] != 0)
		return lengthMx[start][end];

	if (s[start] == s[end]) {
		lengthMx[start][end] = dynamicSearch(start + 1, end - 1) + 2;
	} else {
		lengthMx[start][end] = max(dynamicSearch(start + 1, end), dynamicSearch(start, end - 1));
	}
	return lengthMx[start][end];
}

int SearchPalindrome::directSearch(int start, int end)
{
	if (start > end)
		return 0;
	enumerate++;
	if (start == end)
		return 1;

	if (s[start] == s[end]) {
		return directSearch(start + 1, end - 1) + 2;
	} else {
		return max(directSearch(start + 1, end), directSearch(start, end - 1));
	}
}

void SearchPalindrome::setLengthMx(int start, int end)
{
	if (start >= end) {
		return;
	}
	setLengthMx(start + 1, end);
	setLengthMx(start, end - 1);
	int val = 0;
	if (s[start] == s[end]) {
		val = lengthMx[start + 1][end - 1] + 2;
	} else {
		val = max(lengthMx[start + 1][end], lengthMx[start][end - 1]);
	}
	lengthMx[start][end] = val;
}

void SearchPalindrome::showMatrix()
{
	size_t len = s.length();
	for (size_t i = 0; i < len; i++) {
		for (size_t j = 0; j < len; j++) {
			cout << lengthMx[i][j] << " ";
		}
		cout << endl;
	}
}
