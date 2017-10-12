#include <iostream>
#include <string>
#include <vector>
#include "classes.h"
using namespace std;


void printMenu()
{
	//print menu
	cout << endl;
	cout << "Welcome to the Smallsville Library Management System. Please select an option: " << endl;
	cout << "0. Quit" << endl;
	cout << "1. Add Patron to list" << endl;
	cout << "2. Add item to list" << endl;
	cout << "3. Check out item to patron" <<  endl;
	cout << "4. Check in item from patron" << endl;
	cout << "5. Print list of patrons" << endl;
	cout << "6. Print list of items" << endl;
	cout << "7. Print mailing list (only name, address, and email address)" << endl;
	cout << "8. Edit Patron Data" << endl;
	cout << "9. Edit item Data" << endl;
	cout << "10. Search for patron" << endl;
	cout << "11. Search for item" << endl;
	cout << "12. Remove a patron from the library" << endl;
	cout << "13. Remove a item from the library" << endl;
	cout << "14. Record a item as lost" << endl;
}
//info for printing/editting	
int Patron::getID() {return ID;};
string Patron::getPhone() {return phone;}
string Patron::getName() {return name;}
string Patron::getAddress() {return address;}
string Patron::getEmail() {return email;}
void Patron::addFine(int amt) {finebalance += amt;}
void Patron::payFine(int amt) {finebalance -= amt;}
void Patron::setNext(Patron *n) {next = n;}
void Patron::addBlock() {pStatus++;}
void Patron::removeBlock() {pStatus--;}
Patron *Patron::getNext() {return next;}
void Patron::editName(string newName) {name = newName;}
void Patron::editNum(string newNum) {phone = newNum;}
void Patron::editMail(string newMail) {email = newMail;}
void Patron::editAddress(string newAddress) {address = newAddress;}
int Patron::getbNum() {return booknum;}
void Patron::setbNum() {booknum++;}
void Patron::checkbNum() {booknum--;}

