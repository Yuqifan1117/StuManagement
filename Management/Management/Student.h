#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Grade.h"
#include "Book.h"
#include"User.h"
/*
	学生类，继承用户，记录学生所特有的属性
*/
class Student :public User
{
public:
	Student(User u, string sid);
	void ShowOwnGrade(string sid); // 查询自己的成绩
	void BorrowBook();  // 借阅书籍
	void ShowBorrowedBook();   //显示当前待归还的书籍
	void ReturnBook();   // 归还书籍
	bool Select();   // 学生系统界面
private:
	string stuID;  // 学号
	vector<Book> BookList;   // 所可以借阅的书籍
};
#endif