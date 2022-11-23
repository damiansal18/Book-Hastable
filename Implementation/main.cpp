#include "HashTable.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool checkISBN(string ISBN);

int main()
{
	HashTable table;

	string ISBN;
	string name;
	string author;
	int volumeNum;

	Element element;

	string filename;
	cout << " What is the input file? ";
	cin >> filename;

	ifstream fin(filename.c_str(), ios::in);
	ofstream fout("fileoutput", ios::out);

	int choice = 0;
	while (choice != 7)
	{
		cout << endl << "MENU************************:" << endl;
		cout << "1. Load data from a file." << endl;
		cout << "2. Display table." << endl;
		cout << "3. Search using ISBN." << endl;
		cout << "4. Add a new entry." << endl;
		cout << "5. Delete an entry." << endl;
		cout << "6. Save data to a file." << endl;
		cout << "7. Exit." << endl;
		cout << "==>";

		cin >> choice;

		switch (choice)
		{
		case 1: 
			while(fin >> ISBN)
			{
				fin >> name;
				fin >> author;
				fin >> volumeNum;
				table.add(Element(ISBN, name, author, volumeNum));
			}
			cout << "Data has been uploaded from the input file." << endl;
			break;

		case 2:
			table.displayTable(fout);
			break;

		case 3:
			do {
				cout << "Enter an ISBN to look for: "; cin >> ISBN;
			} while (!checkISBN(ISBN));

			element = table.find(ISBN);
			
			if (element == Element())
				cout << "Not found." << endl;
			else
			{
				cout << "Found book: " << element.getKey() + " " << element.getName() + " ";
				cout << element.getAuthor() + " " << element.getVol() << endl;
			}
			break;

		case 4:
			do {
				cout << "Enter an ISBN: "; cin >> ISBN;
			} while (!checkISBN(ISBN));
			
			cout << "Enter a name: "; cin >> name;
			cout << "Enter an Author: "; cin >> author;
			cout << "Enter a volume number: "; cin >> volumeNum;
			cout << "In slot: " << table.add(Element(ISBN, name, author, volumeNum));
			cout << " added." << endl;

			break;

		case 5:
			do {
				cout << "Enter an ISBN to delete : "; cin >> ISBN;
			} while (!checkISBN(ISBN));
			cout << "In slot: " << table.deleteAt(Element(ISBN, "", "", -1));
			cout << " deleted." << endl;
			
			break;

		case 6:
			table.displayTable(fout);
			cout << "Sent data to output file!" << endl;
			
			break;

		default:
			cout << "No action." << endl;
			break;
		}
		fin.close();
		fout.close();
	}


}

bool checkISBN(string ISBN)
{
	int num = stoi(ISBN.substr(0,3));

	if (num < 960 || num > 980)
	{
		cout << "Invalid ISBN! Make sure inital numbers are correct." << endl;
		return false;
	}
	else
		return true;
		
}