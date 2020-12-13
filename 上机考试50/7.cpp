//编写一个程序，求一个自然数中含有多少个2的因子
//如，6含1个2的因子，8含3个2的因子，11不含2的因子。
//（提示，程序应检查用户输入的合法性）。
#include<iostream>
using namespace std;
int main(void)
{
	int x,i;
	
	cout<<"请输入一个自然数"<<endl;
	cin>>x;
	if(x<0)
	cout<<"请输入一个正数"<<endl;
	else
	{
		for(i=0;x%2==0;i++)
		x/=2;
	}
	cout<<x<<"有"<<i<<"个2的因子";
	return 0;
}
