#include"Student.h"

#include<iostream>
#include <fstream>
#include <algorithm>
#include<string>
using namespace std;

struct borrow {
	string bookname;
	string sid;
	borrow(string b,string s):bookname(b),sid(s){}
};
Student::Student(User u,string sid) :User(u)
{
	this->stuID = sid;
}
bool Student::Select()
{
	cout << "****************************************" << endl;
	cout << endl;
	cout << "            选择1：查询个人成绩" << endl;
	cout << "            选择2：借阅书籍" << endl;
	cout << "            选择3：显示当前待归还的书籍" << endl;
	cout << "            选择4：归还书籍" << endl;
	cout << "            选择5：退出登录" << endl;
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
	while (select != 1 && select != 2 && select != 3 && select != 4 && select != 5)
	{
		cout << "请重新输入：";
		cin >> select;
	};
	switch (select)
	{
	case 1: {
		ShowOwnGrade(stuID);
		break;
	};
	case 2: {
		BorrowBook();
		break;
	};
	case 3: {
		ShowBorrowedBook();
		break;

	};
	case 4: {
		ReturnBook();
		break;
	};
	case 5: {
		break;
	};
	};
	if (select != 5)
	{
		return true;
	}
	else
	{
		return false;
	};
}
void Student::ShowOwnGrade(string sid)
{
	vector<Grade> GradeList;
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
		if (stuID == GradeList[i].getID()) {
			cout << "学号：" << stuID << endl;
			cout << "学生姓名：" << GradeList[i].getName() << endl;
			cout << "程序设计语言成绩：" << GradeList[i].getC() << endl;
			cout << "英语成绩：" << GradeList[i].getEng() << endl;
			cout << "高等数学成绩：" << GradeList[i].getMat() << endl;
			cout << "平均成绩：" << GradeList[i].getAverage() << endl;
			return;
		}
	}
}
void Student::BorrowBook()
{
	cout << "***************欢迎使用！***************" << endl;
	cout << " --------------------------------------" << endl;
	cout << "|\n";
	cout << "|     * 正在运行图书管理系统 *" << endl;
	cout << "|\n";
	cout << " --------------------------------------" << endl;
	cout << endl;
	ifstream infile("BookRecord.txt");
	while (!infile.eof())
	{
		string bookname; bool isborrowed;
		infile >> bookname;
		infile >> isborrowed;
		if (infile.good()) {
			Book b(bookname, isborrowed);
			BookList.push_back(b);
		}
	}
	infile.close();
	int booksize = BookList.size();
	for (int i = 0; i < booksize; i++) {
		cout << "《" << BookList[i].getBookName() << "》" << "		";
		if (BookList[i].getisBorrowed()) {
			cout << "已被借阅" << endl;
			BookList[i].setisNotBorrowed();
		}
		else {
			cout << "未被借阅" << endl;
		}
		cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
	}
	cout << "****************************************" << endl;
	cout << "请输入选择要借阅的书籍：(从上到下第几本)" << endl;
	int select;
	cin >> select;
	cout << "借阅成功，请注意及时归还！" << endl;
	if (BookList[select - 1].getisBorrowed() != 0) {
		cout << "该书已被借走，请等待" << endl;
	}
	else {
		BookList[select - 1].setisBorrowed();
	}
	ofstream outfile;
	outfile.open("BookRecord.txt", ios::out);
	for (int i = 0; i < booksize; i++) {
		outfile << BookList[i].getBookName() <<"	"<< BookList[i].getisBorrowed() << endl;
	}
	outfile.close();
	outfile.open("BookBorrowedRecord.txt", ios::app);
	for (int i = 0; i < booksize; i++) {
		if (BookList[i].getisBorrowed()) {
			outfile << BookList[i].getBookName() << "	" << stuID << endl;
		}
	}
	outfile.close();
}
void Student::ShowBorrowedBook()
{
	ifstream infile("BookBorrowedRecord.txt");
	cout << "****************************************" << endl;
	cout << "当前借阅书籍：" << endl;
	while (!infile.eof())
	{
		string bookname; string sid;
		infile >> bookname;
		infile >> sid;
		if (infile.good()) {
			if (sid == this->stuID) {
				cout << "《" << bookname << "》" << "		" << endl;
				cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
			}
		}
	}
	infile.close();
}
void Student::ReturnBook()
{
	vector<borrow> BorrowList;
	ifstream openfile("BookBorrowedRecord.txt");
	while (!openfile.eof())
	{
		string bookname; string sid;
		openfile >> bookname;
		openfile >> sid;
		if (openfile.good()) {
			borrow b(bookname, sid);
			BorrowList.push_back(b);
		}
	}
	openfile.close();
	int size = BookList.size();
	if (size == 0) {
		ifstream infile("BookRecord.txt");
		while (!infile.eof())
		{
			string bookname; bool isborrowed;
			infile >> bookname;
			infile >> isborrowed;
			if (infile.good()) {
				Book b(bookname, isborrowed);
				BookList.push_back(b);
			}
		}
		infile.close();
	}
	ShowBorrowedBook();
	cout << "请输入选择要归还的书籍：(从上到下第几本，输入0返回)" << endl;
	int select;
	cin >> select;
	ofstream outfile;
	if (select == 0)return;
	else {
		cout << "归还成功！" << endl;
		int line = 1; string returnBookname;
		ifstream infile("BookBorrowedRecord.txt");
		while (!infile.eof())
		{
			string bookname; string sid;
			infile >> bookname;
			infile >> sid;
			if (infile.good()) {
				if (sid == this->stuID) {
					if (line == select) {
						returnBookname = bookname;
						break;
					}
					line++;
				}
			}
		}
		infile.close();
		for (int i = 0; i < BookList.size(); i++) {
			if (BookList[i].getBookName() == returnBookname) {
				BookList[i].setisNotBorrowed();
				break;
			}
		}
		outfile.open("BookRecord.txt", ios::out);
		for (int i = 0; i < BookList.size(); i++) {
			outfile << BookList[i].getBookName() << "	" << BookList[i].getisBorrowed() << endl;
		}
		outfile.close();
		for (int i = 0; i < BorrowList.size(); i++) {
			if (BorrowList[i].bookname == returnBookname && BorrowList[i].sid == stuID) {
				BorrowList[i].sid = "";
			}
		}

	}
	outfile.open("BookBorrowedRecord.txt", ios::out);
	for (int i = 0; i < BorrowList.size(); i++) {
		if (BorrowList[i].sid!="") {
			outfile << BorrowList[i].bookname << "	" << BorrowList[i].sid << endl;
		}
	}
	outfile.close();

}
;