#pragma once
#ifndef USER_H
#define USER_H

#include<string>
using namespace std;
/*
	完成用户注册登录功能
*/
class User
{
public:
	User(string ID = "", string Password = "");   // 构造函数，完成注册
	User(const User& u);  // 拷贝构造函数
	void SetID(string id);   // 设置用户名
	void SetPassword(string password);   // 设置密码
	string GetID();  // 获取用户名
	string GetPassword();   // 获取密码
	// 重载操作符，完成用户核验
	friend bool operator==(const User&, const User&);
	friend bool operator!=(const User&, const User&);
private:
	string ID;
	string Password;
};

#endif