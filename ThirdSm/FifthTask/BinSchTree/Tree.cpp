#include <iostream>
#include <fstream>
#include <cstring>
#include "Tree.h"
#include "Phone.h"

using namespace std;

Tree::Item::Item(const char *id, const int shift)
{
	this->id = new char[strlen(id)];
	strcpy(this->id, id);
	this->shift = shift;
	this->left = 0;
	this->right = 0;
}

void Tree::Generate(const char *binfl)
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
	int cmp = strcmp(node->id, id);
	if (0 == cmp)
		return node->shift;
	return Search((cmp < 0) ? node->left : node->right, id);
}

void Tree::Remove(const char *id)
{
	Item **node = &this->root;
	int cmp;
	while ((cmp = strcmp((*node)->id, id)) != 0) {
		node = (cmp < 0) ? &((*node)->left) : &((*node)->right);
	}
	if (!node)
		return;
	else if (((*node)->left == 0 || (*node)->right == 0)
			&& (*node)->left != (*node)->right) {
		Item *garbage = *node;
		node = ((*node)->left == 0) ? &((*node)->left) : &((*node)->right); 
		delete garbage;
		return;
	}
	Item **pmin = GetParentMin(node);
	// delete string id ??
	(*node)->id = new char [strlen((*pmin)->id)];
	strcpy((*node)->id, (*pmin)->id);
	(*node)->shift = (*pmin)->shift;
	delete (*pmin);
}

void Tree::Show() const
{
	unsigned count = PathLength(this->root);
	for (unsigned i = 0; i < count; i++) {
		Show(this->root, i);
	}
}

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
