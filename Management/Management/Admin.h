#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include "Grade.h"
#include "Book.h"
#include"User.h"
/*
	管理员类，负责对系统的操作，继承用户
*/
class Admin :public User 
{
public:
	Admin(User u);
	Admin(const Admin& en);
	bool Add(Grade newGrade);  //添加一个新的学生成绩或学生信息
	bool Select();    // 管理员选择界面
	void Search();      // 完成对学生成绩查询
	Grade FindStudent(string id);
	void SearchID();  //根据学生学号进行查询
	void SearchName();  //根据学生姓名进行查询
	void SearchAllStudent();   // 查询显示所有学生
	bool ChangeGrade();   // 修改学生成绩
	void AddBook();    // 添加书籍信息
private:
	vector<Grade> GradeList;    // Grade列表，保存所有学生成绩
	bool isAdded = false;  // 判断老师有无添加新成绩，成绩列表是否要更新
};

#endif