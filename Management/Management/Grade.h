#pragma once
#ifndef GRADE_H
#define GRADE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    成绩类，记录每个学生的成绩
*/
class Grade {
public:
    explicit Grade(string NID="", string Nname="", string Nc="0", string Neng="0", string Nmat="0")
        :ID(NID), name(Nname),  c_score(Nc), eng_score(Neng), math_score(Nmat)
    {
        sumup();
    }
    string getID();    // 获取学生ID
    string getName();    // 获取学生姓名
    string getEng();    // 获取该学生的大学物理成绩
    string getC();    // 获取该学生的程序设计语言成绩
    string getMat();   // 获取该学生的微积分成绩
    double getAverage();   // 计算该生的分数总和
    /*
        修改学生成绩
    */
    void  changeEng(string newEng); 
    void  changeC(string newChi); 
    void  changeMat(string newMat); 
    void  changeSum(int value) { scores_sum += value; }
    // 辅助函数，用于计算均分
    void  sumup() {
        int e = stoi(eng_score); 
        int c = stoi(c_score); 
        int m = stoi(math_score); 
        scores_sum = e + c + m;
    }
private:    
    string ID;   // 学号
    string name;  //学生姓名
    string eng_score;  //  大学物理成绩
    string c_score;   // 程序设计语言成绩
    string math_score;  // 微积分成绩
    int scores_sum;
};
#endif