#include<iostream>
using namespace std;

int main(void)
{
	int n=6,i,j,k;
	int count1;
	int count2;
	for(i=1;i<=n;i++)
	{
		count1=0;
		count2=0;
		for(j=i;j>0;j--)
		{
		cout<<j<<' ';
	    count1++;
	}
		for(k=2;count1+count2<6;k++)
		{
			cout<<k<<' ';
			count2++;
		}
		cout<<endl;
	}
	return 0;
}
