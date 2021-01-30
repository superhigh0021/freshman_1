#include "manager.h"
#include"globalFile.h"

//Ĭ�Ϲ���
Manager::Manager() {
	
}

//�вι���
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

//ѡ��˵�
void Manager::operMenu() {
	cout << "��ӭ����Ա:"<<this->m_Name << "��¼!" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ���: " << endl;
}

//����˺�
void Manager::addPerson() {
	cout<<"����������˺ŵ�����"<<endl;
	cout<<"1�����ѧ��"<<endl;
	cout<<"2�������ʦ"<<endl;
	
	string fileName,tip;
	ofstream ofs;
	
	int select=0;
	cin>>select;
	
	if(select==1){
		fileName=STUDENT_FILE;
		tip="������ѧ�ţ�";
	}else{
		fileName=TEACHER_FILE;
		tip="������ְ���ţ�";
	}
	ofs.open(fileName,ios::out | ios::app);
	int id;
	string name,pwd;
	cout<<tip<<endl;
	cin>>id;
	cout<<"������������"<<endl;
	cin>>name;
	cout<<"���������룺"<<endl;
	cin>>pwd;
	
	//���ļ����������
	ofs<<id<<' '<<name<<' '<<pwd<<' '<<endl;
	cout<<"��ӳɹ���"<<endl;
	
	system("pause");
	system("cls");
	
	ofs.close(); 
}

void printStudent(Student &s){
	cout<<"ѧ�ţ�"<<s.m_Id<<"������"<<s.m_Name<<endl;
} 

void printTeacher(Teacher &s){
	cout<<"ְ���ţ�"<<s.m_EmpId<<"������"<<s.m_Name<<endl;
} 

//�鿴�˺�
void Manager::showPerson() {
	cout<<"��ѡ��鿴������:"<<endl;
	cout<<"1���鿴���е�ѧ��"<<endl;
	cout<<"2���鿴���е���ʦ"<<endl;
	
	int select = 0;
	cin>>select;
	
	if(select==1){
		//�鿴ѧ��
		cout<<"���е�ѧ����Ϣ���£�"<<endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
	}else{
		//�鿴��ʦ 
		cout<<"���е���ʦ��Ϣ���£�"<<endl;
		for_each(vTea.begin(),vTea.end(),printTeacher);
	}
	
	system("pause");
	system("cls");
}


//�鿴������Ϣ
void Manager::showComputer() {
	cout<<"��������Ϣ���£�"<<endl;
	for(auto i:vCom){
		cout<<"������ţ�"<<i.m_ComId<<"�������������"<<i.m_MaxNum<<endl;
	}	
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::trunc);
	ofs.close();
	
	cout<<"��ճɹ���"<<endl;
	
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector(){
	//��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
    
	vStu.clear();
    vTea.clear();
    
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name &&  ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close(); //ѧ����ʼ��

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name &&  ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;

	ifs.close();
} 
