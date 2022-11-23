#pragma once
const int TABLESIZE = 47;

#include "sList.h"
class HashTable
{
private:
	sList table[TABLESIZE];
	int hash(string);

public:
	HashTable();
	~HashTable();

	int add(Element);
	Element find(string);
	void displayTable(ofstream&);
	int deleteAt(Element);

};