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
	ofs.open(fileName,ios::out |ios::app);
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

//�鿴�˺�
void Manager::showPerson() {
}


//�鿴������Ϣ
void Manager::showComputer() {
	
}

//���ԤԼ��¼
void Manager::cleanFile() {
	
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
