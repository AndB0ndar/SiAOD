#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Tree.h"
#include "Phone.h"

using namespace std;

Tree::Item::Item(const char *id, const int shift): 
	shift(shift), 
	left(0), right(0)
{
	this->id = new char[strlen(id)];
	strcpy(this->id, id);
	this->left = 0;
	this->right = 0;
}
Tree::Item::Item(const char *id, const int shift, Tree::Item *left, Tree::Item *right): 
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
		cout << "ID: " << ph.GetId() << " SHIFT: " << i << endl;
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

void Tree::Remove(const char *id)
{
	this->root = Splay(this->root, id);
	this->root = Merge(this->root->left, this->root->right);
}

void Tree::Show() const
{
	Show(this->root);
	/*
	unsigned count = PathLength(this->root);
	for (unsigned i = 0; i < count; i++) {
		Show(this->root, i);
	}
	*/
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
		return 0;
	int cmp = strcmp(node->id, id);
	if (cmp == 0)
		return node;
	else if (cmp > 0) {  // left
		if (node->left == 0)
			return 0;
		cmp = strcmp(node->left->id, id);
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
		return node;
	} else {  // right
		if (node->right == 0)
			return 0;
		cmp = strcmp(node->right->id, id);
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
		return node;
	}
}

Tree::Item* Tree::Merge(Tree::Item *t1, Tree::Item *t2)  // t1 < t2
{
	Item *max = GetMax(t1);
	cout << "max: " << max->id << endl;
	t1 = Splay(t1, max->id);
	cout << "t1->right: " << t1->right << endl;
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
		cmp = strcmp(node->id, id);
		if (cmp == 0) {
			return min;
		} else if (cmp > 0) {
			min = node;
			node = node->left;
		} else if (cmp < 0)
			node = node->right;
	}
	return min;
}

Tree::Item* Tree::GetMax(Tree::Item *node)
{
	if (!node->right)
		return node;
	return GetMax(node->right);
}

/*
void Tree::Show(const Tree::Item *node, const unsigned level, unsigned cur_lvl) const
{
	if (!node)
		return;
	if (level == cur_lvl) {
		cout  << node->id << " ";
		return;
	}
	Show(node->left, level, cur_lvl+1);
	Show(node->right, level, cur_lvl+1);
}
*/

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

unsigned Tree::PathLength(Tree::Item *node, int mxlen) const
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
