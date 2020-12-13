#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
	int x,i,h=0,n=0;
	char c;
	char ch[13];
	cin>>ch;
	
	for(i=0;i<11;i++)
	{
		if(ch[i]!='-')
		{
			n++;
			h+=n*(ch[i]-'0');//0是为了将字符串变成普通数字
		}
	}
	h%=11;
	if(h==10) c='X';
	else c=h+'0';
	if(c==ch[12])
	cout<<"Right"<<endl;
	else
	{
		ch[12]=c;
		cout<<ch;
	}
	return 0;
}
