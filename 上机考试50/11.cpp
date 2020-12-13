//编写程序．计算100之内可以被13整除的自然数之和。
#include<iostream>
using namespace std;
int main(void)
{
	int i;
	int num =0;
	for(i=0;i<=100;i++)
	{
		if(i%13==0)
		num+=i;
	}
	printf("100之内可以被13整除的自然数之和为：%d",num);
	
	return 0;
}
