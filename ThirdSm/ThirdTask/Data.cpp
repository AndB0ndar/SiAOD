#include <iostream>
#include "Data.h"

using namespace std;

void Data::SaveEntry(int shift)
{
	Phone ph = file.Read(shift);
	table.Insert(ph.GetId(), shift);
}

void Data::Remove(const char *id)
{
	file.Remove(id);
	table.Remove(id);
}

Phone Data::Search(const char *id)
{
	int shift = table.GetShift(id);
	return file.Read(shift);
}

void Data::Output() const
{
	cout << "=====" << endl;
	cout << "+@+@+File: " << endl;
	file.Output();
	cout << "+@+@+Table: " << endl;
	table.Output();
	cout << "=====" << endl;
}