//constructor
		Patrons::Patrons()
		{
			pCount = 0;
			//sets both the top and bottom node to NULL initially
			top = bottom = NULL;
		}
		Patrons::~Patrons()
		{
		}
		//adds patron node to the linked list
		void Patrons::addPatron(vector<Patron>& myPatrons)
		{
			string nm,mail,addr;
			int id;
			string number;
        
			cout << "Enter Patron name: ";
			//cin.ignore();
			getline(cin, nm);
			cout << "Enter Patron ID: ";
			cin >> id;
			//cin.ignore() makes it so that cin ignores the \n that cin leaves in the iostream (so that getline works properly)
			cin.ignore();
			cout << "Enter Patron Phone: ";
			cin >> number;
			cin.ignore();
			cout << "Enter Patron email: ";
			cin >> mail;
			cin.ignore();
			cout << "Enter Patron address: ";
			getline(cin, addr);
			
			Patron myPatron(nm,id, mail, addr, number);
			myPatrons.push_back(myPatron);
			pCount++;
            
		}
        //prints list of patrons     
		void Patrons::printList(vector<Patron>& myPatrons)
		{
			for(unsigned int i = 0; i < myPatrons.size(); i++)
			{
				//prints
				cout << "Patron: " << myPatrons[i].getName() << endl;
				cout << "ID: " << myPatrons[i].getID() << endl;
				cout << "Phone Number: " << myPatrons[i].getPhone() << endl;
				cout << "Email: " << myPatrons[i].getEmail() << endl;
				cout << "Address: " << myPatrons[i].getAddress() << endl << endl;
			}
		}	
		//prints mailing info
		void Patrons::printMail(vector<Patron>& myPatrons)
		{
			//same as printList() but with less info being printed
			for(unsigned int i = 0; i < myPatrons.size(); i++)
			{
				//prints
				cout << "Patron: " << myPatrons[i].getName() << endl;
				cout << "Phone Number: " << myPatrons[i].getPhone() << endl;
				cout << "Email: " << myPatrons[i].getEmail() << endl;
				cout << "Address: " << myPatrons[i].getAddress() << endl << endl;
			}
		}
		//edit patron info with user given id
		void Patrons::editPatron(vector<Patron>& myPatrons)
		{
			int ifCheck = 0;
			int editChoice;
			int edittee;
			int i = 0;
			string tempStore;
			if(pCount > 0)
			{
				cout << "Whose account would you like to edit? Please enter ID number: ";
				cin >> edittee;
				cout << "What attribute would you like to edit?" << endl;
				cout << "1. Name" << endl;
				cout << "2. Phone Number" << endl;
				cout << "3. Email" << endl;
				cout << "4. Address" << endl;
				cin >> editChoice;
				cin.ignore();
				while(i != myPatrons.size())
				{
					if(myPatrons[i].getID() == edittee)
					{
						ifCheck = 1;
						switch(editChoice)
						{
							case 1:
								cout << "What is the new name? ";
								getline(cin, tempStore);
								myPatrons[i].editName(tempStore);
							break;
							case 2:
								cout << "What is the new phone number? ";
								getline(cin, tempStore);
								myPatrons[i].editNum(tempStore);
							break;
							case 3:
								cout << "What is the new email? ";
								getline(cin, tempStore);
								myPatrons[i].editMail(tempStore);
							break;
							case 4:
								cout << "What is the new Address? ";
								getline(cin, tempStore);
								myPatrons[i].editAddress(tempStore);
							break;
							default:
								cout << "This is an invalid choice. Please try again." << endl;
							break;
						}
					}
					i++;
				}
				if(ifCheck == 0)
				{
				cout << "There is no Patron with this ID, please try again" << endl;
				}
			}
			else
			{
				cout << "There are no patrons to edit." << endl;
			}
		}
		//searches linked list for patron,outputs info if found
		void Patrons::searchPatron(vector<Patron>& myPatrons)
		{
			int ifCheck = 0, searchee;
			int i = 0;
			if(pCount > 0)
			{
				cout << "What is the ID of the person you are searching for? ";
				cin >> searchee;
				cin.ignore();
				while(i != myPatrons.size())
				{
					if(myPatrons[i].getID() == searchee)
					{
						ifCheck = 1;
						cout << "Patron: " << myPatrons[i].getName() << endl;
						cout << "ID: " << myPatrons[i].getID() << endl;
						cout << "Phone Number: " << myPatrons[i].getPhone() << endl;
						cout << "Email: " << myPatrons[i].getEmail() << endl;
						cout << "Address: " << myPatrons[i].getAddress() << endl << endl;
					}
					i++;
				}
				if(ifCheck == 0)
				{
					cout << "There is no patron with this ID, please try again." << endl;
				}
				
			}
			else
			{
				cout << "The are no patrons to search. Please add a patron and try again." << endl;
			}
		}
		//checks id, used with check out function
		int Patrons::checkID(int checkThis, vector<Patron>& myPatrons)
		{
			int i = 0;
			int ifCheck = 0;
			if(pCount > 0)
			{
				while(i != myPatrons.size())
				{
					if(myPatrons[i].getID() == checkThis)
					{
						ifCheck = 1;
						cout << ifCheck << endl;
					}
					i++;
				}
				if(ifCheck == 0)
				{
					return 0;
					
				}
				else
				{
					return 1;
					
				}
				
			}
			else
			{
				cout << "The are no patrons to search. Please add a patron and try again." << endl;
			}
		}
		//returns just the name of patron with int id
		string Patrons::printName(int id , vector<Patron>& myPatrons)
		{
			int i = 0;
			while(i != myPatrons.size())
			{
				if(myPatrons[i].getID() == id)
				{
					return myPatrons[i].getName();
				}
				i++;
			}
		}
		//adds 1 to booknum in patron class
		void Patrons::changebNum(int id, vector<Patron>& myPatrons)
		{
			int i = 0;
			while(i != myPatrons.size())
			{
				if(myPatrons[i].getID() == id)
				{
					myPatrons[i].setbNum();
				}
				i++;
			}
		}
		//takes 1 off of booknum in patron class
		void Patrons::checkinbNum(int id, vector<Patron>& myPatrons)
		{
			int i = 0;
			while(i != myPatrons.size())
			{
				if(myPatrons[i].getID() == id)
				{
					myPatrons[i].checkbNum();
				}
				i++;
			}
		}
		//deletes patron from linked list if they don't have book checked out (has errors)
		void Patrons::delPatron(int id, vector<Patron>& myPatrons)
		{
			int i = 0;
			
			while(i != myPatrons.size())
			{
				if(myPatrons[i].getID() == id)
				{
					myPatrons.erase(myPatrons.begin() - i);
				}
				i++;
			}
			
		}
		//function gets the number of books that the user has
		int Patrons::getbookNum(int id, vector<Patron>& myPatrons)
		{
			int i = 0;
			while(i != myPatrons.size())
			{
				if(myPatrons[i].getID() == id)
				{
					return myPatrons[i].getbNum();
				}
				i++;
			}
		}
		Item::Item(string titl, int id, int copy, float cost,string nm, string ser)
		{
			title = titl;
			ID = id;
			copyright = copy;
			bcost = cost;
			name = nm;
			serial = ser;
		}
		int Item::getID() { return ID; }
		int Item::getCopy() { return copyright; }
		float Item::getCost() { return bcost; }
		string Item::getTitle() { return title; }
		string Item::getAuthor() {return name;}
		string Item::getSerial() {return serial;}
		void Item::setNext(Item *n) {next = n;}
		Item *Item::getNext() {return next;}
		void Item::editTitle(string newTitle) {title = newTitle;}
		void Item::editAuthor(string newName) {name = newName;}
		void Item::editCost(float newCost) {bcost = newCost;}
		void Item::bBorr() {Status = 0;}
		void Item::bLost() {Status = 1;}
		void Item::bIn() {Status = 2;}
		int Item::getbStat() {return Status;}
 
		
		
		//functions for printing/editting of info
		//string Book::getAuthor() {return author;}
		//string Book::getISBN() {return ISBN;}
		//void Book::editAuthor(string newAuthor) {author = newAuthor;}
	
		//constructor setting different values to the variables
		Catalog::Catalog()
		{
			cCount = 0;
			top = bottom = NULL;
		}
		//deconstructor for class
		Catalog::~Catalog()
		{
			//setting tracker to the top
			Item *now = top;
			while (now != bottom)
			{
				//making so next iterates to next node
				Item *next = now->getNext();
				delete now;
				now = next;
			}
		}
		
		//adds book by prompting user for info and creating new node in list with given info
		void Catalog::addItem()
		{
			Item *temp;
			string titl, auth, ISBN;
			int id, copy;
			float cost;
			int num;
			cout << "What item do you want to add?" << endl;
			cout << "1. Book"  << endl;
			cout << "2. Audio Book" << endl;
			cout << "3. Reference" << endl;
			cout << "4. DVD" << endl;
			cin >> num;
			cin.ignore();
			switch(num)
			{
				case 1:
					cout << "What is the Title of the book?" << endl;
					getline(cin, titl);
					cout << "Who is the author of the book?" << endl;
					getline(cin,auth);
					cout << "What is the ISBN number?" << endl;
					getline(cin,auth);
					cout << "What is the ID of the book?" << endl;
					cin >> id;
					cin.ignore();
					cout << "What is the copyright date of the book?" << endl;
					cin >> copy;
					cin.ignore();
					cout << "What is the cost of the book?" << endl;
					cin >> cost;
					cin.ignore();

					//temp constructs new book with previous values
					temp = new Book (titl, id, copy, cost, auth, ISBN);
					if (cCount == 0)
					{
						//top and bottom set to temp
						top = bottom = temp;
						//setting temp to next node
						temp->setNext(NULL);
						cCount++;
            				}
             				else
             				{
						//setting bottom to temp
                 				bottom->setNext(temp);
                 				bottom = temp;
                 				temp->setNext(NULL);
                				cCount++;
             				}
				break;
				case 2:
					cout << "What is the Title of the audio book?" << endl;
					getline(cin, titl);
					cout << "Who is the author of the audio book?" << endl;
					getline(cin,auth);
					cout << "What is the serial number?" << endl;
					getline(cin,ISBN);
					cout << "What is the ID of the audio book?" << endl;
					cin >> id;
					cin.ignore();
					cout << "What is the copyright date of the book?" << endl;
					cin >> copy;
					cin.ignore();
					cout << "What is the cost of the book?" << endl;
					cin >> cost;
					cin.ignore();

					//temp constructs new book with previous values
					temp = new audio (titl, id, copy, cost, auth, ISBN);
					if (cCount == 0)
					{
						//top and bottom set to temp
						top = bottom = temp;
						//setting temp to next node
						temp->setNext(NULL);
						cCount++;
            				}
             				else
             				{
						//setting bottom to temp
                 				bottom->setNext(temp);
                 				bottom = temp;
                 				temp->setNext(NULL);
                				cCount++;
             				}
				break;
				case 3:
					cout << "What is the Title of the reference book?" << endl;
					getline(cin, titl);
					cout << "Who is the author of the reference book?" << endl;
					getline(cin,auth);
					cout << "What is the ISBN number?" << endl;
					getline(cin,ISBN);
					cout << "What is the ID of the book?" << endl;
					cin >> id;
					cin.ignore();
					cout << "What is the copyright date of the book?" << endl;
					cin >> copy;
					cin.ignore();
					cout << "What is the cost of the book?" << endl;
					cin >> cost;
					cin.ignore();

					//temp constructs new book with previous values
					temp = new ref (titl, id, copy, cost, auth, ISBN);
					if (cCount == 0)
					{
						//top and bottom set to temp
						top = bottom = temp;
						//setting temp to next node
						temp->setNext(NULL);
						cCount++;
            				}
             				else
             				{
						//setting bottom to temp
                 				bottom->setNext(temp);
                 				bottom = temp;
                 				temp->setNext(NULL);
                				cCount++;
             				}
				break;
				case 4:
					cout << "What is the Title of the DVD?" << endl;
					getline(cin, titl);
					cout << "Who is the director of the DVD?" << endl;
					getline(cin,auth);
					cout << "What is the serial number?" << endl;
					getline(cin,ISBN);
					cout << "What is the ID of the DVD?" << endl;
					cin >> id;
					cin.ignore();
					cout << "What is the copyright date of the DVD?" << endl;
					cin >> copy;
					cin.ignore();
					cout << "What is the cost of the DVD?" << endl;
					cin >> cost;
					cin.ignore();

					//temp constructs new book with previous values
					temp = new dvd (titl, id, copy, cost, auth, ISBN);
					if (cCount == 0)
					{
						//top and bottom set to temp
						top = bottom = temp;
						//setting temp to next node
						temp->setNext(NULL);
						cCount++;
            				}
             				else
             				{
						//setting bottom to temp
                 				bottom->setNext(temp);
                 				bottom = temp;
                 				temp->setNext(NULL);
                				cCount++;
             				}
				break;
			}
			
             
		}
		//prints list of attributes for each node in list
		void Catalog::printList()
		{
			//set now to top to print list of books
			Item *now = top;
			while (now != NULL)
			{
				cout << "Book: " << now->getTitle() << endl;
				cout << "ID: " << now->getID() << endl;
				cout << "Author: " << now->getAuthor() << endl;
				cout << "Book ISBN: " << now->getSerial() << endl;
				cout << "Copyright Date: " << now->getCopy() << endl;
				cout << "Book Cost: $" << now->getCost() << endl << endl;
				now = now->getNext();
			}
		}
		//searches for id, edits book using Book class functions
		void Catalog::editBook()
		{
			Item *now = top;
			int ifCheck = 0;
			int editChoice;
			int edittee;
			string tempStore;
			float tempCost;
			if(cCount > 0)
			{
				cout << "Which book would you like to edit? Please enter ID number: ";
				cin >> edittee;
				cout << "What attribute would you like to edit?" << endl;
				cout << "1. Title" << endl;
				cout << "2. Author" << endl;
				cout << "3. Book Cost" << endl;
				cin >> editChoice;
				cin.ignore();
				while(now != NULL)
				{
					if(now->getID() == edittee)
					{
						ifCheck = 1;
						switch(editChoice)
						{
							case 1:
								cout << "What is the new title? ";
								getline(cin, tempStore);
								now->editTitle(tempStore);
							break;
							case 2:
								cout << "Who is the new Author? ";
								getline(cin, tempStore);
								now->editAuthor(tempStore);
							break;
							case 3:
								cout << "What is the new cost? ";
								cin >> tempCost;
								cin.ignore();
								now->editCost(tempCost);
							break;
							default:
								cout << "This is an invalid choice. Please try again." << endl;
							break;
						}
					}
					now = now->getNext();
				}
				if(ifCheck == 0)
				{
				cout << "There is no book with this ID, please try again" << endl;
				}
			}
			else
			{
				cout << "There are no books to edit." << endl;
			}
		}
		//searches book by using the id number the user enters to search for. Outputs info about book if found
		void Catalog::searchBook()
		{
			Item *now = top;
			int ifCheck = 0, searchee;
			if(cCount > 0)
			{
				cout << "What is the ID of the book you are searching for? ";
				cin >> searchee;
				cin.ignore();
				while(now != NULL)
				{
					if(now->getID() == searchee)
					{
						ifCheck = 1;
						cout << "Book: " << now->getTitle() << endl;
						cout << "ID: " << now->getID() << endl;
						cout << "Author: " << now->getAuthor() << endl;
						cout << "Book ISBN: " << now->getSerial() << endl;
						cout << "Copyright Date: " << now->getCopy() << endl;
						cout << "Book Cost: $" << now->getCost() << endl << endl;
					}
					now = now->getNext();
				}
				if(ifCheck == 0)
				{
					cout << "There is no book with this ID, please try again." << endl;
				}
				
			}
			else
			{
				cout << "The are no books to search. Please add a book and try again." << endl;
			}
		}
		//function to check the id, used with check out function
		int Catalog::checkID(int checkThis)
		{
			Item *now = top;
			int ifCheck = 0;
			if(cCount > 0)
			{
				while(now != NULL)
				{
					if(now->getID() == checkThis)
					{
						if(now->getbStat() == 0)
						{
							ifCheck = 1;
						}
						else if(now->getbStat() == 1)
						{
							cout << "Sorry! This book has already been loaned out." << endl;
							ifCheck = 0;
						}
						else
						{
							cout << "This book is currently lost, please try again later." << endl;
						}
					}
					now = now->getNext();
				}
				return ifCheck;
			}
			else
			{
				cout << "The are no books to search. Please add a book and try again." << endl;
			}
		}
		//prints just the name of the node
		string Catalog::printName(int id)
		{
			Item *now = top;
			while(now != NULL)
			{
				if(now->getID() == id)
				{
					return now->getTitle();
				}
				now = now->getNext();
			}
		}
		//change the status of the book (is it being borrowed/lost)
		void Catalog::changebStat(int id)
		{
			Item *now = top;
			while(now != NULL)
			{
				if(now->getID() == id)
				{
					now->bBorr();
				}
				now = now->getNext();
			}
		}
		//change the status of the book (is it being borrowed/lost)
		void Catalog::checkinbStat(int id)
		{
			Item *now = top;
			while(now != NULL)
			{
				if(now->getID() == id)
				{
					now->bIn();
				}
				now = now->getNext();
			}
		}
		void Catalog::lostbStat(int id)
		{
			Item *now = top;
			while(now != NULL)
			{
				if(now->getID() == id)
				{
					now->bLost();
				}
				now = now->getNext();
			}
		}
		//delet book just goes through linked list checking for id of node, if it matches the id of the node, it deletes the node (has some segmentation fault errors)
		void Catalog::delBook(int id)
		{
			Item *p1 = NULL, *pDel = NULL;
			
			if(top->getID() == id)
			{
				pDel = top;
				top = pDel->getNext();
				delete pDel;
				return;
			}
			
			p1 = top;
			pDel = top->getNext();
			
			while(pDel != NULL)
			{
				if(pDel->getID() == id)
				{
					Item *p1Next = p1->getNext();
					Item *pNext = pDel->getNext();
					p1Next = pNext;
					if(pDel == bottom)
					{
						bottom = pNext;
					}
					delete pDel;
					break;
				}
				p1 = pDel;
				pDel = pDel->getNext();
			}
			
		}
		//this function is used to return the book status to other functions(used when removing books/etc.
		int Catalog::getbookStat(int id)
		{
			Item *now = top;
			while(now != NULL)
			{
				if(now->getID() == id)
				{
					return now->getbStat();
				}
				now = now->getNext();
			}
		}
		
		
		Loan::Loan(int pID, int bID, int loanPeriod, int dueDatem, int dueDated, int dueDatey)
		{
			bookID = bID;
			patronID = pID;
			dueDateM = dueDatem;
			dueDateD = dueDated;
			dueDateY = dueDatey;
		}
		int Loan::getpID() {return patronID;}
		int Loan::getbID() {return bookID;}
		void Loan::setNext(Loan *n) {next = n;}
		Loan *Loan::getNext() {return next;}
		
		Loans::Loans()
		{
			lCount = 0;
			top = bottom = NULL;
		}
		Loans::~Loans()
		{
			//setting tracker to the top
			Loan *now = top;
			while (now != bottom)
			{
				//making so next iterates to next node
				Loan *next = now->getNext();
				delete now;
				now = next;
			}
		}
		void Loans::checkOut(int pID, int bID, int loanPeriod, int dueDatem, int dueDated, int dueDatey)
		{
			Loan *temp;
			temp = new Loan (pID, bID, loanPeriod, dueDatem, dueDated, dueDatey);
			if (lCount == 0)
			{
				//top and bottom set to temp
				top = bottom = temp;
				//setting temp to next node
				temp->setNext(NULL);
				lCount++;
			}
			else
			{
				//setting bottom to temp
				bottom->setNext(temp);
				bottom = temp;
				temp->setNext(NULL);
				lCount++;
			}
		}
		//function for checking in, essentially it just deletes the node that this loan is stored in therefore making the book and patron unassociated
		void Loans::checkIn(int pID,int bID)
		{
			//pointers for going through linked list
			Loan *p1 = NULL, *pDel = NULL;
			
			//if the top node is equal to values it does a specific process
			if((top->getbID()) == bID && (top->getpID()) == pID)
			{
				pDel = top;
				top = pDel->getNext();
				delete pDel;
				return;
			}
			
			p1 = top;
			pDel = top->getNext();
			//goes through list until null
			while(pDel != NULL)
			{
				//checks for values at same locations
				if(pDel->getbID() == bID && pDel->getpID() == pID)
				{
					Loan *p1Next = p1->getNext();
					Loan *pNext = pDel->getNext();
					p1Next = pNext;
					if(pDel == bottom)
					{
						bottom = pNext;
					}
					//deleting node
					delete pDel;
					break;
				}
				p1 = pDel;
				pDel = pDel->getNext();
			}
			
		}
