#include"Grade.h"
#include<iostream>
using namespace std;


string Grade::getID()  { return ID; }  // ��ȡѧ��ID
string Grade::getName() { return name; }   // ��ȡѧ������
string Grade::getEng()  { return eng_score; }   // ��ȡ��ѧ���Ĵ�ѧ����ɼ�
string Grade::getC() { return c_score; }   // ��ȡ��ѧ���ĳ���������Գɼ�
string Grade::getMat() { return math_score; }  // ��ȡ��ѧ����΢���ֳɼ�
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