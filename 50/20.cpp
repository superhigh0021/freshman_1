//��һ��1Ԫ��Ʊ����1�֡�2�ֺ�5�ֵ�Ӳ�ң�ÿ��������1ö�����ж����ֻ�����
#include<iostream>
using namespace std;
int main(void)
{
	int x,y,z;
	int num=0;
	for(x=1;x<=100;x++)
	{
		for(y=1;y<=50;y++)
		{
			for(z=1;z<=20;z++)
			{
				if((x+2*y+5*z)==100)
				num++;
			}
		}
	}
	printf("��%d�ֻ���",num);
	return 0;
}
