//�û�����һ��������������1000��ʾ�������������
//��4  1  13  0  6  -5  1  -1   7  -12  19  0  100
//��д����ͳ����������-1��0��+1�ĸ���
#include<iostream>
using namespace std;
int main(void)
{
	int a[100];
	int i,j,x,y,z;
	x=0;
	y=0;
	z=0;
	cout<<"������������"<<endl;
	for(i=0;;i++)
	{
	cin>>a[i];
	if(a[i]==1000)
	break;
	}
	for(j=0;a[j]!=1000;j++)
	{
	if(a[j]==-1)
	x++;
    if(a[j]==0)
	y++;
	if(a[j]==1)
	z++;
}
cout<<x<<y<<z<<endl;
	return 0;
}
