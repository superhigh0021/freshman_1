#include "manager.h"
#include"globalFile.h"

//默认构造
Manager::Manager() {
	
}

//有参构造
Manager::Manager(string name, string pwd) {
	this->m_Name=name;
	this->m_Pwd=pwd;
	this->initVector();
	
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while(ifs>>com.m_ComId>>com.m_MaxNum){
		vCom.push_back(com);
	}
	ifs.close();	
}

//选择菜单
void Manager::operMenu() {
	cout << "欢迎管理员:"<<this->m_Name << "登录!" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作: " << endl;
}

//添加账号
void Manager::addPerson() {
	cout<<"请输入添加账号的类型"<<endl;
	cout<<"1、添加学生"<<endl;
	cout<<"2、添加老师"<<endl;
	
	string fileName,tip;
	ofstream ofs;
	
	int select=0;
	cin>>select;
	
	if(select==1){
		fileName=STUDENT_FILE;
		tip="请输入学号：";
	}else{
		fileName=TEACHER_FILE;
		tip="请输入职工号：";
	}
	ofs.open(fileName,ios::out | ios::app);
	int id;
	string name,pwd;
	cout<<tip<<endl;
	cin>>id;
	cout<<"请输入姓名："<<endl;
	cin>>name;
	cout<<"请输入密码："<<endl;
	cin>>pwd;
	
	//向文件中添加数据
	ofs<<id<<' '<<name<<' '<<pwd<<' '<<endl;
	cout<<"添加成功！"<<endl;
	
	system("pause");
	system("cls");
	
	ofs.close(); 
}

void printStudent(Student &s){
	cout<<"学号："<<s.m_Id<<"姓名："<<s.m_Name<<endl;
} 

void printTeacher(Teacher &s){
	cout<<"职工号："<<s.m_EmpId<<"姓名："<<s.m_Name<<endl;
} 

//查看账号
void Manager::showPerson() {
	cout<<"请选择查看的内容:"<<endl;
	cout<<"1、查看所有的学生"<<endl;
	cout<<"2、查看所有的老师"<<endl;
	
	int select = 0;
	cin>>select;
	
	if(select==1){
		//查看学生
		cout<<"所有的学生信息如下："<<endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
	}else{
		//查看老师 
		cout<<"所有的老师信息如下："<<endl;
		for_each(vTea.begin(),vTea.end(),printTeacher);
	}
	
	system("pause");
	system("cls");
}


//查看机房信息
void Manager::showComputer() {
	cout<<"机房的信息如下："<<endl;
	for(auto i:vCom){
		cout<<"机房编号："<<i.m_ComId<<"机房最大容量："<<i.m_MaxNum<<endl;
	}	
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::trunc);
	ofs.close();
	
	cout<<"清空成功！"<<endl;
	
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector(){
	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
    
	vStu.clear();
    vTea.clear();
    
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name &&  ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close(); //学生初始化

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name &&  ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为： " << vTea.size() << endl;

	ifs.close();
} 
