
#include <iostream>
#include <string>

using namespace std;

class Element
{
private:
	//We are creating a book directory , this is the book information will need 
	
	string key; //ISBN
	string name; //bookName
	string author; // authorName
	int volume;  //bookVolume

public:
	// constructors
	Element();
	Element(string, string, string, int); // (ISBN, bookName, authorName, Volume)

	// These functions are reusable for other element types
	string getName();
	string getKey();
	void setKey(string);

	bool operator == (Element); // overloading '==' operator for node comparison

	bool operator != (Element); // overloading '!=' operator for node comparison

	//overloading the insertion '<<' operator to output the element type
	friend ostream& operator<<(ostream&, const Element&); 





};