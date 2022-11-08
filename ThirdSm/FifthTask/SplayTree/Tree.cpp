#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Tree.h"
#include "Phone.h"

using namespace std;

Tree::Item::Item(const char *id, int shift): 
	shift(shift), 
	left(0), right(0)
{
	this->id = new char[strlen(id)];
	strcpy(this->id, id);
	this->left = 0;
	this->right = 0;
}
Tree::Item::Item(const char *id, int shift, Tree::Item *left, Tree::Item *right): 
	shift(shift), 
	left(left), right(right)
{
	this->id = new char[strlen(id)];
	strcpy(this->id, id);
}

void Tree::Build(const char *binfl)
{
    ifstream in(binfl, ios::binary);
    Phone ph;
	in.read(reinterpret_cast<char *>(&ph), sizeof(Phone));
	for (unsigned i = 0; !in.eof(); i++) {
		Add(ph.GetId(), i);
		in.read(reinterpret_cast<char *>(&ph), sizeof(Phone));
	}
    in.close();
}

void Tree::Add(const char *id, const int shift)
{
	if (!this->root) {
		this->root = new Item(id, shift);
		return;
	}
	Item **trees = Split(this->root, id);
	this->root = new Item(id, shift, trees[0], trees[1]);
}

int Tree::Search(const char *id) 
{ 
	this->root = Splay(this->root, id);
	return (StrCmpNum(this->root->id, id) == 0) ? this->root->shift : -1;
}

void Tree::Remove(const char *id)
{
	this->root = Splay(this->root, id);
	Item *garbage = this->root;
	this->root = Merge(this->root->left, this->root->right);
	delete garbage;
}

Tree::Item* Tree::Zig(Tree::Item *node) // right rotate
{
	Item *left_child = node->left;
	node->left = left_child->right;
	left_child->right = node;
	return left_child;
}

Tree::Item* Tree::Zag(Tree::Item *node)
{
	Item *right_child = node->right;
	node->right = right_child->left;
	right_child->left = node;
	return right_child;
}

Tree::Item* Tree::Splay(Tree::Item *node, const char *id)
{
	if (!node)
		return node;
	int cmp = StrCmpNum(node->id, id);
	if (cmp > 0) {  // left
		if (!node->left)
			return node;
		cmp = StrCmpNum(node->left->id, id);
		if (cmp > 0) {  // Zig-Zig
			node->left->left = Splay(node->left->left, id);
			node = Zig(node);
		} else if (cmp < 0){  // Zig-Zag
			node->left->right = Splay(node->left->right, id);
			if (node->left->right)
				node->left = Zag(node->left);
		}
		if (node->left)
			node = Zig(node);
	} else if (cmp < 0) {  // right
		if (!node->right)
			return node;
		cmp = StrCmpNum(node->right->id, id);
		if (cmp < 0) {  // Zag-Zag
			node->right->right = Splay(node->right->right, id);
			node = Zag(node);
		} else if (cmp > 0) {  // Zag-Zig
			node->right->left = Splay(node->right->left, id);
			if (node->right->left)
				node->right = Zig(node->right);
		}
		if (node->right)
			node = Zag(node);
	}
	return node;
}

Tree::Item* Tree::Merge(Tree::Item *t1, Tree::Item *t2)  // t1 < t2
{
	Item *max = GetMax(t1);
	t1 = Splay(t1, max->id);
	t1->right = t2;
	return t1;
}

Tree::Item** Tree::Split(Tree::Item *node, const char *id)
{	
	Item *min = GetMinLarge(node, id);
	Item **trees = new Item*[2];
	if (min) {
		node = Splay(node, min->id);
		trees[0] = node->left;
		node->left = 0;
		trees[1] = node;
	} else {
		trees[0] = node;
		trees[1] = 0;
	}
	return trees;
}

Tree::Item* Tree::GetMinLarge(Tree::Item *node, const char *id)
{
	Item *min = 0;
	int cmp;
	while (node) {
		cmp = StrCmpNum(node->id, id);
		if (cmp < 0) {
			node = node->right;
		} else if (cmp > 0) {
			min = node;
			node = node->left;
		} else {
			return min;
		}
	}
	return min;
}

Tree::Item* Tree::GetMax(Tree::Item *node)
{
	if (!node->right)
		return node;
	return GetMax(node->right);
}

void Tree::Show(const Tree::Item *node, unsigned shift) const
{
	if (!node)
		return;
	Show(node->right, shift+1);
	for (unsigned i = 0; i < shift; i++)
		cout << "  ";
	cout << node->id << endl;
	Show(node->left, shift+1);
}

int Tree::StrCmpNum(const char *s1, const char *s2)
{
	unsigned i = 0;
	while ((s1[i] && s2[i])
			&& ((s1[i] >= '0' && s1[i] <= '9')
			|| (s2[i] >= '0' && s2[i] <= '9'))) {
		if (s1[i] == s2[i]) {
			i++;
			continue;
		} else {
			return s1[i] - s2[i];
		}
	}
	if (s1[i] >= '0' && s1[i] <= '9')
		return 1;
	else if (s2[i] >= '0' && s2[i] <= '9')
		return -1;
	else
		return 0;
}

void Tree::Clean(Tree::Item *node)
{
	if (node)
		return;
	Clean(node->left);
	Clean(node->right);
	delete node;
}
