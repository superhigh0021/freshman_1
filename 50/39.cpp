//编写一个将十进制整数转换为十六进制字符串的函数
#include<iostream>
using namespace std;

void con10to16(int n,char *s) {
	int i=0,m=0,j=0;
	char c;
	while(n!=0) {
		m=n%16;
		if(m>=0&&m<=9)
			s[i]=m+'0';
		else if(m>=10&&m<=15)
		s[i]=m-10+'A';
		n/=16;
		i++;
	}
	i--;
	m=i/2;
	for(j=0; j<=m; j++,i--) {
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}
}
int main(void) {
	char s[8];
	int n;
	cout<<"请输入一个整数:";
	cin>>n;
	con10to16(n,s);
	cout<<"转化的字符串为"<<s<<endl;
}
