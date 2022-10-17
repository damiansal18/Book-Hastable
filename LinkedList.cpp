#include "LinkedList.h"
#include <fstream>
#include <iostream>

using namespace std;


void LinkedList::moveTo(int position, Node*& temp)
{
	temp = front;
	for (int index = 1; index <= position - 1; index++)
	{
		temp = temp->next;
	}
}

LinkedList::LinkedList()
{
	front = NULL;
	rear = NULL;
	count = 0;

}

LinkedList::~LinkedList()
{
	Element temp;

	while (isEmpty() == false)
	{
		deleteFirst(temp); // deletes the first element of the list until it is empty.
	}
}

bool LinkedList::isEmpty()
{
	if ((front == NULL) && (rear == NULL) && (count == 0))
		return true;
	else
		return false;
}

void LinkedList::displayList(ofstream& fout) 
{
	Node* currentElement;
	currentElement = front;

	if (isEmpty())
	{
		cout << "Linked-List is empty" << endl;
	}
	else
	{
		cout << " ";

		while (currentElement != NULL)
		{
			fout << " " << currentElement->book << " ";  //output to file
			cout << " " << currentElement->book << " "; //output to program

			currentElement = currentElement->next;
		}

		cout << "" << endl;
		fout << "" << endl;
	}
}

void LinkedList::addToFront(Element newBook)
{
	if (isEmpty())
	{
		front = new Node;
		front->book = newBook;

		rear = front; 
		rear->next = NULL;

		count++;
	}
	else
	{
		Node* temp;
		temp = new Node;
		temp->book = newBook; //input element into the node
		
		temp->next = front; // attach the new node to the list by having the next pointer "point' to the front.
		front = temp; // temp is set as the front of the list.

		count++;
	}
}

void LinkedList::addToRear(Element newBook)
{
	cout << "Adding to rear..." << endl;

	if (isEmpty())
	{
		front = new Node;
		front->book = newBook;

		rear = front;
		rear->next = NULL;

		count++;
	}
	else
	{
		rear->next = new Node;  // rear-next "points" to the address in memory of the new node
		rear = rear->next; // the newly allocated node becomes the rear

		rear->book = newBook; // new rear "points" to the address of the new book
		rear->next = NULL; //  next pointer set back to null after setting up new rear

		count++;
	}
}

void LinkedList::deleteFirst(Element& frontElement)
{
	if (isEmpty())
		throw underFlow();
	else if (front->next == NULL)
	{
		frontElement = front->book;

		delete front;

		front = NULL;
		rear = NULL;

		count--;
	}
	else
	{
		frontElement = front->book;

		Node* second; //pointer to the second element in the list
		second = front->next;

		delete front; 
		front = second; //second node move to the front

		count--;

	}
}

void LinkedList::deleteLast(Element& lastElement)
{
	if (isEmpty())
		throw underFlow();
	else if (front->next == NULL)
	{
		lastElement = rear->book; // setting the the rears element as the last elem
		delete rear;

	}
}

void LinkedList::deleteAt(int, Element&)
{
}

void LinkedList::insertAt(int, Element&)
{
}

LinkedList::LinkedList(const LinkedList&)
{
}

LinkedList& LinkedList::operator=(const LinkedList&)
{
	
}

