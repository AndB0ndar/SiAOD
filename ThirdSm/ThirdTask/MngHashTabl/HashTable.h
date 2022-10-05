#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstring>

class HashTable {
	struct Item {
		const char *id;
		int shift;
		Item(const char *id, const int shift): shift(shift)
		{ char *tmp_id = new char[strlen(id)]; strcpy(tmp_id, id); this->id = tmp_id; }
		~Item() { delete id; }
	};
	Item **table;
	unsigned size;
public:
	HashTable();
	~HashTable();
	void Insert(const char *id, const int shift);
	int Remove(const char *id);
	int GetShift(const char *id) const;
	void ReHash();
	void OutPut() const;
	void Clear();
private:
	unsigned Hash1(const char *id) const;
	unsigned Hash2(const char *id) const;
	int Search(const char *id) const;
};

#endif
