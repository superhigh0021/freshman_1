#include<iostream>
using namespace std;
int judge(int i);

int main (void)
{
	int i;
	cout<<"请输入一个数："<<endl;
	cin>>i;
    if(judge(i))
       cout<<i<<"是质数"<<endl;
    else
       cout<<i<<"不是质数"<<endl;
	
	return 0;
}

int judge(int i)
{
	int y,flag;
	if(i>=2)
	{
	for(y = 2; y < i;y++)
	{
		flag =1;
		if(i % y == 0)
		{
			flag = 0;
			break;
		}
	}
	}
	else 
	    flag = 0;
	return flag;
}
