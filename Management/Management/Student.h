#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Grade.h"
#include "Book.h"
#include"User.h"
/*
	ѧ���࣬�̳��û�����¼ѧ�������е�����
*/
class Student :public User
{
public:
	Student(User u, string sid);
	void ShowOwnGrade(string sid); // ��ѯ�Լ��ĳɼ�
	void BorrowBook();  // �����鼮
	void ShowBorrowedBook();   //��ʾ��ǰ���黹���鼮
	void ReturnBook();   // �黹�鼮
	bool Select();   // ѧ��ϵͳ����
private:
	string stuID;  // ѧ��
	vector<Book> BookList;   // �����Խ��ĵ��鼮
};
#endif