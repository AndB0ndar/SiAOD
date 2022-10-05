#include <iostream>
#include <cstring>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(): size(64)
{
	table = new Item*[size];
	for (unsigned i = 0; i < size; i++) {
		table[i] = 0;
	}
}

HashTable::~HashTable()
{
	for (unsigned i = 0; i < size; i++) {
		if (!table[i]) {
			delete table[i];
		}
	}
	delete [] table;
}

void HashTable::Insert(const char *id, const int shift)
{
	unsigned key1 = Hash1(id);
	unsigned key2 = Hash2(id);
	unsigned index;
	while (true) {
		for (unsigned i = 0; i < size; i++) {
			index = (key1 + i*key2) % size;
			if (table[index] == 0) {
				Item *it = new Item(id, shift);
				table[index] = it;
				return;
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
			if (0 == strcmp(table[index]->id, id)) {
				int shift = table[index]->shift;
				delete table[index];
				table[index] = 0;
				return shift;
			}
		} else {
			return -1;
		}
	}
	return -1;
}

int HashTable::GetShift(const char *id) const
{
	int index = Search(id);
	if (index == -1)
		return index;
	else
		return table[index]->shift;
}

void HashTable::ReHash()
{
	size *= 2;
	Item **tmp_table = table;
	table = new Item*[size];
	unsigned i;
	for (i = 0; i < size; i++) {
		table[i] = 0;
	}

	for (i = 0; i < size/2; i++) {
		if (tmp_table[i] != 0)
			Insert(tmp_table[i]->id, tmp_table[i]->shift);
	}
	for (unsigned i = 0; i < size; i++) {
		if (!table[i]) {
			delete table[i];
		}
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
			cout << table[i]->id << " :: " << table[i]->shift << endl;
	}
}

void HashTable::Clear()
{
	for (unsigned i = 0; i < this->size; i++) {
		if (!table[i])
			delete table[i];
		table[i] = 0;
	}
	this->size = 64;
}

int HashTable::Search(const char *id) const
{
	unsigned key1 = Hash1(id);
	unsigned key2 = Hash2(id);
	unsigned index;
	for (unsigned i = 0; i < size; i++) {
		index = (key1 + i*key2) % size;
		if (table[index] != 0) {
			if (0 == strcmp(table[index]->id, id))
				return index;
		} else {
			return -1;
		}
	}
	return -1;
}
