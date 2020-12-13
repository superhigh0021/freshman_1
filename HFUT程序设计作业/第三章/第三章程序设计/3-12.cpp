#include<iostream>
using namespace std;
int sum(unsigned n);

int main(void)
{
	int n,k;
	cout<<"ÇëÊäÈëÕûÊın£º"<<endl;
	cin>>n;
	k=sum(n);
	cout<<k<<endl;
	
	return 0;
}

int sum(unsigned n)
{
	int f;
	if(n==1)
	f = 1;
	else
	f = sum(n-1)+n;
	return f;
}
