#pragma once
#ifndef GRADE_H
#define GRADE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    �ɼ��࣬��¼ÿ��ѧ���ĳɼ�
*/
class Grade {
public:
    explicit Grade(string NID="", string Nname="", string Nc="0", string Neng="0", string Nmat="0")
        :ID(NID), name(Nname),  c_score(Nc), eng_score(Neng), math_score(Nmat)
    {
        sumup();
    }
    string getID();    // ��ȡѧ��ID
    string getName();    // ��ȡѧ������
    string getEng();    // ��ȡ��ѧ���Ĵ�ѧ����ɼ�
    string getC();    // ��ȡ��ѧ���ĳ���������Գɼ�
    string getMat();   // ��ȡ��ѧ����΢���ֳɼ�
    double getAverage();   // ��������ķ����ܺ�
    /*
        �޸�ѧ���ɼ�
    */
    void  changeEng(string newEng); 
    void  changeC(string newChi); 
    void  changeMat(string newMat); 
    void  changeSum(int value) { scores_sum += value; }
    // �������������ڼ������
    void  sumup() {
        int e = stoi(eng_score); 
        int c = stoi(c_score); 
        int m = stoi(math_score); 
        scores_sum = e + c + m;
    }
private:    
    string ID;   // ѧ��
    string name;  //ѧ������
    string eng_score;  //  ��ѧ����ɼ�
    string c_score;   // ����������Գɼ�
    string math_score;  // ΢���ֳɼ�
    int scores_sum;
};
#endif