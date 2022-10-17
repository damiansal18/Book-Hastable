#include "Element.h"

Element::Element()
{
	key = "";
	name = "";
	author = "";
	volume = -1 ;
}

Element::Element(string ISBN, string bookName, string bookAuthor, int bookVolume)
{
	key = ISBN;
	name = bookName;
	author = bookAuthor;
	volume = bookVolume;
}

string Element::getKey()
{
	return key;
}

void Element::setKey(string ISBN)
{
	key = ISBN;
}

bool Element::operator ==(Element otherBook)
{
	if (key == otherBook.key)
		return true;
	else
		return false;
}

bool Element::operator !=(Element otherBook)
{
	if (key == otherBook.key)
		return true;
	else
		return false;
}

ostream& operator << (ostream& os, const Element& book)
{
	os << book.key << book.name << book.author << book.volume;
	return os;
}