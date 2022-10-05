#ifndef HASH_TABLE_H
#define HASH_TABLE_H

class HashTable
{
	const char **table;
	unsigned size;
public:
	HashTable();
	int Insert(const char *id);
	int Remove(const char *id);
	int Search(const char *id) const;
	void ReHash();
	~HashTable();
	void OutPut() const;
private:
	unsigned Hash1(const char *id) const;
	unsigned Hash2(const char *id) const;
};

#endif
