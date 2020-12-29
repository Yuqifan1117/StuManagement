#pragma once
#ifndef USER_H
#define USER_H

#include<string>
using namespace std;
/*
	����û�ע���¼����
*/
class User
{
public:
	User(string ID = "", string Password = "");   // ���캯�������ע��
	User(const User& u);  // �������캯��
	void SetID(string id);   // �����û���
	void SetPassword(string password);   // ��������
	string GetID();  // ��ȡ�û���
	string GetPassword();   // ��ȡ����
	// ���ز�����������û�����
	friend bool operator==(const User&, const User&);
	friend bool operator!=(const User&, const User&);
private:
	string ID;
	string Password;
};

#endif