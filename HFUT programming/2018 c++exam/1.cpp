#include<iostream>
using namespace std;

int main(void) {
	char ch;
	int flag=1;

	while(flag==1) {
		cout<<"���ǳ���Ա��"<<endl;
		cin>>ch;
		if(ch=='Y'||ch=='y') {
			cout<<"���ǳ���Ա"<<endl;
			flag=0;
		} else if(ch=='N'||ch=='n') {
			cout<<"�㲻�ǳ���Ա"<<endl;
			flag=0;
		}
	}
	return 0;
}
