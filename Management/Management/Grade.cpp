#include"Grade.h"
#include<iostream>
using namespace std;


string Grade::getID()  { return ID; }  // 获取学生ID
string Grade::getName() { return name; }   // 获取学生姓名
string Grade::getEng()  { return eng_score; }   // 获取该学生的大学物理成绩
string Grade::getC() { return c_score; }   // 获取该学生的程序设计语言成绩
string Grade::getMat() { return math_score; }  // 获取该学生的微积分成绩
void  Grade::changeEng(string newEng) 
{ 
	eng_score = newEng; 
}
void  Grade::changeC(string newC) 
{ 
	c_score = newC; 
}
void  Grade::changeMat(string newMat) 
{ 
	math_score = newMat; 
}

double Grade::getAverage()
{ 
	return scores_sum / 3.0; 
}