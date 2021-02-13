//编一程序模拟整数加、减、乘、除四则运算。当你在键盘上输入
//5+6后，程序将输出=11，当你在键盘上输入11*7后，程序将输出=77
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
