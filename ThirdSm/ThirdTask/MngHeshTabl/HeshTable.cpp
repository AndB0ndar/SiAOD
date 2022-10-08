#include <iostream>
#include <cstring>
#include "HeshTable.h"

using namespace std;

HeshTable::Item::Item(const char *id, const int shift): shift(shift)
{ 
	char *tmp_id = new char[strlen(id)];
	strcpy(tmp_id, id);
	this->id = tmp_id;
}

HeshTable::HeshTable(): size(4)
{
	table = new Item*[size];
	for (unsigned i = 0; i < size; i++) {
		table[i] = 0;
	}
}

HeshTable::~HeshTable()
{
	for (unsigned i = 0; i < size; i++) {
		if (table[i]) {
			delete table[i];
		}
	}
	delete [] table;
}

void HeshTable::Insert(const char *id, const int shift)
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
int HeshTable::Remove(const char *id)
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
		}
	}
	return -1;
}

int HeshTable::GetShift(const char *id) const
{
	int index = Search(id);
	if (index == -1)
		return index;
	return table[index]->shift;
}

void HeshTable::ReHash()
{
	unsigned old_size = size;
	size *= 2;
	Item **tmp_table = table;
	table = new Item*[size];
	unsigned i;
	for (i = 0; i < size; i++) {
		table[i] = 0;
	}
	for (i = 0; i < old_size; i++) {
		if (tmp_table[i] != 0) {
			Insert(tmp_table[i]->id, tmp_table[i]->shift);
			delete tmp_table[i];
		}
	}
	delete [] tmp_table;
}

unsigned HeshTable::Hash1(const char *id) const
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

unsigned HeshTable::Hash2(const char *id) const
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

void HeshTable::Output() const
{
	for (unsigned i = 0; i < size; i++) {
		if (table[i] == 0)
			cout << "null" << endl;
		else
			cout << table[i]->id << " :: " << table[i]->shift << endl;
	}
}

void HeshTable::Clear()
{
	for (unsigned i = 0; i < this->size; i++) {
		if (!table[i])
			delete table[i];
		table[i] = 0;
	}
	this->size = 64;
}

int HeshTable::Search(const char *id) const
{
	unsigned key1 = Hash1(id);
	unsigned key2 = Hash2(id);
	unsigned i, index;
	for (i = 0, index = key1; i < size; i++, index+=key2) {
		index %= size;
		// index = (key1 + i*key2) % size;
		if (table[index] != 0) {
			if (0 == strcmp(table[index]->id, id)) {
				return index;
			}
		}
	}
	return -1;
}
