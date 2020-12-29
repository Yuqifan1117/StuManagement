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
	cout << "            ѡ��1����ѯ���˳ɼ�" << endl;
	cout << "            ѡ��2�������鼮" << endl;
	cout << "            ѡ��3����ʾ��ǰ���黹���鼮" << endl;
	cout << "            ѡ��4���黹�鼮" << endl;
	cout << "            ѡ��5���˳���¼" << endl;
	cout << endl;
	cout << "****************************************" << endl;
	cout << "������ѡ��";
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
			cout << "���������֣�";
			cin >> select;
		}
	}
	while (select != 1 && select != 2 && select != 3 && select != 4 && select != 5)
	{
		cout << "���������룺";
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
		cout << "��ǰ�����ڳɼ���¼��" << endl;
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
			cout << "ѧ�ţ�" << stuID << endl;
			cout << "ѧ��������" << GradeList[i].getName() << endl;
			cout << "����������Գɼ���" << GradeList[i].getC() << endl;
			cout << "Ӣ��ɼ���" << GradeList[i].getEng() << endl;
			cout << "�ߵ���ѧ�ɼ���" << GradeList[i].getMat() << endl;
			cout << "ƽ���ɼ���" << GradeList[i].getAverage() << endl;
			return;
		}
	}
}
void Student::BorrowBook()
{
	cout << "***************��ӭʹ�ã�***************" << endl;
	cout << " --------------------------------------" << endl;
	cout << "|\n";
	cout << "|     * ��������ͼ�����ϵͳ *" << endl;
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
		cout << "��" << BookList[i].getBookName() << "��" << "		";
		if (BookList[i].getisBorrowed()) {
			cout << "�ѱ�����" << endl;
			BookList[i].setisNotBorrowed();
		}
		else {
			cout << "δ������" << endl;
		}
		cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
	}
	cout << "****************************************" << endl;
	cout << "������ѡ��Ҫ���ĵ��鼮��(���ϵ��µڼ���)" << endl;
	int select;
	cin >> select;
	cout << "���ĳɹ�����ע�⼰ʱ�黹��" << endl;
	if (BookList[select - 1].getisBorrowed() != 0) {
		cout << "�����ѱ����ߣ���ȴ�" << endl;
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
	cout << "��ǰ�����鼮��" << endl;
	while (!infile.eof())
	{
		string bookname; string sid;
		infile >> bookname;
		infile >> sid;
		if (infile.good()) {
			if (sid == this->stuID) {
				cout << "��" << bookname << "��" << "		" << endl;
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
	cout << "������ѡ��Ҫ�黹���鼮��(���ϵ��µڼ���������0����)" << endl;
	int select;
	cin >> select;
	ofstream outfile;
	if (select == 0)return;
	else {
		cout << "�黹�ɹ���" << endl;
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