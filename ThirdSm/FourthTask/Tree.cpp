#include <iostream>
#include <iomanip>
#include "Tree.h"

using namespace std;

void Tree::Add(char dt)
{
	Item *node = new Item;
	node->data = dt;
	node->left = 0;
	node->right = 0;
	if (!this->root) {
		this->root = node;
		return;
	}
	Item **it = &(this->root);
	while (*it) {
		int a = PathLength((*it)->left);
		int b = PathLength((*it)->right);
		it = (a <= b) ? &((*it)->left) : &((*it)->right);
	}
	*it = node;
}

const Tree::Item* Tree::GetLeftItem() const
{
	if (!this->root)
		return 0;
	Item *node = this->root;
	while (node->left) {
		node = node->left;
	}
	return node;
}

int Tree::GetDistanse(const char dt, const Item *node, int dist)
{
	if (!node)
		return -1;
	if (node->data == dt)
		return dist;
	int a = GetDistanse(dt, node->left, dist+1);
	int b = GetDistanse(dt, node->right, dist+1);
	if (a == -1)
		return b;
	else
		return (b == -1 || a < b) ? a : b;
}

const char Tree::FindMaxChar(const Item *node, char mxchar) const
{
	if (!node)
		return mxchar;
	mxchar = (node->data > mxchar) ? node->data : mxchar;
	int a = FindMaxChar(node->left, mxchar);
	int b = FindMaxChar(node->right, mxchar);
	return (a > b) ? a : b;
}

void Tree::Show(const Tree::Item *node, int shift) const
{
	if (!node)
		return;
	Show(node->right, shift+3);
	cout  << setw(shift) << node->data << endl;
	Show(node->left, shift+3);
}

unsigned Tree::PathLength(Tree::Item *node, int mxlen)
{
	if (!node)
		return mxlen;
	int a = PathLength(node->left, mxlen+1);
	int b = PathLength(node->right, mxlen+1);
	return (a < b) ? a : b;
}

void Tree::Clean(Tree::Item *node)
{
	if (node)
		return;
	Clean(node->left);
	Clean(node->right);
	delete node;
}
