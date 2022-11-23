#include "LinkedList.h"

//Search list which inherits from the bas LinkedList Class
//Public Inheritance: X is public, Y is protected & Z is private

class sList: public LinkedList{

public: 
	sList();
	int search(Element );
	void replace(Element, int);
	bool operator==(const sList&);
	Element searchTwo(Element temp);

};