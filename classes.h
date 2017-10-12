#include <string>
#include <vector>
using namespace std;

void printMenu();

//classes for transaction
class Patron
{
	private:
		int ID,finebalance, booknum, pStatus;
		string phone;
		string name, address, email;
		//pointer to the next node in the linked list
		Patron *next;
	public:
	//constructor
		Patron(string nm, int id, string mail, string addr, string number)
		{
			name = nm;
			ID = id;
			email = mail;
			address = addr;
			phone = number;
			booknum = 0;
			pStatus = 0;
			finebalance = 0;
		}
		//functions for the different get/sets you need
		int getID();
		string getPhone();
		string getName();
		string getAddress();
		string getEmail();
		void addFine(int amt);
		void payFine(int amt);
		void setNext(Patron *n);
		void addBlock();
		void removeBlock();
		Patron *getNext();
		void editName(string newName);
		void editNum(string newNum);
		void editMail(string newMail);
		void editAddress(string newAddress);
		int getbNum();
		void setbNum();
		void checkbNum();
};

class Patrons
{
	private:
		int pCount;
		//top and bottom nodes in linked list
		Patron *top;
		Patron *bottom;
	public:
		//constructor
		Patrons();
		~Patrons();
		void addPatron(vector<Patron>& myPatrons);     
		void printList(vector<Patron>& myPatrons);
		void printMail(vector<Patron>& myPatrons);
		void editPatron(vector<Patron>& myPatrons);
		void searchPatron(vector<Patron>& myPatrons);
		int checkID(int checkThis, vector<Patron>& myPatrons);
		string printName(int id, vector<Patron>& myPatrons);
		void changebNum(int id, vector<Patron>& myPatrons);
		void checkinbNum(int id, vector<Patron>& myPatrons);
		void delPatron(int id, vector<Patron>& myPatrons);
		int getbookNum(int id, vector<Patron>& myPatrons);
		
};



class Item
{
	private:
		int ID, Status, copyright; 
		float bcost;
		string title, name,serial;
		//next node
		Item *next;
	public:
		//constructor
		Item(string titl, int id, int copy, float cost, string nm,string ser);
		//functions for printing of info
		int getID();
		int getCopy();
		float getCost();
		string getTitle();
		virtual string getAuthor();
		virtual string getSerial();
		void setNext(Item *n);
		Item *getNext();
		void editTitle(string newTitle);
		void editAuthor(string newAuthor);
		void editCost(float newCost);
		void bBorr();
		void bIn();
		int getbStat();
		void bLost();
};
class Book : public Item
{
	private:
		string author, ISBN;
	public:
		//constructor for an individual book 
		Book(string titl, int id, int copy, float cost, string auth, string ISB) : Item(titl, id, copy, cost, auth,ISB)
		{
			author = auth;
			ISBN = ISB;
		}
		//string getAuthor();
		//string getISBN();
		//void editAuthor(string newTitle);
		
};
class audio : public Item
{
	private:
		string author, serial;
	public:
		audio(string titl, int id, int copy,float cost, string auth, string ser) : Item(titl,id,copy,cost,auth,ser)
		{
			author = auth;
			serial = ser;
		}
};
class ref : public Item
{
	private:
		string author, ISBN;
	public:
		ref(string titl, int id, int copy, float cost, string auth, string ser) : Item(titl,id,copy,cost,auth,ser)
		{
			author = auth;
			ISBN = ser;
		}
};
class dvd : public Item
{
	private:
		string director, serial;
	public:
		dvd(string titl, int id, int copy, float cost, string auth, string ser) : Item(titl,id,copy,cost,auth,ser)
		{
			director = auth;
			serial = ser;
		}
};
class Catalog
{
	private:
		int cCount;
		//top and bottom nodes of linked lists
		Item *top;
		Item *bottom;
	public:
		//constructor setting different values to the variables
		Catalog();
		~Catalog();
		void addItem();
		void printList();
		void editBook();
		void searchBook();
		int checkID(int checkThis);
		string printName(int id);
		void changebStat(int id);
		void checkinbStat(int id);
		void lostbStat(int id);
		void delBook(int id);
		int getbookStat(int id);
		
};

class Loan
{
	private:
		int patronID;
		int bookID;
		int dueDateM, dueDateD, dueDateY;
		Loan *next;
	public:
		Loan(int pID, int bID, int loanPeriod, int dueDatem, int dueDated, int dueDatey);
		int getpID();
		int getbID();
		void setNext(Loan *n);
		Loan *getNext();
};

class Loans
{
	private:
		int lCount, loanPeriod;
		Loan *top;
		Loan *bottom;
		float fineRate;
	public:
		Loans();
		~Loans();
		void checkOut(int pID, int bID, int loanPeriod, int dueDatem, int dueDated, int dueDatey);
		void checkIn(int pID, int bID);
};
