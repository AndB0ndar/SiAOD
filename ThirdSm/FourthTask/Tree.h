#ifndef TREE_H
#define TREE_H

class Tree
{
	struct Item {
		char data;
		Item *left;
		Item *right;
	};
	Item *root;
public:
	Tree(): root(0) {}
	~Tree() { Clean(this->root); }
	void Add(char dt);
	const Item* GetLeftItem() const;
	int GetDistanse(const char dt)
	{ return (!this->root) ? -1 : GetDistanse(dt, this->root); }
	const char FindMaxChar() const
	{ return (!this->root) ? '\0' : FindMaxChar(this->root); }
	void Show() const { Show(this->root); }
private:
	int GetDistanse(const char dt, const Item *node, int dist=0);
	void Show(const Item *rt, int shift=0) const;
	const char FindMaxChar(const Item *it, char mxchar='\0') const;
	unsigned PathLength(Item *rt, int mxlen=0);
	void Clean(Item *unit);
};

#endif
