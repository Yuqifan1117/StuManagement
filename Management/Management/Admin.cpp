#include"Admin.h"

#include<iostream>
#include <fstream>
#include <algorithm>
#include<string>
using namespace std;


Admin::Admin(User p) :User(p)
{
};
Admin::Admin(const Admin& en) :User(en)
{
	//project.assign(en.project.begin(), en.project.end());
};


//自定义成绩比较函数
bool cmp(Grade a, Grade b) {
	return a.getAverage() > b.getAverage();
}

bool Admin::Add(Grade grade) {
	// 当前不存在成绩记录
	ifstream infile("GradeRecord.txt");
	if (!infile)
	{
		cout << "当前不存在成绩记录！" << endl;
		infile.close();
		ofstream outfile;
		outfile.open("GradeRecord.txt", ios::app);
		outfile << grade.getID() << "	" << grade.getName() << "	" << grade.getC() << "	" << grade.getEng() << "	" << grade.getMat() << "	" << endl;
		outfile.close();
	}
	else {
		infile.close();
		ofstream outfile;
		outfile.open("GradeRecord.txt", ios::app);
		outfile << grade.getID() << "	" << grade.getName() << "	" << grade.getC() << "	" << grade.getEng() << "	" << grade.getMat() << "	" << endl;
		outfile.close();
	}
	cout << "增加学生成绩成功！" << endl;
	isAdded = true;
	return true;
}
bool Admin::Select()
{
	cout << "****************************************" << endl;
	cout << endl;
	cout << "            选择1：添加学生成绩" << endl;
	cout << "            选择2：查找学生成绩" << endl;
	cout << "            选择3：查看学生成绩" << endl;
	cout << "            选择4：修改学生成绩" << endl;
	cout << "            选择5：添加书籍信息" << endl;
	cout << "            选择6：退出登录" << endl;
	cout << endl;
	cout << "****************************************" << endl;
	cout << "请输入选择：";
	int select;

	cin >> select;
	while (1)
	{
		if (cin.good())
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "请输入数字：";
			cin >> select;
		}
	}
	while (select != 1 && select != 2 && select != 3 && select != 4 && select != 5 && select != 6)
	{
		cout << "请重新输入：";
		cin >> select;
	};
	switch (select)
	{
		case 1: {
			string Nname, NID, Neng, Nc, Nmat;
			cout << "请输入学生学号：";
			cin >> NID;
			cout << "请输入学生姓名：";
			cin >> Nname;
			cout << "请输入程序设计语言成绩：";
			cin >> Nc;
			cout << "请输入大学物理成绩：";
			cin >> Neng;
			cout << "请输入微积分成绩：";
			cin >> Nmat;
			Grade newGrade(NID, Nname, Neng, Nc, Nmat);
			Add(newGrade);
			break;
		};
		case 2: {
			Search();

			break;
		};
		case 3: {
			SearchAllStudent();
			break;

		};
		case 4: {
			ChangeGrade();
			break;
		};
		case 5: {
			AddBook();
			break;
		};
		case 6: {
			break;
		};
	};
	if (select != 6)
	{
		return true;
	}
	else
	{
		return false;
	};
}
void Admin::Search()
{
	cout << "****************************************" << endl;
	cout << endl;
	cout << "            选择1：按学号" << endl;
	cout << "            选择2：按学生姓名" << endl;
	cout << endl;
	cout << "****************************************" << endl;
	cout << "请输入你要查找的方式：";
	int select;
	int size = GradeList.size();
	cin >> select;
	while (1)
	{
		if (cin.good())
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "请输入数字：";
			cin >> select;
		}
	}
	while (select != 1 && select != 2)
	{
		cout << "请重新输入：";
		cin >> select;
	};
	ifstream infile("GradeRecord.txt");
	if (!infile) {
		cout << "当前不存在成绩记录！" << endl;
		infile.close();
	}
	else {
		while (!infile.eof())
		{
			string Nid,Nname, Neng, Nc, Nmat;
			infile >> Nid;
			infile >> Nname;
			infile >> Nc;
			infile >> Neng;
			infile >> Nmat;
			if (infile.good()) {
				Grade nowgrade = Grade(Nid, Nname, Neng, Nc, Nmat);
				GradeList.push_back(nowgrade);
			}
		}
	}
	switch (select)
	{
	case 1: {
		SearchID();
		break;
	};
	case 2: {
		SearchName();
		break;
	};
	};
}
Grade Admin::FindStudent(string id)
{
	ifstream infile("GradeRecord.txt");
	if (!infile) {
		cout << "当前不存在成绩记录！" << endl;
		infile.close();
	}
	else {
		while (!infile.eof())
		{
			string Nid, Nname, Neng, Nc, Nmat;
			infile >> Nid;
			infile >> Nname;
			infile >> Nc;
			infile >> Neng;
			infile >> Nmat;
			if (infile.good()) {
				Grade nowgrade = Grade(Nid, Nname, Neng, Nc, Nmat);
				GradeList.push_back(nowgrade);
			}
		}
	}
	int size = GradeList.size();
	for (int i = 0; i < size; i++) {
		if (id == GradeList[i].getID()) {
			return Grade(id, GradeList[i].getName(), GradeList[i].getC(), GradeList[i].getEng(), GradeList[i].getMat());
		}
	}
	return Grade();
}

