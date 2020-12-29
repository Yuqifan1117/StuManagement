#include "Book.h"

Book::Book(string bookname, bool isborrowed) : BookName(bookname), isBorrowed(isborrowed){}

string Book::getBookName()
{
	return BookName;
}

bool Book::getisBorrowed()
{
	return isBorrowed;
}

void Book::setisBorrowed()
{
	this->isBorrowed = true;
}

void Book::setisNotBorrowed()
{
	this->isBorrowed = false;
}

