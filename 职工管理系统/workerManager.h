//#pragma once      //��ֹͷ�ļ��ظ�����
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFIle.txt"

using namespace std;

class WorkerManager {
	public:
		WorkerManager();

		void Show_Menu();      //չʾ�˵�

		void ExitSystem();   //�˳�ϵͳ

		int m_EmpNum;   //��¼ְ������

		Worker **m_EmpArray;  // ְ������ָ��

		//���ְ��
		void Add_Emp();
		
		//�����ݱ��浽�ļ�
		void save(); 
		
		//�ж��ļ��Ƿ�Ϊ�յı�־ 
		bool m_FileIsEmpty;
		
		//ͳ������
		int get_EmpNum(); 
		
		//��ʼ��Ա��
		void init_Emp();
		
		//��ʾְ��
		void Show_Emp(); 
		
		//ɾ��ְ��
		void Del_Emp(); 
		
		//�ж�ְ���Ƿ���ڣ��������򷵻�ְ���������е�λ�ã������ڷ���-1
		int isExist(int id);
		
		//�޸�ְ��
		void Mod_Emp(); 
		
		//����ְ��
		void Find_Emp();
		
		//����ְ��
		void Sort_Emp(); 
		
		//����ļ�
		void Clean_File(); 

		~WorkerManager();
};
