//��д���򣮼���100֮�ڿ��Ա�13��������Ȼ��֮�͡�
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
	printf("100֮�ڿ��Ա�13��������Ȼ��֮��Ϊ��%d",num);
	
	return 0;
}
