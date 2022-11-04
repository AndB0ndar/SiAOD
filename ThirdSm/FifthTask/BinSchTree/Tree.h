#ifndef TREE_H
#define TREE_H

class Tree
{
	struct Item {
		char *id;
		int shift;
		Item *left;
		Item *right;
		Item(const char *id, const int shift);
	};
	Item *root;
public:
	Tree(): root(0) {}
	~Tree() { Clean(this->root); }

	void Generate(const char *binfl);
	void Add(const char *id, const int shift);
	int Search(const char *id) { return Search(this->root, id); }
	void Remove(const char *id);
	void Show() const;
private:
	int Search(const Item *node, const char *id);
	void Show(const Item *node, const unsigned level, unsigned cur_lvl=0) const;
	Item** GetParentMin(Item **node);
	unsigned PathLength(Item *rt, int mxlen=0) const;
	void Clean(Item *unit);
};

#endif
