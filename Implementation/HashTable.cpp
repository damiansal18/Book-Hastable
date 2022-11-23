#include <iostream>
#include "HashTable.h"
#include <string>
#include <fstream>

HashTable:: HashTable()
{}

HashTable::~HashTable()
{}

int HashTable::hash(string key)
{
	int total = 0;
	string temp = "";
	char item;

	for (int i = 0; i < key.length(); i++)
	{
		item = key[i];
		if (isdigit(item))
		{
			int x = int(item - '0');
			total += x;
		}
		else
		{

		}
	}
	return total % TABLESIZE;
}

int HashTable::add(Element book)
{
	int slot = hash(book.getKey());
	table[slot].addToRear(book);

	return slot;
}

Element HashTable::find(string name)
{
	int slot = hash(name);
	Element target;

	target.setKey(name);
	target = table[slot].searchTwo(target);

	return target;
}

void HashTable::displayTable(ofstream& fout)
{
	fout.open("fileoutput.txt");
	for (int i = 0; i < 47; i++)
		table[i].displayList(fout);
}

int HashTable::deleteAt(Element book)
{
	int slot = hash(book.getKey());
	int pos = table[slot].search(book);

	table[slot].deleteAt(pos, book); //LinkedList.deleteAt(int, Element)
	return slot;
}