void Admin::SearchID()
{
	cout << "请输入你要找的学号：";
	string stuID;
	cin >> stuID;
	int size = GradeList.size();
	for (int i = 0; i < size; i++) {
		if (stuID == GradeList[i].getID()) {
			cout << "查询成功！" << endl;
			cout << "学号：" << stuID << "学生姓名：" << GradeList[i].getName() << "程序设计语言成绩：" << GradeList[i].getC() << "大学物理成绩：" << GradeList[i].getEng() << "微积分成绩：" << GradeList[i].getMat() << "平均成绩：" << GradeList[i].getAverage() << endl;
			return;
		}
	}
	cout << "查询不到该学号的成绩信息" << endl;
};

void Admin::SearchName()
{
	cout << "请输入你要找的学生姓名：";
	string name;
	cin >> name;
	int size = GradeList.size();
	for (int i = 0; i < size; i++) {
		if (name == GradeList[i].getName()) {
			cout << "查询成功！" << endl;
			cout << "学号：" << GradeList[i].getID() << "学生姓名：" << GradeList[i].getName() << "程序设计语言成绩：" << GradeList[i].getC() << "大学物理成绩：" << GradeList[i].getEng() << "微积分成绩：" << GradeList[i].getMat() << "平均成绩：" << GradeList[i].getAverage() << endl;
			return;
		}
	}
	cout << "查询不到该姓名学生的成绩信息" << endl;
};

void Admin::SearchAllStudent() {
	int size = GradeList.size();
	if (size == 0) {
		ifstream infile("GradeRecord.txt");
		if (!infile) {
			cout << "当前不存在成绩记录！" << endl;
			infile.close();
		}
		else {
			while (!infile.eof())
			{
				string Nid, Nname, Neng, Nc, Nmat;
				infile >> Nid;
				infile >> Nname;
				infile >> Nc;
				infile >> Neng;
				infile >> Nmat;
				if (infile.good()) {
					Grade nowgrade = Grade(Nid, Nname, Neng, Nc, Nmat);
					GradeList.push_back(nowgrade);
				}
			}
		}
	}
	size = GradeList.size();
	cout << "***************学生成绩总览！***************" << endl;
	for (int i = 0; i < size; i++) {
		cout << "学号：" << GradeList[i].getID() << "学生姓名：" << GradeList[i].getName() << "程序设计语言成绩：" << GradeList[i].getC() << "英语成绩：" << GradeList[i].getEng() << "高等数学成绩：" << GradeList[i].getMat() << "平均成绩：" << GradeList[i].getAverage() << endl;
	}
	int judg;
	cout << "是否按学生平均分进行排序？是输入1，否输入0" << endl;
	cin >> judg;
	if (judg == 1) {
		sort(GradeList.begin(), GradeList.end(), cmp);
		cout << "***************按学生成绩高低排序！***************" << endl;
		for (int i = 0; i < size; i++) {
			cout << "学号：" << GradeList[i].getID() << "学生姓名：" << GradeList[i].getName() << "程序设计语言成绩：" << GradeList[i].getC() << "大学物理成绩：" << GradeList[i].getEng() << "微积分成绩：" << GradeList[i].getMat() << "平均成绩：" << GradeList[i].getAverage() << endl;
		}
	}
	GradeList.clear();
}
bool Admin::ChangeGrade() {
	int size = GradeList.size();
	if (size == 0) {
		ifstream infile("GradeRecord.txt");
		if (!infile) {
			cout << "当前不存在成绩记录！" << endl;
			infile.close();
		}
		else {
			while (!infile.eof())
			{
				string Nid, Nname, Neng, Nc, Nmat;
				infile >> Nid;
				infile >> Nname;
				infile >> Nc;
				infile >> Neng;
				infile >> Nmat;
				if (infile.good()) {
					Grade nowgrade = Grade(Nid, Nname, Neng, Nc, Nmat);
					GradeList.push_back(nowgrade);
				}
			}
		}
	}
	cout << "请输入你要修改的学生学号：";
	string stuID;
	cin >> stuID;
	size = GradeList.size();
	for (int i = 0; i < size; i++) {
		if (stuID == GradeList[i].getID()) {
			string Neng, Nc, Nmat;
			cout << "请输入更新后的程序设计语言成绩：";
			cin >> Nc;
			GradeList[i].changeC(Nc);
			cout << "请输入更新后的大学物理成绩：";
			cin >> Neng;
			GradeList[i].changeEng(Neng);
			cout << "请输入更新后的微积分成绩：";
			cin >> Nmat;
			GradeList[i].changeMat(Nmat);
			break;
		}
	}
	cout << "修改成功！" << endl;
	ofstream outfile;
	outfile.open("GradeRecord.txt", ios::out);
	for (int i = 0; i < size; i++) {
		outfile << GradeList[i].getID() << "	" << GradeList[i].getName() << "	" << GradeList[i].getC() << "	" << GradeList[i].getEng() << "	" << GradeList[i].getMat() << "	" << endl;
	}
	outfile.close();
	return true;
}

void Admin::AddBook()
{
	cout << "请输入增加的书籍名称：";
	string bookname;
	cin >> bookname;
	Book newbook(bookname);
	ofstream outfile;
	outfile.open("BookRecord.txt", ios::app);
	outfile << newbook.getBookName() << "	" << newbook.getisBorrowed() << endl;
	outfile.close();
	cout << "添加书籍成功！" << endl;
}
