#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
	char ch[100];
	int num=0;
	cout<<"������һ��Ӣ�ľ���"<<endl;
	cin>>ch;
	for(int i=0;i<100;i++)
	{
		if((ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z'))
		num++;
		else if(ch[i]=='.')
		break;
	}
	cout<<num<<endl;
	
	return 0;
}
