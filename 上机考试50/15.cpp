//�󲻳���������n��2�������ֵ��������17������Ӧ���4��24=16<17����
#include<iostream>
#include<math.h>
using namespace std;
int main(void)
{
	int m,i,n;
	printf("������һ��������");
	scanf("%d",&m);
	for(i=0;;i++)
	{
		if(pow(2,i)<=m&&pow(2,i+1)>=m)
		{
			n=pow(2,i);
			printf("2^%d=%d<%d",i,n,m);
			break;
		}
	}
	return 0;
}
