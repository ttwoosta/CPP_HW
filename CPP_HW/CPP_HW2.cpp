// CPP_HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct bookType
{
	int bookNumber;
	string title;
	string authorLastName;
	string publisher;
	int numberOfPages;
	double price;

	// contructor
	bookType(int, string, string, string, int, double);
	string desc();

	bookType* link;
};

class linkedListBook
{
public:
	// default contructor
	// initialize the list to an empty state
	linkedListBook();

	// destructor
	// Delete all nodes from the list
	~linkedListBook();

	// the length of the linked list
	int length();

	// insert node on the top
	void insertFirst(bookType* newBook);

	// insert node at position
	void insertAt(bookType* newBook, int position);

	// access the first node of the list
	bookType* firstBook();


protected:
	int count; // variable to store the number of element

	bookType* first; // pointer to the first node of the list
	bookType* last;  // pointer to the last node of the list
private:

};

int main()
{
	linkedListBook *bookList = new linkedListBook();
	bookList->insertFirst(new bookType(1, "HOW TO GET FASTER PIZZA", "SMITH", "READING MATERIALS INC.", 534, 17.0));
	bookList->insertFirst(new bookType(2, "THE WOK WAY TO COOK", "KZOCHSKY", "REED-N-RITE", 339, 23.15));
	bookList->insertFirst(new bookType(3, "REVENGE OF MICKEY", "JONES", "PRINTING IS US", 740, 14.0));
	bookList->insertFirst(new bookType(4, "BODYBUILD IN 10 MINUTES A DAY", "PORTER", "READING MATERIALS INC.", 532, 18.50));
	bookList->insertFirst(new bookType(5, "HANDCRANKED COMPUTERS", "WHITE", "AMERICAN PUBLISHING", 457, 67.99));
	bookList->insertFirst(new bookType(6, "PAINLESS CHILD-REARING", "BAKER", "AMERICAN PUBLISHING", 864, 48.98));
	bookList->insertFirst(new bookType(7, "COOKING WITH MUSHROOMS", "ROBINSON", "READING MATERIALS INC.", 231, 12.50));
	bookList->insertFirst(new bookType(10, "HOLY GRAIL OF ORACLE", "AUSTIN", "AMERICAN PUBLISHING", 789, 16.25));

	// insert a book at position 2
	bookList->insertAt(new bookType(8, "DATABASE IMPLEMENTATION", "ADAMS", "READING MATERIALS INC.", 642, 24.50), 2);
	bookList->insertAt(new bookType(9, "E-BUSINESS THE EASY WAY", "JONES", "PUBLISH OUR WAY", 328, 37.99), 2);

	bookType *currBook = bookList->firstBook();
	while (currBook != NULL)
	{
		cout << currBook->desc() << endl;
		currBook = currBook->link;
	}

	// remove list of books from memory
	delete bookList;

	return 0;
}

bookType::bookType(int bookNum, string bookTitle, string authorLName, string pub, int pages, double bookPrice) {
	bookNumber = bookNum;
	title = bookTitle;
	authorLastName = authorLName;
	publisher = pub;
	numberOfPages = pages;
	price = bookPrice;
}

string bookType::desc() {
	// to_string method
	// https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
	return "Book #" + to_string(bookNumber) + ": " + title + 
		" (" + to_string(numberOfPages) + " pages)" +
		", by " + authorLastName + ", publish by " + publisher +
		", price $" + to_string(price);
}

linkedListBook::linkedListBook()
{
	first = NULL;
	last = NULL;
	count = 0;
}

linkedListBook::~linkedListBook()
{
	bookType* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link; // advance first node to next node
		delete temp;
	}
	last = NULL; // initialize the last node to NULL
	count = 0;
}

int linkedListBook::length() 
{
	return count;
}

void linkedListBook::insertFirst(bookType* newBook) {
	// make sure new book never be empty
	assert(newBook != NULL);

	newBook->link = first;
	first = newBook;
	count++;  // increment count

	// if the list was empty, new book is also
	// the last node of the list
	if (last == NULL)
		last = newBook;
}

bookType* linkedListBook::firstBook() {
	return first;
}

void linkedListBook::insertAt(bookType* newBook, int position) {
	// make sure new book never be empty
	assert(newBook != NULL);

	if (position > count)
		return;

	bookType* curr = first;
	bookType* pre = curr;
		
	for (int i = 1; i < position; i++)
	{
		pre = curr;
		curr = curr->link;
	}

	pre->link = newBook;
	newBook->link = curr;
	count++;
}
