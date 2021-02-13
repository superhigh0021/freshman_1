#include<iostream>
using namespace std;

int main(void) {
	char ch;
	int flag=1;

	while(flag==1) {
		cout<<"你是程序员吗？"<<endl;
		cin>>ch;
		if(ch=='Y'||ch=='y') {
			cout<<"你是程序员"<<endl;
			flag=0;
		} else if(ch=='N'||ch=='n') {
			cout<<"你不是程序员"<<endl;
			flag=0;
		}
	}
	return 0;
}
