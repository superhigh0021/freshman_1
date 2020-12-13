//42.编程实现“冒泡排序算法”，将输入的若干整数由小到大（升序）排序输出。要求定义一个排序函数，其原型是void bubble(int data[], int length)。
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
		printf("请输入NO.%d数: ",i+1);
		cin>>ch[i];
	}
	
	bubble(ch,size);
	
	for(int m=0;m<size;m++)
	cout<<ch[m]<<' ';
	
	return 0;
}
