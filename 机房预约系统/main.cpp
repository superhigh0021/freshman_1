#include <iostream>
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//进入管理员子菜单
void managerMenu(Identity* &manager){
	while(true){
		//调用管理员的子菜单
		manager.operMenu(); 
		//将父类指针 转为子类指针 调用子类里其他借口
		Manager *man=(Manager*) manager;
		
		int select;=0;
		cin>>select; 
		if(select==1){    //添加账号 
			cout<<"添加账号"<<endl;
		}else if(select==2){   //查看账号 
			cout<<"查看账号"<<endl;
		}else if(select==3){    //查看机房 
			cout<<"查看机房"<<endl;
		}else if(select==4){    //清空预约 
 			cout<<"清空预约"<<endl;
		} else {    //注销 
			delete manager;
			cout<<"注销成功"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
} 

//登录功能
void LoginIn(string fileName,int type) {
	Identity *person=NULL;   //父类指针，指向子类对象

	//读文件
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//判断文件是否存在
	if(!ifs.is_open()) {
		cout<<"文件不存在!"<<endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id=0;
	string name,pwd;

	//判断身份
	if(type==1) {   //学生身份
		cout<<"请输入你的学号:"<<endl;
		cin>>id;
	} else if(type==2) {
		cout<<"请输入你的职工号:"<<endl;
		cin>>id;
	}

	cout<<"请输入用户名："<<endl;
	cin>>name;

	cout<<"请输入密码："<<endl;
	cin>>pwd;
	if(type==1) {
		//学生验证
		int fId;  //从文件中读取的id号
		string fName,fPwd;
		while(ifs>>fId>>fName>>fPwd) {
			//与用户输入的信息进行对比
			if(fId==id &&fName==name &&fPwd==pwd) {
				cout<<"学生验证登录成功"<<endl;
				system("pause");
				system("cls");

				person=new Student(id,name,pwd);

				//进入学生身份的子菜单



				return;
			}
		}
	} else if(type==2) {
		//教师验证
		int fId;  //从文件中读取的id号
		string fName,fPwd;
		while(ifs>>fId>>fName>>fPwd) {
			//与用户输入的信息进行对比
			if(fId==id &&fName==name &&fPwd==pwd) {
				cout<<"教师验证登录成功"<<endl;
				system("pause");
				system("cls");

				person=new Teacher(id,name,pwd);

				//进入老师身份的子菜单



				return;
			}
		}
	} else if(type==3) {
		//管理员验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name,pwd);
				return;
			}
		}
	}

	cout<<"验证登录失败！"<<endl;
	system("pause");
	system("cls");
	return;
}

int main(int argc, char** argv) {
	int select = 0;   //勇于接受用户的选择
	while(true) {
		cout << "======================  欢迎来到机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin>>select;    //接收用户选择
		switch(select) {
		case 1:   //学生身份
			LoginIn(STUDENT_FILE,1);
			break;
		case 2:   //老师身份
			LoginIn(TEACHER_FILE,2);
			break;
		case 3:   //管理员身份
			LoginIn(ADMIN_FILE,3);
			break;
		case 0:   //退出系统
			cout<<"欢迎下次使用！"<<endl;
			system("pause");
			exit(0);
			break;
		default:
			cout<<"输入有误，请重新输入!"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}
