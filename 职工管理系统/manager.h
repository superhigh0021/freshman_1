#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager:public Worker {
	public:
		Manager(int id,string name,int dId);
		virtual void showInfo();   //��ʾ������Ϣ
		virtual string getDeptName();      //��ȡ��λ����
};
