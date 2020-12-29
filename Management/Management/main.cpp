#include<iostream> 
#include<string>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include "User.h"
#include "Admin.h"
#include "Student.h"
using namespace std;


User testUser("LHJ", "123");  //��������������Ա�����ṩע�ᴰ��
User testUser2("ABC", "123");
Admin LHJ2(testUser);   //  ����Ա�û�

//��λ��txt�ļ���ĳһ��
ifstream& seek_to_line(ifstream& in, int line)
//���򿪵��ļ�in����λ��line�С�
{
    int i;
    char buf[1024];
    in.seekg(0, ios::beg);  //��λ���ļ���ʼ��
    for (i = 0; i < line; i++)
    {
        in.getline(buf, sizeof(buf));//��ȡ�С�
    }
    return in;
}

int main()
{
    bool Log_out = true;
    bool login = true;  // ��¼�ɹ���ת������ʼ��Ϊ��¼����

    User man;
    //vector<PROJECT>project;
    //ENGINEER Account(man,project);
    //ENGINEER Temp(man,project);

    char Password[20];
    char StudentID[20];
    string id, password, repassword;


    while (1)
    {
        //��¼����
        while (login) {
            cout << "***************��ӭʹ�ã�***************" << endl;
            cout << " --------------------------------------" << endl;
            cout << "|\n";
            cout << "|     * ��������ѧ������ϵͳ *" << endl;
            cout << "|\n";
            cout << " --------------------------------------" << endl;
            cout << endl;
            cout << "              ѡ��1����¼" << endl;
            cout << "              ѡ��2��ע��" << endl;
            cout << "              ѡ��3���˳�" << endl;
            cout << endl;
            cout << "****************************************" << endl;
            cout << "������ѡ��";
            int input;


            cin >> input;
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
                    cin >> input;
                }
            }
            while (input != 1 && input != 2 && input != 3)
            {
                cout << "���������룺";
                cin >> input;
            };

            switch (input)
            {
            case 1:
            {
                cout << "�������˺ţ�";
                cin >> id;
                cout << "���������룺";
                cin >> password;
                // ����Ա��¼��֤
                if (id == "LHJ" && password == testUser.GetPassword()) { login = false; Log_out = 1; break; }
                else if (id == "LHJ") {
                    cout << "���벻��ȷ�����������룡" << endl;
                    login = true;
                    break;
                }
                // ��¼��֤
                ifstream infile(id + ".txt");
                if (!infile)
                {
                    cout << "�˺Ų����ڣ�" << endl;
                    login = true;
                    infile.close();
                    break;
                }
                seek_to_line(infile, 3);  // ��λ���洢������
                infile.getline(Password, 20);

                if (Password != password)
                {
                    cout << "�˺������벻�������������룡" << endl;
                    login = true;
                    infile.close();
                    break;
                };
                login = false;

                infile.close();

                Log_out = 1;
                break;
            };
            case 2:
            {
                cout << "�������˺ţ�";
                cin >> id;
                ifstream checkfile;
                checkfile.open(id + ".txt", ios::in);
                if (checkfile || id == "LHJ")
                {
                    cout << "���˺��Ѵ��ڣ�" << endl;
                    login = true;
                    checkfile.close();
                    break;
                }
                checkfile.close();
                do {
                    cout << "����������һ�µ����룺" << endl;
                    cout << "���������룺";
                    cin >> password;
                    cout << "���ظ����룺";
                    cin >> repassword;
                } while (password != repassword);
                ofstream infile;
                infile.open(id + ".txt", ios::trunc | ios::out);
                infile << "ID��" << endl << id << endl;
                infile << "Password��" << endl << password << endl;
                infile.close();
                ofstream refile;
                refile.open("record.txt", ios::out | ios::app);
                refile << id << endl;
                refile.close();
                login = true;
                break;
            };
            case 3:
            {
                return 0;
            };
            };

        }
        // ��¼�ɹ�
        if (id == "LHJ")
        {
            while (Log_out)
            {
                Log_out = LHJ2.Select();
            };
            login = true;
        }
        // ���û�Ϊ��ͨѧ��
        else {
            string sid;
            cout << "���������ѧ�ţ�" << endl;
            cin >> sid;
            Grade g = LHJ2.FindStudent(sid);
            if (g.getID() == "") {
                cout << "����ѧ�Ŵ���" << endl;
                login = true;
            }
            else {
                ifstream infile(id + ".txt");
                seek_to_line(infile, 5);  // ��λ���洢�ĸ��˺Ŷ�Ӧ����֤ѧ��
                infile.getline(StudentID, 20);
                if (!infile.good()) {
                    cout << "��ʼ��֤ѧ����ݣ�" << endl;
                    ofstream outfile;
                    outfile.open(id + ".txt", ios::app);
                    outfile << "stuID��" << endl << sid << endl;
                    outfile.close();
                }
                else if (StudentID != sid)
                {
                    cout << "�����ѧ��ѧ�Ų����������µ�¼��" << endl;
                    login = true;
                    infile.close();

                }
                else {

                    if (g.getID() != "") {
                        while (Log_out) {
                            cout << "***************��ӭʹ�ã�" << g.getName() << "��***************" << endl;
                            cout << " ---------------------------------------------" << endl;
                            cout << "|\n";
                            cout << "|            * ѧ������ϵͳ������ *" << endl;
                            cout << "|\n";
                            cout << " ---------------------------------------------" << endl;
                            Student s(testUser2, g.getID());
                            Log_out = s.Select();
                        }
                        login = true;

                    }
                    else {
                        cout << "����ѧ�Ŵ���" << endl;
                        login = true;
                    }
                }
            }
            
            
           
            
        }
    }
    return 0;
}