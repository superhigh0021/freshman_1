//������1000���ڵ����з�����������������
//���λ����С�ڵ�λ���֡���12��238�ȡ���21��548������������
#include<iostream>
using namespace std;
int main(void)
{
	int i,x,y,a,b,c;
	for(i=10;i<1000;i++)
	{
		if(i<100)
		{
			x=i/10;
			y=i%10;
			if(x<y)
			printf("%d ",i);
		}
		else
		{
			a=i/100;
			b=i/10%10;
			c=i%10;
			if(a<b&&b<c)
			printf("%d ",i);
		}
	}
	return 0;
 } 
