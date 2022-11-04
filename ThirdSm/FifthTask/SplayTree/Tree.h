#ifndef TREE_H
#define TREE_H

class Tree
{
	struct Item {
		char *id;
		int shift;
		Item *left;
		Item *right;
		Item(const char *id, int shift);
		Item(const char *id, int shift, Item *left, Item *right);
	};
	Item *root;
public:
	Tree(): root(0) {}
	~Tree() { Clean(this->root); }

	void Build(const char *binfl);
	void Add(const char *id, int shift);
	int Search(const char *id);
	void Remove(const char *id);
	void Show() const { Show(this->root); }
private:
	static Item* Zig(Item *node);  // right rotate
	static Item* Zag(Item *node);  // left rotate
	Item* Splay(Item *node, const char *id);
	Item* Merge(Item *t1, Item *t2);
	Item** Split(Item *node, const char *id);
	Item* GetMinLarge(Item *node, const char *id);
	Item* GetMax(Item *node);

	void Show(const Item *node, unsigned shift=0) const;
	static int StrCmpNum(const char *s1, const char *s2) ;
	void Clean(Item *unit);
};

#endif
