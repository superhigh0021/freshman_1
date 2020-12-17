//#pragma once      //防止头文件重复包含
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

		void Show_Menu();      //展示菜单

		void ExitSystem();   //退出系统

		int m_EmpNum;   //记录职工人数

		Worker **m_EmpArray;  // 职工数组指针

		//添加职工
		void Add_Emp();
		
		//把数据保存到文件
		void save(); 
		
		//判断文件是否为空的标志 
		bool m_FileIsEmpty;
		
		//统计人数
		int get_EmpNum(); 
		
		//初始化员工
		void init_Emp();
		
		//显示职工
		void Show_Emp(); 
		
		//删除职工
		void Del_Emp(); 
		
		//判断职工是否存在，若存在则返回职工在数组中的位置，不存在返回-1
		int isExist(int id);
		
		//修改职工
		void Mod_Emp(); 
		
		//查找职工
		void Find_Emp();
		
		//排序职工
		void Sort_Emp(); 
		
		//清空文件
		void Clean_File(); 

		~WorkerManager();
};
