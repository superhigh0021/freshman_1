#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	if(n>0&&n<=100)
	{
		if(n*5<n*3+11)
		cout<<"Local"<<endl;
		else if(n*5>n*3+11)
		cout<<"Luogu"<<endl;
	}
	
	return 0;
}
