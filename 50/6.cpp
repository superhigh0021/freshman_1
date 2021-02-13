//用户输入一个整数流（输入1000表示数据输入结束）
//如4  1  13  0  6  -5  1  -1   7  -12  19  0  100
//编写程序统计输入流中-1、0和+1的个数
#include<iostream>
using namespace std;
int main(void)
{
	int a[100];
	int i,j,x,y,z;
	x=0;
	y=0;
	z=0;
	cout<<"请输入整数流"<<endl;
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
