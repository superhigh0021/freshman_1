//����һ����N�ı�׼�ֽ�ʽ������������֮��������16=2*2*2*2�� 15=3*5
#include<iostream>
using namespace std;
int main(void)
{
	int x,n,m;
	cout<<"������һ��������";
	cin>>x;
	printf("%d=",x);
	for(n=2;n*n<=x;)
	{
		if(x%n==0)
		{
			printf("%d*",n);
			x/=n;
		}
		else n++;
	}
	printf("%d",x);
	return 0;
}
