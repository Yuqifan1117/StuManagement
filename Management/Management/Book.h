#pragma once
#ifndef BOOK_H
#define BOOK_H

#include<string>
using namespace std;

/*
	设计图书类，记录某本书的各种属性情况
*/
class Book
{
public:
	Book(string bookname,bool isborrowed=0);
	string getBookName();
	bool getisBorrowed();   // 获取图书的借阅状态
	void setisBorrowed();   //  修改书籍借阅状态为已借阅
	void setisNotBorrowed();   // 修改书籍借阅状态为已归还
private:
	string BookName;  // 书籍名称
	bool isBorrowed;  // 借阅状态，表示是否借阅，1表示不可借阅，0表示可借阅


};
#endif