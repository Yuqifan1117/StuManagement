#include"User.h"
#include<iostream>
using namespace std;

User::User(string id, string password) :ID(id), Password(password) {};

User::User(const User& u)
{
	this->ID = u.ID;
	this->Password = u.Password;
};

bool operator==(const User& u1, const User& u2)
{
	return (u1.ID == u2.ID) && (u1.Password == u2.Password);
};

bool operator!=(const User& u1, const User& u2)
{
	return (u1.ID != u2.ID) || (u1.Password != u2.Password);
};

void User::SetID(string id)
{
	this->ID = id;
};
void User::SetPassword(string password)
{
	this->Password = password;
};

string User::GetID()
{
	return ID;
};
string User::GetPassword()
{
	return Password;
};
