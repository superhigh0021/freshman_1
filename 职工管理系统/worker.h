#pragma once
#include<iostream>
using namespace std;
#include<string.h>

//ְ��������
class Worker{
	public:
		int m_Id;
		string m_Name;
		int m_DeptId;
		
		virtual void showInfo()=0;   //��ʾ������Ϣ
		virtual string getDeptName()=0;      //��ȡ��λ���� 
}; 
