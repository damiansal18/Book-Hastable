#include <iostream>
#include "sList.h"

using namespace std;

sList::sList()
{
	
}

Element sList::searchTwo(Element x)
{
	Element temp;
	Node* ptr;

	ptr = front;

	while (ptr != NULL)
	{
		if (ptr->book == x)
			return ptr->book;
		else
			ptr = ptr->next;
	}
	cout << "Input ISBN is not in the system." << endl;
	return temp;
}

int sList::search(Element key)
{
	int counter = 1;
	Node* ptr;
	ptr = front;

	while (ptr != NULL)
	{
		if (ptr->book == key)
			return counter;

		counter++;
		ptr = ptr->next;
	}
	cout << " " << key << " was not found the system." << endl;
	return 0;
}

void sList::replace(Element novel, int pos)
{
	if ((pos > count) || (pos < 1))
		throw outOfRange();
	else
	{
		Node* ptr;
		moveTo(pos, ptr);
		ptr->book = novel;
	}
}

bool sList::operator==(const sList& rhs)
{
	if (count == rhs.count)
	{
		Node* ptr = rhs.front;
		Node* ptrTwo = this->front;

		while (ptr != NULL && ptrTwo != NULL)
		{
			if (ptr->book != ptrTwo->book)
				return false;

			ptr = ptr->next;
			ptrTwo = ptrTwo->next;
		}
		return true; // if both pointer are pointing at the same spot
	}
	return false;
}