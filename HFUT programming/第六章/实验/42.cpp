//42.���ʵ�֡�ð�������㷨���������������������С�����������������Ҫ����һ������������ԭ����void bubble(int data[], int length)��
#include<iostream>
#define size 8
using namespace std;
void bubble(int *ch, int length)
{
	int temp;
	for(int i=0;i<=length-1;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(ch[j]>ch[j+1])
			{
				temp=ch[j];
				ch[j]=ch[j+1];
				ch[j+1]=temp;
			}
		}
	}
}

int main(void)
{
	int ch[size];
	for(int i=0;i<size;i++)
	{
		printf("������NO.%d��: ",i+1);
		cin>>ch[i];
	}
	
	bubble(ch,size);
	
	for(int m=0;m<size;m++)
	cout<<ch[m]<<' ';
	
	return 0;
}
