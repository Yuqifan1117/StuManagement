#pragma once
#ifndef BOOK_H
#define BOOK_H

#include<string>
using namespace std;

/*
	���ͼ���࣬��¼ĳ����ĸ����������
*/
class Book
{
public:
	Book(string bookname,bool isborrowed=0);
	string getBookName();
	bool getisBorrowed();   // ��ȡͼ��Ľ���״̬
	void setisBorrowed();   //  �޸��鼮����״̬Ϊ�ѽ���
	void setisNotBorrowed();   // �޸��鼮����״̬Ϊ�ѹ黹
private:
	string BookName;  // �鼮����
	bool isBorrowed;  // ����״̬����ʾ�Ƿ���ģ�1��ʾ���ɽ��ģ�0��ʾ�ɽ���


};
#endif