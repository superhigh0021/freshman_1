#include<iostream>
using namespace std;

int main(void)
{
	int n=6,i,j,k;
	for(i=1;i<=n;i++)
	{
		int count1=0,count2=0;
		for(j=i;j<=n;j++)
		{
			cout<<j<<' ';
			count1++;
		}
		for(k=0;count1+count2<n;k++)
		{
			cout<<k<<' ';
			count2++;
		}
		cout<<endl;
	}
	return 0;
}
