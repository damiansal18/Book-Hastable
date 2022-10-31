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

void LinkedList::deleteFirst()
{
	if (isEmpty())
		throw underFlow();
	else if (front->next == NULL) // one element in the list
	{
		//frontElement = front->book;

		delete front;

		front = NULL;
		rear = NULL;

		count--;

		cout << "Last element in the list has been removed... " << endl;
	}
	else // multiple elements, make the second element the front.
	{
		//frontElement = front->book;

		Node* second; //pointer to the second element in the list
		second = front->next;

		delete front; 
		front = second; //second node move to the front

		count--;

	}
}

void LinkedList::deleteLast()
{
	
	if (isEmpty())
		throw underFlow();
	else
	{
		Node* temp;
		temp = front; // create a temporary pointer pointing to the memory address of "front" fro traversal

		while (temp->next != NULL &&)
			temp = temp->next;  // traverse to the end of list

		front = temp;
		
		Node* waste;
		waste = front;
		front = NULL;
		rear = NULL;

		delete waste;
	}
}

void LinkedList::deleteAt(int pos)
{
	if (pos > count || pos < 1)
		throw outOfRange();
	else if (pos == 1)
	{
		deleteFirst();
	}
	else if (pos == count)
	{
		deleteLast();
	}
	else
	{
		int prevPos = pos - 1;
		int nextPos = pos + 1;

		Node* left;
		Node* current;
		Node* right;

		moveTo(prevPos, left); //set a pointer to the previous element of the current one, to it's left.
		moveTo(nextPos, right); //set a pointer to the next element of the current one, to it's right.
		moveTo(pos, current); //set a pointer to current element.

		//book = current->book; 

		delete current;

		//cout << "Book: " + book.getName + "was deleted from position: " + pos << endl;

		left->next = right;

		count--;

	}
}

void LinkedList::insertAt(int pos, Element& book)
{
	if (pos > count || pos < 1)
		throw outOfRange();
	else if (pos == 1)
		addToFront(book);
	else if (pos == count)
		addToRear(book);
	else {
		int prevPos = pos - 1;
		int nextPos = pos + 1;

		Node* left;
		Node* current;
		Node* right;

		moveTo(prevPos, left); //set a pointer to the previous element of the current one, to it's left.
		moveTo(nextPos, right); //set a pointer to the next element of the current one, to it's right.
		moveTo(pos, current);  //set a pointer to current element.

		// new node is allocated , info is input
		current = new Node;
		current->book = book;

		// new node is set at the desired position by rearranging pointers
		left->next = current;
		current->next = right;

		count++;
	}
}

LinkedList::LinkedList(const LinkedList& original)
{
	front = NULL;
	rear = NULL;
	count = 0;

	Node* pointer;
	pointer = original.front;

	while (pointer != NULL)
	{
		this->addToRear(pointer->book);

		pointer = pointer->next;
	}
	
}

LinkedList& LinkedList::operator=(const LinkedList& RHS)
{
	Element temp;
	
	if (&RHS != this)
	{
		while (!this->isEmpty())
			this->deleteLast();

		Node* pointer;
		pointer = RHS.front;

		while (pointer != NULL) {

			this->addToRear(pointer->book);
			pointer = pointer->next;
		}
	}

	return *this;

}

