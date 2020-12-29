#include<iostream> 
#include<string>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include "User.h"
#include "Admin.h"
#include "Student.h"
using namespace std;


User testUser("LHJ", "123");  //测试用例，管理员，不提供注册窗口
User testUser2("ABC", "123");
Admin LHJ2(testUser);   //  管理员用户

//定位到txt文件的某一行
ifstream& seek_to_line(ifstream& in, int line)
//将打开的文件in，定位到line行。
{
    int i;
    char buf[1024];
    in.seekg(0, ios::beg);  //定位到文件开始。
    for (i = 0; i < line; i++)
    {
        in.getline(buf, sizeof(buf));//读取行。
    }
    return in;
}

int main()
{
    bool Log_out = true;
    bool login = true;  // 登录成功跳转，否则始终为登录界面

    User man;
    //vector<PROJECT>project;
    //ENGINEER Account(man,project);
    //ENGINEER Temp(man,project);

    char Password[20];
    char StudentID[20];
    string id, password, repassword;


    while (1)
    {
        //登录界面
        while (login) {
            cout << "***************欢迎使用！***************" << endl;
            cout << " --------------------------------------" << endl;
            cout << "|\n";
            cout << "|     * 正在运行学生管理系统 *" << endl;
            cout << "|\n";
            cout << " --------------------------------------" << endl;
            cout << endl;
            cout << "              选择1：登录" << endl;
            cout << "              选择2：注册" << endl;
            cout << "              选择3：退出" << endl;
            cout << endl;
            cout << "****************************************" << endl;
            cout << "请输入选择：";
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
                    cout << "请输入数字：";
                    cin >> input;
                }
            }
            while (input != 1 && input != 2 && input != 3)
            {
                cout << "请重新输入：";
                cin >> input;
            };

            switch (input)
            {
            case 1:
            {
                cout << "请输入账号：";
                cin >> id;
                cout << "请输入密码：";
                cin >> password;
                // 管理员登录验证
                if (id == "LHJ" && password == testUser.GetPassword()) { login = false; Log_out = 1; break; }
                else if (id == "LHJ") {
                    cout << "密码不正确，请重新输入！" << endl;
                    login = true;
                    break;
                }
                // 登录验证
                ifstream infile(id + ".txt");
                if (!infile)
                {
                    cout << "账号不存在！" << endl;
                    login = true;
                    infile.close();
                    break;
                }
                seek_to_line(infile, 3);  // 定位到存储的密码
                infile.getline(Password, 20);

                if (Password != password)
                {
                    cout << "账号与密码不符，请重新输入！" << endl;
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
                cout << "请输入账号：";
                cin >> id;
                ifstream checkfile;
                checkfile.open(id + ".txt", ios::in);
                if (checkfile || id == "LHJ")
                {
                    cout << "该账号已存在！" << endl;
                    login = true;
                    checkfile.close();
                    break;
                }
                checkfile.close();
                do {
                    cout << "请两次输入一致的密码：" << endl;
                    cout << "请输入密码：";
                    cin >> password;
                    cout << "请重复密码：";
                    cin >> repassword;
                } while (password != repassword);
                ofstream infile;
                infile.open(id + ".txt", ios::trunc | ios::out);
                infile << "ID：" << endl << id << endl;
                infile << "Password：" << endl << password << endl;
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
        // 登录成功
        if (id == "LHJ")
        {
            while (Log_out)
            {
                Log_out = LHJ2.Select();
            };
            login = true;
        }
        // 该用户为普通学生
        else {
            string sid;
            cout << "请输入你的学号：" << endl;
            cin >> sid;
            Grade g = LHJ2.FindStudent(sid);
            if (g.getID() == "") {
                cout << "输入学号错误！" << endl;
                login = true;
            }
            else {
                ifstream infile(id + ".txt");
                seek_to_line(infile, 5);  // 定位到存储的该账号对应的认证学号
                infile.getline(StudentID, 20);
                if (!infile.good()) {
                    cout << "开始认证学生身份！" << endl;
                    ofstream outfile;
                    outfile.open(id + ".txt", ios::app);
                    outfile << "stuID：" << endl << sid << endl;
                    outfile.close();
                }
                else if (StudentID != sid)
                {
                    cout << "输入的学生学号不符，请重新登录！" << endl;
                    login = true;
                    infile.close();

                }
                else {

                    if (g.getID() != "") {
                        while (Log_out) {
                            cout << "***************欢迎使用，" << g.getName() << "！***************" << endl;
                            cout << " ---------------------------------------------" << endl;
                            cout << "|\n";
                            cout << "|            * 学生管理系统主界面 *" << endl;
                            cout << "|\n";
                            cout << " ---------------------------------------------" << endl;
                            Student s(testUser2, g.getID());
                            Log_out = s.Select();
                        }
                        login = true;

                    }
                    else {
                        cout << "输入学号错误！" << endl;
                        login = true;
                    }
                }
            }
            
            
           
            
        }
    }
    return 0;
}