//100ƥ����100����������һƥ��3��������һƥ��2����С��2ƥ��1�����Ա�̼�����С�С�����Ŀ��
#include<iostream>
using namespace std;
int main(void)
{
	int l,m,s;
	for(l=0;l<34;l++)
	{
		for(m=0;m<=50;m++)
		{
			for(s=0;s<=100;s++)
			{
				if(l+m+s==100&&3*l+2*m+s/2==100)
				printf("����%dƥ������%dƥ��С��%dƥ\n",l,m,s);
			}
		}
	}
	return 0;
}
