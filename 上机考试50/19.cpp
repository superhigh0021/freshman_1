//��һ����ģ�������ӡ������ˡ����������㡣�����ڼ���������
//5+6�󣬳������=11�������ڼ���������11*7�󣬳������=77
#include<iostream>
using namespace std;
int main(void)
{
	float x,y;
	char ch;
	cin>>x>>ch>>y;
	if(ch=='+')
	  printf("%f+%f=%f",x,y,x+y);
	else if(ch=='-')
	  printf("%f-%f=%f",x,y,x-y);
	else if(ch=='*')
	  printf("%f*%f=%f",x,y,x*y);
	else if(ch=='/')
	  printf("%f/%f=%f",x,y,x/y);
	  
	return 0;
}
