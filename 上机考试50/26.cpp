//26.ˮ�ɻ������⣺ˮ�ɻ�����һ����λ��������ֵ����ÿ�����ֵ������͡�
//���磬153=13+53+33��������С��999��ˮ�ɻ�����
#include<iostream>
using namespace std;
int main(void)
{
	int i,a,b,c;
	for(i=100;i<=999;i++)
	{
		a=i%10;
		b=i/10%10;
		c=i/100;
		if(i==a*a*a+b*b*b+c*c*c)
		printf("%d ",i);
	}
	return 0;
}
