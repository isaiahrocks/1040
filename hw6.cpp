/*
Author: Miguel Martinez
Email: miguelmartinez7@my.unt.edu
Program: hw6.cpp
*/

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "classes.h"
using namespace std;

void printMenu();

int main()
{
	//make objects of classes
	Patrons patronObject;
	Catalog catObject;
	Loans loanObject;
	vector<Patron> myPatronClass;
	vector<Item> myItemClass;
	int choice = 0, pID, bID,pCheck, bCheck, loanPeriod = 7;
	time_t now = time(0);
	tm *tm = localtime(&now);
	
	printMenu();
	cin >> choice;
	cin.ignore();
	
	//test for quit
	do
	{
		//switch to manage choices
		switch(choice)
		{
			case 0:
			break;
			case 1: 
				//patronObject.addPatron();
				patronObject.addPatron(myPatronClass);
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 2:
				catObject.addItem();
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 3:
				cout << "Enter the patron ID number: ";
				cin >> pID;
				cin.ignore();
				pCheck = patronObject.checkID(pID, myPatronClass);
				cout << "Enter the book ID number: ";
				cin >> bID;
				cin.ignore();
				bCheck = catObject.checkID(bID);
				
				patronObject.changebNum(pID, myPatronClass);
				catObject.changebStat(bID);
				
				if(bCheck == 1 && pCheck == 1)
				{
					loanObject.checkOut(pID, bID, loanPeriod, (1+tm->tm_mon), (loanPeriod + tm->tm_mday), (1900+tm->tm_year));
					cout << catObject.printName(bID) << " has been loaned to " << patronObject.printName(pID, myPatronClass) << "." << endl;
					cout << "Your book is due in " << loanPeriod << " days on " << 1+ tm->tm_mon << "/" << loanPeriod + tm->tm_mday << "/" << 1900 + tm->tm_year << endl;
				}
				else
				{	
					cout << "Either the patron ID is not valid or the book ID is not valid. Please try again." << endl;
				}
				
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 4:
				cout << "Enter the patron ID number: ";
				cin >> pID;
				cin.ignore();
				cout << "Enter the book ID number: ";
				cin >> bID;
				cin.ignore();
				loanObject.checkIn(pID, bID);
				patronObject.checkinbNum(pID , myPatronClass);
				catObject.checkinbStat(bID);
				cout << patronObject.printName(pID, myPatronClass) << " has successfully turned in " << catObject.printName(bID) << "." << endl;
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 5:
				patronObject.printList(myPatronClass);
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 6:
				catObject.printList();
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 7:
				patronObject.printMail(myPatronClass);
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 8:
				patronObject.editPatron(myPatronClass);
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 9: 
				catObject.editBook();
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 10:
				patronObject.searchPatron(myPatronClass);
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 11:
				catObject.searchBook();
				printMenu();
				cin >> choice;
				cin.ignore();
			break;
			case 12:
				cout << "Which patron would you like to remove? (Enter ID): ";
				cin >> pID;
				cin.ignore();
				if(patronObject.getbookNum(pID, myPatronClass) == 0)
				{
					patronObject.delPatron(pID, myPatronClass);
					printMenu();
					cin >> choice;
					cin.ignore();
				}
				else
				{
					cout << "We cannot remove this patron until he returns all of the books he has loaned." << endl;
					printMenu();
					cin >> choice;
					cin.ignore();
				}
			break;
			case 13:
					cout << "Which book would you like to remove? (Enter ID): ";
					cin >> bID;
					cin.ignore();
					if(catObject.getbookStat(bID) == 0)
					{
						catObject.delBook(bID);
						printMenu();
						cin >> choice;
						cin.ignore();
					}
					else if(catObject.getbookStat(bID) == 1)
					{
						cout << "We cannot remove this book because it is currently on loan." << endl;
						printMenu();
						cin >> choice;
						cin.ignore();
					}
					else
					{
						cout << "This book is currently lost.  We cannot remove it." << endl;
						printMenu();
						cin >> choice;
						cin.ignore();
					}
			break;
			case 14:
				cout << "Which book is lost? (Enter ID)" << endl;
				cin >> bID;
				cin.ignore();
				catObject.lostbStat(bID);
				cout << "This book has now been marked as lost." << endl;
			break;
			default: 
				cout << "This is not a valid choice. Please try again." << endl;
				return 0;
			break;
		}
	}while(choice != 0);
	return 0;
}

