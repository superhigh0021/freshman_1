#include<iostream>
using namespace std;
int judge(int i);

int main (void)
{
	int i;
	cout<<"������һ������"<<endl;
	cin>>i;
    if(judge(i))
       cout<<i<<"������"<<endl;
    else
       cout<<i<<"��������"<<endl;
	
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
