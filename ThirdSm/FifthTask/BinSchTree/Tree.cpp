#include <iostream>
#include <fstream>
#include <cstring>
#include "Tree.h"
#include "Phone.h"

using namespace std;

Tree::Item::Item(const char *id, const int shift): 
	shift(shift), left(0), right(0)
{
	this->id = new char[strlen(id)];
	strcpy(this->id, id);
}

void Tree::Generate(const char *bin_fl)
{
    ifstream in(bin_fl, ios::binary);
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
	Item *node = new Item(id, shift);
	if (!this->root) {
		this->root = node;
		return;
	}
	Item **it = &(this->root);
	while (*it) {
		it = (strcmp(id, (*it)->id) <= 0) ? 
			&((*it)->left) : &((*it)->right);
	}
	*it = node;
}

int Tree::Search(const Item *node, const char *id)
{
	if (!node)
		return -1;
	int cmp = strcmp(id, node->id);
	if (0 == cmp)
		return node->shift;
	return Search((cmp <= 0) ? node->left : node->right, id);
}

void Tree::Remove(const char *id)
{
	Item **node = &this->root;
	int cmp;
	while ((cmp = strcmp(id, (*node)->id)) != 0) {
		node = (cmp <= 0) ? &((*node)->left) : &((*node)->right);
	}
	if (((*node)->left == 0 || (*node)->right == 0)
			&& (*node)->left != (*node)->right) {
		Item *garbage = *node;
		(*node) = ((*node)->left == 0) ? ((*node)->right) : ((*node)->left); 
		delete garbage;
	} else {
		Item **pmin = GetParentMin(&((*node)->right));
		strcpy((*node)->id, (*pmin)->id);
		(*node)->shift = (*pmin)->shift;
		delete (*pmin);
		(*pmin) = 0;
	}
}

void Tree::Show(const Tree::Item *node, unsigned level) const
{
	if (!node)
		return;
	Show(node->right, level+1);
	for (unsigned i = 0; i < level; i++)
		cout << "  ";
	cout << node->id << endl;
	Show(node->left, level+1);
}

Tree::Item** Tree::GetParentMin(Item **node)
{
	if (!node) {
		cout << "ERROR!!!" << endl;
		return 0;
	} else if (!(*node)) {
		cout << "ERROR!!!" << endl;
		return 0;
	} else if (!(*node)->left) {
		return node;
	}
	return GetParentMin(&((*node)->left));
}

unsigned Tree::PathLength(Tree::Item *node, int mxlen) const
{
	if (!node)
		return mxlen;
	int a = PathLength(node->left, mxlen+1);
	int b = PathLength(node->right, mxlen+1);
	return (a > b) ? a : b;
}

void Tree::Clean(Tree::Item *node)
{
	if (node)
		return;
	Clean(node->left);
	Clean(node->right);
	delete node;
}
