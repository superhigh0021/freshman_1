#pragma once 
#include<iostream>
using namespace std;
#include"identity.h"
class Student:public Identity{
	public:
		Student();
		
		//�вι���
		Student(int id, string name,string pwd);
		
		//�˵�����
		void operMenu();
		
		//����ԤԼ
		void applyOrder();
		
		//�鿴����ԤԼ
		void showMyOrder();
		
		//�鿴����ԤԼ
		void showAllOrder(); 
		
		//ȡ��ԤԼ
		void cancelOrder();
		
		//ѧ��ѧ�� 
		int m_Id;
};
