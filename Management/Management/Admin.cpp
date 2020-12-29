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


//�Զ���ɼ��ȽϺ���
bool cmp(Grade a, Grade b) {
	return a.getAverage() > b.getAverage();
}

bool Admin::Add(Grade grade) {
	// ��ǰ�����ڳɼ���¼
	ifstream infile("GradeRecord.txt");
	if (!infile)
	{
		cout << "��ǰ�����ڳɼ���¼��" << endl;
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
	cout << "����ѧ���ɼ��ɹ���" << endl;
	isAdded = true;
	return true;
}
bool Admin::Select()
{
	cout << "****************************************" << endl;
	cout << endl;
	cout << "            ѡ��1�����ѧ���ɼ�" << endl;
	cout << "            ѡ��2������ѧ���ɼ�" << endl;
	cout << "            ѡ��3���鿴ѧ���ɼ�" << endl;
	cout << "            ѡ��4���޸�ѧ���ɼ�" << endl;
	cout << "            ѡ��5������鼮��Ϣ" << endl;
	cout << "            ѡ��6���˳���¼" << endl;
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
	while (select != 1 && select != 2 && select != 3 && select != 4 && select != 5 && select != 6)
	{
		cout << "���������룺";
		cin >> select;
	};
	switch (select)
	{
		case 1: {
			string Nname, NID, Neng, Nc, Nmat;
			cout << "������ѧ��ѧ�ţ�";
			cin >> NID;
			cout << "������ѧ��������";
			cin >> Nname;
			cout << "���������������Գɼ���";
			cin >> Nc;
			cout << "�������ѧ����ɼ���";
			cin >> Neng;
			cout << "������΢���ֳɼ���";
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
	cout << "            ѡ��1����ѧ��" << endl;
	cout << "            ѡ��2����ѧ������" << endl;
	cout << endl;
	cout << "****************************************" << endl;
	cout << "��������Ҫ���ҵķ�ʽ��";
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
			cout << "���������֣�";
			cin >> select;
		}
	}
	while (select != 1 && select != 2)
	{
		cout << "���������룺";
		cin >> select;
	};
	ifstream infile("GradeRecord.txt");
	if (!infile) {
		cout << "��ǰ�����ڳɼ���¼��" << endl;
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
		if (id == GradeList[i].getID()) {
			return Grade(id, GradeList[i].getName(), GradeList[i].getC(), GradeList[i].getEng(), GradeList[i].getMat());
		}
	}
	return Grade();
}

void Admin::SearchID()
{
	cout << "��������Ҫ�ҵ�ѧ�ţ�";
	string stuID;
	cin >> stuID;
	int size = GradeList.size();
	for (int i = 0; i < size; i++) {
		if (stuID == GradeList[i].getID()) {
			cout << "��ѯ�ɹ���" << endl;
			cout << "ѧ�ţ�" << stuID << "ѧ��������" << GradeList[i].getName() << "����������Գɼ���" << GradeList[i].getC() << "��ѧ����ɼ���" << GradeList[i].getEng() << "΢���ֳɼ���" << GradeList[i].getMat() << "ƽ���ɼ���" << GradeList[i].getAverage() << endl;
			return;
		}
	}
	cout << "��ѯ������ѧ�ŵĳɼ���Ϣ" << endl;
};

void Admin::SearchName()
{
	cout << "��������Ҫ�ҵ�ѧ��������";
	string name;
	cin >> name;
	int size = GradeList.size();
	for (int i = 0; i < size; i++) {
		if (name == GradeList[i].getName()) {
			cout << "��ѯ�ɹ���" << endl;
			cout << "ѧ�ţ�" << GradeList[i].getID() << "ѧ��������" << GradeList[i].getName() << "����������Գɼ���" << GradeList[i].getC() << "��ѧ����ɼ���" << GradeList[i].getEng() << "΢���ֳɼ���" << GradeList[i].getMat() << "ƽ���ɼ���" << GradeList[i].getAverage() << endl;
			return;
		}
	}
	cout << "��ѯ����������ѧ���ĳɼ���Ϣ" << endl;
};

void Admin::SearchAllStudent() {
	int size = GradeList.size();
	if (size == 0) {
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
	}
	size = GradeList.size();
	cout << "***************ѧ���ɼ�������***************" << endl;
	for (int i = 0; i < size; i++) {
		cout << "ѧ�ţ�" << GradeList[i].getID() << "ѧ��������" << GradeList[i].getName() << "����������Գɼ���" << GradeList[i].getC() << "Ӣ��ɼ���" << GradeList[i].getEng() << "�ߵ���ѧ�ɼ���" << GradeList[i].getMat() << "ƽ���ɼ���" << GradeList[i].getAverage() << endl;
	}
	int judg;
	cout << "�Ƿ�ѧ��ƽ���ֽ�������������1��������0" << endl;
	cin >> judg;
	if (judg == 1) {
		sort(GradeList.begin(), GradeList.end(), cmp);
		cout << "***************��ѧ���ɼ��ߵ�����***************" << endl;
		for (int i = 0; i < size; i++) {
			cout << "ѧ�ţ�" << GradeList[i].getID() << "ѧ��������" << GradeList[i].getName() << "����������Գɼ���" << GradeList[i].getC() << "��ѧ����ɼ���" << GradeList[i].getEng() << "΢���ֳɼ���" << GradeList[i].getMat() << "ƽ���ɼ���" << GradeList[i].getAverage() << endl;
		}
	}
	GradeList.clear();
}
bool Admin::ChangeGrade() {
	int size = GradeList.size();
	if (size == 0) {
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
	}
	cout << "��������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
	string stuID;
	cin >> stuID;
	size = GradeList.size();
	for (int i = 0; i < size; i++) {
		if (stuID == GradeList[i].getID()) {
			string Neng, Nc, Nmat;
			cout << "��������º�ĳ���������Գɼ���";
			cin >> Nc;
			GradeList[i].changeC(Nc);
			cout << "��������º�Ĵ�ѧ����ɼ���";
			cin >> Neng;
			GradeList[i].changeEng(Neng);
			cout << "��������º��΢���ֳɼ���";
			cin >> Nmat;
			GradeList[i].changeMat(Nmat);
			break;
		}
	}
	cout << "�޸ĳɹ���" << endl;
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
	cout << "���������ӵ��鼮���ƣ�";
	string bookname;
	cin >> bookname;
	Book newbook(bookname);
	ofstream outfile;
	outfile.open("BookRecord.txt", ios::app);
	outfile << newbook.getBookName() << "	" << newbook.getisBorrowed() << endl;
	outfile.close();
	cout << "����鼮�ɹ���" << endl;
}
