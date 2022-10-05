#include <iostream>
#include <cstring>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(): size(64)
{
	table = new const char*[size];
	for (unsigned i = 0; i < size; i++) {
		table[i] = 0;
	}
}

HashTable::~HashTable()
{
	delete [] table;
}

int HashTable::Insert(const char *id)
{
	unsigned key1 = this->Hash1(id);
	unsigned key2 = Hash2(id);
	unsigned index;
	while (true) {
		for (unsigned i = 0; i < size; i++) {
			index = (key1 + i*key2) % size;
			if (table[index] == 0) {
				table[index] = id;
				return index;
			}
		}
		ReHash();
	}
}

int HashTable::Remove(const char *id)
{
	unsigned key1 = Hash1(id);
	unsigned key2 = Hash2(id);
	unsigned index;
	for (unsigned i = 0; i < size; i++) {
		index = (key1 + i*key2) % size;  // key2 = (key1 + key2) % size
		if (table[index] != 0) {
			if (table[index] == id) {
				table[index] = 0;
				return index;
			}
		} else {
			return -1;
		}
	}
	return -1;
}

int HashTable::Search(const char *id) const
{
	unsigned key1 = Hash1(id);
	unsigned key2 = Hash2(id);
	unsigned index;
	for (unsigned i = 0; i < size; i++) {
		index = (key1 + i*key2) % size;
		if (table[index] != 0) {
			if (table[index] == id)
				return index;
		} else {
			return -1;
		}
	}
	return -1;
}

void HashTable::ReHash()
{
	size *= 2;
	const char **tmp_table = table;
	table = new const char*[size];
	unsigned i;
	for (i = 0; i < size; i++) {
		table[i] = 0;
	}

	for (i = 0; i < size/2; i++) {
		const char *id = tmp_table[i];
		if (id != 0)
			Insert(id);
	}
	delete [] tmp_table;
}

unsigned HashTable::Hash1(const char *id) const
{
	unsigned key = 0x0;
	for (unsigned i = 0; i < strlen(id); i++) {
		unsigned x = sizeof(unsigned)*8 / id[i]%10;
		unsigned mask = id[i] + 7*(id[i]%13);
		key ^= id[i];
        key = ((key << x) | (key >> (sizeof(unsigned)*8 - x)));
		if (id[i] % 3 == 0)
			key |= mask;
		else if (id[i] % 3 == 1)
			key &= mask;
		else
			key ^= mask;
	}
	return key;
}
unsigned HashTable::Hash2(const char *id) const
{
	unsigned key = 0x0;
	unsigned sum = 0;
	unsigned mask;
	for (unsigned i = 0; i < strlen(id); i++) {
		sum += 7 * (id[i]%10);
		key ^= sum;
		mask = ((19 * id[i]) ^ (sum * 13));
		key ^= mask;
	}
	return key % (size-1) + 1;
}

void HashTable::OutPut() const
{
	for (unsigned i = 0; i < size; i++) {
		if (table[i] == 0)
			cout << "null" << endl;
		else
			cout << table[i] << endl;
	}
}
