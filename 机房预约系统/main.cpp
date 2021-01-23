#include <iostream>
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//�������Ա�Ӳ˵�
void managerMenu(Identity* &manager){
	while(true){
		//���ù���Ա���Ӳ˵�
		manager.operMenu(); 
		//������ָ�� תΪ����ָ�� �����������������
		Manager *man=(Manager*) manager;
		
		int select;=0;
		cin>>select; 
		if(select==1){    //����˺� 
			cout<<"����˺�"<<endl;
		}else if(select==2){   //�鿴�˺� 
			cout<<"�鿴�˺�"<<endl;
		}else if(select==3){    //�鿴���� 
			cout<<"�鿴����"<<endl;
		}else if(select==4){    //���ԤԼ 
 			cout<<"���ԤԼ"<<endl;
		} else {    //ע�� 
			delete manager;
			cout<<"ע���ɹ�"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
} 

//��¼����
void LoginIn(string fileName,int type) {
	Identity *person=NULL;   //����ָ�룬ָ���������

	//���ļ�
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//�ж��ļ��Ƿ����
	if(!ifs.is_open()) {
		cout<<"�ļ�������!"<<endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id=0;
	string name,pwd;

	//�ж����
	if(type==1) {   //ѧ�����
		cout<<"���������ѧ��:"<<endl;
		cin>>id;
	} else if(type==2) {
		cout<<"���������ְ����:"<<endl;
		cin>>id;
	}

	cout<<"�������û�����"<<endl;
	cin>>name;

	cout<<"���������룺"<<endl;
	cin>>pwd;
	if(type==1) {
		//ѧ����֤
		int fId;  //���ļ��ж�ȡ��id��
		string fName,fPwd;
		while(ifs>>fId>>fName>>fPwd) {
			//���û��������Ϣ���жԱ�
			if(fId==id &&fName==name &&fPwd==pwd) {
				cout<<"ѧ����֤��¼�ɹ�"<<endl;
				system("pause");
				system("cls");

				person=new Student(id,name,pwd);

				//����ѧ����ݵ��Ӳ˵�



				return;
			}
		}
	} else if(type==2) {
		//��ʦ��֤
		int fId;  //���ļ��ж�ȡ��id��
		string fName,fPwd;
		while(ifs>>fId>>fName>>fPwd) {
			//���û��������Ϣ���жԱ�
			if(fId==id &&fName==name &&fPwd==pwd) {
				cout<<"��ʦ��֤��¼�ɹ�"<<endl;
				system("pause");
				system("cls");

				person=new Teacher(id,name,pwd);

				//������ʦ��ݵ��Ӳ˵�



				return;
			}
		}
	} else if(type==3) {
		//����Ա��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name,pwd);
				return;
			}
		}
	}

	cout<<"��֤��¼ʧ�ܣ�"<<endl;
	system("pause");
	system("cls");
	return;
}

int main(int argc, char** argv) {
	int select = 0;   //���ڽ����û���ѡ��
	while(true) {
		cout << "======================  ��ӭ��������ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin>>select;    //�����û�ѡ��
		switch(select) {
		case 1:   //ѧ�����
			LoginIn(STUDENT_FILE,1);
			break;
		case 2:   //��ʦ���
			LoginIn(TEACHER_FILE,2);
			break;
		case 3:   //����Ա���
			LoginIn(ADMIN_FILE,3);
			break;
		case 0:   //�˳�ϵͳ
			cout<<"��ӭ�´�ʹ�ã�"<<endl;
			system("pause");
			exit(0);
			break;
		default:
			cout<<"������������������!"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}
