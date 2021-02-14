/*设计一个基类employee，包括姓名，编号，月薪三个数据成员
然后派生出manager（经理）类和salesman（推销员）类
在employee类中以虚函数的方式定义计算月薪函数pay()和显示信息函数displayStatus()
然后在manager（经理）类和salesman（推销员）类两个派生类中再根据各自的含义具体实现
经理拿固定月薪8000元，推销员的月薪按该推销员当月销售额的5%提成 */

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





















