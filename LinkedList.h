
#include "Element.h"

struct Node
{
	Element book; //each element is a book in this case
	Node* next = NULL;
};

class LinkedList
{
protected:
	Node* front;
	Node* rear;
	int count;

	void moveTo(int, Node*&); // utility function to move to a specified node position

public:
	class underFlow{};
	class outOfRange{};

	LinkedList(); // constructor 
	~LinkedList(); // deconstructor

	bool isEmpty();

	void displayList(ofstream&);

	void addToFront(Element); // adding an element at the front of the list

	void addToRear(Element); // adding an element at the rear of the list

	void deleteFirst(); // the front element of the list is to be deleted

	void deleteLast(); // the rear element of the list is to be deleted

	void deleteAt(int); // deleting the element at the specified position(int)

	void insertAt(int, Element&); // inserts an element at the specified position(int)

	LinkedList(const LinkedList&); // copy constructor allows pass by value and return by value of linked-list

	LinkedList& operator = (const LinkedList&); // overload the '=' operator to return the referenced 
};

