#ifndef SEARCH_PALINDROME_H
#define SEARCH_PALINDROME_H

#include <string>

class SearchPalindrome
{
	std::string s;
	int **lengthMx;
	int enumerate;
public:
	static SearchPalindrome *getInstance(std::string s);

	SearchPalindrome(std::string s);
	~SearchPalindrome();
	int dynamicSearch() { return dynamicSearch(0, s.length()-1); }
	int directSearch() { return directSearch(0, s.length()-1); }
	int getEnumerate() { return enumerate; enumerate = 0; }
	void showMatrix();
private:
	int dynamicSearch(int i, int j);
	int directSearch(int i, int j);
	void setLengthMx(int i, int j);
	int max(int a, int b) { return a > b ? a : b; }

};

#endif
