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
		Item(const char *id, const int shift, Item *left, Item *right);
	};
	Item *root;
public:
	Tree(): root(0) {}
	~Tree() { Clean(this->root); }

	void Build(const char *binfl);
	void Add(const char *id, const int shift);
	int Search(const char *id)
	{ this->root = Splay(this->root, id); return this->root->shift; }
	void Remove(const char *id);
	void Show() const;
private:
	Item* Zig(Item *node);  // right rotate
	Item* Zag(Item *node);  // left rotate
	Item* Splay(Item *node, const char *id);
	Item* Merge(Item *t1, Item *t2);
	Item** Split(Item *node, const char *id);
	Item* GetMinLarge(Item *node, const char *id);
	Item* GetMax(Item *node);

	//void Show(const Item *node, const unsigned level, unsigned cur_lvl=0) const;
	void Show(const Item *node, unsigned shift=0) const;
	unsigned PathLength(Item *node, int mxlen=0) const;
	void Clean(Item *unit);
};

#endif
