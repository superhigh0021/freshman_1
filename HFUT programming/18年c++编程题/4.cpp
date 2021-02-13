/*���һ������employee��������������ţ���н�������ݳ�Ա
Ȼ��������manager���������salesman������Ա����
��employee�������麯���ķ�ʽ���������н����pay()����ʾ��Ϣ����displayStatus()
Ȼ����manager���������salesman������Ա�����������������ٸ��ݸ��Եĺ������ʵ��
�����ù̶���н8000Ԫ������Ա����н��������Ա�������۶��5%��� */

#include<iostream>
using namespace std;

class employee {
	public:
		string name,ID;
		double salary;
		virtual void pay()=0;
		virtual void displayStatus()=0;
};

class manager:public employee {
	public:
		manager(string name, string ID) {
			this->name=name;
			this->ID=ID;
		}
		void pay() {
			this->salary=8000;
		}
		void displayStatus() {
			cout<<this->name<<' '<<this->ID<<' '<<this->salary<<endl;
		}
};
class salesman:public employee {
	public:
		double sales;
		salesman(string name,string ID,int sales) {
			this->name=name;
			this->ID=ID;
			this->sales=sales;
		}
		void pay() {
			this->salary=0.05*this->sales;
		}
		void displayStatus() {
			cout<<this->name<<' '<<this->ID<<' '<<this->salary<<endl;
		}
};

int main(void){
	manager Mt("zhu","1");
	Mt.pay();
	Mt.displayStatus();
	salesman St("li","2",100);
	St.pay();
	St.displayStatus();
	
	return 0;
}





















