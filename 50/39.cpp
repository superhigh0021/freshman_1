//��дһ����ʮ��������ת��Ϊʮ�������ַ����ĺ���
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
	cout<<"������һ������:";
	cin>>n;
	con10to16(n,s);
	cout<<"ת�����ַ���Ϊ"<<s<<endl;
}
