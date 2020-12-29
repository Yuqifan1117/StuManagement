#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include "Grade.h"
#include "Book.h"
#include"User.h"
/*
	����Ա�࣬�����ϵͳ�Ĳ������̳��û�
*/
class Admin :public User 
{
public:
	Admin(User u);
	Admin(const Admin& en);
	bool Add(Grade newGrade);  //���һ���µ�ѧ���ɼ���ѧ����Ϣ
	bool Select();    // ����Աѡ�����
	void Search();      // ��ɶ�ѧ���ɼ���ѯ
	Grade FindStudent(string id);
	void SearchID();  //����ѧ��ѧ�Ž��в�ѯ
	void SearchName();  //����ѧ���������в�ѯ
	void SearchAllStudent();   // ��ѯ��ʾ����ѧ��
	bool ChangeGrade();   // �޸�ѧ���ɼ�
	void AddBook();    // ����鼮��Ϣ
private:
	vector<Grade> GradeList;    // Grade�б���������ѧ���ɼ�
	bool isAdded = false;  // �ж���ʦ��������³ɼ����ɼ��б��Ƿ�Ҫ����
};

#endif